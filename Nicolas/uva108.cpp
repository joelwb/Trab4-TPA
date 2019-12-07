#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*Autor: Nicolas Pereira Sampaio
	O problema se baseia em calcularmos o retângulo que tem o maior valor dentro da matriz quadrática*/

int main(void) {
	int n, linha, coluna, c, d, e, maximo;
	int somasParciais[101][101], mat[100][100];

	while (cin >> n) {
		for (linha = 0; linha < n; linha++)
			for (coluna = 0; coluna < n; coluna++)
				cin >> mat[linha][coluna];

		for (linha = 0; linha < n + 1; linha++) {
			somasParciais[0][linha] = 0; somasParciais[linha][0] = 0; 
		}

		// Realizando somas parciais
		for (linha = 1; linha < n + 1; linha++)
			for (coluna = 1; coluna < n + 1; coluna++)
				somasParciais[linha][coluna] = somasParciais[linha - 1][coluna] + somasParciais[linha][coluna - 1] - somasParciais[linha - 1][coluna - 1] + mat[linha - 1][coluna - 1];


		
		maximo = -1;

		
		// Percorrendo toda matriz verificando os retângulos n^4
		for (linha = 1; linha < n + 1; linha++)
			for (coluna = 1; coluna < n + 1; coluna++)
				for (c = linha - 1; c >= 0; c--)
					for (d = coluna - 1; d >= 0; d--)
						if (somasParciais[linha][coluna] + somasParciais[c][d] - somasParciais[linha][d] - somasParciais[c][coluna] > maximo) maximo = somasParciais[linha][coluna] + somasParciais[c][d] - somasParciais[linha][d] - somasParciais[c][coluna];


		cout << maximo << endl;
	}

	return 0;
}
	
