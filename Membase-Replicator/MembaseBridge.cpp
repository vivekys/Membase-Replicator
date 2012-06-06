//
//  MembaseBridge.cpp
//  Membase-Replicator
//
//  Created by Vivek Y S on 05/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "MembaseBridge.h"
#include "MembaseCBImpl.h"
#include "TapJob.h"

using namespace std;

MembaseBridge::MembaseBridge(Config sConfig, Config dConfig): srcConfig(sConfig), dstConfig(dConfig)
{
    this->srcClient = NULL;
    this->dstClient = new MembaseClient* [CONCURRENCY];
    
    for (int i = 0; i < CONCURRENCY; i++) 
    {
        mc_mpMap.push_back(new MP_MC<pair<string, string> > ());
    }
}

void
MembaseBridge::membaseBridgeInitializer()
{
    srcClient = new MembaseClient(srcConfig, *new MembaseCBImpl(mc_mpMap));
    for (int i=0; i<CONCURRENCY; i++) {
        dstClient[i] = new MembaseClient(dstConfig, *new MembaseCBImpl(mc_mpMap));
    }
    tapJob = new TapJob(); 
    replicatorJobArray = new ReplicatorJob [CONCURRENCY];
    
}

void
MembaseBridge::start()
{
    tapJob->start(*srcClient);
    for (int i = 0; i < CONCURRENCY; i++) 
    {
        replicatorJobArray[i].start(*dstClient[i], *mc_mpMap[i]);
    }
}

void 
MembaseBridge::join()
{
    tapJob->join();
    for (int i = 0; i < CONCURRENCY; i++) 
    {
        replicatorJobArray[i].join();
    }
    
}

MembaseBridge::~MembaseBridge()
{
    delete tapJob;
    delete []replicatorJobArray;
    delete srcClient;
    delete dstClient;
}