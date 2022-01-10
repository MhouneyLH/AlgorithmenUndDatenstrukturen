#include <QCoreApplication>
#include "SinglyLinkedList.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    SinglyLinkedList singlyLinkedList;
    singlyLinkedList.createNewNode(0);
    singlyLinkedList.createNewNode(1);
    singlyLinkedList.createNewNode(2);
    singlyLinkedList.createNewNode(3);
    singlyLinkedList.createNewNode(4);
    singlyLinkedList.displayAllNodesSimplified();

    singlyLinkedList.insertNewNodeAtBeginning(10);
    singlyLinkedList.displayAllNodesSimplified();

    singlyLinkedList.insertNewNodeAtEnd(20);
    singlyLinkedList.displayAllNodesSimplified();

    return a.exec();
}
