#include<stdio.h>
#include<stdlib.h>

struct node* head =NULL;

struct node{
  int data;
  struct node * next;
};

struct node* createnode()
{
  struct node* newnode = (struct node*) malloc (sizeof(struct node ));

  if(newnode==NULL){
    printf("memory allocation failed.");
  }
  else{
    printf("Enter the data:\n");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
  }
  return newnode;

  }
   void printlist(){
    struct node*temp=head;
    printf("the list data are :\n");

    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->next;
    }
    printf("\n");
    }

    int count(){
      int count=0;
      struct node*temp=head;
      if(head==NULL)
      {
        printf("list is empty");
      }
      else{
         while(temp!=NULL){
          count++;
          temp=temp->next;
         }
      }

      printf("The number of nodes are :%d\n",count);;
  
    }

    void insertbeg(){

    struct node* newnode=createnode();
    newnode->next=head;
    head=newnode;
    }
    
     void insertpos(){
          int pos ,i=1;
      printf("Enter the position:\n");
      scanf("%d",&pos);

      struct node* newnode=createnode();
      if(pos==1){
        insertbeg();
      }
      else{
    struct node* temp=head;

        if(temp->next==NULL){
          printf("invalid position");
        }

        while(i<pos-1 && temp->next!=NULL){
          temp=temp->next;
          i++;
        }

       newnode->next=temp->next;
       temp->next=newnode;

      }

      }

       void insertlast(){
        struct node* newnode=createnode();
        struct node* temp=head;
        if(head->next==NULL){
          temp->next=newnode;
          temp=newnode;
        }
        else{
          while(temp->next!=NULL){
            temp=temp->next;
          }
          temp->next=newnode;
          temp=newnode;
        }
       }

    void deletefirst(){
      struct node* temp= head;
      if(head->next==NULL){
        free(temp);
        temp=NULL;
      }

      else{
        head=head->next;
        free(temp);
        temp=NULL;
      }
    }
           
    void deletelast(){
      if(head->next==NULL)
      {
        free(head);
        head=NULL;
        return;
      }
      else{
         struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

          }
    }

    void deletepos(){
      
      int pos,i=1;
      printf("Enter the position:\n");
      scanf("%d",&pos);

      if(head==NULL){
        printf("the list is empty");
      }

      if(pos==1){
        deletefirst();
      }
      struct node* temp=head;
      struct node* prev;
      while(i<pos && temp->next!=NULL){
       prev=temp;
       temp=temp->next;
       i++;
      }
     prev->next=temp->next;
     free(temp);
     temp=NULL;
    }

   void reverselist(){
    struct node*current=head;
    struct node* prev=NULL;
    struct node* nextnode=NULL;

    while(current!=NULL){
      nextnode= current->next;
      current->next=prev;
      prev=current;
      current=nextnode;
    }
    head=prev;
   }

    int main()
    {
      struct node*temp=NULL;
      int choice=1;

      while(choice){
        struct node*newnode=createnode();
         if(head==NULL){
          head=temp=newnode;
         }

         else{
          temp->next=newnode;
          temp=newnode;
         }
      printf("do you want to continue\n");
      scanf("%d",&choice);
      }

     printlist();
     count();
     reverselist();
     printlist();
     insertbeg();
     printlist();
     insertpos();
     printlist();
     insertlast();
     printlist();
     deletelast();
      printlist();
      deletefirst();
      printlist();
      deletepos();
      printlist();
     return 0;
    }
   