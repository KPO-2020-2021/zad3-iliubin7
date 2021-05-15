#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>
#include <cmath>
#define MIN_DIFF 0.000001

class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();            // Konstruktor klasy

    Vector(double [SIZE]);           // Konstruktor klasy

    ~Vector();                   // Destruktor klasy

    Vector operator + (const Vector &v) const;   // Przeciazenie operatora +

    Vector operator - (const Vector &v) const;   // Przeciazenie operatora -

    Vector operator * (const double &tmp) const;  // Przeciazenie operatora *

    Vector rotation(const double &angle) const; 

    double modul2() const;  // metoda do znajdowania kwadrata dlugosci wektora

    double get_length() const;    // metoda do znajdowania dlugosci wektora
      
    bool operator == (const Vector &v) const;  // Przeciazenie operatora ==

    const double &operator [] (int index) const;   

    double &operator [] (int index);               

};

std::ostream &operator << (std::ostream &out, Vector const &tmp); 

std::istream &operator >> (std::istream &in, Vector &tmp);    
