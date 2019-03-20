/**
平安科技2019春招技术笔试

第一题
输入正整数m， 输出满足如下条件的最小正整数n：
对任意0<i,j<m且i！=j，有n^i%m != n^j%m。 

思路：从1到m-1遍历n，找出第一个满足条件的n。 
**/
#include<stdio.h>
#include<math.h>

#define N 100000

int check(int res[], int m){
	int i, j;
	for(i=1; i<m; i++){
		for(j=1; j<m; j++){
			if(res[i]==res[j]&&i!=j){
				return 0;
			}
		}
	}
	return 1;
}

//判断是否为素数
int isSu(int x){
	int i;
	if(x<2){
		return 0;
	}
	for(i=2; i<x; i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
} 

int main(){
	int m, a, ans=-1;
	int i; 
	int res[N];
	
	scanf("%d", &m);
	
	if(isSu(m)==0){
		ans = -1;
	}else{
		for(a=2; a<m; a++){
			for(i=1; i<m; i++){
				res[i] = ((int)pow(a, i))%m;
			}
			if(check(res, m)==1){
				ans = a;
				break;
			}
		}
	}
	
	printf("%d", ans);
	return 0;
} 
