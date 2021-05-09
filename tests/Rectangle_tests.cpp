#include "../tests/doctest/doctest.h"
#include "rectangle.hh"

TEST_CASE("test rectangle konstruktor parametryczny")
{
    double tab1[SIZE] = {5, 1}, tab2[SIZE] = {7,1}, tab3[SIZE] = {7, 3}, tab4[SIZE] = {5,3}, tabn1[SIZE] = {5, 1}, tabn2[SIZE] = {7,1}, tabn3[SIZE] = {7, 3}, tabn4[SIZE] = {5,3};
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4), vn1(tabn1), vn2(tabn2), vn3(tabn3), vn4(tabn4);
    Rectangle n1(vn1, vn2, vn3, vn4);
    CHECK( n1 == (v1, v2, v3, v4));
}
TEST_CASE("test rectangle konstruktor bezparametryczny")
{
    double tab1[SIZE] = {2,1}, tab2[SIZE] = {5,1}, tab3[SIZE] = {5,4}, tab4[SIZE] = {2,4};
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4);
    Rectangle n1, n2(v1, v2, v3, v4);
    CHECK(n1 == n2);
}
TEST_CASE("test rectangle translacja o wektor")
{
    double tab1[SIZE] = {5, 1}, tab2[SIZE] = {7,1}, tab3[SIZE] = {7, 3}, tab4[SIZE] = {5,3}, tabn1[SIZE] = {6, 2}, tabn2[SIZE] = {8,2}, tabn3[SIZE] = {8, 4}, tabn4[SIZE] = {6,4}, tabtranslate[SIZE] = {1,1};
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4), vn1(tabn1), vn2(tabn2), vn3(tabn3), vn4(tabn4), t(tabtranslate);
    Rectangle n1(v1, v2, v3, v4), n2(vn1, vn2, vn3, vn4);
    n1.translation(t);
    CHECK(n1 == n2);
}
TEST_CASE("test rectangle rotacja wokol srodka ukladu wspolrzednych, kat = 180")
{
    double tab1[SIZE] = {5, 1}, tab2[SIZE] = {7,1}, tab3[SIZE] = {7, 3}, tab4[SIZE] = {5,3}, tabr1[SIZE] = {5, 1}, tabr2[SIZE] = {7,1}, tabr3[SIZE] = {7, 3}, tabr4[SIZE] = {5,3};
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4), vr1(tabr1), vr2(tabr2), vr3(tabr3), vr4(tabr4);
    Rectangle n1(v1, v2, v3, v4), n2(tabr1, tabr2, tabr3, tabr4);
    n1.rotate(180, 2);
    CHECK(n1 == n2);
}
TEST_CASE("test rectangle rotacja wokol srodka ukladu wspolrzednych, kat = 30")
{
    double tab1[SIZE] = {5, 1}, tab2[SIZE] = {5,3}, tab3[SIZE] = {7, 3}, tab4[SIZE] = {7,1}, tabr1[SIZE] = {4.045544905932738, -1.792893218813452}, tabr2[SIZE] = {5.4497747468305833, -2.792893218813452}, tabr3[SIZE] = {6.4497747468305833, -1.378679656440357}, tabr4[SIZE] = {5.035533905932738, -0.378679656440357};
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4), vr1(tabr1), vr2(tabr2), vr3(tabr3), vr4(tabr4);
    Rectangle n1(v1, v2, v3, v4), n2(vr1, vr2, vr3, vr4);
    n1.rotate(30, 3);
    CHECK(n1 == n2);
}
TEST_CASE("test rectangle sprawdzanie dlugosci bokow")
{
    double tab1[SIZE] = {4,1}, tab2[SIZE] = {7,1}, tab3[SIZE] = {7,3}, tab4[SIZE] = {4,3};
    Vector v1(tab1), v2(tab2), v3(tab3), v4(tab4);
    Rectangle n1(v1, v2, v3, v4);
    CHECK(n1.check_length() == true);
}