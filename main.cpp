#include <iostream>
#include "komorka.h"
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

int wymiarPlanszyX();
int wymiarPlanszyY();

int main()
{
    int zapis;
    int licznik=0;
    int wymiarX = wymiarPlanszyX();
    int wymiarY = wymiarPlanszyY();

    bool gameover=false;
    bool otworz_zapis=false;

    Plansza p1(wymiarX, wymiarY);

    cout << "Czy chcesz wczytac zapis? (1/0): ";
    cin >> zapis;

    if(zapis == 1){
        otworz_zapis=true;
    }

    sleep(2);
    system("clear");

    //p1.k[15].SetZycie(true);
    //p1.k[16].SetZycie(true);
    //p1.k[17].SetZycie(true);
    //p1.k[12].SetZycie(true);

    while(gameover == false){

        if(otworz_zapis == true){
            p1.WczytajZPliku();

            otworz_zapis=false;
        }

        p1.WypiszPlansze();
        p1.SprawdzPlansze();
        cout << licznik << "\n";

        if(licznik%10 == 0){
            p1.ZapiszDoPliku();
        }

        sleep(1);
        system("clear");

        licznik++;
    }

    return 0;
}
