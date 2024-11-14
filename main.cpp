#include "StackQueue.h"
#include <iostream>

int main() {
    Stack<int> stack;
    Queue<int> queue;

    // Работа со стеком
    std::cout << "Stack operations:" << std::endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    std::cout << "Stack: " << stack << std::endl;
    stack.Pop();
    std::cout << "After Pop: " << stack << std::endl;

    // Работа с очередью
    std::cout << "Queue operations:" << std::endl;
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    std::cout << "Queue: " << queue << std::endl;
    queue.Pop();
    std::cout << "After Pop: " << queue << std::endl;

    return 0;
}
