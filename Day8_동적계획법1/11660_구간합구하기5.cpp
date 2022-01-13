#include <bits/stdc++.h>

#define MAXN 1025

using namespace std;

int N, M;
int X1, X2, Y1, Y2;

int numArr[MAXN][MAXN];
int DP[MAXN][MAXN]; // 1024 * 1024 * 1000 < INT의 최대 범위

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> numArr[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + numArr[i][j];

    for (int i = 0; i < M; i++) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << DP[X2][Y2] - DP[X1-1][Y2] - DP[X2][Y1-1] + DP[X1-1][Y1-1] << '\n';
    }

    return 0;
}