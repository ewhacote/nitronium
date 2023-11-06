//
// Created by KangMinji on 2023-11-06.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string getResult(int n, int max) {
	string str = ""; // max개의 사람들이 외칠 문자를 저장
	stack<int> s;

	// 0부터 진법 변환한 값을 str에 붙임. 이때 str의 길이가 max보다 작을때까지만 반복
	for (int i = 0; str.length() <= max; i++) {
		int cur = i; // 진법 변환해야할 값을 cur로 초기화.

		// 진법 변환 과정 - 나눈 나머지를 스택에 저장
		while (1) {
			s.push(cur % n);
			cur /= n;
			if (cur == 0)
				break;
		}

		// 스택의 값을 이용해 진법 변환 결과를 str에 붙임.
		while (!s.empty()) {
			if (s.top() < 10)
				str += to_string(s.top());
			else // 스택의 값이 10을 넘는다면 A~F로 변환
				str += (char)(65+s.top()-10);
			s.pop();
		}
	}
	return str; // 사람들이 외칠 문자열을 반환.
}

// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
// 0부터 시작
string solution(int n, int t, int m, int p) {
	string answer = "";
	// t * m 개의 진법변환 결과면 충분함.
	string str = getResult(n, t*m);

	// p-1번째의 값과 m씩 건너뛴 값이 불러야할 값임. t가 0이 될때까지 반복.
	for (int i = p-1; t > 0; i += m) {
		answer += str[i];
		t--;
	}

	return answer;
}