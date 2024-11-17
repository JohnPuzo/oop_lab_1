#include <string>


class Stack {
public:
    Stack();                     
    ~Stack();                    
    void push(std::string text); 
    void pop();                  
    std::string top() const;     
    bool isEmpty() const;
    std::string forRedo();
    void deleteRedo(int redoNum);  
    void move();      

private:
    struct node {
        std::string text;        
        node* next;
        node* prev;
    };

    node* topNode;
    node* currNode;               
};
