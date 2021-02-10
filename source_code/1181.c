*/==============================================================================================================================================================================
문제 1181
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로

첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
==============================================================================================================================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct str_info{
    char str[51];
    int length;
}str_info;

struct str_info info_arr[200000];

int compare(const void* a,const void* b){
    //길이순으로 정렬하고 길이가 같으면 사전순으로
    struct str_info *s1 = (str_info *)a;
    struct str_info *s2 = (str_info *)b;

    if(s1->length > s2->length) return 1;
    else if(s1->length < s2->length) return -1;
    else if(s1->length == s1->length){
        if(strcmp(s1->str,s2->str) > 0)
            return 1;
        if(strcmp(s1->str,s2->str) < 0)
            return -1;
    }
    return 0;
}

void sort(int n){
    //정렬
    qsort(info_arr,n,sizeof(str_info),compare);
    for(int i=0;i<n;i++){
        if(info_arr[i].length == 0)
            continue;
        printf("%s\n",info_arr[i].str);
    }
}

int check(char* str,int n){
    for(int i=0;i<n;i++){
        if(strcmp(info_arr[i].str,str)==0 && info_arr[i].length == strlen(str))
            return 1;
    }   
    return 0;
}

int main(){
    int n;
    char temp[51];
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",temp);
        if(check(temp,i))
            continue;
        strcpy(info_arr[i].str,temp);
        info_arr[i].length = strlen(temp); 
    }
    sort(n);

    return 0;
}
