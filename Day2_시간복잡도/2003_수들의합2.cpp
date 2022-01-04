#include <bits/stdc++.h>

#define MAX 10000
using namespace std;

int answer;
int N, M;
int A[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int lp = 0;
    int rp = 0;
    int partSum = 0;

    while (rp <= N)
    {
        if (partSum == M)
        {
            answer++;
            partSum += A[rp++];
        }
        else if (partSum < M)
        {    
            partSum += A[rp++];
        }
        else if (partSum > M)
        {
            partSum -= A[lp++];
        }
    }
    cout << answer;

    return 0;
}