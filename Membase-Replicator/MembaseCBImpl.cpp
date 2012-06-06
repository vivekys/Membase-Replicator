//
//  MembaseCBImpl.cpp
//  Membase-Replicator
//
//  Created by Vivek Y S on 03/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <string>
#include "MembaseCBImpl.h"
#include "tri_logger.hpp"

using namespace std;

vector< MP_MC <pair <std::string, std::string> >* > *MembaseCBImpl::mp_mcMap;

void
MembaseCBImpl::registerCallbacks(libcouchbase_t mvInstance)
{
     libcouchbase_set_get_callback(mvInstance, MembaseCBImpl::get_callback);
     libcouchbase_set_storage_callback(mvInstance, MembaseCBImpl::storage_callback);
     libcouchbase_set_arithmetic_callback(mvInstance, MembaseCBImpl::arithmetic_callback);
     libcouchbase_set_remove_callback(mvInstance, MembaseCBImpl::remove_callback);
     libcouchbase_set_stat_callback(mvInstance, MembaseCBImpl::stat_callback);
     libcouchbase_set_version_callback(mvInstance, MembaseCBImpl::version_callback);
     libcouchbase_set_touch_callback(mvInstance, MembaseCBImpl::touch_callback);
     libcouchbase_set_tap_mutation_callback(mvInstance, MembaseCBImpl::tap_mutation_callback);
     libcouchbase_set_tap_deletion_callback(mvInstance, MembaseCBImpl::tap_deletion_callback);
     libcouchbase_set_tap_flush_callback(mvInstance, MembaseCBImpl::tap_flush_callback);
     libcouchbase_set_tap_opaque_callback(mvInstance, MembaseCBImpl::tap_opaque_callback);
     libcouchbase_set_tap_vbucket_set_callback(mvInstance, MembaseCBImpl::tap_vbucket_set_callback);
     libcouchbase_set_error_callback(mvInstance, MembaseCBImpl::error_callback);
     libcouchbase_set_flush_callback(mvInstance, MembaseCBImpl::flush_callback);
}

void 
MembaseCBImpl::get_callback(libcouchbase_t instance,
                               const void *cookie,
                               libcouchbase_error_t err,
                               const void *key,
                               libcouchbase_size_t nkey,
                               const void *bytes,
                               libcouchbase_size_t nbytes,
                               libcouchbase_uint32_t flags,
                               libcouchbase_cas_t cas)
{
    string str_key = string((char *)key, nkey);
    int *error = (int*)cookie;
    if (err == LIBCOUCHBASE_SUCCESS) {
        TRI_LOG_STR("Successfully got KEY "+str_key);
        *error = 0;
        cout << "Successfully got KEY " << str_key << endl;
    } else {
        *error = 1;
        TRI_LOG_STR("Failed to get KEY "+ str_key + " "+ libcouchbase_strerror(instance, err));
        cout << "Failed to get KEY " << str_key << " " << libcouchbase_strerror(instance, err) << endl;
    }    
}

void 
MembaseCBImpl::storage_callback(libcouchbase_t instance,
                                   const void *cookie,
                                   libcouchbase_storage_t operation,
                                   libcouchbase_error_t err,
                                   const void *key,
                                   libcouchbase_size_t nkey,
                                   libcouchbase_cas_t cas)
{
    string str_key = string((char *)key, nkey);
    int *error = (int*)cookie;
    if (err == LIBCOUCHBASE_SUCCESS) {
        TRI_LOG_STR("Successfully stored KEY "+str_key);
        *error = 0;
        cout << "Successfully stored KEY " << str_key << endl;
    } else {
        *error = 1;
        TRI_LOG_STR("Failed to store KEY "+ str_key + " "+ libcouchbase_strerror(instance, err));
        cout << "Failed to store KEY " << str_key << " "<< libcouchbase_strerror(instance, err) << endl;
    }    
}

void
MembaseCBImpl::arithmetic_callback(libcouchbase_t instance,
                                      const void *cookie,
                                      libcouchbase_error_t error,
                                      const void *key,
                                      libcouchbase_size_t nkey,
                                      libcouchbase_uint64_t value,
                                      libcouchbase_cas_t cas)
{
    string str_key = string((char *)key, nkey);
    TRI_LOG_STR("Key = "+str_key);    
    
}

void 
MembaseCBImpl::remove_callback(libcouchbase_t instance,
                                  const void *cookie,
                                  libcouchbase_error_t err,
                                  const void *key,
                                  libcouchbase_size_t nkey)
{
    string str_key = string((char *)key, nkey);
    int *error = (int*)cookie;
    if (err == LIBCOUCHBASE_SUCCESS) {
        TRI_LOG_STR("Successfully removed KEY "+str_key);
        *error = 0;
        cout << "Successfully removed KEY " << str_key << endl; 
    } else {
        *error = 1;
        TRI_LOG_STR("Failed to remoce KEY "+ str_key + " "+ libcouchbase_strerror(instance, err));
        cout << "Failed to remoce KEY " << str_key << " " << libcouchbase_strerror(instance, err) << endl;
    }    
    
}

void 
MembaseCBImpl::stat_callback(libcouchbase_t instance,
                                const void *cookie,
                                const char *server_endpoint,
                                libcouchbase_error_t error,
                                const void *key,
                                libcouchbase_size_t nkey,
                                const void *bytes,
                                libcouchbase_size_t nbytes)
{
    string str_key = string((char *)key, nkey);
    TRI_LOG_STR("Key = "+str_key);    
    
}

void 
MembaseCBImpl::version_callback(libcouchbase_t instance,
                                   const void *cookie,
                                   const char *server_endpoint,
                                   libcouchbase_error_t error,
                                   const char *vstring,
                                   libcouchbase_size_t nvstring)
{
    string str_version = string((char *) vstring, nvstring);
    TRI_LOG_STR(str_version);
}

void 
MembaseCBImpl::touch_callback(libcouchbase_t instance,
                                 const void *cookie,
                                 libcouchbase_error_t error,
                                 const void *key,
                                 libcouchbase_size_t nkey)
{
    string str_key = string((char *)key, nkey);
    TRI_LOG_STR("Key = "+str_key);    
    
}

void 
MembaseCBImpl::tap_mutation_callback(libcouchbase_t instance,
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

    size_t size = MembaseCBImpl::mp_mcMap->size();
    int hash = 0;
    const char *str_key = (char *)key;
    const char *str_data = (char *)data;
    for (int i = 0; i < nkey; i++) {
        hash += str_key[i];
    }
    hash = hash % size;
    (*MembaseCBImpl::mp_mcMap)[hash]->enqueue(pair<string, string>(string(str_key, nkey), string(str_data, nbytes)));
//    cout << "Tap mutation for Key = " << str_key << endl;
    fwrite(key, nkey, 1, stdout);
    fprintf(stdout, " \t%d\n", (unsigned int)nbytes);
}

void 
MembaseCBImpl::tap_deletion_callback(libcouchbase_t instance,
                                        const void *cookie,
                                        const void *key,
                                        libcouchbase_size_t nkey,
                                        libcouchbase_cas_t cas,
                                        libcouchbase_vbucket_t vbucket,
                                        const void *es,
                                        libcouchbase_size_t nes)
{

    size_t size = MembaseCBImpl::mp_mcMap->size();
    int hash = 0;
    const char *str_key = (char *)key;
    for (int i = 0; i < nkey; i++) {
        hash += str_key[i];
    }
    hash = hash % size;
    (*MembaseCBImpl::mp_mcMap)[hash]->enqueue(pair<string, string>(string(str_key, nkey), string("")));
    cout << "Tap deletion for Key " << str_key << endl;
}

void 
MembaseCBImpl::tap_flush_callback(libcouchbase_t instance,
                                     const void *cookie,
                                     const void *es,
                                     libcouchbase_size_t nes)
{
    TRI_LOG_STR("tap_flush_callback");    
}

void 
MembaseCBImpl::tap_opaque_callback(libcouchbase_t instance,
                                      const void *cookie,
                                      const void *es,
                                      libcouchbase_size_t nes)
{
    TRI_LOG_STR("tap_opaque_callback");        
}

void 
MembaseCBImpl::tap_vbucket_set_callback(libcouchbase_t instance,
                                           const void *cookie,
                                           libcouchbase_vbucket_t vbid,
                                           libcouchbase_vbucket_state_t state,
                                           const void *es,
                                           libcouchbase_size_t nes)
{
    TRI_LOG_STR("tap_vbucket_set_callback");
    TRI_LOG(vbid);
}

void 
MembaseCBImpl::error_callback(libcouchbase_t instance,
                                 libcouchbase_error_t error,
                                 const char *errinfo)
{
    TRI_LOG_STR(string(errinfo));
}

void 
MembaseCBImpl::flush_callback(libcouchbase_t instance,
                                 const void *cookie,
                                 const char *server_endpoint,
                                 libcouchbase_error_t error)
{
    TRI_LOG_STR("flush_callback");
}
