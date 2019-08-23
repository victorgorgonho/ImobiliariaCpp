#include "SistemaImobiliaria.h"

using namespace std;

Endereco::Endereco()
{
    logradouro = bairro = cidade = cep = " ";
    numero = 0;
}

string Endereco::toString(){

	stringstream resumo;

	resumo << "Logradouro: " << logradouro << ", no. " << numero
		<< ", " << bairro << ", " << cidade
		<< ", " << cep;

	return resumo.str();
}

string Endereco::getLogradouro(){
    return logradouro;
}

string Endereco::getBairro(){
    return bairro;
}

string Endereco::getCidade(){
    return cidade;
}

string Endereco::getCep(){
    return cep;
}

int Endereco::getNumero(){
    return numero;
}

void Endereco::setLogradouro(string logradouro){
    this -> logradouro = logradouro;
}

void Endereco::setBairro(string bairro){
    this -> bairro = bairro;
}

void Endereco::setCidade(string cidade){
    this -> cidade = cidade;
}

void Endereco::setCep(string cep){
    this -> cep = cep;
}

void Endereco::setNumero(int numero){
    if(numero <= 0)
        this->numero = -1;
    else
        this->numero = numero;
}
