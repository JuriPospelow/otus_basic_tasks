#pragma once

namespace dll
{
    template <typename T>
    class DoublyLinkedList
    {
    struct Node {
        Node* next; // указатель на следующий элемент Node
        Node* prev; // указатель на предыдущий элемент Node
        T data; // пользовательские данные (хранимый объект)
    };

    public:

       ~DoublyLinkedList()
        {
            delete[] list;
        }

        void push_back(const T& val);

        size_t size() const
        {
            return _size;
        }
        T& operator[] (size_t n) const
        {
            return list[n].data;
        }
        void erase (const_iterator first);

        void insert (const_iterator position, const T& val);

        void print() const;

    private:
        Node* list{};
        size_t _size{};

        size_t _iter{};
        void update();
    };
} // end namespace dll

namespace sll
{
    template <typename T>
    class SingleLinkedList
    {
    struct Node {
        Node* next; // указатель на следующий элемент Node
        T data; // пользовательские данные (хранимый объект)
    };

    public:

       ~SingleLinkedList()
        {
            delete[] list;
        }

        void push_back(const T& val);

        size_t size() const
        {
            return _size;
        }
        T& operator[] (size_t n) const
        {
            return list[n].data;
        }
        void erase (const_iterator first);

        void insert (const_iterator position, const T& val);

        void print() const;

    private:
        Node* list{};
        size_t _size{};

        size_t _iter{};
        void update();
    };
} // end namespace sll


#include "List.cpp"
