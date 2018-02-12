//
//  inorder_traversal_stacks.hpp
//  Learning_2017
//
//  Created by Surya Sahukar on 4/3/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#ifndef inorder_traversal_stacks_hpp
#define inorder_traversal_stacks_hpp

#include <stdio.h>
#include "stack"
#include "iostream"
#include "stdio.h"
#include "queue"


struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int);
struct node *insert_bst(struct node *, int);
void inorder_traversal(struct node *);
int8_t find_pair(struct node *, int);
void test_stub_inorder_traversal();
#endif /* inorder_traversal_stacks_hpp */
