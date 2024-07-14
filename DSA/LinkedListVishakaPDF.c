// SINGLY LINKED LIST 
#include <stdio.h>
#include <stdlib.h>

 struct Node {
    int data;
    struct Node *next;
};
struct Node *node, *start = NULL, *q, *temp;

struct Node* createNode(int info){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node ->data = info;
    node ->next = NULL;
    return node;
}


void addAtFront(int info){
    node = createNode(info);
    if(start == NULL){
	start = node;
    }else{
	node-> next = start;
	start = node;
    }
}

void addAtLast(int info){
    temp = createNode(info);
    q = start;
    while(q->next!=NULL){
	q = q-> next;
    }
    q->next = temp;
    temp->next = NULL;
}

void addbefore(int info){
    int no;
    printf("Enter the data before new node to be added: ");
    scanf("%d", &no);
    temp = createNode(info);
    q = start;
    while(q->next->data!=no){
	q = q-> next;
    }
     temp->next=q->next;
     q->next=temp;
}
void addafter(int info){
    int no;
    printf("Enter the data after new node to be added: ");
    scanf("%d", &no);
    temp = createNode(info);
    q = start;
    while(q->data!=no){
	q = q-> next;
    }
     temp->next=q->next;
     q->next=temp;
}

void addPosition(int info){
    int no,i;
    printf("Enter the Position: ");
    scanf("%d", &no);
    temp = createNode(info);
    q = start;
    for(i = 1; i<no-1; i++){
	q = q->next;
    }
    temp->next = q->next;
    q->next = temp;
}

void display() {
    if(start == NULL){
	printf("List is Empty.");
    }else{
	q = start;
	printf("Linked List: ");
	while(q != NULL){
	    printf("%d->",q->data);
	    q = q-> next;
	}

	printf("NULL\n");
    }
}

void deleteAtFront(){
    if(start == NULL){
	printf("The List is empty.\n");
    }else{
	temp = start;
	start = temp-> next;
	printf("Deleted Node is: %d\n",temp->data);
	free(temp);
    }
}

void deleteAtLast(){
    if(start == NULL){
	printf("The List is empty.\n");
    }else if(start  == start->next){
	free(start);
    }else{
	q = start;
	while(q->next->next!=NULL){
	    q = q->next;
	}
	temp = q->next;
	q->next = NULL;
	printf("Deleted Node is: %d\n",temp->data);
	free(temp);
    }
}


void deletePosition(){
    int no,i;
    printf("Enter Position to delete: ");
    scanf("%d", &no);
    if(start == NULL){
	printf("The List is empty.\n");
	return;
    }else if(no == 1){
	deleteAtFront();
    }else{
	q = start;
	for( i = 1; i< no -1; i++){
	    q = q->next;
	}
	temp = q->next;
	q->next = temp->next;
	printf("Deleted Node is: %d\n",temp->data);
	free(temp);
    }
}

void search(int info){
    q = start;
    while(q != NULL){
	if( q->data == info){
	printf("%d is present\n",q->data);
	return;
	}
	q=q->next;
    }
    printf("%d not found",info);
}


void deleteData(int info){
    if(start == NULL){
	printf("The List is empty.\n");
	return;
    }else{
	q=start;
	while(q->next->data!=info){
	    q = q->next;
	}
	temp = q->next;
	q->next = temp->next;
	free(temp);
    }
}


void searchAndDelete()
{   int no;
    printf("Enter node to be deleted: ");
    scanf("%d",&no);
    q=start;
    while(q->next->data!=no)
	{
	q=q->next;
	}
	temp = q->next;
	q->next = temp->next;
	printf("%d is deleted",temp->data);
	free(temp);
}

void main() {
    int n,choice;
    do{
	printf("\n\n****Main Menu****\n");
	printf("\nChoose one option from the following list ...\n");
	printf("\n===============================================\n");
	printf("\n1.Insert in begining\n2.Insert at last\n3.Insert before\n4.Insert at any random location\n5.Delete from Beginning\n6.Delete from last\n7.Delete node after specified location\n8.Search\n9.SearchandDelete\n10.Add after and Display\n11.Exit");
	printf("\nEnter Choice: ");
	scanf("%d", &choice);

	switch (choice){
		case 1:
		printf("Enter data: ");
		scanf("%d",&n);
		addAtFront(n);
		display();
		break;

		case 2:
		printf("Enter data: ");
		scanf("%d", &n);
		addAtLast(n);
		display();
		break;

		case 3:
		printf("Enter data of node to be added: ");
		scanf("%d",&n);
		addbefore(n);
		display();
		break;

		case 4:
		printf("Enter data : ");
		scanf("%d",&n);
		addPosition(n);
		display();
		break;

		case 5:
		deleteAtFront();
		display();
		break;

		case 6:
		deleteAtLast();
		display();
		break;

		case 7:
		deletePosition();
		display();
		break;

		case 8:
		printf("Enter data to search: ");
		scanf("%d",&n);
		search(n);
		break;

		case 9:
		searchAndDelete();
		display();
		break;

		case 10:
	printf("Enter data of node to be added: ");
		scanf("%d",&n);

		addafter(n);
		display();
		break;

		case 11:
		exit(0);
		break;

		default:
		printf("\nEnter a valid input");
		break;
	}
    }while(choice!=11);
}