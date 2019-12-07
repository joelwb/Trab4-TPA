#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_knapsack = 10000;

int main()
{
	int totalKnapsack, knapsacksSize[max_knapsack];

	// Primeiramente lê o total de knapsacks dados aos viajantes
	cin >> totalKnapsack;
	while (totalKnapsack)
	{
		// Lê a tamanho de cada knapsack
		for (int i = 0; i < totalKnapsack; ++i) cin >> knapsacksSize[i];
			
		// Ordena o array de tamanhos
		sort(knapsacksSize, knapsacksSize + totalKnapsack);

		// Faz um loop por todos tamanhos e pega a maior quantidade de mochilas do mesmo tamanho
		int count_repeticao = 1, n_maior_repeticao = 0;
		knapsacksSize[totalKnapsack] = 0; // Garante que o último caso será verificado 
		for (int i = 0; i < totalKnapsack; i++) {

			// Verifica se elemento i se repete em i + 1
			if (knapsacksSize[i] == knapsacksSize[i + 1]) count_repeticao++;
			else {
				// Mantém guardado o maior valor de repetições
				n_maior_repeticao = count_repeticao > n_maior_repeticao 
					? count_repeticao 
					: n_maior_repeticao;

				// reseta o contador
				count_repeticao = 1;
			}
		}

		// Printa o maior valor de repetições 
		cout << n_maior_repeticao << "\n";
		
		// Primeiro loop para percorrer cada elemento que se repete
		int i = 0;
		while (i < n_maior_repeticao) {
			// Segundo loop para definir quais knapsack ficaram guardados em determiado elemento
			for (int j = i; j < totalKnapsack; j += n_maior_repeticao) {
				if (i != j) cout << " ";
				cout << knapsacksSize[j];
			}
			cout << '\n';

			i++;
		}

		// Verificac se é o fim
		cin >> totalKnapsack;
		if (totalKnapsack) {
			cout << '\n';
		}
	}
}