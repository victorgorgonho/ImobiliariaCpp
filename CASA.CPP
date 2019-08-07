#include "Casa.h"

using namespace std;

Casa::Casa(): Imovel(){
    tipoImovel = CASA;
    numPavimento = numQuartos = areaConstruida = areaTerreno = 0;
}

string Casa::getDescricao(){
    stringstream descricao;

    descricao << "Tipo imovel: " << tipoImovel << "\nValor: " << valor << "\nTipo oferta: " << tipoOferta << "\nLogradouro: "
              << endereco.getLogradouro() << "\nNumero: " << endereco.getNumero() << "\nBairro: " << endereco.getBairro() << "\nCidade"
              << endereco.getCidade() << "\nCEP: " << endereco.getCep() << "\nNumPavimento: " << numPavimento << "\nNumQuartos: "
              << numQuartos << "\nArea: " << areaTerreno << "\nArea construida: " << areaConstruida << endl;

    return descricao.str();
}

int Casa::getNumPavimento(){
    return numPavimento;
}

int Casa::getNumQuartos(){
    return numQuartos;
}

double Casa::getAreaTerreno(){
    return areaConstruida;
}

double Casa::getAreaConstruida(){
    return areaConstruida;
}

void Casa::setNumPavimento(int numPavimento){
    if(numPavimento <= 0)
        this->numPavimento = -1;
    else
        this->numPavimento = numPavimento;
}

void Casa::setNumQuartos(int numQuartos){
    if(numQuartos <= 0)
        this->numQuartos = -1;
    else
        this->numQuartos = numQuartos;
}

void Casa::setAreaTerreno(double areaTerreno){
    if(areaTerreno <= 0)
        this->areaTerreno = -1;
    else
        this->areaTerreno = areaTerreno;
}

void Casa::setAreaConstruida(double areaConstruida){
    if(areaConstruida <= 0)
        this->areaConstruida = -1;
    else
        this->areaConstruida = areaConstruida;
}
