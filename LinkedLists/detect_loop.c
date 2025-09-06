#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* isloop(Node* head){
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true; // Loop detected
        }
    }
    return false; // No loop
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
    // Creating a loop for testing
    head->next->next->next->next->next=head->next; // 5 -> 2
    if(isloop(head)){
        printf("Loop detected in the linked list\n");
    }
    else{
        printf("No loop in the linked list\n");
    }
    return 0;
}