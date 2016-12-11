//
//  observ_application.cpp
//  observer
//
//  Created by 徐艺然 on 16/11/27.
//  Copyright © 2016年 徐艺然. All rights reserved.
//

#ifndef DEBUG
#define DEBUG 0
#endif

#include "observ_application.h"
#include "observ_client.h"

using namespace std;

ServerEvents::~ServerEvents()
{
}

void ServerEvents::Attach(IClient* clt)
{
#ifdef DEBUG
    cout << "Observer client with IP " << clt->getClientIP() << " STARTED observing " << this->getEventID() << endl;
#endif
    m_cltList.push_back(clt);
}

// 接下来的算法：移除特定客户端

void ServerEvents::Detach(IClient* clt)
{
#ifdef DEBUG
    cout << "Observer client with IP " << clt->getClientIP() << " STOPPED observing " << this->getEventID() << endl;
#endif
    m_cltList.remove(clt);
}

void ServerEvents::Notify(const int& EvtType)
{
    list<IClient*>::iterator lc_iter;
    for(lc_iter=m_cltList.begin(); lc_iter!=m_cltList.end(); lc_iter++)
    {
        (*lc_iter)->Update(this, EvtType);
    }
}

// AppEvent class

void AppEvent::ChangeVersion(string &newVer)
{
#ifdef DEBUG
    cout << "== AppEvent " << getEventID() << " fired  from ChangeVersion ==" << endl;
#endif
    m_appVersion = newVer;
    Notify(APP_EVENT_TYPE);
}


AppEvent::~AppEvent()
{
}

unsigned int AppEvent::GetAppID()
{
    return m_appID;
}

string AppEvent::GetAppName()
{
    return m_appName;
}

string AppEvent::GetAppVersion()
{
    return m_appVersion;
}

// SysEvent class

SysEvent::~SysEvent()
{
}

int SysEvent::GetDiskSpace()
{
    return m_diskSpace;
}

int SysEvent::GetMemoryUsage()
{
    return m_memoryUsage;
}

int SysEvent::GetTemperature()
{
    return m_temperature;
}

void SysEvent::ChangeDiskSpace(const int& ds)
{
#ifdef DEBUG
    cout << "== SysEvent " << getEventID() << " fired  from ChangeDiskSpace ==" << endl;
#endif
    m_diskSpace = ds;
    Notify(SYS_EVENT_TYPE);
}
