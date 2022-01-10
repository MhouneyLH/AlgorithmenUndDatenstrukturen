#include <QCoreApplication>
#include "SinglyLinkedList.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    SinglyLinkedList singlyLinkedList;
    singlyLinkedList.createNewNode(0);
    singlyLinkedList.createNewNode(1);
    singlyLinkedList.createNewNode(2);

    return a.exec();
}
