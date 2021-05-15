#pragma once

#include"rectangle.hh"
#include <iostream>

// definicja klasy menu
class menu{

    private:

    bool open;

    public:
    
    menu();

    void init_menu(Vector const (&tab)[4]);

    void show();

    void switch_menu(const char &oper,Rectangle &rec);

};