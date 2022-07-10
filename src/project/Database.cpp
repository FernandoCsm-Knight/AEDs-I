
#include "../header/Database.hpp"

//CONSTRUCTOR & DESTRUCTOR
Database::Database() {
    this->setPosicao(0);
}

Database::~Database() {
    std::cout << "\nFinalizando..." << std::endl;
    limpaMemoria();
    std::cout << "\n\t=> Liberando Base de Dados.\n" << std::endl;
}

//SET
bool Database::setPosicao(int tam) {
    bool valido = tam >= 0;
    if(valido) this->posicao = tam;
    return valido;
}

void Database::setAluno() {
    int pos = getPosicao();
    this->people[pos] = new Aluno(this->posicao);
    this->people[pos]->rPessoa();
}

void Database::setProfessor() {
    int pos = getPosicao();
    this->people[pos] = new Professor(this->posicao);
    this->people[pos]->rPessoa();
}

//GET
int Database::getPosicao() const {
    return this->posicao;
}

//READ
void Database::leValor(int& a, std::string str, int max) {
    bool erro;
    do {
        fflush(stdin);
        std::cout << "\nDigite o " << str;
        std::cin >> a;
        erro = a < 1 || a > max;
        if(erro) std::cout << "\nValor invalido... Digite novamente\n" << std::endl;
    } while(erro);
}

void Database::leNome(std::string& nome)  {
    fflush(stdin);
    std::cout << "\nDigite o nome: ";
    getline(std::cin, nome);
}

//LIST
void Database::listaPessoas() {
    int pos = getPosicao();
    for(int i = 0; i < pos; i++) {
        people[i]->wPessoa();
    }
}

//SEARCH
void Database::menuPesquisa() {
    int valor = 0;
    int cont = 0;
    int pos = getPosicao();
    std::string nome;

    Menu* init = new Menu(1, 4, "\n\t1 - Pesquisar por Nome\n\t2 - Pesquisar por Dia\n\t3 - Pesquisar por Mes\n\t4 - Pesquisar por Ano\n");

    init->wInterface();
    switch(init->getOpt()) {
        case 1:
            leNome(nome);
            for(int i = 0; i < pos; i++) {
                if(people[i]->nameIncludes(nome)) {
                    people[i]->wPessoa();
                    cont++;
                }                
            }
            break;
        
        case 2:
            leValor(valor, "Dia: ", 31);
            for(int i = 0; i < pos; i++) {
                if(people[i]->getBirth()->compDia(valor)) {
                    people[i]->wPessoa();
                    cont++;
                }                
            }
            break;

        case 3:
            leValor(valor, "Mes: ", 12);
            for(int i = 0; i < pos; i++) {
                if(people[i]->getBirth()->compMes(valor)) {
                    people[i]->wPessoa();
                    cont++;
                }                
            }
            break;

        case 4:
            leValor(valor, "Ano: ", 2022);
            for(int i = 0; i < pos; i++) {
                if(people[i]->getBirth()->compAno(valor)) {
                    people[i]->wPessoa();
                    cont++;
                }                
            }
    } 
    if(cont == 0) std::cout << "\nSem Resultado" << std::endl;
    std::cout << std::endl;
    delete init;
}

void Database::menuPessoas() {
    Menu* init = new Menu(1, 2, "\n\t1 - Cadastrar Aluno\n\t2 - Cadastrar Professor\n");

    init->wInterface();
    switch(init->getOpt()) {
        case 1:
            this->setAluno();
            break;

        case 2:
            this->setProfessor();

    }
    delete init;
}

void Database::menuPrincipal() { 
    Menu* init = new Menu(0, 3, "\n\t0 - Sair\n\t1 - Cadastrar pessoa\n\t2 - Listar pessoas\n\t3 - Pesquisar pessoas\n");
    
    init->wInterface();
    int option = init->getOpt();

    while(option != 0) {
        switch(option) {
            case 1:
                if(this->getPosicao() < MAX) menuPessoas();
                else std::cout << "\nNao ha mais espaco...\n" << std::endl; 
                break;

            case 2:
                listaPessoas();
                break;

            case 3:
                menuPesquisa();

        }
        init->wInterface();
        option = init->getOpt();
    }
    delete init;
}

//FREE
void Database::limpaMemoria() {
    int pos = getPosicao();
    for(int i = 0; i < pos; i++) {
        delete people[i];
    }
}
