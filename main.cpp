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
    singlyLinkedList.displayAllNodesSimplified();
    //    qDebug().noquote() << "Length of SinglyLinkedList:" << QString::number(singlyLinkedList.getLength());

    //    singlyLinkedList.deleteList();
    //    singlyLinkedList.clearList();

    //    singlyLinkedList.insertNewNodeAtBeginning(10);
    //    singlyLinkedList.insertNewNodeAtEnd(20);
    //    singlyLinkedList.insertNewNodeAtPosition(2U, 42);

    //    singlyLinkedList.replaceSingleNode(2U, 100);
    //    const QVector<int> vector = {500, 1000, 3000};
    //    singlyLinkedList.replaceMultipleNodes(2U, 4U, vector);

    //    singlyLinkedList.displayAllNodesSimplified();

    return a.exec();
}
