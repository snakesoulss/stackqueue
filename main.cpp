#include <iostream>
#include "structures.h"
using namespace std;

int main() {
    Stack<int> intStack;
    Queue<int> intQueue;

    int numStackElements, numQueueElements;

    cout << "Enter the number of elements for the stack: ";
    cin >> numStackElements;
    cout << "Input stack elements:\n";

    for (int i = 0; i < numStackElements; ++i) {
        int value;
        cin >> value;
        intStack.Add(value);
    }

    cout << "Stack content:\n";
    intStack.Display();

    if (!intStack.IsEmpty()) {
        cout << "Top element: " << intStack.Peek() << endl;
        intStack.Remove();
        cout << "Stack after removing the top element:\n";
        intStack.Display();
    }

    cout << "Enter the number of elements for the queue: ";
    cin >> numQueueElements;
    cout << "Input queue elements:\n";

    for (int i = 0; i < numQueueElements; ++i) {
        int value;
        cin >> value;
        intQueue.Enqueue(value);
    }

    cout << "Queue content:\n";
    intQueue.Display();

    if (!intQueue.IsEmpty()) {
        cout << "Front element: " << intQueue.Peek() << endl;
        intQueue.Dequeue();
        cout << "Queue after removing the front element:\n";
        intQueue.Display();
    }

    return 0;
}