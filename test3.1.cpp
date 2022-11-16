#include <iostream>
#include <cstring>
using namespace std;

typedef struct date{
    int a;
}Date;

typedef struct _node{
    Date number;
    struct _node *next;
}Lnode;

void MAKE_LIST(Lnode *);

int main(){
    
    Lnode *head=nullptr;
    MAKE_LIST(head);
    return 0;

}


void MAKE_LIST(Lnode * &head){
    Lnode *p=nullptr;
    int i;
    int n;

    cout<<"how much number you want:";
    cin>>n;

    

        if(!head){
            head =new Lnode;
            head->next=nullptr;
            p=head;
        }else{
            p=new Lnode;
            p->next =nullptr;
            Lnode *pr=head;
            while(pr->next!=nullptr){
                pr=pr->next;
            }
            pr->next=p;
        }
    
    cout<<"enter the number:";
    cin>>p->number.a;
}
