//
//  MembaseClient.h
//  membase_replicator
//
//  Created by Vivek Y S on 26/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef membase_replicator_MembaseClient_h
#define membase_replicator_MembaseClient_h

#include <libcouchbase/couchbase.h>
#include "Config.h"
#include "MembaseCallbacks.h"

class MembaseClient
{
private:
    libcouchbase_io_opt_t *mvIoOptPtr;
    libcouchbase_t mvInstance;
    Config mvConfig;
    
public:
    MembaseClient(const Config config, MembaseCallbacks &callbacks);
    virtual ~MembaseClient();
    
    int membaseTapCluster(const void *command_cookie,
                           libcouchbase_tap_filter_t filter,
                           int block);
    
    int membaseMultiGet(const void *command_cookie,
                         libcouchbase_size_t num_keys,
                         const void *const *keys,
                         const libcouchbase_size_t *nkey,
                         const libcouchbase_time_t *exp);
    
    int membaseStore(const void *command_cookie,
                      libcouchbase_storage_t operation,
                      const void *key, libcouchbase_size_t nkey,
                      const void *bytes, libcouchbase_size_t nbytes,
                      libcouchbase_uint32_t flags, libcouchbase_time_t exp,
                      libcouchbase_cas_t cas);
    
    int membaseRemove(const void *command_cookie,
                       const void *key,
                       libcouchbase_size_t nkey,
                       libcouchbase_cas_t cas);
    
    void membaseWait();
};


#endif
