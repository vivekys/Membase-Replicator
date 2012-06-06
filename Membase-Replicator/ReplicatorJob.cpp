//
//  ReplicatorJob.cpp
//  Membase-Replicator
//
//  Created by Vivek Y S on 05/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <boost/bind.hpp>
#include "ReplicatorJob.h"

using namespace std;

void
ReplicatorJob::operator()(MembaseClient &client, MP_MC<std::pair<std::string, std::string> > &queue)
{
    int ret[10];
    int error[10];
    pair<string, string>* kv[10];
    
    while (true) 
    {
        for (int i = 0; i < 10; i++) {
            kv[i] = new pair<string, string>(queue.dequeue());
            const char *key = kv[i]->first.c_str();
            libcouchbase_size_t nkey = kv[i]->first.length();
            const char *bytes = kv[i]->second.c_str();
            libcouchbase_size_t nbytes = kv[i]->second.length();
            
            if (nbytes != 0) {
                ret[i] = client.membaseStore(error, LIBCOUCHBASE_SET, key, nkey, bytes, nbytes, 0, 0, 0);
            }
            else
            {
                ret[i] = client.membaseRemove(error, key, nkey, 0);
            }
            if (ret[i] == LIBCOUCHBASE_SUCCESS) {
                error[i] = 0;
            }
            else
            {
                error[i] = -1;
            }
                    
        }
        
        client.membaseWait();
        for (int i = 0; i < 10; i++) {
            delete kv[i];
        }
    }
    
}

void
ReplicatorJob::start(MembaseClient &client, MP_MC<std::pair<std::string, std::string> > &queue)
{
    replicatorThread = new boost::thread(boost::ref(*this), boost::ref(client), boost::ref(queue));
}

void
ReplicatorJob::join()
{
    replicatorThread->join();
}