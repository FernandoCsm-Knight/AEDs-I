
#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

//Classe Data
class Data {
    private:
        int dia,
            mes,
            ano;

    public:
    //CONSTRUCTOR & DESTRUCTOR
        Data(int dia = 0, int mes = 0, int ano = 0);
        ~Data();

    //SET
        bool setDate(int dia, int mes, int ano);
        bool setDia(int dia);
        bool setMes(int mes);
        bool setAno(int ano);

    //GET
        int getDia() const;
        int getMes() const;
        int getAno() const;
        std::string getMesExt() const;
        std::string getData() const;
        std::string getDataExt() const;

    //VERIFY
        bool verifyDate(int dia, int mes, int ano) const;
        bool verifyDia(int dia, int mes, int ano) const;
        bool verifyMes(int mes) const;
        bool verifyAno(int ano) const;

    //READ
        void rDate();

    //WRITE
        void wDateExt();
        void wDate();

    //SEARCH
        bool compDia(int dia);
        bool compMes(int mes);
        bool compAno(int ano);

};

#endif
