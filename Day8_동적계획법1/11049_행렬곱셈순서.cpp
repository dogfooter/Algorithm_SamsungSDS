#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

int N;
int m[500][2];
int dp[500][500];

int dfs(int x, int y){

    if(x == y) return 0;
    if(dp[x][y] != INF) return dp[x][y];

    for(int i = x; i < y; i++){
        dp[x][y] = min(dp[x][y], dfs(x, i) + dfs(i + 1, y) + m[x][0] * m[i][1] * m[y][1]);
    }
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> m[i][0] >> m[i][1];
        for(int j = 0; j < N; j++){
            dp[i][j] = INF;
        }
    }

    cout << dfs(0, N-1) << '\n';
    
    return 0;
}