#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Tree{
    char data;
    struct Tree *lchild;
    struct Tree *rchild;
}Tree;

//前序遍历创建二叉树
//根左右:ABD##E##C##

Tree* CreatTree(){
    Tree* T=nullptr;
    char ch;
    cin>>ch;
    if(ch!='#'){
        T=new Tree;
        T->data=ch;
        T->lchild=CreatTree();
        T->rchild=CreatTree();
    }else{
        T=nullptr;
    }
    return T; 
}

//递归前序遍历二叉树
void preOrder(Tree* T){
    if(T!=nullptr){
  cout<<T->data;
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//递归中序遍历二叉树
void inOrder(Tree* T){
    if(T!=nullptr){
        inOrder(T->lchild);
        cout<<T->data;
        inOrder(T->rchild);
    }
}

//递归后序遍历二叉树
void endOrder(Tree* T){
    if(T!=nullptr){ 
        endOrder(T->lchild);
        endOrder(T->rchild);
        cout<<T->data;
    }
}

// 非-递归前序遍历二叉树
void preOrderN(Tree* root){
	Tree* stack[30];
    Tree* node;
	int k = -1;
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		k++;
		// 仿照一个栈
		stack[k] = root; // 将根节点入栈
		while (k > -1){
			//出栈
			node = stack[k--];
			printf("%c-", node->data);
 
			// 先把右子树放进去，栈是先进去后出，所以下面的左子树先出
			if (node->rchild!= NULL){
				stack[++k] = node->rchild;
			}
			if (node->lchild != NULL){
				stack[++k] = node->lchild;
			}
 
		}
 
	}
}


// 非-递归中序遍历二叉树
void inOrderN(Tree* T){
	Tree* stack[30];
    Tree* t;
	int top=0;
    //判断树是否为空
    if(t==nullptr){
        cout<<"tree is empty"<<endl;
        return;
    }
    t = T;
    //内侧循环为指向lchild，外侧循环为指向rchild
    //因为需要先遍历左子树，再遍历右子树
    while(t!=nullptr||top>0){
        //将所有左子树节点入栈
        while(t!=nullptr){
            stack[++top]=t;
            t=t->lchild;
        }
        //如果左子树为空，则弹出栈中元素
        t=stack[top--]; 
        cout<<t->data<<"-";

        //扫描右节点
        t=t->rchild;
    }
	
}


int main(){
 
	printf("starting ------ \n");
 
	Tree* T = CreatTree();
	printf("递归前序遍历--- \n");
	preOrder(T);
	printf("\n");
	printf("递归中序遍历--- \n");
	inOrder(T);
	printf("\n");
	printf("递归后序遍历--- \n");
	endOrder(T);
	printf("\n");

    printf("-非-递归前序遍历--- \n");
	preOrderN(T);
    printf("\n");
    printf("-非-递归中序遍历--- \n");
    inOrderN(T);
	printf("\n");

    system("pause");
	return 0;
}