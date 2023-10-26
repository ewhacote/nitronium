//
// Created by KangMinji on 2023-10-26.
// https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

// mix = 가장 맵지 않은 스코빌 + (두 번째로 맵지 않은 음식의 스코빌) * 2
int solution(vector<int> scoville, int K) {
	int answer = 0;

	// 입력
	priority_queue<int, vector<int>, greater<>> pq; // 최소힙
	for (int score : scoville){
		pq.push(score);
	}

	// 연산
	while(pq.size() >= 2 && pq.top() < K){
		int food1 = pq.top(); pq.pop();
		int food2 = pq.top(); pq.pop();

		long long new_food = food1 + food2*2;
		pq.push(new_food);

		answer++;
	}

	if (pq.empty() || pq.top() < K){
		answer = -1;
	}

	return answer;
}