#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

string input;
stack<char> myStack;
long long answer;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int temp = 1;
    bool error = false;

    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        // 불가능한 경우
        if (input[i] == ')' && (myStack.empty() || myStack.top() != '('))
        {
            error = true;
            break;
        }
        else if (input[i] == ']' && (myStack.empty() || myStack.top() != '['))
        {
            error = true;
            break;
        }

        // 가능한 경우
        if (input[i] == '(')
        {
            temp *= 2;
            myStack.push(input[i]);
        }
        else if (input[i] == '[')
        {
            temp *= 3;
            myStack.push(input[i]);
        }
        else if (input[i] == ')')
        {
            if (input[i - 1] == '(')
                answer += temp;
            
            temp /= 2;
            myStack.pop();       
        }
        else if (input[i] == ']')
        {
            if (input[i - 1] == '[')
                answer += temp;
            
            temp /= 3;
            myStack.pop();     
        }                
    }

    if (error || !myStack.empty())
        cout << 0 << endl;
    else
        cout << answer << endl;

    return 0;
}