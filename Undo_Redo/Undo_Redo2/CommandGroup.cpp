//
//  CommandGroup.cpp
//  History
//
//  Created by xu on 16/11/29.
//  Copyright © 2016 xu. All rights reserved.
//

#include "CommandGroup.h"

CommandGroup::~CommandGroup() {
    for ( auto command : commands ) {
        delete command;
    }
}

void CommandGroup::add( ICommand* command ) {
    commands.push_back( command );
}


void CommandGroup::execute() {
    for ( unsigned int i=0; i < commands.size(); i++ ) {
        commands[ i ]->execute();
    }
}


void CommandGroup::undo() {
    for ( unsigned int i=0; i < commands.size(); i++ ) {
        commands[ i ]->undo();
    }
}
