#include "SistemaImobiliaria.h"

using namespace std;

Casa::Casa(): Imovel(){
    tipoImovel = CASA;
    numPavimento = numQuartos = areaConstruida = areaTerreno = 0;
}

string Casa::toString(){
    stringstream resumo;

    resumo << "Id: " << id 
           << "\nTipo imovel: " << tipoImovel  
           << "\nValor: " << valor 
           << "\nTipo oferta: " << tipoOferta 
           << "\nTitulo anuncio: " << tituloAnuncio 
           << "\nDescricao: " << descricao 
           << "\nLogradouro: " << endereco.getLogradouro() 
           << "\nNumero: " << endereco.getNumero() 
           << "\nBairro: " << endereco.getBairro()
           << "\nCidade: " << endereco.getCidade() 
           << "\nCEP: " << endereco.getCep() 
           << "\nNumPavimento: " << numPavimento 
           << "\nNumQuartos: " << numQuartos 
           << "\nArea: " << areaTerreno 
           << "\nArea construida: " << areaConstruida << endl;

    return resumo.str();
}

string Casa::toStringSalvar(){
    stringstream resumo;

    resumo << id << endl 
           << tipoImovel << endl 
           << valor << endl 
           << tipoOferta << endl 
           << tituloAnuncio << endl 
           << descricao << endl 
           << endereco.getLogradouro() << endl 
           << endereco.getNumero() << endl 
           << endereco.getBairro() << endl 
           << endereco.getCidade() << endl 
           << endereco.getCep() << endl 
           << numPavimento << endl
           << numQuartos << endl 
           << areaTerreno << endl 
           << areaConstruida << endl;

    return resumo.str();
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
        this->numPavimento = 0;
    else
        this->numPavimento = numPavimento;
}

void Casa::setNumQuartos(int numQuartos){
    if(numQuartos <= 0)
        this->numQuartos = 0;
    else
        this->numQuartos = numQuartos;
}

void Casa::setAreaTerreno(double areaTerreno){
    if(areaTerreno <= 0)
        this->areaTerreno = 0;
    else
        this->areaTerreno = areaTerreno;
}

void Casa::setAreaConstruida(double areaConstruida){
    if(areaConstruida <= 0)
        this->areaConstruida = 0;
    else
        this->areaConstruida = areaConstruida;
}

void Casa::EditaImovel(string novaString, double novoDouble, int modificacao){
    switch(modificacao){
        case DESCRICAO:
            setDescricao(descricao);
            break;

        case VALOR:
            setValor(novoDouble);
            break;

        case TIPO_OFERTA:
            if(tipoOferta == IMOVEL_PARA_ALUGAR || tipoOferta == IMOVEL_PARA_VENDER)
                setTipoOferta(novoDouble);
            break;

        case TITULO_ANUNCIO:
            setTituloAnuncio(novaString);
            break;

        case RUA:
            getEndereco().setLogradouro(novaString);
            break;

        case NUMERO:
            getEndereco().setNumero(novoDouble);
            break;

        case BAIRRO:
            getEndereco().setBairro(novaString);
            break;

        case CIDADE:
            getEndereco().setCidade(novaString);
            break;

        case CEP:
            getEndereco().setCep(novaString);
            break;

        case NUM_PAVIMENTO:
            setNumPavimento(novoDouble);
            break;

        case NUM_QUARTOS:
            setNumQuartos(novoDouble);
            break;

        case AREA_TERRENO:
            setAreaTerreno(novoDouble);
            break;

        case AREA_CONSTRUIDA:
            setAreaConstruida(novoDouble);
    }
}