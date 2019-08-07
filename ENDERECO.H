#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>

class Endereco
{
    private:
        std::string logradouro;
        std::string bairro;
        std::string cidade;
        std::string cep;
        int numero;

    public:
        Endereco();
        std::string toString();

        std::string getLogradouro();
        std::string getBairro();
        std::string getCidade();
        std::string getCep();
        int getNumero();

        void setLogradouro(std::string logradouro);
        void setBairro(std::string bairro);
        void setCidade(std::string cidade);
        void setCep(std::string cep);
        void setNumero(int numero);

};

#endif // ENDERECO_H
