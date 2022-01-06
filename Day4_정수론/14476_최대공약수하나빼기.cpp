#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int leftGCD[MAX];
int rightGCD[MAX];
int num[MAX];
int N;

// 최대공약수
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
     
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> num[i];
    for(int i = 1; i <= N; i++) leftGCD[i] = gcd(num[i], leftGCD[i-1]); // 왼쪽부터 누적해서 공약수 구하기
    for(int i = N; i >= 1; i--) rightGCD[i] = gcd(num[i], rightGCD[i+1]); // 오른쪽부터 누적해서 공약수 구하기

    int deletedNum = -1;
    int bigGCD = 0;

    for(int i = 1; i <= N; i++){
        int gcdResult = gcd(leftGCD[i-1], rightGCD[i+1]);
        if(gcdResult > bigGCD && (num[i] % gcdResult)){
            bigGCD = gcdResult;
            deletedNum = num[i];
        }
    }

    if(deletedNum == -1) cout << -1;
    else cout << bigGCD << ' ' << deletedNum;
    return 0;
}

