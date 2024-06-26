#include <iostream>
#include <stack>
using namespace std;

struct e { int h, cnt; };

int N;
stack<e> st;

long long ans = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		int cnt = 1;
		cin >> temp;
		while (!st.empty() && st.top().h <= temp)
		{
			ans += st.top().cnt;
			if (st.top().h == temp) cnt += st.top().cnt;
			st.pop();
		}

		if (!st.empty()) ans++;
		st.push({ temp, cnt });
	}

	cout << ans << "\n";


	return 0;
}