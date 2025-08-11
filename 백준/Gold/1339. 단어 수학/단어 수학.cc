#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

int N;
vector<string> strVec;
unordered_map<char, int> C2Itable;
unordered_map<char, int> charCnt;
unordered_map<char, long long> posWeight;
set<char> alphabet;
// 길이가 긴게 남은 숫자중에 큰걸 가져가자!
// 길이가 같으면 많이 나온 알파뱃한테 큰 수를 주자
int main()
{
    cin >> N;
    int maxLen = 0;
    for (int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        strVec.push_back(str);
        int len = strVec[i].size();
        
        long long weight = 1;
        
        for (int j = len - 1; j >= 0; j--) {
            alphabet.insert(strVec[i][j]);
            posWeight[strVec[i][j]] += weight;
            weight *= 10;
        }
    }

    
    vector<bool> numVisited(10);
    vector<char> sortedvec(alphabet.begin(), alphabet.end());
    sort(sortedvec.begin(), sortedvec.end(), [&](const char& a, const char& b) {
        return posWeight[a] > posWeight[b];
    });
    for (auto& a : sortedvec) 
    {
        for (int num = 9; num >= 0; num--) 
        {
            if (!numVisited[num]) 
            {
                numVisited[num] = true;
                C2Itable[a] = num;
                break;
            }
        }
    }

    long long answer = 0;
    for (auto &s : strVec) {
        long long val = 0;
        for (char c : s) {
            val = val * 10 + C2Itable[c];
        }
        answer += val;
    }

    cout << answer << "\n";
    return 0;
}
