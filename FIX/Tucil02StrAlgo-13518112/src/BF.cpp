#include "BF.hpp"
#include <iostream>
#include <vector>
using namespace std;

vector<int> BF(vector<int> pol1, vector<int> pol2, int *cKali, int *cTambah){
// Output berupa array polinom hasil perkalian pol1 dan pol2 dengan metode Brute Force
	int i,j;
	*cKali = 0;
	*cTambah = 0;
	vector<int> pol3(pol1.size()+pol2.size());

	for (i = 0; i < pol1.size(); i++){
		for (j = 0; j< pol2.size(); j++){
			pol3[i+j] += pol1[i] * pol2[j];
			*cKali += 1;		// Menghitung jumlah operasi kali
			*cTambah += 1;		// Menghitung jumlah operasi tambah
		}
	}
	return pol3;
}