#include "SinglyLinkedList.h"
#include <QCoreApplication>
#include <QVector>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    SinglyLinkedList singlyLinkedList;
    singlyLinkedList.createNewNode(0);
    singlyLinkedList.createNewNode(1);
    singlyLinkedList.createNewNode(2);
    singlyLinkedList.createNewNode(3);
    singlyLinkedList.createNewNode(4);
    singlyLinkedList.createNewNode(5);
    singlyLinkedList.createNewNode(6);
    singlyLinkedList.displayAllNodesSimplified();

    return a.exec();
}
