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

void SistemaImobiliaria::printaLista(std::list<Imovel *> lista){
    for(Imovel *n : lista){
        cout << n->toString() << endl;
    }
}

GerenteDePersistencia SistemaImobiliaria::getControlador(){
    return controlador;
}

list<Imovel *> SistemaImobiliaria::buscaImovel(std::list<Imovel *> lista, string substring, int tipoSubstring){
    list<Imovel *> resultado;
    string stringMinuscula;
    size_t posicaoSubstring;

    for(Imovel *n : lista){
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

list<Imovel *> SistemaImobiliaria::buscaImovelValor(std::list<Imovel *> lista, double valor, int tipoBusca){
    list<Imovel *> resultado;

    for(Imovel *n : lista){
        if(tipoBusca == MAIOR_QUE ){
            if(n->getValor() >= valor)
                resultado.push_back(n);
        }else if(tipoBusca == MENOR_QUE){
            if(n->getValor() <= valor){
                resultado.push_back(n);
            }
        }
    }
    return resultado;
}

list<Imovel *> SistemaImobiliaria::getImoveis(){
    return listaDeImoveis;
}

list<string> SistemaImobiliaria::getDescricaoImoveis(std::list<Imovel *> lista){
    list<string> descricaoImoveis;
    for(Imovel *n : lista){
        descricaoImoveis.push_back(n->toString());
    }

    return descricaoImoveis;
}

list<string> SistemaImobiliaria::getDescricaoSalvarImoveis(std::list<Imovel *> lista){
    list<string> descricaoSalvarImoveis;
    for(Imovel *n : lista){
        descricaoSalvarImoveis.push_back(n->toStringSalvar());
    }

    return descricaoSalvarImoveis;
}

std::list<std::string> SistemaImobiliaria::getResumoImoveis(std::list<Imovel *> lista){
    list<string> resumoImoveis;

    stringstream resumo;

    for(Imovel *n : lista){
        resumo << "Titulo: " << n->getTituloAnuncio() 
               << "\nBairro: " << n->getEndereco().getBairro() 
               << "\nCidade: " << n->getEndereco().getCidade()
               << "\nValor: " << n->getValor() << endl;

        resumoImoveis.push_back(resumo.str());
    }

    return resumoImoveis;
}

list<Imovel *> SistemaImobiliaria::getImoveisPorTipo(std::list<Imovel *> lista, int tipo){
    list<Imovel *> imoveisPorTipo;

    for(Imovel *n : lista){
        if(n->getTipoImovel() == tipo)
            imoveisPorTipo.push_back(n);
    }

    return imoveisPorTipo;
}

list<Imovel *> SistemaImobiliaria::getImoveisPorTipoAnuncio(std::list<Imovel *> lista, int tipo){
    list<Imovel *> imoveisParaAlugar, imoveisParaVender;

    if(tipo == IMOVEL_PARA_VENDER){
        for(Imovel *m : lista){
            if(m->getTipoOferta() == IMOVEL_PARA_VENDER){
                imoveisParaVender.push_back(m);
            }
        }
        return imoveisParaVender;
    }else if(tipo == IMOVEL_PARA_ALUGAR){
        for(Imovel *n : lista){
            if(n->getTipoOferta() == IMOVEL_PARA_ALUGAR){
                imoveisParaAlugar.push_back(n);
            }
        }
        return imoveisParaAlugar;
    }
}
