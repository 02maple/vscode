#include <iostream>
using namespace std;

//点和圆关系案例



class Point{

public:
    //设置x
    void setX(int x){
        m_X=x;
    }
    //获取x
    int getX(){
        return m_X;
    }

    //设置y
    void setY(int y){
        m_Y=y;
    }
    //获取y
    int getY(){
        return m_Y;
    }

private:
    int m_X;

    int m_Y;


};
//圆类
class Circle{

    //行为
public:
    //设置半径
    void setR(int r){

        m_R=r;
    }
    //获取半径
    int getR(){
        return m_R;
    }

    //设置圆心
    void setCenter(Point center){

        m_Center=center;
    }

    //获取圆心

    Point getCenter(){
        return m_Center;
    }


private:

//属性
    int m_R; //半径

    /*int m_X; //点的x位置

    int m_Y; //点的y位置*/

    Point m_Center;//圆心

};

//判断点和圆关系
void isInCircle(Circle &c,Point &p){

    //计算两点之间距离的平方
    int p2pDistance;
    p2pDistance=(c.getCenter().getX()-p.getX())*
              (c.getCenter().getX()-p.getX())+(c.getCenter().getY()-p.getY())*
              (c.getCenter().getY()-p.getY());
    //计算半径的平方
    int r2=c.getR()*c.getR();

    //判断关系
    if(p2pDistance==r2){
        cout<<"点在圆上"<<endl;
    }else if(p2pDistance<r2){
        cout<<"点在圆内"<<endl;
    }else{
        cout<<"点在圆外"<<endl;
    }

}

int main(){

    //创建圆
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    //创建点

    Point p;
    p.setX(10);
    p.setY(10);

    //判断关系

    isInCircle(c,p);

    system("pause");

    
}