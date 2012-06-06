//
//  MembaseCallbacks.cpp
//  Membase-Replicator
//
//  Created by Vivek Y S on 03/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "MembaseCallbacks.h"

void
MembaseCallbacks::registerCallbacks(libcouchbase_t mvInstance)
{
    /*
    libcouchbase_set_get_callback(mvInstance, MembaseCallbacks::get_callback);
    libcouchbase_set_storage_callback(mvInstance, MembaseCallbacks::storage_callback);
    libcouchbase_set_arithmetic_callback(mvInstance, MembaseCallbacks::arithmetic_callback);
    libcouchbase_set_remove_callback(mvInstance, MembaseCallbacks::remove_callback);
    libcouchbase_set_stat_callback(mvInstance, MembaseCallbacks::stat_callback);
    libcouchbase_set_version_callback(mvInstance, MembaseCallbacks::version_callback);
    libcouchbase_set_touch_callback(mvInstance, MembaseCallbacks::touch_callback);
    libcouchbase_set_tap_mutation_callback(mvInstance, MembaseCallbacks::tap_mutation_callback);
    libcouchbase_set_tap_deletion_callback(mvInstance, MembaseCallbacks::tap_deletion_callback);
    libcouchbase_set_tap_flush_callback(mvInstance, MembaseCallbacks::tap_flush_callback);
    libcouchbase_set_tap_opaque_callback(mvInstance, MembaseCallbacks::tap_opaque_callback);
    libcouchbase_set_tap_vbucket_set_callback(mvInstance, MembaseCallbacks::tap_vbucket_set_callback);
    libcouchbase_set_error_callback(mvInstance, MembaseCallbacks::error_callback);
    libcouchbase_set_flush_callback(mvInstance, MembaseCallbacks::flush_callback);
    */
    
}

void 
MembaseCallbacks::get_callback(libcouchbase_t instance,
                            const void *cookie,
                            libcouchbase_error_t error,
                            const void *key,
                            libcouchbase_size_t nkey,
                            const void *bytes,
                            libcouchbase_size_t nbytes,
                            libcouchbase_uint32_t flags,
                            libcouchbase_cas_t cas)
{
    
}

void 
MembaseCallbacks::storage_callback(libcouchbase_t instance,
                                const void *cookie,
                                libcouchbase_storage_t operation,
                                libcouchbase_error_t error,
                                const void *key,
                                libcouchbase_size_t nkey,
                                libcouchbase_cas_t cas)
{
    
}

void
MembaseCallbacks::arithmetic_callback(libcouchbase_t instance,
                                   const void *cookie,
                                   libcouchbase_error_t error,
                                   const void *key,
                                   libcouchbase_size_t nkey,
                                   libcouchbase_uint64_t value,
                                   libcouchbase_cas_t cas)
{
    
}

void 
MembaseCallbacks::remove_callback(libcouchbase_t instance,
                               const void *cookie,
                               libcouchbase_error_t error,
                               const void *key,
                               libcouchbase_size_t nkey)
{
    
}

void 
MembaseCallbacks::stat_callback(libcouchbase_t instance,
                             const void *cookie,
                             const char *server_endpoint,
                             libcouchbase_error_t error,
                             const void *key,
                             libcouchbase_size_t nkey,
                             const void *bytes,
                             libcouchbase_size_t nbytes)
{
    
}

void 
MembaseCallbacks::version_callback(libcouchbase_t instance,
                                const void *cookie,
                                const char *server_endpoint,
                                libcouchbase_error_t error,
                                const char *vstring,
                                libcouchbase_size_t nvstring)
{
    
}

void 
MembaseCallbacks::touch_callback(libcouchbase_t instance,
                              const void *cookie,
                              libcouchbase_error_t error,
                              const void *key,
                              libcouchbase_size_t nkey)
{
    
}

void 
MembaseCallbacks::tap_mutation_callback(libcouchbase_t instance,
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
                                     libcouchbase_size_t nes)
{
    
}

void 
MembaseCallbacks::tap_deletion_callback(libcouchbase_t instance,
                                     const void *cookie,
                                     const void *key,
                                     libcouchbase_size_t nkey,
                                     libcouchbase_cas_t cas,
                                     libcouchbase_vbucket_t vbucket,
                                     const void *es,
                                     libcouchbase_size_t nes)
{
    
}

void 
MembaseCallbacks::tap_flush_callback(libcouchbase_t instance,
                                  const void *cookie,
                                  const void *es,
                                  libcouchbase_size_t nes)
{
    
}

void 
MembaseCallbacks::tap_opaque_callback(libcouchbase_t instance,
                                   const void *cookie,
                                   const void *es,
                                   libcouchbase_size_t nes)
{
    
}

void 
MembaseCallbacks::tap_vbucket_set_callback(libcouchbase_t instance,
                                        const void *cookie,
                                        libcouchbase_vbucket_t vbid,
                                        libcouchbase_vbucket_state_t state,
                                        const void *es,
                                        libcouchbase_size_t nes)
{
    
}

void 
MembaseCallbacks::error_callback(libcouchbase_t instance,
                              libcouchbase_error_t error,
                              const char *errinfo)
{
    
}

void 
MembaseCallbacks::flush_callback(libcouchbase_t instance,
                              const void *cookie,
                              const char *server_endpoint,
                              libcouchbase_error_t error)
{
    
}
