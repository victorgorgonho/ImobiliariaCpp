#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H

#include <iostream>
#include <string>
#include <list>
#include "Imovel.h"

class SistemaImobiliaria{

	private:
		std::list<Imovel *> listaDeImoveis;

	public:
	    SistemaImobiliaria();
		void cadastraImovel(Imovel *tImovel);
		void removeImovel(int indice);

		std::list<Imovel *> buscaImovel(std::string substring, int tipoSubstring);
		std::list<Imovel *> buscaImovelValor(double valor, int tipoBusca);
		std::list<Imovel *> getImoveis();
		std::list<std::string> getDescricaoImoveis();
		std::list<std::string> getResumoImoveis();
		std::list<Imovel *> getImoveisPorTipo(int tipo);
		std::list<Imovel *> getImoveisParaAlugarPorBairro(std::string bairro);
		std::list<Imovel *> getImoveisParaVenderPorBairro(std::string bairro);
		std::list<Imovel *> getImoveisPorCidade(std::string cidade);
		std::list<Imovel *> getImoveisPorTipoAnuncio(int tipo);
};

#endif
