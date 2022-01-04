#include <bits/stdc++.h>

#define endl '\n'
#define MAX 100001
using namespace std;

int minScore, maxScore;
int table[MAX][3];
int minDP[3];
int maxDP[3];
int N;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 3; j++)
            cin >> table[i][j];

    for (int i = 1; i <= N; i++)
    {   
        int minLeft = minDP[0];
        int minCenter = minDP[1];
        int minRight = minDP[2];
        minDP[0] = min(minLeft, minCenter) + table[i][0];
        minDP[1] = min({minLeft, minCenter, minRight}) + table[i][1];
        minDP[2] = min(minCenter, minRight) + table[i][2];

        int maxLeft = maxDP[0];
        int maxCenter = maxDP[1];
        int maxRight = maxDP[2];
        maxDP[0] = max(maxLeft, maxCenter) + table[i][0];        
        maxDP[1] = max({maxLeft, maxCenter, maxRight}) + table[i][1];        
        maxDP[2] = max(maxCenter, maxRight) + table[i][2];
    }
    minScore = min({minDP[0], minDP[1], minDP[2]});
    maxScore = max({maxDP[0], maxDP[1], maxDP[2]});

    cout << maxScore << ' ' << minScore << endl;

    return 0;
}