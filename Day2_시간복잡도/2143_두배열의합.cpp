#include <bits/stdc++.h>

#define endl '\n'
#define MAX 1001
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long T;
    cin >> T;

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int M;
    cin >> M;
    vector<long long> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    vector<long long> v1;
    for (int i = 0; i < N; i++)
    {
        int sum = A[i];
        v1.push_back(sum);
        for (int j = i + 1; j < N; j++)
        {
            sum += A[j];
            v1.push_back(sum);
        }
    }

    vector<long long> v2;
    for (int i = 0; i < M; i++)
    {
        int sum = B[i];
        v2.push_back(sum);
        for (int j = i + 1; j < M; j++)
        {
            sum += B[j];
            v2.push_back(sum);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    long long answer = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        int lo = lower_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
        int hi = upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
        
        answer += (hi - lo);
    }
    cout << answer << '\n';

    return 0;
}