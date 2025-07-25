#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector<pair<int,int>> housePosVec;
vector<pair<int,int>> chickenPosVec;
vector<bool> chickenVisited;
vector<pair<int,int>> selectedList;
int N,M;
int answer = INT_MAX;

int CalcChickenDist(const int& x1,const int& y1,const int& x2,const int& y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int CalcMinChickenDist(const vector<pair<int,int>>& selectedList)
{
    int toatal_dist = 0;
    for (auto& [houseX, houseY] : housePosVec)
    {
        if (toatal_dist >= answer) return INT_MAX;
        int min_of_current_house = INT_MAX;
        for (auto& [chickenX, chickenY] : selectedList)
        {
            int dist = CalcChickenDist(houseX, houseY, chickenX, chickenY);
            min_of_current_house = min(min_of_current_house, dist);
        }
        toatal_dist += min_of_current_house;
    } 
    return toatal_dist;
}

void dfs(int before ,int index)
{
    int minchckdist = 0;
    if (selectedList.size() > M) return;

    if (selectedList.size() == M)  
    {
    minchckdist = CalcMinChickenDist(selectedList);
    answer = min(answer, minchckdist);
    return;
    }

    for (int i = index; i < chickenPosVec.size(); i++)
    {
        if (chickenVisited[i]) continue;
        chickenVisited[i] = true;
        selectedList.push_back(chickenPosVec[i]);
        dfs(minchckdist, i+1);
        selectedList.pop_back();
        chickenVisited[i] = false;
    }
}



int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int val;
            cin >> val;
            if (val == 1)
            {
                housePosVec.push_back({i,j});
            }
            else if (val == 2)
            {
                chickenPosVec.push_back({i,j});
            }
        }
    }

    chickenVisited.resize(13, false);
    dfs(0,0);
    cout << answer << endl;

}