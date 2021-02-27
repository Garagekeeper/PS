/*========================================================================================
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
======================================================================================*/
#include <stdio.h>
#include <stdlib.h>
//arr[i]=j ===> i행 j열
int arr[15]={0,};
int cnt=0,n;

void nQueen();
void dfs(int row);
int check_con(int col);
void print_result();

int main(){
    nQueen();
    return 0;
}

void nQueen(){
    scanf("%d",&n);
    for(int col=1;col<=n;col++){
        arr[1]=col;
        dfs(1);
    }
    print_result();
}

void dfs(int row){
    if(row == n){
        cnt++;
    }else{
        for(int col=1;col<=n;col++){
            arr[row+1] = col;
            if(check_con(row+1))
                dfs(row+1);
            else
                arr[row+1]=0;
        }
    }
    arr[row+1] = 0;
}

int check_con(int brow){
    for(int row=1;row<brow;row++){
        if(arr[row] == arr[brow])
            return 0;
        if(abs(arr[row]-arr[brow]) ==  abs(row - brow))
            return 0;
    }
    return 1;
}

void print_result(){
    printf("%d\n",cnt);
}
