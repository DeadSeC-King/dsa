//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#define MAX 100
int deque[MAX];
int front=-1;
int rear=-1;
void insertFront(int x){
    if((front==0 && rear==MAX-1) || (front==rear+1)){
        printf("Deque is full\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0){
        front=MAX-1;
    }
    else{
        front--;
    }
    deque[front]=x;
}
void insertRear(int x){
    if((front==0 && rear==MAX-1) || (front==rear+1)){
        printf("Deque is full\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear==MAX-1){
        rear=0;
    }
    else{
        rear++;
    }
    deque[rear]=x;
}
void deleteFront(){
    if(front==-1){
        printf("Deque is empty\n");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
}
void deleteRear(){
    if(front==-1){
        printf("Deque is empty\n");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        rear=MAX-1;
    }
    else{
        rear--;
    }
}
void display(){
    if(front==-1){
        printf("Deque is empty\n");
        return;
    }
    int i=front;
    while(i!=rear){
        printf("%d ",deque[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n",deque[rear]);
}
int main(){
    insertRear(1);
    insertRear(2);
    insertFront(0);
    insertFront(-1);
    printf("Deque after inserting elements: ");
    display();
    deleteFront();
    printf("Deque after deleting front element: ");
    display();
    deleteRear();
    printf("Deque after deleting rear element: ");
    display();
    return 0;
}
