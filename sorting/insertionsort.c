#include<stdio.h>

int main()
{
    int i,j,temp,key;
    int n;
  int a[6];
  printf("Enter the number of elements to be sorted:\n");
  scanf("%d",&n);

  printf("Enter the elements to be sorted:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

for(i=1;i<n;i++)
{
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key)
           {
            a[j+1]=a[j];
            j=j-1;
           }
        a[j+1]=key;
}
printf("The sorted array is :");
for(i=0;i<n;i++)
{
    printf("%d ",a[i]);
}
return 0;
}