#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define N 3  //5��Ԫ�ذ������Ƴɼ��Լ�ƽ���ֺ��ܷ� 

void Menu(int num[],int score[][N],float sum[],float aver[],int paim[]);
void GetIn(int num[],int score[][N],int n);
void GetSumAver(int num[],int score[][N],float sum[],float aver[],int n);
void ToptoEnd(int num[],int score[][N],float sum[],float aver[],int n,int paim[]);
void OutPut(int num[],int score[][N],float sum[],float aver[],int n,int paim[]);
void Found(int num[],int score[][N],float sum[],float aver[],int n,int num1,int paim[]);

int main(){
	
	int score[MAX][N]={0};//��ʼ���ɼ���ά���� 
	int num[MAX]={0}; //��ʼ��ѧ�����飬�������Ϊ30 
	float sum[MAX]={0}; //��ʼ�������ܷ�����
	float aver[MAX]={0};//��ʼ������ƽ��������
	int paim[MAX]={0};
	
	while(1){
		Menu(num,score,sum,aver,paim);
		printf("\n");
	}
    system("pause");
	
	return 0;
}





//1.����ѧ���ɼ�����
void GetIn(int num[],int score[][N],int n){  //nΪѧ������ //num[]Ϊѧ��ѧ������ 

	int i=0;//��Ԫ�أ�����ѧ�� 
	int j=0;//��Ԫ�أ�������Ƴɼ���ͬʱֻ�����ƣ�����Ϊ0-2
	
	for(i=0;i<n;++i){
			
			printf("������ ��%dλ ѧ��ѧ��:",i+1);
			scanf("%d",&num[i]);
			
			printf("�ֱ����� ��ѧ Ӣ�� ���� �ɼ�:"); 
			for(j=0;j<N;++j){	
				scanf("%d",&score[i][j]);
			}
            
	}

} 

//2.����ѧ���ֺܷ�ƽ���� 
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

//3.���ֳܷɼ��Ӹߵ����ų��ɼ����� 

void ToptoEnd(int num[],int score[][N],float sum[],float aver[],int n,int paim[]){
	
	int i=0;
	int j=0;
	int k=0;
	float temp1[MAX]={0};
	int temp2[MAX]={0};
	float temp3[MAX]={0};
	float temp4[MAX][N]={0}; 
	for (j=0;j<n;++j){
        for(i=0;i<n-j-1;++i){  //ð������
            if(sum[i+1]>sum[i]){
			temp1[i]=sum[i]; //�ܳɼ����� 
			sum[i]=sum[i+1];
			sum[i+1]=temp1[i];
			
			temp2[i]=num[i]; //ѧ�Ż��� 
			num[i]=num[i+1];
			num[i+1]=temp2[i];
			
			temp3[i]=aver[i]; //ƽ���ֻ��� 
			aver[i]=aver[i+1];
			aver[i+1]=temp3[i];
			
			for(k;k<N;++k){
				temp4[i][k]=score[i][k]; //���ƻ��� 
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

//���
void OutPut(int num[],int score[][N],float sum[],float aver[],int n,int paim[]){
	
	
	int i,j;
	printf("-------------------------------------------\n");
	printf("ѧ�����\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\t����\n");
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

//����ѧ�Ų���ѧ��

void Found(int num[],int score[][N],float sum[],float aver[],int n,int num1,int paim[]){

	int i;
	int j;
	int ret=-1;  //��ʶ���������������Ϊ-1�����������Ϊ1��
	for(i=0;i<n;i++){
		if (num[i]==num1){
			ret=1;
			break;
		}
	}
	
	if(ret==1){
		printf("-------------------------------------------\n");
		printf("ѧ�����\t��ѧ\tӢ��\t����\t�ܷ�\tƽ����\t����\n");
		printf("-------------------------------------------\n");
		printf("%d\t",num[i]);
		for(j=0;j<N;++j){
			printf("\t%d",score[i][j]);
		}
		printf("\t%.2lf\t%.2lf\t%d",sum[i],aver[i],paim[i]);
		printf("\n");
	}else {
		printf("���޴���!\n");
	}
	

}

//�˵�
void Menu(int num[],int score[][N],float sum[],float aver[],int paim[]){
	int c;
	printf("---------�˵�---------\n");
	printf("---   1.�ɼ�¼��   ---\n");
	printf("---   2.�ɼ�����   ---\n");
	printf("---   3.�ɼ�����   ---\n");
	printf("---   4.�ɼ���ʾ   ---\n");
	printf("---   5.�˳�       ---\n");
	printf("----------------------\n");
	printf("������������еĲ���:");
	scanf("%d",&c);
	int n;
	int num1;
	switch (c)
	{
	case 1:
		printf("������ѧ������:");
		scanf("%d",&n);
		GetIn(num,score,n);
		break;
	case 2:
		if(num[0]==0){
			printf("δ������");
			break;
		}else{
			GetSumAver(num,score,sum,aver,n);
			ToptoEnd(num,score,sum,aver,n,paim);
			printf("����ɹ�!\n");
			break;
		}
		
	case 3:
		printf("����������Ҫ���ҵ�ѧ�����:");
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

