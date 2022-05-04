#ifndef SMACIERZ_HH
#define SMACIERZ_HH
#include "SWektor.hh"
#include <iostream>
#include <math.h>
/**
 * @brief Inicjator Macierzy
 *
 * @tparam Typ z ktorego bedzie skladac sie macierz
 * @tparam Rozmiar macierzy
 */
template<typename STyp, int MWymiar>
/**
    * @brief Klasa przetrzymujaca macierz
    * Sklada sie ona z MWymiaru tablic typu STYp ktore rowaniez sa MWymiaru
    *
    */
    //test git laba 
class SMacierz {

    SWektor<STyp, MWymiar> KOL[MWymiar];
public:
    /**
     * @brief Zwraca wartosci wektora zapisanego pod miejscem kolumna
     *
     * @param kolumna numere kolumny(od 0 do MWymiar-1)
     * @return STyp& wartosc wektora pod miejcem koluma
     */
    SWektor<STyp, MWymiar>& operator[](const int kolumna) { return KOL[kolumna]; }
    /**
     * @brief Zwraca referencje do wektora zapsianego pod miejscem kolumna
     *
     * @param kolumna numer kolumny(od 0 do MWymiar-1)
     * @return STyp referencja wektoa pod miejscem kolumna
     */
    SWektor<STyp, MWymiar> operator[](const int koluna)const { return KOL[koluna]; }
    /**
     * @brief Definicja mnozenie Macierzy przez wektor
     *
     * @param xyz wektro przez ktory mnozona jest macierz
     * @return STyp iloczyn Macierzy razy wektor
     */
    SWektor<STyp, MWymiar> operator*(const SWektor < STyp, MWymiar > xyz)const;
    /**
     * @brief Operacja transpozycji macierzy
     *
     * @return SMacierz<STyp, MWymiar> macierz trasnponowana
     */

    SMacierz<STyp, MWymiar> transpozycja()const;
    /**
     * @brief Operacja wyzncznika macierzy
     * Srowadza macierz do postaci 3x3 a nastepnie wylicza ze wzrou sarusa
     * analogicznie jesezli  MWymiar=2 to policzy ze wzoru dla macierzy 2x2
     *
     * @return STyp wyznacznik macierz
     */
    STyp wyznacznik()const;
    /**
     * @brief zamiana kolumn ze soba
     *
     * @param KOL1 kolumna pierwsz
     * @param KOL2 kolumna druga
     */
    void zamiana(unsigned int KOL1, unsigned int KOL2);
};


template<typename STyp, int MWymiar>
std::istream& operator >> (std::istream& input, SMacierz< STyp, MWymiar>& Mac) {
    for (int a = 0;a < MWymiar;++a) {
        input >> Mac[a];
        if (input.fail()) {
            return input;
        }
    }
    return input;
}
template<typename STyp, int MWymiar>
std::ostream& operator << (std::ostream& output, SMacierz< STyp, MWymiar>& Mac) {
    for (int a = 0;a < MWymiar;++a) {
        output << Mac[a];
        output << ' ';
    }
    return output;
}
template<typename STyp, int MWymiar>
STyp SMacierz<STyp, MWymiar>::wyznacznik()const {
    SMacierz< STyp, MWymiar> tmp;
    STyp liczba;
    liczba = 1;
    double zamianawierszy = 1;
    int a;
    STyp wyznacznik;
    wyznacznik = 1;
    for (a = 0;a < MWymiar;++a) {
        tmp[a] = this->KOL[a];
    }
    if (MWymiar != 2) {
        for (int a = 0;a < MWymiar - 3;++a) {
            if (tmp[a][a] == 0) {
                for (int x = a + 1;x < MWymiar;++x) {
                    if (tmp[x][a] != 0) {
                        tmp.zamiana(x, a);
                        zamianawierszy = zamianawierszy * -1;
                        a = a - 1; //wtf
                        break;
                    }
                    else if (x + 1 == MWymiar) {
                        wyznacznik = 0;
                    }
                }
            }
            else {
                liczba = liczba * tmp[a][a];
                for (int b = a + 1;b < MWymiar;++b) {
                    tmp[b] = tmp[b] + (tmp[a] * (-1) * (tmp[b][a]) / tmp[a][a]);
                }


            }
        }

        if (wyznacznik == 0) {
            return wyznacznik;
        }
        else {
            wyznacznik = liczba * zamianawierszy * (tmp[MWymiar - 3][MWymiar - 3] * tmp[MWymiar - 2][MWymiar - 2] * tmp[MWymiar - 1][MWymiar - 1] + tmp[MWymiar - 3][MWymiar - 2] * tmp[MWymiar - 2][MWymiar - 1] * tmp[MWymiar - 1][MWymiar - 3] + tmp[MWymiar - 3][MWymiar - 1] * tmp[MWymiar - 2][MWymiar - 3] * tmp[MWymiar - 1][MWymiar - 2] - (tmp[MWymiar - 3][MWymiar - 1] * tmp[MWymiar - 2][MWymiar - 2] * tmp[MWymiar - 1][MWymiar - 3] + tmp[MWymiar - 3][MWymiar - 3] * tmp[MWymiar - 2][MWymiar - 1] * tmp[MWymiar - 1][MWymiar - 2] + tmp[MWymiar - 3][MWymiar - 2] * tmp[MWymiar - 2][MWymiar - 3] * tmp[MWymiar - 1][MWymiar - 1]));
            return wyznacznik;
        }
    }
    else {
        wyznacznik = tmp[0][0] * tmp[1][1] - tmp[0][1] * tmp[1][0];
        return wyznacznik;
    }
}


template<typename STyp, int MWymiar>
void SMacierz< STyp, MWymiar>::zamiana(unsigned int KOL1, unsigned int KOL2) {
    std::swap(KOL[KOL1], KOL[KOL2]);
}
template<typename STyp, int MWymiar>
SMacierz< STyp, MWymiar> SMacierz< STyp, MWymiar>::transpozycja()const {
    SMacierz< STyp, MWymiar> wynik;

    for (int a = 0; a < MWymiar;++a) {
        for (int b = 0;b < MWymiar;++b) {
            wynik[b][a] = KOL[a][b];
        }
    }
    return wynik;
}
template<typename STyp, int MWymiar>
SWektor<STyp, MWymiar> SMacierz< STyp, MWymiar>::operator *(const SWektor<STyp, MWymiar> xyz)const {
    SWektor<STyp, MWymiar> wynik;
    for (int a = 0;a < MWymiar;++a) {
        wynik[a] = KOL[a] * xyz;
    }
    return wynik;
}
















#endif
