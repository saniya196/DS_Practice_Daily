#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int size;
    int front;
    int rear;
    int *a;
}Queue;
Queue *create(){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    printf("Enter the size of the queue:");
    scanf("%d",&q->size);
    q->front=0;
    q->rear=-1;
    q->a=(int *)malloc(q->size * sizeof(int));
    return q;
}
int isFull(Queue *q){
    return((q->rear==q->size-1)?1:0);
}
int isEmpty(Queue *q){
    return ((q->front>q->rear)?1:0);
}
void enqueue(Queue *q,int ele){
    if (isFull(q)){
        printf("Queue is full\n");
    }
    else{
        q->rear++;
        q->a[q->rear]=ele;
        printf("Element %d added to queue\n",ele);
    }
}
void dequeue(Queue *q){
    if (isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        int x=q->a[q->front];
        q->front++;
        printf("Element %d removed from the Queue\n",x);
    }
}
void peek(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Element at the front is %d\n",q->a[q->front]);
    }
}
void display(Queue *q){
    if (isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue elements are:");
        for (int i=q->front ;i<=q->rear;i++){
            printf(" %d ",q->a[i]);
        }
    }
}
int main(){
    Queue *q=create();
    int choice,ele;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d",&ele);
                enqueue(q,ele);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                free(q->a);
                free(q);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}