#include "DNC.hpp"
#include "other.hpp"
#include <iostream>
using namespace std

vector<int> DNC(vector<int> pol1, vector<int> pol2, int *cKali, int *cTambah){
	if(pol1.size() == 1 or pol2.size() == 1){
		vector<int> pol3(1);
		pol3[0] = pol1[0] * pol2[0];
		return pol3;
	}
	else{
		int i;
		int n = pol1.size()/2;
		vector<int> A0, B0, A1, B1;
		Divide(pol1, pol2, &A0, &B0, &A1, &B1, n);
		
		vector<int> Y = DNC(Sum(A0, A1), Sum(B0, B1), &*cKali, &*cTambah);
		vector<int> U = DNC(A0, B0, &*cKali, &*cTambah);
		vector<int> Z = DNC(A1, B1, &*cKali, &*cTambah);

		*cTambah += 4;
		*cKali += 2;
		return Sum(Sum(Multi(Min(Min(Y, U), Z), n), U), Multi(Z, n*2));
	}
}