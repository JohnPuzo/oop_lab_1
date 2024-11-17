#include <string>
#include "TextRedactor.h"
#include <iostream>


TextRedactor::TextRedactor(std::string a_text){
    text = a_text;
    cursor = text.size();
    redoNum = 0;
    Stack *Stack2 = new Stack;
    Stack2 -> push(text);
    Stack1 = Stack2;
}



TextRedactor::TextRedactor(){
    text = "";
    cursor = 0;
    Stack *Stack2 = new Stack;
    Stack1 = Stack2;
    redoNum = 0;

}

TextRedactor::TextRedactor(const TextRedactor &a){
    text = a.text;
    cursor = a.cursor;
    Stack *Stack2 = new Stack;
    Stack1 = Stack2;
    redoNum = 0;
}


void TextRedactor::moveCursoreInPosition(int cur){
    if ( cur >= text.size() || cur < 0) {
        std::cout << "Invalid position!" << std::endl;
    } 
    else {
        cursor = cur;
    }
}

void TextRedactor::moveCursoreOutPosition(int cur) {
    if (cursor + cur >= text.size() || cursor + cur < 0) {
        std::cout << "Invalid position!" << std::endl;
    } 
    else {
        cursor += cur;
    }
}

void TextRedactor::moveCursoreInTheEnd(){
    cursor = text.size();
}

void TextRedactor::addText(std::string txt) {
    text.insert(cursor, txt);
    cursor += txt.size();
    Stack1->push(text);
    if (redoNum != 0){
        Stack1->deleteRedo(redoNum);
    }
}

void TextRedactor::removeText(int len){
    if (cursor + len >= text.size() || len < 0){
        std::cout << "Invalid length!" << std::endl;
    }
    else{
        text.erase(cursor, len);
    }
    Stack1->push(text);
    if (redoNum != 0){
        Stack1->deleteRedo(redoNum);
    }
}

void TextRedactor::printText() const{
    std::cout << text << std::endl;
}

void TextRedactor::replacementText(std::string txt){
    text = txt;
    cursor = text.size();
    Stack1->push(text);
    if (redoNum != 0){
        Stack1->deleteRedo(redoNum);
    }
}

void TextRedactor::removalText(){
    text = "";
    cursor = 0;
    Stack1->push(text);
    if (redoNum != 0){
        Stack1->deleteRedo(redoNum);
    }
}

std::string TextRedactor::getText() const {
    return text;
}

int TextRedactor::getCursor() const{
    return cursor;
}

void TextRedactor::undo(){
    if (Stack1->isEmpty()){
        std::cout << "No more undo operations!" << std::endl;
        return;
    }
    redoNum++;
    Stack1->move();
    text = Stack1->top();
    cursor = text.size();
}

void TextRedactor::redo(){
    if (redoNum == 0){
        std::cout << "No more redo operations!" << std::endl;
        return;
    }
    redoNum--;
    text = Stack1->forRedo();
    cursor = text.size();
}
