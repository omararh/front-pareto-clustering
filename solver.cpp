#include <iostream>
#include <cmath>
#include <fstream>

#include "solver.hpp"

void Solver::import(string filename) {
    points.clear();
    solution.clear();
    ifstream file(filename);
    float tmpFLOAT = -1;

    if (file.good() != true)
    {
        cout << "Fatal error : unable to read file " << filename << "!" << endl;
        exit(EXIT_FAILURE);
    }

    file >> tmpFLOAT;//tmpUINT;
    N= static_cast<int> (tmpFLOAT);
    cout << "Valeur de N : " << N << endl;

    if (file.good() != true)
    {
        cout << "Fatal error : cannot read dimension !" << endl;
        exit(EXIT_FAILURE);
    }
    file >> tmpFLOAT;//tmpUINT;
    D= static_cast<int> (tmpFLOAT);
    cout << "Valeur de D : " << D << endl;
    uint siz = N*D;
    points.reserve(siz);
    uint pt=0;

    if (file.good() != true)
    {
        cout << "Fatal error : cannot read the points " << filename << "!" << endl;
        exit(EXIT_FAILURE);
    }


    while (file >> tmpFLOAT)
    {  if(file.good()){
            points[pt]= tmpFLOAT;
            //cout << "Ajout de   " << tmpFLOAT << endl;
            pt ++;
            }
    }

    if (pt != N*D)
    {
        cout << "Fatal error : size problem, read  " << pt << " coordiantes instead of " << N*D << endl;
        exit(EXIT_FAILURE);
    }

    solution.resize(N);

}


void Solver::displayInstance() {
	cout<<"Liste des points de l'instance:\n";
	 for (int i=0 ; i<N; ++i){
         displayPoint(i);
         cout << endl;
     }
     //cout << endl;
	}
void Solver::displayPoint(uint k) {
    cout << "( ";
    for (int d=0 ; d<D; ++d)
        cout <<  points[D*k+d] << ((d<D-1)?" , " : "");//" , ";//
    cout << " )";

}

void Solver::displaySolution() {
    cout<<"\nSolutions en clusters:\n";
    for(uint k=1; k<=K; k++){
        cout<<"Cluster " << k << " : ";
        for (vector<uint>::iterator it2 = solution.begin() ; it2 != solution.end(); ++it2){
            if (solution.at(*it2) ==k) displayPoint(*it2);
        }

    }
/*	 cout<<"\nSolutions en clusters:\n";
     for (vector<pair<uint, uint>>::iterator it2 = solution.begin() ; it2 != solution.end(); ++it2){
		 cout << "(" << it2->first << "," << it2->second << ") ";
	 }
	 cout <<endl<<endl;
     */
}






double Solver::squaredDistance(uint i, uint ii){
    double result = (double) points[2*i] - points[2*ii];
    result *= result;
    for (uint d=1; d<D; d++)
    result += (double) (points[2*i+d] - points[2*ii+d])*(points[2*i+d] - points[2*ii+d]);
    return result;
}

double Solver::distance(uint i, uint ii){
    return sqrt(squaredDistance(i,ii));}


double Solver::distancePower(uint i, uint ii, float a){
    return pow(squaredDistance(i,ii), 0.5 *a);
}

/*
void Solver::write_result(string filename){
    ofstream file(filename.c_str());
    if(file.is_open()){
    	file << "cost : " << OPT <<endl;;
    	file << "clusters:\n";
        for(int i = solution.size()-1; i >= 0; i--){
            file << (solution)[i].first << " " << (solution)[i].second << "\n";
        }
        file.close();
        }
 }
 */
/*
double Solver2D::squaredDistance(uint i, uint ii){
    double a = (double) points[2*i] - points[2*ii];
    double b = (double) points[2*i+1] - points[2*ii+1];
    return a*a +  b *b;
}
*/
