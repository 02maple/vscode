#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct date{
    int a;
}Date;

typedef struct _node{
    Date number;
    struct _node *next;
}Lnode;



void MAKE_LIST(Lnode * &,int ); //创造新的链表的函数
void OUT(Lnode * &,int );   //输出链表数据的函数
void IN_LIST(Lnode * &,int );   //在建立的链表中加入数据的函数
void SER_LIST(Lnode * &,int); //寻找数据
void DEL_LIST(Lnode * &); //删除数据
void reverse(Lnode * &);//链表就地逆置


int main(){
    
    Lnode *head=nullptr;
    int n;
    cout<<"您想加入几个数据:";
    cin>>n;
    MAKE_LIST(head,n);
    
    OUT(head,n);
    int i;
    cout<<"您想在哪加入新的数据:  ";
    cin>>i;
    IN_LIST(head, i);
    ++n;
    OUT(head,n);
    SER_LIST(head,n);
    DEL_LIST(head);
    --n;
    OUT(head,n);
    reverse(head);
    OUT(head,n);

    system ("pause");
    return 0;

}





void MAKE_LIST(Lnode* &head,int n){
    Lnode *pr=nullptr;   //创造一个节点，目的是使其一直指向链表的尾部
    Lnode *p=nullptr;   //创造一个新节点，目的是使其通过尾插法加入链表

    head=new Lnode;       //为头节点创造一个空间，同时不为其赋值，其数据域实为空，只是存有地址
    head->next=nullptr;   //令头节点的指针域指向nullptr
    pr =head;             //由于链表只有一个节点，所以指向尾节点的指针和指向头节点的指针在一起
    
    p=new Lnode;          //为新加入的数据创建一个节点
    int i=0;
    cout<<"您想加入的数据是:";
    for(i=0;i<n;++i){   
        p=new Lnode;
        cin>>p->number.a;

        p->next=nullptr;
        pr->next=p;
        pr=p;
    }

}

void OUT(Lnode * &head,int n){
   
    Lnode *p=head->next;
    int i;
    while(p!=NULL){
        for(i=1;i<n+1;++i){
            cout<<" "<< i <<":"<<"  "<<p->number.a<<" \n";
            p=p->next;
        }
    }
}

void IN_LIST(Lnode * &head,int i){
    Lnode *p=head;  
    int j=0,e;
    for(j=0;j<i-1;++j){
        if(p!=nullptr){
            p=p->next;
        }
    }
    

        Lnode *s=new Lnode;
        

        cout<<"您想加入的数据是:";
        cin>>e;
        s->number.a=e;
        s->next=p->next;
        p->next=s;
  
    
}

void SER_LIST(Lnode * &head,int n){
    Lnode *p=head->next;
    int j=1,e;
    cout<<"您想寻找哪个数据:";
    cin>>e;
    while(p&&(p->number.a!=e)){
            p=p->next;
            ++j;
    }
    if(j<=n){
        cout<<"这个数据在第 "<<j<<"位 \n";
    }else {
        cout<<"数据不存在\n";
    }
}

void DEL_LIST(Lnode * &head){

    Lnode *p=head;   //将节点指针指向头
    int j=0;
    int i;
    cout<<"您想删除第几位数据:";
    cin>>i;
    while((p->next)&&(j<i-1)){
        p=p->next;
        ++j;
    }
    if (!(p->next)||(j>i-1)){
        return ;
    }
    Lnode *q=p->next;
    p->next=q->next;
    delete q;

    
}


void reverse(Lnode * &head){   //链表就地逆置  //可以通过头插法来实现
    if(head==nullptr||head->next==nullptr||head->next->next==nullptr){
        return ;
    }
    cout<<"链表逆置后为:"<<"\n";
    Lnode *p=head->next->next;
    head->next->next=nullptr;  //将第一个有数据节点和第二个节点断开，方便头插
    while(p!=nullptr){
        Lnode *q=p->next;
        p->next=head->next;  //头插法
        head->next=p;        //头插法
        p=q;
    }

}    

