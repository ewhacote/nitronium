// LV2
// Created by KangMinji on 2023-09-14.
// https://school.programmers.co.kr/learn/courses/30/lessons/68936

#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);
vector<vector<int>> board;

void compress(int x, int y, int size) {
	bool flag = false;
	int bit = board[x][y];
	for (int i=x; i<x+size; i++){
		for (int j=y; j<y+size; j++) {
			if (bit != board[i][j])
				flag = true;
		}
	}

	// 압축하기
	if (flag) {
		int nsize = size/2;
		compress(x, y, nsize);
		compress(x, y+nsize, nsize);
		compress(x+nsize, y, nsize);
		compress(x+nsize, y+nsize, nsize);
	} else { // 모두 같은 상수라면
		answer[bit]++;
	}
	return;
}

vector<int> solution(vector<vector<int>> arr) {

	board = arr;
	compress(0, 0, arr.size());


	return answer;
}