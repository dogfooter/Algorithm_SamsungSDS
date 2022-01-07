#include <bits/stdc++.h>

#define MAXN 31

using namespace std;

int DP[MAXN][MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        DP[i][0] = 1;
        DP[i][i] = 1;
    }

    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j <= i; j++)
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;  cin >> T;
    
    init();
    while (T--)
    {
        int N, M;  cin >> N >> M;
        cout << DP[M][N] << '\n';
    }
}