#ifndef TERRENO_H
#define TERRENO_H
#include "Imovel.h"

class Terreno : public Imovel
{
    protected:
        double area;

    public:
        Terreno();
        std::string getDescricao();

        double getArea();
        void setArea(double area);

        void EditaImovel(std::string novaString, double novoDouble, int modificacao);
};

#endif // TERRENO_H
