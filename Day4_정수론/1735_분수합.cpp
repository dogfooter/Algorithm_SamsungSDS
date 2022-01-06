#include <bits/stdc++.h>
using namespace std;

// 최대공약수
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int num1, num2, num3 ,num4;
    int up, down, gcdVal;

    cin >> num1 >> num2 >> num3 >> num4;
    up = num1 * num4 + num2 * num3;
    down = num2 * num4;
    
    gcdVal = gcd(up, down);
    cout << up / gcdVal << ' ' << down / gcdVal;

    return 0;
}