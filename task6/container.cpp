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

int main()
{
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


return 0;
}
