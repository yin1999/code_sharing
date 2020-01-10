// 请先将文件名改为"node.h"
//关于此版本改进的说明
//1. 当前版本使用了C++11中的新特性：右值引用，提升部分情况下的使用性能
//2. 将数据的属性全部改为private，防止一些“未被注意的错误发生”。
//3. 增加了Get函数，其返回链表中储存数据的引用，方便使用者修改链表节点的数据域中储存的数据
//由于鄙人才疏学浅，目前仍存在一些小问题，暂时没有很好的改进方法，下面通过ToDoList的形式列出存在的问题
//ToDoList:
//1. 为实现函数的复用，同时兼容右值引用以及一般的值传递，我采用内联函数来关联二者，
//当前状态是无法将const修饰的变量直接传进去的，可以采用强制类型转换的方法传值进去
//2. 暂时无法避免恶意的指针使用，对于正常状态的使用，当前版本能够满足绝大部分人的需求

//最后，若有什么问题、或者有什么可以改进的地方，可以email我:yin199909@qq.com、yin199909@gmail.com 或者在当前文件下评论，我看到时会予以回复，谢谢。
#pragma once
#include <utility>

#ifndef NULL
	#ifdef __cplusplus
		#define NULL 0
	#else
		#define NULL ((void *)0)
	#endif
#endif // !NULL

/*
//链表模板使用样例
#include "node.h"
#include <iostream>
using namespace std;

bool cmp(int a, int b) {
	return a == b;
}

int main() {
	node<int> head;  //创建链表对象 head.next即为链表的首个节点
	int a = 1;
	head.Store(a);
	a = 3;
	head.Store(a);
	head.Store(4);
	head.Store(5);
	node<int>* ptr = head.Find(a, cmp);
	if (ptr != 0) {
		cout << head.Get(ptr) << endl;
		head.Get(ptr) = 7;
		cout << "修改节点数据后: " << head.Get(ptr) << endl;
		if (head.Del(ptr)) {
			cout << "del successful\n";
		}
		else {
			cout << "del error\n";
		}
	}
	ptr = head.Find(a, cmp);
	if (ptr == NULL) {
		cout << "Not Found\n";
	}
	return 0;
}
*/

template <class Type>
class node
{
private:
	Type data;
	node* next;
	bool store(Type&& __x);
	bool del(node*&& __ptr);
	template <class V>
	node* find(V&& __value, bool __cmp(Type __classObj, V __data));
	Type& get(node*&& __ptr);

public:
	//使用构造函数创建链表
	node()
	{
		data = std::move(Type());
		next = std::move((node<Type>*)(NULL));
	}
	//析构函数自动删除链表
	~node()
	{
		if (next != NULL)
			delete next;
	}
	/**
	 * 函数名：Store
	 * 传入参数：储存的元素
	 * 当链表节点创建成功时，返回true，否则返回false
	 */
	inline bool Store(Type&& __x) { return store(std::move(__x)); }
	inline bool Store(Type& __x) { return store(std::move(__x)); }
	/**
	 * 函数名：Del
	 * 功能：删除相应节点
	 * 传入参数：节点指针
	 * 返回值：删除成功时返回ture，否则返回false
	 */
	inline bool Del(node*&& __ptr) { return del(std::move(__ptr)); }
	inline bool Del(node*& __ptr) { return del(std::move(__ptr)); }
	/**
	 * 函数名：Find
	 * 传入参数：寻找的数据、比较函数（比较特定数据是否相同）
	 * 返回值：寻找到相应数据，返回节点地址，否则返回NULL
	 */
	template <class V>
	inline node* Find(V&& __value, bool __cmp(Type __classObj, V __data)) { return find(std::move(__value), std::move(__cmp)); }
	template <class V>
	inline node* Find(V& __value, bool __cmp(Type __classObj, V __data)) { return find(std::move(__value), std::move(__cmp)); }
	/**
	 * 函数名：Get
	 * 传入参数：节点地址
	 * 返回值：传入指针指向数据的可读可写的引用
	 */
	inline Type& Get(node*&& __ptr) { return get(std::move(__ptr)); }
	inline Type& Get(node*& __ptr) { return get(std::move(__ptr)); }
};

template <class Type>
bool node<Type>::store(Type&& __x)
{
	node* p(std::move(this));
	while (p->next)
	{
		p = std::move(p->next);
	}
	p->next = std::move(new node);
	if (p->next != NULL)
	{
		p->next->data = std::move(__x);
		return true;
	}
	return false;
}

template <class Type>
bool node<Type>::del(node*&& ptr)
{
	if (ptr == NULL)
	{
		return false;
	}
	node* p(std::move(this));
	while (p->next && p->next != ptr)
	{
		p = std::move(p->next);
	}
	if (p->next != NULL)
	{
		node* del_node(std::move(p->next));
		p->next = std::move(del_node->next);
		del_node->next = std::move((node*)(NULL)); //防止析构函数将后面的节点全部删除
		delete del_node;
		return true;
	}
	return false;
}

template <class Type>
template <class V>
node<Type>* node<Type>::find(V&& __val, bool __cmp(Type __classObj, V __data))
{
	node* p(std::move(this));
	while (p != NULL && !__cmp(std::move(p->data), std::move(__val)))
	{
		p = std::move(p->next);
	}
	return p;
}

template <class Type>
Type& node<Type>::get(node*&& __ptr)
{
	return __ptr->data;
}
