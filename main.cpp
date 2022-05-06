#include "SinglyLinkedList.h"
#include "Stack.h"

#include <QCoreApplication>

static const char BRACKET_1_1 = '(';
static const char BRACKET_1_2 = ')';
static const char BRACKET_2_1 = '{';
static const char BRACKET_2_2 = '}';
static const char BRACKET_3_1 = '[';
static const char BRACKET_3_2 = ']';

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    //    SinglyLinkedList singlyLinkedList;
    //    singlyLinkedList.createMultipleNewNodes({1, 2, 3, 4, 2, 3, 4, 2, 23});

    //    singlyLinkedList.displayAllNodesSimplified();

    for (int i = 1; i < argc; i++)
    {
    }

    Stack stack(10);
    stack.push('(');
    stack.push('{');
    stack.push('[');
    stack.push(']');
    stack.push('}');
    stack.push(')');
    stack.printValuesOfStack();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.printValuesOfStack();

    return a.exec();
}
