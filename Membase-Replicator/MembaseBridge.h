//
//  MembasePopulator.h
//  membase_replicator
//
//  Created by Vivek Y S on 26/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef membase_replicator_MembasePopulator_h
#define membase_replicator_MembasePopulator_h

#include <vector>
#include <utility>
#include <string>

#include "MP_MC.h"
#include "Config.h"
#include "MembaseClient.h"
#include "MembaseCallbacks.h"
#include "TapJob.h"
#include "ReplicatorJob.h"

#define CONCURRENCY 10

class MembaseBridge
{
private:
    Config srcConfig;
    Config dstConfig;
    MembaseClient* srcClient;
    MembaseClient** dstClient;
    std::vector< MP_MC <std::pair <std::string, std::string> >* > mc_mpMap;
    TapJob *tapJob;
    ReplicatorJob *replicatorJobArray;
    
public:
    MembaseBridge(Config srcConfig, Config dstConfig);
    void membaseBridgeInitializer();
    void start();
    void join();
    ~MembaseBridge();
    
};


#endif
