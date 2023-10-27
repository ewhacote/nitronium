//
// Created by KangMinji on 2023-10-27.
//

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<pair<int, int>> q;
	priority_queue<int> pq;
	for (int i = 0; i< (int)priorities.size(); i++){
		q.push({priorities[i], i});
		pq.push(priorities[i]);
	}

	while(!q.empty()) {
		int priority = q.front().first;
		int idx = q.front().second;
		q.pop();

		if (priority != pq.top()){
			q.push({priority, idx});
		} else {
			answer++;
			if (idx == location){
				break;
			}
			pq.pop();
		}
	}
	return answer;
}