#ifndef STACK_H4C16A066861F4E1690C63D6EC0DA3E31
#define STACK_H4C16A066861F4E1690C63D6EC0DA3E31

class Stack
{
public:
    Stack(const int maxSize, const int top, char* items);
    ~Stack();

    void push(const char data);
    char peak();
    char pop();

    bool isEmpty();
    bool isFull();

private:
    int m_maxSize = 10;
    int m_top = -1;
    char* m_items = nullptr;
};

#endif // STACK_H4C16A066861F4E1690C63D6EC0DA3E31
