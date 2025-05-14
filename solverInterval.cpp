#include "solverInterval.hpp"

void SolverInterval::computeSolutionFromIntervals(){
    uint compt=1;
    for (vector<pair<uint, uint>>::iterator it2 = solutionInterval.begin() ; it2 != solutionInterval.end(); ++it2){
        for (uint i = it2->first; i<= it2->second ; i++)
            solution.at(i) = compt;
        compt ++;
    }

}

//TODO
bool SolverInterval::checkIsSorted()
{
    return true;
}

//TODO
void SolverInterval::resort()
{
    if (checkIsSorted()) return;
}

/*
void SolverInterval::solve(){
}
*/
