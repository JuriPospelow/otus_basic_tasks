#pragma once
using const_iterator = size_t;

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
explicit
       DoublyLinkedList(size_t size = 0);
       ~DoublyLinkedList();

        DoublyLinkedList(const DoublyLinkedList &);
        DoublyLinkedList(DoublyLinkedList &&);

        DoublyLinkedList& operator=(DoublyLinkedList);
        // DoublyLinkedList& operator=(DoublyLinkedList &&);

        void push_back(const T& val);

        size_t size() const
        {
            return _size;
        }
        T& operator[] (size_t n) const
        {
            return list[n].data;
        }
        Node* get_list() const
        {
            return list;
        }

        Node* get_prev(size_t n) const
        {
            return list[n].prev;
        }
        Node* get_next(size_t n) const
        {
            return list[n].next;
        }

        void erase (const_iterator first);

        void insert (const_iterator position, const T& val);

        void print() const;

    private:
        size_t _size{};
        Node* list{};

        void update();
        void _swap(DoublyLinkedList&);
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
explicit
       SingleLinkedList(size_t size = 0);
       ~SingleLinkedList();

        SingleLinkedList(const SingleLinkedList &);
        SingleLinkedList(SingleLinkedList &&);

        SingleLinkedList& operator=(SingleLinkedList );
        // SingleLinkedList& operator=(SingleLinkedList &&);

        void push_back(const T& val);

        size_t size() const
        {
            return _size;
        }
        T& operator[] (size_t n) const
        {
            return list[n].data;
        }
        Node* get_list() const
        {
            return list;
        }
        void erase (const_iterator first);

        void insert (const_iterator position, const T& val);

        void print() const;

    private:
        size_t _size{};
        Node* list{};

        void update();
        void _swap(SingleLinkedList&);
    };
} // end namespace sll


#include "List.tpp"
