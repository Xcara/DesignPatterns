//
//  component.cpp
//  Composite2
//
//  Created by 徐艺然 on 16/12/1.
//  Copyright © 2016年 徐艺然. All rights reserved.
//

#include "component.h"
#include <iostream>

using namespace std;


Component::~Component() {
    cout << "Delete" << endl;
}

Composite::~Composite() {
    for (list<Component* >::iterator it = components.begin(); it != components.end(); it++) {
        delete *it;
    }
}

Composite* Component::GetComposite() {
    return nullptr;
}

Composite* Composite::GetComposite() {
    return this;
}

list<Component*>::iterator Composite::Begin() {
    return this->components.begin();
}

list<Component*>::iterator Composite::End() {
    return this->components.end();
}

void Composite::Add(Component* component) {
    this->components.push_back(component);
}

string Leaf::GetMessage() {
    return "Leaf";
}

