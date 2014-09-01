#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//归并排序
//合并已排序的两个数组
void Merge(int A[],int B[],int p,int r,int q)
{
    int i=p,j=r+1,k=i;
    while(i<=r&&j<=q)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    while(i<=r)
        B[k++]=A[i++];
    while(j<=q)
        B[k++]=A[j++];
    memcpy((A+p),(B+p),sizeof(int)*(q-p+1));
}
//非递归方法
void BottomUpSort_Iterator(int A[],int B[],int len)
{
    int t=1;
    int s,i;
    while(t<len)
    {
        s=t,t=2*s,i=-1;
        while(i+t<len)
        {
           Merge(A,B,i+1,i+s,i+t);
           i=i+t;
        }
        if(len-1-i>s)  //剩余元素多余上一轮的一个自序列，
            Merge(A,B,i+1,i+s,len-1);
        printf("%d\n",t);
    }
}
void main()
{
    int A[]={5,3,2,7,6,1,8,4,0,9};
    int len=sizeof(A)/4;
    int B[len];
    //B=(int*)malloc(sizeof(int)*len);
    BottomUpSort_Iterator(A,B,len);
    int i=0;
    for(;i<len;i++)
    {
        printf("%d,",A[i]);
    }
}
