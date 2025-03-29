#include <fstream>
#include <vector>
using namespace std;

void countingSort(int*& A, int*& B, int najmanjseStevilo, int najvecjeStevilo, int trenutnaVelikost){
    int velikostC = najvecjeStevilo - najmanjseStevilo + 1;
    
	int* C = new int[velikostC];
	for (int i = 0; i < velikostC; i++) {
		C[i] = 0;
	}

	for (int i = 0; i < trenutnaVelikost; i++) {
		C[A[i]] = C[A[i]] + 1;
	}

	for (int i = 1; i < velikostC; i++) {
		C[i] = C[i] + C[i - 1];
	}

	B = new int[trenutnaVelikost];
	
	for (int i = trenutnaVelikost - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i] + najmanjseStevilo;
		C[A[i]] = C[A[i]] - 1;
	}

	delete[] C;
}

void romanSort(int*& A, int*& B, int najmanjseStevilo, int najvecjeStevilo, int trenutnaVelikost){}

bool Branje_Stevil(int*& A, const char s[], int& velikost, int& najmanjseStevilo, int& najvecjeStevilo){}

void Izpis_Stevil(int* polje, unsigned int velikost){
    ofstream output("out.txt");

	for (int i = 0; i < velikost; i++)
		output << polje[i] << ' ';
}

int main(int argc, const char* argv[]){

    return 0;
}