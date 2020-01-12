// 请先将文件名改为"node.h"
//关于此版本改进的说明
//1. 当前版本使用了C++11中的新特性：右值引用，提升部分情况下的使用性能
//2. 将数据的属性全部改为private，防止一些“未被注意的错误发生”。
//3. 增加了Get函数，其返回链表中储存数据的引用，方便使用者修改链表节点的数据域中储存的数据
//4. 增加了迭代器等若干功能，方便获取链表中的所有元素，具体使用可以参考下方样例说明
//5. 关于Clear函数：此函数用于在函数未结束时清空链表以继续使用而设计，若在程序结束运行前没有清空链表，
//   程序将在结束运行时自动清空，不需要自行清空。
//6. 优化各项体验，将单项链表修改为双向链表，同时增加了抛出异常的机制，方便排查常规的指针引用异常
//7. 将类改为两个，修改了之前的使用递归调用析构函数的方法来清空链表的策略，当前版本理论上可以无限制地增加长度
//   由于鄙人才疏学浅，目前仍存在一些小问题，暂时没有很好的改进方法，下面通过ToDoList的形式列出存在的问题
//ToDoList:
//1. 暂时无法避免恶意的指针使用，对于正常状态的使用，当前的类封装能避免绝大部分"非恶意"的指针操作，能够满足绝大部分人的需求

//注意事项：请若在多个函数间传递链表的head，请使用指针或者将其定义为全局变量，否则，可能会自动调用析构函数而清空链表！！！

//最后，若有什么问题、或者有什么可以改进的地方，可以email我:yin199909@qq.com、yin199909@gmail.com 或者在Issues中评论，我看到时会予以回复，谢谢。
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
	Node<int> head;  //创建链表对象 head.next即为链表的首个节点，注意，是大写的N
	int a = 1;
	head.Store(a);
	a = 3;
	head.Store(a);
	head.Store(4);
	head.Store(5);
	cout << "输出所有对象" << endl;
	while (head.HasNext()) {
		cout << head.Next() << '\t';
	}
	head.ResetIterator();
	node<int>* ptr;  //小写的n，唯一需要的指针
	cout << endl;
	a = 3;
	ptr = head.Find(a, cmp);
	if (ptr != 0) {
		cout << head.Get(ptr) << endl;
		head.Get(ptr) = 7;
		cout << "修改节点数据后: " << head.Get(ptr) << endl;
		if (head.Remove(ptr)) {
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
	if (head.Empty()) {
		cout << "Empty\n";
	}
	else {
		cout << "Not Empty\n";
	}
	head.Clear();
	if (head.Empty()) {
		cout << "Empty\n";
	}
	else {
		cout << "Not Empty\n";
	}
	//head.HasNext();         //可以尝试注释掉这一句话再执行一遍程序，了解本程序的异常抛出
	return 0;
}
*/

template <class Type>
class Node;

template <class Type>
class node {
private:
	Type data;
	node* next;
	node* prev;
public:
	friend class Node<Type>;
	node(Type __data = std::move(Type())) { data = std::move(__data); next = std::move((node*)NULL); prev = std::move((node*)NULL); }
};

template <class Type>
class Node {
private:
	node<Type>* next;
	node<Type>* now;
	node<Type>* last;
public:
	Node();
	~Node();
	/**
	 * 函数名：Store
	 * 传入参数：储存的元素
	 * 当链表节点创建成功时，返回true，否则返回false
	 */
	bool Store(Type&& __x);
	bool Store(Type& __x);
	/**
	 * 函数名：Remove
	 * 功能：删除相应节点
	 * 传入参数：节点指针
	 * 返回值：删除成功时返回ture，否则返回false
	 */
	bool Remove(node<Type>*&& __ptr);
	bool Remove(node<Type>*& __ptr);
	/**
	 * 函数名：Find
	 * 传入参数：寻找的数据、比较函数（比较特定数据是否相同）
	 * 返回值：寻找到相应数据，返回节点地址，否则返回NULL
	 */
	template <class V>
	node<Type>* Find(V&& __value, bool __CMP(Type __classObj, V __data));
	template <class V>
	node<Type>* Find(V& __value, bool __CMP(Type __classObj, V __data));
	/**
	 * 函数名：Get
	 * 传入参数：节点地址
	 * 返回值：传入指针指向对象可读可写的引用
	 */
	Type& Get(node<Type>*&& __ptr);
	Type& Get(node<Type>*& __ptr);
	/**
	 * 函数名：HasNext
	 * 功能：判断是否有下一个对象(即是否到了链表末尾)
	 * 传入参数：无
	 * 返回值：若存在下一个对象：返回true，否则返回false
	 */
	bool HasNext();
	/**
	 * 函数名：Next
	 * 功能：迭代器，获取下一个元素
	 * 传入参数：无
	 * 返回值：链表中下一个对象可读可写的引用
	 */
	Type& Next();
	/**
	 * 函数名：Clear
	 * 功能：清空链表
	 * 传入参数：无
	 * 返回值：无
	 */
	void Clear();
	/**
	 * 函数名：Empty
	 * 功能：判断链表是否为空
	 * 传入参数：无
	 * 返回值：bool 若为空，返回true,否则返回false
	 */
	bool Empty();
	/**
	 * 函数名：ResetIterator
	 * 功能：清空链表
	 * 传入参数：无
	 * 返回值：无
	 */
	bool ResetIterator();
};

template <class Type>
Node<Type>::Node() {
	last = std::move((node<Type>*)NULL);
	next = std::move((node<Type>*)NULL);
	now = std::move((node<Type>*)NULL);
}

template <class Type>
Node<Type>::~Node() {
	Clear();
}

template <class Type>
bool Node<Type>::Store(Type&& __x) {
	node<Type>* p = std::move(new node<Type>(std::move(__x)));
	if (p != NULL) {
		if (last == NULL) {
			next = std::move(p);
			now = std::move(p);
		}
		else {
			last->next = std::move(p);
		}
		p->prev = std::move(last);
		last = std::move(p);
		return true;
	}
	return false;
}

template <class Type>
bool Node<Type>::Store(Type& __x) {
	node<Type>* p = std::move(new node<Type>(std::move(__x)));
	if (p != NULL) {
		if (last == NULL) {
			next = std::move(p);
			now = std::move(p);
		}
		else {
			last->next = std::move(p);
		}
		p->prev = std::move(last);
		last = std::move(p);
		return true;
	}
	return false;
}

template <class Type>
bool Node<Type>::Remove(node<Type>*&& __ptr) {
	if (__ptr == NULL) {
		return false;
	}
	if (__ptr == last) {
		last = std::move(__ptr->prev);
		last->next = std::move((node<Type>*)NULL);
	}
	else {
		__ptr->next->prev = std::move(__ptr->prev);
	}
	if (__ptr->prev != NULL) {
		__ptr->prev->next = std::move(__ptr->next);
	}
	else {
		next = __ptr->next;
	}
	if (now == __ptr) {
		now = std::move(now->next);
	}
	delete __ptr;
	return true;
}

template <class Type>
bool Node<Type>::Remove(node<Type>*& __ptr) {
	if (__ptr == NULL) {
		return false;
	}
	if (__ptr == last) {
		last = std::move(__ptr->prev);
		last->next = std::move((node<Type>*)NULL);
	}
	else {
		__ptr->next->prev = std::move(__ptr->prev);
	}
	if (__ptr->prev != NULL) {
		__ptr->prev->next = std::move(__ptr->next);
	}
	else {
		next = std::move(__ptr->next);
	}
	if (now == __ptr) {
		now = std::move(now->next);
	}
	delete __ptr;
	return true;
}

template <class Type>
template <class V>
node<Type>* Node<Type>::Find(V&& __value, bool __cmp(Type __classObj, V __data)) {
	node<Type>* p(std::move(next));
	while (p != NULL && !__cmp(std::move(p->data), std::move(__value))) {
		p = std::move(p->next);
	}
	return p;
}

template <class Type>
template <class V>
node<Type>* Node<Type>::Find(V& __value, bool __cmp(Type __classObj, V __data)) {
	node<Type>* p(std::move(next));
	while (p != NULL && !__cmp(std::move(p->data), std::move(__value))) {
		p = std::move(p->next);
	}
	return p;
}

template <class Type>
Type& Node<Type>::Get(node<Type>*&& __ptr) {
	if (__ptr == NULL) {
		throw("NullPointerException");  //空指针异常
	}
	return __ptr->data;
}

template <class Type>
Type& Node<Type>::Get(node<Type>*& __ptr) {
	if (__ptr == NULL) {
		throw("NullPointerException");  //空指针异常
	}
	return __ptr->data;
}

template <class Type>
bool Node<Type>::HasNext() {
	if (now == NULL) {
		throw("NullPointerException");  //空指针异常：链表为空或迭代器未重置(使用ResetIterator函数重置迭代器)
	}
	return now->next != NULL;
}

template <class Type>
Type& Node<Type>::Next() {
	if (now == NULL || now->next == NULL) {
		throw("NullPointerException");  //空指针异常
	}
	now = std::move(now->next);
	return now->data;
}

template <class Type>
void Node<Type>::Clear() {
	node<Type>* p(std::move(next)), * q;
	while (p != NULL) {
		q = std::move(p->next);
		delete p;
		p = std::move(q);
	}
	next = std::move((node<Type>*)NULL);
	last = std::move(next);
	now = std::move(next);
}

template <class Type>
bool Node<Type>::Empty() {
	return next == NULL;
}

template <class Type>
bool Node<Type>::ResetIterator() {
	now = std::move(next);
	return now != NULL;
}
