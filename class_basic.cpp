#include <iostream>
using namespace std;


//���ѧ����
class Student{
public: //����Ȩ��

    //���е����Ժ���Ϊ ͳһ��Ϊ ��Ա
    //����  ��Ա����  ��Ա����
    //��Ϊ  ��Ա����  ��Ա����


    //��Ϊ
    //ͨ����Ϊ �����Ը�ֵ ͨ������
    void in_name(string name){
        s_name=name;
    }
    void in_id(string id){
        s_id=id;
    }

    //��Ϊ  ��ʾ������ѧ��   �ú�����װ
    void show_student(){
        cout<<"name:"<<s_name<<"\t"<<"ID:"<<s_id<<endl;
    }

public:  //����Ȩ��
    //����
    string s_name;//����
    string s_id;//ѧ��


};


int main(){

    //ͨ����Ϊ��ֵ
    Student s1;  //ʵ��������
    s1.in_name("����");
    s1.in_id("5903121081");
    s1.show_student();

    //��������ѧ��  ʵ��������
    Student s2;
    //��s2����������Ը�ֵ
    /*s2.s_id="1";
    s2.s_name="����";
    s2.show_student();*/



    system("pause");
    return 0;
}