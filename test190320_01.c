/**
ƽ���Ƽ�2019���м�������

��һ��
����������m�� �������������������С������a��
������0<i,j<m��i��=j����a^i%m != a^j%m

˼·������ȡ�෨��a*b%n=(a%n*b%n)%n��ֹ��� 
**/

#include<stdio.h>

#define N 100000

// ����x^y%m �ݹ�ʵ�� 
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

// ����x^y%m �ǵݹ�ʵ�� 
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
