/*
 * My implementation of classical algorithms
 *
 * */

#include <iostream>
#include <vector>
#include <string>

#include "greedy.h"

void activitySelectionProblemTests()
{
	unsigned wrongs = 0;

	greedy::activity a1_1(10,20);
	greedy::activity a1_2(12,25);
	greedy::activity a1_3(20,30);
	vector<greedy::activity> a1Solution = greedy::solveActivitySelectionProblem({a1_1,a1_2,a1_3});
	if(a1Solution.size() != 2)
	{
		cout << "Activity Selection Problem a1 WRONG!" << endl;
		wrongs++;
	}

	greedy::activity a2_1(1,2);
	greedy::activity a2_2(3,4);
	greedy::activity a2_3(0,6);
	greedy::activity a2_4(5,7);
	greedy::activity a2_5(8,9);
	greedy::activity a2_6(5,9);
	vector<greedy::activity> a2Solution = greedy::solveActivitySelectionProblem({a2_1,a2_2,a2_3,a2_4,a2_5,a2_6});
	if(a2Solution.size() != 4)
	{
		cout << "Activity Selection Problem a2 WRONG!" << endl;
		wrongs++;
	}

	greedy::activity a3_1(5,9);
	greedy::activity a3_2(1,2);
	greedy::activity a3_3(3,4);
	greedy::activity a3_4(0,6);
	greedy::activity a3_5(5,7);
	greedy::activity a3_6(8,9);
	vector<greedy::activity> a3Solution = greedy::solveActivitySelectionProblem({a3_1,a3_2,a3_3,a3_4,a3_5,a3_6});
	if(a3Solution.size() != 4)
	{
		cout << "Activity Selection Problem a3 WRONG!" << endl;
		wrongs++;
	}

	if(wrongs == 0)
	{
		cout << "Activity Selection Problem Tests OK." << endl;
	}
	if(wrongs != 0)
	{
		cout << "Activity Selection Problem Tests WITH ERRORS." << endl;
	}
}

void activitySelectionProblemDemo()
{
	cout << "Demo of greedy solution for Activity Selection Problem." << endl;
	cout << "Now enter as many activities as you want." << endl;

	vector<greedy::activity> activities;
	while(true)
	{
		cout << "Do you want to enter new activity? ('YES' for yes & whatever else for NO)" << endl;
		string answer;
		cin >> answer;

		if(answer.compare("YES") == 0)
		{
			cout << "Enter start time and end time of the activity separated by space" << endl;
			unsigned startTime, endTime;
			cin >> startTime >> endTime;

			activities.push_back(greedy::activity(startTime,endTime));
		}
		else
		{
			cout << "You have entered '" << answer << "', which is not 'YES'. Now I will solve the problem for the activities entered." << endl;
			break;
		}
	}

	cout << "The solution is: ";
	for(auto activity : greedy::solveActivitySelectionProblem(activities))
	{
		cout << "(" << activity.startTime << "," << activity.endTime << "),";
	}

	cout << endl;
}

using namespace std;

int main()
{
	activitySelectionProblemTests();
	activitySelectionProblemDemo();
}
