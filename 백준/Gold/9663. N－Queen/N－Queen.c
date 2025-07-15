#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int chess[15]={0,};
int n;
int cnt=0;

int check(int n){
    for(int i=1;i<n;i++){
        if( chess[n] == chess[i] )
            return 0;
        else if( abs(n-i) == abs(chess[n]-chess[i]))
            return 0;
    }
    return 1;
}

int dfs(int x){
    if(x==n)
        cnt++;
    else{
        x++;
        for(int i=1;i<=n;i++){
            chess[x]=i;
            if(check(x))
                dfs(x);
            chess[x]=0;
        }
    }
}

void nQueen(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        chess[1]=i;
        dfs(1);    
    }        
    printf("%d\n",cnt);
}


int main(){
    nQueen();
    return 0;
}
