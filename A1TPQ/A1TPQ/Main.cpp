#include <iostream>
#include "queue.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main()
{
    // Make stacks
    PriorityQueue<int*>* intPriorityQueue = new PriorityQueue<int*>();
    PriorityQueue<char*>* charPriorityQueue = new PriorityQueue<char*>();
    PriorityQueue<double*>* doublePriorityQueue = new PriorityQueue<double*>();
    // Make data for stacks
    int* data1 = new int(1);
    int* data2 = new int(2);
    int* data3 = new int(3);
    char* char1 = new char('a');
    char* char2 = new char('b');
    char* char3 = new char('c');
    double* double1 = new double(56);
    double* double2 = new double(2);
    double* double3 = new double(862);
    // Print int stack
    if (intPriorityQueue->IsEmpty()) {
        cout << "Priority queue is currently empty" << endl;
    }
    else {
        cout << "Priority queue is currently not empty" << endl;
    }
    cout << "Add 1,2,3 to int priority queue" << endl;
    intPriorityQueue->Push(data1);
    intPriorityQueue->Push(data2);
    intPriorityQueue->Push(data3);
    intPriorityQueue->Print();
    cout << endl;
    cout << "Pop bottom" << endl;
    intPriorityQueue->Pop();
    intPriorityQueue->Print();
    cout << endl;
    cout << "Priority queue size is: " << intPriorityQueue->GetSize() << endl;
    if (intPriorityQueue->IsEmpty()) {
        cout << "Priority queue is currently empty" << endl << endl;
    }
    else {
        cout << "Priority queue is currently not empty" << endl << endl;
    }


    // Print char stack
    cout << "Add a,b,c to char priority queue" << endl;
    charPriorityQueue->Push(char1);
    charPriorityQueue->Push(char2);
    charPriorityQueue->Push(char3);
    charPriorityQueue->Print();
    cout << endl;
    cout << "Pop bottom" << endl;
    charPriorityQueue->Pop();
    charPriorityQueue->Print();
    cout << endl;

    // Print double stack
    cout << "Add 56, 2, 862 to double priority queue" << endl;
    doublePriorityQueue->Push(double1);
    doublePriorityQueue->Push(double2);
    doublePriorityQueue->Push(double3);
    doublePriorityQueue->Print();
    cout << endl;
    cout << "Pop bottom" << endl;
    doublePriorityQueue->Pop();
    doublePriorityQueue->Print();
    cout << endl;

    // Test copy constructor
    PriorityQueue<double*>* copyPriorityQueue = doublePriorityQueue;
    cout << "Print copied double priority queue" << endl;
    copyPriorityQueue->Print();
    copyPriorityQueue->Pop();
    cout << endl;
    cout << "Pop once and print again" << endl;
    copyPriorityQueue->Print();
    cout << endl;
    cout << "Set equal to original double priority queue and print again" << endl;
    copyPriorityQueue = doublePriorityQueue;
    copyPriorityQueue->Print();

    // Delete pointers
    delete intPriorityQueue;
    intPriorityQueue = nullptr;

    delete charPriorityQueue;
    intPriorityQueue = nullptr;

    delete doublePriorityQueue;
    intPriorityQueue = nullptr;

    delete data1;
    data1 = nullptr;

    delete data2;
    data2 = nullptr;

    delete data3;
    data3 = nullptr;

    delete char1;
    char1 = nullptr;

    delete char2;
    char2 = nullptr;

    delete char3;
    char3 = nullptr;

    delete double1;
    double1 = nullptr;

    delete double2;
    double2 = nullptr;

    delete double3;
    double3 = nullptr;

    _CrtDumpMemoryLeaks();
}
