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
  string L;
  cin >> testcase;
  getchar();
  getchar();
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