#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "rozmiar.h"
#include "LZespolona.hh"


/**
 * @brief Inicjator Wektora
 *
 * @tparam STYp - typ z jakiego skladac sie bedzie wektor
 * @tparam MWymiar - rozmiar wektorra
 */
template <typename STyp, int MWymiar>
class SWektor {
  /**
   * @brief Klasa opisujaca wektor
   *
   */
  STyp  _Wsp[MWymiar];
public:
  /**
   * @brief Inicjalizator, jak stworzona zostaje klasa wektor zeruje jej wszystkie warotsci
   *
   */
  SWektor() { for (STyp& Wsp : _Wsp) Wsp = 0; }
  /**
   * @brief ZWraca wartosc zapisana pod Ind
   *
   * @param Ind nie wiem jak to opisac
   * @return STyp Wartosc pod Ind
   */
  STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
  /**
   * @brief Zwraca referencje do liczby w wektorze na miejcu IND
   *
   * @param Ind nie wiem jak to opisac
   * @return STyp& Rferencje spod Inf
   */
  STyp& operator [] (unsigned int Ind) { return _Wsp[Ind]; }
  /**
   * @brief Metoda odejmowania dwoch wektorow od siebie
   *
   * @param Odjemnik Wektor przez ktory this jest odejmownay
   * @return SWektor<STyp, MWymiar> Roznica liczby zespolonej
   */
  SWektor<STyp, MWymiar> operator - (const SWektor<STyp, MWymiar> Odjemnik) const;
  /**
   * @brief Metoda mnzoenia dwoch wektorow
   *
   * @param Mnoznik Wektor przez ktory this jest mnozony
   * @return SWektor<STyp, MWymiar> iloczyn dowch wektorow
   */
  SWektor<STyp, MWymiar> operator * (STyp Mnoznik) const;
  /**
   * @brief Metoda mnozenia wektora przez liczbe
   *
   * @param Mnoznik Liczba przez ktora this jest mnozone
   * @return SWektor<STyp, MWymiar> iloczyn wekotra i liczby
   */
  SWektor<STyp, MWymiar> operator * (int Mnoznik) const;
  /**
   * @brief  Metoda dodawania dwoch wektorwo do siebie
   *
   * @param drugi Wektor ktory bedzie dodany do this
   * @return SWektor<STyp, MWymiar> wektor sumy wektorow
   */
  SWektor<STyp, MWymiar>  operator +(SWektor<STyp, MWymiar> drugi);//cost w srodku elo
  /**
   * @brief  Metoda mnozenia Wektora przez Wektor, skalarny
   *
   * @param drugi Wektor przez ktory this bedzie mnozony
   * @return STyp wartos skalara dwoch wektorow
   */
  STyp  operator *(const SWektor<STyp, MWymiar> drugi)const;
  /**
   * @brief Metoda dzielenia wektora przez liczbe
   *
   * @param liczba liczba przez ktora this bedzie dzielone
   * @return SWektor<STyp, MWymiar> wektor dzielenia dwoch wektorow
   */
  SWektor<STyp, MWymiar> operator /(const STyp liczba);//const;
  /**
   * @brief Metoda przypisanie liczby zespolonej innej liczby przez operator =
   *
   * @param drugi wektor kotry bedzie wpisywany do this
   * @return SWektor<STyp, MWymiar> zwraca wektor
   */
  SWektor<STyp, MWymiar> operator=(const SWektor<STyp, MWymiar> drugi);
  /**
   * @brief Modul z wektora
   *
   * @return STyp zwraca warotsc modulu
   */
  STyp modul()const;

};


template <typename STyp, int MWymiar>
std::istream& operator >> (std::istream& Strm, SWektor<STyp, MWymiar>& Wek) {
  for (int a = 0;a < MWymiar;++a) {
    Strm >> Wek[a];
    if (Strm.fail()) {
      return Strm;
    }
  }
  return Strm;
}

template <typename STyp, int MWymiar>
SWektor<STyp, MWymiar> SWektor<STyp, MWymiar>::operator - (const SWektor<STyp, MWymiar>Odjemnik) const
{
  SWektor<STyp, MWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < MWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int MWymiar>
SWektor<STyp, MWymiar> SWektor<STyp, MWymiar>::operator * (STyp Mnoznik) const
{
  SWektor<STyp, MWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < MWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] * Mnoznik;
  return Wynik;
}
template <typename STyp, int MWymiar>
SWektor<STyp, MWymiar> SWektor<STyp, MWymiar>::operator * (int Mnoznik) const
{
  SWektor<STyp, MWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < MWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] * Mnoznik;
  return Wynik;
}


template <typename STyp, int MWymiar>
std::ostream& operator << (std::ostream& StrmWyj, const SWektor<STyp, MWymiar>& W)
{
  for (unsigned int Ind = 0; Ind < MWymiar; ++Ind) {

    StrmWyj << " " << W[Ind];
  }
  return StrmWyj;
}
template <typename STyp, int MWymiar>
SWektor<STyp, MWymiar>  SWektor<STyp, MWymiar>::operator +(SWektor<STyp, MWymiar> drugi)
{
  SWektor<STyp, MWymiar> wynik;
  for (int a = 0;a < MWymiar;++a) {
    wynik._Wsp[a] = drugi._Wsp[a] + this->_Wsp[a];
  }
  return wynik;

}


template <typename STyp, int MWymiar>
STyp  SWektor<STyp, MWymiar>::operator *(const SWektor<STyp, MWymiar> drugi) const
{
  STyp wynik;
  wynik = 0;
  for (int a = 0;a < MWymiar;++a) {
    wynik = wynik + drugi[a] * this->_Wsp[a];
  }
  return wynik;

}





template <typename STyp, int MWymiar>
SWektor<STyp, MWymiar> SWektor<STyp, MWymiar>::operator /(const STyp liczba)
{
  SWektor<STyp, MWymiar> wynik;
  //assert(liczba != 0);
  for (int a = 0; a < MWymiar;++a) {

    wynik[a] = this->_Wsp[a] / liczba;
  }
  return wynik;
}
template <typename STyp, int MWymiar>
SWektor<STyp, MWymiar> SWektor<STyp, MWymiar>::operator=(const SWektor<STyp, MWymiar> liczba) {
  for (int a = 0;a < MWymiar;++a) {
    this->_Wsp[a] = liczba[a];
  }
  return *this;
}



template <typename STyp, int MWymiar>
STyp SWektor<STyp, MWymiar>::modul()const {
  STyp wynik, pom;
  wynik = 0;
  for (int a = 0;a < MWymiar;++a) {
    pom = this->_Wsp[a];
    wynik = wynik + pom * pom;
  }

  return wynik;


}
template<>
LZespolona  SWektor <LZespolona, ROZMIAR>::modul()const {
  LZespolona wynik, pom;
  wynik = 0;
  for (int a = 0;a < ROZMIAR;++a) {
    pom = this->_Wsp[a];
    wynik = wynik + pom * pom / pom.Sprzezenie();
  }
  return wynik;
}






#endif
