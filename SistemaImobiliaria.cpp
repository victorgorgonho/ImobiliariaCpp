#include <iostream>
#include "SistemaImobiliaria.h"
#include "IMOVEL.H"
#include "Apartamento.h"
#include "TERRENO.H"
#include "CASA.H"

using namespace std;

SistemaImobiliaria::SistemaImobiliaria(){
}

void SistemaImobiliaria::cadastraImovel(Imovel *tImovel){
    listaDeImoveis.push_back(tImovel);
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
