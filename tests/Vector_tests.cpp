#include "../tests/doctest/doctest.h"
#include "vector.hh"

TEST_CASE("test vector konstruktor parametryczny"){

    Vector x, y;
    double tab1[2] = {3, 3}, tab2[2] = {3,3};
    x = Vector(tab1);
    y = Vector(tab2);
    CHECK(x == y);
}

TEST_CASE("test vector konstruktor bezparametryczny"){
    
    double tab1[2]= {0, 0};
    Vector x, y = tab1;
    CHECK(x == y);

}
TEST_CASE("test Vector suma")
{
    Vector x, y, sum;
    double tab1[2] = {1, 2}, tab2[2] = {4,0} , tab3[2] = {5, 2};
    x = Vector(tab1);
    y = Vector(tab2);
    sum = Vector(tab3);
    CHECK((x+y) == sum);
}
TEST_CASE("test Vector roznica")
{
    Vector x, y, res;
    double tab1[2] = {4, 2}, tab2[2] = {3,3} , tab3[2] = {1, -1};
    x = Vector(tab1);
    y = Vector(tab2);
    res = Vector(tab3);
    CHECK( (x-y) == res);

}
TEST_CASE("test wyswietlanie vector standard")
{
    Vector x;
    double tab1[2] = {7, 3};
    x = Vector(tab1);
    std::ostringstream out;
    out << x;
    std:: cout << out.str();
    CHECK("7, 3" == out.str());
}
TEST_CASE("test == 10 miejsc po przecinku")
{
   Vector x, y;
   double tab1[2] = {1.0000000009, 2.0000000007}, tab2[2] = {1.0000000009, 2.0000000007};
   x = Vector(tab1);
   y = Vector(tab2);
   CHECK(x == y);
}
TEST_CASE("test == 20 miejsc po przecinku")
{
   Vector x, y;
   double tab1[2] = {1.00000000000000000009, 2.00000000000000000007}, tab2[2] = {1.00000000000000000009, 2.00000000000000000007};
   x = Vector(tab1);
   y = Vector(tab2);
   CHECK(x == y);
}
TEST_CASE("test wczytywanie vector standard")
{
    Vector x;
    double tab1[2] = {7, 3};
    x = Vector(tab1);
    std::istringstream in;
    in >> x;
    std:: cout << in.str();
    CHECK("7, 3" == in.str());
}
TEST_CASE("test operatora []")
{
    Vector x, y, z;
    double tab1[2] = {6, 7}, tab2[2] = {8, 9}, tab3[2] = {21, 199};
    x = Vector(tab1);
    y = Vector(tab2);
    z = Vector(tab3);
    double a, b, c, d, e, f;
    a = 6;
    b = 7;
    c = 8;
    d = 9;
    e = 21;
    f = 199;
    
    CHECK(a == x[0]);
    CHECK(b == x[1]);
    CHECK(c == y[0]);
    CHECK(d == y[1]);
    CHECK(e == z[0]);
    CHECK(f == z[1]);
}
/*
TEST_CASE("test mnozenie vector razy macierz 1")
{
       Vector x, wynik;
       double tab1[2] = {0, 2}, tab2[2] = {-2, 0};
       Matrix rotate = Matrix();
       rotate.przypisz_Stopnie(45);
       rotate.StopienNaRadian();
       rotate.Oblicz_tablice();
       x = Vector(tab1);
       x = rotate * x;
       wynik = Vector(tab2);
       CHECK(wynik == x);
}
TEST_CASE("test mnozenie vector razy macierz 1")
{
       Vector x, wynik;
       double tab1[2] = {0, 2}, tab2[2] = {-2, 0};
       Matrix rotate = Matrix();
       rotate.przypisz_Stopnie(90);
       rotate.StopienNaRadian();
       rotate.Oblicz_tablice();
       x = Vector(tab1);
       x = rotate * x;
       wynik = Vector(tab2);
       CHECK(wynik == x);
}
TEST_CASE("test mnozenie vector 1")
{
    Vector x, result;
    double tab1[2] = {6, 9}, mnozenie = 3;
    x = Vector(tab1);
    result= x * mnozenie;
    CHECK(result[0] == 18);
    CHECK(result[0] == 27);
}
TEST(TestVector, testCompare){
    Vector a(3,0);
    Vector b(4.000000009, 4.000000001);
    EXPECT_TRUE (a==b);
}

TEST(TestVector, testCompare){
    Vector a(3,0);
    double x = a[0];
    EXPECT_EQ (v, 3);

    double y = a(1);
    EXPECT_EQ (y,4);

    EXPECT_THROW (double z = a[2], std::invalid_argument);
}

TEST(TestVector, testPrint){
    Vector a(1,4);
    std::stringstream g;
    g << a;
    EXPECT_EQ ("[1; 4]", g.str());
}

TEST(TestVector, testPrint){
    Vector a(
} */