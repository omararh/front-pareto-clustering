#pragma once

#include "solverDP.hpp"
//#include <utility>


class MediansDP : public SolverDP {
    
protected:

    double alpha;
    void clusterCostsBefore(uint i, vector<double> & v) override;
    void clusterCostsFromBeginning(vector<double>  & v) override;

/*
public:

    void solve();
*/


};

