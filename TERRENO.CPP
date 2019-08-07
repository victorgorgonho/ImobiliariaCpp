#include "Terreno.h"

using namespace std;

Terreno::Terreno(): Imovel(){
    tipoImovel = TERRENO;
    area = 0;
}

string Terreno::getDescricao(){
    stringstream descricao;

    descricao << "Tipo imovel: " << tipoImovel << "\nValor: " << valor << "\nTipo oferta: " << tipoOferta << "\nLogradouro: "
              << endereco.getLogradouro() << "\nNumero: " << endereco.getNumero() << "\nBairro: " << endereco.getBairro() << "\nCidade"
              << endereco.getCidade() << "\nCEP: " << endereco.getCep() << "\nArea: " << area << endl;

    return descricao.str();
}

double Terreno::getArea(){
    return area;
}

void Terreno::setArea(double area){
    if(area <= 0)
        this->area = -1;
    else
        this->area = area;
}
