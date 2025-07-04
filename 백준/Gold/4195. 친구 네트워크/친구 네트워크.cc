#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> idOf;
vector<int> parent;
vector<int> sizeOf;

int findSet(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findSet(parent[x]);  // 경로 압축
}

int unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        parent[b] = a;
        sizeOf[a] += sizeOf[b];  // 루트 a에 b의 크기 합침
    }
    return sizeOf[a];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int F;
        cin >> F;

        idOf.clear();
        parent.clear();
        sizeOf.clear();

        parent.resize(2*F + 5);
        sizeOf.resize(2*F + 5);
        int nextId = 0;

        for (int i = 0; i < F; i++) {
            string a, b;
            cin >> a >> b;

            if (!idOf[a]) {
                idOf[a] = ++nextId;
                parent[nextId] = nextId;
                sizeOf[nextId] = 1;
            }
            if (!idOf[b]) {
                idOf[b] = ++nextId;
                parent[nextId] = nextId;
                sizeOf[nextId] = 1;
            }

            int pa = idOf[a], pb = idOf[b];
            int ans = unionSet(pa, pb);
            cout << ans << '\n';
        }
    }
    return 0;
}
