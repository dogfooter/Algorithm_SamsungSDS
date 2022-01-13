#include <bits/stdc++.h>

#define MAX 4001

using namespace std;

int answer;
int DP[MAX][MAX];
string str1;
string str2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str1;
    cin >> str2;

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                DP[i+1][j+1] = DP[i][j] + 1;
                answer = max(answer, DP[i+1][j+1]);
            }
        }
    }

    cout << answer;

    return 0;
}