线性结构 包括：线性表、栈、队列、串、数组。
线性结构 基本特点：除第一个元素无直接前驱，最后一个元素无直接后继之外，其他每个数据元素都有一个直接前驱、直接后继。
线性表 包括：顺序表、链表。
线性表 定义：由n个 数据特性 相同的元素构成的有限序列。

顺序表：
#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
}SqList;

//初始化顺序表
int InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE];//为顺序表分配一个大小为maxsize的数组空间；
    if(!L.elem)
        return 0;
    L.length = 0;//初始化顺序表长度；
    return 1;

}

//顺序表插入
int ListInsert(SqList &L,int i,ElemType e)
{
    if(i<1 || (i>L.length+1))
        return 0;   //千万不能忘记判断是否合理
    if(L.length == MAXSIZE)
        return 0;
    int j;
    for(j=L.length;j>=i;j--)
    {
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i-1] = e;  //数组序号和顺序表元素序号不同；
    L.length++; //长度不能忘；
    return 1;
}

//顺序表取值
int GetElem(SqList L,int i,ElemType &e)
{
    if(i<1 || i>L.length)
        return 0;   //千万不能忘记判断是否合理
    else
        e = L.elem[i-1];
    return 1;   //把返回值都留给状态量
}

//顺序表删除
int ListDelete(SqList &L,int i,ElemType &e)
{
    if(i<1 || i>L.length)
        return 0;
    int j;
    GetElem(L,i,e);  //有返回删除的值；
    for(j=i-1;j<L.length-1;j++)
    {
        L.elem[j]=L.elem[j+1];
    }
    L.length--;
    return 1;
}

//顺序表查找
int LocateElem(SqList L,ElemType e)
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i] == e)
            return i+1;
    return 0;
}

//顺序表输出
void  ShowElem(SqList L)
{
    int i;
    if(L.length==0)
        cout<<"null"<<endl;
    for(i=0;i<L.length;i++)
        cout<<L.elem[i]<<" ";
    cout<<endl;

}

int main()
{
    SqList list;
    InitList(list);
    ListInsert(list,1,1);
    ListInsert(list,1,2);
    ListInsert(list,1,3);
    ListInsert(list,1,4);
    ListInsert(list,1,5);
    ShowElem(list);
    return 0;
}
