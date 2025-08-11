#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> students (n+1, 1);
    
    for (auto& l : lost)
    {
        students[l]--;
    }
    
    for (auto& r : reserve)
    {
        students[r]++;
    }
    
    for (int i=1; i<n+1; i++)
    {
        if (students[i] == 0)
        {
            if (i != 1 && students[i+1] == 2 && students[i-1] == 2)
            {
                students[i] = 1;
                students[i-1]--;
            }
            else if (i != 1 && students[i-1] == 2)
            {
                students[i] = 1;
                students[i-1]--;
            }
            else if (i != n && students[i+1] == 2)
            {
                students[i] = 1;
                students[i+1]--;
            }
            
            
        }
    }
    
    int cnt = count(students.begin()+1, students.end(), 0);
    
    //for (int i=1; i<n+1; i++)
        //cout << students[i];
    
    return n-cnt;
}