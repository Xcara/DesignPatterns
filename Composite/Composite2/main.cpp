//
//  main.cpp
//  Composite2
//
//  Created by 徐艺然 on 16/12/1.
//  Copyright © 2016年 徐艺然. All rights reserved.
//

#include <iostream>
#include "component.h"
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    Composite *c = new Composite();
    
    for (int i = 0; i < 10; i++) {
        Leaf* l = new Leaf();
        c->Add(l);
    }
    
    if (c->GetComposite()) {
        for (list<Component*>::iterator it = c->Begin(); it != c->End(); it++) {
            cout << ((Leaf*)(*it))->GetMessage() << endl;
        }
    }
    
    delete c;
    
    return 0;
}