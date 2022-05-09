#ifndef STACK_H4C16A066861F4E1690C63D6EC0DA3E31
#define STACK_H4C16A066861F4E1690C63D6EC0DA3E31

#include <QChar>
#include <QString>

class Stack
{
public:
    Stack(const int maxSize);

    void push(const QChar& data);
    QChar peak() const;
    QChar pop();
    bool isEmpty();
    bool isFull();
    void printValuesOfStack();

private:
    int m_maxSize = 10;
    int m_top = -1;
    QString m_items;
};

#endif // STACK_H4C16A066861F4E1690C63D6EC0DA3E31
