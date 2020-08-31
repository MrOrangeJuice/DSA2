#include <iostream>
#include "queue.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main()
{
    // Make priority queues
    PriorityQueue<int> intPriorityQueue = PriorityQueue<int>();
    PriorityQueue<char> charPriorityQueue = PriorityQueue<char>();
    PriorityQueue<double> doublePriorityQueue = PriorityQueue<double>();
    // Make data for queues
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    char char1 = 'a';
    char char2 = 'b';
    char char3 = 'c';
    double double1 = 56;
    double double2 = 2;
    double double3 = 862;
    // Print int queue
    if (intPriorityQueue.IsEmpty()) {
        cout << "Priority queue is currently empty" << endl;
    }
    else {
        cout << "Priority queue is currently not empty" << endl;
    }
    cout << "Add 3,2,1 to int priority queue to test sorting" << endl;
    intPriorityQueue.Push(data3);
    intPriorityQueue.Push(data2);
    intPriorityQueue.Push(data1);
    intPriorityQueue.Print();
    cout << endl;
    cout << "Pop bottom" << endl;
    intPriorityQueue.Pop();
    intPriorityQueue.Print();
    cout << endl;
    cout << "Priority queue size is: " << intPriorityQueue.GetSize() << endl;
    if (intPriorityQueue.IsEmpty()) {
        cout << "Priority queue is currently empty" << endl << endl;
    }
    else {
        cout << "Priority queue is currently not empty" << endl << endl;
    }


    // Print char queue
    cout << "Add c,b,a to char priority queue to test sorting" << endl;
    charPriorityQueue.Push(char1);
    charPriorityQueue.Push(char2);
    charPriorityQueue.Push(char3);
    charPriorityQueue.Print();
    cout << endl;
    cout << "Pop bottom" << endl;
    charPriorityQueue.Pop();
    charPriorityQueue.Print();
    cout << endl;

    // Print double queue
    cout << "Add 56, 2, 862 to double priority queue" << endl;
    doublePriorityQueue.Push(double1);
    doublePriorityQueue.Push(double2);
    doublePriorityQueue.Push(double3);
    doublePriorityQueue.Print();
    cout << endl;
    cout << "Pop bottom" << endl;
    doublePriorityQueue.Pop();
    doublePriorityQueue.Print();
    cout << endl;

    // Test copy constructor and assignment operator
    PriorityQueue<double> copyPriorityQueue = doublePriorityQueue;
    cout << "Print copied double priority queue" << endl;
    copyPriorityQueue.Print();
    copyPriorityQueue.Pop();
    cout << endl;
    cout << "Pop once and print again" << endl;
    copyPriorityQueue.Print();
    cout << endl;
    cout << "Set equal to original double priority queue and print again" << endl;
    copyPriorityQueue = doublePriorityQueue;
    copyPriorityQueue.Print();

    _CrtDumpMemoryLeaks();
}
