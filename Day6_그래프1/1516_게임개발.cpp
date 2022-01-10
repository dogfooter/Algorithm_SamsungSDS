#include <bits/stdc++.h>

#define MAXN 501
using namespace std;

int N, input;
int DP[MAXN];
int inDegree[MAXN]; // inDegree : 해당 Vertex의 inDegree 수
int cost[MAXN];
vector<int> graph[MAXN];
queue<int> q;

void topologicalSort()
{
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            DP[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : graph[cur]) {
            DP[next] = max(DP[next], DP[cur] + cost[next]);
            inDegree[next]--;

            // 정점 cur을 지워서 indegree가 새롭게 0이 된 정점 next
            if (inDegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << DP[i] << '\n';

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> input;
        cost[i] = input;
        while (true) {
            cin >> input;
            if (input == -1)
                break;

            graph[input].push_back(i);
            inDegree[i]++;
        }       
    }
    
    topologicalSort();

    return 0;
}