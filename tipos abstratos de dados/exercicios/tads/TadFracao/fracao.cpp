#include <string>
#include <iostream>

using namespace std;

/**
 * cria uma classe de manipulação de frações,
 * onde executará operações de adição, subtração, multiplicação e divisão.
 * 
 * obs.: criei 3 construtores:
 * 1 - sem parâmetros (inicializa com 0/1)
 * 2 - com um parâmetro (inicializa com o valor passado, um inteiro/1)
 * 3 - com dois parâmetros (inicializa com o valor passado, um numerador/deominador)
 */
class Fracao
{
	private:
		int _numerador;
		int _denominador;
	public:
		/**
		 * @brief Construct a new Fracao object
		 * 
		 * @param numerador 
		 * @param denominador 
		 */
		Fracao(int numerador, int denominador)
		{
			_numerador = numerador;
			_denominador = denominador;
		};

		/**
		 * @brief Construct a new Fracao object
		 * 
		 * @param numerador 
		 */
		Fracao(int numerador)
		{
			_numerador = numerador;
			_denominador = 1;
		};

		/**
		 * @brief Construct a new Fracao object
		 * 
		 */
		Fracao()
		{
			_numerador = 0;
			_denominador = 1;
		};

		/**
		 * @brief Get the Numerador object
		 * 
		 * @return int 
		 */
		int getNumerador()
		{
			return _numerador;
		};

		/**
		 * @brief Get the Denominador object
		 * 
		 * @return int 
		 */
		int getDenominador()
		{
			return _denominador;
		};

		/**
		 * @brief Set the Numerador object
		 * 
		 * @param numerador 
		 */
		void setNumerador(int numerador)
		{
			_numerador = numerador;
		};

		/**
		 * @brief Set the Denominador object
		 * 
		 * @param denominador 
		 */
		void setDenominador(int denominador)
		{
			_denominador = denominador;
		};

		/**
		 * @brief Adiciona duas frações
		 * 
		 * @param Fracao fracao 
		 * @return Fracao 
		 */
		Fracao soma(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getDenominador() + _denominador * fracao.getNumerador() );
			resultado.setDenominador( _denominador * fracao.getDenominador() );
			return resultado;
		};

		/**
		 * @brief Subtrai duas frações
		 * 
		 * @param Fracao fracao 
		 * @return Fracao 
		 */
		Fracao subtracao(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getDenominador() - _denominador * fracao.getNumerador() );
			resultado.setDenominador( _denominador * fracao.getDenominador() );
			return resultado;
		};

		/**
		 * @brief Multiplica duas frações
		 * 
		 * @param Fracao fracao 
		 * @return Fracao 
		 */
		Fracao multiplicacao(Fracao fracao)
		{
			Fracao resultado;
			resultado.setNumerador( _numerador * fracao.getNumerador() );
			resultado.setDenominador( _denominador * fracao.getDenominador() );
			return resultado;
		};

		/**
		 * @brief Divide duas frações
		 * 
		 * @param Fracao fracao 
		 * @return Fracao 
		 */
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