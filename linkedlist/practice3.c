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

    if(head==NULL){
      printf("The list is empty.");
    }
    printf("the list data are :\n");

    do{
      printf("%d\t",temp->data);
      temp=temp->next;
    }  while(temp!=head);
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
         do{
          count++;
          temp=temp->next;
         }while(temp!=head);
      }

      printf("The number of nodes are :%d\n",count);;
  
    }
void insertbeg() {
    struct node* newnode = createnode();
    if (head == NULL) {
        // Empty list: newnode points to itself
        head = newnode;
        head->next = head;
    } else {
        struct node* temp = head;
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode; // Update head to newnode
    }
}

    
     void insertpos(){
          int pos ,i=1;
      printf("Enter the position:\n");
      scanf("%d",&pos);

      struct node* newnode=createnode();
      if(pos==1){
        insertbeg();
        return;
      }
      else{
    struct node* temp=head;


        while(i<pos-1 && temp->next!=head){
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
        if(head==NULL){
        head=newnode;
        newnode->next=head;
        }
        else{
          while(temp->next!=head){
            temp=temp->next;
          }
          temp->next=newnode;
          newnode->next=head;
        }
       }

    void deletefirst(){
      struct node* temp= head;
      if(temp->next==head){
        free(temp);
        temp=NULL;
      }

      else{
        struct node* last=head;
        while(last->next!=head){
          last=last->next;
        }
        head=head->next;
        last->next=head;
        free(temp);
        temp=NULL;
      }
    }
           
    void deletelast(){
      struct  node*temp=head;
      if(temp->next==head)
      {
        free(head);
        head=NULL;
        return;
      }
      else{

    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;

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

    int main()
    {
      struct node*temp=NULL;
      int choice=1;

      while(choice){
        struct node*newnode=createnode();
         if(head==NULL){
          head=temp=newnode;
          newnode->next=head;
         }

         else{
          temp->next=newnode;
          newnode->next=head;
          temp=newnode;
         }
      printf("do you want to continue\n");
      scanf("%d",&choice);
      }

     printlist();
     count();
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