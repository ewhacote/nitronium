// LV2
// Created by KangMinji on 2023-09-15.
// https://school.programmers.co.kr/learn/courses/30/lessons/68645

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int m;
int board[1005][1005];
int cnt = 1;

void makeTriangle(int x, int y, int len) {
	if (len <= 0){
		return;
	}

	// 변1
	for (int i=0; i<len; i++){
		board[x+i][y] = cnt++;
	}

	// 변2
	for (int i=1; i<len; i++){
		board[x + len - 1][y+i] = cnt++;
	}

	// 변3
	for (int i=len-2; i>0; i--){
		board[x + i][y + i] = cnt++;
	}

	makeTriangle(x+2, y+1, len-3);
}

vector<int> solution(int n) {
	vector<int> answer;

	m = n;
	makeTriangle(0, 0, n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (board[i][j])
				answer.push_back(board[i][j]);
		}
	}
	return answer;
}