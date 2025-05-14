#include <iostream>
#include "solverDP.hpp"

void SolverDP::printFinalCosts(string sep){
	//cout << endl;
    /*
	for(int i = 0; i <K; i++){
		cout << matrixDP.getElement(i,N-1) << sep;
	}
	cout << endl;
    */
}


void SolverDP::printMatrixDP(){
    /*
	cout << endl;
	for(int i = K-1; i >=0; i--){
		for(int n = 0; n < N;n++) 	cout << matrixDP.getElement(i,n) << " ";
		cout << endl;
	}
	cout << endl;
    */
}

void SolverDP::fillFirstLine()
{
    vector<double> v;
    v.resize(N);/*
    clusterCostsFromBeginning(v);
    for(uint i = 0; i <N-1; i++)
        matrixDP.setElement(i,0,v[i]);
*/
}

void SolverDP::solve(){
    resort();
    matrixDP.initMatrix(N,K-1);

    vector<double> v;
    v.resize(N);
    fillFirstLine();
    for(uint n = 1; n <N-1; n++){
        clusterCostsBefore(n,v);
    }
    matrixDP.deleteMatrix();
    //bactracking operations
}
