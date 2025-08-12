#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

//이게 머임 ㄷㄷ
//지니어스 들이네
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<int> vec(N);
    for (int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (auto& v : vec)
    {
        if (ans + 1 < v)
            break;
        ans += v;
    }

    cout << ans+1 << '\n';

    return 0;
}
