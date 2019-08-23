#include "SistemaImobiliaria.h"

using namespace std;

SistemaImobiliaria::SistemaImobiliaria(){
}

void SistemaImobiliaria::setListaDeImoveis(std::list<Imovel *> lista){
    int
        reset = 0;

    list<Imovel *> listaSemRepetido;

    for(Imovel *i : lista){

        if(reset){
            reset = 0;
            continue;
        }else{
            listaSemRepetido.push_back(i);
            reset++;
        }
    }
    listaDeImoveis = listaSemRepetido;
}

void SistemaImobiliaria::cadastraImovel(Imovel *tImovel){
    listaDeImoveis.push_back(tImovel);
}

void SistemaImobiliaria::editaImovel(int id, string novaString, double novoValor, int tipoModificacao){
    list<Imovel *> novaLista;

    for(Imovel *i : listaDeImoveis){
        if(i->getId() == id){
            switch(tipoModificacao){
                case 1:
                    i->setValor(novoValor);
                    break;
                case 2:
                    i->setTipoOferta(novoValor);
                    break;
                case 3:
                    i->getEndereco().setNumero(novoValor);
                    break;
                case 4:
                    i->setTituloAnuncio(novaString);
                    break;
                case 5:
                    i->setDescricao(novaString);
                    break;
                case 6:
                    i->getEndereco().setLogradouro(novaString);
                    break;
                case 7:
                    i->getEndereco().setBairro(novaString);
                    break;
                case 8:
                    i->getEndereco().setCidade(novaString);
                    break;
                case 9:
                    i->getEndereco().setCep(novaString);
                    break;
                case 10:
                    ((Apartamento *)i)->setNumQuartos(novoValor);
                    break;
                case 11:
                    ((Apartamento *)i)->setValorCondominio(novoValor);
                    break;
                case 12:
                    ((Apartamento *)i)->setVagasGaragem(novoValor);
                    break;
                case 13:
                    ((Apartamento *)i)->setArea(novoValor);
                case 14:
                    ((Terreno *)i)->setArea(novoValor);
                case 17:
                    ((Casa *)i)->setAreaTerreno(novoValor);
                    break;
                case 15:
                    ((Casa *)i)->setNumPavimento(novoValor);
                    break;
                case 16:
                    ((Casa *)i)->setNumQuartos(novoValor);
                    break;
                case 18:
                    ((Casa *)i)->setAreaConstruida(novoValor);
            }
        }
        novaLista.push_back(i);
    }
    listaDeImoveis = novaLista;
}

void SistemaImobiliaria::removeImovel(int indice){
    for(list<Imovel *>::iterator i = listaDeImoveis.begin(); i != listaDeImoveis.end(); i++){
        if((*i)->getId() == indice){
            i = listaDeImoveis.erase(i);
            break;
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

                if(posicaoSubstring >= 0 && posicaoSubstring < stringMinuscula.size()){
                    resultado.push_back(n);
                }
                break;

            case SI_CIDADE:
                stringMinuscula = n->getEndereco().getCidade();
                transform(stringMinuscula.begin(), stringMinuscula.end(), stringMinuscula.begin(), ::tolower);
                transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

                posicaoSubstring = stringMinuscula.find(substring);

                if(posicaoSubstring >= 0 && posicaoSubstring < stringMinuscula.size())
                    resultado.push_back(n);
                break;

            case TITULOANUNCIO:
                stringMinuscula = n->getTituloAnuncio();
                transform(stringMinuscula.begin(), stringMinuscula.end(), stringMinuscula.begin(), ::tolower);
                transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

                posicaoSubstring = stringMinuscula.find(substring);

                if(posicaoSubstring >= 0 && posicaoSubstring < stringMinuscula.size())
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
