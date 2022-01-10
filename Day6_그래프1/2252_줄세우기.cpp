#include <bits/stdc++.h>

#define MAXN 32001
using namespace std;

int N, M, A, B;
int inDegree[MAXN]; // inDegree : 해당 Vertex의 inDegree 수
vector<int> graph[MAXN];
queue<int> q;

void topologicalSort()
{
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        cout << cur << " ";
        for (auto next : graph[cur]) {
            inDegree[next]--;

            if (inDegree[next] == 0)
                q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }
    
    topologicalSort();

    return 0;
}