#include "SistemaImobiliaria.h"

using namespace std;

GerenteDePersistencia::GerenteDePersistencia()
{
    //ctor
}

std::list<Imovel *> GerenteDePersistencia::RecuperaListaImoveis(){
    ifstream
        ler;

    std::list<Imovel *>
        listaDeImovel;

    int
        id, tipoImovel, tipoOferta, numero, numQuartos, vagasGaragem, numPavimento, lixo;

    double
        valor, valorCondominio, area, areaConstruida;

    string
        tituloAnuncio, descricao, logradouro, bairro, cidade, cep, posicao;


    ler.open("listaImoveis.txt", ios::in);

    if(!ler.is_open( )){
        cout << "deu errado brother" << endl;
        ler.close();
    }

    while(!ler.eof()){
        ler >> id;
        ler >> tipoImovel;
        ler >> valor;

        ler >> tipoOferta;
        ler.ignore();
        
        getline(ler, tituloAnuncio);
        getline(ler, descricao);
        getline(ler, logradouro);
        
        ler >> numero;
        ler.ignore();

        getline(ler, bairro);
        getline(ler, cidade);
        getline(ler, cep);

        if(tipoImovel == APARTAMENTO){
            getline(ler, posicao);
        
            ler >> numQuartos;
            ler >> valorCondominio;
            ler >> vagasGaragem;
            ler >> area;
            ler.ignore();

            Apartamento *ap = new Apartamento();

            ap->setId(id);
            ap->setEndereco(logradouro, bairro, cidade, cep, numero);
            ap->setTipoOferta(tipoOferta);
            ap->setTituloAnuncio(tituloAnuncio);
            ap->setDescricao(descricao);
            ap->setValor(valor);

            ap->setPosicao(posicao);
            ap->setNumQuartos(numQuartos);
            ap->setValorCondominio(valorCondominio);
            ap->setVagasGaragem(vagasGaragem);
            ap->setArea(area);

            listaDeImovel.push_back(ap);
        }

        if(tipoImovel == TERRENO){
            ler >> area;
            ler.ignore();

            Terreno *te = new Terreno();

            te->setId(id);
            te->setEndereco(logradouro, bairro, cidade, cep, numero);
            te->setTipoOferta(tipoOferta);
            te->setTituloAnuncio(tituloAnuncio);
            te->setDescricao(descricao);
            te->setValor(valor);

            te->setArea(area);

            listaDeImovel.push_back(te);
        }

        if(tipoImovel == CASA){
            ler >> numPavimento;
            ler >> numQuartos;
            ler >> area;      
            ler >> areaConstruida;
            ler.ignore();

            Casa *casa = new Casa();

            casa->setId(id);
            casa->setEndereco(logradouro, bairro, cidade, cep, numero);
            casa->setTipoOferta(tipoOferta);
            casa->setTituloAnuncio(tituloAnuncio);
            casa->setDescricao(descricao);
            casa->setValor(valor);

            casa->setNumPavimento(numPavimento);
            casa->setNumQuartos(numQuartos);
            casa->setAreaTerreno(area);
            casa->setAreaConstruida(areaConstruida);

            listaDeImovel.push_back(casa);
        }
    }
    return listaDeImovel;

}

void GerenteDePersistencia::SalvaListaImoveis(std::list<Imovel *> listaImoveis){
    ofstream salvar;

    salvar.open("listaImoveis.txt", ios::out);

    if(!salvar.is_open( )){
        cout << "deu errado brother" << endl;
        salvar.close();
        return;
    }

    for(Imovel *i : listaImoveis){
        salvar << i->toStringSalvar();
    }

    salvar.close();
}
