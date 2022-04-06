#include "../namespaces/tads.h"

using namespace tads;

int main()
{
	srand(time(NULL));

	tads::Matriz matriz_1(3, 3), matriz_2(3, 3);
	matriz_1.preenche();
	matriz_2.preenche();

	matriz_1.multiplicacao(&matriz_2)->imprime();

}