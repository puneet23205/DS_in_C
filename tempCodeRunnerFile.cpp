#include<stdio.h>

int main()
{
    int i,minINDEX,j,temp;
    int n;
  int a[50];

printf("Enter the number of elements to be sorted:\n");
scanf("%d",&n);

printf("Enter the elements to be sorted :\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
 minINDEX=i;
    for(j=i+1;j<n;j++)
    {
       
        if(a[minINDEX]>a[j])
        {
            temp=a[minINDEX];
            a[minINDEX]=a[j];
            a[j]=temp;
        }

    }
}
printf("The sorted array is :");
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
return 0;
}