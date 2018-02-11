//
//  Queue_threaded.h
//  Oculus_Onsite
//
//  Created by Surya Sahukar on 12/11/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#ifndef Queue_threaded_h
#define Queue_threaded_h

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

struct node
{
    int data;
    struct node *next;
};

struct qu_node
{
    struct node *front;
    struct node *back;
    int count;
    pthread_mutex_t f_lock;
    pthread_mutex_t b_lock;
    pthread_mutex_t count_lock;
    pthread_cond_t cond_var;
};

void queue_setup(void);

int enqueue(int);
int dequeue(void);

void e_thread(void);
void d_thread(void);

void test_mutex( void);






#endif /* Queue_threaded_h */
