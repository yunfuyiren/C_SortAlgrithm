#include<stdio.h>
//冒泡排序：每次交换选出最大值放在最后
void BubbleSort(int A[],int len)
{
    int i,j,temp;
   for(i=len-1;i>0;i--) 
       for(j=0;j<i;j++)
       {
           if(A[j]>A[j+1])
           {
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
           }
       }
}
void main()
{
    int A[]={6,5,3,7,4,2,9,8,1,0};
    int len=sizeof(A)/4;
    BubbleSort(A,len);
    int i=0;
    for(;i<len;i++)
    {
        printf("%d,",A[i]);
    }

}
