#define _XOPEN_SOURCE 600 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // Needed for sleep
#include <pthread.h>

void hello_world(){
    int random = rand()%5;
    sleep(random);
    printf("Hello World\n");
    pthread_exit(NULL);
}
void goodbye(){
    int random2 = rand()%5;
    sleep(random2);
    printf("Goodbye\n");
    pthread_exit(NULL);
}

int main(void){
    pthread_t th1, th2;
    if(pthread_create(&th1, NULL, &hello_world, NULL)){
        printf("Could not create thread 1.");
        return -1;
    }
    
    if(pthread_create(&th2, NULL, &goodbye, NULL)){
        printf("Could not create thread 2.");
        return -1;
    }

    if(pthread_join(th1, NULL)){
        printf("Could not join th1.");
        return -1;
    }

    if(pthread_join(th2, NULL)){
        printf("Could not join th2.");
        return -1;
    }

    return 0;
}