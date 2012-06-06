//
//  ReplicatorJob.h
//  Membase-Replicator
//
//  Created by Vivek Y S on 05/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Membase_Replicator_ReplicatorJob_h
#define Membase_Replicator_ReplicatorJob_h

#include <boost/thread.hpp>
#include <utility>
#include <string>

#include "MembaseClient.h"
#include "MP_MC.h"

class ReplicatorJob
{
private:
    boost::thread* replicatorThread;
public:
    void operator() (MembaseClient &client, MP_MC<std::pair<std::string, std::string> > &queue);
    
    void start(MembaseClient &client, MP_MC<std::pair<std::string, std::string> > &queue);
    
    void join();
    ~ReplicatorJob()
    {
        delete replicatorThread;
    }
    
};

#endif
