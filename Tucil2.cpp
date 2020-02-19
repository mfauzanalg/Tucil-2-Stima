#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <chrono> 
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono; 

void CetakPol (vector<int> pol){
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
	return (x>y)? x: y;
}

vector<int> Sum (vector<int> pol1, vector<int> pol2){
	int size = max(pol1.size(), pol2.size());
	int i;
	vector<int> sum(size);
	for (int i = 0; i < pol1.size(); i++){
		sum[i] = pol1[i];
	}
	for (int i = 0; i < pol2.size(); i++){
		sum[i] += pol2[i];
	}

	while (sum[sum.size()-1] == 0){
		sum.pop_back();
	}
	return sum;
}

vector<int> Min (vector<int> pol1, vector<int> pol2){
	int size = max(pol1.size(), pol2.size());
	int i;
	vector<int> sum(size);
	for (int i = 0; i < pol1.size(); i++){
		sum[i] = pol1[i];
	}
	for (int i = 0; i < pol2.size(); i++){
		sum[i] -= pol2[i];
	}

	while (sum[sum.size()-1] == 0){
		sum.pop_back();
	}
	return sum;
}

vector<int> Multi (vector<int> pol1, int n){
	int i;
	vector<int> multi(pol1.size()+n, 0);
	for (i = 0; i < pol1.size(); i ++){
		multi[i+n] = pol1[i];
	}
	return multi;
}

vector<int> BF(vector<int> pol1, vector<int> pol2, int *cKali, int *cTambah){
	int i,j;
	*cKali = 0;
	*cTambah = 0;
	vector<int> pol3(pol1.size()+pol2.size());

	for (i = 0; i < pol1.size(); i++){
		for (j = 0; j< pol2.size(); j++){
			pol3[i+j] += pol1[i] * pol2[j];
			*cKali += 1;
			*cTambah += 1;
		}
	}
	return pol3;
}

vector<int> DNC(vector<int> pol1, vector<int> pol2, int *cKali, int *cTambah){
	if(pol1.size() == 1 and pol2.size() == 1){
		vector<int> pol3(1);
		pol3[0] = pol1[0] * pol2[0];
		return pol3;
	}
	else{
		int i, j = 0;
		int n = pol1.size()/2;
		cout << n << endl;
		vector<int> A0(n);
		vector<int> B0(n);
		vector<int> A1(pol1.size()-n);
		vector<int> B1(pol1.size()-n);
		for(i = 0; i <= n-1; i++){
			A0[i] = pol1[i];
			B0[i] = pol2[i];
		}
		for(i = n; i < pol1.size(); i++){
			A1[j] = pol1[i];
			B1[j] = pol2[i];
			j++;
		}
		
		vector<int> Y = DNC(Sum(A0, A1), Sum(B0, B1), &*cKali, &*cTambah);
		vector<int> U = DNC(A0, B0, &*cKali, &*cTambah);
		vector<int> Z = DNC(A1, B1, &*cKali, &*cTambah);

		*cTambah += 4;
		*cKali += 2;
		return Sum(Sum(Multi(Min(Min(Y, U), Z), n), U), Multi(Z, n*2));
	}
}


int main(){
    int n, i,a ,b;
    int cKali, cTambah;
    vector<int> pol1;
    vector<int> pol2;
    vector<int> pol3;
    vector<int> pol4;

    cout << "Masukkan panjang suku polinom : ";
	cin >> n;
	while (n < 0){
		cout << "Minimal n bernilai 0" << endl;
		cout << "Masukkan panjang suku polinom : ";
		cin >> n;
	}

	srand(time(0));
	for (i = 0; i <= n; i++){
		a = (rand() % 5) - 3;
		b = (rand() % 5) - 3;
		if (i == n){
			do{
			a = (rand() % 5) - 3;
			b = (rand() % 5) - 3;
			} while (a == 0 or b == 0);
		}
		pol1.push_back(a);
		pol2.push_back(b);
	}

	cout << "polinom 1  : "; CetakPol(pol1);
	cout << "polinom 2  : "; CetakPol(pol2);
	cout << endl;

	cout << "[ALGORITMA BRUTE FORCE]" << endl;
	auto startBF = high_resolution_clock::now();
	pol3 = BF(pol1, pol2, &cKali, &cTambah);
	auto stopBF = high_resolution_clock::now();
	auto durationBF = duration_cast<microseconds>(stopBF - startBF).count(); 

	cout << "hasil perklian polinom	: "; CetakPol(pol3);
	cout << "jumlah operasi kali	: " << cKali << endl;
	cout << "jumlah operasi tambah	: " << cTambah << endl;
	cout << "waktu yang dibutuhkan	: " << durationBF << " microseconds" << endl;
	cout << endl;

	cout << "[ALGORITMA DIVIDE AND CONQUER]" << endl;
	cKali = 0;
	cTambah = 0;
	auto startDNC = high_resolution_clock::now();
	pol4 = DNC(pol1, pol2, &cKali, &cTambah);
	auto stopDNC = high_resolution_clock::now();
	auto durationDNC = duration_cast<microseconds>(stopDNC - startDNC).count(); 

	cout << "hasil perklian polinom	: "; CetakPol(pol4);
	cout << "jumlah operasi kali	: " << cKali << endl;
	cout << "jumlah operasi tambah	: " << cTambah << endl;
	cout << "waktu yang dibutuhkan	: " << durationDNC << " microseconds" << endl;
	cout << endl;


    return 0;
}