#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 1024
typedef enum{Char,Double} Flag;			//用来判断 该结点是为操作符 还是 操作数据 
typedef struct binode					// 线索二叉树 
{
	struct binode *lchild,*rchild;			
	char data;
	double num;
	Flag F;								//F 0 代表操作符 1 代表 操作数据 
}BiTNode,*BiTree;

void visit(BiTree T);					//访问结点的数据 

BiTree CreatTree(char s[],int i,int j);	//生成二叉树 

double cal(BiTree T){
	double l,r;
	if(T->lchild!=NULL && T->rchild!=NULL)  
	{   
        
        //如果该节点存在左右子树，则继续向左子树遍历
        
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

BiTree CreatTree(char s[],int i,int j)			//生成表达式二叉树 
{
	//动态生成的树节点 
	BiTree p,t;									//动态申请二叉树的根结点 
	int k, flag = 0, pos,x=0;
	int m=-1,n=-1,num=0;						//m,n代表左右括号的位置 
	char str[MAXSIZE];
	double sum;
	//如果i == j，则说明字符串只有一个字符，即为叶子节点、则创建只有一个根节点的二叉树并返回
	if (i == j)
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		str[x++]=s[i];							//将字符转换为数字 
		str[x]='\0';
		sum=atof(str);
		p->num = sum;
		p->F=Double;							//设置结点的线索 
		p->lchild = NULL;					
		p->rchild = NULL;
		return p;
	}
	//以下是 i != j的情况
	//从后向前找最后一个  +或-，先找+或-为了体现先乘除后加减的原则 
	for (k = j; k >= i; k--)
	{
		if(s[k]==')')							//如果有括号 先跳过括号 
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

	//若没有+或-，则寻找字符串中最后一个*或/ 
	if (!flag)
	{
		for (k = j; k >= i; k--)
		{
			if(s[k]==')')						//如果有括号 先跳过括号 
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

	if(!flag)				//说明只剩下括号里面的了 或者 只剩下了一整个数 
	{
		if(m!=-1)					//如果不为-1  代表 是只剩下了括号  临时使用t进行递归 
		{
			t = (BiTree)malloc(sizeof(BiTNode));
			t=CreatTree(s,n+1,m-1);
			p=t;
			return p;
		} 
		else						//表明只剩下了一个数据  
		{
			for(i;i<=j;i++,x++)		//将该数据转换为  浮点型  
			{
				str[x]=s[i];
			}
			str[x]='\0';
			sum=atof(str);
			p = (BiTree)malloc(sizeof(BiTNode));
			p->num=sum;
			p->F=Double;			//设置线索 
			p->lchild=NULL;
			p->rchild=NULL;
			return p;
		}		
	}
	//若flag不等于0，则以pos为界将字符串分为左右两部分，分别对应表达式二叉树的左、右子树 
	//同样以最后的运算符为根，将串分为两部分
	//创建一个根节点、将找到的运算符放入 
	if (flag)
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		p->data = s[pos];
		p->F=Char;
		p->lchild = CreatTree(s, i, pos - 1);		//递归调用自身进入其左子树建树过程 
		p->rchild = CreatTree(s, pos + 1, j);     //递归调用自身进入其右子树建树过程 
		return p;
	}
	else									
		return NULL;
}

int main(){
    
	BiTree p;
	double sum=0;
	char s[MAXSIZE],s1[MAXSIZE];
	printf("请按照中序表示式输入:\n");
	gets(s);
	p=CreatTree(s,0,strlen(s)-1);	
	printf("结果:");
	sum=cal(p);
	printf("%.2lf",sum); 

    system("pause");
	return 0;
}
