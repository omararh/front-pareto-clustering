#pragma once

#include "matrixDouble.hpp"
#include "solverInterval.hpp"
//#include <utility>


class SolverDP : public SolverInterval {
    
protected:

    //Matrix<double> matrixDP;
    MatrixDouble matrixDP;
    uint lastIndex;
    void fillFirstLine();
    virtual void clusterCostsBefore(uint i, vector<double> & v)=0;
    virtual void clusterCostsFromBeginning(vector<double>  & v)=0;


public:

    void solve();
    void printMatrixDP();
	void printFinalCosts(string sep);
};

