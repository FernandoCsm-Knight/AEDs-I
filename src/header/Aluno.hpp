
#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Pessoa.hpp"

class Aluno:public Pessoa {
    private:
        std::string curso;

    public:
    //CONSTRUCTOR
        Aluno(int& pos, int dia = 0, int mes = 0, int ano = 0, std::string name = "", std::string curso = "");

    //SET
        void setCurso(std::string curso);

    //GET
        std::string Origem() const;

    //READ
        void rPessoa();
};

#endif
