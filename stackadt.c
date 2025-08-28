#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int size;
    int top;
    int *a;
}Stack;
Stack *create(){
    Stack *s= (Stack*)malloc(sizeof(Stack));
    printf("Enter the size of the stack:");
    scanf("%d",&s->size);
    s->top=-1;
    s->a=(int *)malloc(s->size*sizeof(int));
    return s;
}
int isFull(Stack *s){
    return ((s->top==s->size-1)?1:0);
}
int isEmpty(Stack *s){
    return ((s->top==-1)?1:0);
}
void push(Stack*s,int ele){
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->top++;
        s->a[s->top]=ele;
        printf("Element %d pushed to stack\n",ele);
    }
}
void pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        int x=s->a[s->top];
        s->top--;
        printf("Element %d popped from stack\n",x);
    }
}
void peak(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",s->a[s->top]);
    }
}
void display(Stack *s){
    if (isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements are:");
        for(int i=0;i<=s->top;i++){
            printf(" %d ",s->a[i]);
        }
    }
}
int getmin(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty");
        return -1;
    }
    int min=s->a[0];
    for (int i=1;i<=s->top;i++){
        if (s->a[i]<min){
            min=s->a[i];
        }
    }
    return min;
}
int main(){
    Stack *s=create();
    int choice,ele;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Peak\n4. Display\n5. Exit\n 6.Get Minimum\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(s, ele);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peak(s);
                break;
            case 4:
                display(s);
                break;
            case 6:
                printf("Minimum element in the stack is :%d\n",getmin(s));
                break;
            case 5:
                free(s->a);
                free(s);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
