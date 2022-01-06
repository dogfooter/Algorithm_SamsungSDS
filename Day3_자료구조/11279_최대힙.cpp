#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    priority_queue<int> pq;
    
    int N;  cin >> N;
    for (int i = 0; i < N; i++) {
        int x;  cin >> x;
        if (x > 0)
            pq.push(x);
        else if (x == 0) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << 0 << '\n';
        }
    }

    return 0;
}