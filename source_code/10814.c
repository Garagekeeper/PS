/*============================================================================================================================================================================
문제 10814
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 
정렬하는 프로그램을 작성하시오.

첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고,
 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.
째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.
============================================================================================================================================================================*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct member_info{
    char str[101];
    int age;
}member_info;

struct member_info info_arr[100000];
struct member_info temp_arr[100000];

//합병정렬
void merge(int front, int mid, int rear) {
	int frArr = front, frTemp = front;
	int midpp = mid + 1;

	while (frArr <= mid && midpp <= rear) {
		if (info_arr[frArr].age <= info_arr[midpp].age) {
			temp_arr[frTemp++] = info_arr[frArr++];
		}
		else {
			temp_arr[frTemp++] = info_arr[midpp++];
		}
	}

	if (frArr > mid) {
		for (int i = midpp; i <= rear; i++)
			temp_arr[frTemp++] = info_arr[i];
	}
	else if (midpp > rear) {
		for (int i = frArr; i <= mid; i++)
			temp_arr[frTemp++] =info_arr[i];
	}

	for (int i = front; i <= rear; i++) {
		info_arr[i] = temp_arr[i];
	}

}

void merge_sort(int front, int rear) {
	int mid;
	if (front < rear) {
		mid = (front + rear) / 2;
		merge_sort(mid + 1, rear);
		merge_sort(front, mid);
		merge(front, mid, rear);
	}
}

void printArr(int n) {
	for (int i = 0; i < n; i++)
		printf("%d %s\n", info_arr[i].age,info_arr[i].str);
}

int main(){
    
    int n;
    char temp[101];
    int tmpnum;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %s",&tmpnum,temp);
        strcpy(info_arr[i].str,temp);
        info_arr[i].age = tmpnum; 
    }
    merge_sort(0, n - 1);
    printArr(n);
    return 0;
}
