#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Tree{
    int data;
    struct Tree* lchild;
    struct Tree* rchild;
}Tree;

Tree* CreatLink(){

    int data;
    Tree* T;  //ָ�����нڵ��ָ��
    cin>>data;
    getchar();

    if (data==-1){
        return NULL;
    }else{
        T=new Tree;
        T->data=data;
        cout<<"������"<<data<<"��������"<<endl;
        T->lchild=CreatLink();
        cout<<"������"<<data<<"��������"<<endl;
        T->rchild=CreatLink();
        return T;
    }

}

//�������

void XianXu(Tree* T){

    if(T==nullptr){
        return ; //�ݹ��У�������һ�ڵ�
    }else{
        cout<<T->data;
        XianXu(T->lchild);
        XianXu(T->rchild);
    }

}
void ZhongXu(Tree* T){

    if(T==nullptr){
        return ; //�ݹ��У�������һ�ڵ�
    }else{
        ZhongXu(T->lchild);
        cout<<T->data;
        ZhongXu(T->rchild);
    }

}
void HouXu(Tree* T){

    if(T==nullptr){
        return ; //�ݹ��У�������һ�ڵ�
    }else{
        
        HouXu(T->lchild);
        HouXu(T->rchild);
        cout<<T->data;
    }

}


int main(){
    Tree* S;
    S=CreatLink();
    cout<<"����������:";
    XianXu(S);
    cout<<endl;

    cout<<"����������:";
    ZhongXu(S);
    cout<<endl;
    
    cout<<"����������:";
    HouXu(S);
    cout<<endl;

    system("pause");
    return 0;
}


