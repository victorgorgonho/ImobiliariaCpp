#include <iostream>
#include <string>

#include "IMOVEL.H"
#include "SistemaImobiliaria.h"
#include "Apartamento.h"
#include "TERRENO.H"
#include "CASA.H"

using namespace std;

int main()
{
    SistemaImobiliaria sistema;

    Imovel *i1 = new Apartamento();
    Imovel *i2 = new Terreno();
    Imovel *i3 = new Casa();

    cout << i1->getDescricao() << endl;
    cout << i2->getDescricao() << endl;
    cout << i3->getDescricao() << endl;

    sistema.cadastraImovel(i1);
    sistema.cadastraImovel(i2);
    sistema.cadastraImovel(i3);

    return 0;
}
