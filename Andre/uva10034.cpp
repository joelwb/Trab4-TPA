/***
	Author: André Martins

	Esse código tem o objetivo que calcular a menor distância entre as sardas nas costas do pai de Richie, para assim, economizar tinta.
	A solução deste algoritmo baseia-se no uso do algoritmo de Prim para calcular a árvore geradora mínima, que seria representada pelas pintas.
***/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>

using namespace std;

struct Pinta {
	double x, y;
	bool checado;
} pinta;

// calcula distancia entre duas pintas
double getDistancia(Pinta a, Pinta b) {
	double pt1 = ((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
	return sqrt(pt1);
}

double prim(vector<Pinta> pintas, int n) {
	vector<vector<double>> distancia(n);
	double resultado, menor_distancia;
	Pinta *proxima_pinta;
	int i, j, pos_proxima_pinta;

	// Cria uma matriz de distancia entre as pintas
	for (i = 0; i < n; i++)
	{
		distancia[i].resize(n);
		for (j = 0; j < n; j++)
		{
			resultado = getDistancia(pintas[i], pintas[j]);
			distancia[i][j] = resultado;
			distancia[i][j] = resultado;
		}
	}

	// Seleciona o primeiro elemento como pivot
	pintas[0].checado = true;
	vector<double> distancias_ponto_atual(n);
	distancias_ponto_atual = distancia[0];
	resultado = 0;

	for (i = 0; i < n; i++) {
		
		// Busca o elemento mais próximo
		menor_distancia = INT_MAX;
		proxima_pinta = NULL;
		for (j = 0; j < n; j++) {
			if (!pintas[j].checado && distancias_ponto_atual[j] < menor_distancia) {
				menor_distancia = distancias_ponto_atual[j];
				pos_proxima_pinta = j;
				proxima_pinta = &pintas[pos_proxima_pinta];
			}
		}

		// Caso não encontre nenhum elemento, já finalizou a árvore
		if (proxima_pinta == NULL) break;
		
		// Soma o valor da distância
		resultado += menor_distancia;
		proxima_pinta->checado = true;
		
		// Atualiza lista de distâncias do elemento atual
		for (j = 0; j < n; j++) {
			if (distancia[pos_proxima_pinta][j] < distancias_ponto_atual[j]) {
				distancias_ponto_atual[j] = distancia[pos_proxima_pinta][j];
			}
		}
	}

	return resultado;
}

int main()
{
	int n_casos, n_sardas, i;
	double resultado;
	vector<Pinta> pintas;

	cin >> n_casos;
	//cout << '\n';
	
	while (n_casos--)
	{
		cin >> n_sardas;

		for (i = 0; i < n_sardas; i++) {
			Pinta p;
			cin >> p.x >> p.y;
			p.checado = false;
			pintas.push_back(p);
		}

		resultado = prim(pintas, n_sardas);
		printf("%.2lf\n", resultado);

		if (n_casos) {
			pintas.clear();
			cout << '\n';
		}
	}

	return 0;
}