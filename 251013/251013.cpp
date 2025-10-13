//11279 maxHeap
#include <iostream>

using namespace std;

int n, heap[100002], x, heapSize;

void swap(int a, int b) {
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
    return;
}

void down(int cur) {
    if(cur*2 > heapSize) return;
    int left = cur*2;
    int right = cur*2 + 1;

    if(right > heapSize) {
        if(heap[cur] < heap[left]) {
            swap(left, cur);
            down(left);
        }
    } else {
        int maxId = heap[left] > heap[right] ? left : right;
        if(heap[cur] < heap[maxId]) {
            swap(cur, maxId);
            down(maxId);
        }
    }
    return;
}

void up(int cur) {
    if(cur == 1) return; 
    int par = cur/2;
    if(heap[cur] > heap[par]) {
        swap(cur, par);
        up(par);
    }
    return;
}

int pop() {
    int ret;
    if(heapSize == 0) return 0;
    if(heapSize > 0) ret = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    down(1);
    return ret;
}

void push(int k) {
    heap[++heapSize] = k;
    up(heapSize);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(x == 0) cout << pop() << '\n';
        else push(x);
    }

    return 0;
}