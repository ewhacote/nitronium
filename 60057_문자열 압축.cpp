#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.size();
    
    int len = s.size();
    for (int i=1; i<=len/2; i++) {
        string tmp = "";
        string target = s.substr(0, i); // 반복되는 문자열
        int same_cnt = 1; // 반복 횟수
        
        for (int j=i; j<len; j+=i){
            if (target == s.substr(j, i))
                same_cnt++;
            else { // 반복이 끝난 경우
                if (same_cnt > 1) {
                    tmp += to_string(same_cnt);
                }
                tmp += target;
                // 초기화
                target = s.substr(j, i);
                same_cnt = 1;
            }
        }
        if (same_cnt > 1) {
            tmp += to_string(same_cnt);
        }
        tmp += target;
       
        // 최소인 경우
        if (answer > tmp.size()){
            answer = tmp.size();
        }
    }
    return answer;
}
