#include <bits/stdc++.h>

#define MAXN 100001
#define MAXP 20

using namespace std;

int N, M;
int a, b;

int DP[MAXN][MAXP+1];
int depth[MAXN];
bool isVisited[MAXN];
vector<int> v[MAXN];

// cur: 노드번호, d: 깊이, 각 노드들의 2^0 부모와 깊이를 저장
void DFS(int cur, int d)
{
    isVisited[cur] = true;
    depth[cur] = d;

    for (auto next : v[cur]) {
        if (isVisited[next])
            continue;

        DP[next][0] = cur;
        DFS(next, d+1);
    }
}

// 2^j번째 부모를 DP배열의 j번째 열에 저장
void setDP()
{
    for (int j = 1; j < MAXP; j++) {
        for (int i = 1; i <= N; i++) {
            DP[i][j] = DP[DP[i][j - 1]][j - 1];
        }
    }
}

int LCA(int x, int y)
{
    if (depth[x] > depth[y])
        swap(x, y);
    
    for (int i = MAXP; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i))
            y = DP[y][i];
    }

    if (x == y) 
        return x;

    for (int i = MAXP; i >= 0; i--) {
        if (DP[x][i] != DP[y][i]) {
            x = DP[x][i];
            y = DP[y][i];
        }
    }

    return DP[x][0];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, 0, sizeof(isVisited));

    DFS(1, 0);
    setDP();

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

    return 0;
}