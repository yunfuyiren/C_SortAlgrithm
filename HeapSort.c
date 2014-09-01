#include<stdio.h>
#include<stdlib.h>
#define Parent(i) i>>1  //  求父节点编号
#define Left(i) i<<1
#define Right(i) (i<<1)+1
//堆排序
//最大堆的调整,i节点的左右子树都是最大堆，i节点加入后可能小于叶子节点
void MaxHeapify(int A[],int len,int i)
{
    int left=Left(i),right=Right(i);
    int largest=-1;
    if(left<len&&A[left]>A[i])
        largest=left;
    else
        largest=i;
    if(right<len&&A[right]>A[largest])
        largest=right;
    if(largest!=i)
    {
        A[i]=A[largest]+A[i];
        A[largest]=A[i]-A[largest];
        A[i]=A[i]-A[largest];
        MaxHeapify(A,len,largest);
    }
}
//自底向上地用MaxHeapify将一个数组A[1..n](此处n=length[A])变成一个最大堆
//子数组A[(n/2)+1]中的元素都是树中叶子节点，每个看作只有一个元素的堆
void BuildMaxHeap(int A[],int len)
{
    int i=(len-1)/2;
    for(;i>=0;i--)
    {
        printf("while1\n");
        MaxHeapify(A,len,i);
    }
}
//堆排序算法：先建立大顶堆，然后将最大元素放到最后，对1~len-1元素调用MaxHeapify调整
void HeapSort(int A[],int len)
{
    BuildMaxHeap(A,len);
    int i=len-1;
    int temp;
    for(;i>=1;i--)
    {
        printf("while2\n");
        temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        len--;
        MaxHeapify(A,len,0);
    }
}
void main(){
    int A[10]={5,4,6,2,7,1,3,8,9,0};
    int len=sizeof(A)/4;
    printf("len=%d ",len);
    HeapSort(A,len);
    int i;
    for(i=0;i<len;i++)
        printf("%d ,",A[i]);
}
