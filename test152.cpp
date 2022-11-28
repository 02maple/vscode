/*#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Person{
    friend ostream &operator<<(ostream &cout,Person p);
    friend void test01();
private:
    //利用成员函数重载 左移运算符
    //不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    // void operator<<(Person &p){

    // } 
    int m_A;
    int m_B;
};

//只能利用全局函数重载左移运算符
ostream &operator<<(ostream &cout,Person p){    //本质operator<<(cout,p)  简化cout<<p
    cout<<"m_A="<<p.m_A;              //ostream 标准输出流对象
    cout<<"m_B="<<p.m_B;
    return cout;
}  

void test01(){
   Person p;
   p.m_A=10;
   p.m_B=10;
   cout<<p<<"hello"<<endl;  //链式编程
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

    //重载++运算符(前置)
    MyInteger& operator++(){  //对同一个数字进行累加，所以用引用传递
        //先进行++运算
        m_Num++;
        return *this; //再返回自身
    }

    //重载++运算符(后置)
    MyInteger operator++(int){  //int 代表占位参数 用于区分前置和后置递增
        //先 记录当时结果   
        MyInteger temp=*this;
        //后 递增
        m_Num++;
        //最后将记录结果返回
        return temp;
    }

private:
    int m_Num;
};

//全局函数   重载左移运算符
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
    //重载 赋值运算符
    //返回引用才是真正的自身
    Person& operator=(Person &p){
        //编译器是提供浅拷贝
        //m_Age=p.m_Age;

        //应该先判断是否有属性在堆区，如果有先释放，然后再深拷贝
        if(m_Age!=NULL){
            delete m_Age;
            m_Age=NULL;
        }
        //深拷贝
        m_Age=new int(*p.m_Age);
        //返回对象本身
        return *this;
    }

    int *m_Age;
};

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(20);
    p3=p2=p1; //赋值运算操作
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

//     //重载==
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
//     Person p1("张三",18);
//     Person p2("张",18);

//     if(p1==p2){
//         cout<<"p1和p2是相等的"<<endl;
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
// //函数调用运算符重载

// //打印输出类

// class MyPrint{
// public:
//     //重载函数调用运算符
//     void operator()(string test){
//         cout<<test<<endl;
//     }
// };
// void MyPring02(string test){
//     cout<<test<<endl;
// }

// void test01(){
//     MyPrint myPrint;

//      //由于使用起来非常类似函数调用，因此称为仿函数
//     myPrint("hello world");
//     MyPring02("hello world 02");
// }

// //仿函数非常灵活，没有固定写法

// //加法类
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

//     //匿名函数对象
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
//         cout<<"首页，公开课，登录，注册....(公共头部)"<<endl;
//     }
//     void footer(){
//         cout<<"帮助中心，交流合作，站内地图....(公共底部)"<<endl;
//     }
//     void left(){
//         cout<<"Java,Python,C++....(公共分类列表)"<<endl;
//     }
//     void content(){
//         cout<<"Java学科视频"<<endl;
//     }
// };

// //Python
// class Python{
// public:
//     void header(){
//         cout<<"首页，公开课，登录，注册....(公共头部)"<<endl;
//     }
//     void footer(){
//         cout<<"帮助中心，交流合作，站内地图....(公共底部)"<<endl;
//     }
//     void left(){
//         cout<<"Java,Python,C++....(公共分类列表)"<<endl;
//     }
//     void content(){
//         cout<<"Python学科视频"<<endl;
//     }
//};


//继承实现
//公共页面
class Basepage{
public:
    void header(){
        cout<<"首页，公开课，登录，注册....(公共头部)"<<endl;
    }
    void footer(){
        cout<<"帮助中心，交流合作，站内地图....(公共底部)"<<endl;
    }
    void left(){
        cout<<"Java,Python,C++....(公共分类列表)"<<endl;
    }

};

//继承的好处:减少重复代码
//语法:
   // class 子类 : 继承方式 父类
   // 子类 也称为 派生类
   // 父类 也成为 基类
//JAVA页面
class Java:public Basepage{
public:
    void content(){
        cout<<"Java学科视频"<<endl;
    }
};

//Python页面
class Python:public Basepage{
public:
    void content(){
        cout<<"Python学科视频"<<endl;
    }
};


void test01(){
    cout<<"Java下载视频页面如下:"<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"---------------------"<<endl;
}

void test02(){
    cout<<"Python下载视频页面如下:"<<endl;
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
        m_A=10;  //父类中 公共 权限成员 到子类中依然是公共权限
        m_B=10;  //父类中 保护 权限成员 到子类中依然是保护权限  类内可以访问 类外不行
      //m_C=10;  //父类中 私有 权限成员 子类无法访问
    }
};

void test01(){
    Son1 s1;
    s1.m_A=100;  //公共权限，类内可访问，类外也访问
    
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
        m_A=10;  //父类中 公共 权限成员 到子类中是保护权限  类内可以访问 类外不行
        m_B=10;  //父类中 保护 权限成员 到子类中是保护权限  类内可以访问 类外不行
      //m_C=10;  //父类中 私有 权限成员 子类无法访问
    }
};

void test02(){
    Son2 s2;
    s2.m_A=100;  //保护权限，类内可访问，类外不可访问
    
}

int main(){
    test02();

    return 0;
}