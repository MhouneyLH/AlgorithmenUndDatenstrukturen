#include "Stack.h"

#include <QDebug>

Stack::Stack(const int maxSize, const int top)
    : m_maxSize(maxSize)
    , m_top(top)
{
    m_items = (char*)(malloc(sizeof(char) * maxSize));
}

Stack::~Stack()
{
    m_items = nullptr;
    delete m_items;
}

void Stack::push(const char data)
{
    if (isFull())
    {
        qDebug() << "Overflow, while pushing on the stack.";
        exit(EXIT_FAILURE);
    }

    m_items[++m_top] = data;
}

char Stack::pop()
{
    if (isEmpty())
    {
        qDebug() << "Underflow while popping on the stack.";
        exit(EXIT_FAILURE);
    }

    return m_items[m_top--];
}

bool Stack::isEmpty()
{
    return m_top == -1;
}

bool Stack::isFull()
{
    return m_top == m_maxSize - 1;
}
