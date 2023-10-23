//
// Created by KangMinji on 2023-10-23.
//

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
	if (n < 2) return false;

	// 에라토스테네스의 체
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;

	return true;
}


int solution(string numbers) {
	int answer = 0;
	vector<char> v;  // 종이 조각의 각 숫자 저장
	vector<int> nums;   // 종이 조각으로 만들 수 있는 모든 수 저장

	// numbers의 각 숫자를 v에 입력 후 오름차순 정렬
	for (int i = 0; i < numbers.size(); i++)
		v.push_back(numbers[i]);
	sort(v.begin(), v.end());

	do {
		string temp = "";
		// 만들 수 있는 모든 숫자 nums에 저장
		for (int i = 0; i < v.size(); i++) {
			temp.push_back(v[i]);
			nums.push_back(stoi(temp));
		}
	} while (next_permutation(v.begin(), v.end()));

	// 중복 값 지우기
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	for (int i = 0; i < nums.size(); i++)
		// 소수일 경우 answer++
		if (isPrime(nums[i]))
			answer++;

	return answer;
}