//
//  TapJob.cpp
//  Membase-Replicator
//
//  Created by Vivek Y S on 05/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "TapJob.h"
#include <boost/bind.hpp>

typedef void (*myBad) (TapJob *, MembaseClient &);

void
TapJob::operator()(MembaseClient &client)
{
  client.membaseTapCluster(NULL, NULL, true);  
}

void
TapJob::start(MembaseClient &client)
{
    tapThread = new boost::thread(boost::ref(*this), boost::ref(client)); 
}

void
TapJob::join()
{
    tapThread->join();
}