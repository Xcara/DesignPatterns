//
//  History.hpp
//  History
//
//  Created by 徐艺然 on 16/11/29.
//  Copyright © 2016年 徐艺然. All rights reserved.
//

#ifndef DEBUG
#define DEBUG 0
#endif

#include <vector>

class ICommand;

class History {
    
private:
    
    std::vector<ICommand*> history;
    int lastExecuted;
    int lastSaved;
    
public:
    
    History();
    ~History();
    
    void clear();
    void save();
    bool modified();
    void limit( unsigned int numCommands );
    void add( ICommand* command, bool execute );
    void revert();
    void undo();
    void redo();
    
};