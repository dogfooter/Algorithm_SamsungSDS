#include <bits/stdc++.h>
using namespace std;

map<string, int> tree;
int cnt;

int main(void)
{
    ios::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    string input;

    // 한 라인 단위로 입력을 받음
    while (getline(cin, input))
    {   
        cnt++;
        tree[input]++;
    }

    double rate;
    // cout.precision(4);
    // cout << fixed;
    for (auto it : tree)
    {   
        rate = (double)(it.second * 100) / (double)cnt;
        // cout << it.first << ' ' << rate << '\n';
        printf("%s %.4lf\n", it.first.c_str(), rate);        
    }

    return 0;
}