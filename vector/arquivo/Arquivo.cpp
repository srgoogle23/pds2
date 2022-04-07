#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class Arquivo
{
	private:
		std::string _filename;
		std::vector<std::string> _words;
	public:

		/**
		 * @brief Construtor padrão do objeto Arquivo
		 *
		 * @param filename 
		 */
		Arquivo(std::string filename)
		{
			_filename = filename;
			this->read();
		}

		/**
		 * @brief Método que lê o arquivo e armazena as palavras em um vetor
		 *
		 * @return void
		 */
		void read()
		{
			std::ifstream file(_filename);
			std::string word;
			while(file >> word)
			{
				_words.push_back(word);
			}
		}

		/**
		 * @brief Método que imprime todas palavras do vetor
		 * 
		 * @return void
		 */
		void print()
		{
			for(auto word : _words)
			{
				std::cout << word << std::endl;
			}
		}

		/**
		 * @brief Método que remove todas as palavras duplicadas do vetor
		 * 
		 * @return void
		 */
		void removeDuplicates()
		{
			std::sort( _words.begin(), _words.end() ); // ordena o vetor, do inicio ao fim, em ordem crescente
			_words.erase( unique( _words.begin(), _words.end() ), _words.end() ); // remove os elementos repetidos em sequencia, do inicio ao fim do array
		}
};

int main()
{
	Arquivo arquivo("arquivo.txt");
	std::cout << "Arquivo geral: " << std::endl;
	arquivo.print();
	arquivo.removeDuplicates();
	std::cout << std::endl << "Arquivo sem duplicatas: " << std::endl;
	arquivo.print();
	return 0;
}