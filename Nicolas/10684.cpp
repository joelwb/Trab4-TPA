#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	/*O problema se baseia em calcularmos se manuel saiu ganhando ou perdendo em uma streak de uma aposta em jackpot*/

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		int valor;
		int streakAtual = 0;
		int winningStreak = 0;
		while (n > 0) {
			cin >> valor;
			if (streakAtual > winningStreak) {
				winningStreak = streakAtual;
			}
			
			streakAtual = streakAtual + valor;
			if (streakAtual < 0) {
				streakAtual = 0;
			}
			
			n--;
		}

		if (winningStreak >0) {
			if (streakAtual > winningStreak) {
				winningStreak = streakAtual;
			}
			cout << "The maximum winning streak is ";
			cout << winningStreak;
			cout << '.' << endl;
		}
		else {
			cout << "Losing streak." << endl;
		}
	}
}