//
// Created by KangMinji on 2023-11-08.
//

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int next_idx = 1;
map<string, int> mp;

void init() {
	for (int i=0; i<26; i++){
		string st(1, 'A' + i); // 문자 'A'에 i를 더한 문자열을 생성
		mp.emplace(st, next_idx++);
	}
}

vector<int> solution(string msg) {
	vector<int> answer;

	// 전처리
	// 1-1) 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
	init();

	// 연산
	string w = "";
	string c = "";
	int idx = 0;
	while(idx <= msg.length()) {
		c = msg[idx];

		// 사전에 현재 문자열이 존재하는 경우
		if (mp.find(w + c) != mp.end()) {
			w = w + c; // 문자열 늘려주기
		}
			// 사전에 현재 문자열이 존재하지 않는 경우
		else {
			// w에 해당하는 사전의 색인 번호 출력
			answer.push_back(mp.find(w) -> second);
			// 입력에서 처리되지 않은 다음 글자가 있다면(c)
			// w+c에 해당하는 단어를 사전에 등록한다
			mp.emplace(w+c, next_idx++);
			// 입력에서 w를 제거한다
			w = c;
		}
		idx++;
	}

	return answer;
}