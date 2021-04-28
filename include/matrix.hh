#pragma once

#include <cmath>
#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>

class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector operator * (Vector tmp);           // Przeciazenie operatora mnożenia macierzy razy wektor

    Matrix operator + (Matrix tmp);           // Przeciazenie operatora dodawania macierzy

    double  &operator () (unsigned int row, unsigned int column); // Przeciazenie operatora funkcyjnego do zmieniania wartosci macierzy
    
    const double &operator () (unsigned int row, unsigned int column) const; // Przeciazenie operatora funkcyjnego do pobierania wartosci macierzy

    void MatrixRotate(double angle);  // metoda generujaca macierz obrotu o zadany kat
    
    bool operator == (const Matrix &matrix) const;  // przeciazenie operatora == porownywania wartosci macierzy
    
    bool operator != (const Matrix &matrix) const;  // przeciazenie operatora != porownywania wartosci macierzy
};

std::istream &operator >> (std::istream &in, Matrix &mat); // Przeciazenie operatora wpisywania wartosci macierzy

std::ostream &operator << (std::ostream &out, Matrix const &mat);  // Przeciazenie operatora wypisywania wartosci macierzy

