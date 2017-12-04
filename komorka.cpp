#include "komorka.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool Komorka::GetZycie(){
    return this->czyZyje;
}

void Komorka::SetZycie(bool status){
    this->czyZyje = status;
}

int Komorka::GetX(){
    return this->wspX;
}

int Komorka::GetY(){
    return this->wspY;
}

void Komorka::SetX(int pozycja){
    this->wspX = pozycja;
}

void Komorka::SetY(int pozycja){
    this->wspY = pozycja;
}

void Plansza::PoszerzPlansze(int dlugoscX, int dlugoscY){
    int pole;
    pole = dlugoscX*dlugoscY;

    k.resize(pole);
}

Plansza::Plansza(int daneX, int daneY){
    this->dlugoscX = daneX;
    this->dlugoscY = daneY;

    PoszerzPlansze(dlugoscX, dlugoscY);
}

void Plansza::SprawdzPlansze(){

    int sumaZywych=0;

    for(int i=0; i<dlugoscX*dlugoscY; i++){

        if( (i+1>=0 && i+1 <dlugoscX*dlugoscY && (i+1)%dlugoscX != 0) && k[i+1].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i-1>=0 && i-1 <dlugoscX*dlugoscY && (i-1)%dlugoscX != 0) && i%dlugoscX != 0 && k[i-1].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i-dlugoscX - 1 >= 0 && i-dlugoscX - 1 <dlugoscX*dlugoscY && i%dlugoscX != 0 && (i-dlugoscX)%dlugoscX != 0) && k[i-dlugoscX - 1].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i-dlugoscX >= 0 && i-dlugoscX < dlugoscX*dlugoscY && (i-dlugoscX)%dlugoscX != 0) && k[i-dlugoscX].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i-dlugoscX+1 >= 0 && i-dlugoscX+1 < dlugoscX*dlugoscY && (i-dlugoscX+1)%dlugoscX != 0) && k[i-dlugoscX+1].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i+dlugoscX >= 0 && i+dlugoscX < dlugoscX*dlugoscY && (i+dlugoscX)%dlugoscX != 0) && k[i+dlugoscX].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i+dlugoscX-1 >= 0 && i+dlugoscX-1 < dlugoscX*dlugoscY &&i%dlugoscX != 0 && (i+dlugoscX-1)%dlugoscX != 0) && k[i+dlugoscX-1].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }
        if( (i+dlugoscX+1 >= 0 && i+dlugoscX+1 < dlugoscX*dlugoscY && (i+dlugoscX+1)%dlugoscX != 0) && k[i+dlugoscX+1].GetZycie() == true && i%dlugoscX != 0)
            {
                sumaZywych++;
            }

        //std::cout << "suma zywych: "<< sumaZywych << "\n";

        if(k[i].GetZycie() == false && sumaZywych==3){
            k[i].SetZycie(true);
            }

        else if(k[i].GetZycie() == true && (sumaZywych != 2 && sumaZywych != 3)){
            k[i].SetZycie(false);
        }
        sumaZywych = 0;
    }
    for(int i=0; i <dlugoscX*dlugoscY; i++){
        //std::cout << k[i].GetZycie() << "\n";
    }
}

void Plansza::WypiszPlansze(){

    for(int i=0; i < dlugoscX*dlugoscY; i++){
        if(k[i].GetZycie() == false){
            std::cout << "-";
        }
        if(k[i].GetZycie() == true){
            std::cout << "+";
        }
        if( (i+1)%dlugoscX == 0){
            std::cout << "\n";
        }
    }
}

int wymiarPlanszyX(){
    int dlX;

    std::cout << "Podaj dlugosc X planszy: ";
    std::cin >> dlX;

    return dlX;
}

int wymiarPlanszyY(){
    int dlY;

    std::cout << "Podaj dlugosc Y planszy: ";
    std::cin >> dlY;

    return dlY;
}

void Plansza::ZapiszDoPliku(){

    std::fstream plik;

    plik.open("save.txt", std::ios::out);

    if(plik.good() != true){
        std::cout << "Nie udalo sie otworzyc pliku!\n";
        exit(-1);
    }

    plik << dlugoscX*dlugoscY << std::endl;

    for(int i=0; i < dlugoscX*dlugoscY; i++){
        plik << i << " " << k[i].GetZycie() << std::endl;
    }

    plik.close();
}

void Plansza::WczytajZPliku(){

    int rozmiarPlanszy=-1;
    int licznik=0;

    std::fstream plik;
    std::string linia;

    plik.open("save.txt", std::ios::in);

    if(plik.good() != true){
        std::cout << "Nie udalo sie otworzyc pliku!\n";
        exit(-1);
    }

    std::vector<char> zycie;

    while(getline(plik,linia)){

        if(licznik<=10 && licznik>0){
            zycie.push_back(linia[2]);
        }
        else if(licznik > 10){
            zycie.push_back(linia[3]);
        }
        else if(licznik == 0){
            rozmiarPlanszy = atoi(linia.c_str());
        }

        if(licznik==rozmiarPlanszy){
            for(int i=0; i < rozmiarPlanszy; i++){
                if(zycie[i] == '0'){
                    k[i].SetZycie(false);
                }
                else if(zycie[i] == '1'){
                    k[i].SetZycie(true);
                }
            }
        }
        licznik++;
    }

    plik.close();
}
