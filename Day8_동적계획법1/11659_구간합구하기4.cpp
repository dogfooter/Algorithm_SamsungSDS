#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, M;
int a, b;

int numArr[MAXN];
int DP[MAXN];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> numArr[i];
        DP[i] += DP[i-1] + numArr[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << DP[b] - DP[a-1] << '\n';
    }

    return 0;
}