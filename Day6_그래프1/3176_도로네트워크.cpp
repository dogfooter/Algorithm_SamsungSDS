#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; 

struct Data {
    int node, weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};
};

struct Output {
    int shortest;
    int longest;
    Output() {};
    Output(int shortest, int longest) : shortest(shortest), longest(longest) {};
};

const int MAXN = 100001;
const int MAXP = 20;
int N, M;
int a, b, c;

vector<Data> v[MAXN];
int depth[MAXN];
int dp[MAXN][MAXP+1];
int dpMax[MAXN][MAXP+1];
int dpMin[MAXN][MAXP+1];

void BFS(int root)
{
    queue<pii> q;
    q.push(pii(root, 0));

    while (!q.empty()) {
        int curNode = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto next : v[curNode]) {
            if (next.node == parent)
                continue;
            
            depth[next.node] = depth[curNode] + 1;
            dp[next.node][0] = curNode;
            dpMin[next.node][0] = next.weight;
            dpMax[next.node][0] = next.weight;
            q.push(pii(next.node, curNode));
        }
    }
}

void setDP()
{
    for (int j = 1; j <= MAXP; j++) {
        for (int i = 1; i <= N; i++) {
            dpMin[i][j] = min(dpMin[i][j - 1], dpMin[dp[i][j - 1]][j - 1]);
            dpMax[i][j] = max(dpMax[i][j - 1], dpMax[dp[i][j - 1]][j - 1]);
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

Output LCA(int x, int y) 
{
    int longest = 0;
    int shortest = 1e9;

    if (depth[x] != depth[y]) {
        if (depth[x] > depth[y])
            swap(x, y);

        for (int i = MAXP; i >= 0; i--) {
            if (depth[y] - depth[x] >= (1 << i)) {
                longest = max(dpMax[y][i], longest);
                shortest = min(dpMin[y][i], shortest);
                y = dp[y][i];
            }
        }
    }

    if (x != y) {
        for (int i = MAXP; i >= 0; i--) {
            if (dp[x][i] != dp[y][i]) {
                longest = max(dpMax[x][i], longest);
                shortest = min(dpMin[x][i], shortest);
                x = dp[x][i];

                longest = max(dpMax[y][i], longest);
                shortest = min(dpMin[y][i], shortest);
                y = dp[y][i];
            }
        }

        longest = max(dpMax[x][0], longest);
        longest = max(dpMax[y][0], longest);
        shortest = min(dpMin[x][0], shortest);
        shortest = min(dpMin[y][0], shortest);
    }

    return Output(shortest, longest);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        cin >> a >> b >> c;
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }

    for (int j = 1; j <= MAXP; j++) {
        for (int i = 1; i <= N; i++) {
            dpMin[i][j] = 1e9;
            dpMax[i][j] = 0;
            dp[i][j] = 0;
        }
    }

    BFS(1);
    setDP();

    cin >> M;

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        Output answer = LCA(x, y);
        cout << answer.shortest << " " << answer.longest << "\n";
    }

    return 0;
}