#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int totalKnapsack, knapsacksSize[10001];

		// Primeiramente lê o total de knapsacks dados aos viajantes
		while ((cin >> totalKnapsack) && totalKnapsack)
		{
			// Lê a tamanho de cada knapsack
			for (int i = 0; i < totalKnapsack; ++i) cin >> knapsacksSize[i];
			
			// Ordena o array de tamanhos
			sort(knapsacksSize, knapsacksSize + totalKnapsack);

			// Faz um loop por todos tamanhos e pega a maior quantidade de mochilas do mesmo tamanho
			int count_repeticao = 1, n_maior_repeticao = 0;
			knapsacksSize[totalKnapsack] = 0; // Garante que o último caso será verificado 
			for (int i = 0; i < totalKnapsack; i++) {
				if (knapsacksSize[i] == knapsacksSize[i + 1]) count_repeticao++;
				else {
					n_maior_repeticao = count_repeticao > n_maior_repeticao 
						? count_repeticao 
						: n_maior_repeticao;

					count_repeticao = 1;
				}
			}

			// Printa o maior valor de repetições 
			cout << n_maior_repeticao << "\n";

			// Primeiro loop que passa por todo array de tamanhos
			for (int i = 0; i < n_maior_repeticao; ++i) {
				
				// Segundo loop para passa
				for (int j = i; j < totalKnapsack; j += n_maior_repeticao) {
					if (i != j) cout << " ";
					cout << knapsacksSize[j];
				}
				
				cout << "\n";
			}
		}
}