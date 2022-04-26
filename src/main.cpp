#include "SWektor.hh"
#include "rozmiar.h"
#include "LZespolona.hh"
#include "SMacierz.hh"
#include "SUklad.hh"
#include <fstream>


using namespace std;










void obliczuklad(ifstream& streamin) {
     char znak;
     streamin >> znak;
     switch (znak) {
     case 'r': {
          UkladR<double, ROZMIAR> uklad;
          SWektor<double, ROZMIAR> bledu;
          streamin >> uklad;
          if (streamin.fail()) {
               cerr << "Jakis blad podczas wczytywania" << endl;
               break;
          }
          else {
               cout << "Wczytano uklad rowanan" << endl;
               cout << std::fixed << std::setprecision(2) << uklad;
               //cout << macierz[0] << endl;
               cout << "Rozwiazanie od (x1 do xn)" << endl;
               //` cout << uklad.m().wyznacznik() << endl;
               cout << uklad.oblicz() << endl;
               bledu = uklad.m() * uklad.oblicz() - uklad.w();
               cout << "Wektor bledu={" << std::scientific << std::setprecision(2) << bledu << "}" << endl;
               cout << "Wielkosc bledu: " << bledu.modul() << endl;
               break;
          }
     }
     case 'z': {
          UkladR<LZespolona, ROZMIAR> uklad;
          SWektor<LZespolona, ROZMIAR> bledu;
          streamin >> uklad;
          if (streamin.fail()) {
               cerr << "Jakis blad podczas wczytywania" << endl;
               break;
          }
          else {
               cout << "Wczytano uklad rowanan" << endl;
               cout << std::fixed << std::setprecision(2) << uklad;
               //cout << macierz[0] << endl;
               cout << "Rozwiazanie od (x1 do xn)" << endl;
               //cout << uklad.m().wyznacznik() << endl;
               cout << uklad.oblicz() << endl;
               bledu = uklad.m() * uklad.oblicz() - uklad.w();
               cout << "Wektor bledu={" << std::scientific << std::setprecision(2) << bledu << "}" << endl;
               cout << "Wielkosc bledu: " << bledu.modul() << endl;
               break;
          }
     }
     }
}

// UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
// cin >> UklRown;
// cout << UklRown;
int main(int argc, char** argv)
{
     if (argc < 2) {
          cerr << endl;
          cerr << " Brak nazwy pliku z zawartoscia testu." << endl;
          cerr << endl;
          return 1;
     }

     ifstream  PlikTestu(argv[1]);

     if (PlikTestu.is_open() == false) {
          cerr << "Nie udalo sie utworzyc pliku o nazwie " << argv[1] << endl;
          return 1;
     }

     obliczuklad(PlikTestu);




}
