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
typedef PtrToNode Position;

// 初始化链表
LinkedList makeEmpty( LinkedList L );
// 判链表是否为空
bool isEmpty( LinkedList L );
// 判断结点是否为表尾结点
bool isLast( LinkedList L, Position P );
// 头结点
Position header( LinkedList L );
// 链表第一个结点
Position first( LinkedList L );
// 结点的下一个结点
Position advance( Position P );
// 确定结点在链表中的位置(链表元素位序从1开始)
int position( LinkedList L, Position P );
// 结点的元素值
ElementType retrieve( Position P );
// 链表长度
int length( LinkedList L );

// 此处默认所有结点的元素值不相同
// 查找第i个结点的前驱结点
Position findPrevious( LinkedList L, int i );
// 查找结点元素值为value的前一个结点
Position findValuePrevious( LinkedList L, ElementType value );
// 查找结点的前一个结点
Position findPositionPrevious( LinkedList L, Position P );
// 查找第i个结点
Position find( LinkedList L, int i );
// 查找结点元素值为value的结点
Position findValue( LinkedList L, ElementType value );

// 更改

// 头插
void headInsert( LinkedList L, ElementType value );
// 尾插
void tailInsert( LinkedList L, ElementType value );
// 在第i个位置前插入元素值为value的结点
void insertPrior( LinkedList L, int i, ElementType value );
// 在结点前插入元素值为value的结点
void insertPriorPosition( LinkedList L, Position P, ElementType value );
// 在第i个结点后插入元素值为value的结点
void insertNext( LinkedList L, int i, ElementType value );
// 在结点后插入元素值为value的结点
void insertNextPosition( LinkedList L, Position P, ElementType value );

// 删除结点
void deletePosition( LinkedList L, Position P );
// 删除结点元素值为value的结点
void deleteValue( LinkedList L, ElementType value );
// 删除第i个结点
void delete ( LinkedList L, int i );
// 删除链表
void deleteList( LinkedList L );

// 顺序输出链表元素值
void printList( LinkedList L );

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINKEDLIST_H
