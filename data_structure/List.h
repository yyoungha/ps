#pragma once
template <class T> class List;

template <class T>
class ListNode
{
	friend class List<T>;
	ListNode(const T& item, ListNode<T>* ptr = 0);
private:
	T data;
	ListNode<T>* link;
};

template <class T>
ListNode<T>::ListNode(const T& item, ListNode<T>* ptr)
{
	data = item;
	link = ptr;
}

template <class T>
class List
{
public:
	List() { first = 0; }

	void InsertBack(const T& item);

	void Concatenate(List<T>& b);

	void Reverse();

	ListNode<T>* Find(const T& item);

private:
	ListNode<T>* first;
	ListNode<T>* last;
};

template <class T>
void List<T>::InsertBack(const T& item)
{
	if (first)
	{
		last->link = new ListNode<T>(item);
		last = last->link;
	}
	else
		first = last = new ListNode<T>(item);
}

template <class T>
void List<T>::Concatenate(List<T>& b)
{
	if (first)
	{
		last->link = b.first;
		last = b.last;
	}
	else
	{
		first = b.first;
		last = b.last;
	}
	b.first = b.last = 0;
}

template <class T>
void List<T>::Reverse()
{
	ListNode<T>* curr = first,
			   * prev = 0;

	while (curr)
	{
		ListNode<T>* r = prev;
		prev = curr;
		curr = curr->link;
		prev->link = r;
	}
	first = prev;
}

template <class T>
ListNode<T>* List<T>::Find(const T& item)
{
	ListNode<T>* curr = first;
	while (curr)
	{
		if (curr->data == item) return curr;
		curr = curr->link;
	}
	return 0;
}