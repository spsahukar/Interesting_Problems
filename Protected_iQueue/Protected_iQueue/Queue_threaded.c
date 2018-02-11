//
//  Queue_threaded.c
//  Oculus_Onsite
//
//  Created by Surya Sahukar on 12/11/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "Queue_threaded.h"

struct qu_node *q_node;

#define NUM_ENQ_THREADS 10
#define NUM_DQ_THREADS 2

void wait_ms(struct timespec *ts, int timeInMs)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ts -> tv_sec = time(NULL) + timeInMs / 1000;
    ts -> tv_nsec = tv.tv_usec * 1000 + 1000 * 1000 * (timeInMs % 1000);
    ts -> tv_sec += ts -> tv_nsec / (1000 * 1000 * 1000);
    ts -> tv_nsec %= (1000 * 1000 * 1000);
}

int enqueue(int item)
{
    int ret = 0;
    struct node *temp = (struct node *) malloc(sizeof(struct node ));
    temp -> data = item;
    temp -> next = NULL;
    
    pthread_mutex_lock(&q_node -> b_lock);
    if (! q_node -> front && ! q_node -> back)
    {
        pthread_mutex_lock(&q_node -> f_lock);
        q_node -> front = temp;
        q_node -> back = temp;
        pthread_mutex_lock(&q_node -> count_lock);
        q_node -> count++;
        pthread_mutex_unlock(&q_node -> count_lock);
        pthread_mutex_unlock(&q_node -> f_lock);
        printf("Enqueue Item = %d\n", temp -> data);
        ret = 1;
    }
    else
    {
        q_node -> back -> next = temp;
        q_node -> back = temp;
        pthread_mutex_lock(&q_node -> count_lock);
        q_node -> count++;
        printf("Enqueue Item = %d\n", temp -> data);
        pthread_mutex_unlock(&q_node -> count_lock);
        ret = 1;
    }
    pthread_cond_signal(&q_node -> cond_var);
    pthread_mutex_unlock(&q_node -> b_lock);
    
    if (ret)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;                                                                /* return 1 for sucess 0 for fail */
}

int dequeue()
{
    struct node *temp;
    int item;
    
    struct timespec *wait;
    wait = malloc(sizeof(struct timespec));
    wait_ms(wait, 1);

    if(!q_node -> front && !q_node -> back)
    {
        printf("Wait entry called ...\n");
        pthread_mutex_lock(&q_node -> f_lock);
        pthread_cond_timedwait(&q_node -> cond_var, &q_node -> f_lock, wait);
        pthread_mutex_unlock(&q_node -> f_lock);
        printf("Wait exit called ...\n");
        return EXIT_FAILURE;
    }
    
    pthread_mutex_lock(&q_node -> f_lock);

    if (q_node -> front && q_node -> front == q_node -> back)
    {
        temp = q_node -> front;
        temp -> next = NULL;
        q_node -> front = NULL;
        pthread_mutex_lock(&q_node -> b_lock);
        q_node -> back = NULL;
        pthread_mutex_unlock(&q_node -> b_lock);
        pthread_mutex_lock(&q_node -> count_lock);
        q_node -> count = 0;
        pthread_mutex_unlock(&q_node -> count_lock);
        item = temp -> data;
        free(temp);
        printf("Dequeue Item = %d\n", item);
    }
    else if (q_node -> front)
    {
        temp = q_node -> front;
        q_node -> front = temp -> next;
        temp -> next = NULL;
        pthread_mutex_lock(&q_node -> count_lock);
        q_node -> count--;
        pthread_mutex_unlock(&q_node -> count_lock);
        item = temp -> data;
        free(temp);
        printf("Dequeue Item = %d\n", item);
    }
    pthread_mutex_unlock(&q_node -> f_lock);
    
    return item;
}

void e_thread()
{
    int item;
    for (int i = 0; i < 5 ; i++)
    {
        item = i * 10;
        enqueue(item);
    }
}

void d_thread()
{
    for (int i = 0; i < 5 ; i++)
    {
        dequeue();
    }
    
}

void queue_setup()
{
    q_node =  (struct qu_node *)malloc(sizeof(struct qu_node));
    q_node -> front = NULL;
    q_node -> back = NULL;
    q_node -> count = 0;
    pthread_mutex_init(&q_node -> f_lock, NULL);
    pthread_mutex_init(&q_node -> b_lock, NULL);
    pthread_mutex_init(&q_node -> count_lock, NULL);
    pthread_cond_init(&q_node -> cond_var , NULL);
}

void test_mutex()
{
    int i;
    queue_setup();
    pthread_t e_tid[NUM_ENQ_THREADS];
    pthread_t d_tid[NUM_DQ_THREADS];
    
    for(i = 0; i < NUM_ENQ_THREADS; i++)
    {
        pthread_create(&e_tid[i], NULL, &e_thread, NULL);
    }
    
    for(i = 0; i < NUM_DQ_THREADS; i++)
    {
        pthread_create(&d_tid[i], NULL, &d_thread, NULL);
    }
    
    for(i = 0; i < NUM_ENQ_THREADS; i++)
    {
        pthread_join(e_tid[i], NULL);
    }
    
    for(i = 0; i < NUM_DQ_THREADS; i++)
    {
        pthread_join(d_tid[i], NULL);
    }
}
