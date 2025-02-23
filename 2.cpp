#include<iostream>
using namespace std;
#include<stack>
#include<string>
void Transform(const string& ss, string& sss) {//从中缀到后缀
	stack<char>s;
	for (int i = 0; i < ss.size(); i++) {
		switch (ss[i])
		{
		case '+':
		case '-':
			while (!s.empty() && s.top() != '(') {
				sss += s.top();
				s.pop();
			}
			s.push(ss[i]);
			break;
		case '*':
		case '/':
			while (s.top() == '*' || s.top() == '/') {
				sss += s.top();
				s.pop();
			}
			s.push(ss[i]);
			break;
		case '(':
			s.push(ss[i]);
			break;
		case ')':
			while (s.top() != '(') {
				sss += s.top();
				s.pop();
			}
			s.pop();
			break;
		default:
			sss += ss[i];
			break;
		}
	}
	while (!s.empty()) {
		sss += s.top();
		s.pop();
	}
}
int Calculate(const string&sss) {//再由后缀进行计算
	stack<int>s;
	int count = 0;
	int x = 0;
	int i = 0;
	int z = 0;
	while (i < sss.length()) {
		char arr = sss[i];
		if (arr >= '0' && arr <= '9') {
			x = 0;
			while (arr >= '0' && arr <= '9') {
				x = x * 10 + arr - '0';
				i++;
				arr = sss[i];
			}
			s.push(x);
		}
		else if (arr == ' ') {
			i++;
		}
		else {
			int y = s.top();
			s.pop();
			x = s.top();
			s.pop();
			switch (arr) {
			case '+': z = x + y; break;
			case '-': z = x - y; break;
			case '*': z = x * y; break;
			case '/': z = x / y; break;
			default:break;
			}
			i++;
			s.push(z);
		}
	}
	return s.top();
}
int main() {
	
	string ss = "10 + 20 * (30 - 40) + 50";
	string sss;
	Transform(ss, sss);
	cout << sss << endl;
	cout << Calculate(sss);
	return 0;
}
