#include <bits/stdc++.h>

#define MAX 50
#define MMAX MAX*MAX+1

using namespace std;

int N, M, K;
int stone[MAX];

int main()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> stone[i];
        N += stone[i];
    }
    cin >> K;

    double answer = 0.0;
    for(int i=0; i<M; i++) {
        double temp = 1.0;
        if (stone[i] < K)
            continue;

        for (int j=0; j<K; j++)
            temp *= (double)(stone[i] - j) / (N - j);

        answer += temp;
    }

    cout << fixed;
    cout.precision(15);
    cout << answer;

    return 0;
}