#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Actie{
protected:
    const string type;    //kunnen we nog const maken, als we het nooit zouden setten
public:
    Actie();
    Actie(string type);
    Actie(const Actie &a);  //copyconstructor

    string getType();
    virtual ~Actie(){}; //ANDERS KUNNEN WE NIET DYNAMIC CASTEN
    //https://stackoverflow.com/questions/15114093/getting-source-type-is-not-polymorphic-when-trying-to-use-dynamic-cast




};/////////////einde klasse//////////////////////////

    Actie::Actie() : type("onbepaald"){}

    Actie::Actie(string type) : type(type) {}

    Actie::Actie(const Actie &a): type(a.type) {}



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

class Tackle : public Actie{
    private:
        bool correctUitgevoerd;
        bool kaartGekregen;
        string kaartKleur;
    public:
        Tackle();
        Tackle(bool correct);
        Tackle(bool correct, bool kaart, string kaartKleur);
        ~Tackle();

        //getters
        bool getCorrectUitgevoerd();
        bool getKaartGekregen();
        string getKaartKleur();

        //setters
        void setCorrectUitgevoerd(bool b);
        void setKaartGekregen(bool b);
        void setKaartKleur(string kaart);





};/////////////einde klasse//////////////////////////

    Tackle::Tackle() :Actie("tackle"){
        correctUitgevoerd = true;
        kaartGekregen = false;
        kaartKleur = "";
    }

    Tackle::Tackle(bool correct):Actie("tackle") {
        correctUitgevoerd = correct;
        kaartGekregen = false;
        kaartKleur = "";
    }

    Tackle::Tackle(bool correct, bool kaart, string kaartKleur): Actie("tackle") {
        this->correctUitgevoerd = correct;
        this->kaartGekregen = kaart;
        this->kaartKleur = kaartKleur;
    }

    Tackle::~Tackle() {}

    //getters
    bool Tackle::getCorrectUitgevoerd() {return correctUitgevoerd;}
    bool Tackle::getKaartGekregen() {return kaartGekregen;}
    string Tackle::getKaartKleur() {return kaartKleur;}

    //setters
    void Tackle::setCorrectUitgevoerd(bool b) {correctUitgevoerd= b;}
    void Tackle::setKaartGekregen(bool b) {kaartGekregen = b;}
    void Tackle::setKaartKleur(string kaart) {
        if(kaartGekregen){kaartKleur = kaart;}
        else{cout<<"geen kaart gekregen";}
    }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Inworp : public Actie{
    private:
        bool naarTeamSpeler;
    public:
        Inworp();
        Inworp(bool naarTeamSpeler);
        ~Inworp();

        bool getNaarTeamSpeler();
        void setNaarTeamSpeler(bool b);






};/////////////einde klasse//////////////////////////

    Inworp::Inworp() :Actie("inworp"){
        naarTeamSpeler = true;
    }

    Inworp::Inworp(bool naarTeamSpeler) :Actie("inworp"){
        this->naarTeamSpeler = naarTeamSpeler;
    }

    Inworp::~Inworp() {}

    bool Inworp::getNaarTeamSpeler() {return naarTeamSpeler;}
    void Inworp::setNaarTeamSpeler(bool b) {naarTeamSpeler = b;}



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Redding : public Actie{
    private:
        bool gered;
    public:
        Redding();
        Redding(bool gered);
        ~Redding();

        void setGered(bool b);
        bool getGered();

};/////////////einde klasse//////////////////////////

        Redding::Redding():Actie("redding"){
            gered = false;
        }

        Redding::Redding(bool gered):Actie("redding") {
            this->gered = gered;
        }

        Redding::~Redding() {}

        void Redding::setGered(bool b) {gered = b;}
        bool Redding::getGered() {return gered;}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Opraap : public Actie{
    private:
        bool inCarre;
    public:
        Opraap();
        Opraap(bool inCarre);
        ~Opraap();

        void setOpraap(bool b);
        bool getOpraap();
};/////////////einde klasse//////////////////////////

        Opraap::Opraap():Actie("opraap"){
            inCarre = true;
        }

        Opraap::Opraap(bool inCarre):Actie("opraap") {
            this->inCarre = inCarre;
        }

        Opraap::~Opraap(){}

        void Opraap::setOpraap(bool b) {inCarre = b;}

        bool Opraap::getOpraap() {return inCarre;}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

class Speler{

protected:
    vector<Actie*> acties; //heeft een lijst van acties
public:
    const string &getNaam() const;

    const string &getPositie() const;

    int getAantalKmGelopen() const;

    int getAantalPasses() const;

    int getAantalGoedePasses() const;

    int getAantalSchoten() const;

    int getAantalSchotenOpDoel() const;

    int getAantalDoelpunten() const;

    int getAantalKaarten() const;

    int getAantalTackles() const;

    int getAantalInworpen() const;

    int getAantalGoedeInworpen() const;

    int getAantalReddingen() const;

    int getAantalBallenOpgeraapt() const;

protected:
    const string naam;
    const string positie;
    int aantalKmGelopen;
    int aantalPasses;
    int aantalGoedePasses;
    int aantalSchoten;
    int aantalSchotenOpDoel;
    int aantalDoelpunten;
    int aantalKaarten;
    int aantalTackles;
    int aantalInworpen;
    int aantalGoedeInworpen;
    int aantalReddingen;
    int aantalBallenOpgeraapt;

public:
    Speler();   //ok
    Speler(string naam, string positie);    //ok
    Speler(const Speler &sp);   // niet zeker als ok, problemen met de acties
    virtual ~Speler() {  //ok
        //itereren over de acties, deze moeten manueel verwijderd worden aangezien het pointers zijn$
        vector<Actie*>::iterator it;
        for (it = acties.begin(); it!=acties.end(); it++){
            delete (*it);
        }
    }

    void doeActie(Actie* actie){
        acties.push_back(actie);
    }

    void geefPunten(){
        vector<Actie*>::iterator ait;   //actieiterator
        for(ait = acties.begin(); ait != acties.end(); ait++){
            string s = (*ait)->getType();
            if(s=="lopen"){
                Loop *loop;
                loop = dynamic_cast<Loop*> (*ait);

                if(loop != 0){
                    aantalKmGelopen += loop->getAfstand();
                }
            }
            else if(s =="pas"){
                aantalPasses++;
                Pas *pas;
                pas = dynamic_cast<Pas*> (*ait);

                if(pas != 0){
                    if (pas->getGoedePas()){aantalGoedePasses++;}
                }

            }
            else if(s == "schiet"){
                aantalSchoten++;
                Schiet * schiet;
                schiet = dynamic_cast<Schiet*> (*ait);
                if(schiet != 0){
                    if (schiet->getOpDoel()){aantalSchotenOpDoel++;}
                    if (schiet->getBinnen()){aantalDoelpunten++;}
                }
            }
            else if(s=="tackle"){
                aantalTackles++;
                Tackle* tak ;
                tak = dynamic_cast<Tackle*> (*ait);
                if(tak != 0){
                    if(! (tak->getCorrectUitgevoerd())){
                        aantalKaarten++;
                    }
                }
            }
            else if(s=="inworp"){
                aantalInworpen++;
                Inworp *iw;
                iw = dynamic_cast<Inworp*> (*ait);
                if(iw != 0){
                    if(iw->getNaarTeamSpeler()){aantalGoedeInworpen++;}
                }
            }
            else if(s=="redding"){
                Redding *red;
                red = dynamic_cast<Redding*> (*ait);
                if(red != 0){
                    if(red->getGered()){aantalReddingen++;}
                }
            }
            else if(s=="opraap"){
                aantalBallenOpgeraapt++;
            }
            else(cout<<"foute actie");

        }
    }

    void print(){
        cout<<"naam:                 "<<naam<<endl;
        cout<<"positie:              "<<positie<<endl;
        cout<<"aantalkmgelopen :     "<<aantalKmGelopen<<endl;
        cout<<"aantal passes :       "<<aantalPasses<<endl;
        cout<<"aantal goede passes : "<<aantalGoedePasses<<endl;
        cout<<"aantal schoten :      "<<aantalSchoten<<endl;
        cout<<"waarvan op doel :     "<<aantalSchotenOpDoel<<endl;
        cout<<"waarvan binnen :      "<<aantalDoelpunten<<endl;
        cout<<"aantal kaaten :       "<<aantalKaarten<<endl;
        cout<<"aantal tackles :      "<<aantalTackles<<endl;
        cout<<"aantal inworpen :     "<<aantalInworpen<<endl;
        cout<<"aantal reddingen :    "<<aantalReddingen<<endl;
        cout<<"aantal ballen op geraapt: "<<aantalBallenOpgeraapt<<endl;

    }











};/////////////////////////einde klasse///////////////////////////

bool doelmanComparator(Speler *sp1, Speler *sp2){
    return sp1->getAantalReddingen() > sp2->getAantalReddingen();
}

bool aanvallerComparator(Speler *sp1, Speler *sp2){
    return sp1->getAantalDoelpunten() > sp2->getAantalDoelpunten();
}

bool verdedigerComparator(Speler *sp1, Speler *sp2){
    return sp1->getAantalTackles() > sp2->getAantalTackles();
}

bool middenVelderComparator(Speler *sp1, Speler *sp2){
    return sp1->getAantalGoedePasses() >sp2->getAantalGoedePasses();
}

    Speler::Speler(): naam("niemand"),positie("nergens") {
        aantalKmGelopen = 0;
        aantalPasses = 0;
        aantalGoedePasses = 0;
        aantalSchoten = 0;
        aantalSchotenOpDoel = 0;
        aantalDoelpunten = 0;
        aantalKaarten = 0;
        aantalTackles = 0;
        aantalInworpen = 0;
        aantalGoedeInworpen = 0;
        aantalReddingen = 0;
        aantalBallenOpgeraapt = 0;
    }
    Speler::Speler(string naam, string positie): naam(naam),positie(positie) {
        aantalKmGelopen = 0;
        aantalPasses = 0;
        aantalGoedePasses = 0;
        aantalSchoten = 0;
        aantalSchotenOpDoel = 0;
        aantalDoelpunten = 0;
        aantalKaarten = 0;
        aantalTackles = 0;
        aantalInworpen = 0;
        aantalGoedeInworpen = 0;
        aantalReddingen = 0;
        aantalBallenOpgeraapt = 0;
    }


const string &Speler::getNaam() const {
    return naam;
}

const string &Speler::getPositie() const {
    return positie;
}

int Speler::getAantalKmGelopen() const {
    return aantalKmGelopen;
}

int Speler::getAantalPasses() const {
    return aantalPasses;
}

int Speler::getAantalGoedePasses() const {
    return aantalGoedePasses;
}

int Speler::getAantalSchoten() const {
    return aantalSchoten;
}

int Speler::getAantalSchotenOpDoel() const {
    return aantalSchotenOpDoel;
}

int Speler::getAantalDoelpunten() const {
    return aantalDoelpunten;
}

int Speler::getAantalKaarten() const {
    return aantalKaarten;
}

int Speler::getAantalTackles() const {
    return aantalTackles;
}

int Speler::getAantalInworpen() const {
    return aantalInworpen;
}

int Speler::getAantalGoedeInworpen() const {
    return aantalGoedeInworpen;
}

int Speler::getAantalReddingen() const {
    return aantalReddingen;
}

int Speler::getAantalBallenOpgeraapt() const {
    return aantalBallenOpgeraapt;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class Keeper: public Speler {
public:
    Keeper(string naam):Speler(naam, "keeper"){}
    ~Keeper(){};
};
class Verdediger : public Speler {
public:
    Verdediger(string naam):Speler(naam, "verdediger"){};
    ~Verdediger(){};
};
class Middenvelder : public Speler {
public:
    Middenvelder(string naam ):Speler(naam,"middenvelder"){};
    ~Middenvelder(){};
};
class Aanvaller : public Speler {
public:
    Aanvaller(string naam):Speler(naam,"aanvaller"){};
    ~Aanvaller(){};
};


class Trainer{
private:
    vector<Speler*> spelers;

public:
    Trainer(){}
    ~Trainer(){
        //de vectorLijst moet gedelete worden
        vector<Speler*>::iterator it;
        for(it = spelers.begin(); it != spelers.end(); it++){
            delete (*it);
        }
    };

    void voegSpelerToe(Speler *sp){
        spelers.push_back(sp);
    }

    void geefPunten(){
        //grote methode man
        vector<Speler*>::iterator it;
        for(it = spelers.begin(); it!= spelers.end(); it++){

            (*it)->geefPunten();
        }

    }


    vector<Speler*> neemBesteSpeler(string typeSpeler, int aantal) {

        vector<Speler*> spelersVanDeSoort;
        vector<Speler*>::iterator it;
        if(typeSpeler =="keeper"){  // meeste aantal reddingen
            Keeper *keep;
            for(it = spelers.begin(); it != spelers.end(); it++){
                keep = dynamic_cast<Keeper*> (*it);
                if(keep !=0){
                    spelersVanDeSoort.push_back(keep);
                }
            }

            sort(spelersVanDeSoort.begin(), spelersVanDeSoort.end(), doelmanComparator);
            spelersVanDeSoort.resize(aantal);
            return spelersVanDeSoort;
        }
        else if(typeSpeler =="middenvelder"){
            Middenvelder* mdv;
            for(it = spelers.begin(); it !=spelers.end(); it++){
                mdv = dynamic_cast<Middenvelder*> (*it);
                if(mdv != 0){
                    spelersVanDeSoort.push_back(mdv);
                }
            }

            sort(spelersVanDeSoort.begin(), spelersVanDeSoort.end(), middenVelderComparator);
            spelersVanDeSoort.resize(aantal);
            return spelersVanDeSoort;

        }
        else if(typeSpeler =="verdediger"){
            Verdediger *vd;
            for(it = spelers.begin(); it !=spelers.end(); it++){
                vd = dynamic_cast<Verdediger*> (*it);
                if(vd != 0){
                    spelersVanDeSoort.push_back(vd);
                }
            }

            sort(spelersVanDeSoort.begin(), spelersVanDeSoort.end(), verdedigerComparator);
            spelersVanDeSoort.resize(aantal);
            return spelersVanDeSoort;


        }
        else if(typeSpeler =="aanvaller"){
            Aanvaller *av;
            for(it = spelers.begin(); it !=spelers.end(); it++){
                av = dynamic_cast<Aanvaller*> (*it);
                if(av != 0){
                    spelersVanDeSoort.push_back(av);
                }
            }
            sort(spelersVanDeSoort.begin(), spelersVanDeSoort.end(), aanvallerComparator);
            spelersVanDeSoort.resize(aantal);
            return spelersVanDeSoort;

        }

        //nu bevat de array allemaal spelers van hetzelfde type



    }
};



int main() {

    //echte main begint vanaf hier
    Trainer* trainer = new Trainer();

    //nu telkens spelers maken, en hen kenmerken toe eisen, dan speler toevoegen aan de lijst
    Keeper *k1 = new Keeper("thibaut courtois");
    k1->doeActie(new Loop(0,0,10,15));
    k1->doeActie(new Redding(true));
    k1->doeActie(new Redding(false));
    k1->doeActie(new Redding(false));
    k1->doeActie(new Opraap(true)); //in de carré = true;
    trainer->voegSpelerToe(k1);

    Keeper *k2 = new Keeper("koen kasteels");
    k2->doeActie(new Redding(true));
    k2->doeActie(new Redding(false));
    k2->doeActie(new Redding(true));

    k2->doeActie(new Inworp(true)); //naar team speler
    k2->doeActie(new Inworp(false));
    k2->doeActie(new Pas(true));    //goede pas= true
    k2->doeActie(new Loop(1,2,9,9));
    trainer->voegSpelerToe(k2);

    Verdediger *v1 = new Verdediger("vincent kompany");
    v1->doeActie(new Loop(10,30,50,20));
    v1->doeActie(new Tackle(true));
    v1->doeActie(new Tackle(true));
    v1->doeActie(new Tackle(false));
    v1->doeActie(new Pas(true));
    trainer->voegSpelerToe(v1);

    Verdediger *v2 = new Verdediger("marc vertongen");
    v1->doeActie(new Loop(10,30,50,20));
    v1->doeActie(new Tackle(true));
    v1->doeActie(new Tackle(false,true,"rood"));
    v1->doeActie(new Tackle(false,true,"geel"));
    v1->doeActie(new Pas(false));
    trainer->voegSpelerToe(v1);

    Middenvelder *mdv1 = new Middenvelder("axel witsel");
    mdv1->doeActie(new Pas(true));
    mdv1->doeActie(new Pas(true));
    mdv1->doeActie(new Loop(3,3,5,9));
    mdv1->doeActie(new Schiet(true,false));
    mdv1->doeActie(new Schiet(true, true));
    mdv1->doeActie(new Tackle(false,true,"geel"));
    trainer->voegSpelerToe(mdv1);

    Middenvelder *mdv2 = new Middenvelder("kevin debruyne");
    mdv1->doeActie(new Pas(true));
    mdv1->doeActie(new Pas(true));
    mdv1->doeActie(new Loop(3,3,5,40));
    mdv1->doeActie(new Schiet(true,true));
    mdv1->doeActie(new Schiet(true, true));
    mdv1->doeActie(new Tackle(true));
    trainer->voegSpelerToe(mdv2);

    Middenvelder *mdv3 = new Middenvelder("nacer chadli");
    mdv1->doeActie(new Pas(false));
    mdv1->doeActie(new Pas(false));
    mdv1->doeActie(new Loop(3,1,5,9));
    mdv1->doeActie(new Schiet(true,false));
    mdv1->doeActie(new Schiet(true, false));
    mdv1->doeActie(new Tackle(false,true,"rood"));
    trainer->voegSpelerToe(mdv3);

    Aanvaller *av1 = new Aanvaller("romelu lukaku");
    av1->doeActie(new Pas(true));
    av1->doeActie(new Schiet(true, true));
    av1->doeActie(new Loop(5,5,21,21));
    av1->doeActie(new Tackle(true));
    av1->doeActie(new Inworp(true));
    trainer->voegSpelerToe(av1);

    Aanvaller *av2 = new Aanvaller("batschiaui");
    av1->doeActie(new Pas(false));
    av1->doeActie(new Schiet(false, false));
    av1->doeActie(new Loop(5,5,21,9));
    av1->doeActie(new Tackle(false,true,"geel"));
    av1->doeActie(new Inworp(false));
    trainer->voegSpelerToe(av2);

    trainer->geefPunten();
    vector<Speler*> besteKeeper = trainer->neemBesteSpeler("keeper",1); //    Keeper : op aantalSaves die gered zijn
    vector<Speler*> besteAanvaller = trainer->neemBesteSpeler("aanvaller",1); //    Aanvaller : op aantalDoelpunten
    vector<Speler*> besteMiddenVelders = trainer->neemBesteSpeler("middenvelder",2); //    Middenvelder: op aantalGoedePasses
    vector<Speler*> besteVerdedigers = trainer->neemBesteSpeler("verdediger",2); //    Verdediger : op aantal Tackles

    vector<Speler*>::iterator it;
    cout<<endl;
    cout<<endl;
    cout<<"printen van de beste keepers"<<endl;
    for(it = besteKeeper.begin(); it != besteKeeper.end(); it++){
        (*it)->print();
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<"printen van de beste aanvallers"<<endl;
    for(it = besteAanvaller.begin(); it != besteAanvaller.end(); it++){
        (*it)->print();
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<"printen van de beste middenvelders"<<endl;
    for(it = besteMiddenVelders.begin(); it != besteMiddenVelders.end(); it++){
        (*it)->print();
        cout<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<"printen van de beste verdedigers"<<endl;
    for(it = besteVerdedigers.begin(); it != besteVerdedigers.end(); it++){
        (*it)->print();
        cout<<endl;
    }


    // debuggen om te kijken wat er in zit
    cout<<"gelukt"<<endl;













    return 0;


}