#ifndef IMOVEL_H
#define IMOVEL_H
#define IMOVEL_PARA_VENDER 1
#define IMOVEL_PARA_ALUGAR 2

#define APARTAMENTO 1
#define TERRENO 2
#define CASA 3

#define Nulo -1

#include "Endereco.h"
#include <iostream>
#include <string>

class Imovel
{
    public:
        Imovel();
        virtual ~Imovel();

        double getValor();
        int getId();
        int getTipoOferta();
        int getTipoImovel();
        Endereco getEndereco();
        std::string getTituloAnuncio();
        std::string getDescricao();

        void setId(int id);
        void setValor(double valor);
        void setTipoOferta(int tipoOferta);
        void setTipoImovel(int tipoImovel);
        void setEndereco(std::string logradouro, std::string bairro, std::string cidade, std::string cep, int numero);
        void setTituloAnuncio(std::string tituloAnuncio);
        void setDescricao(std::string descricao);

        virtual void EditaImovel(std::string novaString, double novoDouble, int modificacao) = 0;
        virtual std::string toString() = 0;
        virtual std::string toStringSalvar() = 0;

    protected:
        int id;
        int tipoImovel;
        double valor;
        int tipoOferta;
        Endereco endereco;
        std::string tituloAnuncio;
        std::string descricao;
};

#endif // IMOVEL_H
