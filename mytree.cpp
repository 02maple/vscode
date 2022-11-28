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
    Tree* T;  //指向树中节点的指针
    cin>>data;
    getchar();

    if (data==-1){
        return NULL;
    }else{
        T=new Tree;
        T->data=data;
        cout<<"请输入"<<data<<"的左子树"<<endl;
        T->lchild=CreatLink();
        cout<<"请输入"<<data<<"的右子树"<<endl;
        T->rchild=CreatLink();
        return T;
    }

}

//先序遍历

void XianXu(Tree* T){

    if(T==nullptr){
        return ; //递归中，返回上一节点
    }else{
        cout<<T->data;
        XianXu(T->lchild);
        XianXu(T->rchild);
    }

}
void ZhongXu(Tree* T){

    if(T==nullptr){
        return ; //递归中，返回上一节点
    }else{
        ZhongXu(T->lchild);
        cout<<T->data;
        ZhongXu(T->rchild);
    }

}
void HouXu(Tree* T){

    if(T==nullptr){
        return ; //递归中，返回上一节点
    }else{
        
        HouXu(T->lchild);
        HouXu(T->rchild);
        cout<<T->data;
    }

}


int main(){
    Tree* S;
    S=CreatLink();
    cout<<"先序遍历结果:";
    XianXu(S);
    cout<<endl;

    cout<<"中序遍历结果:";
    ZhongXu(S);
    cout<<endl;
    
    cout<<"后序遍历结果:";
    HouXu(S);
    cout<<endl;

    system("pause");
    return 0;
}


