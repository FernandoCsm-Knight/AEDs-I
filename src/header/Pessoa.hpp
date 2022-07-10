
#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Data.hpp"

class Pessoa {
    private:
        std::string name;
        Data* birth;

    public:
    //CONSTRUCTOR & DESTRUCTOR
        Pessoa(int& pos, int dia = 0, int mes = 0, int ano = 0, std::string name = ""); 
        ~Pessoa();

    //SET
        void setName(std::string name);
        void setBirth(int dia, int mes, int ano);

    //GET
        Data* getBirth() const;
        std::string getName() const;
        virtual std::string Origem() const = 0;

    //READ
        virtual void rPessoa();

    //WRITE
        void wPessoa();

    //BOOL
        bool nameIncludes(std::string str);
};

#endif
