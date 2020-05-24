#pragma once
#include <iostream>
using namespace std;

template<typename T>
class LinkedList
{
public:
	LinkedList() : head(nullptr), count(0) {}
	LinkedList(LinkedList& other)
	{
		for (int i = 0; i < other.GetCount(); ++i)
		{
			PushBack(other.GetData(i));
		}
	}

	LinkedList& operator = (LinkedList<T> *&other)
	{
		Clear();

		for (int i = 0; i < other.GetCount(); ++i)
		{
			PushBack(other.GetData(i));
		}

		return *this;
	}
	LinkedList& operator + (LinkedList<T>& other)
	{
		LinkedList<T> tmp_list;

		for (int i = 0; i < count; ++i)
		{
			tmp_list.PushBack(GetData(i));
		}
		
		for (int i = 0; i < other.GetCount(); ++i)
		{
			tmp_list.PushBack(other.GetData(i));
		}

		return tmp_list;
	}

	int GetCount()
	{
		return count;
	}
	T GetData(int idx)
	{
		Node<T>* current = head;
		
		for (int i = 0; i < idx; ++i)
		{
			current = current->pNext;
		}

		return current->date;
	}

	void PushBack(const T value)
	{
		head == nullptr ? AddHead(value) : AddBack(value);
		++count;
	}
	void PushFront(const T value)
	{
		head == nullptr ? AddHead(value) : AddFront(value);
		++count;
	}
	void Push(const T value, const int idx)
	{
		idx == 0 ? PushFront(value) : Add(value, idx);
	}

	void Show()
	{
		Node<T>* pCurrent = head;

		for (int i = 0; i < count; ++i)
		{
			cout << pCurrent->date << endl;
			pCurrent = pCurrent->pNext;
		}
	}
	void FlipOver()
	{
		Node<T>* newHead = SearchLastElement();
		Node<T>* inverted_list = newHead;

		Invert(inverted_list);
		head = newHead;

		newHead = nullptr;
		inverted_list = nullptr;
	}

	int Search(const T item)
	{
		Node<T> *current = head;

		for (int i = 0; i < count; ++i)
		{
			if (current->date == item)
				return i + 1;

			current = current->pNext;
		}

		return NULL;
	}
	int Swap(const T source , const T direction)
	{
		Node<T> *current = head;
		int numberOfSwap = 0;

		for (int i = 0; i < count; ++i)
		{
			if (current->date == source)
			{
				current->date = direction;
				++numberOfSwap;
			}		
			current = current->pNext;
		}

		if (numberOfSwap > 0)
			return numberOfSwap;
		else
			return -1;
	}

	void DeleteFromHead()
	{
		Node<T> *thisDeleteNode = head;
		head = head->pNext;
		delete thisDeleteNode;
		thisDeleteNode = nullptr;
		--count;
	}
	void DeleteFromTail()
	{
		head->pNext != nullptr ? DeleteTail() : delete head;
		--count;
	}
	void DeleteOneElement(const int idx)
	{
		if (idx == 0)
			DeleteFromHead();
		else if (idx == count - 1)
			DeleteFromTail();
		else
			DeleteElement(idx);
	}
	void Clear()
	{
		while (count)
		{
			DeleteFromHead();
		}
	}

	~LinkedList()
	{
		Clear();
	}

private:
	template<typename T>
	struct Node
	{
	public:
		Node* pNext;
		T date;

		Node(T date = T(), Node* pNext = nullptr) 
		{
			this->date = date;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	int count;

	void AddBack(const T value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* pCurrent = head;

		for (int i = 0; i < count - 1; ++i)
		{
			pCurrent = pCurrent->pNext;
		}
		pCurrent->pNext = newNode;

		newNode = nullptr;
		pCurrent = nullptr;
	}
	void AddFront(const T value)
	{
		Node<T>* newNode = new Node<T>(value, head);
		head = newNode;
		newNode = nullptr;

	}
	void AddHead(const T value) 
	{ 
		head = new Node<T>(value); 
	}
	void Add(const T value, const int idx)
	{
		Node<T>* current = head;
		for (int i = 0; i < idx - 1; ++i)
		{
			current = current->pNext;
		}

		Node<T>* newNode = new Node<T>(value, current->pNext);
		current->pNext = newNode;

		newNode = nullptr;
		current = nullptr;
		++count;
	}

	Node<T>* SearchLastElement()
	{
		Node<T>* current = head;

		for (int i = 0; i < count - 1; ++i)
		{
			current = current->pNext;
		}

		return current;
	}
	void Invert(Node<T>* inverted_list)
	{
		Node<T>* current = head;
		int current_idx = 2;

		for (int i = 0; i < count - 1; ++i)
		{
			current = head;
			for (int j = 0; j < count - current_idx; ++j)
			{
				current = current->pNext;
			}
			++current_idx;

			inverted_list->pNext = current;
			inverted_list = inverted_list->pNext;
		}

		current->pNext = nullptr;
		current = nullptr;
	}

	void DeleteTail()
	{
		Node<T>* current = head;

		while (current->pNext->pNext != nullptr)
		{
			current = current->pNext;
		}

		delete current->pNext;
		current->pNext = nullptr;
		current = nullptr;
	}
	void DeleteElement(const int idx)
	{
		Node<T>* current = head;
		for (int i = 0; i < idx - 1; ++i)
		{
			current = current->pNext;
		}

		Node<T>* thisDeleteElement = current->pNext;
		current->pNext = thisDeleteElement->pNext;
		delete thisDeleteElement;

		thisDeleteElement = nullptr;
		current = nullptr;
		--count;
	}
};