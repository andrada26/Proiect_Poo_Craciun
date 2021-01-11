#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
#include <stdio.h>
#include <iterator>
#include <sstream>

#define Nr_Copii_Max 6
#define V 7 // numarul de noduri din graf ( cele 6 orase + nodul 0 = orasul Rovaniemi)

using namespace std;

class Scrisori
{
protected: //INCAPSULARE
    string nume;
    string prenume;
    int varsta;
    string oras;
    string wishlist;
    string culoare_plic;

public:
    //settersi  // INCAPSULARE
    void set_nume(string nume)
    {
        this->nume = nume;
    }
    void set_prenume(string prenume)
    {
        this->prenume = prenume;
    }
    void set_varsta(int varsta)
    {
        this->varsta = varsta;
    }
    void set_oras(string oras)
    {
        this->oras = oras;
    }
    void set_wishlist(string wishlist)
    {
        this->wishlist = wishlist;
    }
    void set_culoare_plic(string culoare_plict)
    {
        this->culoare_plic = culoare_plic;
    }

    //gettersi //INCAPSULARE
    string arata_nume()
    {
        return this->nume;
    }
    string arata_prenume()
    {
        return this->prenume;
    }
    int arata_varsta()
    {
        return this->varsta;
    }
    string arata_oras()
    {
        return this->oras;
    }
    string arata_wishlist()
    {
        return this->wishlist;
    }
    string arata_culoare_plic()
    {
        return this->culoare_plic;
    }

    Scrisori() {} // constructor fara parametru                                       // overloading - POLIMORFISM

    Scrisori(string nm, string pn, int vt, string oras, string wl, string c_p) // constructor cu parametrii definit in interiorul clasei
    {
        this->nume = nm;
        this->prenume = pn;
        this->varsta = vt;
        this->oras = oras;
        this->wishlist = wl;
        this->culoare_plic = c_p;
    }

    ~Scrisori(); // declarare de destructor
};
Scrisori::~Scrisori(void)
{ // definire destructor in afara clasei care nu afiseaza nimic pentru ca ar arata urat :)
    ;
}

class Polul_Nord_Sarcini //ABSTRACTIZARE //nu aveam alta idee de a integra o clasa abstracta,deoarece ma impiedica faptul ca aceasta clasa nu va putea fi instantiata pe motiv ca este abstracta
{
public:
    virtual void creare_purtare() = 0; //virtual void function()=0 => clasa abstracta
    virtual void acordare_cadouri() = 0;
    ~Polul_Nord_Sarcini() {} // declarare de destructor
};

vector<Scrisori> Letters; // declaram vectorul variabila globala pentru a ne fi mai
//usor sa lucram cu el in functii (fara a-l trimite parametru)

class Evidenta_Orase
{
public:
    string oras1;
    string oras2;
    float kilometri;

    Evidenta_Orase(string o1, string o2, float k)
    {
        this->oras1 = o1;
        this->oras2 = o2;
        this->kilometri = k;
    }
};

class Elfi : public Scrisori, public Polul_Nord_Sarcini //MULTIPLE INHERITANCE
{
public:
    vector<string> purtare;
    vector<string> lista_cadouri;
    vector<Evidenta_Orase> lista_orase;
    vector<int> lista_acadele;
    string cadou_default_copil_cuminte = " Telefon"; //setam cadou default in valoare de 100$ pentru copiii cuminti care nu au pus nimic pe wishlist.ul lor
    string cadou_default_copil_obraznic = " Carte";  //setam cadou default in valoare de 10$ pentru copiii obraznici care nu au pus nimic pe wishlist.ul lor
    int buget;

    Elfi() {}                                                                      // overloading - POLIMORFISM
    Elfi(string nm, string pn, int vt, string oras, string wl, string c_p, int bg) // overloading - POLIMORFISM
    {
        this->nume = nm;
        this->prenume = pn;
        this->varsta = vt;
        this->oras = oras;
        this->wishlist = wl;
        this->culoare_plic = c_p;
        this->buget = bg;
    }

    int arata_buget()
    {
        return this->buget;
    }

    void creare_purtare() // facem overriding la functia virtuala => clasa elfi NU este la randul ei abstracta
    {
        try // EXCEPTIONS
        {
            ifstream Evidenta_Purtare("Lista_copii_cuminti_obraznici.txt");
            int i = 0;

            string p;
            if (Evidenta_Purtare.is_open())
            {

                while (getline(Evidenta_Purtare, p, ' '))
                {
                    purtare.push_back(p);
                    cout << purtare[i++] << endl;
                }

                Evidenta_Purtare.close();
            }
            else
                throw "NU PUTEM DESCHIDE BAZA DE DATE A Purtarilor!!EROARE2!";
        }
        catch (const char *eroare2)
        {
            cout << eroare2 << endl;
            exit(1);
        }
    }

    void acordare_cadouri() // facem overriding la functia virtuala => clasa elfi NU este la randul ei abstracta
    {

        int pret;
        string cadou_gasit, cadou, pr, nr;

        for (int i = 0; i < Letters.size(); i++)
        {
            string lista = ""; //pentru fiecare copil reinitializam lista de cadouri dorite si gasite in inventarul
            int acadele = 0;   //pentru fiecare copil reinitializam numarul de acadele

            if (purtare[i] == "Cuminte") //setarea bugetului
                this->buget = 100;
            else
                this->buget = 10;

            if (Letters[i].arata_wishlist() == "" && purtare[i] == "Cuminte") //acordarea cadoului default - copil cuminte fara wishlist
            {
                lista_cadouri.push_back(cadou_default_copil_cuminte);
                lista_acadele.push_back(0);
                cout << endl;
                cout << "Copilul " << i + 1 << " are wishlist-ul gol => primeste cadou default pentru copil cuminte." << endl;
            }

            else if (Letters[i].arata_wishlist() == "" && purtare[i] == "Obraznic") //acordarea cadoului default - copil obraznic fara wishlist
            {
                lista_cadouri.push_back(cadou_default_copil_obraznic);
                lista_acadele.push_back(0); //deoarece cadourile default valoareaza exact cat bugetul in functie de purtare elfii trebuie sa stie sa nu mai ofere acadele pentru acest copil
                cout << endl;
                cout << "Copilul " << i + 1 << " are wishlist-ul gol => primeste cadou default pentru copil obraznic." << endl;
            }
            else
            // pentru fiecare copil se deschide inventaru pentru a acorda cadourile specifice fiecaruia in ordinea aparuta pe scrisori
            {

                istringstream wishlist(Letters[i].arata_wishlist());
                ifstream Evidenta_Cadouri;

                cout << endl;
                cout << "Copilul " << i + 1 << " cu bugetul " << this->buget << ":" << endl; //Afisam pentru ce copil se fac cautarile

                while (getline(wishlist, cadou, ' ')) //spargem wishlist.ul dupa caracterul " " si cautam fiecare obiect dorit in inventar
                {
                    Evidenta_Cadouri.open("Lista_Cadouri_Inventar.txt");
                    cout << "Se cauta cadoul " << cadou << " in inventarul elfilor....." << endl;

                    while (getline(Evidenta_Cadouri, cadou_gasit, ' ')) //cadou existent in inventar
                    {

                        getline(Evidenta_Cadouri, pr); //pretul cadoului din inventar

                        pret = stoi(pr);

                        if (cadou == cadou_gasit)
                        {
                            cout << "Am gasit cadoul " << cadou << " pe care copilul " << i + 1 << " il doreste si costa " << pret << "." << endl; //cout.uri create pentru verificare
                            cout << "Bugetul copilul este in prezent " << this->buget << "." << endl;

                            if (pret > this->buget || this->buget == 0) // daca pretul cadoului curent depaseste bugetul actual se iese din while.uri si se atribuie acadele corespunzator
                            {
                                cout << "S-a depasit bugetul pentru copilul " << i + 1 << "." << endl;
                                goto buget_depasit;
                            }
                            else
                            {
                                cout << "Copilul isi permite acest cadou => ";
                                cout << "cadoul " << cadou_gasit << " s-a adaugat." << endl;
                                lista = lista + " " + cadou_gasit;
                                this->buget = this->buget - pret;
                                cout << "Bugetul dupa adugarea cadoului este " << this->buget << "." << endl;
                            }

                        } //inchiere if (cadou == cadou_gasit)
                    }     // inchiere while (getline(Evidenta_Cadouri, cadou_gasit, ' '))
                    Evidenta_Cadouri.close();
                } // inchiere while (getline(sin, cadou, ' '))
            buget_depasit:

                if (lista == "") //Dacă ce e pe listă depășește bugetul( si nu exista niciun alt cadou dorit care sa nu se incadreze in buget) se va da un cadou default care valorează fix 100$ sau 10$ în funcție de copil.
                {
                    cout << "Pregatire cadou default.." << endl;
                    if (purtare[i] == "Obraznic")
                        lista_cadouri.push_back(cadou_default_copil_obraznic);
                    else
                        lista_cadouri.push_back(cadou_default_copil_cuminte);

                    lista_acadele.push_back(0);
                } //incheiere if(lista=="")
                else
                {
                    cout << "Lista cu cadouri creata in while este:" << lista << endl;
                    lista_cadouri.push_back(lista);

                    if (this->buget != 0)
                    {
                        while (this->buget != 0)
                        {
                            acadele++;
                            this->buget = this->buget - 1;
                        }

                        lista_acadele.push_back(acadele);
                    }
                    else if (this->buget == 0)
                        lista_acadele.push_back(0);
                } //incheiere else

                // } //incheiere if (Evidenta_Cadouri.is_open())

            } //incheiere else
        }     //incheiere for
              //incheiere try

    } //incheiere metoda acordare_cadouri()

    void creare_lista_orase()
    { //elfi au o harta cu toate orasele din belgia(tara unde lucreaza mosul:) )
        try
        {
            string oras_1, oras_2, km;
            float kilometri;
            ifstream Evidenta_Drum("Lista_kilometri_orase.txt");

            if (Evidenta_Drum.is_open())
            {
                while (getline(Evidenta_Drum, oras_1, ' '))
                {
                    getline(Evidenta_Drum, oras_2, ' ');
                    getline(Evidenta_Drum, km);

                    kilometri = stof(km);

                    Evidenta_Orase Oras(oras_1, oras_2, kilometri);
                    lista_orase.push_back(Oras);
                } // incheiere while fisier
                Evidenta_Drum.close();
            } //incheiere if (Evidenta_Drum.is_open())
            else
                throw "NU PUTEM DESCHIDE BAZA DE DATE A Oraselor !!EROARE4!";
        } //incheiere try
        catch (const char *eroare4)
        {
            cout << eroare4 << endl;
            exit(1);
        }
    } //incheiere metoda creare_lista_orase()

    friend class Troli;        //Elfii dau mai departe lista cu cadouri trolilor.
    friend class Doamna_Claus; //Elfii dau mai departe numărul de acadele Doamnei Crăciun.
    friend class Domnul_Claus; //Elfii dau mai departe lista cu orașe lui Moș Crăciun.
};

vector<Elfi> Noua_Evidenta; // noul vector va avea pe langa atributele din clasa Srisori si atributele din clasa Elfi

class Troli
{
public:
    int nr_carbuni = 0;
    int ambalaje_fete = 0;
    int ambalaje_baieti = 0;

    void impachetare(Elfi *elf) //Trolii primesc de la elfi lista cu cadouri
    {
        for (int i = 0; i < Noua_Evidenta.size(); i++)
        {
            if (Noua_Evidenta[i].arata_culoare_plic() == "roz")
            {
                this->ambalaje_fete++;

                if (elf->purtare[i] == "Obraznic")
                {
                    this->nr_carbuni++;
                    cout << "Cadoul lui " << Noua_Evidenta[i].arata_nume() << " " << Noua_Evidenta[i].arata_prenume() << " :" << elf->lista_cadouri[i] << " a fost impachetat in ambalaj roz!";
                    cout << "(contine carbune..)" << endl;
                }
                else
                    cout << "Cadoul lui " << Noua_Evidenta[i].arata_nume() << " " << Noua_Evidenta[i].arata_prenume() << " :" << elf->lista_cadouri[i] << " a fost impachetat in ambalaj roz!" << endl;
            }
            else if (Noua_Evidenta[i].arata_culoare_plic() == "albastru")
            {
                this->ambalaje_baieti++;

                if (elf->purtare[i] == "Obraznic")
                {
                    this->nr_carbuni++;
                    cout << "Cadoul lui " << Noua_Evidenta[i].arata_nume() << " " << Noua_Evidenta[i].arata_prenume() << " :" << elf->lista_cadouri[i] << " a fost impachetat in ambalaj albastru!";
                    cout << "(contine carbune..)" << endl;
                }
                else
                    cout << "Cadoul lui " << Noua_Evidenta[i].arata_nume() << " " << Noua_Evidenta[i].arata_prenume() << " :" << elf->lista_cadouri[i] << " a fost impachetat in ambalaj albastru!" << endl;
            }

        } //incheiere for
    }

    ~Troli() {}                // declarare de destructor
    friend class Doamna_Claus; //Trolii dau mai departe numărul de carbuni Doamnei Crăciun.
};

//  DIJKSTRA'S SHORTEST PATH ALGORITHM

//functie care determina nodul cu cel mai scurt drum fata de sursa
int minDistance(float dist[], bool sptSet[])
{
    //Initializam valoarea lui min ca fiind cea mai mare valoare posibila in cazul variabilelor float
    float min = __FLT_MAX__, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
// functie pentru afisarea vectorului de distante dist[] creat anterior
void printSolution(float dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %f\n", i, dist[i]);
}
//functie care implementeaza Dijkstra algoritm pentru determinarea celui mai scurt drum intre doua noduri
//afalate intr-un graf reprezentat folosind lista de adiacenta
void dijkstra(float graph[V][V], int sursa, float dist[])
{
    // dist[i] va retine cea mai scurta distanta de la sursa la nodul i

    bool sptSet[V]; // sptSet[i] va fi "true" daca nodul i este inclus in drumul cel mai scurt realizat de la sursa la i

    //  initializam toate distantele infinit si stpSet[] drept "false"
    for (int i = 0; i < V; i++)
        dist[i] = __FLT_MAX__, sptSet[i] = false;

    // distanta de la sursa la sursa va fi intotdeauna
    dist[sursa] = 0;

    //cautam cea mai scurta distanta pentru toate noduri
    for (int count = 0; count < V - 1; count++)
    {
        // Alegem nodul cu distanța minima din setul de noduri neprocesate inca
        //  u este întotdeauna egal cu sursa în prima iterație
        int u = minDistance(dist, sptSet);

        //nodul ales trebuie figurat ca si "vizitat"
        sptSet[u] = true;

        // Actualizam valoarea dist a vârfurilor adiacente vârfului ales
        for (int v = 0; v < V; v++)

            // Actualizam dist[v] numai dacă nu este în sptSet, există acces de la
            // u la v, iar costul total al drumului de la sursa la v prin u este
            // mai mic decât valoarea curentă a dist [v]
            if (!sptSet[v] && graph[u][v] && dist[u] != __FLT_MAX__ && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}
int urmatorul_nod(float dist[], int vizitat[])
{
    float min = __FLT_MAX__;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] < min && vizitat[i] == 0)
            min = dist[i];
    }
    for (int i = 0; i < V; i++)

        if (dist[i] == min)
            return i;
}

class Domnul_Claus
{
public:
    float graph[V][V] = {0.0};
    float dist[V];
    int vizitat[V] = {0};
    int parcurgere[V];
    int varf;
    float suma = 0.00;
    vector<string> corespondenta_orase_cu_noduri;

    void creare_corespondenta_orase_cu_noduri() // cream corespondenta intre noduri si orase pentru a afisa calea mai frumos:)
    {
        corespondenta_orase_cu_noduri.push_back("Rovaniemi"); // nod 0 = Rovaniemi
        corespondenta_orase_cu_noduri.push_back("Louvain");   // nod 1 = Louvain
        corespondenta_orase_cu_noduri.push_back("Bruxelles"); // nod 2 = Bruxelles
        corespondenta_orase_cu_noduri.push_back("Charleroi"); // nod 3 = Charleroi
        corespondenta_orase_cu_noduri.push_back("Namur");     // nod 4 = Namur
        corespondenta_orase_cu_noduri.push_back("Ronse");     // nod 5 = Ronse
        corespondenta_orase_cu_noduri.push_back("Bruges");    // nod 6 = Bruges
    }

    void creare_matrice_adiacenta(Elfi *elf)
    {
        int i, j = 0, k = 0, l = 0;
        for (i = 0; i < V; i++)
        { //stim ca incepem cu orasul rovaniemi asa ca am creat vectorul incepand cu acest oras care reprezinta orasul plecare
            for (j = i; j < V; j++)
            {
                if (i != j)
                {
                    graph[i][j] = elf->lista_orase[k].kilometri;
                    k++;
                }
            }
        }
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                graph[j][i] = graph[i][j];
            }
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }
    }

    void aflare_drum_minim()
    {
        for (int i = 0; i < V; i++)
        {
            if (i == 0)
            {
                cout << "Cititi nodul din care doriti sa incepeti parcurgerea" << endl;
                cin >> varf;
                cout << "pentru nodul " << varf << " se aplica distanta dijkstra:" << endl;
                dijkstra(graph, varf, dist);
                parcurgere[i] = varf;
                vizitat[varf] = 1;
                i++;
            }
            int nod_urmator = urmatorul_nod(dist, vizitat);
            parcurgere[i] = nod_urmator;
            suma = suma + dist[nod_urmator];
            cout << endl;
            cout << "pentru nodul " << nod_urmator << " se aplica distanta dijkstra:" << endl;
            dijkstra(graph, nod_urmator, dist);
            vizitat[nod_urmator] = 1;
        }
        cout << "S a plecat din ";
        for (int i = 0; i < V; i++)
        {
            cout << "nodul " << parcurgere[i] << " (orasul " << corespondenta_orase_cu_noduri[i] << " ) -> ";
        }
        cout << "IN TOTAL s-au parcurs " << suma << " kilometri." << endl;
    }
    friend class Doamna_Claus; //Mos Craciun impartaseste traseul lui cu Doamna Crăciun.
};

class Doamna_Claus
{
public:
    int total_carbuni;
    int total_acadele;

    void impartasire_drum(Domnul_Claus *Craciun)
    {
        Craciun->aflare_drum_minim();
        cout << endl;
        cout << "Santa Claus a impartasit drumul lui cu Doamna Claus!" << endl;
    }
    void calculare_acadele(Elfi *elf)
    {
        int suma = 0;
        for (int i = 0; i < elf->lista_acadele.size(); i++)
            suma = suma + elf->lista_acadele[i];
        this->total_acadele = suma;
    }

    void calculare_carbuni(Troli *trol)
    {
        this->total_carbuni = trol->nr_carbuni;
    }

    template <class T>
    T calculare_buget(T aux1, T aux2)
    {
        T aux3 = aux1 * aux2;
        return aux3;
    }

    void calculare_buget_total(int buget_acadele, float buget_carbuni)
    {
        cout << "Doamna Craciun calculeaza: " << endl;
        cout << this->total_acadele << " x  1$ + " << this->total_carbuni << " x 0.5$ =>";
        cout << " Bugetul final = " << (float)buget_acadele + buget_carbuni << " $." << endl;
    }
};

int main()
{
    //CITIREA DIN FISIER A SCRISORILOR
    string nume, prenume, oras, wishlist, culoare_plic, varsta;
    ifstream Evidenta_Scrisori("Scrisori_trimise_de_copii.txt");
    try // EXCEPTIONS
    {
        if (Evidenta_Scrisori.is_open())
        {

            while (getline(Evidenta_Scrisori, nume, ','))
            {
                getline(Evidenta_Scrisori, prenume, ',');
                getline(Evidenta_Scrisori, varsta, ',');
                getline(Evidenta_Scrisori, oras, ',');
                getline(Evidenta_Scrisori, wishlist, ',');
                getline(Evidenta_Scrisori, culoare_plic);

                Scrisori scrisori(nume, prenume, stoi(varsta), oras, wishlist, culoare_plic);
                Letters.push_back(scrisori);
            }
            Evidenta_Scrisori.close();
        }
        else
            throw "NU PUTEM DESCHIDE BAZA DE DATE A Scrisorilor!!EROARE1!";
    }
    catch (const char *eroare1)
    {
        cout << eroare1 << endl;
        exit(1);
    }

    //AFISAREA VECTORULUI SCRISORI PENTRU VERIFICARE
    //Observarea vectorului de obiecte pentru verificare
    cout << endl;
    for (int i = 0; i < Letters.size(); i++)
    {

        cout << "Scrisoarea " << i + 1 << " a fost trimisa catre elfi la Polul Nord:" << endl;
        cout << Letters[i].arata_nume() << ",";
        cout << Letters[i].arata_prenume() << ",";
        cout << Letters[i].arata_varsta() << ",";
        cout << Letters[i].arata_oras() << ",";
        cout << Letters[i].arata_wishlist() << ",";
        cout << Letters[i].arata_culoare_plic() << endl;
    }

    //CREAREA VECTORULUI NOUA_EVIDENTA CARE RETINE SI PURTAREA COPIILOR PE LANGA INFORMATIILE DEJA COLECTATE DIN SCRISORI
    Elfi elf;
    cout << endl;
    elf.creare_purtare();

    for (int i = 0; i < Letters.size(); i++)
    {
        if (elf.purtare[i] == "Cuminte")
        {
            Elfi elf2(Letters[i].arata_nume(), Letters[i].arata_prenume(), Letters[i].arata_varsta(), Letters[i].arata_oras(), Letters[i].arata_wishlist(), Letters[i].arata_culoare_plic(), 100);
            Noua_Evidenta.push_back(elf2);
        }
        else
        {
            Elfi elf2(Letters[i].arata_nume(), Letters[i].arata_prenume(), Letters[i].arata_varsta(), Letters[i].arata_oras(), Letters[i].arata_wishlist(), Letters[i].arata_culoare_plic(), 10);
            Noua_Evidenta.push_back(elf2);
        }
    }

    // AFISAREA VECTORULUI NOUA_EVIDENTA PENTRU VERIFICARE
    cout << endl;
    for (int i = 0; i < Noua_Evidenta.size(); i++)
    {

        cout << "Copilul: " << i + 1 << endl;
        cout << Noua_Evidenta[i].arata_nume() << ",";
        cout << Noua_Evidenta[i].arata_prenume() << ",";
        cout << Noua_Evidenta[i].arata_varsta() << ",";
        cout << Noua_Evidenta[i].arata_oras() << ",";
        cout << Noua_Evidenta[i].arata_wishlist() << ",";
        cout << Noua_Evidenta[i].arata_culoare_plic() << ",";
        cout << Noua_Evidenta[i].arata_buget() << endl;
    }

    cout << endl;
    elf.acordare_cadouri();
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "Copilul " << i + 1 << " primeste de la elfi urmatoarele cadouri:  ";
        cout << elf.lista_cadouri[i];
        cout << " ,si " << elf.lista_acadele[i] << " acadele." << endl;
    }

    elf.creare_lista_orase();
    cout << endl;
    cout << "Lista cu orase:" << endl;
    for (int i = 0; i < elf.lista_orase.size(); i++)
        cout << "Din " << elf.lista_orase[i].oras1 << " pana la " << elf.lista_orase[i].oras2 << " sunt " << elf.lista_orase[i].kilometri << " de kilometri." << endl;

    Troli trol;
    cout << endl;
    trol.impachetare(&elf);
    cout << endl;
    cout << "In total s-au folosit " << trol.ambalaje_fete << " ambalaje de fetite si " << trol.ambalaje_baieti << " ambalaje pentru impachetat cadourile baietilor." << endl;

    cout << endl;
    Doamna_Claus Craciunita;
    Craciunita.calculare_acadele(&elf);
    Craciunita.calculare_carbuni(&trol);
    Craciunita.calculare_buget_total(Craciunita.calculare_buget<int>(Craciunita.total_acadele, 1), Craciunita.calculare_buget<float>(Craciunita.total_carbuni, 0.5));

    cout << endl;
    cout << "MATRICEA DE ADIACENTA:" << endl;
    Domnul_Claus Craciun;
    Craciun.creare_matrice_adiacenta(&elf);
    cout << endl;
    Craciun.creare_corespondenta_orase_cu_noduri();
    Craciunita.impartasire_drum(&Craciun);
    //  Craciun.aflare_drum_minim();

    return 0;
}
