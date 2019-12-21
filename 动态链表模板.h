#pragma once

/*
链表模板使用样例
#include "node.h"
#include <iostream>
using namespace std;

int main() {
    node<int> head;  //创建链表对象 head.next即为链表的首个节点
    int a = 1;
    head.Store(a);
    a = 3;
    head.Store(a);
    a = 4;
    head.Store(a);
    a = 3;
    node<int>* ptr = head.Find(a);
    if (ptr != 0) {
        cout << ptr->data << endl;
        if (head.Del(ptr)) {
            cout << "del successful\n";
        }
        else {
            cout << "del error\n";
        }
    }
    ptr = head.Find(a);
    if (ptr == 0) {
        cout << "Not Found\n";
    }
    return 0;
}
*/

template <class Type>
class node {
public:
    Type data;
    node* next;
    node() { data = Type(); next = 0; }  //使用构造函数创建链表head指针
    ~node() { if (next) delete next; }   //析构函数自动删除链表
    bool Store(const Type&);             //当链表节点创建成功时，返回true，否则返回false
    bool Del(const node* const ptr);     //删除链表节点请使用Del函数，传入参数为要删除的节点的地址，删除成功时返回ture，否则返回false
    node* Find(const Type& data);        //寻找链表中的元素，其返回值为所在data所在节点的地址(若没有找到，则返回0)，不能传入常量，要改成能使用常量的，可以把此函数声明以及定义处的“&”去掉
};

template <class Type>
bool node<Type>::Store(const Type& temp) {
    node* p = this;
    while (p->next) {
        p = p->next;
    }
    p->next = new node;
    if (p->next != 0) {
        p->next->data = temp;
        return true;
    }
    return false;
}

template <class Type>
bool node<Type>::Del(const node* const ptr) {
    if (ptr == 0) {
        return false;
    }
    node* p = this;
    while (p->next && p->next != ptr) {
        p = p->next;
    }
    if (p->next != 0) {
        node* del_node = p->next;
        p->next = del_node->next;
        del_node->next = 0;        //防止析构函数将后面的节点全部删除
        delete del_node;
        return true;
    }
    else {
        return false;
    }
}

template <class Type>
node<Type>* node<Type>::Find(const Type& data) {
    node* p = this;
    while (p->next) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
