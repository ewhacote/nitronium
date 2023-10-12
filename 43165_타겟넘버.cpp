//
// Created by KangMinji on 2023-10-12.
// https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
using namespace std;

int answer = 0;

void dfs(int idx, int target, int sum,  vector<int> &numbers){
	if (idx == numbers.size()){
		if (sum == target){
			answer++;
		}
		return;
	}
	dfs(idx+1, target, sum + numbers[idx], numbers);
	dfs(idx+1, target, sum - numbers[idx], numbers);
}


int solution(vector<int> numbers, int target) {
	dfs(0, target, 0, numbers);
	return answer;
}