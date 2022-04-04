#include <string>
#include <iostream>

using namespace std;

class Conta
{
	private:
		int _saldo;
		string _nome;
	public:
		Conta(string nome, int saldo)
		{
			_nome = nome;
			_saldo = saldo;
		};

		bool sacar(int valor)
		{
			if(_saldo >= valor)
			{
				_saldo -= valor;
				return true;
			}
			else
			{
				return false;
			}
		};

		bool depositar(int valor){
			_saldo += valor;
			return true;
		};

		bool transferir(int valor, Conta &conta)
		{
			sacar(valor);
			conta.depositar(valor);
			return true;
		};

		int getSaldo()
		{
			return _saldo;
		};

		string getNome()
		{
			return _nome;
		};
};

int main(){
	srand(time(NULL));

	// cria contas
	Conta conta1("Joao", 1000);
	Conta conta2("Maria", 2000);

	// realiza operações bancárias entre a conta de joão e maria
	conta1.transferir( rand() % 90 + 10, conta2);
	conta2.sacar( rand() % 90 + 10);
	conta2.transferir( rand() % 90 + 10, conta1);

	cout << "Saldo da conta de Joao: " << conta1.getSaldo() << endl;
	cout << "Saldo da conta de Maria: " << conta2.getSaldo() << endl;

	return 0;
}