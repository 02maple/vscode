#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define N 3  //5个元素包括三科成绩以及平均分和总分 

void Menu(int num[],int score[][N],float sum[],float aver[],int paim[]);
void GetIn(int num[],int score[][N],int n);
void GetSumAver(int num[],int score[][N],float sum[],float aver[],int n);
void ToptoEnd(int num[],int score[][N],float sum[],float aver[],int n,int paim[]);
void OutPut(int num[],int score[][N],float sum[],float aver[],int n,int paim[]);
void Found(int num[],int score[][N],float sum[],float aver[],int n,int num1,int paim[]);

int main(){
	
	int score[MAX][N]={0};//初始化成绩二维数组 
	int num[MAX]={0}; //初始化学号数组，人数最多为30 
	float sum[MAX]={0}; //初始化个人总分数组
	float aver[MAX]={0};//初始化个人平均分数组
	int paim[MAX]={0};
	
	while(1){
		Menu(num,score,sum,aver,paim);
		printf("\n");
	}
    system("pause");
	
	return 0;
}





//1.输入学生成绩函数
void GetIn(int num[],int score[][N],int n){  //n为学生个数 //num[]为学生学号数组 

	int i=0;//行元素，代表学生 
	int j=0;//列元素，代表各科成绩，同时只有三科，所以为0-2
	
	for(i=0;i<n;++i){
			
			printf("请输入 第%d位 学生学号:",i+1);
			scanf("%d",&num[i]);
			
			printf("分别输入 数学 英语 物理 成绩:"); 
			for(j=0;j<N;++j){	
				scanf("%d",&score[i][j]);
			}
            
	}

} 

//2.计算学生总分和平均分 
void GetSumAver(int num[],int score[][N],float sum[],float aver[],int n){
	
	int i=0;
	int j=0;
    
	for(i=0;i<n;i++){
        int sum1=0;
		for(j=0;j<N;j++){
			sum1+=score[i][j];
            
		}
        sum[i]=sum1;
		aver[i]=sum[i]/N;
	}
	
}

//3.按总分成绩从高到低排出成绩名次 

void ToptoEnd(int num[],int score[][N],float sum[],float aver[],int n,int paim[]){
	
	int i=0;
	int j=0;
	int k=0;
	float temp1[MAX]={0};
	int temp2[MAX]={0};
	float temp3[MAX]={0};
	float temp4[MAX][N]={0}; 
	for (j=0;j<n;++j){
        for(i=0;i<n-j-1;++i){  //冒泡排序
            if(sum[i+1]>sum[i]){
			temp1[i]=sum[i]; //总成绩互换 
			sum[i]=sum[i+1];
			sum[i+1]=temp1[i];
			
			temp2[i]=num[i]; //学号互换 
			num[i]=num[i+1];
			num[i+1]=temp2[i];
			
			temp3[i]=aver[i]; //平均分互换 
			aver[i]=aver[i+1];
			aver[i+1]=temp3[i];
			
			for(k;k<N;++k){
				temp4[i][k]=score[i][k]; //各科互换 
				score[i][k]=score[i+1][k];
				score[i+1][k]=temp4[i][k];
				
			}
		  }
        }	
	}	
	for(i=0;i<n;i++){
		paim[i]=i+1;
	}
}

//输出
void OutPut(int num[],int score[][N],float sum[],float aver[],int n,int paim[]){
	
	
	int i,j;
	printf("-------------------------------------------\n");
	printf("学生编号\t数学\t英语\t物理\t总分\t平均分\t排名\n");
	printf("-------------------------------------------\n");
	for(i=0;i<n;++i){
		printf("%d\t",num[i]);
		for(j=0;j<N;++j){
			printf("\t%d",score[i][j]);
		}
		printf("\t%.2lf\t%.2lf\t%d",sum[i],aver[i],paim[i]);
		printf("\n");
	}
	
} 

//输入学号查找学生

void Found(int num[],int score[][N],float sum[],float aver[],int n,int num1,int paim[]){

	int i;
	int j;
	int ret=-1;  //标识符，如果不存在则为-1，如果存在则为1；
	for(i=0;i<n;i++){
		if (num[i]==num1){
			ret=1;
			break;
		}
	}
	
	if(ret==1){
		printf("-------------------------------------------\n");
		printf("学生编号\t数学\t英语\t物理\t总分\t平均分\t排名\n");
		printf("-------------------------------------------\n");
		printf("%d\t",num[i]);
		for(j=0;j<N;++j){
			printf("\t%d",score[i][j]);
		}
		printf("\t%.2lf\t%.2lf\t%d",sum[i],aver[i],paim[i]);
		printf("\n");
	}else {
		printf("查无此人!\n");
	}
	

}

//菜单
void Menu(int num[],int score[][N],float sum[],float aver[],int paim[]){
	int c;
	printf("---------菜单---------\n");
	printf("---   1.成绩录入   ---\n");
	printf("---   2.成绩排序   ---\n");
	printf("---   3.成绩查找   ---\n");
	printf("---   4.成绩显示   ---\n");
	printf("---   5.退出       ---\n");
	printf("----------------------\n");
	printf("请输入您想进行的操作:");
	scanf("%d",&c);
	int n;
	int num1;
	switch (c)
	{
	case 1:
		printf("请输入学生人数:");
		scanf("%d",&n);
		GetIn(num,score,n);
		break;
	case 2:
		if(num[0]==0){
			printf("未有数据");
			break;
		}else{
			GetSumAver(num,score,sum,aver,n);
			ToptoEnd(num,score,sum,aver,n,paim);
			printf("排序成功!\n");
			break;
		}
		
	case 3:
		printf("请输入您需要查找到学生编号:");
		scanf("%d",&num1);
		Found(num,score,sum,aver,n,num1,paim);
		break;
	case 4:
		OutPut(num,score,sum,aver,n,paim);
		break;
	case 5:
		exit(0);
	default:
		break;
	}
	

}

