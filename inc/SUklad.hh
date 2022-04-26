#ifndef UKLAD_HH
#define UKLAD_HH
#include <iostream>
#include "SMacierz.hh"
#include <string>
/**
 * @brief Inicjator ukladu rownan
 *
 * @tparam STyp Typ z jakiego bedzie sie skladac uklad rownac
 * @tparam MWymiar  Rozmiar jaki bedzie miec
 */
template<typename STyp, int MWymiar>
class UkladR {
    /**
     * @brief Klada Uklad rownan
     * mac = macierz
     * wek = wektor wyrazow wolnych
     *
     */
private:
    SMacierz<STyp, MWymiar> mac;
    SWektor<STyp, MWymiar> wek;
public:
    /**
     * @brief Zwraca macierz zapisana w klasie
     *
     * @return SMacierz<STyp,MWymiar> Macierz
     */
    SMacierz<STyp, MWymiar> m()const { return mac; }
    /**
     * @brief Zwraca wektor zapiany w klasie
     *
     * @return SWektor<STyp,MWymiar> Wektor wyrazow wolnych
     */
    SWektor<STyp, MWymiar>  w()const { return wek; }
    /**
     * @brief Zwraca referencje do klasy zapisanej w Klasie
     *
     * @return SMacierz<STyp,MWymiar>& Referencja do macierzy
     */


    SMacierz<STyp, MWymiar>& m() { return mac; }
    /**
     * @brief Zwraca referencje do wektora zapisanego w klasie
     *
     * @return SWektor<STyp,MWymiar>& Referencja do wektora wyrazow wolnych
     */

    SWektor<STyp, MWymiar>& w() { return wek; }
    /**
     * @brief Oblicza wynik ukladu rownan
     * Rozwiazuje uklad metoda cramera
     * jesli wyznacznik macierzy glownej byl rowny 0
     * to program wypisuje ze nie da sie policzyc z cramera
     *
     * @return SWektor<STyp,MWymiar> wektor rozwiazan od(1 do MWymiar)
     */
    SWektor<STyp, MWymiar> oblicz()const;

};
template<typename STyp, int MWymiar> std::istream& operator >> (std::istream& input, UkladR<STyp, MWymiar>& UklRown) {
    input >> UklRown.m();
    input >> UklRown.w();
    return input;
}
template<typename STyp, int MWymiar> std::ostream& operator << (std::ostream& out, const UkladR<STyp, MWymiar> UklRown) {
    int b;
    b = ROZMIAR / 2;
    for (int a = 0;a < ROZMIAR;++a) {
        out << "| " << UklRown.m()[a] << "|| " << "x_" << a + 1 << "|";

        if (b == a) {
            out << " = " << "| " << UklRown.w()[a] << " |" << std::endl;
        }
        else {
            out << "   " << "| " << UklRown.w()[a] << " |" << std::endl;
        }


    }
    out << std::endl;


    return out;
}

template<typename STyp, int MWymiar>
SWektor<STyp, MWymiar> UkladR<STyp, MWymiar>::oblicz()const {
    STyp wyznacznik;
    SWektor<STyp, MWymiar> wynik;
    SMacierz<STyp, MWymiar> trans;
    wyznacznik = mac.wyznacznik();
    if (wyznacznik == 0) {
        std::cout << "Wyzacznik Macierzy glownej jest rowny 0" << std::endl;
        std::cout << "Nie da policzyc sie tego z Cramera" << std::endl;
        exit(0);
    }
    else {
        for (int a = 0;a < ROZMIAR;++a) {
            trans = mac.transpozycja();
            //Transpozycja macierzy nie powoduje zmiany wartości jej wyznacznika: det A^T = det A . 
            trans[a] = wek;
            wynik[a] = trans.wyznacznik() / wyznacznik;
        }
    }

    return wynik;
}




















#endif