#include<stdio.h>
#include<stdlib.h>
//希尔排序
//dk表示前后记录位置的增量是dk，而不是1
void ShellInsert(int a[],int dk)
{
    int elem;
    int i,j;
    int len=(int)sizeof(a)/4;
    printf("len= %d,",len);
    for(i=dk;i<len;i++){
        if(a[i]>a[i-dk]){
            elem=a[i];
            for(j=i-dk;j>=0&&elem>a[j];j-=dk)
                a[j+dk]=a[j];
            a[j+dk]=elem;
        }
    }
}

//第一个参数是待排序数组，第二个参数是记录增量，第三个参数是排序趟数
void ShellSort(int a[],int dlta[],int t)
{
    int i=0,j;
    for(i=0;i<t;i++)
    {
        ShellInsert(a,dlta[i]);
        for(j=0;j<10;j++)
            printf("%d,",a[j]);
        printf("\n");
    }
}
void main()
{
	int a[10]={2,3,4,1,6,5,9,8,7,0};
    int deta[3]={5,3,1};
    int t=3;
    ShellSort(a,deta,t);
    arraylen(a);
    int i=0;
    for(i=0;i<10;i++)
        printf("%d,",a[i]);
}
