
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Menu {
    private:
        int op;
        std::string info;
        int min;
        int max;

        //READ
        void rOpt(); //utilitary function
    
    public:
    //CONSTRUCTOR & DESTRUCTOR
        Menu(int minimum = 0, int maximum = 0, std::string information = "");
        ~Menu();

    //SET
        void setOpt(int op);
        void setInfo(std::string info);
        void setMin(int min);
        void setMax(int max);

    //GET
        int getOpt() const;
        std::string getInfo() const;
        int getMin() const;
        int getMax() const;

    //INTERFACE
        void wInterface();

};

#endif
