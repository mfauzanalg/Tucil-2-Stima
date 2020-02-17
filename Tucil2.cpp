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

int main(){
    int n, i,a ,b;
    int cKali, cTambah;
    vector<int> pol1;
    vector<int> pol2;
    vector<int> pol3;
    // vector<int> pol4;

    cout << "Masukkan panjang suku polinom : ";
	cin >> n;
	while (n < 1){
		cout << "Minimal n bernilai 1" << endl;
		cout << "Masukkan panjang suku polinom : ";
		cin >> n;
	}

	srand((unsigned)time(0));
	for (i = 0; i < n; i++){
		a = (rand() % 200) - 100;
		b = (rand() % 200) - 100;
		if (i == n-1){
			do{
			a = (rand() % 200) - 100;
			b = (rand() % 200) - 100;
			} while (a == 0 or b == 0);
		}
		pol1.push_back(a);
		pol2.push_back(b);
	}

	CetakPol(pol1);
	CetakPol(pol2);
	cout << endl;

	cout << "[ALGORITMA BRUTEFORCE]" << endl;
	auto startBF = high_resolution_clock::now();
	pol3 = BF(pol1, pol2, &cKali, &cTambah);
	auto stopBF = high_resolution_clock::now();
	auto durationBF = duration_cast<microseconds>(stopBF - startBF).count(); 

	cout << "hasil perklian polinom	: "; CetakPol(pol3);
	cout << "jumlah operasi kali	: " << cKali << endl;
	cout << "jumlah operasi tambah	: " << cTambah << endl;
	cout << "waktu yang dibutuhkan	: " << durationBF << " microseconds" << endl;

	cout << endl;


    return 0;
}