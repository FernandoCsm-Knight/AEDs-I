
#include "../header/Pessoa.hpp"

//Constructor & Destructor
Pessoa::Pessoa(int& pos, int dia, int mes, int ano, std::string name) {
    this->setName(name);
    this->setBirth(dia, mes, ano); 
    pos++;
}

Pessoa::~Pessoa() {
    delete this->birth;
    std::cout << "\n\t=> Memoria de " << this->getName() << " Liberada." << std::endl;
}

//SET functions
void Pessoa::setName(std::string name) {
    this->name = name;
}

void Pessoa::setBirth(int dia, int mes, int ano) {
    this->birth = new Data(dia, mes, ano);
}

//GET functions
Data* Pessoa::getBirth() const {
    return this->birth;
}

std::string Pessoa::getName() const {
    return this->name;
}

//READ function
void Pessoa::rPessoa() {
    std::string palavra;
    fflush(stdin);
    std::cout << "\nDigite seu nome: ";
    getline(std::cin, palavra);
    this->setName(palavra);
    this->getBirth()->rDate();
}

//WRITE functions
void Pessoa::wPessoa() {
    std::cout << this->getName() << " - " << this->Origem() << " { " << this->getBirth()->getData() << " => " << this->getBirth()->getDataExt() << " }" << std::endl;
}

//Boolean
bool Pessoa::nameIncludes(std::string str) {
    std::string nome = this->getName();

    for(int i = 0; i < str.length(); i++) if((int)str[i] < 91) str[i] = (char)((int)str[i] + 32);
    for(int h = 0; h < nome.length(); h++) if((int)nome[h] < 91) nome[h] = (char)((int)nome[h] + 32);

    bool valido;
    for(int i = 0, j = 0; i < nome.length(); i++) {
        valido = str[j] == nome[i];

        if(valido) j++;

        if(j == str.length()) i = nome.length();
        
        if(j != 0 && !valido) {
            j = 0;
            i -= j;
        }
    } return valido;
}
