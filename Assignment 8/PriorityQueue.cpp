#include <iostream>
#include <vector>
using namespace std;

struct MaxPQ
{
    vector<int> heap;
    void push(int x)
    {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] >= heap[i])
                break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }
    int top()
    {
        return heap.empty() ? -1 : heap[0];
    }
    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        int n = heap.size();
        int i = 0;
        while (true)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;
            if (l < n && heap[l] > heap[largest])
                largest = l;
            if (r < n && heap[r] > heap[largest])
                largest = r;
            if (largest == i)
                break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    int size() { return heap.size(); }
    bool empty() { return heap.empty(); }
};

struct MinPQ
{
    vector<int> heap;
    void push(int x)
    {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] <= heap[i])
                break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }
    int top()
    {
        return heap.empty() ? -1 : heap[0];
    }
    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        int n = heap.size();
        int i = 0;
        while (true)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int smallest = i;
            if (l < n && heap[l] < heap[smallest])
                smallest = l;
            if (r < n && heap[r] < heap[smallest])
                smallest = r;
            if (smallest == i)
                break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
    int size() { return heap.size(); }
    bool empty() { return heap.empty(); }
};

int main()
{
    MaxPQ mp;
    mp.push(5);
    mp.push(1);
    mp.push(9);
    mp.push(3);
    cout << "MaxPQ order: ";
    while (!mp.empty())
    {
        cout << mp.top() << " ";
        mp.pop();
    }
    cout << "\n";

    MinPQ mn;
    mn.push(5);
    mn.push(1);
    mn.push(9);
    mn.push(3);
    cout << "MinPQ order: ";
    while (!mn.empty())
    {
        cout << mn.top() << " ";
        mn.pop();
    }
    cout << "\n";

    return 0;
}
