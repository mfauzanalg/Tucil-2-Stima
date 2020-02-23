#include "other.hpp"
#include <iostream>
#include <vector>
using namespace std;

void CetakPol (vector<int> pol){
//Prosedur untuk mencetak polinom
	int i;
	for (i = 0; i < pol.size(); i++){
		if (pol[i] != 0){
			if (i == 0){
				cout << pol[i];
			}
			else if (i == 1){
				if (pol[i] < 0) cout << " - " << (-1*pol[i]) << "x";
				else if (pol[i] > 0) cout << " + " << pol[i] << "x";
			}
			else{
				if (pol[i] < 0) cout << " - " << (-1*pol[i]) << "x^" << i;
				else if (pol[i] > 0) cout << " + " << pol[i] << "x^" << i;
			}
		}
	}
	cout << endl;
}

int max(int x, int y){
//Fungsi untuk menghasilkan integer maksimum
	return (x>y)? x: y;
}

vector<int> Sum (vector<int> pol1, vector<int> pol2){
//Fungsi untuk menjumlahkan polinom
	int size = max(pol1.size(), pol2.size());
	int i;
	vector<int> sum(size);
	for (int i = 0; i < pol1.size(); i++){
		sum[i] = pol1[i];
	}
	for (int i = 0; i < pol2.size(); i++){
		sum[i] += pol2[i];
	}
	return sum;
}

vector<int> Min (vector<int> pol1, vector<int> pol2){
//Fungsi untuk mengurangkan polinom
	int size = max(pol1.size(), pol2.size());
	int i;
	vector<int> sum(size);
	for (int i = 0; i < pol1.size(); i++){
		sum[i] = pol1[i];
	}
	for (int i = 0; i < pol2.size(); i++){
		sum[i] -= pol2[i];
	}
	return sum;
}

vector<int> Multi (vector<int> pol1, int n){
//Fungsi untuk menaikkan derajat polinom sebanyak n
	int i;
	vector<int> multi(pol1.size()+n);
	for (i = 0; i < pol1.size(); i ++){
		multi[i+n] = pol1[i];
	}
	return multi;
}


void Divide (vector<int> pol1, vector<int> pol2, vector<int> *A0, vector<int> *B0, vector<int> *A1, vector<int> *B1, int n){
//Membagi polinom menjadi dua bagian yang sama besar, jika ganjil dilebihkan pada polinom yang kedua
	int i;

	for(i = 0; i <= n-1; i++){
		(*A0).push_back(pol1[i]);
		(*B0).push_back(pol2[i]);
	}
	for(i = n; i < pol1.size(); i++){
		(*A1).push_back(pol1[i]);
		(*B1).push_back(pol2[i]);
	}

}