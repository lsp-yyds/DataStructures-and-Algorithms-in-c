//
// Created by bruce on 8/29/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_CONVERTTOPOLISHNOTATION_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_CONVERTTOPOLISHNOTATION_H

#include <stdbool.h>

struct StackRecord;
typedef struct StackRecord *Stack;

bool isEmpty( Stack S );                            // 判空
bool isFull( Stack S );                             // 判满
Stack createStack( int maxElements );               // 创建栈
void disposeStack( Stack S );                       // 销毁栈
void makeEmpty( Stack S );                          // 初始化栈
void push( Stack S, char value );                   // 进栈
char top( Stack S );                                // 读栈顶元素
void pop( Stack S );                                // 出栈
char topAndPop( Stack S );                          // 读栈顶并出栈
void printStack( Stack S );                         // 输出栈
void convertToPolishNotation( char *str, char *s ); // 转化成波兰表达式

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_CONVERTTOPOLISHNOTATION_H
