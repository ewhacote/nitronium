// LV2
// Created by KangMinji on 2023-09-24.
// https://school.programmers.co.kr/learn/courses/30/lessons/67257

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long calc(long long a, long long b, char op) {
	if (op == '+')
		return a+b;
	if (op == '-')
		return a-b;
	return a*b;
}

long long solution(string expression) {
	long long answer = 0;

	vector<long long> numbers;
	vector<char> operators;

	// 1) 연산자와 숫자 분리
	string num = "";
	for (char c : expression) {
		if (c == '+' || c == '-' || c == '*') {
			numbers.push_back(stoll(num));
			num = "";
			operators.push_back(c);
		} else {
			num += c;
		}
	}
	numbers.push_back(stoll(num));

	// 2) 연산자 우선순위 조합
	vector<char> order = {'+', '-', '*'};
	sort(order.begin(), order.end()); // 이거 넣어야 함
	do {
		vector<long long> t_num = numbers;
		vector<char> t_op = operators;

		for (char op : order){
			// 각 연산자에 해당하는 인덱스 전 후 값들을 연산
			for (int i=0 ;i<t_op.size(); i++){
				if (op == t_op[i]) {
					t_num[i] = calc(t_num[i], t_num[i+1], t_op[i]);
					t_num.erase(t_num.begin() + i + 1);
					t_op.erase(t_op.begin() + i);
					i--;
				}
			}
		}
		answer = max(answer, abs(t_num.front()));
	} while(next_permutation(order.begin(), order.end()));

	return answer;
}