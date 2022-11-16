#include <stdio.h>
#include <stdlib.h>

#define MaxSize 30
int InData(long num[],float score[]);
int GetFail(long num[],float score[],int );
int GetAbove(long num[],float score[],int );
void GetPer(float score[],int );


int main(){

    long num[MaxSize]={0};
    float score[MaxSize]={0};
    int n,fail,above;
    n=InData(num,score);
    printf("ѧ������:%d\n \n",n);
    fail=GetFail(num,score,n);
    printf("\n");
    above=GetAbove(num,score,n);
    printf("\n");
    GetPer(score,n);

    system("pause");
    return 0;
}

//����ѧ����ѧ�źͳɼ���������ɼ�Ϊ����������ѭ��������ѧ������
int InData(long num[],float score[]){
    int i=0;
    scanf("%ld %f",&num[i],&score[i]);
    while(score[i]>=0){
        i++;
        scanf("%ld %f",&num[i],&score[i]);
    }
 
    return i;
}

//ͳ�Ʋ���������������ӡ����
int GetFail(long num[],float score[],int n){
    int i,count=0;
    for(i=0;i<n;++i){
        if(score[i]<60){
            printf("ѧ�� %ld �����񣬳ɼ�Ϊ %.0lf\n",num[i],score[i]);
            count++;
        }
    }
    printf("����������Ϊ %d \n",count);
    return count;
}


//����ȫ��ƽ���֣���ͳ�Ʒ�����ƽ���ּ����ϵ���������ӡ����
int GetAbove(long num[],float score[],int n){
    int i,count=0;
    int sum=0;
    float avrage=0;
    for(i=0;i<n;++i){
        sum+=score[i];
    }
    avrage=sum/n;//���ƽ����
    printf("������ƽ���ּ�����:\n");
    for(i=0;i<n;++i){
        if(score[i]>=avrage){
            printf("ѧ�� %ld �ɼ�Ϊ %.0lf\n",num[i],score[i]);
            count++;
        }
    }
    printf("������ƽ���ּ����ϵ�����Ϊ %d \n",count);
    return count;
}

//ͳ�Ƹ������ε�ѧ�������Լ���ռ�İٷֱ�

void GetPer(float score[],int n){
    int i,j;
    int m[6]={0};
    for(i=0;i<n;++i){
        if (score[i]<60){
            j=0;
        }else{
            j=((int)score[i]-50)/10;
        }
        m[j]++;
    }
    for(i=0;i<6;++i){
        if(i==0){
            printf("<60\t%d\t%.2f%%\n",m[i], m[i]/(float)n*100);
        }else if(i==5){
            printf("100\t%d\t%.2f%%\n",m[i], m[i]/(float)n*100);
        }else {
            printf("%d--%d\t%d\t%.2f%%\n",(i+5)*10,(i+5)*10+9,m[i],m[i]/(float)n*100);
        }
    }
}