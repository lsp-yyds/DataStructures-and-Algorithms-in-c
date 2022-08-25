//
// Created by bruce on 8/24/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_CIRCULARLINKEDLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_CIRCULARLINKEDLIST_H

#include <stdbool.h>

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode CLinkedList;
typedef PtrToNode CNode;

// 初始化链表
CLinkedList makeEmpty( CLinkedList L );
// 判链表是否为空
bool isEmpty( CLinkedList L );
// 判断结点是否为表尾结点
bool isLast( CLinkedList L, CNode P );
// 头结点
CNode header( CLinkedList L );
// 链表第一个结点
CNode first( CLinkedList L );
// 结点的下一个结点
CNode advance( CNode P );
// 结点的元素值
ElementType retrieve( CNode P );
// 链表长度
int length( CLinkedList L );

// 此处默认所有结点的元素值不相同
// 查找位置结点的前驱结点
CNode findPositionPrevious( CLinkedList L, int i );
// 查找元素值为value结点的前驱结点
CNode findValuePrevious( CLinkedList L, ElementType value );
// 查找结点的前一个结点
CNode findNodePrevious( CLinkedList L, CNode P );
// 查找位置结点
CNode findPosition( CLinkedList L, int i );
// 查找指定元素值结点
CNode findValue( CLinkedList L, ElementType value );
// 查找链表最后一个结点
CNode findLastNode( CLinkedList L );
// 确定结点在链表中的位置(链表元素位序从1开始)
int findNodePosition( CLinkedList L, CNode P );

// 更改结点元素值
void updateNode( CLinkedList L, CNode P, ElementType value );
// 更改指定元素值结点的元素值
void updateValue( CLinkedList L, ElementType targetValue, ElementType value );
// 更改指定位置结点的元素值
void updatePosition( CLinkedList L, int i, ElementType value );

// 头插
void headInsert( CLinkedList L, ElementType value );
// 尾插
void tailInsert( CLinkedList L, ElementType value );
// 结点前插入结点
void insertNodePrevious( CLinkedList L, CNode P, ElementType value );
// 指定位置前插入结点
void insertPositionPrevious( CLinkedList L, int i, ElementType value );
// 结点后插入结点
void insertNodeFollowing( CLinkedList L, CNode P, ElementType value );
// 指定位置结点后插入结点
void insertPositionFollowing( CLinkedList L, int i, ElementType value );

// 删除结点
void deleteNode( CLinkedList L, CNode P );
// 删除指定元素值结点
void deleteValue( CLinkedList L, ElementType value );
// 删除指定位置结点
void deletePosition( CLinkedList L, int i );
// 删除链表
void deleteList( CLinkedList L );

// 顺序输出链表元素值
void printList( CLinkedList L );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_CIRCULARLINKEDLIST_H
