//
//  Config.h
//  membase_replicator
//
//  Created by Vivek Y S on 26/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef membase_replicator_Config_h
#define membase_replicator_Config_h

#include<string>

class Config
{
private:
    std::string host;
    std::string user;
    std::string passwd;
    std::string bucket;
    
public:
    Config(const char *host, const char *user, const char *passwd, const char *bucket);
    Config(const Config &copyMe);
    Config & operator=(const Config &assignMe);
    
    std::string getHost();
    void setHost(const char *host)
    {
        this->host = host;
    }
    
    std::string getUser();
    void setUser(const char *user)
    {
        this->user = user;
    }
    
    std::string getPasswd();
    void setPasswd(const char *passwd)
    {
        this->passwd = passwd;
    }
    
    std::string getBucket();
    void setBucket(const char *bucket)
    {
        this->bucket = bucket;
    }
    
    ~Config()
    {
        std::cout << "Config object destroyed" << std::endl;
    }
    
};


#endif
