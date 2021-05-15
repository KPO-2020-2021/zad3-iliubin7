#include "../tests/doctest/doctest.h"
#include "rectangle.hh"

TEST_CASE("test Rectangle konstruktor bezparametryczny i przeciazenie operatorow << >>"){
    Rectangle a;
    Rectangle b;
    std::ostringstream out;
    out << a; 
    std::ostringstream out2;
    out2 << b; 

    CHECK (out.str() == out2.str());
}

TEST_CASE("test Rectangle konstruktor parametryczny i przeciazenie operatorow << >>"){
    double args[NUMBEROFVERTEX][SIZE]= {{100.0, 00.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    Rectangle b(a1);
    std::ostringstream out;
    out << a;
    std::ostringstream out2;
    out2 << b; 

    CHECK (out.str() == out2.str());
}

TEST_CASE("test konstruktor parametryczny prostokata i przeciazenie operatorow << >>"){
    double args[NUMBEROFVERTEX][SIZE]= {{200.0, 300.0},{300.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a1[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    Rectangle b(a1);
    std::ostringstream out;
    out << a; 
    std::ostringstream out2;
    out2 << b; 

    CHECK (out.str() == out2.str());
}

TEST_CASE("test translacja prostokata o wektor"){
    double args[NUMBEROFVERTEX][SIZE]= {{0.0, 300.0},{0.0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a1[NUMBEROFVERTEX];        
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[NUMBEROFVERTEX][SIZE]= {{100.0, 400.0},{100.0, 300.0},{300.0, 300.0},{300.0, 400.0}};
       Vector a2[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double tab[SIZE] = {100,100};
    Vector trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("test translacja o wektor z ujemnymi wspolrzednymi 1"){
    double args[NUMBEROFVERTEX][SIZE]= {{0.0, 300.0},{0.0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a1[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[NUMBEROFVERTEX][SIZE]= {{-100.0, 200.0},{-100.0, 100.0},{100.0, 100.0},{100.0, 200.0}};
       Vector a2[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double tab[SIZE] = {-100,-100};
    Vector trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("test translacja o wektor z ujemnymi wspolrzednymi 2"){
    double args[NUMBEROFVERTEX][SIZE]= {{0.0, 300.0},{0.0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a1[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[NUMBEROFVERTEX][SIZE]= {{-100.0, 25.0},{-100.0, 150.0},{100.0, 150.0},{100.0, 250.0}};
       Vector a2[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double tab[SIZE] = {-100,-50};
    Vector trans(tab);

    CHECK (a.translation(trans) == b);
}

TEST_CASE("test rotacja prostokata o 180 stponi"){
    double args[NUMBEROFVERTEX][SIZE]= {{0.0, 300.0},{0.0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a1[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[NUMBEROFVERTEX][SIZE]= {{0.0, -300.0},{0.0, -200.0},{-200.0, -200.0},{-200.0, -300.0}};
       Vector a2[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double ang = 180;


    CHECK (a.rotate(ang) == b);
}

TEST_CASE("test rotacja prostokata o 360 stopni"){
    double args[NUMBEROFVERTEX][SIZE]= {{0.0, 300.0},{0.0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a1[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a1[i]=Vector(args[i]);
       } 
    Rectangle a(a1);
    double args2[NUMBEROFVERTEX][SIZE]= {{0.0, 300.0},{0.0, 200.0},{200.0, 200.0},{200.0, 300.0}};
       Vector a2[NUMBEROFVERTEX];
       for (int i=0;i<NUMBEROFVERTEX;i++){
              a2[i]=Vector(args2[i]);
       } 
       Rectangle b(a2);
    double ang = 360;


    CHECK (a.rotate(ang) == b);
}