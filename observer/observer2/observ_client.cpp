//
//  observer_client.cpp
//  observer
//
//  Created by 徐艺然 on 16/11/27.
//  Copyright © 2016年 徐艺然. All rights reserved.
//
#ifndef DEBUG
#define DEBUG 0
#endif

#include "observ_client.h"

using namespace std;


void Client::Update(ServerEvents* app, const int& EvtType)
{
    switch(EvtType)
    {
        case APP_EVENT_TYPE :
        {
            cout << "Event consumed by observer client machine IP = " << m_clientIP << endl;
            cout << "Application version updated..." << endl;
            cout << "Application Name = " << app->GetAppName() << endl;
            cout << "New version number = " << app->GetAppVersion() << endl << endl;
            
            break;
        }
            
        case SYS_EVENT_TYPE:
        {
            cout << "Event consumed by observer client machine IP = " << m_clientIP << endl;
            cout << "System stats updated..." << endl;
            cout << "Disk space = " << app->GetDiskSpace() << endl;
            cout << "Memory usage = " << app->GetMemoryUsage() << endl;
            cout << "Temperature = " << app->GetTemperature() << endl << endl;
            
            break;
        }
            
        default:
        {
            cout << "Event type not known... duh!!" << endl << endl;
        }
    }
}
