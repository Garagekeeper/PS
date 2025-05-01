#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    priority_queue<int> pq;
    queue<int> tempQueue;

    int T;
    int M;

    cin >> T;

    int inputInt;
    int outputCount;

    for (int i=0; i < T; i++)
    {
        cin>>M;
        outputCount = M % 2 == 0 ? M / 2 : (M / 2) + 1;
        cout << outputCount << endl;
        pq = priority_queue<int>();
        int outCnt = 1;
        for (int j = 1; j <= M; j++)
        {
            cin >> inputInt;
            pq.push(inputInt);

            if (j % 2 == 1)
            {
                for (int k = 0; k < j/2 ; k++)
                {
                    tempQueue.push(pq.top());
                    pq.pop();
                    // cout << "k: " << k <<endl;
                    // cout << "j: " << j <<endl;
                    // cout << "j/2: " << j/2 <<endl;
                }

                cout << pq.top() << " ";
                outCnt++;

                if ( outCnt > 10 )
                {
                    outCnt = 1;    
                    cout << endl;
                } 

                while(!tempQueue.empty())
                {
                    pq.push(tempQueue.front());
                    tempQueue.pop();
                }
            }
        }
    }
    return 0;
}