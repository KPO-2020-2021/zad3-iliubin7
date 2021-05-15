#pragma once 

#include "vector.hh"
#include "size.hh"
#include "matrix.hh"
#include "lacze_do_gnuplota.hh"
#include <fstream>
#include <iostream>
#include <iomanip>

class Rectangle{

    Vector v[NUMBEROFVERTEX];  // lista wierzcholkow prostokata

public:
   
   Rectangle();    // Konstruktor klasy

   Rectangle(Vector const (&ar)[NUMBEROFVERTEX]);      // Konstruktor klasy

   ~Rectangle();                                        // Destruktor klasy

   Rectangle translation(Vector const &t) const;   // metoda translacji prostokata o zadany wektor (z zadanym "na sztywno" wektorem)

   Rectangle rotate(const double &angle) const;     // metoda rotacji prostokata (z zadanym "na sztywno" katem)

   Rectangle translation() const;  // metoda translacji prostokata (wektor podaje uzytkownik)

   Rectangle rotate() const;   // metoda rotacji prostokata (kat podaje uzytkownik)

   void new_rectangle(Vector const (&ar)[NUMBEROFVERTEX]) const;  // metoda zwracajaca prostokat

   bool check_length(Vector const (&vx)[NUMBEROFVERTEX]) const; // metoda sprawdzania dlugosci przeciwleglych bokow prostokata

   Rectangle numberofrotation();  // metoda obracajaca prostokat n razy   

   bool Writetofile(std:: string filename); // metoda zapisu danych do pliku
   
   bool operator == (const Rectangle &Rec) const;
   
   void PrintRectangle();      
    
};
std::ostream &operator << (std::ostream &out, Rectangle const &Rec);  // Przeciazenie operatora wpisywania 

 std::ofstream &operator << (std::ofstream &fout, Rectangle const &Rec); // Przeciazenie operatora wypisywania 





