#include <bits/stdc++.h>

#define MAXN 20001
#define INF 987654321

using namespace std;

struct Data {
    int node, weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};

    // 우선순위 큐를 가중치가 짧은 순으로 배치
    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

int V, E, K;
int u, v, w;

priority_queue<Data> pq;
vector<Data> graph[MAXN];
bool isVisited[MAXN];
int dist[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;
    cin >> K;

    for (int i = 0; i <= V; i++) {
        graph[i].clear();
        dist[i] = INF;
        isVisited[i] = false;
    }

    for (int i = 1; i <= E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    pq.push(Data(K, 0));
    dist[K] = 0;

    while (!pq.empty()) {
        Data cur = pq.top();
        pq.pop();

        if (isVisited[cur.node]) continue;
        else isVisited[cur.node] = true;

        for (int i = 0; i < graph[cur.node].size(); i++) {
            Data next = graph[cur.node][i];

            if (dist[next.node] > dist[cur.node] + next.weight) {
                dist[next.node] = dist[cur.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (isVisited[i]) {
            cout << dist[i];
        }
        else {
            cout << "INF";
        }
        cout << '\n';
    }

    return 0;
}