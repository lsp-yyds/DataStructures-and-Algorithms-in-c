//
// Created by bruce on 9/8/22.
//

#include "ThreadedBinaryTree.h"

struct TreeNode {
    ElementType element;
    struct TreeNode *left, *right;
    int l_tag, r_tag;
};

// TODO
