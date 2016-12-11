//
//  main.cpp
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

int main()
{
    AppEvent *app1 = new AppEvent(500, 11, "imovie", "10.1");
    AppEvent *app2 = new AppEvent(501, 12, "GarageBand", "1.1.2");
    
    SysEvent *sysevt = new SysEvent(502, 50, 30, 10);
    
    Client *clt1 = new Client("127.72.50.51", "loc1", "clt1");
    Client *clt2 = new Client("127.72.50.52", "loc2", "clt2");
    Client *clt3 = new Client("127.72.50.53", "loc3", "clt3");
    
    app1->Attach(clt1);
    app1->Attach(clt2);
    
    app2->Attach(clt2);
    
    app1->Detach(clt2);
    
    sysevt->Attach(clt3);
    sysevt->Attach(clt2);
    sysevt->Attach(clt1);
    
    string ver = "11.1";
    app1->ChangeVersion(ver);
    
    ver = "1.2.1";
    app2->ChangeVersion(ver);
    
    sysevt->ChangeDiskSpace(26);
    
    delete app1;
    delete app2; 
    delete clt1; 
    delete clt2;
    delete clt3;
    delete sysevt;
    
    return 0;
}

