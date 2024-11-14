#include "StackQueue.h"

template <typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template <typename T>
Stack<T>::Stack(const Stack& other) : top(nullptr), size(0) {
    Node<T>* temp = other.top;
    Stack<T> reverseTemp;
    while (temp) {
        reverseTemp.Push(temp->data);
        temp = temp->next;
    }
    temp = reverseTemp.top;
    while (temp) {
        Push(temp->data);
        temp = temp->next;
    }
}

template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : top(other.top), size(other.size) {
    other.top = nullptr;
    other.size = 0;
}

template <typename T>
Stack<T>::~Stack() {
    Clear();
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        Clear();
        Stack temp(other);
        std::swap(top, temp.top);
        size = other.size;
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        Clear();
        top = other.top;
        size = other.size;
        other.top = nullptr;
        other.size = 0;
    }
    return *this;
}

template <typename T>
void Stack<T>::Push(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    ++size;
}

template <typename T>
void Stack<T>::Pop() {
    if (IsEmpty()) throw std::out_of_range("Stack is empty");
    Node<T>* temp = top;
    top = top->next;
    delete temp;
    --size;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return top == nullptr;
}

template <typename T>
T& Stack<T>::GetFront() const {
    if (IsEmpty()) throw std::out_of_range("Stack is empty");
    return top->data;
}

template <typename T>
void Stack<T>::Clear() {
    while (!IsEmpty()) Pop();
}

template <typename T>
size_t Stack<T>::GetSize() const {
    return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
    Node<T>* temp = stack.top;
    while (temp) {
        os << temp->data << " ";
        temp = temp->next;
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Stack<T>& stack) {
    T value;
    while (is >> value) {
        stack.Push(value);
    }
    return is;
}

// ====================== Реализация класса Queue ======================

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0) {}

template <typename T>
Queue<T>::Queue(const Queue& other) : front(nullptr), rear(nullptr), size(0) {
    Node<T>* temp = other.front;
    while (temp) {
        Push(temp->data);
        temp = temp->next;
    }
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept : front(other.front), rear(other.rear), size(other.size) {
    other.front = other.rear = nullptr;
    other.size = 0;
}

template <typename T>
Queue<T>::~Queue() {
    Clear();
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        Clear();
        Node<T>* temp = other.front;
        while (temp) {
            Push(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        Clear();
        front = other.front;
        rear = other.rear;
        size = other.size;
        other.front = other.rear = nullptr;
        other.size = 0;
    }
    return *this;
}

template <typename T>
void Queue<T>::Push(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (IsEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    ++size;
}

template <typename T>
void Queue<T>::Pop() {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");
    Node<T>* temp = front;
    front = front->next;
    delete temp;
    if (!front) rear = nullptr;
    --size;
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return front == nullptr;
}

template <typename T>
T& Queue<T>::GetFront() const {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");
    return front->data;
}

template <typename T>
void Queue<T>::Clear() {
    while (!IsEmpty()) Pop();
}

template <typename T>
size_t Queue<T>::GetSize() const {
    return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
    Node<T>* temp = queue.front;
    while (temp) {
        os << temp->data << " ";
        temp = temp->next;
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Queue<T>& queue) {
    T value;
    while (is >> value) {
        queue.Push(value);
    }
    return is;
}
