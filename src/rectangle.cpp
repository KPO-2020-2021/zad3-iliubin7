
#include "../include/rectangle.hh"
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
     v1 = v1X;
     v2 = v2X;
     v3 = v3X;
     v4 = v4X;
}

/******************************************************************************
 |  metoda rotacji prostokata                                                 |
 |  Argumenty:                                                                    |
 |      angle - kat obrotu, 
        n - ilosc                                                   |
 |  Zwraca:                                                                       |
 |      zmienione wartosci wektorow z wejscia                                          |
 */
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
   double length[4];
   length[0] = v2[0] - v1[0];
   length[1] = v3[0] - v4[0];
   
   length[2] = v4[1] - v1[1];
   length[3] = v3[1] - v2[1];
   if(length[0] < length[1])
   {
       // Boki length[0] i length[1] sa dluzsze, a boki length[2] i length[3] sa krotsze
     if(length[0] == length[1])
      std::cout << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
      else
      std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
    // wyswietlanie dlugosci dluzszych bokow
    std::cout << "Dlugosc pierwszego boku:" << std::fixed << std::setprecision(20) << length[0] << std::endl;
    std::cout << "Dlugosc drugiego boku:" << std::fixed << std::setprecision(20) << length[1] << std::endl;
    if(length[2] == length[3])
    std::cout << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
    else
    std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
    // wyswietlanie dlugosci krotszych bokow
    std::cout << "Dlugosc pierwszego boku:" << std::fixed << std::setprecision(20) << length[2] << std::endl;
    std::cout << "Dlugosc drugiego boku:" << std::fixed << std::setprecision(20) << length[3] << std::endl;
    }
    else
    {
        // Boki length[0] i length[1] sa krotsze, a boki length[2] i length[3] sa dluzsze
        if(length[2] == length[3])
        std::cout << "Dluzsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
        std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        // wyswietlanie dlugosci bokow
        std::cout << "Dlugosc pierwszego boku:" << std::fixed << std::setprecision(20) << length[2] << std::endl;
        std::cout << "Dlugosc drugiego boku:" << std::fixed << std::setprecision(20) << length[3] << std::endl;
        if(length[0] == length[1])
        std::cout << "Krotsze przeciwlegle boki sa sobie rowne." << std::endl;
        else
        std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        // wyswietlanie dlugosci krotszych bokow
        std::cout << "Dlugosc pierwszego boku:" << std::fixed << std::setprecision(20) << length[0] << std::endl;
        std::cout << "Dlugosc drugiego boku:" << std::fixed << std::setprecision(20) << length[1] << std::endl;
    }
    
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
 |      Rec - prostokat.                                                         |
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

