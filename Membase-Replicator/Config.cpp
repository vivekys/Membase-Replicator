//
//  Config.cpp
//  membase_replicator
//
//  Created by Vivek Y S on 26/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Config.h"
using namespace std;

Config::Config(const char *host, const char *user, const char *passwd, const char *bucket)
{
    if (host != NULL)
        this->host = host;
    if (user != NULL) 
        this->user = user;
    if (passwd == NULL) 
        this->passwd = "";
    else
        this->passwd = passwd;
    if (bucket != NULL) 
        this->bucket = bucket;
}

Config::Config(const Config &copyMe)
{
    this->host = copyMe.host;
    this->user = copyMe.user;
    this->passwd = copyMe.passwd;
    this->bucket = copyMe.bucket;
    
}
               
Config& Config::operator=(const Config &assignMe)
{
    if (this != & assignMe) {
        this->host = assignMe.host;
        this->user = assignMe.user;
        this->passwd = assignMe.passwd;
        this->bucket = assignMe.bucket;
    }
    return *this;
}

string Config::getHost()
{
    return host;
}

string Config::getUser()
{
    return user;
}

string Config::getPasswd()
{
    return passwd;
}

string Config::getBucket()
{
    return bucket;
}

