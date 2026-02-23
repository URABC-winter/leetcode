#include <bits/stdc++.h>
using namespace std;

string convert(string date) {
	int len = date.size();
	int sum = 0;
	string backNum;
	stack<int> st;
	for(int i= 0;i<len;i++){
		int num = date[i] - '0';
		sum *= 10;
		sum += num;
	}
	cout<<sum<<endl;
	while(sum > 0) {
		int remain = sum % 2;
		st.push(remain);
		sum /= 2;
	}
	while(!st.empty()){
		int popNum = st.top();
		backNum += to_string(popNum);
		st.pop();
	}
	return backNum;
}

string convertDateToBinary(string date) {
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    string day = date.substr(8);
    string yearBack = convert(year);
    string monthBack = convert(month);
    string dayBack = convert(day);
    string binary = yearBack + "-" + monthBack + "-" + dayBack;
    return binary;
}

int main() {
	string str = "2080-02-29";
	string s = convertDateToBinary(str);
	cout<<s<<endl;
	return 0;
}
