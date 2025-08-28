#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* head=NULL;
void InsertBegin(int ele){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=ele;
    newnode->next=head;
    head=newnode;
}
void InsertEnd(int ele){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=ele;
    newnode->next=NULL;
    if (head==NULL){
        head=newnode;
    }
    else{
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void InsertAtPos(int ele,int pos){
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->data=ele;
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    Node *temp=head;
    for (int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
    }
    if(temp==NULL){
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }
newnode->next=temp->next;
temp->next=newnode;
}
void DeleteBegin(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        Node *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
        return head;
    }
}
void DeleteEnd(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if (head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        Node *temp=head;
        Node *temp2=head;
        while(temp->data!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        free(temp);
        temp=NULL;
    }
    }
