
#include "../header/Database.hpp"

int main() {
    system("cls || clear");
    Database* iniciar = new Database();
    iniciar->menuPrincipal();

    delete iniciar;
    std::cout << "Finalizado\n" << std::endl;
    return 0;
}   
