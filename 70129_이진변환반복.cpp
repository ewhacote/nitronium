// LV2
// Created by KangMinji on 2023-09-13.
// https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=cpp

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer(2, 0);

	int freq = 0, zero_cnt = 0;

	while(s != "1"){
		freq++;

		// 1. x의 모든 0 제거
		int len = 0;
		for (char c : s){
			if (c == '0')
				zero_cnt++;
			else
				len++;

		}

		s = "";
		while(len) {
			s += to_string(len % 2);
			len /= 2;
		}
	}

	answer[0] = freq;
	answer[1] = zero_cnt;

	return answer;
}