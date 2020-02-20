#include <iostream>
#include "DNC.hpp"
#include "BF.hpp"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <chrono> 
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono; 

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
		a = (rand() % 200) - 100;
		b = (rand() % 200) - 100;
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

