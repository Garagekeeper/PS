#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct FileName
{
    string Head;
    string Number;
    string Tail;
};

bool cmp(const FileName a, const FileName b)
{
    string Ahead = a.Head;
    string Bhead = b.Head;
    transform(Ahead.begin(), Ahead.end(), Ahead.begin(), ::toupper);
    transform(Bhead.begin(), Bhead.end(), Bhead.begin(), ::toupper);

    if (Ahead == Bhead)
    {
        int A = stoi(a.Number);
        int B = stoi(b.Number);
        return A < B;
    }
    return Ahead < Bhead;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileName> fileNameVec;
    
    for (auto& file : files)
    {
        string head = "";
        string number = "";
        string tail = "";
        bool headDone = false;
        bool numberDone = false;
        for (auto it = file.begin(); it != file.end(); ++it)
        {
            if ('0'<= *it && *it <= '9')
                headDone = true;
            if (headDone && !('0'<= *it && *it <= '9'))
                numberDone = true;
            
            if (!headDone)
            {
                head += *it;
            }
            else if (!numberDone)
            {
                number += *it;
            }
            else
            {
                tail += *it;
            }
        }
        fileNameVec.push_back({head, number, tail});
    }
    
    stable_sort(fileNameVec.begin(), fileNameVec.end() ,cmp);
    for (auto& fn : fileNameVec)
    {
        string temp = "";
        temp += fn.Head;
        temp += fn.Number;
        temp += fn.Tail;
        answer.push_back(temp);
    }
    return answer;
}