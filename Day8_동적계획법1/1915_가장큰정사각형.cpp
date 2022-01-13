#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int answer;
int N, M;
int DP[MAX][MAX];
string str;

int getMin(int a, int b, int c)
{
    int temp = a;
    if (temp > b) temp = b;
    if (temp > c) temp = c;
    return temp;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> str; 
        for (int j = 1; j <= M; j++) {
            DP[i][j] = str[j-1] - '0';

            if (DP[i][j] == 1) {
                DP[i][j] += getMin(DP[i-1][j-1], DP[i-1][j], DP[i][j-1]);
                answer = max(answer, DP[i][j]);
            }
        }
    }

    cout << answer * answer;

    return 0;
}