#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
//#include <list>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>
#include <limits>
#include <sys/time.h>
#include <cmath>
#include <unistd.h>
#include <stdexcept>

using namespace std;

template <class T>
struct Node
{
	Node(T p_val=0, Node<T>* p_next=NULL):val(p_val),next(p_next)
	{

	}
	T val;
	Node<T> * next;
};

template <class T>
class List
{
public:
	List():begin(NULL)
	{

	}

	List(const List& p_list)
	{
		copyData(p_list);
	}

	List& operator=(const List& p_list)
	{
		if(&p_list!=this)
		{
			clearData();

			copyData(p_list);
		}
		return *this;
	}

	~List()
	{
		clearData();
	}
	void addElemFirst(T p_val)
	{
		Node<T>* newElem=new Node<T>;
		newElem->val=p_val;
		newElem->next=begin;
		begin=newElem;
	}
	void addElemAfter(T p_val, T p_toAdd)
	{
		Node<T>* newElem=new Node<T>;
		newElem->val=p_toAdd;
		if(!begin)
		{
			begin=newElem;
			return;
		}
		Node<T>* iter=begin;
		while(iter->next)
		{
			if(iter->val==p_val)
			{
				break;
			}
			iter=iter->next;
		}
		if(iter->next==NULL)
		{
			throw runtime_error("This is shit!");
		}
		newElem->next=iter->next;
		iter->next=newElem;
	}
	void remElemFirst()
	{
		if(begin)
		{
			Node<T>* toRem=begin;
			begin=begin->next;
			delete toRem;
		}
	}
	void remElem(T p_val)
	{
		if(begin)
		{
			Node<T>* toRem=begin, *prev=NULL;

			bool found = false;
			do
			{
				if(toRem->val==p_val)
				{
					found=true;
					break;
				}
				prev=toRem;
				toRem=toRem->next;
			}
			while(toRem);

			if(prev&&found)
			{
				prev->next=toRem->next;
				delete toRem;
			}
			else if(found)
			{
				begin=toRem->next;
				delete toRem;
			}
		}
	}
	void printList()
	{
		cout<<"Lista: "<<endl;
		if(begin)
		{
			cout<<begin->val<<endl;
			Node<T>* iter=begin;
			while(iter->next)
			{
				iter=iter->next;
				cout<<iter->val<<endl;
			}
		}
	}
private:
	Node<T>* begin;

	void copyData(const List & p_list)
	{
		begin=NULL;
		Node<T>* iter=p_list.begin, *prev=NULL;
		if(iter)
		{
			do
			{
				Node<T> * tmp = new Node<T>;
				if(!begin)
				{
					begin=tmp;
				}
				tmp->val=iter->val;
				if(prev)
				{
					prev->next=tmp;
				}
				prev=tmp;
				iter=iter->next;
			}
			while(iter);
		}
		else
		{
			begin=NULL;
		}
	}

	void clearData()
	{
		if(begin)
		{
			Node<T>* iter=begin;
			do
			{
				Node<T>* tmp=iter;
				iter=iter->next;
				delete tmp;
			}
			while(iter);
			begin = NULL;
		}
	}
};


int main()
{
	try
	{
		List<int> list;
		list.addElemAfter(4,2);
		list.addElemAfter(2,6);
		list.addElemFirst(1);
		cout<<"First list"<<endl;
		list.printList();

		List<int> list2(list);
		cout<<"Second list"<<endl;
		list2.printList();

		List<int> list3=list;
		cout<<"Third list"<<endl;
		list2.printList();

		List<int> list4;
		cout<<"Fourth list"<<endl;
		list4.printList();
		list4=list;
		cout<<"Fourth list"<<endl;
		list4.printList();

		List<char> list5;
		list5.addElemFirst('c');
		list5.addElemAfter('c','d');
		list5.addElemFirst('a');
		cout<<"Fifth list"<<endl;
		list5.printList();
	}
	catch(runtime_error &e)
	{
		cout<<"We are here "<<e.what()<<endl;
	}
	catch(...)
	{
		cout<<"Unexpected"<<endl;
	}

	//delete list;

/*    freopen("input.txt", "r", stdin);
    struct timeval tv;
    struct timeval start_tv;

    gettimeofday(&start_tv, NULL);
    int T=0, test_case;

    cin >> T;
    int tmp;
    for(test_case = 0; test_case < T; test_case++)
    {
    	int num;
    	cin >> num;
    	for(int i=0;i<num;i++)
    	{
    		for(int j=0;j<num;j++)
    		{
    			cin>>tmp;
    			tab[i][j]=tmp;
    		}
    	}
    	int numOfConstellations=0, biggestConstelation=0;
    	readMap(numOfConstellations,biggestConstelation,num);
    	cout<<numOfConstellations<<" "<<biggestConstelation<<endl;
    	//printTab(num);

    }

    double elapsed = 0.0;

    gettimeofday(&tv, NULL);
    elapsed = (tv.tv_sec - start_tv.tv_sec) +
      (tv.tv_usec - start_tv.tv_usec) / 1000000.0;
    cout<< "czas "<<elapsed<<endl;*/
    return 0;
}
