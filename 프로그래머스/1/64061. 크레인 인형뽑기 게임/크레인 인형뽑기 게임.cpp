// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isSameElement(stack<int> st, const int& e)
{
    if (st.empty()) return false;
    
    if (st.top() == e) return true;
    
    return false;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> crane;
    int answer = 0;
    
    for (auto e : moves)
    {
        for (int i = 0; i < board.size(); i++)
        {
            int target = board[i][e-1];
            if (target != 0)
            {
                if (isSameElement(crane, target))
                {
                    crane.pop();
                    answer++;
                    answer++;
                }
                else 
                {
                    crane.push(target);
                }
                board[i][e-1] = 0;
                break;
            }
        }
        
    }
    return answer;
}