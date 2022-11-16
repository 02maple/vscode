#include <iostream>
using namespace std;

//���Բ��ϵ����



class Point{

public:
    //����x
    void setX(int x){
        m_X=x;
    }
    //��ȡx
    int getX(){
        return m_X;
    }

    //����y
    void setY(int y){
        m_Y=y;
    }
    //��ȡy
    int getY(){
        return m_Y;
    }

private:
    int m_X;

    int m_Y;


};
//Բ��
class Circle{

    //��Ϊ
public:
    //���ð뾶
    void setR(int r){

        m_R=r;
    }
    //��ȡ�뾶
    int getR(){
        return m_R;
    }

    //����Բ��
    void setCenter(Point center){

        m_Center=center;
    }

    //��ȡԲ��

    Point getCenter(){
        return m_Center;
    }


private:

//����
    int m_R; //�뾶

    /*int m_X; //���xλ��

    int m_Y; //���yλ��*/

    Point m_Center;//Բ��

};

//�жϵ��Բ��ϵ
void isInCircle(Circle &c,Point &p){

    //��������֮������ƽ��
    int p2pDistance;
    p2pDistance=(c.getCenter().getX()-p.getX())*
              (c.getCenter().getX()-p.getX())+(c.getCenter().getY()-p.getY())*
              (c.getCenter().getY()-p.getY());
    //����뾶��ƽ��
    int r2=c.getR()*c.getR();

    //�жϹ�ϵ
    if(p2pDistance==r2){
        cout<<"����Բ��"<<endl;
    }else if(p2pDistance<r2){
        cout<<"����Բ��"<<endl;
    }else{
        cout<<"����Բ��"<<endl;
    }

}

int main(){

    //����Բ
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    //������

    Point p;
    p.setX(10);
    p.setY(10);

    //�жϹ�ϵ

    isInCircle(c,p);

    system("pause");

    
}