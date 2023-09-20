//
// Created by KangMinji on 2023-09-20.
// https://school.programmers.co.kr/learn/courses/30/lessons/62048

using namespace std;

int makeGCD(int a, int b){
	if (b == 0){
		return a;
	}
	return makeGCD(b, a%b);
}

long long solution(int w, int h) {
	long long answer = 1;

	int gcd = makeGCD(w, h);
	answer = (long long)w * (long long)h;
	answer -= gcd * (w / gcd + h / gcd - 1);
	return answer;
}