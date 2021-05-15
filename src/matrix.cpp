#include <cmath>
#include <iostream>
#include "matrix.hh"
#include "vector.hh"

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}

// Destruktor klasy
Matrix::~Matrix(){}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}
/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - suma dwóch podanych macierzy.                  |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/* 
  Metoda generujaca macierz obrotu
  Argumenty:
      angle - podany kat (w stopniach)
  Zwraca:
     Macierz obrotu, czyli macierz wypelniona wartosciami cos i sin podanego kata przeksztalconego w radiany

void Matrix::MatrixRotate(double angle)
{
    if(SIZE != 2)
    std::cout << ("niewlasciwy rozmiar macierzy!");
    else
    {
    double angle_radian = angle * M_PI / 180;

    value[0][0] = cos(angle_radian);
    value[1][0] = -sin(angle_radian);
    value[0][1]= sin(angle_radian);
    value[1][1] = cos(angle_radian);
    }
} */

/******************************************************************************
 *  Przeciążenie == macierzy                                                         
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktora porownujemy                   
 *      \param[in] tmp - macierz, z ktora porownujemy                                                          
 *  Zwraca:                                                                  
 *      \retval true - jesli sa rowne
 *      \retval false - jesli nie sa                
 */
bool Matrix::operator == (Matrix const &tmp) const{
    int i,j;
    for (i=0;i<SIZE;++i){
        for (j=0;j<SIZE;++j){
            if (abs(value[i][j]-tmp.value[i][j])<=0.000001)
                return true;
        }
    }
    return false;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator >> (std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator << (std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
/******************************************************************************
 *  Zwraca wynik mnozenia dwoch macierzy                                                      
 *  Argumenty:                                                               
 *      \param[in] this - macierz 1 (L)
 *      \param mat - macierz 2 (P)                                                             
 *  Zwraca:                                                                  
 *      \param[out] res - wynik mnozenia macierzy               
 */
Matrix Matrix::multiply(Matrix const &mat) const{
    int i,j,k;
    Matrix res;
    for (i=0; i<SIZE; i++){
        res.value[i][i] = 0;    //zerowanie elementow macierzy ktore sa rowne 1 
                                //(z konstruktora bezparametrycznego)
    }
    for (i=0; i< SIZE; ++i){
        for (j=0; j< SIZE; ++j){
            for (k=0;k<SIZE;k++){
                res.value[i][j]+= value[i][k] * mat.value[k][j];
            }
        }
    }
    return res;
}
/******************************************************************************
 *  Zwraca macierz schodkowa utworzona przez eliminacje gaussa                                                        
 *  Argumenty:                                                               
 *      \param[in] this - macierz dla ktorej chcemy przeprowadzic operacje                                                           
 *  Zwraca:                                                                  
 *      \param[out] mat - macierz schodkowa              
 */
Matrix Matrix::gauss() const{
    Matrix mat = *this;

    double ratio;
    for (int i=0;i<SIZE-1;i++){
        if (value[i][i] == 0)
            return 0;
        for (int j=i+1; j<SIZE; j++){
            ratio = value[j][i] / value[i][i];
            for (int k=0; k<SIZE; k++){
                mat.value[j][k] = (value[j][k] - ratio*value[i][k]);
            }
        }
    }
    return mat;
}
/******************************************************************************
 *  Zwraca wyznacznik macierzy                                                       
 *  Argumenty:                                                               
 *      \param[in] this - macierz, ktorej wyznacznik liczymy                                                             
 *  Zwraca:                                                                  
 *      \param[out] det - wyznacznik               
 */
double Matrix::determinant() const{
    double det;
    Matrix tmp = this->gauss();
    det = 1;
    for (int i=0;i<SIZE;++i){
        det*=tmp.value[i][i];
    }
    return det;
}


