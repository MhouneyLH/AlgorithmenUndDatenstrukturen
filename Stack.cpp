#include "Stack.h"

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

void Stack::push(Stack* stack, const char data)
{
}

char Stack::peak(Stack* stack)
{
}

char Stack::pop(Stack* stack)
{
}

bool Stack::isEmpty(Stack* stack)
{
}

bool Stack::isFull(Stack* stack)
{
}
