#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int answer;
int DP[MAX][MAX];
vector<char> v;
string str1;
string str2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str1;
    cin >> str2;

    memset(DP, 0, sizeof(DP));

    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i-1] == str2[j-1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else {
                DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
            }
        }
    }
    
    // LCS의 길이
    answer = DP[str1.size()][str2.size()];
    cout << answer << '\n';

    if (answer > 0) {
        int x = str1.length();
        int y = str2.length();
        v.clear();

        while (true) {
            if (x == 0 || y == 0) break;
            if (str1[x - 1] == str2[y - 1]) {
                v.push_back(str1[x - 1]);
                x--;
                y--;
            }
            else {
                if (DP[x][y] == DP[x - 1][y]) {
                    x--;
                }
                else if (DP[x][y] == DP[x][y - 1]) {
                    y--;
                }
            }
        }

        while (!v.empty()) {
            cout << v.at(v.size() - 1);
            v.pop_back();
        }
    }

    return 0;
}