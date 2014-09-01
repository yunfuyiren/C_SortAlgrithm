#include<stdio.h>
#include<string.h>
//计数排序：A数组为排序数组，k表示A中元素的范围为0<= <k
void CountingSort(int A[],int R[],int len,int k)
{
    int B[k];
    memset(B,0,sizeof(int)*k);
    int i=0;
    for(;i<len;i++)
    {
        B[A[i]]++;
    }
    for(i=1;i<k;i++)
    {
        B[i]+=B[i-1];
    }
    for(i=len-1;i>=0;--i)
    {
        R[B[A[i]]-1]=A[i];
        B[A[i]]--;
    }
}
void main(){
    int A[]={3,3,2,0,1,1,0,3,2,1};
    int len=sizeof(A)/4;
    int B[len];
    CountingSort(A,B,len,4);
    int i=0;
    //printf("len=%d,",len);
    for(;i<len;i++)
    {
        printf("%d,",B[i]);
    }
}
