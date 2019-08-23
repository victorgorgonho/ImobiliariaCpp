#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H

#include "Imovel.h"

class GerenteDePersistencia{
    public:
        GerenteDePersistencia();

        std::list<Imovel *> RecuperaListaImoveis();
        void SalvaListaImoveis(std::list<Imovel *> listaImoveis);
};

#endif
