/*========================================================================================
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
======================================================================================*/
#include <stdio.h>
int arr[8];
int visit[9];

void back_tracking(int n, int m, int d, int index){
    if(m==d){
        for(int i=0;i<m;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=index+1 ;i<=n;i++){
        if(!visit[i]){
            visit[i] =1;
            arr[d] = i;
            back_tracking(n,m,d+1,i);
            visit[i] = 0;
        }
        
    }
    return;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    back_tracking(n,m,0,0);
    return 0;
}


/*
visit[1] = 1
arr[0] = 1
                        back_tracking(4,2,1,1)
                        2 != 1
                        i=2
                        visit[2] = 1
                        arr[1]=2
                                                back_tracking(4,2,2,2)
                                                2 == 2
                                                arr[0] arr[1] (1 2)
                        visit[2] = 0

                        i=3
                        visit[3] = 1
                        arr[1] = 3
                                                back_tracking(4,2,2,2)
                                                 2 == 2
                                                arr[0] arr[1] (1 3)

                        visit[3]=0

                        i=4
                        visit[4]=1
                        arr[1] = 4
                                                back_tracking(4,2,2,2)
                                                 2 == 2
                                                arr[0] arr[1] (1 4)

                        visit[4]=0

visit[1] = 0

i=2
visit[2] = 1
arr[0] = 2
                        back_tracking(4,2,1,2)
                        2 != 1
                        i=3
                        visit[3]=1
                        arr[1]=3
                                                back_tracking(4,2,2,3)
                                                2 == 2
                                                arr[0] arr[1] (2,3)
                        visit[3]=0

                        i=4
                        visit[4]=1
                        arr[1]=4
                                                back_tracking(4,2,2,3)
                                                2==2
                                                arr[0] arr[1] (2,4)
                        visit[4] = 0;

visit[2]=0
i=3
visit[3]=1
arr[0]=3
                        back_tracking(4,2,1,3)
                        2 != 1
                        i=4
                        visit[4] = 1
                        arr[1] = 4
                                                back_tracking(4,2,1,4)
                                                arr[0] arr[1] (3,4)
                        visit[4] = 0
visit[3] = 0
*/
