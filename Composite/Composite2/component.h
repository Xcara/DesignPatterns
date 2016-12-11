//
//  component.hpp
//  Composite2
//
//  Created by xu on 16/12/1.
//  Copyright © 2016 xu. All rights reserved.
//

#ifndef DEBUG
#define DEBUG 0
#endif

#include <list>
#include <string>

using namespace std;

class Composite;

class Component {
public:
    ~Component();
    virtual Composite* GetComposite();
};

class Composite : public Component {
public:
    ~Composite();
    virtual void Add(Component*);
    Composite* GetComposite();
    list<Component*>::iterator Begin();
    list<Component*>::iterator End();
private:
    list<Component*> components;
};

class Leaf : public Component {
public:
    string GetMessage();
};
