#ifndef IMOVEL_H
#define IMOVEL_H
#define IMOVEL_PARA_VENDER 1
#define IMOVEL_PARA_ALUGAR 2
#define APARTAMENTO 1
#define TERRENO 2
#define CASA 3

#include "Endereco.h"
#include <sstream>
#include <iostream>
#include <string>

class Imovel
{
    protected:
        int tipoImovel;
        double valor;
        int tipoOferta;
        Endereco endereco;

    public:
        Imovel();
        virtual ~Imovel();

        double getValor();
        int getTipoOferta();
        int getTipoImovel();
        Endereco getEndereco();

        void setValor(double valor);
        void setTipoOferta(int tipoOferta);
        void setTipoImovel(int tipoImovel);
        void setEndereco(std::string logradouro, std::string bairro, std::string cidade, std::string cep, int numero);

        virtual std::string getDescricao() = 0;
};

#endif // IMOVEL_H
