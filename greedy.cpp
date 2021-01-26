#include "greedy.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace greedy;


bool compActivities(activity a1,activity a2)
{
	return a1.endTime < a2.endTime;
}


/*
 * Greedy solution of Activity selection problem: https://en.wikipedia.org/wiki/Activity_selection_problem
 *
 * */
vector<activity> greedy::solveActivitySelectionProblem(vector<activity> activities)
{
	sort(activities.begin(), activities.end(), compActivities);

	vector<activity> solution;

	if(activities.size() == 0)
	{
		return solution;
	}
	else
	{
		solution.push_back(activities.front());
	}

	for(auto activitiesIt = activities.begin()+1; activitiesIt != activities.end();++activitiesIt)
	{
		if(activitiesIt->startTime >= solution.back().endTime)
		{
			solution.push_back(*activitiesIt);
		}
	}

	return solution;
}
