#include <iostream>
#include <queue>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while ( T-- ) {

        int N; std::cin >> N;
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int MIDDLE; std::cin >> MIDDLE;
        maxHeap.push(MIDDLE); N >>= 1;


        std::cout << N+1 << '\n';
        std::cout << MIDDLE << ' ';

        for (int iter=1; iter<=N; iter++) {
            int A, B; std::cin >> A >> B;

            int bigger = 0;
            if ( A > MIDDLE ) { minHeap.push(A); bigger++; }
            else { maxHeap.push(A); }

            if ( B > MIDDLE ) { minHeap.push(B); bigger++; }
            else { maxHeap.push(B); }



            if ( bigger == 0 ) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if ( bigger == 2 ) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            MIDDLE = maxHeap.top();
            std::cout << MIDDLE << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}