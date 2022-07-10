
#include "../header/Menu.hpp"
#include <iomanip>

//CONSTRUCTOR & DESTRUCTOR
Menu::Menu(int minimum, int maximum, std::string information) {
    this->setOpt(0);
    this->setMin(minimum);
    this->setMax(maximum);
    this->setInfo(information);
}

Menu::~Menu() {
    std::cout << "\n\t=> Memoria do Menu Liberada." << std::endl;
}

//SET
void Menu::setOpt(int op) {
    this->op = op;
}

void Menu::setInfo(std::string information) {
    this->info = information;
}

void Menu::setMin(int min) {
    this->min = min;
}

void Menu::setMax(int max) {
    this->max = max;
}

//GET
int Menu::getOpt() const {
    return this->op;
}

std::string Menu::getInfo() const {
    return this->info;
}

int Menu::getMin() const {
    return this->min;
} 

int Menu::getMax() const {
    return this->max;
}

//READ
void Menu::rOpt() {
    int a = -1;
    std::string b;
    bool erro;

    fflush(stdin);
    std::cout << "? ";
    std::cin >> b;

    a = std::stoi(b);
    erro = a < this->getMin() || a > this->getMax();
    if(erro) throw std::runtime_error("Erro: Valor acima ou abaixo do permitido");

    this->setOpt(a);
}

//INTERFACE
void Menu::wInterface() {
    std::cout << this->getInfo() << std::endl;

    bool erro;
    do {
        try {
            this->rOpt();
            erro = false;
        } catch(std::runtime_error e) {
            std::cout << "Opcao invalida... Digite novamente.\n" << e.what() << "\n" << std::endl;
            erro = true;
        } catch(...) {
            std::cout << "Opcao invalida... Digite novamente.\n" << "Erro: Conversao string to integer\n" << std::endl;
            erro = true;
        }
    } while(erro);
}
