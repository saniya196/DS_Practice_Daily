#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* reverse(Node* head){
    Node *prev=NULL,*curr=head,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
Node* newnode(int data){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
int main(){
    Node* head=newnode(1);
    head->next=newnode(2);
    head->next->next=newnode(3);
    head->next->next->next=newnode(4);
    head->next->next->next->next=newnode(5);
    printf("Original List: ");
    printList(head);
    head=reverse(head);
    printf("\nReversed List: ");
    printList(head);
    return 0;
}
