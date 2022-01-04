#include <bits/stdc++.h>

#define MAX 100001
using namespace std;

int N, S;
int seq[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    
    for (int i = 0; i < N; i++)
        cin >> seq[i];

    int lp = 0;
    int rp = 0;
    int partSum = 0;
    int answer = N + 1;

    while (rp <= N)
    {
        if (partSum >= S)
        {
            int length = rp - lp;
            answer = min(answer, length);
            partSum -= seq[lp++];

            if (rp == N)
                break;
        }
        else if (partSum < S)
        {
            partSum += seq[rp++];
        }
    }
    cout << (answer <= N ? answer : 0);

    return 0;
}