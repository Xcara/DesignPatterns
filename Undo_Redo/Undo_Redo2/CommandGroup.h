//
//  CommandGroup.hpp
//  History
//
//  Created by xu on 16/12/29.
//  Copyright © 2016年 xu. All rights reserved.
//
#ifndef DEBUG
#define DEBUG 0
#endif

#include <vector>
#include "ICommand.h"

class CommandGroup : public ICommand {
    
private:
    
    std::vector<ICommand*> commands;
    
    
public:
    
    ~CommandGroup();
    void add( ICommand* command );
    void execute();
    void undo();
    
    
};
