#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> inorder;
vector<int> postorder;

void solution(int in_left, int in_right, int post_left, int post_right)
{
    int l1,r1;
    int l2,r2;
    if (in_left > in_right) return;
    if (post_left > post_right) return;

    cout << postorder[post_right] << " ";

    int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), postorder[post_right]));
    int leftSize= index - in_left;

    solution(in_left, index - 1, post_left, post_left + leftSize - 1 );
    solution(index + 1, in_right, post_left + leftSize, post_right - 1);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    for (int i = 0; i < N ; i++)
    {
        int temp;
        cin >> temp;
        inorder.push_back(temp);
    }

    for (int i = 0; i < N ; i++)
    {
        int temp;
        cin >> temp;
        postorder.push_back(temp);
    }

    solution(0,inorder.size() - 1, 0, postorder.size() - 1);
    return 0;
}
