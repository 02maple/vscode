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
    printf("学生总数:%d\n \n",n);
    fail=GetFail(num,score,n);
    printf("\n");
    above=GetAbove(num,score,n);
    printf("\n");
    GetPer(score,n);

    system("pause");
    return 0;
}

//键入学生的学号和成绩，当输入成绩为负数，结束循环，返回学生总数
int InData(long num[],float score[]){
    int i=0;
    scanf("%ld %f",&num[i],&score[i]);
    while(score[i]>=0){
        i++;
        scanf("%ld %f",&num[i],&score[i]);
    }
 
    return i;
}

//统计不及格人数，并打印名单
int GetFail(long num[],float score[],int n){
    int i,count=0;
    for(i=0;i<n;++i){
        if(score[i]<60){
            printf("学号 %ld 不及格，成绩为 %.0lf\n",num[i],score[i]);
            count++;
        }
    }
    printf("不及格人数为 %d \n",count);
    return count;
}


//计算全班平均分，并统计分数在平均分及以上的人数，打印名单
int GetAbove(long num[],float score[],int n){
    int i,count=0;
    int sum=0;
    float avrage=0;
    for(i=0;i<n;++i){
        sum+=score[i];
    }
    avrage=sum/n;//求出平均分
    printf("分数在平均分及以上:\n");
    for(i=0;i<n;++i){
        if(score[i]>=avrage){
            printf("学号 %ld 成绩为 %.0lf\n",num[i],score[i]);
            count++;
        }
    }
    printf("分数在平均分及以上的人数为 %d \n",count);
    return count;
}

//统计各分数段的学生人数以及所占的百分比

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