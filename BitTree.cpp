#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


//���� ���� �������������
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

//�ݹ���ñ���������
    if(data==-1){
        return NULL;
    }else{
        T = new Tree;
        T->data=data;
        cout<<"������"<<data<<"��������:"<<endl;
        T->lchild=Creatlink();
        cout<<"������"<<data<<"��������:"<<endl;
        T->rchild=Creatlink();
        return T;
    }
}
    //	�������
void ShowXianXu(Tree* T){		//		�������������

	if(T==NULL)						//	�ݹ�������NULL��������һ��ڵ�
	{
		return;
	}
	printf("%d ",T->data);
	ShowXianXu(T->lchild);			//	�ݹ����������
	ShowXianXu(T->rchild);			//	�ݹ����������
}
//	�������
void ShowZhongXu(Tree* T){	//		�������������

	if(T==NULL)						//	�ݹ�������NULL��������һ��ڵ�
	{
		return;
	}
	
	ShowZhongXu(T->lchild);			//	�ݹ����������
	printf("%d ",T->data);
	ShowZhongXu(T->rchild);			//	�ݹ����������
	
}
//	�������
void ShowHouXu(Tree* T){			//		�������������
	if(T==NULL)						//	�ݹ�������NULL��������һ��ڵ�
	{
		return;
	}
	
	ShowHouXu(T->lchild);			//	�ݹ����������
	ShowHouXu(T->rchild);			//	�ݹ����������
	printf("%d ",T->data);
}


int main(){
	Tree* S;
	printf("�������һ���ڵ������:\n");
	S = Creatlink();			//		���ܴ�����������ɵĸ��ڵ�
	printf("����������: \n");
	ShowXianXu(S);				//		�������������

	printf("\n����������: \n");
	ShowZhongXu(S);				//		�������������
	
	printf("\n����������: \n");
	ShowHouXu(S);				//		�������������
	
    system("pause");
	return 0;	
} 	


































