#include "SinglyLinkedList.h"
#include <QCoreApplication>
#include <QVector>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    SinglyLinkedList singlyLinkedList;
    singlyLinkedList.createMultipleNewNodes({1, 2, 3, 4, 2, 3, 4, 2, 23});
    QVector<int> vec = singlyLinkedList.findFirstNodeDataPattern({1, 1}); // @TODO: why 2 elements???

    singlyLinkedList.displayAllNodesSimplified();

    return a.exec();
}
