#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct Osoba{
    string Imie;
    string Nazwisko;
    string waga;
    string wiek;
    Osoba * nastepny = nullptr;
};
void zakolejkuj_osobe(Osoba * nowy, Osoba *& glowa)
{
    if(glowa==nullptr){
        glowa = nowy;
        return;
    }
    else{
        Osoba * ptr = glowa;
        while(ptr->nastepny!=nullptr){
            ptr=ptr->nastepny;
        }
        ptr->nastepny = nowy;
    }
    
    
}
void rozmiar_kolejki(Osoba * glowa)
{
    Osoba * rtp = glowa;
    int nr = 0;
    while(rtp!=nullptr){
        
        rtp=rtp->nastepny;
        nr++;
    }    
    cout << "Rozmiar kolejki: " << nr << endl;
}
void wypisz_kolejke(Osoba * glowa)
{
    Osoba * temp = glowa;
    if(glowa==nullptr){
        cout<<"Kolejka jest pusta.\n";
    }
    else{
            cout << "Kolejka: \n";
        cout << " NR |           IMIE            |         NAZWISKO          | WIEK | WAGA \n";
        int numerek = 1;
        while(temp!=nullptr){
            if(numerek<10){
                int dlugosc, dlugosc2, wiekd, wagad = 0;
                cout<< "  " << numerek << " |";
                dlugosc = temp->Imie.length();
                for(int i = 0; i < (25-dlugosc); i++){
                    cout << " ";
                }
                cout << temp->Imie << " |";
                dlugosc2 = temp->Nazwisko.length();
                for(int i = 0; i < (25-dlugosc2); i++){
                    cout << " ";
                }
                cout << temp->Nazwisko << " |";
                wiekd = temp->wiek.length();
                for(int i = 0; i < (4-wiekd); i++){
                    cout << " ";
                }
                cout << temp->wiek << " |";
                wagad = temp->waga.length();
                for(int i = 0; i < (5-wagad); i++){
                    cout << " ";
                }
                cout << temp->waga << endl; 
                numerek++;
            }
            else if(numerek>9 && numerek<100){
                int dlugosc, dlugosc2, wiekd, wagad = 0;
                cout<< " " << numerek << " |";
                dlugosc = temp->Imie.length();
                for(int i = 0; i < (25-dlugosc); i++){
                    cout << " ";
                }
                cout << temp->Imie << " |";
                dlugosc2 = temp->Nazwisko.length();
                for(int i = 0; i < (25-dlugosc2); i++){
                    cout << " ";
                }
                cout << temp->Nazwisko << " |";
                wiekd = temp->wiek.length();
                for(int i = 0; i < (4-wiekd); i++){
                    cout << " ";
                }
                cout << temp->wiek << " |";
                wagad = temp->waga.length();
                for(int i = 0; i < (5-wagad); i++){
                    cout << " ";
                }
                cout << temp->waga << endl; 
                numerek++;
            }
            else{
                int dlugosc, dlugosc2, wiekd, wagad = 0;
                cout<< numerek << " |";
                dlugosc = temp->Imie.length();
                for(int i = 0; i < (25-dlugosc); i++){
                    cout << " ";
                }
                cout << temp->Imie << " |";
                dlugosc2 = temp->Nazwisko.length();
                for(int i = 0; i < (25-dlugosc2); i++){
                    cout << " ";
                }
                cout << temp->Nazwisko << " |";
                wiekd = temp->wiek.length();
                for(int i = 0; i < (4-wiekd); i++){
                    cout << " ";
                }
                cout << temp->wiek << " |";
                wagad = temp->waga.length();
                for(int i = 0; i < (5-wagad); i++){
                    cout << " ";
                }
                cout << temp->waga << endl; 
                numerek++;
            }
            temp = temp->nastepny;
            
        }
    }
}
int main()
{
    Osoba * glowa = nullptr;
    ifstream plik;
    plik.open("kolejka_10.txt", ios::binary);
    if(plik.is_open()) cout << "Udało się otworzyć plik" << endl;
    else cout << "NIE udało się otworzyć pliku" << endl;
    string komenda;
    while(getline(plik, komenda)){
        stringstream ss(komenda);
        ss>>komenda;
        if(komenda == "zakolejkuj"){
            string Imie, Nazwisko, wiek , waga;
            
            ss >> Imie >> Nazwisko >> wiek >> waga;
            Osoba * nowy = new Osoba{Imie, Nazwisko, waga, wiek};
            zakolejkuj_osobe(nowy, glowa);
        }
        else if(komenda == "pobierz"){
            Osoba * w = glowa;
            if(glowa!=nullptr){
                glowa = glowa->nastepny;
                delete w; 
            }
            else{
                cout << "Kolejka jest pusta, nie można pobrać elementu.\n";
            }
            

        }
        else if(komenda == "rozmiar"){
            rozmiar_kolejki(glowa);
        }
        else{
            wypisz_kolejke(glowa);
        }
    }
    
    
    plik.close();
    return 0;
}