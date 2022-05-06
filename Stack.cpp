#include "Stack.h"

#include <QDebug>

Stack::Stack(const int maxSize)
    : m_maxSize(maxSize)
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

void Stack::printValuesOfStack()
{
    if (isEmpty())
    {
        qDebug() << "Nothing can be printed out as the stack is currently empty.";
        return;
    }

    for (int i = 0; i < m_top + 1; i++)
    {
        qDebug() << m_items[i];
    }
}
