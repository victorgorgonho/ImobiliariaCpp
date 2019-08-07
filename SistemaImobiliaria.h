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
		std::list<Imovel *> getImoveis();
		std::list<std::string> getDescricaoImoveis();
		std::list<Imovel *> getImoveisPorTipo(int tipo);
		std::list<Imovel *> getImoveisParaAlugarPorBairro(std::string bairro);
		std::list<Imovel *> getImoveisParaVenderPorBairro(std::string bairro);
		std::list<Imovel *> getImoveisPorCidade(std::string cidade);
};

#endif
