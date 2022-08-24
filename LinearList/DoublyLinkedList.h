//
// Created by bruce on 8/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_DOUBLYLINKEDLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_DOUBLYLINKEDLIST_H

#include <stdbool.h>

typedef int ElementType;
struct Node {
    ElementType element;
    struct Node *next, *prior;
};
typedef struct Node *PtrToNode;
typedef PtrToNode DLinkedList;
typedef PtrToNode DNode;

// 初始化链表
DLinkedList makeEmpty( DLinkedList L );
// 判链表是否为空
bool isEmpty( DLinkedList L );
// 判断结点是否为表尾结点
bool isLast( DLinkedList L, DNode P );
// 头结点
DNode header( DLinkedList L );
// 链表第一个结点
DNode first( DLinkedList L );
// 结点的下一个结点
DNode advance( DNode P );
// 结点的元素值
ElementType retrieve( DNode P );
// 链表长度
int length( DLinkedList L );
// 检查结点是否为链表结点
bool checkNode( DLinkedList L, DNode P );

// 此处默认所有结点的元素值不相同
// 查找位置结点的前驱结点
DNode findPositionPrevious( DLinkedList L, int i );
// 查找元素值为value结点的前驱结点
DNode findValuePrevious( DLinkedList L, ElementType value );
// 查找结点的前一个结点
DNode findNodePrevious( DLinkedList L, DNode P );
// 查找位置结点
DNode findPosition( DLinkedList L, int i );
// 查找指定元素值结点
DNode findValue( DLinkedList L, ElementType value );
// 查找链表最后一个结点
DNode findLastNode( DLinkedList L );
// 确定结点在链表中的位置(链表元素位序从1开始)
int findNodePosition( DLinkedList L, DNode P );

// 更改结点元素值
void updateNode( DLinkedList L, DNode P, ElementType value );
// 更改指定元素值结点的元素值
void updateValue( DLinkedList L, ElementType targetValue, ElementType value );
// 更改指定位置结点的元素值
void updatePosition( DLinkedList L, int i, ElementType value );

// 头插
void headInsert( DLinkedList L, ElementType value );
// 尾插
void tailInsert( DLinkedList L, ElementType value );
// 结点前插入结点
void insertNodePrevious( DLinkedList L, DNode P, ElementType value );
// 指定位置前插入结点
void insertPositionPrevious( DLinkedList L, int i, ElementType value );
// 结点后插入结点
void insertNodeFollowing( DLinkedList L, DNode P, ElementType value );
// 指定位置结点后插入结点
void insertPositionFollowing( DLinkedList L, int i, ElementType value );

// 删除结点
void deleteNode( DLinkedList L, DNode P );
// 删除指定元素值结点
void deleteValue( DLinkedList L, ElementType value );
// 删除指定位置结点
void deletePosition( DLinkedList L, int i );
// 删除链表
void deleteList( DLinkedList L );

// 顺序输出链表元素值
void printList( DLinkedList L );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_DOUBLYLINKEDLIST_H
