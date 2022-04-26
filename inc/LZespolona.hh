
#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<cmath>
#include<iostream>
#include<string>
/**
 * @brief Klasa definiujaca liczbe zespolona
 * Klasa skalda sie z dwoch doubli,
 * ktorw przetrzymuja czesc rzeczywista i urojona
 *
 */
class  LZespolona {

private:
  double   re;
  double   im;
public:
  /**
   * @brief Zwraca wartos re
   *
   *
   * @return double wartosc re
   */
  double RE() const { return re; }
  /**
   * @brief Zwraca wartos im
   *
   * @return double wartos im
   */
  double IM() const { return im; }
  /**
   * @brief Zwraca referencje do re.
   *
   * @return double& referencje do re
   */
  double& RE() { return re; };
  /**
   * @brief zwraca referencje do im
   *
   * @return double& referenjce do im
   */

  double& IM() { return im; };
  /**
   * @brief Metoda dodawanie dwoch liczb zespolonych do siebie
   *
   * @param Skl1 liczba ktora dodajemy do this
   * @return LZespolona suma dwoch liczb zespolonych
   */

  LZespolona operator +(LZespolona Skl1);
  /**
   * @brief Metoda odejmowania dowch liczb zespolonych od siebie
   *
   * @param Skl1 liczba ktora jest odejmowana od this
   * @return LZespolona roznica dwoch liczb zespoloncy
   */
  LZespolona  operator - (LZespolona  Skl1);
  /**
   * @brief Metoda mnozenia dwoch liczba zespolonych
   *
   * @param Skl1 liczba przez ktora this jest mnoznoen
   * @return LZespolona iloczyn dwoch liczb zespolonych
   */
  LZespolona  operator * (LZespolona  Skl1);
  /**
   * @brief Metoda dzielenia liczby zespolonej
   *
   * @param Skl1 liczba przez ktora this jest dzielone
   * @return LZespolona iloraz dwoch liczb zespolonych
   */
  LZespolona  operator / (LZespolona  Skl1);
  /**
   * @brief Metoda dzielenia liczby zespolonej przez liczbe typu double
   *
   * @param liczba liczba przez ktora this jest dzielone
   * @return LZespolona iloraz liczby zespolonej i doubla
   */
  LZespolona  operator / (double liczba);
  /**
   * @brief Metoda mnzozenie liczby zespolonej przez liczbe typu double
   *
   * @param liczba liczba przez ktora this jest mnozone
   * @return LZespolona iloczyn liczby zepsolonej i doubla
   */
  LZespolona  operator * (double liczba);
  /**
   * @brief Zwraca szprzenie liczby this
   *
   * @return LZespolona Sprzezona wartosc liczby zespolonej
   */
  LZespolona Sprzezenie();
  /**
   * @brief Zwraca modul liczby zespolonej
   *
   * @return double wartosc modulu
   */
  double Modul2();
  /**
   * @brief Sprawdzenie czy this jest rowne SKl1
   *
   * @param Skl1 Liczba zespolona ktora jest przyrownywana do this
   * @return true jezeli sa takie same
   * @return false jezeli sie roznia
   */
  bool operator == (LZespolona Skl1);
  /**
   * @brief Sprawdzenie czy this jest rowne liczbie
   *
   * @param liczba liczba do ktorej jest this porownywnaie
   * @return true jezeli sa takie same
   * @return false jezeli sie roznia
   */
  bool operator == (int liczba) { return(this->re == 0 && this->im == 0); };
  /**
   * @brief Sprawdzenie czy liczba jest rozna od liczby
   *
   * @param liczba liczba do kotrej jest this porownywane
   * @return true jezeli sie roznia
   * @return false jezeli sa takie same
   */
  bool operator != (int liczba) { return(this->re != 0 || this->im != 0); };
  /**
   * @brief Operator = dla liczby zespolonej kiedy przypisujemy ja do liczbt
   *
   * @param liczba
   * @return LZespolona Liczbe zespolona={liczba,0}
   */
  LZespolona operator  = (int liczba) { this->re = liczba;this->im = 0;return *this; };
};
/**
 * @brief Sposob w jaki wczytujmy liczbe Zespoona
 * program wczytuje liczbe zespolona w nastepujacy sposob (arg1+arg2i), w przypadku bledy program nie wczyta nieczgo
 * @param input sciezka z ktorej wczytujemy
 * @param liczba miejce w ktorym zostaje zapisana liczba zespolona
 * @return std::istream&
 */
std::istream& operator >>(std::istream& input, LZespolona& liczba);
/**
 * @brief Sposob wypisywania liczby zespolonej
 * program wypisuje liczbe zespolona w nastepujacy sposob (arg1+arg2i)
 * @param out sciezka w ktorej wypisujemy liczbe zespolona
 * @param liczba liczba ktora zostanie wypisana
 * @return std::ostream&
 */
std::ostream& operator <<  (std::ostream& out, LZespolona liczba);



#endif