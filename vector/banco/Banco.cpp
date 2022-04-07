#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Agencia {
	private:
		string numero;
		string nome;
		string endereco;
	public:
		/**
		 * @brief Construtor padrão do objeto Agencia
		 * 
		 * @param numero 
		 * @param nome 
		 * @param endereco 
		 */
		Agencia(string numero, string nome, string endereco) {
			this->numero = numero;
			this->nome = nome;
			this->endereco = endereco;
		}

		/**
		 * @brief Get the Numero object
		 * 
		 * @return string 
		 */
		string getNumero() {
			return numero;
		}

		/**
		 * @brief Get the Nome object	
		 * 
		 * @return string 
		 */
		string getNome() {
			return nome;
		}

		/**
		 * @brief Get the Endereco object
		 * 
		 * @return string 
		 */
		string getEndereco() {
			return endereco;
		}

		/**
		 * @brief Método que imprime todas as informações da agência
		 * 
		 */
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
		/**
		 * @brief Construct a new Banco object
		 * 
		 * @param nome 
		 */
		Banco(string nome) {
			this->nome = nome;
		}

		/**
		 * @brief Adiciona uma nova agência ao banco
		 * 
		 * @param agencia 
		 */
		void addAgencia(Agencia agencia) {
			agencias.push_back(agencia);
		}

		/**
		 * @brief Imprime todas as agências do banco
		 * 
		 */
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