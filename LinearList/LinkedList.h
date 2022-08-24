//
// Created by bruce on 8/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINKEDLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINKEDLIST_H

#include <stdbool.h>

typedef int ElementType;
struct Node {
    ElementType element;
    struct Node *next;
};
typedef struct Node *PtrToNode;
typedef PtrToNode LinkedList;
typedef PtrToNode LNode;

// 初始化链表
LinkedList makeEmpty( LinkedList L );
// 判链表是否为空
bool isEmpty( LinkedList L );
// 判断结点是否为表尾结点
bool isLast( LinkedList L, LNode P );
// 头结点
LNode header( LinkedList L );
// 链表第一个结点
LNode first( LinkedList L );
// 结点的下一个结点
LNode advance( LNode P );
// 结点的元素值
ElementType retrieve( LNode P );
// 链表长度
int length( LinkedList L );
// 检查结点是否为链表结点
bool checkNode( LinkedList L, LNode P );

// 此处默认所有结点的元素值不相同
// 查找位置结点的前驱结点
LNode findPositionPrevious( LinkedList L, int i );
// 查找元素值为value结点的前驱结点
LNode findValuePrevious( LinkedList L, ElementType value );
// 查找结点的前一个结点
LNode findNodePrevious( LinkedList L, LNode P );
// 查找位置结点
LNode findPosition( LinkedList L, int i );
// 查找指定元素值结点
LNode findValue( LinkedList L, ElementType value );
// 查找链表最后一个结点
LNode findLastNode( LinkedList L );
// 确定结点在链表中的位置(链表元素位序从1开始)
int findNodePosition( LinkedList L, LNode P );

// 更改结点元素值
void updateNode( LinkedList L, LNode P, ElementType value );
// 更改指定元素值结点的元素值
void updateValue( LinkedList L, ElementType targetValue, ElementType value );
// 更改指定位置结点的元素值
void updatePosition( LinkedList L, int i, ElementType value );

// 头插
void headInsert( LinkedList L, ElementType value );
// 尾插
void tailInsert( LinkedList L, ElementType value );
// 结点前插入结点
void insertNodePrevious( LinkedList L, LNode P, ElementType value );
// 指定位置前插入结点
void insertPositionPrevious( LinkedList L, int i, ElementType value );
// 结点后插入结点
void insertNodeFollowing( LinkedList L, LNode P, ElementType value );
// 指定位置结点后插入结点
void insertPositionFollowing( LinkedList L, int i, ElementType value );

// 删除结点
void deleteNode( LinkedList L, LNode P );
// 删除指定元素值结点
void deleteValue( LinkedList L, ElementType value );
// 删除指定位置结点
void deletePosition( LinkedList L, int i );
// 删除链表
void deleteList( LinkedList L );

// 顺序输出链表元素值
void printList( LinkedList L );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINKEDLIST_H
