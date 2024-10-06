#include <string>
#include "TextRedactor.h"
#include <iostream>

TextRedactor::TextRedactor(std::string a_text){
    text = a_text;
    cursor = text.size();
}

TextRedactor::TextRedactor(){
    text = "";
    cursor = 0;
}

TextRedactor::TextRedactor(const TextRedactor &a){
    text = a.text;
    cursor = a.cursor;
}

void TextRedactor::moveCursoreInPosition(int cur){
    cursor = cur;
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

void TextRedactor::addText(std::string txt){
    text.insert(cursor, txt);
    cursor += txt.size();
}

void TextRedactor::removeText(int len){
    if (cursor + len >= text.size() || len < 0){
        std::cout << "Invalid length!" << std::endl;
    }
    else{
        text.erase(cursor, len);
    }
}

void TextRedactor::printText() const{
    std::cout << text << std::endl;
}

std::string TextRedactor::getText() const {
    return text;
}

int TextRedactor::getCursor() const{
    return cursor;
}

