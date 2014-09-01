#include<stdio.h>
//选择排序
void SelectionSort(int A[],int len)
{
   int i,j;
   for(i=0;i<len-1;i++)
   {
       int min=i;
       for(j=i+1;j<len;j++)
       {
          if(A[min]>A[j])
              min=j;
       }
       int temp;
       temp= A[i];
       A[i]=A[min];
       A[min]=temp;
   }
}
void main()
{
    int A[]={6,5,3,7,4,2,9,8,1,0};
    int len=sizeof(A)/4;
    SelectionSort(A,len);
    int i=0;
    for(;i<len;i++)
    {
        printf("%d,",A[i]);
    }
}
