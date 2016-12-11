//
//  ICommand.h
//  History
//
//  Created by xu on 16/11/29.
//  Copyright © 2016 xu. All rights reserved.
//

#pragma once

class ICommand {
    
public:
    
    virtual void execute() = 0;
    
    
    virtual void undo() = 0;
    
    
    virtual ~ICommand() { }
    
};
