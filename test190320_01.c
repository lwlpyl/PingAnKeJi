/**
ƽ���Ƽ�2019���м�������

��һ��
����������m�� �������������������С������n��
������0<i,j<m��i��=j����n^i%m != n^j%m�� 

˼·����1��m-1����n���ҳ���һ������������n�� 
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

//�ж��Ƿ�Ϊ����
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
