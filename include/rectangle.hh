#pragma once 

#include "vector.hh"
#include "size.hh"
#include "matrix.hh"
#include <fstream>
#include <iostream>

class Rectangle{

    Vector v1, v2, v3, v4; // wierzcholki prostokata

public:
   
   Rectangle();    // Konstruktor klasy

   Rectangle(Vector const &v1X, Vector const &v2X, Vector const &v3X, Vector const &v4X);      // Konstruktor klasy

   Rectangle translation(Vector const &t) const;   // metoda translacji prostokata o zadany wektor

   bool rotate(const double angle, int n) const;     // metoda rotacji prostokata

   void new_rectangle(Vector &v1X, Vector &v2X, Vector &v3X, Vector &v4X) const;  // metoda do generowania nowego prostokata

   bool check_length() const;   // metoda sprawdzania dlugosci przeciwleglych bokow prostokata

   bool check_angle() const;     

   void Writetofile(std:: string filename, int mode); // metoda zapisu danych do pliku

};

std::ostream &operator << (std::ostream &out, Rectangle const &Rec);  // Przeciazenie operatora wpisywania 

std::ofstream &operator << (std::ofstream &fout, Rectangle const &Rec); // Przeciazenie operatora wypisywania 


