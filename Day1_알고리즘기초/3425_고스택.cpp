#include <bits/stdc++.h>

#define endl '\n'
#define MAX 1000000000
using namespace std;

enum OPERATOR { NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD };

struct stackOp 
{
	int instruction;
	int num;
};

int getOperator(string s) 
{
	if (s.compare("NUM") == 0) return NUM;
	else if (s.compare("POP") == 0) return POP;
	else if (s.compare("INV") == 0) return INV;
	else if (s.compare("DUP") == 0) return DUP;
	else if (s.compare("SWP") == 0) return SWP;
	else if (s.compare("ADD") == 0) return ADD;
	else if (s.compare("SUB") == 0) return SUB;
	else if (s.compare("MUL") == 0) return MUL;
	else if (s.compare("DIV") == 0) return DIV;
	else if (s.compare("MOD") == 0) return MOD;

	return -1;
}

int main(void) 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long first, second;

	while (true)
	{
		vector<stackOp> machine;
		string instruction;
		int num;
		while (true)
		{
			cin >> instruction;
			if (instruction.compare("QUIT") == 0) return 0;
			else if (instruction.compare("END") == 0) break;
			else if (instruction.compare("NUM") == 0) cin >> num;

			machine.push_back({getOperator(instruction), num});
		}

		int N;
		cin >> N;
		
		// 각 입력값 마다 독립적으로 프로그램 수행
		while (N--)
		{
			stack<int> S;
			int V;
			cin >> V;
			S.push(V);

			// 프로그램 명령어 수행
			bool isError = false;
			for (stackOp op : machine)
			{
				if (isError) break;

				switch (op.instruction) 
				{
					case NUM:
						S.push(op.num);
						break;

					case POP:
						if (S.empty()) isError = true;
						else S.pop();
						break;
					
					case INV:
						if (S.empty()) isError = true;
						else
						{
							long long temp = S.top();
							S.pop();
							S.push(-temp);
						}
						break;

					case DUP:
						if (S.empty()) isError = true;
						else S.push(S.top());
						break;

					case SWP:
						if (S.size() < 2) isError = true;
						else
						{
							first = S.top();
							S.pop();
							second = S.top();
							S.pop();
							S.push(first);
							S.push(second);
						}
						break;

					case ADD:
						if (S.size() < 2) isError = true;
						else
						{
							first = S.top();
							S.pop();
							second = S.top();
							S.pop();
							if (abs(first + second) > MAX) isError = true;
							else S.push((int)second + (int)first);
						}
						break;

					case SUB:
						if (S.size() < 2) isError = true;
						else
						{
							first = S.top();
							S.pop();
							second = S.top();
							S.pop();
							if (abs(second - first) > MAX) isError = true;
							else S.push((int)second - (int)first);
						}
						break;					

					case MUL:
						if (S.size() < 2) isError = true;
						else
						{
							first = S.top();
							S.pop();
							second = S.top();
							S.pop();
							if (abs(first * second) > MAX) isError = true; // 절댓값이 10^9를 넘어감
							else S.push((int)second * (int)first);
						}
						break;	

					case DIV:
						if (S.size() < 2) isError = true;
						else
						{
							first = S.top();
							S.pop();
							second = S.top();
							S.pop();
							if (first == 0) isError = true; // 0으로 나누는 경우
							else 
							{	
								int minusCheck = (first < 0) + (second < 0);
								S.push(abs(second) / abs(first) * (minusCheck == 1 ? -1 : 1));
							}
						}
						break;

					case MOD:
						if (S.size() < 2) isError = true;
						else
						{
							int first = S.top();
							S.pop();
							int second = S.top();
							S.pop();
							if (first == 0) isError = true; // 0으로 나누는 경우
							else S.push(second % first);
						}
						break; 
				}
			}

			if (isError || S.size() != 1) // 출력 조건
				cout << "ERROR" << endl;
			else
				cout << S.top() << endl;
		}
		cout << endl;
	}

	return 0;
}