#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> dayQueue;
    for (int i=0; i<progresses.size(); i++)
    {
        int Todo = 100 - progresses[i];
        int requiredDay = ( Todo / speeds [i]) + (Todo % speeds[i] != 0 ? 1 : 0);
        
        dayQueue.push(requiredDay);
    }
    
    int count = 0;
    int front;
    
    while(!dayQueue.empty())
    {
        front = dayQueue.front();
        dayQueue.pop();
        count = 1;
        
        cout << front << endl;
        while(!dayQueue.empty() && front >= dayQueue.front())
        {
            dayQueue.pop();
            count++;
        }
        
        answer.push_back(count);
    }
    
    
    return answer;
}