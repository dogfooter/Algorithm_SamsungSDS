#include <bits/stdc++.h>

#define MAX 91
using namespace std;

long long n;
long long fibonacci[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= n; i++)
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    
    cout << fibonacci[n];

    return 0;
}
