//wap to insert element in a queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front=0;
int rear= -1;
void enqueue_kr(int val){
    if(rear==MAX-1){
        printf("queue overflow");
    }
    rear++;
    queue[rear]=val;
    printf("value inserted successfully",val);

}
void dequeue(int val){
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Removed %d\n", queue[front]);
    front++;
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    enqueue_kr(10);
    dequeue(10);
}