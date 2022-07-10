
#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Pessoa.hpp"

class Professor:public Pessoa {
    private:
        std::string departamento;

    public:
    //CONSTRUCTOR
        Professor(int& pos, int dia = 0, int mes = 0, int ano = 0, std::string name = "", std::string dep = "");

    //SET
        void setDepto(std::string dep);

    //GET
        std::string Origem() const;

    //READ
        void rPessoa();
};

#endif
