#pragma once

template <class T>
class Queue
{
public:
	// create an empty queue with capacity 50
	Queue(int queueCapacity = 100);

	// true if the number of elements in queue is 0.
	bool IsEmpty() const;

	// return front element
	T& Front();

	// return rear element
	T& Rear();

	// insert rear
	void Push(const T& item);

	// delete front element
	void Pop();

private:
	T* queue;
	int front,
		rear,
		capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capacity must be positive integer.";
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const { return front == rear; }

template <class T>
inline T& Queue<T>::Front()
{
	if (IsEmpty()) throw "Queue is empty. There is no element.";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
	if (IsEmpty()) throw "Queue is empty. There is no element.";
	return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& item)
{
	// if queue is full
	if ((rear + 1) % capacity == front)
	{
		// 2x capacity memory allocation
		T* newQueue = new T[2 * capacity];

		// copy queue to newQueue
		int start = (front + 1) % capacity;
		if (start < 2)
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		// set newQueue to queue
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = item;
}

template <class T>
void Queue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empty. There is no element to delete.";
	front = (front + 1) % capacity;
	queue[front].~T();
}