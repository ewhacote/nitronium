//
// Created by KangMinji on 2023-11-10.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

/*
cache hit : 실행 시간 1
cache miss : 실행 시간 5, cache에 넣기
*/
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	transform(cities.begin(), cities.end(), cities.begin(),
			  [](string& str) {
				  // 각 문자를 소문자로 변환
				  transform(str.begin(), str.end(), str.begin(), ::tolower);
				  return str;
			  });

	vector<string> v;
	for (string city : cities) {
		// 1) 캐시에 있는 경우
		auto iter = find(v.begin(), v.end(), city);
		if (iter != v.end()) {
			answer++;
			v.erase(iter);
		}
			// 2) 캐시에 없는 경우
		else {
			// 캐시가 꽉 찬 경우 : 캐시 비워준다
			if (cacheSize != 0 && v.size() == cacheSize) {
				v.erase(v.begin());
			}
			answer += 5;
		}
		if (cacheSize > 0) {
			v.push_back(city);
		}
	}

	return answer;
}