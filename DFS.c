/* **node must be contain  Zero(0)**.
eg. 0 1
 1 4
 3 5
 9 4
 0 5*/#include <stdio.h>
#include<stdlib.h>
#define n 6
int stack[n];
int top=-1;
int visited[n];
int a[n][n];
void DFS();
int pop();

void push(int v);

int IsEmpty();
void create_empty();
void print();
void add_edge(int s,int dest);
int main()
{
int s,dest;
    int p,i;
    create_empty();
    printf("\nplease enter number of the pairs of source and destination vertices\n");
    scanf("%d",&p);
     for(i=0;i<p;i++)
       { 
        scanf("%d %d",&s,&dest);  
         add_edge(s,dest);
       }
       print();
       printf("DFS traversal is :\n");
       DFS();
       return 0;
}
void push(int v)
{
  if(top==(n-1))
  {
    printf("\n stack is full");
    exit(1);
  }
  else
  {
   
    stack[++top]=v;
  }
}
void DFS()
{
  int v,u;
    for(v=0; v<n; v++)
      visited[v]=0;
  
     printf("enter the starting vertex:\n");
    scanf("%d",&v);
    push(v);
    visited[v]=1;
    while(!IsEmpty())
    {   u=pop();
        
        printf("%d",u);
       
        for(v=0;v<n;v++)
       {
         if(visited[v]==0 && a[u][v]==1)
         {
           push(v);
           
           visited[v]=1;
         }
       }


    }
     
 

}

int pop()
{
  if(top==-1)
  {
    printf("\nstack is Empty");
    exit(1);
  }
  else
  {
    int b;
    b=stack[top--];
    
    return b;
  
  }
}

int IsEmpty()
{
   if(top==-1)
  return 1;
  else
  return 0;
   
}






void create_empty()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
}
void add_edge(int s,int dest)
{  
     
    a[s][dest]=1;
    
        
 }
 void print()
 {
     int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");
    } 
 }


 

