#include<stdio.h>
#include<stdlib.h>
//ϣ������
//dk��ʾǰ���¼λ�õ�������dk��������1
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

//��һ�������Ǵ��������飬�ڶ��������Ǽ�¼��������������������������
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
