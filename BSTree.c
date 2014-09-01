#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
//二分查找树排序
typedef struct TElemType{
    int key;
    char c[10];
}TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

bool CreateBiTree(BiTree T){
    int key;
    char c[10];
    scanf("%d",&key);
    scanf("%s",&c);
    TElemType e;
    if(key==-1)
        T=NULL;
    else{
        if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))
            exit(0);
        T->data.key=key;
        strcpy(T->data.c,c);
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 1;
}

bool InitBiTree(BiTree* T){
    *T=NULL;
    return 1;
}

bool SearchBSTree(BiTree T,int key,BiTree f,BiTree* p){
    if(!T){
        *p=f;
        return 0;
    }
    if(T->data.key==key){
        *p=T;
        return 1;}
    if(T->data.key<key){return SearchBSTree(T->rchild,key,T,p);}
    else{
        return SearchBSTree(T->lchild,key,T,p);
    }
}
    
bool InsertBSTree(BiTree* T,TElemType e)
{
    BiTNode*p;
    BiTNode*s;
    if(!SearchBSTree(*T,e.key,NULL,&p))
    {
        s=(BiTNode*)malloc(sizeof(BiTNode));
        memcpy(&s->data,&e,sizeof(TElemType));
        s->lchild=NULL;
        s->rchild=NULL;
        if(!p){
           *T=s; 
        }else if(e.key>p->data.key){
            p->rchild=s;
        }else
            p->lchild=s;
        return 1;
    }
    return 0;
}

bool DeleteBST(BiTree* T,int key){
    if(!(*T))
        return 0;
    else{
        if(key==(*T)->data.key){
            return Delete(T);
        }else if(key<(*T)->data.key)
            return DeleteBST(&((*T)->lchild),key);
        else
            return DeleteBST(&((*T)->rchild),key);
    }
}
bool Delete(BiTree* p)
{
    BiTNode* q;
    if(!(*p)->lchild&&!(*p)->rchild)
    {
        q=*p;
        *p=NULL;
        free(q);
    }
    else if(!(*p)->rchild){
        q=*p;
        *p=(*p)->lchild;
        memcpy(&q->data,&(*p)->data,sizeof(TElemType));
        q->lchild=(*p)->lchild;
        free(*p);
        *p=q;
    }else if(!(*p)->lchild){
        q=*p;
        *p=(*p)->rchild;
        memcpy(&q->data,&(*p)->data,sizeof(TElemType));
        q->rchild=(*p)->rchild;
        free(*p);
        *p=q;
    }else{
        BiTNode*s;
        q=*p;
        s=(*p)->lchild;
        while(s->rchild!=NULL){
            q=s;s=s->rchild;
        }
        memcpy(&(*p)->data,&s->data,sizeof(TElemType));
        if(q!=*p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
        free(s);
    }
    return 1;
}
void PreOrderTraverse(BiTree T)
{
    if(!T)
        printf("@,");
    else{
        printf("%d,",T->data.key);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
int main(){
    int n;
    BiTree bTree;
    InitBiTree(&bTree);
    printf("begin!\n");
    scanf("%d",&n);
    while(n>0){
        TElemType e;
        n--;
        scanf("%d",&e.key);
        scanf("%s",&e.c);
        InsertBSTree(&bTree,e);
    }
    PreOrderTraverse(bTree);
    TElemType t;
    t.key=1;
    strcpy(t.c,"aa");
    printf("\n");
    DeleteBST(&bTree,t.key);
    PreOrderTraverse(bTree);
    return 1;
}
