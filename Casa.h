#ifndef CASA_H
#define CASA_H

#include "Imovel.h"

class Casa : public Imovel
{
    public:
        Casa();
        //friend std::bool operator == (const Casa& i);

        int getNumPavimento();
        int getNumQuartos();
        double getAreaTerreno();
        double getAreaConstruida();

        void setNumPavimento(int numPavimento);
        void setNumQuartos(int numQuartos);
        void setAreaTerreno(double areaTerreno);
        void setAreaConstruida(double areaConstruida);

        void EditaImovel(std::string novaString, double novoDouble, int modificacao);
        std::string toString();
        std::string toStringSalvar();

    protected:
        int numPavimento;
        int numQuartos;
        double areaTerreno;
        double areaConstruida;
};

#endif // CASA_H
