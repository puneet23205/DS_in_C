#include<stdio.h>
int main()
{
  int a[100],i,size,num,pos;
  printf("Enter the size of the array:\n");
  scanf("%d",&size);
   
   printf("Enter the elements of the array:");
   for(i=0;i<size;i++)
   {
    scanf("%d",&a[i]);
   }

   printf("Enter the position where data is to be inserted:\n");
   scanf("%d",&pos);
   if(pos<=0 || pos>=size+1)
   {
    printf("Invalid position");
    return 1;
   }
    printf("Enter the data to be inserted:\n");
   scanf("%d",&num);
    for(i=size;i>=0;i--)
    {
      a[i+1]=a[i];
    }
    //insert new value
    a[0]=num;
    size++;
     printf("The elements of the array are:");
   for(i=0;i<size;i++)
   {
    printf("\t%d",a[i]);
    
   }
   return 0;
}