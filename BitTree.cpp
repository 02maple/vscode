#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


//先序 中序 后序遍历二叉树
typedef struct Tree{
    int data;
    struct Tree *lchild;
    struct Tree *rchild;
}Tree;

Tree* Creatlink(){
    int data;
    Tree* T;

    cin>>data;
    getchar();

//递归调用遍历二叉树
    if(data==-1){
        return NULL;
    }else{
        T = new Tree;
        T->data=data;
        cout<<"请输入"<<data<<"的左子树:"<<endl;
        T->lchild=Creatlink();
        cout<<"请输入"<<data<<"的右子树:"<<endl;
        T->rchild=Creatlink();
        return T;
    }
}
    //	先序遍历
void ShowXianXu(Tree* T){		//		先序遍历二叉树

	if(T==NULL)						//	递归中遇到NULL，返回上一层节点
	{
		return;
	}
	printf("%d ",T->data);
	ShowXianXu(T->lchild);			//	递归遍历左子树
	ShowXianXu(T->rchild);			//	递归遍历右子树
}
//	中序遍历
void ShowZhongXu(Tree* T){	//		先序遍历二叉树

	if(T==NULL)						//	递归中遇到NULL，返回上一层节点
	{
		return;
	}
	
	ShowZhongXu(T->lchild);			//	递归遍历左子树
	printf("%d ",T->data);
	ShowZhongXu(T->rchild);			//	递归遍历右子树
	
}
//	后序遍历
void ShowHouXu(Tree* T){			//		后序遍历二叉树
	if(T==NULL)						//	递归中遇到NULL，返回上一层节点
	{
		return;
	}
	
	ShowHouXu(T->lchild);			//	递归遍历左子树
	ShowHouXu(T->rchild);			//	递归遍历右子树
	printf("%d ",T->data);
}


int main(){
	Tree* S;
	printf("请输入第一个节点的数据:\n");
	S = Creatlink();			//		接受创建二叉树完成的根节点
	printf("先序遍历结果: \n");
	ShowXianXu(S);				//		先序遍历二叉树

	printf("\n中序遍历结果: \n");
	ShowZhongXu(S);				//		中序遍历二叉树
	
	printf("\n后序遍历结果: \n");
	ShowHouXu(S);				//		后序遍历二叉树
    system("pause");
	return 0;	
} 	


































