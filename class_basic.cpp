#include <iostream>
using namespace std;


//设计学生类
class Student{
public: //公共权限

    //类中的属性和行为 统一称为 成员
    //属性  成员属性  成员变量
    //行为  成员函数  成员方法


    //行为
    //通过行为 给属性赋值 通过函数
    void in_name(string name){
        s_name=name;
    }
    void in_id(string id){
        s_id=id;
    }

    //行为  显示姓名和学号   用函数封装
    void show_student(){
        cout<<"name:"<<s_name<<"\t"<<"ID:"<<s_id<<endl;
    }

public:  //公共权限
    //属性
    string s_name;//姓名
    string s_id;//学号


};


int main(){

    //通过行为赋值
    Student s1;  //实例化对象
    s1.in_name("张三");
    s1.in_id("5903121081");
    s1.show_student();

    //创建具体学生  实例化对象
    Student s2;
    //给s2对象进行属性赋值
    /*s2.s_id="1";
    s2.s_name="李四";
    s2.show_student();*/



    system("pause");
    return 0;
}