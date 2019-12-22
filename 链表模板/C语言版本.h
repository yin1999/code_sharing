// 请先将文件名改为"node.h"
#pragma once
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

/****示例代码******
#include "node.h"
#include <stdio.h>

typedef struct {
    int a;
    int b;
} customStruct;

int main() {
    node_head head1, head2;
    head1 = CreateNode(sizeof(customStruct));
    head2 = CreateNode(sizeof(int));
    customStruct tmp = { 1, 2 };
    Store(&head1, &tmp);
    tmp = { 3, 4 };
    Store(&head1, &tmp);
    tmp = { 5, 6 };
    Store(&head1, &tmp);
    int num = 0;
    Store(&head2, &num);
    num = 2;
    Store(&head2, &num);
    num = 5;
    Store(&head2, &num);
    node* p = Find(&head1, &tmp);
    if (p != 0) {
        printf("%d %d\n", ((customStruct*)p->data)->a, ((customStruct*)p->data)->b);  //结构体打印data
    }
    if (DelNode(&head1, p) == true) {
        printf("delete node successful\n");
    }
    else {
        printf("delete node error\n");
    }
    if (DelNode(&head1, p) == true) {       //尝试再一次删除链表节点
        printf("delete node successful\n");
    }
    else {
        printf("delete node error\n");
    }
    p = head2.ptr;
    while (p != 0) {                       //遍历链表演示
        printf("%d\t", *(int*)p->data);
        p = p->next;
    }
    printf("\n");
    num = 4;
    p = Find(&head2, &num);
    if (p != 0) {
        printf("Find the data:%d\n", num);
    }
    else {
        printf("Data Not Found:%d\n", num);
    }
    num = 2;
    p = Find(&head2, &num);
    if (p != 0) {
        printf("Find the data:%d\n", num);
    }
    else {
        printf("Data Not Found:%d\n", num);
    }
    DelAllNode(&head1);  //删除链表中的所有节点
    DelAllNode(&head2);
    return 0;
}
*****End*********/

/*********struct define*****/
// 链表节点结构体
typedef struct _node {
    void* data;
    _node* next;
} node;

// 链表head结构体
typedef struct {
    node* ptr;
    size_t data_size;
} node_head;

/*****end struct define*****/

/*********函数声明***********/
node_head CreateNode(const size_t data_size);
node* Find(const node_head* const head, const void* const data);
node* Store(node_head* const head, const void* const data);
bool DelNode(node_head* const head, node* const ptr);
void DelAllNode(node_head* const head);
/************End***********/

/**
 * 创建链表head
 * 传入参数格式：需要存储的变量所占字节数
 * 返回值：链表head变量，需要使用一个node_head结构体作为左值
 */
node_head CreateNode(const size_t data_size) {
    node_head tmp;
    tmp.data_size = data_size;
    tmp.ptr = 0;
    return tmp;
}

/**
 * 查找数据
 * 传入参数格式：链表头变量，变量对象的地址(所有类型的指针均可)
 * 返回值：节点指针  若找到相应节点，返回节点地址，否则返回0
 */
node* Find(const node_head* const head, const void* const data) {
    node* ptr = head->ptr;
    while (ptr != 0) {
        if (memcmp(ptr->data, data, head->data_size) == 0) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return 0;
}

/**
 * 向链表中存入数据
 * 传入参数格式：链表头变量，变量对象的地址
 * 返回值：节点指针  若创建成功，返回链表的最后一个节点地址，否则返回0
 */
node* Store(node_head* const head, const void* const data) {
    if (head->ptr == 0) {
        head->ptr = (node*)malloc(sizeof(node));
        if (head->ptr == 0) {
            return 0;
        }
        void* newData = malloc(head->data_size);
        if (newData == 0) {
            free(head->ptr);
            head->ptr = 0;
            return 0;
        }
        memcpy(newData, data, head->data_size);
        head->ptr->data = newData;
        head->ptr->next = 0;
        return head->ptr;
    }
    node* ptr = head->ptr;
    while (ptr->next != 0) {
        ptr = ptr->next;
    }
    node* p = (node*)malloc(sizeof(node));
    if (p == 0) {
        return 0;
    }
    p->next = 0;
    p->data = malloc(head->data_size);
    if (p->data == 0) {
        free(p);
        return 0;
    }
    ptr->next = p;
    memcpy(p->data, data, head->data_size);
    return p;
}


/**
 * 删除指定链表节点
 * 传入参数格式：链表head
 * 返回值：布尔值  若找到相应节点并删除数据，返回true，否则返回false
 */
bool DelNode(node_head* const head, node* const ptr) {
    if (ptr == 0) {
        return false;
    }
    node* p = head->ptr;
    if (p == ptr) {
        head->ptr = p->next;
        free(p);
        return true;
    }
    while (p->next != 0 && p->next != ptr) {
        p = p->next;
    }
    if (p->next == ptr) {
        p->next = ptr->next;
        free(ptr);
        return true;
    }
    return false;
}


/**
 * 删除所有链表节点
 * 传入参数格式：链表head
 * 返回值：无
 */
void DelAllNode(node_head* const head) {
    node* p = head->ptr, * q;
    while (p != 0) {
        q = p->next;
        free(p);
        p = q;
    }
    head->ptr = 0;
}
