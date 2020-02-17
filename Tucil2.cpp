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
		if (i == 0){
			cout << pol[i];
		}
		else{
			if (pol[i] < 0){
				cout << " - " << (-1*pol[i]) << "x^" << i;
			}
			else if (pol[i] > 0){
				cout << " + " << pol[i] << "x^" << i;
			}
		}
	}
	cout << endl;
}

int main(){
    int n, i;
    vector<int> pol1;
    vector<int> pol2;

    cout << "Masukkan panjang suku polinom : ";
	cin >> n;
	while (n < 0){
		cout << "Minimal n bernilai 0" << endl;
		cout << "Masukkan panjang suku polinom : ";
		cin >> n;
	}

	srand(time(0));
	for (i = 0; i < n; i++){
		pol1.push_back(rand() % 100);
		pol2.push_back(rand() % 100);
	}

	CetakPol(pol1);
	CetakPol(pol2);

	cout << endl << "Hasil perkalian polinom : " << endl;
    



    return 0;
}