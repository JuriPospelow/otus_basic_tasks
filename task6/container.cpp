#include <iostream>
#include <cstring>
#include "SeqContainer.hpp"
#include "List.hpp"

using namespace std;

void testSeqContainer()
{
    cout << "Test class SeqContainer\n";
    SeqContainer <int> c(10);

    for (int i{}; i<10; ++i) {
        c.push_back(i);
    }
    c.print();

    cout << "container size: " << c.size() << endl;

    c.erase(2);
    c.erase(3);
    c.erase(4);
    c.print();

    c.insert(0,10);
    c.print();

    c.insert(c.size()/2,20);
    c.print();

    c.insert(c.size(),30);
    c.print();
}

void testList()
{
    cout << "Test class List\n";
    // sll::SingleLinkedList <int> l;
    dll::DoublyLinkedList <int> l;

    cout << "test push_back:" << endl;
     for (int i{}; i<10; ++i) {
        l.push_back(i);
    }
    l.print();
    cout << "container size: " << l.size() << endl;

    cout << "test operator[]:" << endl;

    cout << "data in node 5: " << l[5] << endl;
    int tmp = l[5];
    cout << "assigned value 123 to data in node 5\n";
    l[5] = 123;
    cout << l[5] << endl;
    cout << "set value again\n";
    l[5] = tmp;
    cout << l[5] << endl;
    cout << "test erase:" << endl;
    l.erase(2);
    l.erase(3);
    l.erase(4);
    l.print();

    l.insert(0,10);
    l.print();

    l.insert(l.size()/2,20);
    l.print();

    l.insert(l.size(),30);
    l.print();
}

int main()
{

    // testSeqContainer();
    testList();


return 0;
}
