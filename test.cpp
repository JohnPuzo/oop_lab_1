#include <string>
#include <cassert>
#include "TextRedactor.h"
#include <iostream>
#include "inheritance.h"



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
    Text1.replacementText("hehehe");
    assert(Text1.getText() == "hehehe" && Text1.getCursor() == 6);
    Text1.removalText();
    assert(Text1.getText() == "" && Text1.getCursor() == 0);
}

void checkTransformer(){
    Transformer Walking(100, 10);
    Walking.run();
    assert(Walking.getlevel() == 90 && Walking.getDamage() == 10);
    Walking.attack();
    assert(Walking.getlevel() == 70);
    Walking.recharge();
    assert(Walking.getlevel() == 100);
    FlyingTransformer Flying(100,10,20);
    Flying.run();
    assert(Flying.getlevel() == 90 && Flying.getDamage() == 10 && Flying.getHeight() == 20);
    Flying.fly();
    assert(Walking.getlevel() == 75);
}

void test(){
    checkConstructor();
    checkRedactor();
    checkTransformer();
    std::cout << "All tests passed" << std::endl;
}