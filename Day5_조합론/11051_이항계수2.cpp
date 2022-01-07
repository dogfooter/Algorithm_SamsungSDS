#include <bits/stdc++.h>

#define MAXN 1001
#define MOD 10007

using namespace std;

int DP[MAXN][MAXN];

int main()
{
    int N, K;
    
    cin >> N >> K;
    
    for (int i = 0; i <= N; i++)
    {
        DP[i][0] = 1;
        DP[i][i] = 1;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= min(i, K); j++)
            DP[i][j] = DP[i-1][j-1] % MOD + DP[i-1][j] % MOD;
        
    cout << DP[N][K] % MOD << '\n';

    return 0;
}