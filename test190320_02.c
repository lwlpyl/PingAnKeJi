/**
ƽ���Ƽ�2019���м�������

�ڶ���
�ڰ����ĵذ壬��ĳһ����������������������ĸ�����ǰ����
ֻ��������ɫ���ӣ�������ܵ�����ٸ���ɫ���ӡ� 
���룺
=��ʾ��ɫ����
#��ʾ��ɫ����
@��ʾ���
�����
������ 

˼·�����ϱ����ַ����飬����ǰ���Խ���ĸ��ӱ�Ϊ'y'��ֱ��û�п��������ĸ��ӣ����ͳ��'y'�ĸ����� 
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
	int flag; //�Ƿ����仯 
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
				// ��
				ii = i;
				jj = j-1;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
				// ��
				ii = i;
				jj = j+1;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
				// ��
				ii = i-1;
				jj = j;
				if(check(input, count, ii, jj)==1){
					input[i][j] = 'y';
					flag = 1;
				}
				// �� 
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
