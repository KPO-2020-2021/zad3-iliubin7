#include "../tests/doctest/doctest.h"
#include "matrix.hh"

TEST_CASE("test matrix konstruktor parametryczny"){

    double tabm1[SIZE][SIZE] = {{1,3},{2,4}}, tabm2[SIZE][SIZE] = {{1,3}, {2,4}};
    Matrix m1(tabm1);
    Matrix m2(tabm2);
    CHECK(m1 == m2);
}
TEST_CASE("test matrix konstruktor bezparametryczny"){

    double tab3[SIZE][SIZE] = {{0,0}, {0,0}};
    Matrix m1(tab3), m2;
    CHECK(m2 == m1);
}
TEST_CASE("test matrix mnozenie razy wektor (z prawej strony)"){

    double tab1[SIZE] = {1, 3},  tab2[SIZE] = {2, 4}, tabm1[SIZE][SIZE] = {{1,2}, {3,4}}, tabres[SIZE] = {7, 15};
    Matrix m1(tabm1);
    Vector v1(tab1), res(tabres), result;
    result = m1 * v1;
    CHECK(res == result);
}
TEST_CASE("test operatora ()")
{
    double tab1[SIZE] = {1, 3}, tab2[SIZE] = {1, 4}, tab3[SIZE] = {2, 3}, tab4[SIZE] = {2, 4}, tabm1[SIZE][SIZE] = {{1,2}, {3,4}};
    Matrix m1(tabm1);
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4);
    
    CHECK(m1(0,0) == v1);
    CHECK(m1(0,1) == v2);
    CHECK(m1(1,0) == v3);
    CHECK(m1(1,1) == v4);
}
TEST_CASE("test matrix tworzenie macierzy obrotu")
{
    double tabm1[SIZE][SIZE] = {{2, 3}, {1, 4}}, tabm2[SIZE][SIZE] = {{0,-1}, {1, 0}};
    Matrix m1(tabm1), m2(tabm2);
    m1.MatrixRotate(90);
    CHECK(m1 == m2);
}