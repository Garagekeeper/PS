#include <iterator>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int r,c,k;

vector<vector<int>> board(100, vector<int>(100,0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c >> k;
    int cr = 3;
    int cc = 3;

    int eA, eB, eC;
    for (int i=0; i < 3; i++)
    {
        cin >> eA >> eB >> eC;
        board[i][0] = eA;
        board[i][1] = eB;
        board[i][2] = eC;
    }
    


    int sec = 0;
    while (true)
    {
        //if (sec == 2) break;
        if (sec > 100)
        {
            cout << -1 << '\n';
            break;
        }

        if (board[r-1][c-1] == k)
        {
           //cout << r << c << k;
            cout << sec << '\n';
            break;
        }

        unordered_map<int, int> cntMap;
        // R operation
        if (cr >= cc)
        {
           int ccindex = cc;
           int crindex = cr;
           for (int i=0; i < crindex; i++)
           {
                cntMap.clear();
                for (int j=0; j < ccindex; j++)
                {
                    if (board[i][j] == 0 ) continue;
                    cntMap[board[i][j]]++;
                }
                vector<pair<int,int>> forSort (cntMap.begin(), cntMap.end());
                sort(forSort.begin(), forSort.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                    if (a.second == b.second)
                        return a.first < b.first;
                    return 
                        a.second < b.second;
                });

                int j = 0;
                for (j=0; j < forSort.size() && j < 50 ; j++)
                {
                    board[i][2*j] = forSort[j].first;
                    board[i][2*j + 1] = forSort[j].second;
                }

                for (j = forSort.size() * 2; j < ccindex; j++)
                {
                    board[i][j] = 0;
                }

                cc = max(cc , static_cast<int>(forSort.size()) * 2);
                if (cc > 100) cr = 100;
           }
        }
        // C operation
        else if (cr < cc)
        {
           int ccindex = cc;
           int crindex = cr;
           for (int i=0; i < ccindex; i++)
           {
                cntMap.clear();
                for (int j=0; j < crindex; j++)
                {
                    if (board[j][i] == 0 ) continue;
                    cntMap[board[j][i]]++;
                }
                vector<pair<int,int>> forSort (cntMap.begin(), cntMap.end());
                sort(forSort.begin(), forSort.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                    if (a.second == b.second)
                        return a.first < b.first;
                    return 
                        a.second < b.second;
                });

                int j = 0;
                for (j=0; j < forSort.size() && j < 50 ; j++)
                {
                    board[2*j][i] = forSort[j].first;
                    board[2*j + 1][i] = forSort[j].second;
                }

                for (j = forSort.size() * 2; j < crindex; j++)
                {
                    board[j][i] = 0;
                }

                cr = max(cr , static_cast<int>(forSort.size()) * 2);
                if (cr > 100) cr = 100;
           }
        }
        sec++;
    }


    
}