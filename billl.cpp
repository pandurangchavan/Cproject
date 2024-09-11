#include<stdio.h>
int Vmain(){
	
	int count=101;
	++count;
	return count;	
}
int main(){
	int result=Vmain();
		printf("Bill No:%d",result);
		long long a;
		scanf("%d",&a);
		printf("\n%d",a);
		
	return 0;
}
