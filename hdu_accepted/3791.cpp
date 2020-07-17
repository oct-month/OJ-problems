#include<iostream>
using namespace std;
struct Tree
{
    char data;
    Tree *lchild;
    Tree *rchild;
};
Tree *head;
void insert(char a,Tree *&p)
{
    if(p==NULL)
    {
        p=new Tree;
        p->data=a;
        p->lchild=NULL;
        p->rchild=NULL;
    }
    else if(a<p->data)insert(a,p->lchild);
    else insert(a,p->rchild);
}
void clear(Tree *T)
{
    if(T)
    {
        clear(T->lchild);
        clear(T->rchild);
        delete T;
    }
}
int find(Tree *T,Tree *R,bool &flag)
{
    if(T&&R)
    {
        if(T->data!=R->data){flag=false;return 0;}
        if(flag)find(T->lchild,R->lchild,flag);
        if(flag)find(T->rchild,R->rchild,flag);
    }
    else if(T||R)
    {
        flag=false;
        return 0;
    }
    return 1;
}
int main()
{
    int n;
    char e[10];
    bool flag;
    while(cin>>n&&n)
    {
        head=new Tree;
        e[0]=getchar();
        gets(e);
        *head={e[0],NULL,NULL};
        for(int i=1;e[i]!='\0';i++)
        {
            if(e[i]<head->data)insert(e[i],head->lchild);
            else insert(e[i],head->rchild);
        }
        while(n--)
        {
            flag=true;
            gets(e);
            Tree *tap=new Tree;
            *tap={e[0],NULL,NULL};
            for(int i=1;e[i]!='\0';i++)
            {
                if(e[i]<head->data)insert(e[i],tap->lchild);
                else insert(e[i],tap->rchild);
            }
            find(head,tap,flag);
            clear(tap);
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        clear(head);
    }
    return 0;
}