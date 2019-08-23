#include "SistemaImobiliaria.h"

using namespace std;

Terreno::Terreno(): Imovel(){
    tipoImovel = TERRENO;
    area = 0;
}

string Terreno::toString(){
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
           << "\nArea: " << area << endl;

    return resumo.str();
}

string Terreno::toStringSalvar(){
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
           << area << endl;

    return resumo.str();
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

        case AREA:
            setArea(novoDouble);
    }
}