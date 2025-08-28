#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Stack{
    int size;
    int top;
    int *a;
}Stack;
Stack *create(int size){
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->size=size;
    s->top=-1;
    s->a=(int *)malloc(s->size*sizeof(int));
    return s;
}
int isFull(Stack *s){
    return((s->top==s->size-1)?1:0);
}
int isEmpty(Stack *s){
    return((s->top==-1)?1:0);
}
void push(Stack *s,int ele){
    if (isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->a[++s->top]=ele;
    }
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return s->a[s->top--];
    }
}
int evaluatepostfix(char *exp){
    Stack *s=create(100);
    int i=0;
    while (exp[i]!='\0'){
        char ch=exp[i];
        if (isdigit(ch)){
            push(s,ch-'0');
        }
        else{
            int val2=pop(s);
            int val1=pop(s);
            switch(ch){
                case '+': push(s,val1+val2); break;
                case '-': push(s,val1-val2); break;
                case '*': push(s,val1*val2); break;
                case '/': push(s,val1/val2); break;
            }
        }
        i++;
    }
    return pop(s);
}
int main(){
    char exp[100];
    printf("Enter a postfix expresssion:\n");
    scanf("%s",exp);
    int result=evaluatetopostfix(exp);
    printf("Result of postfix expression %s is: %d\n",exp,result);
    return 0;
}
