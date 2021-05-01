#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>
#include "matrix.hh"
#define MIN_DIFF 0.0000000001

class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();            // Konstruktor klasy

    Vector(double [SIZE]);           // Konstruktor klasy

    Vector operator + (const Vector &v);   // Przeciazenie operatora +

    Vector operator - (const Vector &v);   // Przeciazenie operatora -

    Vector operator * (const double &tmp);  // Przeciazenie operatora *

    Vector rotation(const double &angle) const; 

    double modul() const;  // metoda do znajdowania dlugosci wektora

    double get_length() const;

    double kat_obrotu() const;
      
    bool operator == (const Vector v) const;  // Przeciazenie operatora ==

    const double &operator [] (int index) const;   

    double &operator [] (int index);               

};

std::ostream &operator << (std::ostream &out, Vector const &tmp); 

std::istream &operator >> (std::istream &in, Vector &tmp);    
