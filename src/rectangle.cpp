
#include "../include/rectangle.hh"

// Konstruktor bezparametryczny
Rectangle::Rectangle()
{
    double r[SIZE];
    int i;
    r[0]=1.0;
    r[1]=1.0;
    for (i=2;i<SIZE;++i)
        r[i]=0.0;
    v[0] = Vector(r);
    r[1]=-1.0; 
    v[1]=Vector(r);
    r[0]=-1.0;
    v[2]=Vector(r);
    r[1]=1.0; 
    v[3]=Vector(r);
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Rectangle                                                   |
 |  Argumenty:                                                                    |
 |      ar[NUMBEROFVERTEX] - tablica wektorow reprezentujacych polozenie wierzcholkow                                                    |
 |  Zwraca:                                                                       |
 |      Cztery wierzcholki prostokata opisane przez podane wektory                                           |
 */
Rectangle::Rectangle(Vector const (&ar)[NUMBEROFVERTEX])
{
    for (int i=0;i<NUMBEROFVERTEX; ++i){
        v[i]=ar[i];
    }
}

//Destruktor prostokata
Rectangle::~Rectangle(){}

/******************************************************************************
 |  metoda translacji prostokata o zadany wektor                                                |
 |  Argumenty:                                                                    |
 |      t - zadany wektor translacji                                                      |
 |  Zwraca:                                                                       |
 |      prostokat z przesunietymi wierzcholkami o zadany wektor                                        |
 */
Rectangle Rectangle::translation(Vector const &t) const
{
    Rectangle translated;
    int i;
    for (i=0;i<NUMBEROFVERTEX;++i){
        translated.v[i] = v[i] + t;
    }

    return translated;
}
/******************************************************************************
 |  metoda translacji prostokata o zadany wektor                                                |
 |  Argumenty:                                                                    |
 |      brak                                                      |
 |  Zwraca:                                                                       |
 |      prostokat z przesunietymi wierzcholkami o zadany wektor                                        |
 */
Rectangle Rectangle::translation() const
{
    Rectangle translated;
    Vector t;
    std::cin.ignore(100000, '\n');
    std::cout<<"Wprowadz wspolrzedne x i y wektora translacji\n";
    std::cin>>t;
    for (int i=0;i<NUMBEROFVERTEX;++i){
        translated.v[i] = v[i] + t;
    }

    return translated;
}

// metoda zapisu danych wspolrzednych wierzcholkow prostokata do pliku z ktorego gnuplot bedzie rysowal prostokat
bool Rectangle::Writetofile(std:: string filename)
{
        std::ofstream StrmPlikowy;

       StrmPlikowy.open(filename);
       if (!StrmPlikowy.is_open())
       {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << std::endl
                        << ":(  nie powiodla sie." << std::endl;
              return false;
       }

       this->RectangleToStdout(StrmPlikowy);

       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}

/******************************************************************************
 |  metoda, ktora zwraca wierzcholki prostokata                                                 |
 |  Argumenty:                                                                    |
 |     tablica wektorow do ktorej sa zwracane wiercholki prostokata                                                |
 |  Zwraca:                                                                       |
 |      zmienione wartosci wektorow z wejscia                                          |
 */

void Rectangle::new_rectangle( Vector (&ar)[NUMBEROFVERTEX]) const
{
    for (int i=0;i<NUMBEROFVERTEX;i++){
        ar[i]=v[i];
    }
}

/******************************************************************************
 |  metoda rotacji prostokata                                                 |
 |  Argumenty:                                                                    |
 |      angle - kat obrotu, 
        n - ilosc obrotow                                                |
 |  Zwraca:                                                                       |
 |      zmienione wartosci wektorow z wejscia                                          |
 */
Rectangle Rectangle::rotate(const double &angle) const
{
    Rectangle rotated;
    
    rotated.v[0] = v[0].rotation(angle);
    rotated.v[1] = v[1].rotation(angle);
    rotated.v[2] = v[2].rotation(angle);
    rotated.v[3] = v[3].rotation(angle);

    return rotated;
}
// metoda rotacji prostokata o kat podany przez uzytkownika
Rectangle Rectangle::rotate() const{
    double angle;
    Rectangle rotated;
    std::cin.ignore(100000, '\n');
    std::cout<<"Podaj kat obrotu w stopniach: " << std::endl;
    std::cin>> angle;
    rotated.v[0] = v[0].rotation(angle);
    rotated.v[1] = v[1].rotation(angle);
    rotated.v[2] = v[2].rotation(angle);
    rotated.v[3] = v[3].rotation(angle);

    return rotated;
}
// metoda sprawdzania dlugosci bokow prostokata
bool Rectangle::check_length(Vector const (&vx)[NUMBEROFVERTEX]) const
{
   double length[NUMBEROFVERTEX];
for (int i=0;i<NUMBEROFVERTEX;++i){
    length[i]=vx[i].get_length();
}
if (!(length[0] == length[2]) && (length[1] == length[3])){
    std::cerr << "ERROR: przeciwlegle boki nie sa rowne!" << std::endl;
    return 0;
}
int j=0;
if(length[0]!=length[1]){
if(!(length[0]>length[1]))    j++;
std::cout << "Dluzsze przeciwlegle boki sa sobie rowne" << std::endl
          // wyswietlanie dlugosci bokow prostokata
          << "Dlugosc pierwszego boku: " << length[j] << std::endl
          << "Dlugosc drugiego boku: " << length[j+2] << std::endl << std::endl;
if(!(length[0]>length[1]))    j--;
std::cout << "Krotsze przeciwlegle boki sa sobie rowne" << std::endl
          // wyswietlanie dlugosci bokow prostokata
          << "Dlugosc pierwszego boku: " << length[j] << std::endl
          << "Dlugosc drugiego boku: " << length[j+2] << std::endl << std::endl;
}
else std::cout << "Dany prostokat ma wszystkie boki rowne. Dlugosci bokow to:" 
   // wyswietlanie dlugosci bokow prostokata
  << std::endl << length[0] << std::endl << length[1] <<std::endl << length[2]
  << std::endl << length[3] << std::endl << std::endl;
return 1;
}
/******************************************************************************
 Metoda obracajaca prostokat n (podanych) razy       
*/
Rectangle Rectangle::numberofrotation(){
    Rectangle rect;
    double ang, ang_r;
    int r;
    std::cout<<"Podaj wartosc kata obrotu w stopniach" << std::endl;
    std::cin>>ang;
    std::cout<<"Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
    std::cin>>r;
    double d = r;
    ang_r = ang*d;
    rect = this->rotate(ang_r);
    return rect;
}
/******************************************************************************
 *  Przeciążenie == prostokata                                                         
 *  Argumenty:                                                               
 *      \param[in] this - prostokat, ktora porownujemy                   
 *      \param[in] tmp - prostokat, z ktora porownujemy                                                          
 *  Zwraca:                                                                  
 *      \retval true - jesli sa rowne
 *      \retval false - jesli nie sa                
 */
bool Rectangle::operator == (const Rectangle &rec) const{
    int i;
    for (i=0;i<NUMBEROFVERTEX;++i){
        if (!(v[i]==rec.v[i]))
            return 0;
    }
    return 1;
}
/******************************************************************************
 * Metoda Kierujaca wspolrzedne prostokata na strumien wyjsciowy                       
 * Argumenty:                                                                 
 *      \param[in] out - strumien wyjsciowy                                                                  
 * Zwraca:                                                                    
 *      \param[out] out - strumien wyjsciowy z zapisanymi wspolrzednymi                                                                 
 */
void Rectangle::RectangleToStdout(std::ostream &out)
{
    for (int i=0;i<NUMBEROFVERTEX;++i){
        out<<std::setw(10) << std::fixed << std::setprecision(10) << v[i][0] <<" " << v[i][1] << std::endl;
    }
    out<<v[0][0] <<" " << v[0][1] << std::endl;
}
/******************************************************************************
 * Metoda wyswietlajaca prostokat w GNUplocie                                            *
 * Argumenty:                                                                 *
 *      brak                                                                  *
 * Zwraca:                                                                    *
 *      brak                                                                  *
 */
void Rectangle::PrintRectangle(){
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

       Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Ciagly, 2);

       Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Punktowy, 2);

       Lacze.ZmienTrybRys(PzG::TR_2D);
           this->RectangleToStdout(std::cout);
       if (!this->Writetofile("../datasets/prostokat.dat"))
              std::cerr << "ERROR" << std::endl;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');
}
/******************************************************************************
 |  Przeciazenie operatora <<                                          |
 |  Argumenty:                                                                |
 |      out - strumien wyjsciowy,                                              |
 |      Rec- prostokat.                                                         |
 */
std::ostream &operator<<(std::ostream &out, Rectangle const &Rec)
{
    out << std::setprecision(20) << std::fixed;
    Vector vx[NUMBEROFVERTEX];
    Rec.new_rectangle( vx);
    out << "Wierzcholek A: " << std::endl << vx[0] << std::endl;
    out << "Wierzcholek B: " << std::endl << vx[1] << std::endl;
    out << "Wierzcholek C: " << std::endl << vx[2] << std::endl;
    out << "Wierzcholek D: " << std::endl << vx[3] << std::endl;

    return out;
}

/******************************************************************************
 |  Przeciazenie operatora << dla pliku                                         |
 |  Argumenty:                                                                |
 |      fout - strumien wyjsciowy,                                              |
 |      Rec - prostokat.                                                         |
 */
std::ofstream& operator << (std::ofstream &fout, Rectangle const &Rec)
{
    fout << std::setprecision(20) << std::fixed;
    Vector vx[NUMBEROFVERTEX];
    Rec.new_rectangle( vx);
    fout << "Wierzcholek A: " << std::endl << vx[0] << std::endl;
    fout << "Wierzcholek B: " << std::endl << vx[1] << std::endl;
    fout << "Wierzcholek C: " << std::endl << vx[2] << std::endl;
    fout << "Wierzcholek D: " << std::endl << vx[3] << std::endl;
    return fout;
}

