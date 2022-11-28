#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GBK
typedef struct student{
    int ID;
    char name[10];
    int chinese;
    int math;
    int english;
    int physics;
    double average;
    int sum;
} Student;  //创捷学生数据结构体

typedef struct _node{
    Student date;  //数据域
    struct _node *next;  //指针域
} Node;  //创建链表，将学生数据结构体放置其中

void input(Node* &);
void out(Node *);
void toptoend(Node *);
void Intswap(int *,int *);
void Douswap(double *,double *);
void Charwap(char *,char *);
bool Judge(Node *);
int main(){

    Node *head=NULL,*p=NULL,*pr=NULL;

    while(1){
        printf("******************Choice****************\n");
        printf("***     1:加入学生成绩               ***\n");
        printf("***     2:查看学生成绩               ***\n");
        printf("***     3:待定                       ***\n");
        printf("***     4:按总分排序                 ***\n");
        printf("***     5:EXIT                       ***\n");
        printf("****************************************\n");
        printf("\n");

        
        
        int c;
        printf("选择你想进行的操作序号:");
        scanf("%d",&c);
        switch(c){
                case 1:input(head);
                break;
                case 2:
                    
                    printf("---------------------------------------------------------------\n");
                    printf("学号\t姓名\t语文\t数学\t英语\t物理\t平均分\t总分\n");
                    printf("---------------------------------------------------------------\n");
                    out(head);
                    break;
                case 3:break;
                case 4:
                    if(Judge(head)){
                        printf("暂无信息,请先录入数据\n");
                        break;
                    }
                    toptoend(head);
                    break;
                case 5: return 0;
                break;

                default:
                printf("请选择 1-5\n \n");
            }
        }

        
    system("pause");
    system("cls");
    
    return 0;
    
}

//学生数据输入操作函数
void input(Node* &head){
    Node *p=nullptr;
    if(!head){   //判断头节点是否为空，若空，将新数据放置在头节点
        head=new Node;
        head->next=nullptr;
        p=head;
    }else{    //若头节点不为空，为新节点分配空间，同时另尾指针移动，直到尾指针的指针域指向空
        p= new Node;
        p->next=nullptr;
        Node *pre=head;
        while(pre->next!=0){
        pre=pre->next;
    }
        pre->next=p;
    }
        printf("学生学号:");
        scanf("%d",&p->date.ID);
        printf("学生姓名:");
        scanf("%s",&p->date.name);
        printf("学生数学成绩:");
        scanf("%d",&p->date.math);
        printf("学生语文成绩:");
        scanf("%d",&p->date.chinese);
        printf("学生英语成绩:");
        scanf("%d",&p->date.english);
        printf("学生物理成绩:");
        scanf("%d",&p->date.physics);
        printf("\n");
        p->date.sum=p->date.chinese + p->date.math + p->date.physics + p->date.english;
        p->date.average=p->date.sum/4;
        
    system("pause");
    system("cls");
    
        

}

//输出输入过的学生数据
void out(Node *head){
    Node *p=head;
    while(p!=nullptr){
        printf("%d\t",p->date.ID);
        printf("%s\t",p->date.name);
        printf("%d\t",p->date.chinese);
        printf("%d\t",p->date.math);
        printf("%d\t",p->date.english);
        printf("%d\t",p->date.physics);
        printf("%.2lf\t",p->date.average);
        printf("%d\t",p->date.sum);
        printf("\n");
        p=p->next;
    }
    system("pause");
    system("cls");
    
}

//高分排序
void toptoend(Node *head){
    
    Node *p;
    p=head;
    
    while(p->next!=NULL&&p!=NULL){
        if(p->next->date.sum>p->date.sum){
            //通过其他函数，对链表节点中的数据进行调换排序
            //仅对数据
            Intswap(&p->next->date.ID,&p->date.ID);
            Charwap(p->next->date.name,p->date.name);
            Intswap(&p->next->date.chinese,&p->date.chinese);
            Intswap(&p->next->date.math,&p->date.math);
            Intswap(&p->next->date.english,&p->date.english);
            Intswap(&p->next->date.physics,&p->date.physics);
            Intswap(&p->next->date.sum,&p->date.sum);
            Douswap(&p->next->date.average,&p->date.average);
        }
        p=p->next;
        
    }
    printf("排序成功!");
    

    system("pause");
    system("cls");
    
}



void Intswap(int *p1,int *p2){
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void Douswap(double *p1,double *p2){
    double temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void Charwap(char *p1,char *p2){
    char temp[10];
    strcpy(temp,p1);
    strcpy(p1,p2);
    strcpy(p2,temp);
}

bool Judge(Node *head){
    Node *p=head;
    if(!p){
        return true;
    }else{
        return false;
    }
}