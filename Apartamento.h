#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Imovel.h"

class Apartamento : public Imovel
{
    protected:
        std::string posicao;
        double valorCondominio;
        double area;
        int numQuartos;
        int vagasGaragem;

    public:
        Apartamento();
        std::string getDescricao();

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
};

#endif // APARTAMENTO_H
