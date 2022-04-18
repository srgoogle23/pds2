#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

class Complexo
{
	private:
		double real;
		double imag;
	public:
		Complexo conjugado() {
			Complexo c1 = Complexo();
			return c1;
		}

		Complexo inverso()
		{
			Complexo resultado = Complexo();
			return resultado;
		}

		Complexo soma(Complexo y)
		{
			Complexo resultado = Complexo();
			resultado.real = this->real + y.real;
			resultado.imag = this->imag + y.imag;
			return resultado;
		}

		Complexo subtrair(Complexo y)
		{
			Complexo resultado = Complexo();
			resultado.real = this->real - y.real;
			resultado.imag = this->imag - y.imag;
			return resultado;
		}

		Complexo multiplicar(Complexo y)
		{
			Complexo resultado = Complexo();
			resultado.real = (this->real * y.real) - (this->imag * y.imag);
			resultado.imag = (this->real * y.imag) + (this->imag * y.real);
			return resultado;
		}

		Complexo dividir(Complexo y)
		{
			Complexo resultado = Complexo();
			resultado.real = ((this->real * y.real) + (this->imag * y.imag)) / ((y.real * y.real) + (y.imag * y.imag));
			resultado.imag = ((this->imag * y.real) - (this->real * y.imag)) / ((y.real * y.real) + (y.imag * y.imag));
			return resultado;
		}

		pair<Complexo, Complexo> calcula_raizes(double a, double b, double c)
		{
			Complexo x1 = Complexo();
			Complexo x2 = Complexo();
			double delta = this->delta(a, b, c);
			
			if(delta > 0)
			{
				x1.setReal((-b + sqrt(delta)) / (2 * a));
				x2.setReal((-b - sqrt(delta)) / (2 * a));
			}
			else if(delta == 0)
			{
				x1.setReal(-b / (2 * a));
				x2.setReal(-b / (2 * a));
			}
			else
			{
				x1.setReal(0);
				x2.setReal(0);
			}

			return pair<Complexo, Complexo> (x1, x2);
		}
		
		double delta (double a, double b, double c)
		{
			return (b * b) - (4 * a * c);
		}
		
		double getReal()
		{
			return this->real;
		}

		double getImag()
		{
			return this->imag;
		}

		void setReal(double real)
		{
			this->real = real;
		}

		void setImag(double imag)
		{
			this->imag = imag;
		}
};

pair<Complexo, Complexo> raizes(double a, double b, double c) {
    return Complexo().calcula_raizes(a, b, c);
}

int main () {
  cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;
  double a, b, c;
  cin >> a >> b >> c;
  auto r = raizes(a, b, c);
  cout << "(" << r.first.getReal() << ", " << r.first.getImag() << ") "
       << "(" << r.second.getReal() << ", " << r.second.getImag() << ")" << endl;
  return 0;
}