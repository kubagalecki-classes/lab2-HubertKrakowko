#include <iostream>
using namespace std;

class Wektor
{
private:
    int dlugosc;
    int pojemnosc;

public:
    double* tablica;
    /*
        Wektor(int n)
        {
            dlugosc = n;
            tablica = new double[dlugosc];
            for (int i = 0; i < dlugosc; i++) {
                tablica[i] = 2;
            };
        }
    */

    Wektor(int n) : dlugosc{n}, tablica{}
    {
        tablica = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++) {
            tablica[i] = 0.;
        };
    }

    Wektor(const Wektor& tab) : pojemnosc{tab.pojemnosc}, dlugosc{tab.dlugosc}, tablica{}
    {
        cout << dlugosc << endl;
        tablica = new double[dlugosc];

        for (int i = 0; i < dlugosc; i++) {
            tablica[i] = tab.tablica[i];
        }
    }

    Wektor& operator=(const Wektor& tab)
    {
    

        cout << "wywolano opa" << endl;
        for (int i = 0; i < dlugosc; i++) {
            swap(tab.tablica[i], tablica[i]);
        }
        return *this;
    }

    Wektor(Wektor&& tab) : dlugosc{0}, tablica{nullptr}
    {
        int j = tab.dlugosc;
        for (int i = 0; i < 5; i++) {
            tab.tablica[i] = 0;
            cout << "usuwanko" << i << endl;
        }
        cout << "dziala??";

        tab.dlugosc = dlugosc;
        tab.dlugosc = 0;
        tab.tablica = nullptr;
    }
    //
    //
    //
    //
    //
    //
    int getdlug() { return (dlugosc); }
    int getdpoj() { return (pojemnosc); }

    void print()
    {

        for (int i = 0; i < dlugosc; i++) {
            cout << tablica[i] << endl;
        }
    }
    ~Wektor() { delete[] tablica; }

    void zmiendlugosc(int n)
    {
        if (n <= pojemnosc) {

            for (int i = n; i < dlugosc; i++) {
                tablica[i] = 0.;
            }
            dlugosc = n;
        }

        if (n > pojemnosc) {
            double* ntablica = new double[n];

            for (int i = 0; i <= pojemnosc; i++) {

                ntablica[i] = tablica[i];
            }
            for (int i = pojemnosc; i < n; i++) {
                ntablica[i] = 0.;
            }
            delete[] tablica;
            dlugosc = n;
        }
    }

    double& operator[](int n)
    {
        if (n <= dlugosc) {
            double& ref_tab = tablica[n];
            return (ref_tab);
        }
        else if (n > dlugosc) {
            zmiendlugosc(n);
            double& ref_tab = tablica[n];
            return (ref_tab);
        }
    }
};

struct Kokardka
{
    Kokardka(int d) : dlugosc{d} {}

    int dlugosc;
    int kebab;
};

struct Prezent
{
    Prezent(int dk) : k{dk} {}

    Kokardka k;

    // Inne pola ...
};
/*
struct Liczba
{
    Liczba(int w) : wartosc{w} {}
    // Liczba(const Liczba& l) : wartosc{l.wartosc} { cout << "konstruowanie" << endl; }

    int wartosc;
};

int main()
{
    Liczba b{3};
    Liczba a{b};  // W celu konstrukcji b wołamy konstruktor kopiujący z argumentem 'a'
    Liczba c = a; // Tutaj także wołamy konstruktor kopiujący, vide lab. 1
    cout << a.wartosc << endl;

    cout << b.wartosc << endl;
    cout << c.wartosc << endl;
}*/

int main()
{
    Wektor A(5);
    Wektor B(A);
    cout << B.getdlug() << endl;
    // A.print();
    cout << "______" << endl;
    B.print();
    for (int i = 0; i < A.getdlug(); i++) {
        A[i] = 10;
    }
    A.print();
    // A = A;
    cout << "______" << endl;
    // A.print();
    Wektor(move(A));
    // A.print();
    // cout << A[0] << endl;
    // cout << A.getdlug() << endl;
    cout << "udalo sie" << endl;
    // A.print();
    // cout << B[2];
    // cout << "______" << endl;
    // cout << B[2];
    // cout << A[2];
    // A.zmiendlugosc(2);
    // A.print();
    // cout << "______" << endl;
    // A.zmiendlugosc(6);
    // A.print();
    // cout << "______" << endl;

    // A[6] = 42;

    // for (int i = 0; i < 7; i++) {
    //  cout << A[i] << endl;
    //}

    // Prezent(4);
}
