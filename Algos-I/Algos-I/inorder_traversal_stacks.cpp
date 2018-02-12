//
//  inorder_traversal_stacks.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 4/3/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "inorder_traversal_stacks.hpp"

struct node *create_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node * insert_bst(struct node *root,int data)
{
    if(!root)
        return(create_node(data));
    if(!root -> right && data >= root->data)
    {
        root->right=create_node(data);
        return root->right;
    }
    if(!root -> left && data < root->data)
    {
        root->left=create_node(data);
        return root->left;
    }
    
    
    if (data >= root->data)
        insert_bst(root->right,data);
    if(data < root->data)
        insert_bst(root->left,data);
    
    return NULL;
}

    
void inorder_traversal(struct node *root)
{
    if (!root) return;
    
    std:: stack <struct node *> curr_stack;
    std:: stack <struct node *> inorder_stack;
    std:: queue <struct node *> inorder_queue;
    
    struct node *curr = root;
    
    uint8_t done = 0;
    
    while(!done)
    {
        if (curr)
        {
            curr_stack.push(curr);
            curr = curr -> left;
            //curr = curr -> right;
        }
        else
        {
            if (!curr_stack.empty())
            {
                curr = curr_stack.top();
                inorder_stack.push(curr);
                inorder_queue.push(curr);
                curr_stack.pop();
                if (curr -> right)
                    curr = curr -> right;
                //if (curr -> left)
                  //  curr = curr -> left;
                else
                    curr = NULL;
            }
            else
                done = 1;
        }
        
    }
    
    std:: cout << "Inorder Stack: Smallest at the bottom of the stack" << std::endl;
    while(!inorder_stack.empty())
    {
        printf("%d\n", inorder_stack.top() -> data);
        inorder_stack.pop();
    }
    
    std:: cout << "Reverse Inorder: Smallest at the top of the stack" << std::endl;
    while(!inorder_queue.empty())
    {
        printf("%d\n", inorder_queue.front() -> data);
        inorder_queue.pop();
    }
    


}

int8_t find_pair(struct node *root, int sum)
{
    if (!root) return -1;
    
    std:: stack <struct node *> forward_stack;
    std:: stack <struct node *> reverse_stack;
    
    struct node *curr_forward = root;
    struct node *curr_reverse = root;
    
    uint8_t done_forward = 0;
    uint8_t done_reverse = 0;
    
    int forward_val = 0;
    int reverse_val = 0;
    
    while (1)
    {
        while(!done_forward)
        {
            if (curr_forward)
            {
                forward_stack.push(curr_forward);
                curr_forward = curr_forward -> left;
                
            }
            else
            {
                if (!forward_stack. empty())
                {
                    curr_forward = forward_stack.top();
                    forward_val = curr_forward -> data;
                    forward_stack.pop();
                    
                    if (curr_forward -> right)
                        curr_forward = curr_forward -> right;
                    else
                        curr_forward = NULL;
                }
                //else
                done_forward = 1;
            }
            
        }
        
        while(!done_reverse)
        {
            if (curr_reverse)
            {
                reverse_stack.push(curr_reverse);
                curr_reverse = curr_reverse -> right;
                
            }
            else
            {
                if (!reverse_stack.empty())
                {
                    curr_reverse = reverse_stack.top();
                    reverse_val = curr_reverse -> data;
                    reverse_stack.pop();
                    
                    if (curr_reverse -> left)
                        curr_reverse = curr_reverse -> left;
                    else
                        curr_reverse = NULL;
                }
                //else
                done_reverse= 1;
            }
            
        }
        
        if ( forward_val + reverse_val == sum)
        {
            //std:: cout << " Pair Found: %d, %d" << curr_forward -> data, curr_reverse -> data ;
            printf("Pair Found:%d, %d\n", forward_val, reverse_val);
            return 0;
        }
        
        if (forward_val + reverse_val > sum)
            done_reverse = 0;
        
        if (forward_val + reverse_val < sum)
            done_forward = 0;
        
        if (forward_val > reverse_val )
            return -1;

        
    }
}


void test_stub_inorder_traversal()
{
    struct node *root=create_node(10);
    insert_bst(root,3);
    insert_bst(root,40);
    insert_bst(root,-1);
    insert_bst(root,70);
    insert_bst(root,11);
    insert_bst(root,7);
    
    inorder_traversal(root);
    
    
    int8_t ret= find_pair(root, 49);
    
    if(ret < 0)
        printf("No Pair found\n");
    else
        printf("Pair found\n");
    
}
