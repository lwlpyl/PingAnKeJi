/**
平安科技2019春招技术笔试

第一题
输入正整数m， 输出满足如下条件的最小正整数a：
对任意0<i,j<m且i！=j，有a^i%m != a^j%m

思路：大数取余法，a*b%n=(a%n*b%n)%n防止溢出 
**/

#include<stdio.h>

#define N 100000

// 计算x^y%m 递归实现 
int getM(int x, int y, int m) {
	int temp1, temp2;
	int i;
	if(y==1){
		return x%m;
	} 
	temp1 = getM(x, y/2, m);
	temp2 = getM(x, y-y/2, m);
	return (temp1*temp2)%m;
}

// 计算x^y%m 非递归实现 
int getM2(int x, int y, int m) {
	int temp = 1;
	int i;
	for(i=0; i<y; i++){
		temp *= x;
		temp %= m;
	} 
	return temp;
}

int check(int res[], int m) {
	int i, j;
	for(i=1; i<m; i++) {
		for(j=1; j<m; j++) {
			if(res[i]==res[j]&&i!=j) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int m, a, ans=-1;
	int i;
	int res[N];

	scanf("%d", &m);

	for(a=2; a<m; a++) {
		for(i=1; i<m; i++) {
			res[i] = getM2(a, i, m);
		}
		if(check(res, m)==1) {
			ans = a;
			break;
		}
	}

	printf("%d", ans);
	return 0;
}
