//
//  observ_client.h
//  observer
//
//  Created by 徐艺然 on 16/11/27.
//  Copyright © 2016年 徐艺然. All rights reserved.
//

#ifndef observ_client_h
#define observ_client_h

#include <iostream>

#include "observ_application.h"

class IClient
{
public:
    virtual void 	Update(ServerEvents* app, const int& EvtType)=0;
    virtual string 	getClientIP() = 0;
};


class Client : public IClient
{
public:
    Client(const string cltIP,
           const string cltLoc,
           const string mcName)
    : m_clientIP(cltIP)
    , m_clientLocation(cltLoc)
    , m_machineName(mcName)
    {
#ifdef DEBUG
        cout << "New observer Client with IP " << cltIP << " registered. " << endl;
#endif
    }
    
    void Update(ServerEvents*, const int&);
    string getClientIP() { return m_clientIP; }
    
private:
    string m_clientIP;
    string m_clientLocation;
    string m_machineName;
    
    Client();
};


#endif 
