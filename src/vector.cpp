
#include "matrix.hh"
#include "vector.hh"
#include "size.hh"


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
}

// Destruktor klasy
Vector::~Vector(){}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Vector Vector::operator + (const Vector &v) const{
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator-(const Vector &v) const
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] - v[i];
    }
    return result;
}



/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

Vector Vector::operator * (const double &tmp) const {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] * tmp;
    }
    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Vector::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator << (std::ostream &out, Vector const &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator >> (std::istream &in, Vector &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
/******************************************************************************
 |  Metoda do znajdowania kwadrata dlugosci wektora                                              |
 |  Argumenty:                                                                |
 |      brak                                              |
 |  Zwraca:
        dlugosc wektora                                                     |
 */
double Vector::modul2() const
{
   double result;
   for (int i = 0; i < SIZE; i++)
    {
        result += pow(size[i], 2);
    }
    return result;      
}

/******************************************************************************
 * Zwraca dlugosc wektora                                                    
 * Argumenty:                                                                
 *      Brak                                                                 
 * Zwraca:                                                                   
 *      \param[out] length - dlugosc wektora                                                      
 */
double Vector::get_length() const
{
    double len, mod2;
    Vector tmp;
    tmp = *this;
    mod2 = tmp.modul2();
    len = pow(mod2, 1.0 / SIZE);

    return len;
}

/******************************************************************************
 |  Metoda rotacji wektora                                               |
 |  Argumenty:                                                                |
 |      angle - kat obrotu (podany w stopniach),                                              |
 |  Zwraca:
        obrocony wektor                                                       |
 */
Vector Vector::rotation(const double &angle) const
{
    Vector rotated;
    double angle_radian = angle * M_PI / 180;
    if(SIZE == 2)
    {
        double tmp[][SIZE] = {{cos(angle_radian), -sin(angle_radian)}, {sin(angle_radian), cos(angle_radian)}};
        Matrix transformation(tmp);
        rotated = transformation * *this;
    }
    else
    {
      std::cerr << "ERROR: Nie zdefiniowano macierzy obrotu dla przestrzeni innej niz dwuwymiarowa." << std::endl;
    }
    return rotated;
}

/******************************************************************************
 |  Przeciazenie operatora ==                                                |
 |  Argumenty:                                                                |
 |      v - drugi skladnik porownania
    Zwraca:
    wartosc 1 gdy skladniki pierwszego wektora sa mniejsze niz skladniki drugiego,
    a w przypadku przeciwnym zwraca wartosc 0                                                         |
 */

bool Vector::operator == (const Vector &v) const
{
     for (int i=0;i<SIZE;i++){
        if ((abs(size[i] - v.size[i]) <= MIN_DIFF))
            return true;
    }
    return false;
}