#include <fstream>
#include <vector>
using namespace std;

void countingSort(int*& A, int*& B, int najmanjseStevilo, int najvecjeStevilo, int trenutnaVelikost){
    int velikostC = najvecjeStevilo - najmanjseStevilo + 1;

    //podpora negativnim
	for (int i = 0; i < trenutnaVelikost; i++) {
		A[i] = A[i] - najmanjseStevilo;
	}

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

void romanSort(int*& A, int*& B, int najmanjseStevilo, int najvecjeStevilo, int trenutnaVelikost){
    int velikostC = najvecjeStevilo - najmanjseStevilo + 1;

    //podpora negativnim
	for (int i = 0; i < trenutnaVelikost; i++) {
		A[i] = A[i] - najmanjseStevilo;
	}

	int* C = new int[velikostC];
	for (int i = 0; i < velikostC; i++) {
		C[i] = 0;
	}

	for (int i = 0; i < trenutnaVelikost; i++) {
		C[A[i]] = C[A[i]] + 1;
	}

	B = new int[velikostC];

	int trenutniB = 0;
	for (int i = 0; i < velikostC; i++) {
		while (C[i] > 0) {
			if (trenutniB < velikostC) {
				B[trenutniB] = i + najmanjseStevilo;
				trenutniB++;
				C[i]--;
			}
		}
	}

	delete[] C;
}

bool Branje_Stevil(int*& A, const char s[], int& velikost, int& najmanjseStevilo, int& najvecjeStevilo){
    ifstream input(s);
	int st;
	int trenutnaVelikost = 0;
	int maxVelikost = 100;
	A = new int[maxVelikost];

	najmanjseStevilo = INT_MAX;
	najvecjeStevilo = INT_MIN;
	

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		A[trenutnaVelikost] = st;
		trenutnaVelikost++;

		//dobi najmanjse stevilo
		if (st < najmanjseStevilo) {
			najmanjseStevilo = st;
		}

		//dobi najvecje steilo
		if (st > najvecjeStevilo) {
			najvecjeStevilo = st;
		}

		//povecuje veilkost A ce je premajhen
		if (trenutnaVelikost == maxVelikost) {
			maxVelikost *= 2;
			int* povecanoPolje = new int[maxVelikost];

			for (int i = 0; i < trenutnaVelikost; i++) {
				povecanoPolje[i] = A[i];
			}

			delete[] A;
			A = povecanoPolje;
		}
		while (isspace(input.peek())) input.get();
	}
	input.close();
	velikost = trenutnaVelikost;
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost){
    ofstream output("out.txt");

	for (int i = 0; i < velikost; i++)
		output << polje[i] << ' ';
}

int main(int argc, const char* argv[]){
    int* A = nullptr;
	int* B = nullptr;
	int velikost = 0;
	int najmanjseStevilo = INT_MAX;
	int najvecjeStevilo = INT_MIN;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2], velikost, najmanjseStevilo, najvecjeStevilo)) return 0;

	if (argv[1][0] == '0') {
		//counting
		countingSort(A, B, najmanjseStevilo, najvecjeStevilo, velikost);
	}
	else {
		//Roman sort
		romanSort(A, B, najmanjseStevilo, najvecjeStevilo, velikost);
	}
	Izpis_Stevil(B, velikost);

	delete[] A;
    return 0;
}