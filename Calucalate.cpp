#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 1024
typedef enum{Char,Double} Flag;			//�����ж� �ý����Ϊ������ ���� �������� 
typedef struct binode					// ���������� 
{
	struct binode *lchild,*rchild;			
	char data;
	double num;
	Flag F;								//F 0 ��������� 1 ���� �������� 
}BiTNode,*BiTree;

void visit(BiTree T);					//���ʽ������� 

BiTree CreatTree(char s[],int i,int j);	//���ɶ����� 

double cal(BiTree T){
	double l,r;
	if(T->lchild!=NULL && T->rchild!=NULL)  
	{   
        
        //����ýڵ�������������������������������
        
		l=cal(T->lchild);
		r=cal(T->rchild);
		switch (T->data)
		{
			case '+':
				return (l+r);
			case '-':
				return (l-r);
			case '*':
				return (l*r);
			case '/':
				return (l/r);
		}		
	}else{
        return T->num;	
    }
		
}

BiTree CreatTree(char s[],int i,int j)			//���ɱ��ʽ������ 
{
	//��̬���ɵ����ڵ� 
	BiTree p,t;									//��̬����������ĸ���� 
	int k, flag = 0, pos,x=0;
	int m=-1,n=-1,num=0;						//m,n�����������ŵ�λ�� 
	char str[MAXSIZE];
	double sum;
	//���i == j����˵���ַ���ֻ��һ���ַ�����ΪҶ�ӽڵ㡢�򴴽�ֻ��һ�����ڵ�Ķ�����������
	if (i == j)
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		str[x++]=s[i];							//���ַ�ת��Ϊ���� 
		str[x]='\0';
		sum=atof(str);
		p->num = sum;
		p->F=Double;							//���ý������� 
		p->lchild = NULL;					
		p->rchild = NULL;
		return p;
	}
	//������ i != j�����
	//�Ӻ���ǰ�����һ��  +��-������+��-Ϊ�������ȳ˳���Ӽ���ԭ�� 
	for (k = j; k >= i; k--)
	{
		if(s[k]==')')							//��������� ���������� 
		{
			m=k;	
			do
			{
				k--;
			}while(s[k]!='(');
			n=k;
		}
		if (s[k] == '+' || s[k] == '-')
		{
			flag = 1;
			pos = k;
			break;
		}
	}

	//��û��+��-����Ѱ���ַ��������һ��*��/ 
	if (!flag)
	{
		for (k = j; k >= i; k--)
		{
			if(s[k]==')')						//��������� ���������� 
			{
					do
					{
						k--;
					}while(s[k]!='(');
			}
			if (s[k] == '*' || s[k] == '/')
			{
				flag = 1;
				pos = k;
				break;
			}
		}
	}

	if(!flag)				//˵��ֻʣ������������� ���� ֻʣ����һ������ 
	{
		if(m!=-1)					//�����Ϊ-1  ���� ��ֻʣ��������  ��ʱʹ��t���еݹ� 
		{
			t = (BiTree)malloc(sizeof(BiTNode));
			t=CreatTree(s,n+1,m-1);
			p=t;
			return p;
		} 
		else						//����ֻʣ����һ������  
		{
			for(i;i<=j;i++,x++)		//��������ת��Ϊ  ������  
			{
				str[x]=s[i];
			}
			str[x]='\0';
			sum=atof(str);
			p = (BiTree)malloc(sizeof(BiTNode));
			p->num=sum;
			p->F=Double;			//�������� 
			p->lchild=NULL;
			p->rchild=NULL;
			return p;
		}		
	}
	//��flag������0������posΪ�罫�ַ�����Ϊ���������֣��ֱ��Ӧ���ʽ���������������� 
	//ͬ�������������Ϊ����������Ϊ������
	//����һ�����ڵ㡢���ҵ������������ 
	if (flag)
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		p->data = s[pos];
		p->F=Char;
		p->lchild = CreatTree(s, i, pos - 1);		//�ݹ��������������������������� 
		p->rchild = CreatTree(s, pos + 1, j);     //�ݹ��������������������������� 
		return p;
	}
	else									
		return NULL;
}

int main(){
    
	BiTree p;
	double sum=0;
	char s[MAXSIZE],s1[MAXSIZE];
	printf("�밴�������ʾʽ����:\n");
	gets(s);
	p=CreatTree(s,0,strlen(s)-1);	
	printf("���:");
	sum=cal(p);
	printf("%.2lf",sum); 

    system("pause");
	return 0;
}
