//
//  CommandGroup.hpp
//  History
//
//  Created by 徐艺然 on 16/12/29.
//  Copyright © 2016年 徐艺然. All rights reserved.
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
