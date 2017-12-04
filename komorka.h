#include <vector>

class Komorka{

    int wspY;
    int wspX;
    bool czyZyje;

    public:
    void SetX(int);
    void SetY(int);
    int GetX();
    int GetY();
    bool GetZycie();
    void SetZycie(bool);
};

class Plansza : public Komorka{

    int dlugoscX;
    int dlugoscY;

    public:
    std::vector<Komorka> k;

    void WypiszPlansze();
    void SprawdzPlansze();
    Plansza(int, int);
    void PoszerzPlansze(int dlugoscX, int dlugoscY);
    void ZapiszDoPliku();
    void WczytajZPliku();
};
