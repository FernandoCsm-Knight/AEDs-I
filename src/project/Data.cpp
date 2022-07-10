
#include "../header/Data.hpp"

//Constructor e Destructor
Data::Data(int dia, int mes, int ano) {
    this->setDate(dia, mes, ano);
}

Data::~Data() {
    std::cout << "\n\t=> Memoria de " << this->getDataExt() << " Liberada." << std::endl;
}

//SET functions
bool Data::setDia(int dia) {
    bool valido = dia > 0 && dia < 32;
    this->dia = (valido) ? dia : 0;
    return valido;
}

bool Data::setMes(int mes) {
    bool valido = verifyMes(mes);
    this->mes = (valido) ? mes : 0;
    return valido;
}

bool Data::setAno(int ano) {
    bool valido = verifyAno(ano);
    this->ano = (valido) ? ano : 0;
    return valido;
}

bool Data::setDate(int dia, int mes, int ano) {
    bool valido = this->setAno(ano);
    valido = this->setMes(mes);
    valido = this->setDia(dia);
    return valido;
}

//GET functions
int Data::getDia() const {
    bool valido = this->dia > 0 && this->dia < 32;
    return (valido) ? this->dia : 0;
}

int Data::getMes() const {
    bool valido = verifyMes(this->mes);
    return (valido) ? this->mes : 0;
}

int Data::getAno() const {
    bool valido = verifyAno(this->ano);
    return (valido) ? this->ano : 0;
}

std::string Data::getMesExt() const {
    int mes = this->getMes();
    std::string meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    if(mes <= 0) mes = 1;
    return meses[mes-1];
}

std::string Data::getData() const {
    std::string dat = std::to_string(this->getDia()) + "/" + std::to_string(this->getMes()) + "/" + std::to_string(this->getAno());
    return dat;
}

std::string Data::getDataExt() const {
    std::string dat = std::to_string(this->getDia()) + " de " + this->getMesExt() + " de " + std::to_string(this->getAno());
    return dat;
}

//VERIFY functions 
bool Data::verifyDate(int dia, int mes, int ano) const {
    bool valido = verifyMes(mes) && verifyAno(ano);
    if(valido) valido = verifyDia(dia, mes, ano);
    return valido;
}

bool Data::verifyDia(int dia, int mes, int ano) const {
    int diasMes[] = {31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};
    bool valido = dia > 0 && dia <= diasMes[mes-1];

    if(!valido) valido = (mes == 2 && dia == 29) && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0));
    return valido;
}

bool Data::verifyMes(int mes) const {
    return (mes > 0 && mes < 13);
}

bool Data::verifyAno(int ano) const {
    return (ano > 0 && ano < 2023);
}

//READ function
void Data::rDate() {
    int d = 0,
        m = 0,
        a = 0;
    char i;
    bool erro = false;

    do {
        fflush(stdin);
        std::cout << "Data aa/bb/cccc: ";
        std::cin >> d >> i >> m >> i >> a;
        erro = !verifyDate(d, m, a);
        if(erro) std::cout << "Data invalida... Digite novamente.\n" << std::endl;
    } while(erro);
    this->setDate(d, m, a);
}

//WRITE functions
void Data::wDate() {
    std::cout << std::setfill('0') << std::setw(2) << this->getDia() << '/' << std::setw(2) << this->getMes() << '/' << this->getAno() << ' ';
}

void Data::wDateExt() {
    std::cout << this->getDia() << " de " << this->getMesExt() << " de " << this->getAno() << ' ';
}

//SEARCH functions
//Boolean
bool Data::compDia(int dia) {
    return this->dia == dia;
}

bool Data::compMes(int mes) {
    return this->mes == mes;
}

bool Data::compAno(int ano) {
    return this->ano == ano;
}
