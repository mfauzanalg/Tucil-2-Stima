#ifndef ___OTHER___HPP
#define ___OTHER___HPP
#include <vector>
using namespace std;

void CetakPol (vector<int> pol);
//Prosedur untuk mencetak polinom

int max(int x, int y);
//Fungsi untuk menghasilkan integer maksimum

vector<int> Sum (vector<int> pol1, vector<int> pol2);
//Fungsi untuk menjumlahkan polinom

vector<int> Min (vector<int> pol1, vector<int> pol2);
//Fungsi untuk mengurangkan polinom

vector<int> Multi (vector<int> pol1, int n);
//Fungsi untuk menaikkan derajat polinom sebanyak n

void Divide (vector<int> pol1, vector<int> pol2, vector<int> *A0, vector<int> *B0, vector<int> *A1, vector<int> *B1, int n);
//Membagi polinom menjadi dua bagian yang sama besar, jika ganjil dilebihkan pada polinom yang kedua

#endif