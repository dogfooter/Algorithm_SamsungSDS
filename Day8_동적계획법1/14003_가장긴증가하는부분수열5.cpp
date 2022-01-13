#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

int N;
int arr[MAXN];
int idx[MAXN];
vector<int> v;
vector<int> vReverse;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    v.push_back(arr[0]);
    idx[0] = 1;

    for (int i = 1; i < N; i++) {
        if (arr[i] > v.at(v.size() - 1)) {
            v.push_back(arr[i]);
            idx[i] = v.size();
        }
        else {
            int left = 0;
            int right = v.size() - 1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (v.at(mid) >= arr[i]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            v[left] = arr[i];
            idx[i] = left + 1;
        }
    }

    // 가장 긴 증가하는 부분 수열의 길이 출력
    cout << v.size() << '\n';

    vReverse.clear();
    int K = v.size();

    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;
        if (K == idx[i]) {
            vReverse.push_back(arr[i]);
            K--;
        }
    }

    while (!vReverse.empty()) {
        cout << vReverse[vReverse.size() - 1] << ' ';
        vReverse.pop_back();
    }

    return 0;
}