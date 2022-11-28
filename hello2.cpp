#include <iostream>
using namespace std;

//继承中的对象模型
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
    //父类中所有非静态成员属性都会被子类继承下去
    //父类中的私有成员属性 是被编译器给隐藏了 因此访问不到
    //但是确实被继承下去了 
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
        cout<<"Base 构造函数"<<endl;
    }

    ~Base(){
        cout<<"Base 析构函数"<<endl;
    }
};

class Son:public Base{
public:
    Son(){
        cout<<"Son 构造函数"<<endl;
    }

    ~Son(){
        cout<<"Son 析构函数"<<endl;
    }

};

void test01(){
    //Base b;
    //继承中的构造和析构顺序如下
    //先构造父类，再构造子类，析构的顺序和构造相反
    Son a;
}  

int main(){
    test01();
    system("pause");
}


继承同名成员处理方式

访问子类中同名成员 直接访问即可
访问父类中同名成员 需要加作用域

#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        m_A=100;
    }
    void func(){
        cout<<"Base - func()调用"<<endl;
    }
    void func(int a){
        cout<<"Base - func()调用"<<endl;
    }
    int m_A;
    
};

class Son:public Base{
public:
    Son(){
        m_A=200;
    }
    void func(){
        cout<<"Son - func()调用"<<endl;
    }
    int m_A;
};
//同名成员属性
void test01(){
    Son s;
    cout<<"m_A="<<s.m_A<<endl;
    //如果通过子类对象访问父类中的同名成员，需要加作用域
    cout<<"Base下 m_A="<<s.Base::m_A<<endl;
}  


//同名函数
void test02(){
    Son s;
    s.func();//直接调用，调用的是子类中的同名
    s.Base::func(); 

    //如果子类中出现和父类同名的成员函数
    //子类中的同名成员会隐藏掉父类中所有同名的成员函数
    //错误访问父类 s.func(100);
    s.Base::func(100);
    }

int main(){
    //test01();
    test02();
    system("pause");
}