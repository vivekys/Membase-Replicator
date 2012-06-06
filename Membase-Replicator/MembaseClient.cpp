//
//  MembaseClient.cpp
//  membase_replicator
//
//  Created by Vivek Y S on 28/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>

#include "MembaseClient.h"

using namespace std;

MembaseClient::MembaseClient(const Config config, MembaseCallbacks &callbacks) : mvConfig(config) 
{
    mvIoOptPtr = libcouchbase_create_io_ops(LIBCOUCHBASE_IO_OPS_LIBEVENT, NULL, NULL);
    if (mvIoOptPtr == NULL) {
        cerr << "Failed to create IO instance\n" << endl;
        exit(EXIT_FAILURE);
    }

    mvInstance = libcouchbase_create(mvConfig.getHost().c_str(), mvConfig.getUser().c_str(),
                                     mvConfig.getPasswd().c_str(), mvConfig.getBucket().c_str(), mvIoOptPtr);
    
    if (mvInstance == NULL) {
        cerr << "Failed to create libcouchbase instance\n" << endl;
        exit(EXIT_FAILURE);
    }

    if (libcouchbase_connect(mvInstance) != LIBCOUCHBASE_SUCCESS) {
        cerr << "Failed to connect libcouchbase instance to server\n" << endl;
        exit(EXIT_FAILURE);
    }
    
    // Wait for the connect to compelete
    libcouchbase_wait(mvInstance);
    callbacks.registerCallbacks(mvInstance);
    cout << "Created MembaseClient" << endl;
}

MembaseClient::~MembaseClient()
{
    cout << "Delete MembaseClient" << endl;
    libcouchbase_destroy(mvInstance);
}

int
MembaseClient::membaseTapCluster(const void *command_cookie, libcouchbase_tap_filter_t filter, int block)
{
    return libcouchbase_tap_cluster(mvInstance,command_cookie, filter, block);
}

int 
MembaseClient::membaseMultiGet(const void *command_cookie,
                     libcouchbase_size_t num_keys,
                     const void *const *keys,
                     const libcouchbase_size_t *nkey,
                     const libcouchbase_time_t *exp)
{
    return libcouchbase_mget(mvInstance, command_cookie, num_keys, keys, nkey, exp);
}

int 
MembaseClient::membaseStore(const void *command_cookie,
                  libcouchbase_storage_t operation,
                  const void *key, libcouchbase_size_t nkey,
                  const void *bytes, libcouchbase_size_t nbytes,
                  libcouchbase_uint32_t flags, libcouchbase_time_t exp,
                  libcouchbase_cas_t cas)
{
    return libcouchbase_store(mvInstance, command_cookie, operation, key, nkey, bytes, nbytes, flags, exp, cas);
}

int 
MembaseClient::membaseRemove(const void *command_cookie,
                   const void *key,
                   libcouchbase_size_t nkey,
                   libcouchbase_cas_t cas)
{
    return libcouchbase_remove(mvInstance, command_cookie, key, nkey, cas);
}


void
MembaseClient::membaseWait()
{
    libcouchbase_wait(mvInstance);
}