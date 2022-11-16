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



void MAKE_LIST(Lnode * &,int ); //�����µ�����ĺ���
void OUT(Lnode * &,int );   //����������ݵĺ���
void IN_LIST(Lnode * &,int );   //�ڽ����������м������ݵĺ���
void SER_LIST(Lnode * &,int); //Ѱ������
void DEL_LIST(Lnode * &); //ɾ������
void reverse(Lnode * &);//����͵�����


int main(){
    
    Lnode *head=nullptr;
    int n;
    cout<<"������뼸������:";
    cin>>n;
    MAKE_LIST(head,n);
    
    OUT(head,n);
    int i;
    cout<<"�������ļ����µ�����:  ";
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
    Lnode *pr=nullptr;   //����һ���ڵ㣬Ŀ����ʹ��һֱָ�������β��
    Lnode *p=nullptr;   //����һ���½ڵ㣬Ŀ����ʹ��ͨ��β�巨��������

    head=new Lnode;       //Ϊͷ�ڵ㴴��һ���ռ䣬ͬʱ��Ϊ�丳ֵ����������ʵΪ�գ�ֻ�Ǵ��е�ַ
    head->next=nullptr;   //��ͷ�ڵ��ָ����ָ��nullptr
    pr =head;             //��������ֻ��һ���ڵ㣬����ָ��β�ڵ��ָ���ָ��ͷ�ڵ��ָ����һ��
    
    p=new Lnode;          //Ϊ�¼�������ݴ���һ���ڵ�
    int i=0;
    cout<<"��������������:";
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
        

        cout<<"��������������:";
        cin>>e;
        s->number.a=e;
        s->next=p->next;
        p->next=s;
  
    
}

void SER_LIST(Lnode * &head,int n){
    Lnode *p=head->next;
    int j=1,e;
    cout<<"����Ѱ���ĸ�����:";
    cin>>e;
    while(p&&(p->number.a!=e)){
            p=p->next;
            ++j;
    }
    if(j<=n){
        cout<<"��������ڵ� "<<j<<"λ \n";
    }else {
        cout<<"���ݲ�����\n";
    }
}

void DEL_LIST(Lnode * &head){

    Lnode *p=head;   //���ڵ�ָ��ָ��ͷ
    int j=0;
    int i;
    cout<<"����ɾ���ڼ�λ����:";
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


void reverse(Lnode * &head){   //����͵�����  //����ͨ��ͷ�巨��ʵ��
    if(head==nullptr||head->next==nullptr||head->next->next==nullptr){
        return ;
    }
    cout<<"�������ú�Ϊ:"<<"\n";
    Lnode *p=head->next->next;
    head->next->next=nullptr;  //����һ�������ݽڵ�͵ڶ����ڵ�Ͽ�������ͷ��
    while(p!=nullptr){
        Lnode *q=p->next;
        p->next=head->next;  //ͷ�巨
        head->next=p;        //ͷ�巨
        p=q;
    }

}    

