//
// Created by KangMinji on 2023-10-24.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), greater<>());

	/*
	citation 6 5 3 1 0
	인용횟수  1 2 3 4 5
	*/
	for (int i=0; i<(int)citations.size(); i++){
		if (citations[i] >= i + 1) {
			answer = max(answer, i+1);
		}
	}
	return answer;
}