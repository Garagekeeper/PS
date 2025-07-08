#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;
vector<int> costsvec;

int Find(int x)
{
    if (parents[x] == x)
        return (x);
    return Find(parents[x]);
}

void Union(int a, int b, int& answer, int& cost) 
{
    int A = Find(a);
    int B = Find(b);
    
    if (A!=B)
    {
        if (A < B) 
            parents[B] = A;
        else 
            parents[A] = B;
        answer += cost;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    parents = vector<int>(100);
    costsvec = vector<int>(100,0);
    
    for (int i=0; i<n; i++)
    {
        parents[i] = i;
    }
    
    sort(costs.begin(), costs.end() ,[](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });
    
    for (int i = 0; i < costs.size(); ++i)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        int cost = costs[i][2];
        
        Union(a,b,answer,cost);
    }
    
    return answer;
}