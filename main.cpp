#include <iostream>
#include <string>
#include <stdio.h>

#include "IMOVEL.H"
#include "SistemaImobiliaria.h"
#include "Apartamento.h"
#include "TERRENO.H"
#include "CASA.H"

#define FLUSH fflush(stdin)
#define CLEAR system("cls")
#define PAUSE system("pause")

//Todos
#define DESCRICAO 0
#define VALOR 1
#define TIPO_OFERTA 2
#define TITULO_ANUNCIO 3
#define RUA 4
#define NUMERO 5
#define BAIRRO 6
#define CIDADE 7
#define CEP 8

//Apartamento
#define POSICAO 9
#define VALOR_CONDOMINIO 10
#define A_AREA 11
#define A_NUM_QUARTOS 12
#define VAGAS_GARAGEM 13

//Casa
#define NUM_PAVIMENTO 9
#define NUM_QUARTOS 10
#define AREA_TERRENO 11
#define AREA_CONSTRUIDA 12

//Terreno
#define AREA 9

//Sistema
#define SI_BAIRRO 1
#define SI_CIDADE 2
#define TITULOANUNCIO 3
#define SI_PRECO 4

#define MAIOR_QUE 1
#define MENOR_QUE 2

extern int setIdGlobal(std::list <Imovel *> input);
extern void menuCasa();
extern void menuApartamento();
extern void menuTerreno();
extern void menuListar(int tipo);
extern void menuBusca(int tipo);
extern void menuPreco(int tipo);
extern int menuSubBusca();
extern void subBusca(std::list<Imovel *> lista, int tipoBusca, int tipoImovel);
extern void MenuEditar(int tipo, int id);

extern Imovel * CadastraImovel(int tipoImovel);

//Global
static int id = 1;

using namespace std;

SistemaImobiliaria sistema;
list<Imovel *> listaGenerica;
Imovel *a1 = new Apartamento();
Imovel *t1 = new Terreno();
Imovel *c1 = new Casa();

int main(){
    int 
        opcao = -1;

    listaGenerica = sistema.getControlador().RecuperaListaImoveis();
    sistema.setListaDeImoveis(listaGenerica);
    id = setIdGlobal(listaGenerica) + 1;

    while(opcao){
        cout << "	*** Imoveis ***\n" << endl;
        cout << "1) Casas" << endl;
        cout << "2) Apartamento" << endl;
        cout << "3) Terreno" << endl;
        cout << "0) Encerrar\n" << endl;

        do{
            cout << "Opcao: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 3);

        FLUSH;
        CLEAR;

        switch(opcao){
            case 1:
                menuCasa();
                break;
            case 2:
                menuApartamento();
                break;
            case 3:
                menuTerreno();
                break;
        }
    }
    sistema.getControlador().SalvaListaImoveis(sistema.getImoveis());

    return 0;
}

int setIdGlobal(std::list <Imovel *> input){
    int
        id;

    for(list<Imovel *>::iterator i = input.begin(); i != input.end(); i++){
        id = (*i)->getId();
    }
    return id;
}

Imovel * CadastraImovel(int tipoImovel){
    int
        tipoOferta, numero, numQuartos, vagasGaragem, numPavimento;

    double
        valor, valorCondominio, area, areaConstruida;

    string
        tituloAnuncio, descricao, logradouro, bairro, cidade, cep, posicao;

    cout << "Digite o valor: ";
    cin >> valor;
    FLUSH;

    cout << "Digite 1 para Venda e 2 para Aluguel: ";
    cin >> tipoOferta;
    FLUSH;

    cout << "Digite o numero do imovel: ";
    cin >> numero;
    FLUSH;
    
    cout << "Digite o titulo anuncio: ";
    getline(cin, tituloAnuncio);

    cout << "Digite a descricao: ";
    getline(cin, descricao);

    cout << "Digite o logradouro: ";
    getline(cin, logradouro);

    cout << "Digite o bairro: ";
    getline(cin, bairro);

    cout << "Digite o cidade: ";
    getline(cin, cidade);

    cout << "Digite o cep: ";
    getline(cin, cep);

    if(tipoImovel == APARTAMENTO){

        cout << "Digite a posicao: ";
        getline(cin, posicao);

        cout << "Digite o num de quartos: ";
        cin >> numQuartos;

        cout << "Digite o valor condiminio: ";
        cin >> valorCondominio;

        cout << "Digite o num de vagas da garagem: ";
        cin >> vagasGaragem;

        cout << "Digite a area: ";
        cin >> area;

        Apartamento *ap = new Apartamento();

        ap->setEndereco(logradouro, bairro, cidade, cep, numero);
        ap->setTipoOferta(tipoOferta);
        ap->setTituloAnuncio(tituloAnuncio);
        ap->setValor(valor);
        ap->setDescricao(descricao);

        ap->setPosicao(posicao);
        ap->setNumQuartos(numQuartos);
        ap->setValorCondominio(valorCondominio);
        ap->setVagasGaragem(vagasGaragem);
        ap->setArea(area);

        ap->setId(id++);

        return ap;
    }

    if(tipoImovel == TERRENO){

        cout << "Digite a area: ";
        cin >> area;
        FLUSH;
    
        Terreno *te = new Terreno();

        te->setEndereco(logradouro, bairro, cidade, cep, numero);
        te->setTipoOferta(tipoOferta);
        te->setTituloAnuncio(tituloAnuncio);
        te->setValor(valor);
        te->setDescricao(descricao);

        te->setArea(area);

        te->setId(id++);

        return te;
    }

    if(tipoImovel == CASA){

        cout << "Digite o num do Pavimento: ";
        cin >> numPavimento;
        FLUSH;
        
        cout << "Digite o num de quartos: ";
        cin >> numQuartos;
        FLUSH;
    
        cout << "Digite a area: ";
        cin >> area;
        FLUSH;

        cout << "Digite a area construida: ";
        cin >> areaConstruida;
        FLUSH;
    
        Casa *casa = new Casa();

        casa->setEndereco(logradouro, bairro, cidade, cep, numero);
        casa->setTipoOferta(tipoOferta);
        casa->setTituloAnuncio(tituloAnuncio);
        casa->setValor(valor);
        casa->setDescricao(descricao);

        casa->setNumPavimento(numPavimento);
        casa->setNumQuartos(numQuartos);
        casa->setAreaTerreno(area);
        casa->setAreaConstruida(areaConstruida);

        casa->setId(id++);

        return casa;
    }

}

void menuCasa(){
    int 
        opcao = -1, indice = 0;

    while(opcao){
        cout << "Imoveis -> Casa\n" << endl;
        cout << "1) Cadastrar Casa" << endl;
        cout << "2) Listar Casas" << endl;
        cout << "3) Pesquisar/Editar Casas" << endl;
        cout << "4) Excluir Casa" << endl;
        cout << "5) Salvar na lista" << endl;
        cout << "0) Voltar\n" << endl;
        do{
            cout << "Opcao: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 5);
        FLUSH;
        CLEAR;

        switch(opcao){
            case 1:
                c1 = CadastraImovel(CASA);
                if(c1->getValor() > 0){
                    sistema.cadastraImovel(c1);
                    CLEAR;
                    cout << c1->toString() << endl;
                    PAUSE;
                    CLEAR;
                }else{
                    cout << "Erro no cadastro!" << endl;
                }
                break;
            case 2:
                menuListar(CASA);
                break;
            case 3:
                menuBusca(CASA);
                break;
            case 4:
                sistema.printaLista(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA));
                cout << "Digite o indice da casa que deseja remover: ";
                cin >> indice;
                sistema.removeImovel(indice);
                break;            
            case 5:
                sistema.getControlador().SalvaListaImoveis(sistema.getImoveis());
                cout << "Lista salva com sucesso!" << endl;
                PAUSE;
                CLEAR;
                break;
        }//fim do switch
    }//fim do while
}

void menuApartamento(){

	int
        opcao = -1, indice;

    while(opcao){
        cout << "Imoveis -> Apartamento\n" << endl;
        cout << "1) Cadastrar Apartamento" << endl;
        cout << "2) Listar Apartamentos" << endl;
        cout << "3) Pesquisar/Editar Apartamentos" << endl;
        cout << "4) Excluir Apartamento" << endl;
        cout << "5) Salvar na lista" << endl;
        cout << "0) Voltar\n" << endl;
        do{
            cout << "Opcao: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 5);
        FLUSH;
        CLEAR;

        switch(opcao){
            case 1:
                a1 = CadastraImovel(APARTAMENTO);
                if(a1->getValor() > 0){
                    sistema.cadastraImovel(a1);
                    CLEAR;
                    cout << a1->toString() << endl;
                    PAUSE;
                    CLEAR;
                }else{
                    cout << "Erro no cadastro!" << endl;
                }
                break;
            case 2:
                menuListar(APARTAMENTO);
                break;
            case 3:
                menuBusca(APARTAMENTO);
                break;
            case 4:
                sistema.printaLista(sistema.getImoveisPorTipo(sistema.getImoveis(), APARTAMENTO));
                cout << "Digite o indice da casa que deseja remover: ";
                cin >> indice;
                sistema.removeImovel(indice);
                break;            
            case 5:
                sistema.getControlador().SalvaListaImoveis(sistema.getImoveis());
                cout << "Lista salva com sucesso!" << endl;
                PAUSE;
                CLEAR;
                break;
        }
    }
}

void menuTerreno(){
	int 
        opcao = -1, indice;

    while(opcao){
        cout << "Imoveis -> Terreno\n" << endl;
        cout << "1) Cadastrar Terreno" << endl;
        cout << "2) Listar Terrenos" << endl;
        cout << "3) Pesquisar/Editar Terrenos" << endl;
        cout << "4) Excluir Terreno" << endl;
        cout << "5) Salvar na lista" << endl;
        cout << "0) Voltar\n" << endl;
        do{
            cout << "Opcao: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 5);
        FLUSH;
        CLEAR;

        switch(opcao){
            case 1:
                t1 = CadastraImovel(TERRENO);
                if(t1->getValor() > 0){
                    sistema.cadastraImovel(t1);
                    CLEAR;
                    cout << t1->toString() << endl;
                    PAUSE;
                    CLEAR;
                }else{
                    cout << "Erro no cadastro!" << endl;
                }
                break;
            case 2:
                menuListar(TERRENO);
                break;
            case 3:
                menuBusca(TERRENO);
                break;
            case 4:
                sistema.printaLista(sistema.getImoveisPorTipo(sistema.getImoveis(), TERRENO));
                cout << "Digite o indice da casa que deseja remover: ";
                cin >> indice;
                sistema.removeImovel(indice);
                break;            
            case 5:
                sistema.getControlador().SalvaListaImoveis(sistema.getImoveis());
                cout << "Lista salva com sucesso!" << endl;
                PAUSE;
                CLEAR;
                break;
        }
    }
}

void menuListar(int tipo){

    int 
        opcao = -1;

    cout << "Imoveis -> Listar\n" << endl;
    cout << "1) Para Alugar" << endl;
    cout << "2) Para Vender" << endl;
    cout << "3) Listar Todas" << endl;
    cout << "0) Voltar\n" << endl;

    do{
        cout << "Opcao: ";
        cin >> opcao;
    }while(opcao <0 || opcao > 3);
    FLUSH;
    CLEAR;

    switch(opcao){
        case 1:
            switch(tipo){
            case CASA:
                listaGenerica = sistema.getImoveisPorTipoAnuncio(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), IMOVEL_PARA_ALUGAR);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;

            case APARTAMENTO:
                listaGenerica = sistema.getImoveisPorTipoAnuncio(sistema.getImoveisPorTipo(sistema.getImoveis(), APARTAMENTO), IMOVEL_PARA_ALUGAR);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;

            case TERRENO:
                listaGenerica = sistema.getImoveisPorTipoAnuncio(sistema.getImoveisPorTipo(sistema.getImoveis(), TERRENO), IMOVEL_PARA_ALUGAR);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;
            }
            break;
        case 2:
            switch(tipo){
            case CASA:
                listaGenerica = sistema.getImoveisPorTipoAnuncio(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), IMOVEL_PARA_VENDER);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;

            case APARTAMENTO:
                listaGenerica = sistema.getImoveisPorTipoAnuncio(sistema.getImoveisPorTipo(sistema.getImoveis(), APARTAMENTO), IMOVEL_PARA_VENDER);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;

            case TERRENO:
                listaGenerica = sistema.getImoveisPorTipoAnuncio(sistema.getImoveisPorTipo(sistema.getImoveis(), TERRENO), IMOVEL_PARA_VENDER);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;
            }
        	break;
        case 3:
            switch(tipo){
            case CASA:
                listaGenerica = sistema.getImoveisPorTipo(sistema.getImoveis(), CASA);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;

            case APARTAMENTO:
                listaGenerica = sistema.getImoveisPorTipo(sistema.getImoveis(), APARTAMENTO);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;

            case TERRENO:
                listaGenerica = sistema.getImoveisPorTipo(sistema.getImoveis(), TERRENO);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                break;
            }
    }//fim do switch
}

void menuBusca(int tipo){
	int
        opcao = -1, opcao2, indice;

    string
        bairro, cidade, tituloAnuncio;

    while(opcao){ //Exibicao de menu para usuario
        cout << "	*** Opcoes de busca ***\n" << endl;
        cout << "1) Buscar por bairro" << endl;
        cout << "2) Buscar por cidade" << endl;
        cout << "3) Buscar por titulo anuncio" << endl;
        cout << "4) Buscar por preco" << endl;
        cout << "0) Voltar\n" << endl;

        do{
            cout << "Opcao: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 4);
        FLUSH;
        CLEAR;

        switch(opcao){
            case SI_BAIRRO:
                cout << "Digite o bairro: ";
                getline(cin, bairro);

                listaGenerica = sistema.buscaImovel(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), bairro, SI_BAIRRO);
                sistema.printaLista(listaGenerica);
                PAUSE;

                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        subBusca(listaGenerica, SI_BAIRRO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;
            case SI_CIDADE:
                cout << "Digite a cidade: ";
                getline(cin, cidade);

                listaGenerica = sistema.buscaImovel(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), cidade, SI_CIDADE);
                sistema.printaLista(listaGenerica);
                PAUSE;

                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        subBusca(listaGenerica, SI_CIDADE, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;
            case TITULOANUNCIO:
                cout << "Digite o titulo anuncio: ";
                getline(cin, tituloAnuncio);

                listaGenerica = sistema.buscaImovel(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), tituloAnuncio, TITULOANUNCIO);
                sistema.printaLista(listaGenerica);
                PAUSE;

                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        subBusca(listaGenerica, TITULOANUNCIO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                        break;
                    }
                break;            
            case SI_PRECO:
                menuPreco(tipo);
                PAUSE;
                CLEAR;
                break;
        }
    }
}

void menuPreco(int tipo){

	int
        opcao = -1, opcao2, indice;
    double
        valor;

    while(opcao){ //Exibicao de menu para usuario
        cout << "	*** Opcoes de busca -> Preco***\n" << endl;
        cout << "1) Buscar por valor minimo" << endl;
        cout << "2) Buscar por valor maximo" << endl;
        cout << "0) Voltar\n" << endl;

        do{
            cout << "Opcao: ";
            cin >> opcao;
        }while(opcao < 0 || opcao > 2);
        FLUSH;
        CLEAR;

        switch(opcao){
        case 1:
            switch(tipo){
            case CASA:
                cout << "Digite o valor minimo: ";
                cin >> valor;
                CLEAR;

                listaGenerica = sistema.buscaImovelValor(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), valor, MAIOR_QUE);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        CLEAR;
                        subBusca(listaGenerica, SI_PRECO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;

            case APARTAMENTO:
                cout << "Digite o valor minimo: ";
                cin >> valor;
                CLEAR;

                listaGenerica = sistema.buscaImovelValor(sistema.getImoveisPorTipo(sistema.getImoveis(), APARTAMENTO), valor, MAIOR_QUE);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        CLEAR;
                        subBusca(listaGenerica, SI_PRECO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;

            case TERRENO:
                cout << "Digite o valor minimo: ";
                cin >> valor;
                CLEAR;

                listaGenerica = sistema.buscaImovelValor(sistema.getImoveisPorTipo(sistema.getImoveis(), TERRENO), valor, MAIOR_QUE);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                opcao2 = menuSubBusca();
                    switch(opcao2){
                    case 1:
                        CLEAR;
                        subBusca(listaGenerica, SI_PRECO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;
            }
            break;
        case 2:
            switch(tipo){
            case CASA:
                cout << "Digite o valor maximo: ";
                cin >> valor;
                CLEAR;

                listaGenerica = sistema.buscaImovelValor(sistema.getImoveisPorTipo(sistema.getImoveis(), CASA), valor, MENOR_QUE);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        CLEAR;
                        subBusca(listaGenerica, SI_PRECO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;

            case APARTAMENTO:
                cout << "Digite o valor maximo: ";
                cin >> valor;
                CLEAR;

                listaGenerica = sistema.buscaImovelValor(sistema.getImoveisPorTipo(sistema.getImoveis(), APARTAMENTO), valor, MENOR_QUE);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        CLEAR;
                        subBusca(listaGenerica, SI_PRECO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;

            case TERRENO:
                cout << "Digite o valor maximo: ";
                cin >> valor;

                CLEAR;
                listaGenerica = sistema.buscaImovelValor(sistema.getImoveisPorTipo(sistema.getImoveis(), TERRENO), valor, MENOR_QUE);
                sistema.printaLista(listaGenerica);
                PAUSE;
                CLEAR;
                opcao2 = menuSubBusca();
                    switch (opcao2){
                    case 1:
                        CLEAR;
                        subBusca(listaGenerica, SI_PRECO, tipo);
                        break;
                    case 2:
                        sistema.printaLista(listaGenerica);
                        cout << "Digite o ID que deseja editar: ";
                        cin >> indice;

                        CLEAR;
                        MenuEditar(tipo, indice);
                        break;
                    }
                break;
            }
        	break;
        }
    }
}

int menuSubBusca(){
    int
        opcao = -1, flag = 0;

    while(opcao){ //Exibicao de menu para usuario
        do{
            cout << "	*** Opcoes de busca***\n" << endl;
            cout << "1) Refinar busca" << endl;
            cout << "2) Editar imovel" << endl;
            cout << "0) Voltar\n" << endl;
            cout << "Opcao: ";
            cin >> opcao;
            if(opcao < 0 || opcao > 2){
                CLEAR;
                cout << "\nInvalido, digite novamente." << endl;
            }
        }while(opcao < 0 || opcao > 2);
        break;
        CLEAR;
    }
    return opcao;
}

void subBusca(list<Imovel *> lista, int tipoBusca, int tipoImovel){
	int
        opcao = -1, escolha;
    string
        bairro, cidade, tituloAnuncio;
    double
        valor;
        
	switch(tipoBusca){
		case SI_BAIRRO:
			while(opcao){ //Exibicao de menu para usuario
		        do{
                    cout << "	*** Opcoes de busca -> Bairro***\n" << endl;
                    cout << "1) Buscar por cidade" << endl;
                    cout << "2) Buscar por titulo anuncio" << endl;
                    cout << "3) Buscar por preco" << endl;
                    cout << "0) Voltar\n" << endl;
		            cout << "Opcao: ";
		            cin >> opcao;
		        }while(opcao < 0 || opcao > 3);
		        FLUSH;
		        CLEAR;
		        switch(opcao){
		        	case SI_CIDADE-1:
		        		cout << "Digite a cidade: ";
                		getline(cin, cidade);

                		listaGenerica = sistema.buscaImovel(lista, cidade, SI_CIDADE);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        	case TITULOANUNCIO-1:
		        		cout << "Digite o titulo anuncio: ";
                		getline(cin, tituloAnuncio);

                		listaGenerica = sistema.buscaImovel(lista, tituloAnuncio, TITULOANUNCIO);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        		
		        	case SI_PRECO-1:
		        		while(1){						
							cout << "Digite 1 para valor maximo, ou 2 para valor minimo";
							cin >> escolha;
							if(escolha != 1 && escolha != 2){
								cout << "Erro, digite novamente!" << endl;
							}else{
								break;
							}
						}
		        		if(escolha == 1){
		        			cout << "Digite o valor maximo: ";
			                cin >> valor;
			                CLEAR;
			
			                listaGenerica = sistema.buscaImovelValor(lista, valor, MENOR_QUE);
			                sistema.printaLista(listaGenerica);
			                PAUSE;
			                CLEAR;
			                break;
						}
						else if(escolha == 2){
							cout << "Digite o valor minimo: ";
                			cin >> valor;
                			CLEAR;

			                listaGenerica = sistema.buscaImovelValor(lista, valor, MAIOR_QUE);
			                sistema.printaLista(listaGenerica);
			                PAUSE;
			                CLEAR;
			                break;
						}
				}
			}		
		case SI_CIDADE:
			while(opcao){ //Exibicao de menu para usuario
		        cout << "	*** Opcoes de busca -> Cidade***\n" << endl;
		        cout << "1) Buscar por bairro" << endl;
		        cout << "2) Buscar por titulo anuncio" << endl;
		        cout << "3) Buscar por preco" << endl;
		        cout << "0) Voltar\n" << endl;
		
		        do{
		            cout << "Opcao: ";
		            cin >> opcao;
		        }while(opcao < 0 || opcao > 3);
		        FLUSH;
		        CLEAR;
		        switch(opcao){
		        	case SI_BAIRRO:
		        		cout << "Digite o bairro: ";
                		getline(cin, bairro);

                		listaGenerica = sistema.buscaImovel(lista, bairro, SI_BAIRRO);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        	case TITULOANUNCIO-1:
		        		cout << "Digite o titulo anuncio: ";
                		getline(cin, tituloAnuncio);

                		listaGenerica = sistema.buscaImovel(lista, tituloAnuncio, TITULOANUNCIO);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        		
		        	case SI_PRECO-1:
		        		while(1){						
							cout << "Digite 1 para valor maximo, ou 2 para valor minimo";
							cin >> escolha;
							if(escolha != 1 && escolha != 2){
								cout << "Erro, digite novamente!" << endl;
							}else{
								break;
							}
						}
		        		if(escolha == 1){
		        			cout << "Digite o valor maximo: ";
			                cin >> valor;
			                CLEAR;
			
			                listaGenerica = sistema.buscaImovelValor(lista, valor, MENOR_QUE);
			                sistema.printaLista(listaGenerica);
			                PAUSE;
			                CLEAR;
			                break;
						}
						else if(escolha == 2){
							cout << "Digite o valor minimo: ";
                			cin >> valor;
                			CLEAR;

			                listaGenerica = sistema.buscaImovelValor(lista, valor, MAIOR_QUE);
			                sistema.printaLista(listaGenerica);
			                PAUSE;
			                CLEAR;
			                break;
						}
				}
			}
		case TITULOANUNCIO:
			while(opcao){ //Exibicao de menu para usuario
		        cout << "	*** Opcoes de busca -> Titulo Anuncio***\n" << endl;
		        cout << "1) Buscar por bairro" << endl;
		        cout << "2) Buscar por cidade" << endl;
		        cout << "3) Buscar por preco" << endl;
		        cout << "0) Voltar\n" << endl;
		
		        do{
		            cout << "Opcao: ";
		            cin >> opcao;
		        }while(opcao < 0 || opcao > 3);
		        FLUSH;
		        CLEAR;
		        switch(opcao){
		        	case SI_BAIRRO:
		        		cout << "Digite o bairro: ";
                		getline(cin, bairro);

                		listaGenerica = sistema.buscaImovel(lista, bairro, SI_BAIRRO);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        	case SI_CIDADE:
		        		cout << "Digite a cidade: ";
                		getline(cin, cidade);

                		listaGenerica = sistema.buscaImovel(lista, cidade, SI_CIDADE);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        		
		        	case SI_PRECO-1:
		        		while(1){						
							cout << "Digite 1 para valor maximo, ou 2 para valor minimo";
							cin >> escolha;
							if(escolha != 1 && escolha != 2){
								cout << "Erro, digite novamente!" << endl;
							}else{
								break;
							}
						}
		        		if(escolha == 1){
		        			cout << "Digite o valor maximo: ";
			                cin >> valor;
			                CLEAR;
			
			                listaGenerica = sistema.buscaImovelValor(lista, valor, MENOR_QUE);
			                sistema.printaLista(listaGenerica);
			                PAUSE;
			                CLEAR;
			                break;
						}
						else if(escolha == 2){
							cout << "Digite o valor minimo: ";
                			cin >> valor;
                			CLEAR;

			                listaGenerica = sistema.buscaImovelValor(lista, valor, MAIOR_QUE);
			                sistema.printaLista(listaGenerica);
			                PAUSE;
			                CLEAR;
			                break;
						}
				}
			}
		case SI_PRECO:
			while(opcao){ //Exibicao de menu para usuario
		        cout << "	*** Opcoes de busca -> Preco***\n" << endl;
		        cout << "1) Buscar por bairro" << endl;
		        cout << "2) Buscar por cidade" << endl;
		        cout << "3) Buscar por titulo anuncio" << endl;
		        cout << "0) Voltar\n" << endl;
		
		        do{
		            cout << "Opcao: ";
		            cin >> opcao;
		        }while(opcao < 0 || opcao > 3);
		        FLUSH;
		        CLEAR;
		        switch(opcao){
		        	case SI_BAIRRO:
		        		cout << "Digite o bairro: ";
                		getline(cin, bairro);

                		listaGenerica = sistema.buscaImovel(lista, bairro, SI_BAIRRO);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        	case SI_CIDADE:
		        		cout << "Digite a cidade: ";
                		getline(cin, cidade);

                		listaGenerica = sistema.buscaImovel(lista, cidade, SI_CIDADE);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
		        		
		        	case TITULOANUNCIO:
		        		cout << "Digite o titulo anuncio: ";
                		getline(cin, tituloAnuncio);

                		listaGenerica = sistema.buscaImovel(lista, tituloAnuncio, TITULOANUNCIO);
                		sistema.printaLista(listaGenerica);
                		PAUSE;
                		CLEAR;
                		break;
				}
			}
	}
    cout << "Deseja editar algum imovel? Digite 1 para sim, ou 2 para nao: ";
    cin >> escolha;

    if(escolha == 1){
        MenuEditar(tipoImovel, escolha);
    }
}

void MenuEditar(int tipo, int id){
    int
        opcao = -1;
    string
        novaString;
    double
        novoDouble;

    while(1){
        cout << "	*** Opcoes de edicao ***\n" << endl;
        cout << "1) Editar valor" << endl;
        cout << "2) Editar tipo de oferta (Aluguel ou venda)" << endl;
        cout << "3) Editar numero do imovel" << endl;
        cout << "4) Editar titulo anuncio" << endl;
        cout << "5) Editar descricao" << endl;
        cout << "6) Editar logradouro" << endl;
        cout << "7) Editar bairro" << endl;
        cout << "8) Editar cidade" << endl;
        cout << "9) Editar cep" << endl;

        if(tipo == APARTAMENTO){
            cout << "10) Editar numero de quartos" << endl;
            cout << "11) Editar valor de condominio" << endl;
            cout << "12) Editar numero de vagas na garagem" << endl;
            cout << "13) Editar area" << endl;
            cout << "0) Voltar\n" << endl;
            cout << "Opcao: ";
            cin >> opcao;

            CLEAR;
            if(opcao >= 0 && opcao < 13){
                break;
            }else{
                cout << "Invalido!" << endl;
            }
        }

        if(tipo == TERRENO){
            cout <<"10) Editar area" << endl;
            cout << "0) Voltar\n" << endl;
            cout << "Opcao: ";
            cin >> opcao;

            CLEAR;
            if(opcao >= 0 && opcao < 10){
                if(opcao == 10){
                    opcao = 14;
                }
                break;
            }else{
                cout << "Invalido!" << endl;
            }
        }

        if(tipo == CASA){
            cout << "10) Editar numero do pavimento" << endl;
            cout << "11) Editar numero de quartos" << endl;
            cout << "12) Editar area" << endl;
            cout << "13) Editar area construida" << endl;
            cout << "0) Voltar\n" << endl;
            cout << "Opcao: ";
            cin >> opcao;

            CLEAR;
            if(opcao >= 0 && opcao < 13){
                if(opcao >= 10){
                    opcao += 5;
                }
                break;
            }else{
                cout << "Invalido!" << endl;
            }
        }
    }
    switch(opcao){
        case 1:
        case 2:
        case 3:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            cout << "Digite o novo valor: ";
            cin >> novoDouble;
            sistema.editaImovel(id, " ", novoDouble, opcao);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            cout << "Digite a nova string: ";
            cin >> novaString;
            sistema.editaImovel(id, novaString, 0, opcao);
    }
        
}

//Caracter especial (franklin)