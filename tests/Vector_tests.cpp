#include "../tests/doctest/doctest.h"
#include "vector.hh"

TEST_CASE("test vector konstruktor parametryczny"){

    Vector x, y;
    double tab1[SIZE] = {3, 3}, tab2[SIZE] = {3,3};
    x = Vector(tab1);
    y = Vector(tab2);
    CHECK(x == y);
}

TEST_CASE("test vector konstruktor bezparametryczny"){
    
    double tab1[SIZE]= {0, 0};
    Vector x, y = tab1;
    CHECK(x == y);

}
TEST_CASE("test Vector suma")
{
    Vector x, y, sum;
    double tab1[SIZE] = {1, 2}, tab2[SIZE] = {4,0} , tab3[SIZE] = {5, 2};
    x = Vector(tab1);
    y = Vector(tab2);
    sum = Vector(tab3);
    CHECK((x+y) == sum);
}
TEST_CASE("test Vector roznica")
{
    Vector x, y, res;
    double tab1[SIZE] = {4, 2}, tab2[SIZE] = {3,3} , tab3[SIZE] = {1, -1};
    x = Vector(tab1);
    y = Vector(tab2);
    res = Vector(tab3);
    CHECK( (x-y) == res);

}
TEST_CASE("test wyswietlanie vector standard")
{
    Vector x;
    double tab1[SIZE] = {7, 3};
    x = Vector(tab1);
    std::ostringstream out;
    out << x;
    std:: cout << out.str();
    CHECK("7, 3" == out.str());
}
TEST_CASE("test == 10 miejsc po przecinku")
{
   Vector x, y;
   double tab1[SIZE] = {1.0000000009, 2.0000000007}, tab2[SIZE] = {1.0000000009, 2.0000000007};
   x = Vector(tab1);
   y = Vector(tab2);
   CHECK(x == y);
}
TEST_CASE("test == 20 miejsc po przecinku")
{
   Vector x, y;
   double tab1[SIZE] = {1.00000000000000000009, 2.00000000000000000007}, tab2[SIZE] = {1.00000000000000000009, 2.00000000000000000007};
   x = Vector(tab1);
   y = Vector(tab2);
   CHECK(x == y);
}
TEST_CASE("test wczytywanie vector standard")
{
    Vector x;
    double tab1[SIZE] = {7, 3};
    x = Vector(tab1);
    std::istringstream in;
    in >> x;
    std:: cout << in.str();
    CHECK("7, 3" == in.str());
}
TEST_CASE("test operatora []")
{
    Vector x, y, z;
    double tab1[SIZE] = {6, 7}, tab2[SIZE] = {8, 9}, tab3[SIZE] = {21, 199};
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