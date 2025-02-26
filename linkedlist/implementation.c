#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node* next;
};
 int main(){
  int count=0;
  struct node* head,*newnode,*temp;
  head=0;
  temp=0;
  int choice;
  while(choice)
  {
    newnode=(struct node*) malloc(sizeof(struct node));
   printf("Enter the data:\n");
   scanf("%d",&newnode->data);
   newnode->next=0;
   if(head==0)
   {
    head=temp=newnode;
   }
   else{
    temp->next=newnode;
    temp=newnode;
   }
   printf("Do you want to continue(0,1)?:");
   scanf("%d",&choice);
   count++;
  }
  temp=head;
  while(temp!=0)
  {
    printf("\t%d",temp->data);
    temp=temp->next;
  }
  printf("\nThe number of nodes is:%d",count);
  return 0;
 }