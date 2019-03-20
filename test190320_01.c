/**
平安科技2019春招技术笔试

第一题
输入正整数m， 输出满足如下条件的最小正整数a：
对任意0<i,j<m且i！=j，有a^i%m != a^j%m

思路：从1到m-1遍历，找出第一个满足条件的a，如都不满足，则返回-1。
考试的时候没有考虑int溢出的问题，导致只有通过了40%的测试用例。
**/

#include<stdio.h>

#define N 100000

// 计算x^y%m，运用公式a*b%n=(a%n*b%n)%n防止int溢出
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
			res[i] = getM(a, i, m);
		}
		if(check(res, m)==1) {
			ans = a;
			break;
		}
	}

	printf("%d", ans);
	return 0;
}
