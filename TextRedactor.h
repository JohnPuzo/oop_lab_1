#include <string>
#include "Stack.h"

class TextRedactor
{
    public:
        TextRedactor(std::string a_text);
        TextRedactor();
        TextRedactor(const TextRedactor &a);

        void moveCursoreInPosition(int cur);
        void moveCursoreOutPosition(int cur);
        void moveCursoreInTheEnd();
        void addText(std::string txt);
        void removeText(int len);
        void printText() const;
        void replacementText(std::string txt);
        void removalText();
        std::string getText() const;
        int getCursor() const;
        void undo();
        void redo();

    
    private:
        std::string text;
        int cursor;
        int redoNum;
        Stack *Stack1;
};