#include<stdio.h>
#define N 5
int queue[5];
 int front=-1;
 int rear=-1;

void enqueue()
{
  int x;
  printf("Enter data:\n");
  scanf("%d",&x);

  if(rear==N-1)
  {
    printf("Overflow");

  }
  else if(front==-1 && rear==-1)
  {
    front=rear=0;
    queue[rear]=x;
  }
  else{
    rear++;
    queue[rear]=x;
  }
}

void dequeue()
{
  if(front==-1&&rear==-1)
  {
    printf("The queue is empty");
  }
  else if(front==rear){
 front=rear=-1;
  }
  else{
    printf("The deleted element is %d",queue[front]);
    front++;
  }
}
void display()
{
  if(front==-1&&rear==-1)
  {
    printf("The queue is empty");

  }
  else{
    for( int i=front;i<rear+1;i++)
    {
      printf("%d",queue[i]);
    }
  }
}
void peek()
{
  if(front==-1&&rear==-1)
  {
    printf("The queue is empty");

  }
  else{
    printf("The data at front is %d",queue[front]);
  }
}




int main() {
    int ch;
    do {
        printf("\nEnter choice: \n1: enqueue\n2: dequeue\n3: Peek\n4: Display\n0: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 0);

    return 0;
}
