#include <bits/stdc++.h>

#define endl '\n'
#define MAX 100001
using namespace std;

vector<int> A;
vector<int> B;
int N, M;

bool binarySearch(int x)
{
    int lo = 0;
    int hi = A.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (A[mid] == x)
            return true;
        else if (A[mid] < x)
            lo = mid + 1;
        else if (A[mid] > x)
            hi = mid - 1;
    }
    return false;
}

void input()
{
    int input;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        A.push_back(input);
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        B.push_back(input);
    }
}

void solution()
{   
    sort(A.begin(), A.end());
    for (int i = 0; i < M; i++)
    {
        int key = B[i];
        if (binarySearch(key))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solution();
    
    return 0;
}
