
#include "rectangle.hh"
#include "../include/matrix.hh"
#include <iostream>
#include <cmath>
#include "../include/size.hh"

// Konstruktor bezparametryczny
Rectangle::Rectangle()
{
    double args1[2] = {4,4}, args2[2] = {2,4}, args3[2] = {2,1}, args4[2] = {4,1};
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

/******************************************************************************
 |  metoda translacji prostokata o zadany wektor                                                |
 |  Argumenty:                                                                    |
 |      t - zadany wektor translacji                                                      |
 |  Zwraca:                                                                       |
 |      prostokat z przesunietymi wierzcholkami o zadany wektor                                        |
 */
Rectangle Rectangle::translation(Vector const &t) const
{
    Rectangle translate;
    translate.v1 = v1 + t;
    translate.v2 = v2 + t;
    translate.v3 = v3 + t;
    translate.v4 = v4 + t;

    return translate;
}

// metoda zapisu danych do pliku
void Rectangle::Writetofile(std:: string filename, int mode)
{
        std::ofstream Dataf;
        if(mode == 1)
        Dataf.open(filename, std::ios::trunc);
        else
        Dataf.open(filename, std::ios::app);

        fclose(stdout);
}

/******************************************************************************
 |  metoda, ktora zwraca wierzcholki prostokata                                                 |
 |  Argumenty:                                                                    |
 |      &v1X, &v2X, &v3X, &v4X                                                    |
 |  Zwraca:                                                                       |
 |      zmienione wartosci wektorow z wejscia                                          |
 */

void Rectangle::new_rectangle(Vector &v1X, Vector &v2X, Vector &v3X, Vector &v4X) const
{
     
}

bool Rectangle::rotate(const double angle, int n) const
{
       if((static_cast <int> (angle) % 360) == 0)
           return false;

       Matrix matrixRotate;
       matrixRotate.MatrixRotate(angle);
       v1 = v1 * matrixRotate;
       v2 = v2 * matrixRotate;
       v3 = v3 * matrixRotate;
       v4 = v4 * matrixRotate;

       return true;   

}

// metoda sprawdzania dlugosci bokow prostokata
bool Rectangle::check_length() const
{
   
}

/******************************************************************************
 |  Przeciazenie operatora <<                                          |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                              |
 |      Rec- prostokat.                                                         |
 */
std::ostream& operator << (std::ostream &out, Rectangle const &Rec)
{
    out << Rec.v1 << std::endl;
    out << Rec.v2 << std::endl;
    out << Rec.v3 << std::endl;
    out << Rec.v4 << std::endl;
    return out;
}

/******************************************************************************
 |  Przeciazenie operatora << dla pliku                                         |
 |  Argumenty:                                                                |
 |      fout - strumien wyjsciowy,                                              |
 |      Rec- prostokat.                                                         |
 */
std::ofstream& operator << (std::ofstream &fout, Rectangle const &Rec)
{
    fout << std::setprecision(10) << std::fixed;
    fout << Rec.v1 << std::endl;
    fout << Rec.v2 << std::endl;
    fout << Rec.v3 << std::endl;
    fout << Rec.v4 << std::endl;
    return fout;
}

