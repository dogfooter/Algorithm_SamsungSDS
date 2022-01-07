#include <bits/stdc++.h>

using namespace std;

long long factorial[21];
bool checked[21];
int N, M;

void printNum()
{
    vector<int> numList(N);
    long long k;
    
    cin >> k;
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            if (checked[j] == true)
                continue;
            
            if (factorial[N-(i+1)] < k) {
                k -= factorial[N-(i+1)];
            }
            else {
                numList[i] = j;
                checked[j] = true;
                break;
            }
        }
    }
    
    for (int i = 0; i < N; i++)
        cout << numList[i] << ' ';

    return;
}

void printK()
{
    vector<int> numList(N);
    long long k = 0;
    
    for (int i = 0; i < N; i++)
        cin >> numList[i];
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < numList[i]; j++) {
            if (!checked[j]) 
                k += factorial[N-(i+1)];
        }

        checked[numList[i]] = true;
    }

    cout << k + 1 << '\n';
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);

    cin >> N >> M;

    factorial[0] = 1;
    for (int i = 1; i <= 20; i++)
        factorial[i] = i * factorial[i-1];

    switch (M) {
        case 1:
            printNum();
            break;

        case 2:
            printK();
            break;
    }

    return 0;
}