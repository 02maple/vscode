#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct student{
    
    int math;
    
} Student;  //创捷学生数据结构体

typedef struct _node{
    Student date;  //数据域
    struct _node *next;  //指针域
} Node;  //创建链表，将学生数据结构体放置其中

void input(Node* &);
void out(Node *);
void notpase(Node *);
void ninety(Node *);

int main(){

    Node *head=NULL,*p=NULL,*pr=NULL;

    while(1){
        cout<<"******************Choice****************"<<endl;
        cout<<"***     1:Join student's score       ***"<<endl;
        cout<<"***     2:View Student Grades        ***"<<endl;
        cout<<"***     3:Students failed            ***"<<endl;
        cout<<"***     4:Average of 90 or above     ***"<<endl;
        cout<<"***     5:EXIT                       ***"<<endl;
        cout<<"****************************************"<<endl;
        cout<<"\n"<<endl;

        
        
        char c,a;
        cout <<"Choose the project you will undertake:";
        cin >>c ;
        switch(c){
                case '1':input(head);
                break;
                case '2':out(head);
                break;
            
                
                case '5':return 0;

                default:cout<<"please chose 1-5\n \n";
            }
        }

        system("pause");
    
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
        
        
        cout << "Enter the student Math:";
        cin >> p->date.math;
        
        cout<<"\n"<<endl;
    
        

}

//输出输入过的学生数据
void out(Node *head){
    Node *p=head;
    while(p!=nullptr){
       
        cout <<"Math:"<<p->date.math <<"\t";
        
        cout<<"\n"<<endl;
        p=p->next;
    }
}


//输出有科目不及格的学生

/*void notpase(Node *head){
    Node *p=head;
    while(p!=nullptr){   //将新节点的指针从头开始逐步下移，当存在某一科目不及格时，
                         //输出学生的名字
        while(p->date.chinese<60||p->date.math<60||
              p->date.english<60||p->date.physics<60){
                cout <<"  "<<p->date.name<<"  "<<"has failing subject"<< endl;
                cout<<"\n"<<endl;
                break;
            }
                
        p=p->next;

    }
}*/


//输出平均成绩大于90的学生
/*void ninety(Node *head){
    Node *p=head;    //将指针从头开始，逐步往下查询数据，并输出
    while(p!=nullptr){

        while(p->date.average>90){
            cout<<"  "<<p->date.name<<"  "<<"'s average score is greater than 90\n";
            cout<<"\n"<<endl;
            break;
        }
        p=p->next;
    }
    
}*/
 
