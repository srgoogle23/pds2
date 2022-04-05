#include <string>
#include <iostream>

using namespace std;

/**
 * cria uma classe de manipulação de frações,
 * onde executará operações de adição, subtração, multiplicação e divisão.
 */
class Fracao
{
	private:
		int _numerador;
		int _denominador;
	public:
		Fracao(int numerador, int denominador)
		{
			_numerador = numerador;
			_denominador = denominador;
		};

		Fracao(int numerador)
		{
			_numerador = numerador;
			_denominador = 1;
		};

		Fracao()
		{
			_numerador = 0;
			_denominador = 1;
		};

		int getNumerador()
		{
			return _numerador;
		};

		int getDenominador()
		{
			return _denominador;
		};

		void setNumerador(int numerador)
		{
			_numerador = numerador;
		};

		void setDenominador(int denominador)
		{
			_denominador = denominador;
		};

		Fracao soma(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getDenominador() + _denominador * fracao.getNumerador() );
			resultado.setDenominador( _denominador * fracao.getDenominador() );
			return resultado;
		};

		Fracao subtracao(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getDenominador() - _denominador * fracao.getNumerador() );
			resultado.setDenominador( _denominador * fracao.getDenominador() );
			return resultado;
		};

		Fracao multiplicacao(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getNumerador() );
			resultado.setDenominador( _denominador * fracao.getDenominador() );
			return resultado;
		};

		Fracao divisao(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getDenominador() );
			resultado.setDenominador( _denominador * fracao.getNumerador() );
			return resultado;
		};
};

int main()
{
	srand(time(NULL));

	// cria fracoes aleatorias e soma-as
	Fracao fracao1( rand() % 90 + 10, rand() % 90 + 10 );
	Fracao fracao2( rand() % 90 + 10, rand() % 90 + 10 );
	Fracao fracao3 = fracao1.soma( fracao2 );
	
	// soma as duas frações
	cout << fracao1.getNumerador() << "/" << fracao1.getDenominador() << " + " << fracao2.getNumerador() << "/" << fracao2.getDenominador() << " = " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << "Soma: " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << endl;

	// subtrai as duas frações
	fracao3 = fracao1.subtracao( fracao2 );
	cout << fracao1.getNumerador() << "/" << fracao1.getDenominador() << " - " << fracao2.getNumerador() << "/" << fracao2.getDenominador() << " = " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << "Subtração: " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << endl;

	// multiplica as duas frações
	fracao3 = fracao1.multiplicacao( fracao2 );
	cout << fracao1.getNumerador() << "/" << fracao1.getDenominador() << " * " << fracao2.getNumerador() << "/" << fracao2.getDenominador() << " = " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << "Multiplicação: " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << endl;

	// divide as duas frações
	fracao3 = fracao1.divisao( fracao2 );
	cout << fracao1.getNumerador() << "/" << fracao1.getDenominador() << " / " << fracao2.getNumerador() << "/" << fracao2.getDenominador() << " = " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << "Divisão: " << fracao3.getNumerador() << "/" << fracao3.getDenominador() << endl;
	cout << endl;
}