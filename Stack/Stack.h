#ifndef MY_STACK_H
#define MY_STACK_H
#include <iostream>

template <class T>
class Stack {
private:
	T* madr;
	int msize;
	int mtop;
public:
	Stack(int);
	Stack(const Stack<T>&);
	~Stack();
	Stack<T>& operator=(const Stack<T>&);
	// pushing into stack via <<. ex: stack << 4 << 55
	Stack<T>& operator<<(T);
	bool isEmpty() const;
	bool isFull() const;
	bool push(T);
	bool pop(T&);
	template<typename n> friend std::ostream& operator<<(std::ostream&, const Stack<n>&);
};
#endif

//methods definition

template <class T>
Stack<T>::Stack(int size) : msize(size), mtop(-1)
{
	madr = new T[msize];
}

template<class T>
Stack<T>::Stack(const Stack<T>& st) : msize(st.msize), mtop(st.mtop)
{
	madr = new T[msize];
	for (int i = 0; i <= mtop; i++)
	{
		madr[i] = st.madr[i];
	}
}

template<class T>
Stack<T>::~Stack()
{
	delete[] madr;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st)
{
	delete[] madr;
	msize = st.msize, mtop = st.mtop;
	madr = new T[msize];

	for (int i = 0; i <= mtop; i++)
	{
		madr[i] = st.madr[i];
	}

	//chaining of = operator. ex: st3 = st2 = st1;
	return *this;
}

template<class T>
Stack<T>& Stack<T>::operator<<(T value)
{
	push(value);
	return *this;
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return (mtop == -1);
}

template<class T>
bool Stack<T>::isFull() const
{
	return (msize == (mtop + 1));
}

template<class T>
bool Stack<T>::push(T value)
{
	if (isFull()) return false; // fail to push

	madr[++mtop] = value; // increment then push
	return true;
}

template<class T>
bool Stack<T>::pop(T& dest)
{
	if (isEmpty()) return false; // fail to pop

	dest = madr[mtop--];; // pop to destination then decrement
	return true;
}


template <typename n>
std::ostream& operator<<(std::ostream& out, const Stack<n>& st)
{
	for (int i = 0; i <= st.mtop; i++)
	{
		out << st.madr[i] << " ";
	}

	return out;
}
