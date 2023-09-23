#include <cstdio>
long long max=-1001, sum;
int N, val;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &val);
		sum += val;
		if (sum > max) max = sum;
		if (sum < 0) sum = 0;
	}
	printf("%lld", max);


	return 0;
}