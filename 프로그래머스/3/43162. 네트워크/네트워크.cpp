#include <string>
#include <vector>

using namespace std;
vector<int> parents;
vector<int> ranks;


int find(int x)
{
    if (x == parents[x]) return x;
    return parents[x] = find(parents[x]);
}

void merge(int a, int b)
{
    int A = find(a);
    int B = find(b);
    
    if (A != B)
    {
        if (ranks[A] > ranks[B])
        {
            parents[B] = A;
        }
        else if (ranks[A] < ranks[B])
        {
            parents[A] = B;
        }
        else
        {
            parents[B] = A;
            ranks[A]++;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // 초기상태
    // 자신의 부모는 자기 자신
    ranks.resize(n,1);
    for (int i=0; i< n; i++)
    {
        parents.push_back(i);
    }
    
    // 간선의 두 노드를 union
    for (int i = 0; i < n; i++)
    {
        for (int j=0; j < n ; j++)
        {
            if (i == j) continue;
            if (computers[i][j] == 1)
            {
                merge(i , j);
            }
            
        }
    }
    
    //루트 노드의 개수가 네트워크의 개수
    for (int i=0; i< n; i++)
    {
        if (find(i) == i) answer++;
    }
    
    return answer;
}

/*

2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
#include <string>
#include <vector>

using namespace std;

void DFS(int from, int n, vector<int> &visited, vector<vector<int>> &computers) {

    for (int i = 0; i < n; i++) {
        if (from != i && computers[from][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    int network = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i <n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        // visit node and start DFS
        network++;
        visited[i] = 1;

        DFS(i, n, visited, computers);
    }

    return network;
}
*/