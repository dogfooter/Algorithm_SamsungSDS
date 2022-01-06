#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;  cin >> num;
        
        // 처음에 값이 없는 경우
        if (maxHeap.empty()) {
            maxHeap.push(num);
        }
        else {
            if (maxHeap.size() > minHeap.size())
                minHeap.push(num);
            else
                maxHeap.push(num);

            // 최대 힙의 top이 최소 힙의 top보다 크면 교환
            if (maxHeap.top() > minHeap.top()) {
                int maxTop = maxHeap.top();
                int minTop = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(maxTop);
            }
        }

        cout << maxHeap.top() << '\n';
    }

    return 0;
}