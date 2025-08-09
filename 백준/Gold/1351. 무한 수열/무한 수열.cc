#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long N ;
int P,Q;
unordered_map<long long, long long> cache;

long long dfs(long long num)
{
    if (num==0) return 1;
    if (num==1) return 2;
    if (cache.find(num) != cache.end()) return cache[num];
    return cache[num] = dfs(num/P) + dfs(num/Q);
}

int main()
{
    cin >> N >> P >> Q;

    
    long long res = dfs(N);
    cout << res << '\n';

}