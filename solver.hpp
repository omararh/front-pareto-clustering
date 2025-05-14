#pragma once
#include <vector>
#include <string>

using namespace std;

class Solver {

	private:

    uint D; //dimension

    void displayPoint(uint k);


	protected:
    vector<float> points; //

    uint K; //nb of clusters
    uint N; //nb of points

    vector<uint> solution; // indexes of points
    double solutionCost;

   double squaredDistance(uint i, uint ii);
   double distance(uint i, uint ii);
   double distancePower(uint i, uint ii, float a);


    public:

    virtual void solve()=0;

    //double getXpoint(uint i){return (double) points[D*i];};
    //double getYpoint(uint i){return (double) points[D*i+1];};
    double getSolutionCost(){return solutionCost;};
    int getNbClusters(){return K;};
    int getNbPoints(){return N;};

    void setNbClusters(int k){K=k;};
    void import(string filename);
    void displayInstance();
    void displaySolution();
    //void write_result(string filename);

};

/*
class Solver2D : public Solver {

    double squaredDistance(uint i, uint ii) override;


}
*/
