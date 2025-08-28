#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int size;
    int top;
    int *a;
}Stack;
Stack *create(){
    Stack *s=(Stack *)malloc(sizeof(Stack));
    printf("Enter thesize of the stack:");
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
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        int x=s->a[s->top];
        s->top--;
        return x;
    }
}
int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        return s->a[s->top];
    }
}
void nextGreaterElement(int arr[],int n){
    Stack *s=create();
    int ans[n];
    int k=0,i;
    for (int i=n-1;i>=0;i--){
        while (!isEmpty(s) && peek(s)<arr[i]){
            pop(s);
        }
        if (isEmpty(s)){
            ans[k++]=-1;
        }
        else{
            ans[k++]=peek(s);

        }
        }
        push(s,arr[i]);
    for (int i = k - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(s->a); 
    free(s);    
}
int main() {
    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}





