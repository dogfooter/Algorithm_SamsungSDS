#include <bits/stdc++.h>

#define MAX 301

using namespace std;

int N;
int DP[MAX];
int score[MAX];

int main(void) {
    ios::sync_with_stdio(false);  cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> score[i];
    
    DP[1] = score[1];
    DP[2] = score[1] + score[2];

    for (int i = 3; i <= N; i++)
        DP[i] = score[i] + max(score[i - 1] + DP[i - 3], DP[i - 2]);
    
    cout << DP[N] << '\n';
    
    return 0;
}