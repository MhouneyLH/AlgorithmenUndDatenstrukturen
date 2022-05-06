#include "Stack.h"

#include <QDebug>

Stack::Stack(const int maxSize, const int top, char* items)
    : m_maxSize(maxSize)
    , m_top(top)
    , m_items(items)
{
}

Stack::~Stack()
{
    m_items = nullptr;
    delete m_items;
}

void Stack::push(const char data)
{
    if (m_top == m_maxSize - 1)
    {
        qDebug() << "Overflow, while pushing on the stack.";
        exit(EXIT_FAILURE);
    }

    m_items[++m_top] = data;
}

char Stack::peak()
{
}

char Stack::pop()
{
    if (m_top == -1)
    {
        qDebug() << "Underflow while popping on the stack.";
        exit(EXIT_FAILURE);
    }

    return m_items[m_top--];
}

bool Stack::isEmpty()
{
}

bool Stack::isFull()
{
}
