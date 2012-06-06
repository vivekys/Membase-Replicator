//
//  main.cpp
//  Membase-Replicator
//
//  Created by Vivek Y S on 03/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Config.h"
#include "MembaseBridge.h"

const char *srcHost = "pf-mbase1:8091";
const char *dstHost = "pf-cache1:8091";
const char *username = "cms";
const char *passwd = "";
const char *bucket = "cms";

int main (int argc, const char * argv[])
{
    Config srcConfig(srcHost, username, passwd, bucket);
    Config dstConfig(dstHost, username, passwd, bucket);
    
    MembaseBridge memBridge(srcConfig, dstConfig);
    memBridge.membaseBridgeInitializer();
    memBridge.start();
    
    memBridge.join();
    return 0;
    
}

