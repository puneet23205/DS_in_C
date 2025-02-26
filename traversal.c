#include<stdio.h>
int main()
{
  int a[100],i,size;
  printf("Enter the size of the array:\n");
  scanf("%d",&size);
   
   printf("Enter the elements of the array:");
   for(i=0;i<size;i++)
   {
    scanf("%d",&a[i]);
   }
     printf("The elements of the array are:");
   for(i=0;i<size;i++)
   {
    printf("\t%d",a[i]);
    
   }
   return 0;
}