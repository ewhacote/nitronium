//
// Created by KangMinji on 2023-10-17.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx = 0; // 탑승한 인원

	sort(people.begin(), people.end());
	while(idx < people.size()){
		int fattest = people.back();
		people.pop_back();

		// 두 명이서 새로운 보트 탈 수 있는 경우
		if (people[idx] + fattest <= limit){
			idx++;
		} // fattest 혼자 보트 타는 경우는 idx 변화 없음
		answer++;
	}
	return answer;
}