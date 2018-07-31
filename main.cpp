#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Actie{
protected:
    const string type;    //kunnen we nog const maken, als we het nooit zouden setten
public:
    Actie();
    Actie(string type);
    Actie(const Actie &a);  //copyconstructor
    ~Actie();
    string getType();





};/////////////einde klasse//////////////////////////

    Actie::Actie() : type("onbepaald"){}

    Actie::Actie(string type) : type(type) {}

    Actie::Actie(const Actie &a): type(a.type) {}

    Actie::~Actie() {}

    string Actie::getType() {return type;}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Loop : public Actie{
private:
    int afstand; //deze niet const aangezien hij misschien geset moet worden
public:
        //constructoren, destructoren
        Loop();
        Loop(int vanx, int vany, int naarx, int naary);
        ~Loop();

        int getAfstand();
        void setAfstand(int vanx, int vany, int naarx, int naary);




};/////////////einde klasse//////////////////////////



        Loop::Loop():Actie("lopen") {
            afstand = 0;
        }

        Loop::Loop(int vanx, int vany, int naarx, int naary):Actie("lopen") {
            int deltaX = naarx - vanx;
            int deltaY = naary - vany;

            int afstandKwadraat = (deltaX * deltaX) + (deltaY * deltaY);
            afstand = sqrt(afstandKwadraat);
        }

        Loop::~Loop() {}

        int Loop::getAfstand() {return afstand;}

        void Loop::setAfstand(int vanx, int vany, int naarx, int naary) {
            int deltaX = naarx - vanx;
            int deltaY = naary - vany;

            int afstandKwadraat = (deltaX * deltaX) + (deltaY * deltaY);

            afstand = sqrt(afstandKwadraat);
        }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Pas : public Actie{
    private:
        bool goedePas;
    public:
        Pas();
        Pas(bool goedePas);
        ~Pas();

        void setPasQualiteit(bool goed);
        bool getGoedePas();

};/////////////einde klasse//////////////////////////

        Pas::Pas() :Actie("pas"){
            goedePas = false;
        }

        Pas::Pas(bool goedePas) :Actie("pas"){
            this->goedePas = goedePas;
        }

        Pas::~Pas() {}

        void Pas::setPasQualiteit(bool goed) {
            goedePas = goed;
        }

        bool Pas::getGoedePas() {
            return goedePas;
        }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Schiet : public Actie{
    private:
        bool opDoel;
        bool binnen;
    public:
        Schiet();
        Schiet(bool opDoel, bool binnen);
        ~Schiet();

        //getters
        bool getOpDoel();
        bool getBinnen();

        //setters
        void setOpDoel(bool b);
        void setBinnen(bool b);



};/////////////einde klasse//////////////////////////

    Schiet::Schiet() :Actie("schiet"){
        opDoel = false;
        binnen = false;
    }

    Schiet::Schiet(bool opDoel, bool binnen) :Actie("schiet"){
        this->opDoel = opDoel;
        this->binnen = binnen;
    }

    Schiet::~Schiet() {}

    bool Schiet::getOpDoel() {return opDoel;}
    bool Schiet::getBinnen() {return binnen;}

    void Schiet::setBinnen(bool b) {binnen = b;}
    void Schiet::setOpDoel(bool b) {opDoel = b;}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Tackle : public Actie{};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Inworp : public Actie{};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Redding : public Actie{};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Opraap : public Actie{};
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


/*class Speler{
private:
    vector<Actie*> acties; //heeft een lijst van acties
    string naam;
    string positie;
public:
    Speler();
    Speler(string naam, string positie);
    Speler(const Speler &sp);
    ~Speler();






};

class Keeper: public Speler {
private:
    int aantalGoalsSaved;
    int aantalGoalsBinnengelaten;
public:

};
class Verdediger : public Speler {};
class Middenvelder : public Speler {};
class Aanvaller : public Speler {};

/*
 * elke speler heeft acties
 *          loop
 *          pas
 *          schiet
 *          takle
 *          inworp
 *          redding
 *          opraap
 *          ...
 *
 * na de wedstrijd: statistieken printen
 *              uit loopacties : aantal gelopen km berekenen
 *              uit schietacties:aantal goals
 *                              aantal schoten op doel
 *                              totaal aantal schoten
 *
 * begin wedstrijd: trainer kan de spelers met meeste aantal punten in de lijst opvragen
 * geeft mee welk type speeler hij wi
 * hij gaat bvb 1x de beste keepers vragen, 4 maal de beste verdediger, .. elke speler krijgt dan ook punten na elke wedstrijd
 *
 */


int main() {
    Actie a();
    Actie *ap = new Actie("lopen");
    string tekste = ap->getType();
    cout<<tekste<<endl;

    Loop l(2,2,4,4);
    cout<<l.getAfstand()<<endl;
    cout<<l.getType()<<endl;

    Loop *l2 = new Loop();
    l2->setAfstand(2,2,4,4);
    cout<<l2->getAfstand()<<endl;

    return 0;
}