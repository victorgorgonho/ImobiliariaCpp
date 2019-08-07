#include "Apartamento.h"

using namespace std;

Apartamento::Apartamento(): Imovel(){
    tipoImovel = APARTAMENTO;
    posicao = " ";
    valorCondominio = area = numQuartos = vagasGaragem = 0;
}

string Apartamento::getDescricao(){
    stringstream descricao;

    descricao << "Tipo imovel: " << tipoImovel << "\nValor: " << valor << "\nTipo oferta: " << tipoOferta << "\nLogradouro: "
              << endereco.getLogradouro() << "\nNumero: " << endereco.getNumero() << "\nBairro: " << endereco.getBairro() << "\nCidade: "
              << endereco.getCidade() << "\nCEP: " << endereco.getCep() << "\nPosicao: " << posicao << "\nNumQuartos: " << numQuartos
              << "\nValor condominio: " << valorCondominio << "\nVagas garagem: " << vagasGaragem << "\nArea: " << area << endl;

    return descricao.str();
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
        this->valorCondominio = -1;
    else
        this->valorCondominio = valorCondominio;
}

void Apartamento::setArea(double area){
    if(area <= 0)
        this->area = -1;
    else
        this->area = area;
}

void Apartamento::setNumQuartos(int numQuartos){
    if(numQuartos <= 0)
        this->numQuartos = -1;
    else
        this->numQuartos = numQuartos;
}

void Apartamento::setVagasGaragem(int vagasGaragem){
    if(vagasGaragem < 0)
        this->vagasGaragem = -1;
    else
        this->vagasGaragem = vagasGaragem;
}
