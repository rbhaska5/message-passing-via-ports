//dmos - project 4
//Description -  build a module that does message passing via ports
//Rachana Bhaskar - 1217402615
//Ramya Venkateshachary - 1217107164


#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "msgs.h"


void server(){
  int server_port = 14;
  initPort(server_port);
  printf("In Server function, started server \n");
  while(1)
  {

    //int message[10]={1,1,1,1,1,1,1,1,1,1};
    int received[10];
    int reply_port;
    receive(server_port, received);
    reply_port = received[0];
    //printf("num ==== %d\n",received[0]);
    printf("Message received by Server port (14) from client through port (%d)\n", reply_port);
    printf("-------------------------------\n");
    for(int i =0;i<10;i++){
      printf("message[%d] data = %d \n",i,received[i]);
    }
    printf("-------------------------------\n");
    sleep(1);
    send(reply_port,received);
    printf("Message sent by Server port (14) to client port(%d)\n", reply_port);
  }
}

void client1()
{
  printf("In Client function, started client 1\n");
  int server_port = 14;
  int client_port = 1;
  initPort(client_port);
  int received[10] = {1,8,8,8,8,8,8,8,8,8};
  received[0] = client_port;
  //printf("num in client ==== %d\n",received[0]);
  while(1)
  {
    send(server_port,  received);
    // sleep(1);
    printf("Message sent by client - port(%d) to server - port (%d)\n", client_port,server_port);
    sleep(1);
    receive(client_port, received);
    printf("Message received by client - port(%d) from server port (%d)\n", client_port,server_port);

  }
}

void client2()
{
  printf("In Client function, started client 2\n");
  int server_port = 14;
  int client_port = 2;
  initPort(client_port);
  int received[10] = {2,3,3,3,3,3,3,3,3,3};
  received[0] = client_port;
  //	printf("num in client ==== %d\n",received[0]);
  while(1)
  {
    send(server_port,  received);
    // sleep(1);
    printf("Message sent by client - port(%d) to server - port (%d)\n", client_port,server_port);
    sleep(1);
    receive(client_port, received);
    printf("Message received by client - port(%d) from server port (%d)\n", client_port,server_port);

  }
}

void client3()
{
  printf("In Client function, started client 3\n");
  int server_port = 14;
  int client_port = 3;
  initPort(client_port);
  int received[10] = {3,5,5,5,5,5,5,5,5,5};
  received[0] = client_port;
  //printf("num in client ==== %d\n",received[0]);
  while(1)
  {
    send(server_port,  received);
    //sleep(1);
    printf("Message sent by client - port(%d) to server - port (%d)\n", client_port,server_port);
    sleep(1);
    receive(client_port, received);
    printf("Message received by client - port(%d) from server port (%d)\n", client_port,server_port);

  }
}

void client4()
{
  printf("In Client function, started client 4\n");
  int server_port = 14;
  int client_port = 4;
  initPort(client_port);
  int received[10] = {4,1,1,1,1,1,1,1,1,1};
  received[0] = client_port;
  //printf("num in client ==== %d\n",received[0]);
  while(1)
  {
    send(server_port,  received);
    // sleep(1);
    printf("Message sent by client - port(%d) to server - port (%d)\n", client_port,server_port);
    sleep(1);
    receive(client_port, received);
    printf("Message received by client - port(%d) from server port (%d)\n",client_port,server_port);

  }
}

void client5()
{
  printf("In Client function, started client 5\n");
  int server_port = 14;
  int client_port = 5;
  initPort(client_port);
  int received[10] = {5,10,10,10,10,10,10,10,10,10};
  received[0] = client_port;
  //printf("num in client ==== %d\n",received[0]);
  while(1)
  {
    send(server_port,  received);
    // sleep(1);
    printf("Message sent by client - port(%d) to server - port (%d)\n", client_port,server_port);
    sleep(1);
    receive(client_port, received);
    printf("Message received by client - port(%d) from server port (%d)\n", client_port,server_port);

  }
}


int main(){
  ReadyQ = newQueue(ReadyQ);
  start_thread(server);
  printf("Server thread created\n");
  start_thread(client1);
  printf("Client1 thread created\n");
  start_thread(client2);
  printf("Client2 thread created\n");
  start_thread(client3);
  printf("Client3 thread created\n");
  start_thread(client4);
  printf("Client4 thread created\n");
  start_thread(client5);
  printf("Client5 thread created\n");

  run();
  while(1){
    sleep(1);
  }
}
