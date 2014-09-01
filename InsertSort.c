#include<stdio.h>
void InsertSort(int A[],int len)
{
    int i,j,temp;
    for(i=1;i<len;i++)
    {
        temp=A[i];
        for(j=i-1;j>=0&&temp<A[j];j--)
                A[j+1]=A[j];
        A[j+1]=temp;
    }
}
void main()
{
    int A[]={6,5,3,7,4,2,9,8,1,0};
    int len=sizeof(A)/4;
    InsertSort(A,len);
    int i=0;
    for(;i<len;i++)
    {
        printf("%d,",A[i]);
    }
}
