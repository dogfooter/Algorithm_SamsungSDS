#include <bits/stdc++.h>

#define MAX 501

using namespace std;

int n, num;
int DP[MAX][MAX];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num;
            DP[i][j] = num;

            if (j == 1) {
                DP[i][j] += DP[i-1][j];
            }
            else if (j == i) {
                DP[i][j] += DP[i-1][j-1];
            }
            else {
                DP[i][j] += max(DP[i-1][j-1], DP[i-1][j]);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer = max(answer, DP[n][i]);

    cout << answer;

    return 0;
}