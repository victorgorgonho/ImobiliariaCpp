#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H

//Comum a todos
#define DESCRICAO 0
#define VALOR 1
#define TIPO_OFERTA 2
#define TITULO_ANUNCIO 3
#define RUA 4
#define NUMERO 5
#define BAIRRO 6
#define CIDADE 7
#define CEP 8

//Apenas apartamento
#define POSICAO 9
#define VALOR_CONDOMINIO 10
#define A_AREA 11
#define A_NUM_QUARTOS 12
#define VAGAS_GARAGEM 13

//Apenas casa
#define NUM_PAVIMENTO 9
#define NUM_QUARTOS 10
#define AREA_TERRENO 11
#define AREA_CONSTRUIDA 12

//Apenas terreno
#define AREA 9

//Sistema Imobiliaria
#define SI_BAIRRO 1
#define SI_CIDADE 2
#define TITULOANUNCIO 3
#define SI_PRECO 4

#define MAIOR_QUE 1
#define MENOR_QUE 2

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <bits/stdc++.h>

#include "GerenteDePersistencia.h"
#include "Imovel.h"
#include "Apartamento.h"
#include "Terreno.h"
#include "Casa.h"

class SistemaImobiliaria{

	public:
	    SistemaImobiliaria();
		void cadastraImovel(Imovel *tImovel);
		void editaImovel(int id, std::string novaString, double novoValor, int tipoModificacao);
		void removeImovel(int indice);
		void printaLista(std::list<Imovel *> lista);
		void setListaDeImoveis(std::list<Imovel *> lista);

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
