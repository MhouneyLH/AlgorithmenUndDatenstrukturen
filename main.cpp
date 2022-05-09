#include "SinglyLinkedList.h"
#include "Stack.h"

#include <QCoreApplication>

bool areBracketsBalanced(const QString& expression)
{
    Stack tempStack(expression.length());

    for (int i = 0; i < expression.length(); i++)
    {
        if (tempStack.isEmpty())
        {
            tempStack.push(expression.at(i));
            continue;
        }

        // clang-format off
        if((tempStack.peak() == '(' && expression.at(i) == ')')
          || (tempStack.peak() == '{' && expression.at(i) == '}')
          || (tempStack.peak() == '[' && expression.at(i) == ']'))
        {
            tempStack.pop();
            continue;
        }
        // clang-format on

        tempStack.push(expression[i]);
    }

    if (tempStack.isEmpty())
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    //    SinglyLinkedList singlyLinkedList;
    //    singlyLinkedList.createMultipleNewNodes({1, 2, 3, 4, 2, 3, 4, 2, 23});

    //    singlyLinkedList.displayAllNodesSimplified();

    const QString expression = "{({[]})}";
    if (areBracketsBalanced(expression))
    {
        qDebug() << expression << "is balanced! :)";
    }
    else
    {
        qDebug() << expression << "is not balanced! :(";
    }

    return a.exec();
}
