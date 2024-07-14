#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node
{
 int vertex;
 struct node *next;
}node;
typedef struct Q
{
 int data[MAX];
 int R,F;
}Q;
void enqueue(Q *,int);
int dequeue(Q *);
int empty(Q *);
int full(Q *);
void readgraph();
void insert(int,int);
void DFS(int);
void BFS(int);
node *G[20];
int n,visited[20];
void readgraph()
{
 int i,vi,vj,edges;
//  clrscr();
 printf("\n Enter number of vertices: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  G[i]=NULL;
  printf("\n Enter number of edges: ");
  scanf("%d",&edges);
  for(i=0;i<edges;i++)
  {
   printf("\n Enter an edge(u,v): ");
   scanf("%d %d",&vi,&vj);
   insert(vi,vj);
  } }}
void insert(int vi,int vj)
{
 node *p,*q;
 q=(node*)malloc(sizeof(node));
 q->vertex=vj;
 q->next=NULL;
 if(G[vi]==NULL)
  G[vi]=q;
 else

 {
  p=G[vi];
  while(p->next!=NULL)
   p=p->next;
  p->next=q;
 } }
void main()
{
     int i,op;
    //  clrscr();
     do
     {
 printf("\n 1) Create  2) BFS  3) DFS 4) Quit\n");
 scanf("%d",&op);
 switch(op)
 {
  case 1: readgraph(); break;
  case 2: printf("\n Enter starting node number: ");
   scanf("%d",&i);
   BFS(i);break;
  case 3:for(i=0;i<n;i++)
    visited[i]=0;
   printf("\n Enter starting node number: ");
   scanf("%d",&i);
   DFS(i);break;

 }      }while(op!=4);
// getch();
}
void DFS(int i)
{
 node *p;
 printf("\n %d",i);
 p=G[i];
 visited[i]=1;
 while(p!=NULL)
 {
  i=p->vertex;
  if(!visited[i])
   DFS(i);
  p=p->next;
 } }
void BFS(int v)
{
 int i,w,visited[MAX];
 Q q;
 node *p;
 q.R=q.F=-1;
 for(i=0;i<n;i++)
  visited[i]=0;
 enqueue(&q,v);
 printf("\nVisit\t%d",v);
 visited[v]=1;
 while(!empty(&q))
 {
  v=dequeue(&q);
  for(p=G[v];p!=NULL;p=p->next)
  {
   w=p->vertex;
   if(visited[w]==0)
   {
    enqueue(&q,w);
    visited[w]=1;
    printf("\nVisit\t%d",w);
   } 
  }  }       }
int empty(Q *p)
{
 if(p->R==-1)
  return(1);
 return(0);
}
int full(Q *p)
{
 if(p->R==MAX-1)
  return(1);
 return(0);
}
void enqueue(Q *p,int x)
{
 if(p->R==-1)
 {
  p->R=p->F=0;
  p->data[p->R]=x;
 }
 else
 {
  p->R=p->R+1;
  p->data[p->R]=x;
 } }
int dequeue(Q *p)
{
 int x;
 x=p->data[p->F];
 if(p->R==p->F)
 {
  p->R=-1;
  p->F=-1;
 }
 else
  p->F=p->F+1;
 return(x);
}




