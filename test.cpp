#include <string>
#include <cassert>
#include "TextRedactor.h"
#include <iostream>


void checkConstructor(){
    TextRedactor Text1;
    assert(Text1.getText() == "" && Text1.getCursor() == 0);
    TextRedactor Text2("hello");
    assert(Text2.getText() == "hello" && Text2.getCursor() == 5);
}

void checkRedactor(){
    TextRedactor Text1("hello");
    Text1.moveCursoreInPosition(3);
    assert(Text1.getCursor() == 3);
    Text1.moveCursoreInTheEnd();
    assert(Text1.getCursor() == 5);
    Text1.moveCursoreOutPosition(2);
    assert(Text1.getCursor() == 5);
    Text1.moveCursoreOutPosition(-2);
    assert(Text1.getCursor() == 3);
    Text1.addText("oo");
    assert(Text1.getText() == "heloolo" && Text1.getCursor() == 5);
    Text1.moveCursoreInPosition(0);
    Text1.removeText(2);
    assert(Text1.getText() == "loolo" && Text1.getCursor() == 0);
    Text1.printText();
}

void test(){
    checkConstructor();
    checkRedactor();
    std::cout << "All tests passed" << std::endl;
}