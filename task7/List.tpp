#include <iostream>
#include <cstring>

#include "List.hpp"

using namespace std;

namespace dll
{
    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList(size_t size)
    : _size(size), list(size==0 ? nullptr : new Node [_size])
    {
#ifdef DEBUG
        cout << "constructor: " << this << endl;
#endif
    }
    template <typename T>
    DoublyLinkedList<T>::~DoublyLinkedList()
    {
        delete[] list;
#ifdef DEBUG
        cout << "destructor: " << this << endl;
#endif
    }
    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other)
    : DoublyLinkedList(other._size)
    {
        uninitialized_copy(other.list, other.list + _size, list);
        update();
#ifdef DEBUG
        cout << "copy constructor: " << this << endl;
#endif
    }

    template <typename T>
    void DoublyLinkedList<T>::_swap(DoublyLinkedList& other)
    {
        swap(_size, other._size);
        swap(list, other.list);
    }

    template <typename T>
    DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList other)
    {
        _swap(other);
#ifdef DEBUG
        cout << "operator=: " << this << endl;
#endif
        return *this;
    }


    template <typename T>
    DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList && other)
    {
        _swap(other);

        other.list = nullptr;
        other._size = 0;
#ifdef DEBUG
        cout << "move constructor: " << this << endl;
#endif
    }

    template <typename T>
    void DoublyLinkedList<T>::push_back(const T& val)
    {
        Node* new_region = new Node [_size+1];
        uninitialized_copy(list, list + _size, new_region);
        new_region[_size].data = val;

        swap(list, new_region);
        ++_size;
        update();
        delete [] new_region;
    }

    template <typename T>
    void DoublyLinkedList<T>::erase(const_iterator first)
    {
        for (size_t i {first}; i < _size-1; ++i){
            list[i] = list[i+1];
        }
        --_size;
        update();
    }

    template <typename T>
    void DoublyLinkedList<T>::insert(const_iterator position, const T& val)
    {
        if (position == _size){
            push_back(val);
            return;
        }

        Node* new_region = new Node [_size+1];
        new_region[position].data = val;

        uninitialized_copy(list+position, list + _size, new_region+position+1);
        if(position != 0) uninitialized_copy(list, list+position, new_region);

        swap(list, new_region);
        ++_size;
        update();
        delete [] new_region;
    }

    template <typename T>
    void DoublyLinkedList<T>::print() const
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

    template <typename T>
    void DoublyLinkedList<T>::update()
    {
        for (size_t i{0}; i < _size; ++i) {
            list[i].prev = (i==0? nullptr : &list[i-1]);
            list[i].next = nullptr;
            if ( i > 0) list[i-1].next = &list[i];
        }
    }
} // end namespace dll

namespace sll
{
    template <typename T>
    SingleLinkedList<T>::SingleLinkedList(size_t size)
    : _size(size), list(size==0 ? nullptr : new Node [_size])
    {
        cout << "constructor: " << this << endl;
    }

    template <typename T>
    SingleLinkedList<T>::~SingleLinkedList()
    {
        delete[] list;
        cout << "destructor: " << this << endl;
    }
    template <typename T>
    SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList &other)
     : SingleLinkedList(other._size)
    {
        uninitialized_copy(other.list, other.list + _size, list);
        update();
        cout << "copy constructor: " << this << endl;
    }

    template <typename T>
    void SingleLinkedList<T>::_swap(SingleLinkedList& other)
    {
        swap(_size, other._size);
        swap(list, other.list);
    }

    template <typename T>
    SingleLinkedList<T>& SingleLinkedList<T>::operator=(SingleLinkedList other)
    {
        _swap(other);
        cout << "operator=: " << this << endl;
        return *this;
    }


    template <typename T>
    SingleLinkedList<T>::SingleLinkedList(SingleLinkedList && other)
    {
        _swap(other);

        other.list = nullptr;
        other._size = 0;
        cout << "move constructor: " << this << endl;
    }

    template <typename T>
    void SingleLinkedList<T>::push_back(const T& val)
    {
        Node* new_region = new Node [_size+1];
        uninitialized_copy(list, list + _size, new_region);
        new_region[_size].data = val;

        swap(list, new_region);
        ++_size;
        update();
        delete [] new_region;
    }

    template <typename T>
    void SingleLinkedList<T>::erase(const_iterator first)
    {
        for (size_t i {first}; i < _size-1; ++i){
            list[i] = list[i+1];
        }
        --_size;
        update();
    }

    template <typename T>
    void SingleLinkedList<T>::insert(const_iterator position, const T& val)
    {
        if (position == _size){
            push_back(val);
            return;
        }
        Node* new_region = new Node [_size+1];
        new_region[position].data = val;

        uninitialized_copy(list+position, list + _size, new_region+position+1);
        if(position != 0) uninitialized_copy(list, list+position, new_region);

        swap(list, new_region);
        ++_size;
        update();
        delete [] new_region;
    }

    template <typename T>
    void SingleLinkedList<T>::print() const
    {
        cout << "memory struct: \n";
        for (size_t i{}; i<_size; ++i) {
            // cout << list[i].data<< " ";
            cout << "node: " << i << ", data: " << list[i].data << ", ";
            cout << "addr: " << &list[i] << ", ";
            cout << "addr next node: " << (list[i].next) << "\n";
        }
        cout << endl;
    }

    template <typename T>
    void SingleLinkedList<T>::update()
    {
        for (size_t i{0}; i < _size; ++i) {
            list[i].next = nullptr;
            if ( i > 0) list[i-1].next = &list[i];
        }
    }
} // end namespace sll