#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


//1.���캯���ķ��༰����
//����
//   ���ղ�������  �޲ι��죨Ĭ�Ϲ��캯���� �� �вι���
//   �������ͷ���  ��ͨ���� �������캯��
class Person{

public:
    //���캯��
    Person(){
        cout<<"Person�޲ι��캯������"<<endl;
    }
    Person(int a){
        age=a;
        cout<<"Person�вι��캯������"<<endl;
    }

    //�������캯��  �������õķ�ʽ����
    Person(const Person &p){  //�������캯����ʽ
        cout<<"Person�������캯������"<<endl;
    //������������ϵ��������Կ�����������
        age=p.age;
    }

    //��������
    ~Person(){
        cout<<"Person������������"<<endl;
    }


    int age;
};

void test01(){
    //1.���ŷ�

/*  Person p1; //Ĭ�Ϲ��캯������
    Person p2(100);//�вι��캯��
    Person p3(p2);//�������캯��

    //ע������
    //����Ĭ�Ϲ��캯����ʱ�򣬲�Ҫ��()
    //��Ϊ Person p1();  ����������Ϊ��һ������������
    cout<<"p2������Ϊ:"<<p2.age<<endl;
    cout<<"p3������Ϊ:"<<p3.age<<endl;    */

    //2.��ʾ��
/*   Person p1;
    Person p2=Person(10); //�вι���
    Person p3=Person(p2); //��������

    Person(10); //�������� �ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
    
    //ע������ 2
    //��Ҫ���ÿ������캯�� ��ʼ����������
    //����������Ϊ   Person(p3)==Person p3; 

*/
    //3.��ʽת����
    Person p4=10; //�൱��Person p4 = Person(10)
    Person p5=p4;

}

int main(){

    test01();




    system("pause");
    return 0;
}