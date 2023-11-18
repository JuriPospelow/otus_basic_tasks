#include <iostream>
#include <cstring>

using namespace std;
using const_iterator = size_t;

/* template <typename T>
class Container
{
public:
    virtual ~Container() = 0;
    virtual void push_back(const T&) = 0;
    virtual size_t size() const = 0;
    virtual T& operator[] (size_t n) = 0;
    void insert (const_iterator position, const T& val) = 0;
    void erase (const_iterator first, const_iterator last);
};
 */
template <typename T>
class SeqContainer/*  : public Container<T> */
{
public:
    SeqContainer()
    {
        ptr = {};//new T [1];
/*         _size = 1;
        _iter = 0; */
    }
   ~SeqContainer()
    {
        delete[] ptr;
    }

    void push_back(const T& val)
    {
        ++_size;
        // ++_iter;
        T* new_region = new T [_size];
        memcpy(new_region, ptr, (_size-1)*sizeof(T));
        new_region[_size-1] = val;
        delete[] ptr;
        ptr = new_region;
    }
    size_t size() const
    {
        return _size;
    }
    T& operator[] (size_t n)
    {
        return ptr[n];
    }
    void erase (const_iterator first)
    {
        for (size_t i {first}; i < _size; ++i){
            ptr[i] = ptr[i+1];
        }
        --_size;
    }
    void insert (const_iterator position, const T& val)
    {
        if (position == _size){
            push_back(val);
            return;
        }
        ++_size;
        T* new_region = new T [_size];
        new_region[position] = val;

        memcpy(new_region+position+1, ptr+position, (_size - position -1)*sizeof(T));

        if(position != 0) memcpy(new_region, ptr, (position)*sizeof(T));

        delete[] ptr;
        ptr = new_region;
    }

    void print()
    {
        for (size_t i{}; i<_size; ++i) {
            cout << ptr[i]<< " ";
        }
        cout << endl;
    }

private:
    T* ptr{};
    size_t _size{};
    size_t _iter{};
};

template <typename T>
class List/*  : public Container<T> */
{
struct Node {
    Node* next; // указатель на следующий элемент Node
    Node* prev; // указатель на предыдущий элемент Node
    T data; // пользовательские данные (хранимый объект)
};

public:
    List()
    {
        list = {};//new T [1];
/*         _size = 1;
        _iter = 0; */
    }
   ~List()
    {
        delete[] list;
    }

    void push_back(const T& val)
    {
        ++_size;
        // ++_iter;
        Node* new_region = new Node [_size];
        memcpy(new_region, list, (_size-1)*sizeof(Node));
        new_region[_size-1].data = val;
        delete[] list;
        list = new_region;
        update();
    }
    size_t size() const
    {
        return _size;
    }
    T& operator[] (size_t n)
    {
        return list[n].data;
    }
    void erase (const_iterator first)
    {
        for (size_t i {first}; i < _size; ++i){
            list[i] = list[i+1];
        }
        --_size;
        update();
    }
    void insert (const_iterator position, const T& val)
    {
        if (position == _size){
            push_back(val);
            return;
        }
        ++_size;
        Node* new_region = new Node [_size];
        new_region[position].data = val;

        memcpy(new_region+position+1, list+position, (_size - position -1)*sizeof(Node));

        if(position != 0) memcpy(new_region, list, (position)*sizeof(Node));

        delete[] list;
        list = new_region;
        update();
    }

    void print()
    {
        cout << "memory struct: \n";
        for (size_t i{}; i<_size; ++i) {
            // cout << list[i].data<< " ";
            cout << "node: " << i << ", data: " << list[i].data << ", ";
            cout << "addr: " << &list[i] << ", ";
            cout << "addr next node: " << (list[i].next) << ", ";
            cout << "addr prev node: " << (list[i].prev) << "\n";

        }
        cout << endl;
    }

private:
    Node* list{};
    size_t _size{};

    size_t _iter{};
    void update()
    {
        for (size_t i{0}; i < _size; ++i) {
            list[i].prev = (i==0? nullptr : &list[i-1]);
            list[i].next = nullptr;
            if ( i > 0) list[i-1].next = &list[i];
        }
    }

};

void testSeqContainer()
{
    cout << "Test class SeqContainer\n";
    SeqContainer <int> c;

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


int main()
{
    // testSeqContainer();

    cout << "Test class List\n";
    List <int> l;

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

return 0;
}
