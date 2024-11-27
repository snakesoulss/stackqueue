#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;
    ~Stack();

    void Add(const T& value);       // Push
    void Remove();                 // Pop
    bool IsEmpty() const;
    T& Peek();
    const T& Peek() const;
    void Display() const;

private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };

    Node* top;

    void Clear();
    void CopyFrom(const Stack& other);
};

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::Stack(const Stack& other) : top(nullptr) {
    CopyFrom(other);
}

template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : top(other.top) {
    other.top = nullptr;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        Clear();
        CopyFrom(other);
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        Clear();
        top = other.top;
        other.top = nullptr;
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    Clear();
}

template <typename T>
void Stack<T>::Add(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::Remove() {
    if (IsEmpty()) {
        throw runtime_error("Stack is empty");
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

template <typename T>
T& Stack<T>::Peek() {
    if (IsEmpty()) throw runtime_error("Stack is empty");
    return top->value;
}

template <typename T>
const T& Stack<T>::Peek() const {
    if (IsEmpty()) throw runtime_error("Stack is empty");
    return top->value;
}

template <typename T>
void Stack<T>::Display() const {
    Node* current = top;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void Stack<T>::Clear() {
    while (!IsEmpty()) {
        Remove();
    }
}

template <typename T>
void Stack<T>::CopyFrom(const Stack& other) {
    if (!other.top) return;

    Node* source = other.top;
    top = new Node(source->value);
    Node* target = top;
    source = source->next;

    while (source) {
        target->next = new Node(source->value);
        target = target->next;
        source = source->next;
    }
}

// Queue Implementation
template <typename T>
class Queue {
public:
    Queue();
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other) noexcept;
    ~Queue();

    void Enqueue(const T& value);
    void Dequeue();
    bool IsEmpty() const;
    T& Peek();
    const T& Peek() const;
    void Display() const;

private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

    void Clear();
    void CopyFrom(const Queue& other);
};

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::Queue(const Queue& other) : front(nullptr), rear(nullptr) {
    CopyFrom(other);
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept : front(other.front), rear(other.rear) {
    other.front = nullptr;
    other.rear = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        Clear();
        CopyFrom(other);
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        Clear();
        front = other.front;
        rear = other.rear;
        other.front = nullptr;
        other.rear = nullptr;
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    Clear();
}

template <typename T>
void Queue<T>::Enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (IsEmpty()) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
}

template <typename T>
bool Queue<T>::IsEmpty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::Dequeue() {
    if (IsEmpty()) {
        throw runtime_error("Queue is empty");
    }
    Node* temp = front;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
}

template <typename T>
T& Queue<T>::Peek() {
    if (IsEmpty()) throw runtime_error("Queue is empty");
    return front->value;
}

template <typename T>
const T& Queue<T>::Peek() const {
    if (IsEmpty()) throw runtime_error("Queue is empty");
    return front->value;
}

template <typename T>
void Queue<T>::Display() const {
    Node* current = front;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void Queue<T>::Clear() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

template <typename T>
void Queue<T>::CopyFrom(const Queue& other) {
    if (!other.front) return;

    Node* source = other.front;
    while (source) {
        Enqueue(source->value);
        source = source->next;
    }
}
#endif // STACKQUEUE_H
