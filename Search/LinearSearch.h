//
// Created by bruce on 10/14/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINEARSEARCH_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINEARSEARCH_H

struct SearchTable;
typedef struct SearchTable SearchTable;
typedef int ElementType;

// 线性查找[O(n)]
int linearSearch( SearchTable T, ElementType value );
// 线性查找的优化
// 逆线性查找避免越界的判断
int inverseLinearSearch( SearchTable T, ElementType value );
// 对于有序数组的查找可以在比较完第一个大于目标值的位置终止
// 对于被查元素概率不相等且查找成功次数较多的情况可以将元素按概率降序排列

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_C_LINEARSEARCH_H
