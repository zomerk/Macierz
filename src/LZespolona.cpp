#include "LZespolona.hh"
#include <iomanip>

using namespace std;


LZespolona LZespolona::operator + (LZespolona  x)
{
  LZespolona  Wynik;

  Wynik.re = this->re + x.re;
  Wynik.im = this->im + x.im;
  return Wynik;
}
LZespolona  LZespolona::operator - (LZespolona  x)
{
  LZespolona  Wynik;

  Wynik.re = this->re - x.re;
  Wynik.im = this->im - x.im;
  return Wynik;
}
LZespolona  LZespolona::operator * (LZespolona  x)
{
  LZespolona Wynik;

  Wynik.re = (this->re * x.re) - (this->im * x.im);
  Wynik.im = (this->re * x.im) + (this->im * x.re);
  return Wynik;

}
LZespolona LZespolona::operator / (LZespolona y) {
  LZespolona Wynik;
  double modul;

  modul = y.Modul2();
  Wynik = (this->operator*(y.Sprzezenie()) / modul);
  return Wynik;
}
LZespolona LZespolona::operator / (double x) {
  if (x == 0) {
    std::cerr << "Dzielenie przez zero" << std::endl;
  }
  LZespolona wynik;
  wynik.re = this->re / x;
  wynik.im = this->im / x;
  return  wynik;

}
LZespolona  LZespolona::operator * (double liczba) {
  this->im = this->im * liczba;
  this->re = this->re * liczba;
  return *this;
}

LZespolona LZespolona::Sprzezenie() {
  LZespolona wynik;
  this->im = this->im * -1;
  wynik.re = this->re;
  wynik.im = this->im;
  return wynik;
}
double LZespolona::Modul2() {
  double z;
  z = sqrt(this->re * this->re + this->im * this->im);
  return z * z;
}
std::ostream& operator <<  (std::ostream& out, LZespolona liczba) {
  out << std::noshowpos << "(" << liczba.RE() << std::showpos << liczba.IM() << "i)";
  return out;
}
bool LZespolona::operator == (LZespolona Skl2) {
  return(this->re == Skl2.re && this->im == Skl2.im);
}
std::istream& operator >>(std::istream& input, LZespolona& liczba) {
  char znak, nawias, litera;
  input >> znak;
  if (input.fail()) {
    return input;
  }
  if (znak != '(') {
    input.setstate(std::ios::failbit);
    return input;
  }
  input >> liczba.RE();
  if (input.fail()) {
    return input;
  }
  input >> liczba.IM();
  if (input.fail()) {
    return input;
  }
  input >> litera;
  if (input.fail()) {
    return input;
  }
  if (litera != 'i') {
    input.setstate(std::ios::failbit);
    return input;
  }
  input >> nawias;
  if (input.fail()) {
    return input;
  }
  if (nawias != ')') {
    input.setstate(std::ios::failbit);
    return input;
  }
  return input;
}