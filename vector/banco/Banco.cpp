#include <string>
#include <iostream>
#include <vector>

using namespace std;

// cria uma classe de agencia que se relaciona com a classe banco
class Agencia {
	private:
		string numero;
		string nome;
		string endereco;
	public:
		Agencia(string numero, string nome, string endereco) {
			this->numero = numero;
			this->nome = nome;
			this->endereco = endereco;
		}
		string getNumero() {
			return numero;
		}
		string getNome() {
			return nome;
		}
		string getEndereco() {
			return endereco;
		}
		void print() {
			cout << "Numero: " << numero << endl;
			cout << "Nome: " << nome << endl;
			cout << "Endereco: " << endereco << endl;
		}
};

class Banco {
	private:
		string nome;
		vector<Agencia> agencias;
	public:
		Banco(string nome) {
			this->nome = nome;
		}
		void addAgencia(Agencia agencia) {
			agencias.push_back(agencia);
		}
		void print() {
			cout << "Banco: " << nome << endl << endl;
			for (int i = 0; i < agencias.size(); i++) {
				agencias[i].print();
				cout << endl;
			}
		}
};

int main()
{
	Agencia agencia1("123", "Agencia 1", "Rua 1");
	Agencia agencia2("456", "Agencia 2", "Rua 2");
	Agencia agencia3("789", "Agencia 3", "Rua 3");

	Banco banco("Banco 1");
	banco.addAgencia(agencia1);
	banco.addAgencia(agencia2);
	banco.addAgencia(agencia3);
	banco.print();

	return 0;
}