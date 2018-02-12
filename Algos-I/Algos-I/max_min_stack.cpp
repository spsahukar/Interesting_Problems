//
//  max_min_stack.cpp
//  Learning_2017
//
//  Created by Surya Sahukar on 4/4/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "max_min_stack.hpp"

//std:: stack <int> mymaxstack, myminstack;

void max_stack_push(std::stack <int> *mymaxstack, int num)
{
    if (mymaxstack -> empty() || mymaxstack -> top() <= num)
        mymaxstack -> push(num);
    else
    {
        int temp;
        temp = mymaxstack -> top();
        mymaxstack -> pop();
        max_stack_push(mymaxstack, num);
        mymaxstack -> push(temp);
    }
        
}
void min_stack_push(std::stack <int> *myminstack, int num)
{
    if (myminstack -> empty() || myminstack -> top() >= num)
        myminstack -> push(num);
    else
    {
        int temp;
        temp = myminstack -> top();
        myminstack -> pop();
        min_stack_push(myminstack, num);
        myminstack -> push(temp);
    }
    
}

void test_max_min_stack(void)
{
    
    std:: stack <int> mymaxstack, myminstack;
    //myminstack = NULL;
    //mymaxstack = NULL;
    
    max_stack_push(&mymaxstack,5);
    max_stack_push(&mymaxstack,3);
    max_stack_push(&mymaxstack,1);
    max_stack_push(&mymaxstack,2);
    
    
    
    min_stack_push(&myminstack,1);
    min_stack_push(&myminstack,2);
    min_stack_push(&myminstack,5);
    min_stack_push(&myminstack,-1);
    
    printf("Max Stack Created\n");
    
    while(!mymaxstack.empty())
    {
        printf("Max Stack Element: %d\n", mymaxstack.top());
        mymaxstack.pop();
    }
    
    printf("Min Stack Created\n");
    
    while(!myminstack.empty())
    {
        printf("Min Stack Element: %d\n", myminstack.top());
        myminstack.pop();
    }
    
}


