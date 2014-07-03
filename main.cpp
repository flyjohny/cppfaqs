#include <iostream>
#include <list>
#include <cassert>
#include <stdexcept>

using namespace std;

typedef unsigned int uint;

template <class T>
class Stack
{
public:
	void push(T obj);
	T pop();
	uint size() const;
private:
	list<T> m_Stack;
};

template <class T>
void Stack<T>::push(T obj)
{
#ifndef NDEBUG
	uint initialSize=size();
#endif

	m_Stack.push_back(obj);

#ifndef NDEBUG
	assert(initialSize+1==size() && "Size didn't increase!");
#endif
}

template <class T>
T Stack<T>::pop()
{
#ifndef NDEBUG
	uint initialSize=size();
	assert(initialSize!=0 && "No elements on stack!");
#endif

	if(size()==0)
	{
		throw runtime_error("No element to pop!");
	}
	T elem = m_Stack.back();
	m_Stack.pop_back();

#ifndef NDEBUG
	assert(initialSize-1==size() && "Size didn't decrease!");
#endif
	return elem;
}

template <class T>
uint Stack<T>::size() const
{
	return m_Stack.size();
}

int main()
{
	Stack<int> s;
	cout<<s.size()<<endl;
	s.push(5);
	s.push(3);
	cout<<s.size()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.pop()<<endl;
    return 0;
}
