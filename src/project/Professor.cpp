
#include "../header/Professor.hpp"

Professor::Professor(int& pos, int dia, int mes, int ano, std::string name, std::string dep):Pessoa(pos, dia, mes, ano, name) {
    this->setDepto(dep);
}   

//SET
void Professor::setDepto(std::string dep) {
    this->departamento = dep;
}

//GET
std::string Professor::Origem() const{
    return "Professor: " + this->departamento;
}

//READ
void Professor::rPessoa() {
    Pessoa::rPessoa();
    std::string p;
    fflush(stdin);
    std::cout << "Digite o departamento: ";
    getline(std::cin, p);
    setDepto(p);
}
