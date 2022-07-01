#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <class T>
class Queue
{
private:
	int msize;
	struct Node {
		T value;
		Node *next;
	};

	Node *mhead;
	
public:
	Queue();
	// BIG-3
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	~Queue();

	bool isEmpty() const;
	T enQueue(T);
	T deQueue();
	void print() const;
	int getSize() const;
};
// methods definition
template<class T>
Queue<T>::Queue(): msize(0), mhead(nullptr) {
}

template<class T>
Queue<T>::Queue(const Queue<T> &qu): msize(qu.msize) {
	

	if(qu.isEmpty()) {
		mhead = nullptr;
		return;
	}

	// copying
	mhead = new Node;
	mhead->value = qu.mhead->value;

	Node *h = mhead;
	Node *p = qu.mhead->next;

	while(p != nullptr) {
		Node *item = new Node;
		item->value = p->value;
		p = p->next;
		h->next = item;
		h = h->next;
	}

	h->next = nullptr;
} 

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &qu) {
	msize = qu.msize;

	if(qu.isEmpty()) {
		mhead = nullptr;
		return *this;
	}

	//deallocate memory
	Node *h = mhead;
	while(h != nullptr) {
		Node *tmp = h;
		h = h->next;
		delete tmp;
	}

	// copying
	mhead = new Node;
	mhead->value = qu.mhead->value;

	*h = mhead;
	Node *p = qu.mhead->next;

	while(p != nullptr) {
		Node *item = new Node;
		item->value = p->value;
		p = p->next;
		h->next = item;
		h = h->next;
	}

	h->next = nullptr;

	return *this;
}

template<class T>
Queue<T>::~Queue() {

	Node *h = mhead;
	while(h != nullptr) {
		Node *tmp = h;
		h = h->next;
		delete tmp;
	}
}

template<class T>
bool Queue<T>::isEmpty() const {
	return (msize == 0);
}

template<class T>
T Queue<T>::enQueue(T value) {

	Node *p = mhead;
	if(msize == 0) {
		mhead = new Node;
		mhead->value = value;
		mhead->next = nullptr;
	}
	else {
		while (p->next != nullptr) p = p->next;
		p->next = new Node;
		p->next->value = value;
		p->next->next = nullptr;
	}

	msize++;
	return value;
}


template<class T>
T Queue<T>::deQueue() {
	try {
		if (isEmpty()) throw ("the Queue is empty");
	} catch (char const * err) {
		std::cerr << err;
	}
	
	T rs = mhead->value;
	Node *tmp = mhead;
	mhead = mhead->next;
	delete tmp;
	msize--;

	return rs;
}
template<class T>
void Queue<T>::print() const {
	Node *p = mhead;
	while (p != nullptr)
	{
		std::cout << p->value << " ";
		p = p->next;
	}
}

template <class T>
int Queue<T>::getSize() const {
	return msize;
}
#endif