#include "Terreno.h"

#define VALOR 1
#define TIPO_OFERTA 2
#define TITULO_ANUNCIO 3
#define RUA 4
#define NUMERO 5
#define BAIRRO 6
#define CIDADE 7
#define CEP 8
#define AREA 9

using namespace std;

Terreno::Terreno(): Imovel(){
    tipoImovel = TERRENO;
    area = 0;
}

string Terreno::getDescricao(){
    stringstream descricao;

    descricao << "Id: " << id << "\nTipo imovel: " << tipoImovel << "\nValor: " << valor << "\nTipo oferta: " << tipoOferta << "\nTitulo anuncio: "
              << tituloAnuncio << "\nLogradouro: " << endereco.getLogradouro() << "\nNumero: " << endereco.getNumero() << "\nBairro: " << endereco.getBairro()
              << "\nCidade" << endereco.getCidade() << "\nCEP: " << endereco.getCep() << "\nArea: " << area << endl;

    return descricao.str();
}

double Terreno::getArea(){
    return area;
}

void Terreno::setArea(double area){
    if(area <= 0)
        this->area = 0;
    else
        this->area = area;
}

void Terreno::EditaImovel(string novaString, double novoDouble, int modificacao){
    switch(modificacao){
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
        case AREA:
            setArea(novoDouble);
    }
}
