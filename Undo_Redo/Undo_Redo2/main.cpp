//
//  main.cpp
//  History
//
//  Created by xu on 16/11/29.
//  Copyright © 2016 xu. All rights reserved.
//

#include <iostream>

#include "ICommand.h"
#include "CommandGroup.h"
#include "History.h"

class TestDocument {
public:
    std::string text;
    
    void print() const {
        std::cout << "Document text: " << text << "\n";
    }
};


class TestCommandBase : public ICommand {
protected:
    TestDocument & document;
    
public:
    TestCommandBase( TestDocument & document ) : document( document ) {
    }
};


class TestCommandAppend : public TestCommandBase {
private:
    std::string s;
    
public:
    TestCommandAppend( TestDocument & document, std::string const & s ) : TestCommandBase(document), s(s) {
    }
    
    void execute() {
        document.text += s;
    }
    
    void undo() {
        auto len = document.text.length() - s.length();
        document.text.erase( len );
    }
};

int main( int argc, char *argv[] ) {
    TestDocument document;
    document.text = "Hello, world";
    
    History history;
    
    document.print();
    
    
    history.add( new TestCommandAppend( document, "!" ), true ); // !
    
    document.print();
    
    
    history.add( new TestCommandAppend( document, "!" ), true ); // !!
    
    document.print();
    
    history.add( new TestCommandAppend( document, "!" ), true ); // !!!
    
    document.print();
    
    history.undo(); // !!
    
    document.print();
    
    history.redo(); // !!!
    
    document.print();
    
    history.undo(); // !!
    history.undo(); // !
    
    document.print();
    
    history.add( new TestCommandAppend( document, "X" ), true ); // !X
    
    document.print();
    
    history.undo(); // !
    
    document.print();
    
     history.undo(); //
    
    document.print();
    
    history.redo(); // !
    
    document.print();
    
    history.redo(); // !X
    
    document.print();
    
}
