#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Aluno {
	private:
		string nome;
		int matricula;
		vector<int> materias;
	public:
		Aluno(string nome, int matricula) {
			this->nome = nome;
			this->matricula = matricula;
		}
		void realizar_matricula(int  cod_disciplina) {
			materias.push_back(cod_disciplina);
		}
		void print() {
			cout << "Nome: " << nome << endl;
			cout << "Matricula: " << matricula << endl;
			cout << "Materias: ";
			for (int i = 0; i < materias.size(); i++) {
				cout << materias[i] << ", ";
			}
			cout << endl << endl;
		}
};

int main() {
	Aluno aluno1("Joao", 1);
	Aluno aluno2("Maria", 2);
	Aluno aluno3("Pedro", 3);
	aluno1.realizar_matricula(1);
	aluno1.realizar_matricula(2);
	aluno1.realizar_matricula(3);
	aluno2.realizar_matricula(1);
	aluno2.realizar_matricula(2);
	aluno2.realizar_matricula(3);
	aluno3.realizar_matricula(1);
	aluno3.realizar_matricula(2);
	aluno3.realizar_matricula(3);
	aluno1.print();
	aluno2.print();
	aluno3.print();
	return 0;
}