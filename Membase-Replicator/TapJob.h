//
//  TapJob.h
//  Membase-Replicator
//
//  Created by Vivek Y S on 05/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Membase_Replicator_TapJob_h
#define Membase_Replicator_TapJob_h

#include <boost/thread.hpp>  
#include "MembaseClient.h"

class TapJob
{
private:
    boost::thread* tapThread;
    
public:
    void start(MembaseClient &client);

    void join();
    
    void operator() (MembaseClient &client);
    
    ~TapJob()
    {
        delete tapThread;
    }
};


#endif
