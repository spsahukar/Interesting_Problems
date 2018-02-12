//
//  sort_stack_inplace.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 4/4/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "sort_stack_inplace.hpp"

//std::stack <int> my_sip_stack;

void insert_sorted(std:: stack <int> *my_sip_stack, int num)
{

    if (my_sip_stack -> empty() || my_sip_stack -> top() < num)
        my_sip_stack -> push(num);
    else
    {
        int temp1;
        temp1 = my_sip_stack -> top();
        my_sip_stack -> pop();
        insert_sorted(my_sip_stack, num);
        my_sip_stack -> push(temp1);
    }
    
}

void sort_stack(std:: stack <int> *my_sip_stack)
{
    if (my_sip_stack -> empty())
        return;
    else
    {
        int temp = my_sip_stack -> top();
        my_sip_stack -> pop();
        sort_stack(my_sip_stack);
        insert_sorted(my_sip_stack, temp);
    }
}


void test_sort_stack(void){
    
    std::stack <int> my_sip_stack;
    //my_sip_stack = NULL;
    
    my_sip_stack.push(1);
    my_sip_stack.push(-1);
    my_sip_stack.push(5);
    my_sip_stack.push(3);
    
    sort_stack(&my_sip_stack);
    
    printf("After Sorting\n");
    
    while(!my_sip_stack.empty())
    {
        printf("Sorted Array: %d\n", my_sip_stack.top());
        my_sip_stack.pop();
        
    }
    
}
