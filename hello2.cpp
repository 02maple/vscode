#include <iostream>
using namespace std;

//�̳��еĶ���ģ��
class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son:public Base{
public:
    int m_D;

};

void test01(){
    cout<<"size of son="<<sizeof(Son)<<endl;
    //16
    //���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
    //�����е�˽�г�Ա���� �Ǳ��������������� ��˷��ʲ���
    //����ȷʵ���̳���ȥ�� 
}

int main(){
    test01();

    system("pause");
}



#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        cout<<"Base ���캯��"<<endl;
    }

    ~Base(){
        cout<<"Base ��������"<<endl;
    }
};

class Son:public Base{
public:
    Son(){
        cout<<"Son ���캯��"<<endl;
    }

    ~Son(){
        cout<<"Son ��������"<<endl;
    }

};

void test01(){
    //Base b;
    //�̳��еĹ��������˳������
    //�ȹ��츸�࣬�ٹ������࣬������˳��͹����෴
    Son a;
}  

int main(){
    test01();
    system("pause");
}


�̳�ͬ����Ա����ʽ

����������ͬ����Ա ֱ�ӷ��ʼ���
���ʸ�����ͬ����Ա ��Ҫ��������

#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        m_A=100;
    }
    void func(){
        cout<<"Base - func()����"<<endl;
    }
    void func(int a){
        cout<<"Base - func()����"<<endl;
    }
    int m_A;
    
};

class Son:public Base{
public:
    Son(){
        m_A=200;
    }
    void func(){
        cout<<"Son - func()����"<<endl;
    }
    int m_A;
};
//ͬ����Ա����
void test01(){
    Son s;
    cout<<"m_A="<<s.m_A<<endl;
    //���ͨ�����������ʸ����е�ͬ����Ա����Ҫ��������
    cout<<"Base�� m_A="<<s.Base::m_A<<endl;
}  


//ͬ������
void test02(){
    Son s;
    s.func();//ֱ�ӵ��ã����õ��������е�ͬ��
    s.Base::func(); 

    //��������г��ֺ͸���ͬ���ĳ�Ա����
    //�����е�ͬ����Ա�����ص�����������ͬ���ĳ�Ա����
    //������ʸ��� s.func(100);
    s.Base::func(100);
    }

int main(){
    //test01();
    test02();
    system("pause");
}