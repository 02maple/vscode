#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Tree{
    char data;
    struct Tree *lchild;
    struct Tree *rchild;
}Tree;

//ǰ���������������
//������:ABD##E##C##

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

//�ݹ�ǰ�����������
void preOrder(Tree* T){
    if(T!=nullptr){
  cout<<T->data;
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//�ݹ��������������
void inOrder(Tree* T){
    if(T!=nullptr){
        inOrder(T->lchild);
        cout<<T->data;
        inOrder(T->rchild);
    }
}

//�ݹ�������������
void endOrder(Tree* T){
    if(T!=nullptr){ 
        endOrder(T->lchild);
        endOrder(T->rchild);
        cout<<T->data;
    }
}

// ��-�ݹ�ǰ�����������
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
		// ����һ��ջ
		stack[k] = root; // �����ڵ���ջ
		while (k > -1){
			//��ջ
			node = stack[k--];
			printf("%c-", node->data);
 
			// �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ�
			if (node->rchild!= NULL){
				stack[++k] = node->rchild;
			}
			if (node->lchild != NULL){
				stack[++k] = node->lchild;
			}
 
		}
 
	}
}


// ��-�ݹ��������������
void inOrderN(Tree* T){
	Tree* stack[30];
    Tree* t;
	int top=0;
    //�ж����Ƿ�Ϊ��
    if(t==nullptr){
        cout<<"tree is empty"<<endl;
        return;
    }
    t = T;
    //�ڲ�ѭ��Ϊָ��lchild�����ѭ��Ϊָ��rchild
    //��Ϊ��Ҫ�ȱ������������ٱ���������
    while(t!=nullptr||top>0){
        //�������������ڵ���ջ
        while(t!=nullptr){
            stack[++top]=t;
            t=t->lchild;
        }
        //���������Ϊ�գ��򵯳�ջ��Ԫ��
        t=stack[top--]; 
        cout<<t->data<<"-";

        //ɨ���ҽڵ�
        t=t->rchild;
    }
	
}


int main(){
 
	printf("starting ------ \n");
 
	Tree* T = CreatTree();
	printf("�ݹ�ǰ�����--- \n");
	preOrder(T);
	printf("\n");
	printf("�ݹ��������--- \n");
	inOrder(T);
	printf("\n");
	printf("�ݹ�������--- \n");
	endOrder(T);
	printf("\n");

    printf("-��-�ݹ�ǰ�����--- \n");
	preOrderN(T);
    printf("\n");
    printf("-��-�ݹ��������--- \n");
    inOrderN(T);
	printf("\n");

    system("pause");
	return 0;
}