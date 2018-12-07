#include <iostream>
#include <string>
using namespace std;

	template<typename T>
class List
{
public: 
	List();
	~List();

	void push_back(T data);
	int get_size(){ return Size; }
	void pop_front(); //удаление первого элемента списка
	void clear();
	void push_front(T data);
	void insert(T value, int index);
	void remove(T value, int index);
	void pop_back();
	T& operator[](const int index);

private:


	template<typename T>
	class Node 
	{
	public:
		Node *next;
		T data;

		Node(T data=T(), Node *next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	}
	int Size;
	Node<T> *head;
}

	template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


	template<typename T>
void List<T>::push_back(T data)	
{
	 if (head == nullptr)
	 {
	 	head = new Node<T>(data);
	 }
	 else
	 {
	 	Node<T> *current = this->head;

	 	while (current->next !=nullptr)
	 	{
	 		current = current->next;
	 	}
	 	current->next = new Node<T>(data);

	 }

	 Size++;
}

	template<typename T>
void List<T>::pop_front()
{
	Node<t> temp = head;
	head = head->next;

	delete temp;

	Size--;
}
	template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front()
	}
}

	template<typename T>
List<T>::~List()
{
	clear();
}

	template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current!=nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
}
	template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

	template<typename T>
void List<T>::insert(T data, int index)
{
	if (index==0)
	{
		push_front(data)
	}
	else{
	Node<T> *previous = this->head;

	for (int i=0; i < index - 1; i++)
	{
		previous = previous->next;
	}
	
	previous->next = new Node<T>(data, previous->next);
	
	Size++;
	}
	
}

	template<typename T>
void List<T>::remove(int index)
{
	if (index==0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T> *toDelete = previous->next;

		previous->next = toDelete->next;

		delete toDelete;

		Size--;
	}
}
	template<typename T>
void List<T>::pop_back()
{
	remove(Size - 1);
}

int main()
{

	List<int> lst;
	lst.push_front(5);
	lst.push_front(7);
	lst.push_front(101);

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "pop_back " << endl << endl;

	lst.pop_back();

	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}