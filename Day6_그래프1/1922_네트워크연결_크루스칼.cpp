#include <bits/stdc++.h>

#define MAXN 1001
using namespace std;

struct Data {
    int node1, node2, weight;
    Data() {};
    Data(int node1, int node2, int weight) : node1(node1), node2(node2), weight(weight) {};

    bool operator<(const Data& d) const {
        return weight > d.weight;
    }
};

int N, M;
int a, b, c;
int parent[MAXN];
priority_queue<Data> pq;

void init()
{
    // 자기 자신을 부모로 초기화
    for (int i = 0; i <= N; i++)
        parent[i] = i;
}

int find(int x)
{   
    // 부모 노드를 반환
    if (x == parent[x])
        return x;
    
    // 경로 압축 및 부모 탐색
    return parent[x] = find(parent[x]);
}

void unite(int x, int y)
{
    // 1. x의 부모를 y의 부모로 연결 
    // 2. 경로 압축
    parent[find(x)] = find(y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count = 0;
    int answer = 0;

    cin >> N >> M;  
    
    init();
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        pq.push(Data(a, b, c));
    }

    while (true) {
        // 모든 컴퓨터를 연결할 수 있기 때문에
        if (count == N - 1) break;
        Data d = pq.top();
        pq.pop();

        if (find(d.node1) != find(d.node2)) {
            unite(d.node1, d.node2);
            count++;
            answer += d.weight;
        }
    }
    
    cout << answer;

    return 0;
}