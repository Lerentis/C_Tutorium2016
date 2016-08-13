/*******************************************************
 * Written by Lerentis
 * 
 * This file is part of C Course 2016 - HS-Bochum.
 * 
 * Compile gcc main.c -pthread -o pthreads
 *******************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* mutex variable */
pthread_mutex_t lock;

/* struct to handle multible parameters to thread function*/
struct data{
    int inc;
    char name[];
};

typedef struct data* data_ptr;

/* function to be executed in thread  */
/* pthread_create is defined as:      */
/* int pthread_create(pthread_t *restrict thread,
              const pthread_attr_t *restrict attr,
              void *(*start_routine)(void*), void *restrict arg); */
/* so we need a void pointer as param */
void *inc(void *x_tmp_ptr)
{
    /* get our old struct back*/
    data_ptr tmp_ptr = (data_ptr) x_tmp_ptr;

    /* lock mutex */
    pthread_mutex_lock(&lock);
    for (int var = 0; var <= 100; ++var) {
        tmp_ptr->inc = var;
        printf("%s in Thread has Number: %d \n",tmp_ptr->name, tmp_ptr->inc);
    }
    /* free mutex*/
    pthread_mutex_unlock(&lock);

    /* we have to return something. NULL is enough thou*/
    return NULL;
}

int main()
{

    /* create and fill data structs */
    data_ptr x = (data_ptr) calloc(1,sizeof(struct data));
    x->inc = 0;
    strcpy(x->name, "X Struct");

    data_ptr y = (data_ptr) calloc(1,sizeof(struct data));
    y->inc = 0;
    strcpy(y->name, "Y Struct");

    data_ptr z = (data_ptr) calloc(1,sizeof(struct data));
    z->inc = 0;
    strcpy(z->name, "Z Struct");

    /* initialize mutex */
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return -99;
    }

    /* create thread variables */
    pthread_t inc_x_thread;
    pthread_t inc_y_thread;
    pthread_t inc_z_thread;

    /* create a thread which executes inc(x) */
    if(pthread_create(&inc_x_thread, NULL, inc, x)) {
        printf("Error creating thread number 1\n");
        return 1;
    }

    /* create a second thread which executes inc(y) */
    if(pthread_create(&inc_y_thread, NULL, inc, y)) {
        printf("Error creating thread number 2\n");
        return 1;
    }

    /* create a third thread which executes inc(z) */
    if(pthread_create(&inc_z_thread, NULL, inc, z)) {
        printf("Error creating thread number 3\n");
        return 1;
    }

    /* wait for all threads to finish */
    if(pthread_join(inc_x_thread, NULL) || pthread_join(inc_y_thread, NULL) || pthread_join(inc_z_thread, NULL)) {
        printf( "Error joining thread\n");
        return 2;
    }

    /* show the results of all threads */
    printf("x: %d, y: %d, z: %d\n", x->inc, y->inc, z->inc);

    /* cleanup */
    pthread_mutex_destroy(&lock);
    free(x);
    free(y);
    free(z);

    return 0;

}
