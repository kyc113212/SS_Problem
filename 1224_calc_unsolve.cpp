#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

stack<char> st;

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
				case '+' :
					st.push(c);
					//post_s += c;
					break;
				case '*' :
					st.push(c);
					//post_s += c;
					break;
				case '(' :
					st.push(c);
					break;
				case ')' :
					while(!st.empty()) {
						if (st.top() == '(') {
							st.pop();
							//break;
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

		cout << post_s << endl;
		
	}

	return 0;
}







11
(5+6)*(7+1)
11
(2*(3+4))+5
