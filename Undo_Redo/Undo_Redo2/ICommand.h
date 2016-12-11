//
//  ICommand.h
//  History
//
//  Created by 徐艺然 on 16/11/29.
//  Copyright © 2016年 徐艺然. All rights reserved.
//

#pragma once

class ICommand {
    
public:
    
    virtual void execute() = 0;
    
    
    virtual void undo() = 0;
    
    
    virtual ~ICommand() { }
    
};
