//
//  observ_application.hpp
//  observer
//
//  Created by xu on 16/11/27.
//  Copyright © 2016 xu. All rights reserved.
//


#ifndef _OBSERV_APPLICATION_H_
#define _OBSERV_APPLICATION_H_

// 事件种类

#define APP_EVENT_TYPE 	111
#define SYS_EVENT_TYPE 	112


#include <iostream>
#include <string>
#include <list>

using namespace std;

class IClient;

// 事件框架基本类

class ServerEvents
{
public:
    ServerEvents(string ServerIP):m_ServerIP(ServerIP){}
    ServerEvents(unsigned int eventID):m_EventID(eventID){}
    
    virtual 		~ServerEvents()=0;
    
    unsigned int 	getEventID(){ return m_EventID; }
    
    void 			Attach(IClient* clt);
    void 			Detach(IClient* clt);
    
    void 			Notify(const int& EventType);
    
    
    // AppEvent class
    virtual unsigned int GetAppID(){return 0;}
    virtual string GetAppName(){return 0;}
    virtual string GetAppVersion(){return 0;}
    
    // SysEvent class
    virtual int GetDiskSpace(){ return 0; }
    virtual int GetMemoryUsage(){ return 0; }
    virtual int GetTemperature(){ return 0; }
    
protected:
    
    ServerEvents(){}
    
private:
    unsigned int	m_EventID;
    string 			m_ServerIP;
    list<IClient*> 	m_cltList;
};


class AppEvent : public ServerEvents
{
public:
    AppEvent(const unsigned int eventID,
             const unsigned int appID,
             const string appName,
             const string appVersion)
				: ServerEvents(eventID)
				, m_appID(appID)
                , m_appName(appName)
                , m_appVersion(appVersion)
    {
#ifdef DEBUG
        cout << "New AppEvent with Event ID " << getEventID() << " registered. " << endl;
#endif
    }
    
    ~AppEvent();
    
    unsigned int 	GetAppID();
    string 			GetAppName();
    string 			GetAppVersion();
    
    void ChangeVersion(string&);
private:
    unsigned int 	m_appID;
    string			m_appName;
    string			m_appVersion;
    
};

class SysEvent : public ServerEvents
{
public:
    SysEvent(const unsigned int eventID,
             const int ds,
             const int mu,
             const int tem)
    : ServerEvents(eventID)
    , m_diskSpace(ds)
    , m_memoryUsage(mu)
    , m_temperature(tem)
    {
#ifdef DEBUG
        cout << "New SysEvent with Event ID " << getEventID() << " registered." << endl;
#endif
    }
    ~SysEvent();
    
    int GetDiskSpace();
    int GetMemoryUsage();
    int GetTemperature();
    
    void ChangeDiskSpace(const int&);
private:
    int 	m_diskSpace;
    int		m_memoryUsage;
    int		m_temperature;
};

#endif
