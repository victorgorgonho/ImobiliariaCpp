#include "Imovel.h"

Imovel::Imovel(){
    endereco = Endereco();
    valor = tipoOferta = tipoImovel = 0;
}

Imovel::~Imovel(){}

double Imovel::getValor(){
    return valor;
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

void Imovel::setEndereco(std::string logradouro, std::string bairro, std::string cidade, std::string cep, int numero){
    endereco.setLogradouro(logradouro);
    endereco.setBairro(bairro);
    endereco.setCidade(cidade);
    endereco.setCep(cep);
    endereco.setNumero(numero);
}

void Imovel::setTipoOferta(int tipoOferta){
    this -> tipoOferta = tipoOferta;
}

void Imovel::setTipoImovel(int tipoImovel){
    this -> tipoImovel = tipoImovel;
}

void Imovel::setValor(double valor){
    this -> valor = valor;
}
