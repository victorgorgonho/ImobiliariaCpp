#include "Apartamento.h"

#include <sstream>

#define DESCRICAO 0
#define VALOR 1
#define TIPO_OFERTA 2
#define TITULO_ANUNCIO 3
#define RUA 4
#define NUMERO 5
#define BAIRRO 6
#define CIDADE 7
#define CEP 8
#define POSICAO 9
#define VALOR_CONDOMINIO 10
#define A_AREA 11
#define A_NUM_QUARTOS 12
#define VAGAS_GARAGEM 13

using namespace std;

Apartamento::Apartamento(): Imovel(){
    tipoImovel = APARTAMENTO;
    posicao = " ";
    valorCondominio = area = numQuartos = vagasGaragem = 0;
}

string Apartamento::toString(){
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
           << "\nPosicao: " << posicao 
           << "\nNumQuartos: " << numQuartos
           << "\nValor condominio: " << valorCondominio 
           << "\nVagas garagem: " << vagasGaragem 
           << "\nArea: " << area << endl;

    return resumo.str();
}

string Apartamento::toStringSalvar(){
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
           << posicao << endl 
           << numQuartos << endl
           << valorCondominio << endl 
           << vagasGaragem << endl 
           << area << endl;

    return resumo.str();
}

std::string Apartamento::getPosicao(){
    return posicao;
}

double Apartamento::getValorCondominio(){
    return valorCondominio;
}

double Apartamento::getArea(){
    return area;
}

int Apartamento::getNumQuartos(){
    return numQuartos;
}

int Apartamento::getVagasGaragem(){
        return vagasGaragem;
}

void Apartamento::setPosicao(std::string posicao){
    this->posicao = posicao;
}

void Apartamento::setValorCondominio(double valorCondominio){
    if(valorCondominio < 0)
        this->valorCondominio = 0;
    else
        this->valorCondominio = valorCondominio;
}

void Apartamento::setArea(double area){
    if(area <= 0)
        this->area = 0;
    else
        this->area = area;
}

void Apartamento::setNumQuartos(int numQuartos){
    if(numQuartos <= 0)
        this->numQuartos = 0;
    else
        this->numQuartos = numQuartos;
}

void Apartamento::setVagasGaragem(int vagasGaragem){
    if(vagasGaragem < 0)
        this->vagasGaragem = 0;
    else
        this->vagasGaragem = vagasGaragem;
}

void Apartamento::EditaImovel(string novaString, double novoDouble, int modificacao){
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

        case POSICAO:
            setPosicao(novaString);
            break;

        case VALOR_CONDOMINIO:
            setValorCondominio(novoDouble);
            break;

        case A_AREA:
            setArea(novoDouble);
            break;

        case A_NUM_QUARTOS:
            setNumQuartos(novoDouble);
            break;

        case VAGAS_GARAGEM:
            setVagasGaragem(novoDouble);
    }
}