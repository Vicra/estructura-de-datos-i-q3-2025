#include <QCoreApplication>
#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Stack s;
    s.push(new StackNode(1));
    s.push(new StackNode(2));
    s.print();
    cout << "Popped: " << s.pop() << endl;
    s.print();
    s.push(new StackNode(3));
    s.print();
    cout << "Peek: " << s.peek() << endl;
    return a.exec();
}
