//
// Created by KangMinji on 2023-11-09.
//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

string changeStr(string s){
	string temp;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s.size()-1&&s[i+1]=='#'){
			temp+=(s[i]-'A'+'a');
			i++;
		} else {
			temp+=s[i];
		}
	}
}

vector<string> parseMusicInfo(string input) {
	istringstream iss(input);
	string token;

	vector<string> tokens;
	while(getline(iss, token, ',')) {
		tokens.push_back(token);
	}
	return tokens;
}

int calcMusicLength(string t1, string t2) {
	int h1 = stoi(t1.substr(0, 2));
	int m1 = stoi(t1.substr(3, 2));
	int h2 = stoi(t2.substr(0, 2));
	int m2 = stoi(t2.substr(3, 2));

	return (h2*60 + m2) - (h1*60 + m1);
}

string makeNoteList(string note, int musicLength) {
	string noteList = "";

	for (int i=0; i<musicLength; i++){
		noteList += note[i % note.length()];
	}
	return noteList;
}

bool cmpNote(string m, string target) {
	if (target.find(m) != string::npos){
		return true;
	}
	return false;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";

	m = changeStr(m);
	int answerLength = -1;
	for (int i=0; i<musicinfos.size(); i++) {
		string musicinfo = musicinfos[i];
		vector<string> tokens = parseMusicInfo(musicinfo);

		int musicLength = calcMusicLength(tokens[0], tokens[1]);
		string changedNote = changeStr(tokens[3]);
		string note = makeNoteList(changedNote, musicLength);
		if (cmpNote(m, note)){
			if (musicLength > answerLength) {
				answerLength = musicLength;
				answer = tokens[2];
			}
		}
	}
	return answer;
}