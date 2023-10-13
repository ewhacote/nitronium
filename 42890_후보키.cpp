#include <string>
#include <vector>
#include <set>
using namespace std;

bool check(vector<int> answer, int cur) {
	for (int i=0; i<answer.size(); i++) {
		if ((answer[i] & cur) == answer[i]){
			return false;
		}
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int rowSize = (int)relation.size();
	int colSize = (int)relation[0].size();
	vector<int> answer;

	int max_cnt = 1<<colSize;
	for (int i=0; i<max_cnt; i++){
		set<string> s;

		for (int j=0; j<rowSize; j++){
			string cur = "";

			for (int k=0; k<colSize; k++){
				if (i & (1 << k)) {
					cur += relation[j][k];
				}
			}
			s.insert(cur);
		}

		if (s.size() == rowSize && check(answer, i)){
			answer.push_back(i);
		}
	}
	return answer.size();
}