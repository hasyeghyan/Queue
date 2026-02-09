#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "DLL.hpp"

template <typename T>
class Queue 
{
    private:
        DLL<T> list;
    public:
        Queue() = default;
        explicit Queue(const DLL<T>& cont) : list{cont} {}
        explicit Queue(DLL<T>&& cont) : list{std::move(cont)} {}
        Queue(const Queue& other) : list{other.list} {}
        Queue(Queue&& other) noexcept : list{std::move(other.list)} {}
        ~Queue() = default;

        Queue& operator=(const Queue& other);
        Queue& operator=(Queue&& other);

        T& front() { return list.front(); }
        const T& front() const { return list.front(); }
        T& back() { return list.back(); }
        const T& back() const { return list.back(); }

        bool empty() const noexcept { return list.emtpy(); }
        size_t size() const noexcept { return list.get_size(); }

        void push (const T& value) { list.push_back(value); }
        void push(T&& value) { list.push_back(std::move(value)); }
        void pop() { list.pop_front(); }
        void swap(Queue& other) { list.swap(other.list); }

        template <typename U>
        friend bool operator==(const Queue<U>& lhs, const Queue<U>& rhs) { return lhs.list == rhs.list; }
        template <typename U>
        friend bool operator!=(const Queue<U>& lhs, const Queue<U>& rhs) { return !(lhs == rhs); }
        template <typename U>
        friend bool operator<(const Queue<U>& lhs, const Queue<U>& rhs) { return lhs.list < rhs.list; }
        template <typename U>
        friend bool operator<=(const Queue<U>& lhs, const Queue<U>& rhs) { return !(rhs < lhs); }
        template <typename U>
        friend bool operator>(const Queue<U>& lhs, const Queue<U>& rhs) { return rhs < lhs; } 
        template <typename U>
        friend bool operator>=(const Queue<U>& lhs, const Queue<U>& rhs) { return !(lhs < rhs); }
};

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) {
    if (this != &other) {
        list = std::move(other.list);
    }
    return *this;
}

#endif