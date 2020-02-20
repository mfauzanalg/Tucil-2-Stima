#ifndef ___OTHER___HPP
#define ___OTHER___HPP
#include <vector>
using namespace std;

void CetakPol (vector<int> pol);
vector<int> Sum (vector<int> pol1, vector<int> pol2);
vector<int> Min (vector<int> pol1, vector<int> pol2);
vector<int> Multi (vector<int> pol1, int n);
void Divide (vector<int> pol1, vector<int> pol2, vector<int> *A0, vector<int> *B0, vector<int> *A1, vector<int> *B1, int n);


#endif