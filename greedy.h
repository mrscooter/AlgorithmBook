/*
 * greedy.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: nicnajder
 */



#ifndef GREEDY_H
#define GREEDY_H

#include <vector>

using namespace std;

namespace greedy
{

struct activity
{
	unsigned startTime;
	unsigned endTime;

	activity(unsigned startTime0, unsigned endTime0):startTime(startTime0),endTime(endTime0){};
};

vector<activity> solveActivitySelectionProblem(vector<activity> activities);

}

#endif
