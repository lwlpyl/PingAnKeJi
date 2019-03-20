/**
平安科技2019春招技术笔试

第二题
黑白相间的地板，从某一点出发，可以延上下左右四个方向前进，
只允许进入黑色格子，问最多能到达多少个黑色格子。 
输入：
=表示黑色格子
#表示白色格子
@表示起点
输出：
正整数 

思路：不断遍历字符数组，将当前可以进入的格子标为'y'，直至没有可以新增的格子，最后统计'y'的个数。 
**/

#include<stdio.h>
#include<string.h>

#define N 100
#define M 20

int check(char s[][M], int count, int i, int j){
	if(i>=0 && i<=count && j>=0 && j<strlen(s[i]) && s[i][j]=='y'){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int ans;
	char input[N][M];
	int i, j, count;
	int flag; //是否发生变化 
	int ii, jj;
	
	count = 0;
	while(1){
		scanf("%s", input[count]);
		if(strcmp(input[count], "end")==0){
			break;
		}
		count++;
	}
	
	while(1){
		flag = 0;
		for(i=0; i<count; i++){
			for(j=0; input[i][j]!='\0'; j++){
				if(input[i][j]=='#' || input[i][j]=='y'){
					continue;
				}
				if(input[i][j]=='@'){
					input[i][j]='y';
					flag = 1;
					continue;
				}
				// 上
				ii = i;
				jj = j-1;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
				// 下
				ii = i;
				jj = j+1;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
				// 左
				ii = i-1;
				jj = j;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
				// 右 
				ii = i+1;
				jj = j;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
			}
		}
		if(flag==0){
			break;
		}
	} 
	
	ans = 0;
	for(i=0; i<count; i++){
		for(j=0; input[i][j]!='\0'; j++){
			if(input[i][j]=='y'){
				ans++;
			}	
		}
	}
	
	printf("%d", ans);
	return 0;
}
