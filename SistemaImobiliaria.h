#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H

#include <iostream>
#include <string>
#include <list>
#include "Imovel.h"
#include "GerenteDePersistencia.h"

class SistemaImobiliaria{

	public:
	    SistemaImobiliaria();
		void cadastraImovel(Imovel *tImovel);
		void removeImovel(int indice);
		void printaLista(std::list<Imovel *> lista);

        GerenteDePersistencia getControlador();

		std::list<Imovel *> buscaImovel(std::list<Imovel *> lista, std::string substring, int tipoSubstring);
		std::list<Imovel *> buscaImovelValor(std::list<Imovel *> lista, double valor, int tipoBusca);
		std::list<Imovel *> getImoveis();
		std::list<std::string> getDescricaoImoveis(std::list<Imovel *> lista);
		std::list<std::string> getDescricaoSalvarImoveis(std::list<Imovel *> lista);
		std::list<std::string> getResumoImoveis(std::list<Imovel *> lista);
		std::list<Imovel *> getImoveisPorTipo(std::list<Imovel *> lista, int tipo);
		std::list<Imovel *> getImoveisPorTipoAnuncio(std::list<Imovel *> lista, int tipo);

	private:
		std::list<Imovel *> listaDeImoveis;
		GerenteDePersistencia controlador;

};

#endif
