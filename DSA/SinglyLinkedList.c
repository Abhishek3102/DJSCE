#include<stdlib.h>
#include <stdio.h>
     
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
// void delete_begin();
void delete_end();
// void delete_pos();
 
 
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf(" MENU\n");
                printf("1.Create\n");
                printf("2.Display\n");
                printf("3.Insert at the beginning\n");
                printf("4.Insert at the end  \n");
                printf("5.Insert at specified position\n");
                printf("6.Delete from beginning\n");
                printf("7.Delete from the end\n");
                printf("8.Delete from specified position\n");
                printf("9.Exit\n");
              
                printf("Enter your choice:\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        display();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        display();
                                        break;
                        case 4:
                                        insert_end();
                                        display();
                                        break;
                        case 5:
                                        insert_pos();
                                        display();
                                        break;
                        case 6:
                                        // delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        display();
                                        break;
                        case 8:
                                        // delete_pos();
                                        break;
                        
                        case 9:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*q;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:\n");
                exit(0);
        }
        printf("Enter the data value for the node:\n");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                q=start;
                while(q->next!=NULL)
                {
                        q=q->next;
                }
                q->next=temp;
        }
}
void display()
{
        struct node *q;
        if(start==NULL)
        {
                printf("List is empty:\n");
                return;
        }
        else
        {
                q=start;
                printf("The List elements are:\n");
                while(q!=NULL)
                {
                        printf("%d\t",q->info );
                        q=q->next ;
                }
                printf("\n");
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the data value for the node:\n" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*q;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the data value for the node:\n" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                q=start;
                while(q->next !=NULL)
                {
                        q=q->next ;
                }
                q->next =temp;
        }
}
void insert_pos()
{
        struct node *q,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:\n");
                return;
        }
        printf("Enter the position for the new node to be inserted:\n");
        scanf("%d",&pos);
        printf("Enter the data value of the node:\n");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,q=start;i<pos-1;i++) { 
                        q=q->next;
                        if(q==NULL)
                        {
                                printf("Position not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =q->next ;
                q->next=temp;
        }
}
void delete_begin()
{
        struct node *q;
        if(q==NULL)
        {
                printf("List is Empty:\n");
                return;
        }
        else
        {
                q=start;
                start=start->next ;
                printf("The deleted element is :%d\t",q->info);
                free(q);
        }
}
void delete_end()
{
        struct node *temp,*q;
        if(start==NULL)
        {
                printf("List is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                q=start;
                start=NULL;
                printf("The deleted element is:%d\n",q->info);
                free(q);
        }
        else
        {
                q=start;
                while(q->next!=NULL)
                {
                        temp=q;
                        q=q->next;
                }
                temp->next=NULL;
                printf("The deleted element is:%d\n",q->info);
                free(q);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*q;
        if(start==NULL)
        {
                printf("The List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("Enter the position of the node to be deleted:\n");
                scanf("%d",&pos);
                if(pos==0)
                {
                        q=start;
                        start=start->next ;
                        printf("The deleted element is:%d\n",q->info  );
                        free(q);
                }
                else
                {
                        q=start;
                        for(i=0;i<pos;i++) { temp=q; q=q->next ;
                                if(q==NULL)
                                {
                                        printf("Position not Found:\n");
                                        return;
                                }
                        }
                        temp->next =q->next ;
                        printf("The deleted element is:%d\t",q->info );
                        free(q);
                }
        }
}