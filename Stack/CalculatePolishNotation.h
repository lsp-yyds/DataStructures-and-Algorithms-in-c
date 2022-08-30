//
// Created by bruce on 8/30/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_CALCULATEPOLISHNOTATION_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_CALCULATEPOLISHNOTATION_H

#include <stdbool.h>

struct StackRecord;
typedef struct StackRecord *Stack;

bool IsEmpty( Stack S );                  // 判空
bool IsFull( Stack S );                   // 判满
Stack CreateStack( int maxElements );     // 创建栈
void DisposeStack( Stack S );             // 销毁栈
void MakeEmpty( Stack S );                // 初始化栈
void Push( Stack S, int value );          // 进栈
int Top( Stack S );                       // 读栈顶元素
void Pop( Stack S );                      // 出栈
int TopAndPop( Stack S );                 // 读栈顶并出栈
void PrintStack( Stack S );               // 输出栈
int calculatePolishNotation( char *str ); // 计算波兰表达式

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_CALCULATEPOLISHNOTATION_H
