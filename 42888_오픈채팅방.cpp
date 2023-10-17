//
// Created by KangMinji on 2023-10-17.
//

#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
typedef pair<string, string> ci;
const string ENTER = "님이 들어왔습니다.";
const string LEAVE = "님이 나갔습니다.";

map<string, string> mp; // {uid, nickname};
vector<ci> logs;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	// 입력 & 연산
	string op, uid, nickname;
	for (string input : record){
		stringstream ss(input);
		ss >> op >> uid >> nickname;

		if (op == "Change") {
			mp[uid] = nickname;
		} else if (op == "Enter"){
			mp[uid] = nickname;
			logs.push_back({uid, ENTER});
		} else if (op == "Leave"){
			logs.push_back({uid, LEAVE});
		}
	}

	// 출력
	for (ci log : logs){
		string nickname = mp[log.first];
		answer.push_back(nickname + log.second);
	}
	return answer;
}