#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#define MAX 10

#include "Aluno.hpp"
#include "Professor.hpp"
#include "Menu.hpp"

class Database {
    private:
        Pessoa* people[MAX];
        int posicao;

        //FREE
        void limpaMemoria();

    public:
    //CONSTRUCTOR & DESTRUCTOR
        Database();
        ~Database();

    //SET    
        bool setPosicao(int tam);
        void setAluno();
        void setProfessor();
        void incPosicao();

    //GET
        int getPosicao() const;

    //READ
        void leValor(int& a, std::string str, int max);
        void leNome(std::string& nome);

    //LIST
        void listaPessoas();

    //SEARCH
        void menuPesquisa();
        void menuPessoas();

        void menuPrincipal();

};

#endif
