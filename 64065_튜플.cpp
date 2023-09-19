//
// Created by KangMinji on 2023-09-19.
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b){
	if (a.first != b.first)
		return a.second > b.second;
	return a.first < b.first;
}

// 조합 만들기
vector<int> solution(string s) {
	vector<int> answer;

	map<int, int> mp;

	string num = "";
	for (int i=2; i<s.length()-2; i++) {
		char c = s[i];
		// 숫자가 아닌 경우
		if (c == '{') continue;
		if (c == '}' || c == ',') {
			if (num != "") {
				mp[stoi(num)]++;
			}
			num = "";
		} else {
			// 숫자인 경우 -> 문자열 뒤에 바로 추가
			num += c;
		}
	}
	if (num != "") {
		mp[stoi(num)]++;
	}

	// 숫자 개수 counting
	vector<ci> v;
	for (auto key : mp) {
		v.push_back(key);
	}
	sort(v.begin(), v.end(), cmp);

	for (ci val : v){
		answer.push_back(val.first);
	}

	return answer;
}