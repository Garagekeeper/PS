#include <string>
#include <vector>
#include <stack>

using namespace std;

int GetK (vector<int>& Index, int value, int k)
{
    int res = k;
    for (int i=0; i<value; i++)
    {
        res = Index[res];
    }
    return res;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> nextIndex;
    vector<int> prevIndex;
    
    for (int i = 0; i < n; i++) 
    {
        prevIndex.push_back(i - 1);
        nextIndex.push_back(i + 1);
    }
    nextIndex[n-1] = -1;
    
    stack<int> deletedIndex;
    
    for (int i=0; i<cmd.size(); i++)
    {
        char cmdType = cmd[i][0];
        if (cmdType == 'U')
        {
            k = GetK(prevIndex, stoi(cmd[i].substr(2)), k);
        }
        else if (cmdType == 'D')
        {
            k = GetK(nextIndex, stoi(cmd[i].substr(2)), k);
        }
        else if (cmdType == 'C')
        {
            int target = k;
            
            //해당 원소 삭제처리
            if (nextIndex[target] != -1)
                prevIndex[nextIndex[target]] = prevIndex[target];
            if (prevIndex[target] != -1)
                nextIndex[prevIndex[target]] = nextIndex[target];
            deletedIndex.push(target);
            
            // 맨 마지막인 경우
            if (nextIndex[k] == -1)
                k = GetK(prevIndex, 1, k);
            else
                k = GetK(nextIndex, 1, k);
        }
        else if (cmdType == 'Z')
        {
            int index = deletedIndex.top();
            deletedIndex.pop();
            
            //원소 복구
            if (nextIndex[index] != -1)
                prevIndex[nextIndex[index]] = index;
            if (prevIndex[index] != -1)
                nextIndex[prevIndex[index]] = index;
        }
    }
    
    for (int i=0; i<n; i++)
    {
        answer.append("O");
    }
    
    while (!deletedIndex.empty())
    {
        answer[deletedIndex.top()] = 'X';
        deletedIndex.pop();
    }
    
    return answer;
}