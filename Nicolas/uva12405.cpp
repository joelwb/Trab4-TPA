#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	/*Autor: Nicolas Pereira Sampaio
	O problema avalia a quantidade de espantalhos que deve ser colocado na colheita para garantir que irá espantar todas as ameaças*/

	int qntCase;
	cin >> qntCase;
	for (int turno = 0; turno < qntCase; ++turno) {
		int qntCaracteres;
		cin >> qntCaracteres;
		string campo;
		cin >> campo;
		int qntEspantalhos = 0;
		for (int posCampo = 0; posCampo < campo.size(); posCampo++) {
			if (campo[posCampo] == '.') {
				qntEspantalhos++;
				if (posCampo + 2 > campo.size()) {
					break;
				}
				posCampo = posCampo + 2;
			}
		}
		int nCase = turno + 1;
		cout << "Case ";
		cout << nCase;
		cout << ": ";
		cout << qntEspantalhos << endl;
	}
}