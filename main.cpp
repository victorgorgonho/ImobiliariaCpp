#include <iostream>
#include "IMOVEL.H"
#include "SistemaImobiliaria.h"
#include "Apartamento.h"
#include "TERRENO.H"
#include "CASA.H"

using namespace std;

int main()
{
    Imovel *i1 = new Apartamento();
    Imovel *i2 = new Terreno();
    Imovel *i3 = new Casa();

    cout << i1->getDescricao() << endl;
    cout << i2->getDescricao() << endl;
    cout << i3->getDescricao() << endl;

    return 0;
}
