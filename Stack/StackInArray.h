//
// Created by bruce on 8/24/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_STACKINARRAY_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_STACKINARRAY_H

#include <stdbool.h>

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

bool isEmpty( Stack S );                 // 判空
bool isFull( Stack S );                  // 判满
Stack createStack( int maxElements );    // 创建栈
void disposeStack( Stack S );            // 销毁栈
void makeEmpty( Stack S );               // 初始化栈
void push( Stack S, ElementType value ); // 进栈
ElementType top( Stack S );              // 读栈顶元素
void pop( Stack S );                     // 出栈
ElementType topAndPop( Stack S );        // 读栈顶并出栈
void printStack( Stack S );              // 输出栈

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_STACKINARRAY_H
