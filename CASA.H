#ifndef CASA_H
#define CASA_H
#include "Imovel.h"

class Casa : public Imovel
{
    protected:
        int numPavimento;
        int numQuartos;
        double areaTerreno;
        double areaConstruida;

    public:
        Casa();
        std::string getDescricao();

        int getNumPavimento();
        int getNumQuartos();
        double getAreaTerreno();
        double getAreaConstruida();

        void setNumPavimento(int numPavimento);
        void setNumQuartos(int numQuartos);
        void setAreaTerreno(double areaTerreno);
        void setAreaConstruida(double areaConstruida);
};

#endif // CASA_H
