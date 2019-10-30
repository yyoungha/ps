#pragma once
#include <algorithm>
template <class T>
class Stack
{
public:
	Stack(int stackCapacity = 100);

	bool IsEmpty() const;

	T& Top() const;

	void Push(const T& item);

	void Pop();

private:
	void ChangeSize1D(T*& a, const int oldSize, const int newSize);
	T* stack;
	int top;
	int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be positive integer.";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const
{
	if (IsEmpty()) throw "Stack is empty";
	return stack[top];
}

template <class T>
void Stack<T>::Push(const T& item)
{
	if (top == capacity - 1)
	{
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = item;
}

template <class T>
void Stack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. There is no element to delete.";
	stack[top--].~T();
}

template <class T>
void Stack<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New size must be nonnegative integer.";

	T* temp = new T[newSize];
	int number = std::min(oldSize, newSize);
	std::copy(a, a + number, temp);
	delete[] a;
	a = temp;
}