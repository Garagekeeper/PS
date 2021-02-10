#include <stdio.h>
char* str[][51];

void sort(int n){
    int i=0;
    while(i<n){
        printf("%s\n",str[i]);
        i++;
    }

}

int main(){
    
    int n;

    scanf("%d",&n);
    fflush(stdin);
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    sort(n);

    return 0;
}
