#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;


 


Node *createNode(int info){
    Node *node = (Node *)malloc(sizeof(Node));
    node ->data = info;
    node ->next = NULL;
    return node;
}


Node *node,*start=NULL, *q, *temp;
void insertAtStart(int info);
void insertAtEnd();
void insertByData();
void insertByPos();
void deleteAtStart();
void deleteAtEnd();
void deleteByData();
void deleteByPos();
void display();
int searchNode(int info);
void searchAndDelete(int info);


void main(){
    int i,choice=1;
    while(choice){


        printf("Enter Operation To be Performed on Linked List - \n1. Insert At Start \n2. Insert At End \n3. Insert By Data\n4.Insert By Pos \n5. Delete at Start \n6. Delete at End \n7. Delete by Data \n8. Delete by Pos \n9. Display \n10. Search Node \n11. Search and Delete Any Other Key to Exit\n");
         scanf("%d",&choice);
        switch(choice){
            case 1:{                
                insertAtStart();
                display();
                break;
            }
            case 2:{
                insertAtEnd();
                display();
                break;
            }
            case 3:{
                insertByData();
                display();
                break;
            }
            case 4:{
                insertByPos();
                display();
                break;
            }
            case 5:{
                deleteAtStart();
                display();
                break;
            }
            case 6:{
                deleteAtEnd();
                display();
                break;
            }
            case 7:{        
                int datach;
                printf("Enter data choice: ");
                scanf("%d",&datach);        
                deleteByData(datach);
                display();
                break;
            }
            case 8:{                
                deleteByPos();
                display();
                break;
            }
            case 9:{
                display();                
                break;
            }
            case 10:{
                int info;
                printf("Enter node to be searched- ");
                scanf("%d",&info);                                
                searchNode(info);
                break;
            }
            case 11:{
                int info;
                printf("Enter node to be searched- ");
                scanf("%d",&info);
                searchAndDelete(info);
                display();
                break;
            }
            default:{
                choice = 0;
                break;
            }
        }
    }
}


void insertAtStart(int info){
    printf("Enter Data: ");
    scanf("%d",&info);
    node = createNode(info);
    if(start == NULL){
        start = node;
    }else{
        node ->next = start;
        start = node;
    }
}


void insertAtEnd(int info){
    if(start == NULL){
        printf("List is Empty");
    }
    
    printf("\n Enter Data: ");
    scanf("%d",&info);
    node = createNode(info);
    q=start;
    while(q -> next != NULL){
        q = q->next;
    }
    q->next = node;
    node-> next = NULL;    
}


void insertByData(){
    int info,datach;
    printf("Enter Data: ");
    scanf("%d",&info);
    node = createNode(info);


    printf("Enter data choice: ");
    scanf("%d",&datach);
    if(start == NULL){


        printf("List is Empty");
    }
    q = start;
    while(q->data != datach){
        if(q->next == NULL){
            printf("Not Found");
            return 0;
        }
        q=q->next;
       
    }
    node->next = q->next;
    q->next =  node;    
}


void insertByPos(){
    int info,pos,count=1;
    printf("Enter Data: ");
    scanf("%d",&info);
    node = createNode(info);


    printf("Enter position: ");
    scanf("%d",&pos);
    if(start == NULL){
        free(node);
        insertAtStart(info);
    }
    q=start;
    while(count!=pos){
        q = q->next;
        count++;
    }
    node->next = q->next;
    q->next =  node;
}


void deleteAtStart(){
    if(start == NULL){
        printf("List is Empty");
    }
    temp = start;
    start = start -> next;
    free(temp);
}


void deleteAtEnd(){
    if(start == NULL){
        printf("List is Empty");
    }
    q=start;
    while(q->next->next != NULL){
        q = q->next;
    }
    temp = q->next;
    q->next = NULL;
    free(temp);
}


void deleteByData(int datach){    
    if(start == NULL){
        printf("List is Empty");
    }    
    q = start;
    while(q->next->data != datach){
        if(q->next == NULL){
            printf("Not Found");
            return 0;
        }
        q=q->next;        
    }
    temp = q->next;
    q->next = temp ->next;
    free(temp);
}


void deleteByPos(){
    int pos,count=1;
    if(start == NULL){
        printf("List is Empty");
    }
    printf("Enter position: ");
    scanf("%d",&pos);
    q = start;
    while(count != pos-1){
        q = q -> next;
        count++;
    }
    temp = q->next;
    q->next = temp ->next;
    free(temp);
}


int searchNode(int info){
    if(start == NULL){
        printf("List is Empty");
    }    
    q = start;
    while(q->data != info){
        if(q->next == NULL){
            printf("Not Found");
            return 0;
        }
        q = q->next;        
    }
    printf("Found");
    return info;
}


void searchAndDelete(int info){
    int res;
    res = searchNode(info);
    deleteByData(res);
}


void display(){
   
    if(start == NULL){


        printf("List is Empty");
    }
    else{
        q = start;
        while (q != NULL){
            printf("%d -> ",q ->data);
            q = q ->next;
        }
    }    
    printf("NULL\n");
}

