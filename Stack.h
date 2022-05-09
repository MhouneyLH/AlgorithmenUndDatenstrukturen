#ifndef STACK_H4C16A066861F4E1690C63D6EC0DA3E31
#define STACK_H4C16A066861F4E1690C63D6EC0DA3E31

#include <QChar>
#include <QString>

// a datastructure of type LIFO
class Stack
{
public:
    Stack(const int maxSize);

    // give data on top of stack
    void push(const QChar& data);
    // look, whats on top of the stack
    QChar peak() const;
    // remove the item that is on top of the stack
    QChar pop();
    bool isEmpty();
    bool isFull();
    // prints out every value of the stack
    void printValuesOfStack();

private:
    int m_maxSize = 10;
    int m_top = -1;
    QString m_items;
};

#endif // STACK_H4C16A066861F4E1690C63D6EC0DA3E31
