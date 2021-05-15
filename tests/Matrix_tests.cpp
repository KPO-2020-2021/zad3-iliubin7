#include "../tests/doctest/doctest.h"
#include "matrix.hh"

TEST_CASE("test Matrix konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[SIZE][SIZE] = {{-0.0003,0.0001},{0.0003,-0.0001}};
    Matrix a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| -0.0003000000 * | 0.0001000000 * | 0.0003000000 * | -0.0001000000 * ");
}
TEST_CASE("test Matrix konstruktor bezparametryczny i przeciazenie operatorow << >>"){
    //double tab[2][2] = {{3,1}};
    Matrix a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * ");
}
TEST_CASE("test Matrix operator ()"){
    double tab[SIZE][SIZE] = {{1,0.00002},{3,4}};
    double res = 0.00002;

    Matrix a(tab);

    CHECK (res == a(0,1));
}
TEST_CASE("test operator + 0"){
    double tab[SIZE][SIZE] = {{1,2},{3,4}};
    double tab2[SIZE][SIZE] = {{0,0},{0,0}};
    double res[SIZE][SIZE] = {{1,2},{3,4}};

    Matrix a(tab);
    Matrix b(tab2);

    Matrix c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test operator + "){
    double tab[SIZE][SIZE] = {{3,1},{2,5}};
    double tab2[SIZE][SIZE] = {{0.0000000001,0.0000000001},{0.0000000001,0.0000000001}};
    double res[SIZE][SIZE] = {{3.0000000001,1.0000000001},{2.0000000001,5.0000000001}};

    Matrix a(tab);
    Matrix b(tab2);

    Matrix c(res);

    CHECK (c==(a+b));
}
TEST_CASE("test Matrix gauss() 1"){
    double tab[SIZE][SIZE] = {{1,2},{3,4}};
    double tab2[SIZE][SIZE] = {{1,2},{0,-2}};
    Matrix a(tab);
    Matrix b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("test Matrix gauss() 2"){
    double tab[SIZE][SIZE] = {{3,2},{3,4}};
    double tab2[SIZE][SIZE] = {{3,2},{0,2}};
    Matrix a(tab);
    Matrix b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("test Matrix wyznacznik() 1"){
    double tab[SIZE][SIZE] = {{3,2},{3,4}};
    Matrix a(tab);
    double det; 
    det = 6;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("test Matrix wyznacznik() 2"){
    double tab[SIZE][SIZE] = {{1,2},{3,4}};
    Matrix a(tab);
    double det; 
    det = -2;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("test Matrix mnozenie dwoch macierzy() 1"){
    double tab[SIZE][SIZE] = {{-1,0},{12,4}};
    double tab2[SIZE][SIZE] = {{12,7},{1,5}};
    Matrix a(tab);  //macierz jednostkowa
    Matrix b(tab2);
    double tab_res[SIZE][SIZE] = {{-12,-7},{148,104}};
    Matrix res(tab_res);
    CHECK (a.multiply(b) == res);
}

TEST_CASE("test Matrix mnozenie dwoch macierzy 2"){
    double tab[SIZE][SIZE] = {{3,2},{3,4}};
    Matrix a(tab);  //macierz jednostkowa
    Matrix b;
    double tab_res[SIZE][SIZE] = {{3,2},{3,4}};
    Matrix res(tab_res);
    CHECK (a.multiply(b) == res);
}

TEST_CASE("test Matrix mnozenie dwoch macierzy 3"){
    double tab[SIZE][SIZE] = {{1,2},{3,4}};
    Matrix a(tab);  //macierz jednostkowa
    Matrix b(tab);
    double tab_res[SIZE][SIZE] = {{7,10},{15,22}};
    Matrix res(tab_res);
    CHECK (a.multiply(b) == res);
}

