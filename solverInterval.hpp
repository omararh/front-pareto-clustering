#pragma once

#include "solver.hpp"
#include <utility>


class SolverInterval : public Solver {

protected:

	vector<pair<uint,uint>> solutionInterval;
	void computeSolutionFromIntervals();

    bool checkIsSorted(); //TODO
    void resort(); //TODO

/*
public:
		void solve();
*/
};



