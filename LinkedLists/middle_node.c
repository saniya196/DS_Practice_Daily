#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* middleNode(Node* head){
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void printList(Node *head){
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
    Node* mid=middleNode(head);
    printf("\nMiddle Node: %d\n",mid->data);
    return 0;
}
