#include "SinglyLinkedList.h"
#include <QCoreApplication>
#include <QVector>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    SinglyLinkedList singlyLinkedList;

    singlyLinkedList.createMultipleNewNodesWithTheSameData(4, 400);
    singlyLinkedList.createMultipleNewNodes(3, {1, 2, 3});

    singlyLinkedList.displayAllNodesSimplified();

    return a.exec();
}
