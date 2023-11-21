#include <iostream>
#include <cstring>
#include "SeqContainer.hpp"
#include "List.hpp"

using namespace std;

void help()
{
    cout << "Usage:" << endl;
    cout << "-sc X, test sequence containers,\n"
         << "    X - factor for free place [0..2],\n";
    cout << "    0 - without free place, 0.5 - factory settings" << endl;
    cout << "-sll - test single linked list" << endl;
    cout << "-dll - test doubly linked list" << endl;
}

void testSeqContainer(double factor)
{
    cout << "Test class SeqContainer with factor: ";
    cout << factor<< endl << endl;
    SeqContainer <int> c(factor);

    cout << "push_back(): ";
    for (int i{}; i<10; ++i) {
        c.push_back(i);
    }
    c.print();

    cout << "container size: " << c.size() << endl;

    cout << "erase(): ";
    c.erase(2);
    c.erase(3);
    c.erase(4);
    c.print();

    cout << "insert(): \n";
    c.insert(0,10);
    c.print();

    c.insert(c.size()/2,20);
    c.print();

    c.insert(c.size(),30);
    c.print();

    cout << "copy container:\n";
    SeqContainer <int> d = c;
    cout << "new container = old container!\n";
    d.print();

    cout << "assigned container:\n";
    cout << "insert(): \n";
    c.insert(0,100);
    d = c;
    cout << &d <<": ";
    d.print();
    cout << &c <<": ";
    c.print();

    cout << "move container:\n";
    SeqContainer <int> m = move(c);
    cout << &m <<": "; m.print();

    cout << "move assigned container:\n";
    cout << "insert(): \n";
    d.insert(0,1000);
    SeqContainer<int> a(2);
    a = move(d);
    cout << &a <<": ";
    a.print();
    cout << &d <<": ";
    d.print();
    cout << "container is empty! = ok\n";

}
template <typename L>
void testList(L & l)
{
    cout << "Test class List\n";

    cout << "push_back():" << endl;
     for (int i{}; i<10; ++i) {
        l.push_back(i);
    }
    l.print();
    cout << "container size: " << l.size() << endl;

    cout << "operator[]:" << endl;

    cout << "data in node 5: " << l[5] << endl;
    int tmp = l[5];
    cout << "assigned value 123 to data in node 5\n";
    l[5] = 123;
    cout << l[5] << endl;
    cout << "set value again\n";
    l[5] = tmp;
    cout << l[5] << endl;
    cout << "erase():" << endl;
    l.erase(2);
    l.erase(3);
    l.erase(4);
    l.print();

    cout << "insert():" << endl;
    l.insert(0,10);
    l.print();

    l.insert(l.size()/2,20);
    l.print();

    l.insert(l.size(),30);
    l.print();
}

int main(int argc, char** argv)
{
    if (argc >= 2 && argc < 4) {
      std::string arg1_value{ argv[1] };
        if (arg1_value == "-sc") {
            auto factor = argv[2] != 0 ? std::stoi(argv[2]) : 0.5;
            testSeqContainer(factor);
            return 0;
        } else if (arg1_value == "-sll") {
            sll::SingleLinkedList <int> l;
            testList(l);
            return 0;
        } else if (arg1_value == "-dll") {
            dll::DoublyLinkedList <int> l;
            testList(l);
            return 0;
        }
    } else {
            help();
            cout << "\nfor example: ./container -sc 0:\n\n";
            testSeqContainer(0);
            return 0;
    }

return 0;
}
