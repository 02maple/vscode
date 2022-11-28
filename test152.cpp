/*#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Person{
    friend ostream &operator<<(ostream &cout,Person p);
    friend void test01();
private:
    //���ó�Ա�������� ���������
    //�������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
    // void operator<<(Person &p){

    // } 
    int m_A;
    int m_B;
};

//ֻ������ȫ�ֺ����������������
ostream &operator<<(ostream &cout,Person p){    //����operator<<(cout,p)  ��cout<<p
    cout<<"m_A="<<p.m_A;              //ostream ��׼���������
    cout<<"m_B="<<p.m_B;
    return cout;
}  

void test01(){
   Person p;
   p.m_A=10;
   p.m_B=10;
   cout<<p<<"hello"<<endl;  //��ʽ���
}

int main(){
    test01();
    system("pause");
    return 0;
}*/



/*#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class MyInteger{
    friend ostream &operator<<(ostream &cout,MyInteger myint);
public:
    MyInteger(){
        m_Num=0;
    }

    //����++�����(ǰ��)
    MyInteger& operator++(){  //��ͬһ�����ֽ����ۼӣ����������ô���
        //�Ƚ���++����
        m_Num++;
        return *this; //�ٷ�������
    }

    //����++�����(����)
    MyInteger operator++(int){  //int ����ռλ���� ��������ǰ�úͺ��õ���
        //�� ��¼��ʱ���   
        MyInteger temp=*this;
        //�� ����
        m_Num++;
        //��󽫼�¼�������
        return temp;
    }

private:
    int m_Num;
};

//ȫ�ֺ���   �������������
ostream& operator<<(ostream &cout,MyInteger myint){
    cout<<myint.m_Num;
    return cout;
}

void test01(){
    MyInteger myint;
    cout<<++(++myint)<<endl;
    cout<<myint<<endl;
}

void test02(){
    MyInteger myint;
    cout<<myint++<<endl;
    cout<<myint<<endl;

}
int main(){
    //test01();
    test02();
    system("pause");
    return 0;
}*/

/*#include <iostream>
using namespace std;

class Person{

public:
    Person(int age){
        m_Age=new int(age);
    }

    ~Person(){
        if(m_Age!=NULL){
            delete m_Age;
            m_Age=NULL;
        }
    }
    //���� ��ֵ�����
    //�������ò�������������
    Person& operator=(Person &p){
        //���������ṩǳ����
        //m_Age=p.m_Age;

        //Ӧ�����ж��Ƿ��������ڶ�������������ͷţ�Ȼ�������
        if(m_Age!=NULL){
            delete m_Age;
            m_Age=NULL;
        }
        //���
        m_Age=new int(*p.m_Age);
        //���ض�����
        return *this;
    }

    int *m_Age;
};

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(20);
    p3=p2=p1; //��ֵ�������
    cout<<*p1.m_Age;
    cout<<*p2.m_Age;
    cout<<*p3.m_Age;
}

int main(){  
    test01();
    system("pause");
    return 0;
}*/


// #include <iostream>
// #include <string>
// using namespace std;

// class Person{

// public:
//     Person(string name,int age){
//         m_Age=age;
//         m_Name=name;
//     }

//     //����==
//     bool operator==(Person &p){
//         if(this->m_Age=p.m_Age && this->m_Name==p.m_Name){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     string m_Name;
//     int m_Age;
// };
// void test01(){
//     Person p1("����",18);
//     Person p2("��",18);

//     if(p1==p2){
//         cout<<"p1��p2����ȵ�"<<endl;
//     }else{
//         cout<<"no no no"<<endl;
//     }

// }
// int main(){

//     test01();

//     system("pause");
//     return 0;

// }



// #include <iostream>
// #include <stdlib.h>
// #include <string>
// using namespace std;
// //�����������������

// //��ӡ�����

// class MyPrint{
// public:
//     //���غ������������
//     void operator()(string test){
//         cout<<test<<endl;
//     }
// };
// void MyPring02(string test){
//     cout<<test<<endl;
// }

// void test01(){
//     MyPrint myPrint;

//      //����ʹ�������ǳ����ƺ������ã���˳�Ϊ�º���
//     myPrint("hello world");
//     MyPring02("hello world 02");
// }

// //�º����ǳ���û�й̶�д��

// //�ӷ���
// class MyAdd
// {
// public:
//     int operator()(int n1,int n2){
//         return n1+n2;
//     }
// };


// void test02(){
//     MyAdd myadd;
//     int ret=myadd(100,200);
//     cout<<"ret="<<ret<<endl;

//     //������������
//     cout<<MyAdd()(100,200)<<endl;
// }

// int main(){
//     test01();
//     test02();
//     system("pause");
// }






/*#include <iostream>
using namespace std;

//class Java{
// public:
//     void header(){
//         cout<<"��ҳ�������Σ���¼��ע��....(����ͷ��)"<<endl;
//     }
//     void footer(){
//         cout<<"�������ģ�����������վ�ڵ�ͼ....(�����ײ�)"<<endl;
//     }
//     void left(){
//         cout<<"Java,Python,C++....(���������б�)"<<endl;
//     }
//     void content(){
//         cout<<"Javaѧ����Ƶ"<<endl;
//     }
// };

// //Python
// class Python{
// public:
//     void header(){
//         cout<<"��ҳ�������Σ���¼��ע��....(����ͷ��)"<<endl;
//     }
//     void footer(){
//         cout<<"�������ģ�����������վ�ڵ�ͼ....(�����ײ�)"<<endl;
//     }
//     void left(){
//         cout<<"Java,Python,C++....(���������б�)"<<endl;
//     }
//     void content(){
//         cout<<"Pythonѧ����Ƶ"<<endl;
//     }
//};


//�̳�ʵ��
//����ҳ��
class Basepage{
public:
    void header(){
        cout<<"��ҳ�������Σ���¼��ע��....(����ͷ��)"<<endl;
    }
    void footer(){
        cout<<"�������ģ�����������վ�ڵ�ͼ....(�����ײ�)"<<endl;
    }
    void left(){
        cout<<"Java,Python,C++....(���������б�)"<<endl;
    }

};

//�̳еĺô�:�����ظ�����
//�﷨:
   // class ���� : �̳з�ʽ ����
   // ���� Ҳ��Ϊ ������
   // ���� Ҳ��Ϊ ����
//JAVAҳ��
class Java:public Basepage{
public:
    void content(){
        cout<<"Javaѧ����Ƶ"<<endl;
    }
};

//Pythonҳ��
class Python:public Basepage{
public:
    void content(){
        cout<<"Pythonѧ����Ƶ"<<endl;
    }
};


void test01(){
    cout<<"Java������Ƶҳ������:"<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"---------------------"<<endl;
}

void test02(){
    cout<<"Python������Ƶҳ������:"<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout<<"---------------------"<<endl;
}

int main(){

    test01();
    test02();


    system("pause");
    return 0;
}
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Basel{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1:public Basel{
public:
    void func(){
        m_A=10;  //������ ���� Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
        m_B=10;  //������ ���� Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��  ���ڿ��Է��� ���ⲻ��
      //m_C=10;  //������ ˽�� Ȩ�޳�Ա �����޷�����
    }
};

void test01(){
    Son1 s1;
    s1.m_A=100;  //����Ȩ�ޣ����ڿɷ��ʣ�����Ҳ����
    
}

class Base2{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son2:protected Base2{
public:
    void func(){
        m_A=10;  //������ ���� Ȩ�޳�Ա ���������Ǳ���Ȩ��  ���ڿ��Է��� ���ⲻ��
        m_B=10;  //������ ���� Ȩ�޳�Ա ���������Ǳ���Ȩ��  ���ڿ��Է��� ���ⲻ��
      //m_C=10;  //������ ˽�� Ȩ�޳�Ա �����޷�����
    }
};

void test02(){
    Son2 s2;
    s2.m_A=100;  //����Ȩ�ޣ����ڿɷ��ʣ����ⲻ�ɷ���
    
}

int main(){
    test02();

    return 0;
}