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
} Student;  //����ѧ�����ݽṹ��

typedef struct _node{
    Student date;  //������
    struct _node *next;  //ָ����
} Node;  //����������ѧ�����ݽṹ���������

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
        printf("***     1:����ѧ���ɼ�               ***\n");
        printf("***     2:�鿴ѧ���ɼ�               ***\n");
        printf("***     3:����                       ***\n");
        printf("***     4:���ܷ�����                 ***\n");
        printf("***     5:EXIT                       ***\n");
        printf("****************************************\n");
        printf("\n");

        
        
        int c;
        printf("ѡ��������еĲ������:");
        scanf("%d",&c);
        switch(c){
                case 1:input(head);
                break;
                case 2:
                    
                    printf("---------------------------------------------------------------\n");
                    printf("ѧ��\t����\t����\t��ѧ\tӢ��\t����\tƽ����\t�ܷ�\n");
                    printf("---------------------------------------------------------------\n");
                    out(head);
                    break;
                case 3:break;
                case 4:
                    if(Judge(head)){
                        printf("������Ϣ,����¼������\n");
                        break;
                    }
                    toptoend(head);
                    break;
                case 5: return 0;
                break;

                default:
                printf("��ѡ�� 1-5\n \n");
            }
        }

        
    system("pause");
    system("cls");
    
    return 0;
    
}

//ѧ�����������������
void input(Node* &head){
    Node *p=nullptr;
    if(!head){   //�ж�ͷ�ڵ��Ƿ�Ϊ�գ����գ��������ݷ�����ͷ�ڵ�
        head=new Node;
        head->next=nullptr;
        p=head;
    }else{    //��ͷ�ڵ㲻Ϊ�գ�Ϊ�½ڵ����ռ䣬ͬʱ��βָ���ƶ���ֱ��βָ���ָ����ָ���
        p= new Node;
        p->next=nullptr;
        Node *pre=head;
        while(pre->next!=0){
        pre=pre->next;
    }
        pre->next=p;
    }
        printf("ѧ��ѧ��:");
        scanf("%d",&p->date.ID);
        printf("ѧ������:");
        scanf("%s",&p->date.name);
        printf("ѧ����ѧ�ɼ�:");
        scanf("%d",&p->date.math);
        printf("ѧ�����ĳɼ�:");
        scanf("%d",&p->date.chinese);
        printf("ѧ��Ӣ��ɼ�:");
        scanf("%d",&p->date.english);
        printf("ѧ������ɼ�:");
        scanf("%d",&p->date.physics);
        printf("\n");
        p->date.sum=p->date.chinese + p->date.math + p->date.physics + p->date.english;
        p->date.average=p->date.sum/4;
        
    system("pause");
    system("cls");
    
        

}

//����������ѧ������
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

//�߷�����
void toptoend(Node *head){
    
    Node *p;
    p=head;
    
    while(p->next!=NULL&&p!=NULL){
        if(p->next->date.sum>p->date.sum){
            //ͨ������������������ڵ��е����ݽ��е�������
            //��������
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
    printf("����ɹ�!");
    

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