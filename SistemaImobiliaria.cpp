#include <iostream>
#include<bits/stdc++.h>

#include "SistemaImobiliaria.h"
#include "IMOVEL.H"
#include "Apartamento.h"
#include "TERRENO.H"
#include "CASA.H"

#define SI_BAIRRO 1
#define SI_CIDADE 2
#define TITULOANUNCIO 3

#define MAIOR_QUE 1
#define MENOR_QUE 2

using namespace std;

SistemaImobiliaria::SistemaImobiliaria(){
}

void SistemaImobiliaria::cadastraImovel(Imovel *tImovel){
    listaDeImoveis.push_back(tImovel);
}

void SistemaImobiliaria::removeImovel(int indice){
    for(Imovel *n : listaDeImoveis){
        if(n->getId() == indice){
            listaDeImoveis.remove(n);
        }
    }
}

list<Imovel *> SistemaImobiliaria::buscaImovel(string substring, int tipoSubstring){
    list<Imovel *> resultado;
    string stringMinuscula;
    size_t posicaoSubstring;

    for(Imovel *n : listaDeImoveis){
        switch(tipoSubstring){
            case SI_BAIRRO:
                stringMinuscula = n->getEndereco().getBairro();
                transform(stringMinuscula.begin(), stringMinuscula.end(), stringMinuscula.begin(), ::tolower);
                transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

                posicaoSubstring = stringMinuscula.find(substring);

                if(posicaoSubstring >= 0 && stringMinuscula.size())
                    resultado.push_back(n);
                break;
            case SI_CIDADE:
                stringMinuscula = n->getEndereco().getCidade();
                transform(stringMinuscula.begin(), stringMinuscula.end(), stringMinuscula.begin(), ::tolower);
                transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

                posicaoSubstring = stringMinuscula.find(substring);

                if(posicaoSubstring >= 0 && stringMinuscula.size())
                    resultado.push_back(n);
                break;
            case TITULOANUNCIO:
                stringMinuscula = n->getTituloAnuncio();
                transform(stringMinuscula.begin(), stringMinuscula.end(), stringMinuscula.begin(), ::tolower);
                transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

                posicaoSubstring = stringMinuscula.find(substring);

                if(posicaoSubstring >= 0 && stringMinuscula.size())
                    resultado.push_back(n);
        }
    }
    return resultado;
}

list<Imovel *> SistemaImobiliaria::buscaImovelValor(double valor, int tipoBusca){
    list<Imovel *> resultado;

    for(Imovel *n : listaDeImoveis){
        if(tipoBusca == MAIOR_QUE ){
            if(valor >= n->getValor())
                resultado.push_back(n);
        }else if(tipoBusca == MENOR_QUE){
            if(valor <= n->getValor()){
                resultado.push_back(n);
            }
        }
    }
    return resultado;
}

list<Imovel *> SistemaImobiliaria::getImoveis(){
    return listaDeImoveis;
}

list<string> SistemaImobiliaria::getDescricaoImoveis(){
    list<string> descricaoImoveis;
    for(Imovel *n : listaDeImoveis){
        descricaoImoveis.push_back(n->getDescricao());
    }

    return descricaoImoveis;
}

std::list<std::string> SistemaImobiliaria::getResumoImoveis(){
    list<string> resumoImoveis;

    stringstream resumo;

    for(Imovel *n : listaDeImoveis){
        resumo << "Titulo: " << n->getTituloAnuncio() << "\nBairro: " << n->getEndereco().getBairro() << "\nCidade: " << n->getEndereco().getCidade()
               << "\nValor: " << n->getValor() << endl;

        resumoImoveis.push_back(resumo.str());
    }

    return resumoImoveis;
}

list<Imovel *> SistemaImobiliaria::getImoveisPorTipo(int tipo){
    list<Imovel *> imoveisPorTipo;

    for(Imovel *n : listaDeImoveis){
        if(n->getTipoImovel() == tipo)
            imoveisPorTipo.push_back(n);
    }

    return imoveisPorTipo;
}

list<Imovel *> SistemaImobiliaria::getImoveisParaAlugarPorBairro(string bairro){
    list<Imovel *> imoveisParaAlugarPorBairro;

    for(Imovel *n : listaDeImoveis){
        if(n->getTipoOferta() == IMOVEL_PARA_ALUGAR){
            if(n->getEndereco().getBairro() == bairro){
                imoveisParaAlugarPorBairro.push_back(n);
            }
        }
    }

    return imoveisParaAlugarPorBairro;
}

list<Imovel *> SistemaImobiliaria::getImoveisParaVenderPorBairro(string bairro){
    list<Imovel *> imoveisParaVenderPorBairro;

    for(Imovel *n : listaDeImoveis){
        if(n->getTipoOferta() == IMOVEL_PARA_VENDER){
            if(n->getEndereco().getBairro() == bairro){
                imoveisParaVenderPorBairro.push_back(n);
            }
        }
    }

    return imoveisParaVenderPorBairro;
}

list<Imovel *> SistemaImobiliaria::getImoveisPorCidade(string cidade){
    list<Imovel *> imoveisPorCidade;

    for(Imovel *n : listaDeImoveis){
        if(n->getEndereco().getCidade() == cidade){
            imoveisPorCidade.push_back(n);
        }
    }

    return imoveisPorCidade;
}

list<Imovel *> SistemaImobiliaria::getImoveisPorTipoAnuncio(int tipo){
    list<Imovel *> imoveisParaAlugar, imoveisParaVender;

    if(tipo == IMOVEL_PARA_VENDER){
        for(Imovel *m : listaDeImoveis){
            if(m->getTipoOferta() == IMOVEL_PARA_VENDER){
                imoveisParaVender.push_back(m);
            }
        }
        return imoveisParaVender;
    }else if(tipo == IMOVEL_PARA_ALUGAR){
        for(Imovel *n : listaDeImoveis){
            if(n->getTipoOferta() == IMOVEL_PARA_ALUGAR){
                imoveisParaAlugar.push_back(n);
            }
        }
        return imoveisParaAlugar;
    }
}
