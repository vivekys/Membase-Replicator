//
//  MembaseCallbacks.h
//  Membase-Replicator
//
//  Created by Vivek Y S on 03/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Membase_Replicator_MembaseCallbacks_h
#define Membase_Replicator_MembaseCallbacks_h
#include <libcouchbase/couchbase.h>

class MembaseCallbacks
{
public:
    virtual void registerCallbacks(libcouchbase_t mvInstance) = 0;
    
    static void get_callback(libcouchbase_t instance,
                             const void *cookie,
                             libcouchbase_error_t error,
                             const void *key,
                             libcouchbase_size_t nkey,
                             const void *bytes,
                             libcouchbase_size_t nbytes,
                             libcouchbase_uint32_t flags,
                             libcouchbase_cas_t cas);
    
    static void storage_callback(libcouchbase_t instance,
                                 const void *cookie,
                                 libcouchbase_storage_t operation,
                                 libcouchbase_error_t error,
                                 const void *key,
                                 libcouchbase_size_t nkey,
                                 libcouchbase_cas_t cas);
    
    static void arithmetic_callback(libcouchbase_t instance,
                                    const void *cookie,
                                    libcouchbase_error_t error,
                                    const void *key,
                                    libcouchbase_size_t nkey,
                                    libcouchbase_uint64_t value,
                                    libcouchbase_cas_t cas);
    
    static void remove_callback(libcouchbase_t instance,
                                const void *cookie,
                                libcouchbase_error_t error,
                                const void *key,
                                libcouchbase_size_t nkey);
    
    static void stat_callback(libcouchbase_t instance,
                              const void *cookie,
                              const char *server_endpoint,
                              libcouchbase_error_t error,
                              const void *key,
                              libcouchbase_size_t nkey,
                              const void *bytes,
                              libcouchbase_size_t nbytes);
    
    static void version_callback(libcouchbase_t instance,
                                 const void *cookie,
                                 const char *server_endpoint,
                                 libcouchbase_error_t error,
                                 const char *vstring,
                                 libcouchbase_size_t nvstring);
    
    static void touch_callback(libcouchbase_t instance,
                               const void *cookie,
                               libcouchbase_error_t error,
                               const void *key,
                               libcouchbase_size_t nkey);
    
    static void tap_mutation_callback(libcouchbase_t instance,
                                      const void *cookie,
                                      const void *key,
                                      libcouchbase_size_t nkey,
                                      const void *data,
                                      libcouchbase_size_t nbytes,
                                      libcouchbase_uint32_t flags,
                                      libcouchbase_time_t exp,
                                      libcouchbase_cas_t cas,
                                      libcouchbase_vbucket_t vbucket,
                                      const void *es,
                                      libcouchbase_size_t nes);
    
    static void tap_deletion_callback(libcouchbase_t instance,
                                      const void *cookie,
                                      const void *key,
                                      libcouchbase_size_t nkey,
                                      libcouchbase_cas_t cas,
                                      libcouchbase_vbucket_t vbucket,
                                      const void *es,
                                      libcouchbase_size_t nes);
    
    static void tap_flush_callback(libcouchbase_t instance,
                                   const void *cookie,
                                   const void *es,
                                   libcouchbase_size_t nes);
    
    static void tap_opaque_callback(libcouchbase_t instance,
                                    const void *cookie,
                                    const void *es,
                                    libcouchbase_size_t nes);
    
    static void tap_vbucket_set_callback(libcouchbase_t instance,
                                         const void *cookie,
                                         libcouchbase_vbucket_t vbid,
                                         libcouchbase_vbucket_state_t state,
                                         const void *es,
                                         libcouchbase_size_t nes);
    
    static void error_callback(libcouchbase_t instance,
                               libcouchbase_error_t error,
                               const char *errinfo);
    
    static void flush_callback(libcouchbase_t instance,
                               const void *cookie,
                               const char *server_endpoint,
                               libcouchbase_error_t error);

};

#endif
