#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.h"

class Apartamento : public Imovel
{
    public:
        Apartamento();

        std::string getPosicao();
        double getValorCondominio();
        double getArea();
        int getNumQuartos();
        int getVagasGaragem();

        void setPosicao(std::string posicao);
        void setValorCondominio(double valorCondominio);
        void setArea(double area);
        void setNumQuartos(int numQuartos);
        void setVagasGaragem(int vagasGaragem);

        void EditaImovel(std::string novaString, double novoDouble, int modificacao);
        std::string toString();
        std::string toStringSalvar();

    protected:
        std::string posicao;
        double valorCondominio;
        double area;
        int numQuartos;
        int vagasGaragem;
};

#endif // APARTAMENTO_H
