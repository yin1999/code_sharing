#pragma once

template <class Type>
class node
{
public:
	Type data;
	node* next;
	node() { next = 0; }
	~node() { if (next) delete next; }
	void Store(Type&);
};

template <class Type>
void node<Type>::Store(Type& temp)
{
	node* p = this;
	while (p->next)
	{
		p = p->next;
	}
	p->next = new node;
	p->next->data = temp;
}
