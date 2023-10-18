#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int start = 0;
	int limit = number.size() - k;

	// 찾아야 하는 숫자 개수만큼 돌기
	for (int i=0; i<limit; i++){
		char max_num = number[start]; // 처음 검사 대상
		int max_idx = start;
		// 앞에서 남길 수 있는 숫자 중에 제일 큰 수 체크
		for (int j=start; j<=k+i; j++){
			if (max_num < number[j]){
				max_num = number[j];
				max_idx = j;
			}
		}
		answer += max_num;
		start = max_idx + 1;
	}
	return answer;
}