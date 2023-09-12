// LV2
// Created by KangMinji on 2023-09-12.
// https://school.programmers.co.kr/learn/courses/30/lessons/72411

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int mixCount[11];
map<string, int> combination[11];

void combine(string order, int idx, string result){
	if (idx == order.size()) {
		int num = result.size();
		combination[num][result]++;
		mixCount[num] = max(mixCount[num], combination[num][result]);
		return;
	}
	combine(order, idx+1, result + order[idx]);
	combine(order, idx+1, result);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (string order : orders) {
		sort(order.begin(), order.end());
		combine(order, 0, "");
	}

	// 2명 이상의 손님이 주문한 코스요리 생성
	for (int num : course){
		for (auto comb : combination[num]) {
			if (comb.second == mixCount[num] && comb.second >= 2){
				answer.push_back(comb.first);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}