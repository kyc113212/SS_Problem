#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

stack<char> st;
stack<long int> i_st;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {

		int length;
		string s;
		string post_s;
		post_s.clear();
		cin >> length;

		cin >> s;

		//cout << s << endl;

		for (int i = 0; i < length; i++) {
			char c = s[i];
			int s_size = st.size();
			switch (c)
			{
			case '+':
				if (!st.empty()) {
					if (st.top() == '*') {
						post_s += '*';
						st.pop();
					}
					else if (st.top() == '+') {
						post_s += '+';
						st.pop();
					}
				}
				if (!st.empty()) {
					if (st.top() == '+') {
						post_s += '+';
						st.pop();
					}
				}
				st.push(c);
				//post_s += c;
				break;
			case '*':
				if (!st.empty()) {
					if (st.top() == '*') {
						post_s += '*';
						st.pop();
					}
				}
				st.push(c);
				//post_s += c;
				break;
			case '(':
				st.push(c);
				break;
			case ')':
				while (!st.empty()) {
					if (st.top() == '(') {
						st.pop();
						break;
					}
					else {
						//cout << st.size() << endl;
						post_s += st.top();
						st.pop();
					}
				}
				break;
			default:
				post_s += c;
				break;
			}
		}

		while (!st.empty()) {
			post_s += st.top();
			st.pop();
		}
		int post_lenth = post_s.size();

		//cout << post_s << endl;

		for (int i = 0; i < post_lenth; i++) {
			char c = post_s[i];
			if (c >= 49 && c <= 58) {
				i_st.push(c - '0');
			}
			else {
				int a = i_st.top();
				i_st.pop();
				int b = i_st.top();
				i_st.pop();
				if (c == '+') {
					int sum = a + b;
					i_st.push(sum);
				}
				else if (c == '*') {
					int mul = a * b;
					i_st.push(mul);
				}
			}
		}
		cout << "#" << tc << " " << i_st.top() << endl;

	}

	return 0;
}
