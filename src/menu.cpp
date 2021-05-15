#include"menu.hh"
/******************************************************************************
 | Konstruktor bezparametryczny (jedyny) klasy menu                           |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
menu::menu(){
    open=1;
}
/******************************************************************************
 | Metoda inicjujaca menu                                                              |
 | Argumenty:                                                                 |
 |      \param[in] tab - tablica 4 wektorow                                   |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
void menu::init_menu(Vector const (&ar)[NUMBEROFVERTEX]){
    char n;
    Rectangle rect(ar);
    show();
    while(open){
        std::cin>>n;
        this->switch_menu(n, rect);
    }

}
/******************************************************************************
 | Metoda wypisujaca menu na standardowym wyjsciu                                      |
 | Argumenty:                                                                 |
 |      brak                                                                  |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
void menu::show(){
std::cout<<"o - obrot prostokata o zadany kat\n" ;
std::cout<<"p - przesuniecie prostokata o zadany wektor\n";
std::cout<<"w - wyswietlenie wspolrzednych wierzcholkow\n";
std::cout<<"m - wyswietl menu\n";
std::cout<<"k - koniec dzialania programu\n";
}
/******************************************************************************
 | Metoda do obsluga petli switch dla menu                                              |
 | Argumenty:                                                                 |
 |      opcja menu, wczytywany prostokat                                  |
 | Zwraca:                                                                    |
 |      brak                                                                  |
 */
void menu::switch_menu(const char &op, Rectangle &rec){
    switch (op){
        case 'o':
            rec = rec.numberofrotation();
            rec.PrintRectangle();
            break;
        case 'p':
            rec = rec.translation();
            rec.PrintRectangle();
            break;
        case 'w':
            std::cout<<rec<<std::endl;
            break;
        case 'm':
            this->show();
            break;
        case 'k':
            open=0;
            std::cout<<"Koniec dzialania programu"<<std::endl;
            break;
        default:
            std::cout<<"Bledna opcja"<<std::endl;
            break;
    }
}