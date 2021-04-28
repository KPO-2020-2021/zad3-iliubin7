
#include "rectangle.hh"
#include "../include/matrix.hh"
#include <iostream>
#include <cmath>
#include "../include/size.hh"

// Konstruktor bezparametryczny
Rectangle::Rectangle()
{
    double args1[2] = {2,3}, args2[2] = {0,3}, args3[2] = {0,1}, args4[2] = {2,1};
    v1 = Vector(args1);
    v2 = Vector(args2);
    v3 = Vector(args3);
    v4 = Vector(args4);
}

/******************************************************************************
 |  Konstruktor klasy Rectangle                                                   |
 |  Argumenty:                                                                    |
 |      v1X, v2X, v3X, v4X - cztery wektory, ktore reprezentuja polozenie wierzcholkow                                                      |
 |  Zwraca:                                                                       |
 |      Macierz wypelniona wartoscia 0.                                           |
 */
Rectangle::Rectangle(Vector const &v1X, Vector const &v2X, Vector const &v3X, Vector const &v4X)
{
    v1 = v1X;
    v2 = v2X;
    v3 = v3X;
    v4 = v4X;
    Rectangle v1;
    v1 = *this;
    if (!v1.check_length()){
           std::cerr << "ERROR: przeciwlegle boki nie sa rowne!" << std::endl;
    }
}

Rectangle Rectangle::translation(Vector const &t) const
{
    Rectangle translate;
    translate.v1 = v1 + t;
    translate.v2 = v2 + t;
    translate.v3 = v3 + t;
    translate.v4 = v4 + t;

    return translate;
}

void Rectangle::Writetofile(std:: string filename, int mode)
{
        std::ofstream Dataf;
        if(mode == 1)
        Dataf.open(filename, std::ios::trunc);
        else
        Dataf.open(filename, std::ios::app);

        fclose(stdout);
}

std::ostream& operator << (std::ostream &out, Rectangle const &Rec)
{
    out << Rec.v1 << std::endl;
    out << Rec.v2 << std::endl;
    out << Rec.v3 << std::endl;
    out << Rec.v4 << std::endl;
    return out;
}

std::ofstream& operator << (std::ofstream &fout, Rectangle const &Rec)
{
    fout << std::setprecision(10) << std::fixed;
    fout << Rec.v1 << std::endl;
    fout << Rec.v2 << std::endl;
    fout << Rec.v3 << std::endl;
    fout << Rec.v4 << std::endl;
    return fout;
}

