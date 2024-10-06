#include <string>

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
        std::string getText() const;
        int getCursor() const;

    
    private:
        std::string text;
        int cursor;
};