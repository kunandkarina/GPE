// #include<iostream>
// #include<string>
// #include<cstring>
// #include<sstream>
// #include<algorithm>
// using namespace std;

// const int maxContestants = 101;
// const int maxProblems = 10;

// struct Contestants{
// 	int id;
// 	int problemSolve;
// 	int penaltyTime;
// 	bool flag;
// 	//string L;
// };

// int compare(Contestants a, Contestants b){
// 	if(a.problemSolve == b.problemSolve && a.penaltyTime == b.penaltyTime){
// 		return a.id < b.id;
// 	}else if(a.problemSolve == b.problemSolve){
// 		return a.penaltyTime < b.penaltyTime;
// 	}else return a.problemSolve > b.problemSolve;
// }

// int main(){
// 	Contestants contestants[101];
// 	int incorrect[maxContestants][maxProblems];
// 	int firstTime[maxContestants][maxProblems];

// 	int testcase;
// 	int contestant;
// 	int problem;
// 	int time;
// 	string line;
// 	string L;

// 	// cin.ignore();
// 	// getline(cin, line);
// 	while(scanf("%d", &testcase) != EOF){
// 		getchar();
// 		getchar();
// 		while(testcase--){
// 			memset(incorrect,0,sizeof(incorrect));
// 			memset(firstTime,0,size_t(firstTime));

// 			for(int i=0;i<maxContestants;i++){
// 				contestants[i].id = i;
// 				contestants[i].problemSolve = 0;
// 				contestants[i].penaltyTime = 0;
// 				contestants[i].flag = false;

// 			}

// 			while(getline(cin, line) && (line != "")){
// 				stringstream ss;
// 				ss.clear();
// 				ss.str(line);
// 				ss >> contestant >> problem >> time >> L;
// 				contestants[contestant].flag = true;
// 				if(L == "I"){
// 					incorrect[contestant][problem]++;
// 				}
// 				if(L == "C"){
// 					if(firstTime[contestant][problem] == 0  /*沒想到*/){
// 						firstTime[contestant][problem] = time;
// 						contestants[contestant].problemSolve++;/*沒想到*/
// 						contestants[contestant].penaltyTime += time + incorrect[contestant][problem]*20; /*沒想到*/
// 					}
// 				}
// 			}

// 			sort(contestants, contestants + maxContestants, compare);
// 			for(int i=0;i<maxContestants;i++){
// 				if(contestants[i].flag == true){
// 					cout << contestants[i].id << " " << contestants[i].problemSolve << " " << contestants[i].penaltyTime << endl;
// 				}
// 			}

// 			if(testcase != 0) cout << endl;
// 		}
// 		return 0;
// 	}
// }

#include <bits/stdc++.h>
using namespace std;

struct Team
{
  int id;
  int problemSolve;
  int penaltyTime;
  bool flag;
};

bool compare(Team a, Team b)
{
  if (a.problemSolve > b.problemSolve)
    return true;
  if (a.problemSolve < b.problemSolve)
    return false;
  if (a.penaltyTime < b.penaltyTime)
    return true;
  if (a.penaltyTime > b.penaltyTime)
    return false;
  if (a.id < b.id)
    return true;
  return false;
}

int main()
{
  int testcase;
  Team teams[105];
  int contestant, problem, time;
  int inCorrect[105][10];
  int firstSolve[105][10];
  string line;
  //istringstream iss;
  string L;
  cin >> testcase;
  getchar();
  getchar();
  // while(getchar() != '\n'){}
  // for(int i=0;i<testcase;i++)
  while (testcase--)
  {
    memset(inCorrect, 0, sizeof(inCorrect));
    memset(firstSolve, 0, sizeof(firstSolve));
    for (int i = 0; i < 105; i++)
    {
      teams[i].id = i;
      teams[i].penaltyTime = 0;
      teams[i].problemSolve = 0;
      teams[i].flag = false;
    }

    while (getline(cin, line) && (line != ""))
    {
      // ss.clear();
      // ss.str(line);
      istringstream iss(line);
      iss >> contestant >> problem >> time >> L;
      teams[contestant].flag = true;
      if (L == "C")
      {
        if (firstSolve[contestant][problem] == 0)
        {
          firstSolve[contestant][problem] = time;
          teams[contestant].penaltyTime += time + inCorrect[contestant][problem] * 20;
          teams[contestant].problemSolve++;
        }
      }
      else if (L == "I")
      {
        inCorrect[contestant][problem]++;
      }
    }

    sort(teams, teams + 105, compare);
    for (int i = 0; i < 105; i++)
    {
      if (teams[i].flag)
      {
        printf("%d %d %d\n", teams[i].id, teams[i].problemSolve, teams[i].penaltyTime);
      }
    }
    if (testcase != 0)
      cout << endl;
  }
  return 0;
}