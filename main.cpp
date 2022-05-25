#include <iostream>
class Autoturism {
protected:
    float lungime;
    int nr_persoane;
    bool mic_litraj = false, masini_usor_df = false, van = false;
public:
    explicit Autoturism(float Lungime = 4, int Nr_persoane = 4) {
        lungime = Lungime;
        nr_persoane = Nr_persoane;
    }
    Autoturism(Autoturism &A) {
        lungime = A.lungime;
        nr_persoane = A.nr_persoane;
    }
    virtual ~Autoturism() = default;
    virtual void citire(std::istream &is) = 0;
    virtual void afisare(std::ostream &os) = 0;
    void setLungime (float valoare) {
        this -> lungime = valoare;
    }
    float getLungime () const {
        return this -> lungime;
    }
    void setLitraj (bool valoare) {
        mic_litraj = valoare;
    }
    bool getLitraj () const {
        return this -> mic_litraj;
    }
    void setNrP (int valoare) {
        nr_persoane = valoare;
    }
    int getNrP () const {
        return this -> nr_persoane;
    }
    void setMUDF (bool valoare) {
        masini_usor_df = valoare;
    }
    bool getMUDF () const {
        return this -> masini_usor_df;
    }
    void setVan(bool valoare) {
        van = valoare;
    }
    bool getVan() const {
        return this -> van;
    }
};
class Mini: public Autoturism {
public:
    explicit Mini(float lungime = 3.5, int nr_persoane = 4):Autoturism(lungime, nr_persoane) {
        setLitraj(true);
    };
    Mini(Mini &M)  : Autoturism(M) {
        this -> setLungime(M.getLungime());
        this -> setNrP(M.getNrP());
        this -> setLitraj(M.getLitraj());
    }
    void citire (std::istream &is) override {
        float x;
        int y;
        std::cout <<"\nIntroduceti lungimea: ";
        is >> x;
        std::cout <<"\nIntroduceti numarul de persoane: ";
        is >> y;
        this -> setLungime(x);
        this -> setNrP(y);
    }
    void afisare(std::ostream &os) override {
        os << "Tip masina: Mini \n" << "Lungime: " << getLungime() << "\nNumar persoane: " << getNrP() << "\n";
    }

    friend std::ostream &operator<<(std::ostream &os, Mini mini) {
        mini.afisare(os);
        return os;
    }
};
class Compacta: public Autoturism {
public:
    explicit Compacta(float lungime = 4.2, int nr_persoane = 5):Autoturism(lungime, nr_persoane) {
        setMUDF(true);
    };
    Compacta(Compacta &CP)  : Autoturism(CP) {
        this -> setLungime(CP.getLungime());
        this -> setNrP(CP.getNrP());
        this -> setMUDF(CP.getMUDF());
    }
    void citire (std::istream &is) override {
        float x;
        int y;
        std::cout <<"\nIntroduceti lungimea: ";
        is >> x;
        std::cout <<"\nIntroduceti numarul de persoane: ";
        is >> y;
        this -> setLungime(x);
        this -> setNrP(y);
    }
    void afisare(std::ostream &os) override {
        os << "Tip masina: Compacta \n" << "Lungime: " << getLungime() << "\nNumar persoane: " << getNrP() << "\n";
    }

    friend std::ostream &operator<<(std::ostream &os, Compacta &CP) {
        CP.afisare(os);
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Compacta &CP) {
        CP.citire(is);
        return is;
    }
};
class Monovolum: public Autoturism {
    bool nou = true;
public:
    explicit Monovolum(float lungime = 5, int nr_persoane = 6, bool nou = true): Autoturism(lungime, nr_persoane) {
        setVan(true);
        this -> nou = nou;
    }
    void setNou (bool valoare) {
        nou = valoare;
    }
    bool getNou() const {
        return this -> nou;
    }
    void citire (std::istream &is) override {
        float x;
        int y;
        bool valoaren;
        std::cout <<"\nIntroduceti lungimea: ";
        is >> x;
        std::cout <<"\nIntroduceti numarul de persoane: ";
        is >> y;
        std::cout <<"\nSpuneti daca masina este noua sau nu: ";
        is >> valoaren;
        std::cout <<"\n";
        this -> setLungime(x);
        this -> setNrP(y);
        this -> setNou(valoaren);
    }
    Monovolum(Monovolum &M)  : Autoturism(M) {
        this -> setLungime(M.getLungime());
        this -> setNrP(M.getNrP());
        this -> setVan(M.getVan());
        this -> setNou(M.getNou());
    }
    void afisare(std::ostream &os) override {
        os << "Tip masina: Monovolum \n" << "Lungime: " << getLungime() << "\nNumar persoane: " << getNrP() << "\n"
           << "Este nou?: " << nou <<"\n";
    }

    friend std::ostream &operator<<(std::ostream &os, Monovolum &M) {
        M.afisare(os);
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Monovolum &M) {
        M.citire(is);
        return is;
    }
};
int main() {
//    Mini M;
//    M.citire(std::cin);
//    M.afisare(std::cout);
//    Mini M2(M);
//    M2.afisare(std::cout);
//    std::cout << "\n";
//    Compacta C;
//    C.citire(std::cin);
//    C.afisare(std::cout);
    Monovolum MV;
    MV.citire(std::cin);
    MV.afisare(std::cout);

    return 0;
}
