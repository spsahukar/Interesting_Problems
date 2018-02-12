//
//  Reverse_Stack_Inplace.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 4/4/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "Reverse_Stack_Inplace.hpp"




void insert_bottom(std::stack <int> *mystack, int num)
{
    if(mystack -> empty())
        mystack -> push(num);
    else
    {
        int temp;
        temp = mystack -> top();
        mystack -> pop();
        insert_bottom(mystack, num);
        mystack -> push(temp);
    }
}

void reverse_stack(std::stack <int> *mystack)
{
    if (mystack -> empty())
        return;
    else{
        int temp;
        temp = mystack -> top();
        mystack -> pop();
        reverse_stack(mystack);
        insert_bottom(mystack, temp);
    }
}

void test_reverse_stack(void)
{
    std:: stack <int> mystack;
    mystack.push(1);
    mystack.push(5);
    mystack.push(9);
    mystack.push(13);
    
    printf("Before Reversing\n");
    
    while(!mystack.empty())
    {
        printf("Stack Element = %d\n", mystack.top());
        mystack.pop();
    }
    
    mystack.push(1);
    mystack.push(5);
    mystack.push(9);
    mystack.push(13);
    
    reverse_stack(&mystack);
    
    printf("After Reversing\n");
    
    while(!mystack.empty())
    {
        printf("Stack Element = %d\n", mystack.top());
        mystack.pop();
    }
}
