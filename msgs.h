#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "sem.h"

//message type
typedef struct message{
    int array_msg[10];
}message;

typedef struct port{
    int start;
    int end;
    Semaphore_t* mutex;
    Semaphore_t* full;
    Semaphore_t* empty;
    struct message* arr;
}port_t;

//array of ports
port_t p[100];

void initPort(int port_num){
      p[port_num].mutex = CreateSem(1);
      p[port_num].full = CreateSem(10);
      p[port_num].empty = CreateSem(0);
      p[port_num].arr = (struct message*) malloc(10* sizeof(struct message));
      p[port_num].start = 0;
      p[port_num].end = 0;
}

//send - blocking asynchronous send
void send(int num_port, int msg[]){
    //printf("in send - port num = %d\n",num_port);
    P((p[num_port].full));
    P((p[num_port].mutex));
    memcpy(&(p[num_port].arr[p[num_port].end]), msg, 10*sizeof(int));
    p[num_port].end = (p[num_port].end+1) % 10;
    V((p[num_port].mutex));
    V((p[num_port].empty));
}

//receive - blocking receive
void receive(int num_port , int msg[]){
    //printf("in receive - port num = %d\n",num_port);
    P((p[num_port].empty));
    P((p[num_port].mutex));
    memcpy(msg,&(p[num_port].arr[p[num_port].start]), 10*sizeof(int));
    p[num_port].start = (p[num_port].start+1) % 10;
    V((p[num_port].mutex));
    V((p[num_port].full));

}
