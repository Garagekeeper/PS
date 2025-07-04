#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    std::vector<int> heap;

    void goUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    void goDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] < heap[smallest]) smallest = right;

            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        goUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        goDown(0);
    }

    int top() const {
        if (!heap.empty()) return heap[0];
        throw std::runtime_error("Heap is empty");
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    MinHeap minheap;
    
    cin >> N;
    
    for (int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            if (!minheap.empty())
            {
                cout << minheap.top() << '\n';
                minheap.pop();
            }
            else 
                cout << 0 << '\n';
        }
        else
        {
            minheap.push(temp);
        }
    }
}