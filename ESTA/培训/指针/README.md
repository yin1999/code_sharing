# 指针

- [指针](#指针)
  - [指针是什么](#指针是什么)
  - [指针的优点](#指针的优点)
  - [coding环节](#coding环节)
    - [例一](#例一)
      - [例一值传递](#例一值传递)
      - [例一指针传递](#例一指针传递)
      - [例一总结](#例一总结)
    - [例二](#例二)
      - [例二值传递](#例二值传递)
      - [例二指针传递](#例二指针传递)
      - [例二总结](#例二总结)
  - [总结](#总结)
- [链表](../链表/README.md)
- [IO流](../IO流/README.md)

## 指针是什么

__指针__ 是一种数据变量类型，它储存了一个寄存器地址，这个地址的值指向储存在该地址的对象的值。

![image](./image/Pointer.png "指针")  
_名为 a 的指针，指向一个存储器地址，当中的值为 b。_  
_图片来自[Wikipedia.org](https://zh.wikipedia.org/wiki/%E6%8C%87%E6%A8%99_(%E9%9B%BB%E8%85%A6%E7%A7%91%E5%AD%B8))_

## 指针的优点

指针相对于值传递的速度更快(占用储存空间较多的情况下)，值传递在C/C++中是将已有对象复制一份到一个新的内存空间中；而指针则是给出储存数据的位置和数据类型，对数据直接进行操作。

## coding环节

### 例一

观察下面两种方法的输出结果有何不同

#### 例一值传递

    #include <stdio.h>
    #include <stdlib.h>

    void swap(int a, int b) {
        int c = a;
        a = b;
        b = c;
    }

    int main() {
        int a = 2, b = 3;

        swap(a, b);

        printf("a=%d\tb=%d\n", a, b);
        return 0;
    }

#### 例一指针传递

    #include <stdio.h>
    #include <stdlib.h>

    void swap(int* pa, int* pb) {
        int c = *pa;
        *pa = *pb;
        *pb = c;
    }

    int main() {
        int a = 2, b = 3;

        swap(&a, &b);

        printf("a=%d\tb=%d\n", a, b);
        return 0;
    }

#### 例一总结

值传递只是拷贝了一份变量到新的内存空间，对新内存空间中的变量进行操作，而不会对原有变量造成任何影响。指针操作则直接对原有变量内存空间中的数据进行了修改，从而正确地完成了交换数据的功能。

### 例二

对比两种方法的运行时间

#### 例二值传递

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    typedef struct {
        int a;
        float b;
        double c;
        double d;
        double e;
        double f;
        double g;
        double h;
    } comp;

    int main() {
        comp a, b = { 0 };
        getchar();               //排除编译过程对运行时间产生的影响
        clock_t start = clock();
        int i = 0;
        for (; i < 1000000; i++) {
            a = b;
            b.a = i;
        }
        clock_t end = clock();
        printf("Used time=%dms\n", end - start);
        return 0;
    }

#### 例二指针传递

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    typedef struct {
        int a;
        float b;
        double c;
        double d;
        double e;
        double f;
        double g;
        double h;
    } comp;

    int main() {
        comp *a, b = { 0 };
        getchar();               //排除编译过程对运行时间产生的影响
        clock_t start = clock();
        int i = 0;
        for (; i < 1000000; i++) {
            a = &b;
            b.a = i;
        }
        clock_t end = clock();
        printf("Used time=%dms\n", end - start);
        return 0;
    }

#### 例二总结

在变量占用空间较多的情况下，采用指针传值会比普通的值传递快很多

### 总结

指针作为一种高效的传递参数的变量类型，正确地使用可以加快程序运行速度。在C/C++中也有许多用到了指针的地方。例如:qsort,sort函数 cout操作符等。
