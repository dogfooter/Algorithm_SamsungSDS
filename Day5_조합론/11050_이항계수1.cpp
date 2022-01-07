#include <bits/stdc++.h>

using namespace std;

int factorial(int num)
{
    if (num == 0 || num == 1)
        return 1;

    return num * factorial(num - 1);
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << factorial(N) / (factorial(K) * factorial(N-K)) << '\n';
}