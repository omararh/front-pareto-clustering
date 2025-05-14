#include <iostream>
#include "mediansDP.hpp"

using namespace std;

int main(int argc, char **argv)
{
    /*
        if(argc < 7){
            cout << "Need 7 arguments\n";
            return 0;
        }
    */
        int k = 2;
        float a = 1.0;
        double timeSolve=-1;


        //string filename = "data/dataAlea2_50/dataAlea2_50_ex1.txt";
        string filename = "../data/data2.txt";


        int solverType=999;


        //if(argc > 1) solverType = solverTypeToInt(argv[1]);
        if(argc > 2) k = atoi(argv[2]);
        if(argc > 3) filename = //"../data/" +
                argv[3];
        //if(argc > 4) a = atoi(argv[4]);


        MediansDP solver;
        solver.import(filename);
        solver.setNbClusters(k);
        solver.displayInstance();
        solver.solve();


    return 0;
}
