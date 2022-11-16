#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	
	srand(time(NULL));
	int a[4]={0}; //记录计算机生成的各位不相同的4位数 
	int b[4]={0}; //记录用户输入的4位数
	//随机生成4位数 
	a[0]=rand()%10;
	do{
		a[1]=rand()%10;  //生成第二位数，如果第二位与第一位相同，则重新生成，直到不同 
	}while(a[0]==a[1]);
	do{
		a[2]=rand()%10;  //生成第三位数，如果第三位与第一位或第二位相同，则重新生成，直到不同 
	}while(a[0]==a[2]||a[1]==a[2]);
	do{
		a[3]=rand()%10;  //生成第四位.............(如上 
	}while(a[0]==a[3]||a[1]==a[3]||a[2]==a[3]);
	printf("您想猜多少次?:");
	int times; //用户可以猜测的次数 
	scanf("%d",&times);
	printf("\n");
	int count =0;//用户猜测的次数 
	do{
		int ret =0;
	 	count ++;
		printf("请输入各位不同的4位数:");
		do{
			scanf("%d%d%d%d",&b[0],&b[1],&b[2],&b[3]);
			if(b[0]==b[1]||b[0]==b[2]||b[0]==b[3]||b[1]==b[2]||b[1]==b[3]||b[2]==b[3]){
				printf("请输入各位不同的4位数");
				ret=0;
			}else{
				ret=1;
			}
		}while(ret!=1);
		
		
		//数字和位置都猜对的个数
		int right=0;
		int j=0;
		int k=0;
		for(j=0;j<4;++j){
			if(b[j]==a[j]){
				right+=1;
			}
		}
		int w=right;
		//数字猜对的个数
		int right2=0;
		for(j=0;j<4;++j){
			for(k=0;k<4;++k){
				if(b[j]==a[k]){
					right2+=1;
				}
			}
		} 
		right2=right2-right;
		printf("%dA%dB",right,right2);	
	} while(count<times);
	 if(right==4){
		printf("Congratulations! %d times\n",count);
	}else{
		printf("Sorry,you haven't guess the right number!\n ");
	}
	
	
	return 0;
}