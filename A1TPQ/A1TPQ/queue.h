#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
using namespace std;
template <class T>

class PriorityQueue
{
public:
	// Priority Queue constructor
	PriorityQueue()
	{
		pqueueArray = new T[1];
		pqueueArraySize = 1;
		pqueueSize = 0;
	};

	// Deconstructor
	~PriorityQueue()
	{
		delete[] pqueueArray;
		pqueueArray = nullptr;
	};

	// Copy constructor
	PriorityQueue(const PriorityQueue& other)
	{
		pqueueArraySize = other.pqueueArraySize;
		pqueueSize = other.pqueueSize;
		pqueueArray = new T[pqueueArraySize];

		for (int i = 0; i < pqueueSize; i++) {
			pqueueArray[i] = other.pqueueArray[i];
		}
	}

	// Assignment operator
	PriorityQueue& operator =(const PriorityQueue& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (pqueueArray != nullptr)
		{
			delete[] pqueueArray;
			pqueueArray = nullptr;
			pqueueSize = 0;
			pqueueArraySize = 0;
		}
		pqueueArraySize = other.pqueueArraySize;
		pqueueSize = other.pqueueSize;
		pqueueArray = new T[pqueueArraySize];

		for (int i = 0; i < pqueueSize; i++) {
			pqueueArray[i] = other.pqueueArray[i];
		}

		return *this;
	}

	// Push data
	void Push(T data)
	{
		pqueueSize++;
		// Setup new array if necessary
		if (pqueueSize > pqueueArraySize)
		{
			temp = new T[pqueueArraySize * 2];
			// Make new pqueue that's twice as big and copy data
			for (int i = 0; i < pqueueSize - 1; i++) {
				temp[i] = pqueueArray[i];
			}
			// Repoint pqueueArray to new pqueue;
			delete[] pqueueArray;
			pqueueArray = temp;
			temp = nullptr;

			// Add data
			pqueueArray[pqueueSize - 1] = data;
			pqueueArraySize *= 2;
		}
		else
		{
			// Add data
			pqueueArray[pqueueSize - 1] = data;
		}
		
		// Insertion Sort
		for (int i = 1; i < pqueueArraySize; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (pqueueArray[j] < pqueueArray[j - 1])
				{
					temp = &pqueueArray[j];
					pqueueArray[j] = pqueueArray[j - 1];
					pqueueArray[j - 1] = *temp;
				}
			}
		}
	}

	// Pop data
	void Pop()
	{
		// Nullify bottom data of pqueue, and decrease size
		pqueueArray[0] = NULL;
		for (int i = 0; i < pqueueArraySize; i++) {
			if (pqueueArray[i] != NULL)
			{
				pqueueArray[i - 1] = pqueueArray[i];
				pqueueArray[i] = NULL;
			}
		}
		pqueueSize--;
	}

	// Print data in pqueue
	void Print()
	{
		for (int i = 0; i < pqueueSize; i++)
		{
			cout << *(pqueueArray[i]) << endl;
		}
	}

	// Get size of pqueue
	int GetSize()
	{
		return pqueueSize;
	}

	// Return true or false depending on whether pqueue is empty
	bool IsEmpty()
	{
		if (pqueueSize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// Get data at index
	T GetData(int index)
	{
		return pqueueArray[index];
	}

private:
	// Initialize pqueue variables
	T* pqueueArray;
	T* temp;
	int pqueueArraySize;
	int pqueueSize;
};

#endif //queue.h