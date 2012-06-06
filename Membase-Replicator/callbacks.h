//
//  callbacks.h
//  Membase-Replicator
//
//  Created by Vivek Y S on 31/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Membase_Replicator_callbacks_h
#define Membase_Replicator_callbacks_h

#include <string>

typedef void (*insertCallback) (std::string &key, std::string &value);
typedef void (*readCallback) (std::string &key, std::string &value);
typedef void (*ackCallback) (std::string &key, std::string &value);
typedef void (*dequeueCallback) (std::string &key, std::string &value);

#endif
