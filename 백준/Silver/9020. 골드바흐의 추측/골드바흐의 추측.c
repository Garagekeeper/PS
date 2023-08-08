#include <stdio.h>

int arr[10001]={0,};

void Eratos(){
	for(int i=2;i<10000;i++){
		for(int j= 2*i;j<10000;j+=i)
			arr[j] = 1;
	}
}

void Goldbach_Patition(int n){
	int a,b;
	a=b=n/2;
	while(1){
		if( (arr[a] == 0 && arr[b] ==0) && a+b==n)
			break;
		else{
			a--,b++;
		}
	}
	printf("%d %d\n",a,b);

}

int main(){
	int t,n;
	scanf("%d",&t);
	Eratos();
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		Goldbach_Patition(n);
	}
	
	return 0;
}