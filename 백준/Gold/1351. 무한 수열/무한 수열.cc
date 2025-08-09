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
    if (cache.find(num) != cache.end()) return cache[num];
    return cache[num] = dfs(num/P) + dfs(num/Q);
}

int main()
{
    cin >> N >> P >> Q;
    
    cache[0] = 1;
    cache[1] = 2;
    
    long long res = dfs(N);
    cout << res << '\n';

}