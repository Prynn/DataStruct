#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化链表；
LinkList InitList() //如果形参为LinkList的指针，只定义指针而不赋空间则出错；
{
    LinkList Li;
    Li = (LinkList)calloc(1,sizeof(LinkList));
    Li->next = NULL;
    return Li;
}
//前插法构建单向链表；
LinkList CreateList(int n)
{
    int i;
    LinkList p,L;
    /*L = (LinkList)calloc(1,sizeof(LinkList));
    L->next = NULL;*/
    L = InitList();
    for(i=0;i<n;i++)
    {
        p = (LinkList)calloc(1,sizeof(LinkList));
        printf("Please input a new node: ");
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
    return L;
}
//增加结点（无序）
void AddNode_List(LinkList L,ElemType n)
{
    LinkList p;
    p = (LinkList)calloc(1,sizeof(LNode));
    p->data = n;
    p->next = L->next;
    L->next = p;
}
//遍历链表；
void ShowList(LinkList L)
{
    LinkList p = L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

//原地反转，另设节点指针，前插法重置链表
void Inverse_LinkList(LinkList L)
{
    LinkList p,r;
    p = L->next->next;
    L->next->next = NULL;
    while(p)
    {
        r = p -> next; //核心，另设变量指向下一个节点
        p->next = L->next;
        L->next = p;
        p = r;
    }
}
//删除指定结点；
void Delete_Node(LinkList L,int n)
{
    LinkList q,p;
    p = L;
    int i = 0;
    while((i<n-1)&&(p->next!=NULL))
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;

}
//删除偶数元素结点；
void Delete_EvenNode(LinkList L,int n)
{
    LinkList p;
    int i = 1,j=0;
    p = L->next;
    while(p!=NULL&&i<=n)  //不能只以p!=NULL为结束标志；不能把赌注放在野指针上。
    {
        if((p->data)%2==0)
            {
                Delete_Node(L,i-j);
                j++;
            }
        p = p->next;
        i++;
    }
}

//建立升序有序单向链表；
LinkList Create_UpOrderList(int n)
{
    LinkList L,p,r;
    int i;
    ElemType m;
    L = InitList();
    for(i=0;i<n;i++)
    {
        p = L;
        printf("Please input a new node: ");
        scanf("%d",&m);
        r = (LinkList)calloc(1,sizeof(LNode));
        r->data = m;
        while((p->next!=NULL) && (m > p->next->data))
        {
            p = p->next;
        }
        r->next = p->next;
        p->next = r;
    }
    return L;
}
//增加升序单链表结点
void AddNode_UpOrderList(LinkList L,ElemType n)
{
    LinkList p,r;
    p = L;
    r = (LinkList)calloc(1,sizeof(LNode));
    r->data = n;
    while((p->next!=NULL) && (n > p->next->data))
    {
        p = p->next;
    }
    r->next = p->next;
    p->next = r;
}

//建立降序单链表；
LinkList Create_DownOrderList(int n)
{
    LinkList L,p,r;
    int i;
    ElemType m;
    L = InitList();
    for(i=0;i<n;i++)
    {
        p = L;
        printf("Please input a new node: ");
        scanf("%d",&m);
        r = (LinkList)calloc(1,sizeof(LNode));
        r->data = m;
        while((p->next!=NULL) && (m < p->next->data))
        {
            p = p->next;
        }
        r->next = p->next;
        p->next = r;
    }
    return L;
}
//增加降序单链表结点
void AddNode_DownOrderList(LinkList L,ElemType n)
{
    LinkList p,r;
    p = L;
    r = (LinkList)calloc(1,sizeof(LNode));
    r->data = n;
    while((p->next!=NULL) && (n < p->next->data))
    {
        p = p->next;
    }
    r->next = p->next;
    p->next = r;
}
//分割偶数链表
void Divide_EvenNode(LinkList L,LinkList evenList,int n)
{
    int i = 1,j=0;
    LinkList p;
    p = L->next;
    while(p!=NULL&&i<=n)
    {
        if(p->data%2==0)
            {
                AddNode_List(evenList,p->data);
                Delete_Node(L,i-j);
                j++;
            }
        p = p->next;
        i++;
    }
}
int main()
{}
