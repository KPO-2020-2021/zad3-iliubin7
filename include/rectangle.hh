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

   Rectangle translation(Vector const &t) const;

   Rectangle rotate(const double &angle) const; 

   void new_rectangle(Vector &v1X, Vector &v2x, Vector &v3X, Vector &v4X) const;  

   bool check_length() const;   // metoda sprawdzania dlugosci bokow prostokata

   bool check_angle() const;     

   void Rectangle::Writetofile(std:: string filename, int mode); 

};

std::ostream &operator << (std::ostream &out, Rectangle const &Rec);

std::ofstream &operator << (std::ofstream &fout, Rectangle const &Rec); 


