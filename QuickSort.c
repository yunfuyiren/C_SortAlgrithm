#include<stdio.h>
#include<stdlib.h>

void QuickSort(int A[],int start,int end)
{
    if(start>=end)
        return;
    int p=Partition(A,start,end);
    QuickSort(A,start,p-1);
    QuickSort(A,p+1,end);
}
//返回某个位置，该位置前的元素都小于该值，该位置后的元素都大于该值
int Partition(int A[],int start,int end)
{
    int pos=rand()%(end-start+1)+start;
    int temp;
    temp=A[start];
    A[start]=A[pos];
    A[pos]=temp;
    int p=start;
    int i;
    for(i=start+1;i<=end;i++)
    {
        if(A[i]<A[start])
        {
            temp=A[++p];
            A[p]=A[i];
            A[i]=temp;
        }
    }
    temp=A[p];
    A[p]=A[start];
    A[start]=temp;
    return p;
}
void main()
{
    srand((int)time(NULL));
    int A[]={6,3,4,2,1,5,8,7,9,0};
    int len=sizeof(A)/4;
    QuickSort(A,0,len-1);
    int i;
    for(i=0;i<len;i++)
        printf("%d,",A[i]);
}
