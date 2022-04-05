#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Matriz {
	private:
		int linhas;
		int colunas;
		vector<vector<int>> matriz;
	public:
		Matriz(int linhas, int colunas){
			this->linhas = linhas;
			this->colunas = colunas;
			this->matriz.resize(linhas);
			for(int i = 0; i < linhas; i++){
				this->matriz[i].resize(colunas);
			}
		};

		void setValor(int linha, int coluna, int valor)
		{
			this->matriz[linha][coluna] = valor;
		};

		int getValor(int linha, int coluna)
		{
			return this->matriz[linha][coluna];
		};

		int getLinhas()
		{
			return this->linhas;
		};

		int getColunas()
		{
			return this->colunas;
		};

		void imprime()
		{
			for(int i = 0; i < this->linhas; i++){
				for(int j = 0; j < this->colunas; j++){
					cout << this->matriz[i][j] << " ";
				}
				cout << endl;
			}
		};

		void preenche()
		{
			for(int i = 0; i < this->getLinhas(); i++){
				for(int j = 0; j < this->getColunas(); j++){
					this->setValor(i, j, rand() % 10);
				}
			}
		}

		Matriz* soma(Matriz *matriz2)
		{
			Matriz* resultado = new Matriz(this->getLinhas(), this->getColunas());
			for(int i = 0; i < this->getLinhas(); i++){
				for(int j = 0; j < this->getColunas(); j++){
					resultado->setValor(i, j, this->getValor(i, j) + matriz2->getValor(i, j));
				}
			}
			return resultado;
		};

		Matriz* subtracao(Matriz* matriz2)
		{
			Matriz* resultado = new Matriz(this->getLinhas(), this->getColunas());
			for (int i = 0; i < this->getLinhas(); i++) {
				for (int j = 0; j < this->getColunas(); j++) {
					resultado->setValor(i, j, this->getValor(i, j) - matriz2->getValor(i, j));
				}
			}
			return resultado;
		};

		Matriz* multiplicacao(Matriz* matriz2)
		{
			Matriz* resultado = new Matriz(this->getLinhas(), matriz2->getColunas());
			for (int i = 0; i < this->getLinhas(); i++) {
				for (int j = 0; j < matriz2->getColunas(); j++) {
					int soma = 0;
					for (int k = 0; k < this->getColunas(); k++) {
						soma += this->getValor(i, k) * matriz2->getValor(k, j);
					}
					resultado->setValor(i, j, soma);
				}
			}
			return resultado;
		};

		Matriz* transposta()
		{
			Matriz* resultado = new Matriz(this->getColunas(), this->getLinhas());
			for (int i = 0; i < this->getLinhas(); i++) {
				for (int j = 0; j < this->getColunas(); j++) {
					resultado->setValor(j, i, this->getValor(i, j));
				}
			}
			return resultado;
		};

		Matriz* divisao(Matriz* matriz2)
		{
			Matriz* resultado = new Matriz(this->getLinhas(), this->getColunas());
			for (int i = 0; i < this->getLinhas(); i++) {
				for (int j = 0; j < this->getColunas(); j++) {
					if(matriz2->getValor(i, j) == 0){
						resultado->setValor(i, j, 0);
					}else{
						resultado->setValor(i, j, (this->getValor(i, j) / matriz2->getValor(i, j)));
					}
				}
			}
			return resultado;
		};

		Matriz* potencia(int potencia)
		{
			Matriz* resultado = new Matriz(this->getLinhas(), this->getColunas());
			for (int i = 0; i < this->getLinhas(); i++) {
				for (int j = 0; j < this->getColunas(); j++) {
					resultado->setValor(i, j, pow(this->getValor(i, j), potencia));
				}
			}
			return resultado;
		};
};

int main()
{
	srand(time(NULL));

	Matriz matriz_1(3, 3), matriz_2(3, 3);
	matriz_1.preenche();
	matriz_2.preenche();

	cout << endl << "Matriz 1: " << endl;
	matriz_1.imprime();
	cout << endl << "Matriz 2: " << endl;
	matriz_2.imprime();

	cout << endl << "Soma: Matriz 1 + Matriz 2" << endl;
	matriz_1.soma(&matriz_2)->imprime();

	cout << endl << "Subtração: Matriz 1 - Matriz 2" << endl;
	matriz_1.subtracao(&matriz_2)->imprime();

	cout << endl << "Multiplicação: Matriz 1 * Matriz 2" << endl;
	matriz_1.multiplicacao(&matriz_2)->imprime();

	cout << endl << "Transposta: Matriz 1" << endl;
	matriz_1.transposta()->imprime();

	cout << endl << "Divisão: Matriz 1 / Matriz 2" << endl;
	matriz_1.divisao(&matriz_2)->imprime();

	cout << endl << "Potencia: Matriz 1 ^ 2" << endl;
	matriz_1.potencia(2)->imprime();
}