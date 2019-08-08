#include "Imovel.h"

static int identificador = 0;

Imovel::Imovel(){
    identificador++;
    id = identificador;
    endereco = Endereco();
    valor = tipoOferta = tipoImovel = 0;
}

Imovel::~Imovel(){}

double Imovel::getValor(){
    return valor;
}

int Imovel::getId(){
    return id;
}

int Imovel::getTipoOferta(){
    return tipoOferta;
}

int Imovel::getTipoImovel(){
    return tipoImovel;
}

Endereco Imovel::getEndereco(){
    return endereco;
}

std::string Imovel::getTituloAnuncio(){
    return tituloAnuncio;
}

void Imovel::setEndereco(std::string logradouro, std::string bairro, std::string cidade, std::string cep, int numero){
    endereco.setLogradouro(logradouro);
    endereco.setBairro(bairro);
    endereco.setCidade(cidade);
    endereco.setCep(cep);
    endereco.setNumero(numero);
}

void Imovel::setTipoOferta(int tipoOferta){
    if(tipoOferta == IMOVEL_PARA_ALUGAR || tipoOferta == IMOVEL_PARA_VENDER)
        this -> tipoOferta = tipoOferta;
}

void Imovel::setTipoImovel(int tipoImovel){
    this -> tipoImovel = tipoImovel;
}

void Imovel::setValor(double valor){
    this -> valor = valor;
}

void Imovel::setTituloAnuncio(std::string tituloAnuncio){
    this->tituloAnuncio = tituloAnuncio;
}
