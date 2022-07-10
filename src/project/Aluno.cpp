
#include "../header/Aluno.hpp"

Aluno::Aluno(int& pos, int dia, int mes, int ano, std::string name, std::string curso):Pessoa(pos, dia, mes, ano, name) {
    this->setCurso(curso);
}   

//SET
void Aluno::setCurso(std::string curso) {
    this->curso = curso;
}

//GET
std::string Aluno::Origem() const{
    return "Aluno: " + this->curso;
}

//READ
void Aluno::rPessoa() {
    Pessoa::rPessoa();
    std::string p;
    fflush(stdin);
    std::cout << "Digite o curso: ";
    getline(std::cin, p);
    setCurso(p);
}
