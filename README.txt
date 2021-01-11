In acest README o sa incerc pas cu pas sa explic intreg codul meu,
atat implementarea, cat si rularea.

PROIECT POO CRACIUN - ROMAN ANDRADA-LILIANA 321 AC

--------------------------------EXPLICATIE COD-----------------------------------
Cerinta #1 :Moș Crăciun primește scrisori de la copii cu ce își doresc.
 
Fiecare scrisoare conține următoarele atribute:
Nume
Prenume
Vârstă
Oraș
Wishlist (acesta este o listă de mai multe jucării pe care fiecare copil și le dorește)
Culoare plic: roz pentru fetițe și albastru pentru băiețe

REZOLVARE Cerinta #1:

Incep prin a crea o clasa Srisori, cu atributele necesare unei scrisori cerute mai sus.
Citirea scrisorilor se va face din fisierul Scrisori_trimise_de_copii.txt intr-un
vector de obiecte de tip Scrisori.(deci in cazul in  care se vor adauga copii noi
in fisier se vor adauga automat in vector dupa citirea fisierului la inceputul int main.ului)

-6 copii trimit scrisori.

!Vectorul este o variabila globala pentru a-l folosi mai usor in urmatoarele clase unde este
necesar.

In aceasta rezolvare, am acoperit conceptele de CONSTRUCTORI, DESTRUCTORI si de INCAPSULARE =
procesul de combinare a datelor si a functiilor intr-o singura structura ,folosing access
specifier.ul protected pentru atribute si functii publice( includ settersi si gettersi pentru
a accesa atributele protected).
De asemenea, am acoperit si EXCEPTIILE in cazul lucrului cu fisiere.(am ales cea mai usoara
folosire, deoarece nu s-au specificat detalii si nu am dorit sa ma complic)

Cerinta #2 :

-Pentru fiecare copil se acordă un buget, în funcție dacă a fost cuminte sau nu. 
Pentru fiecare copil cuminte se acordă o sumă de 100$, iar pentru unul rău se acordă 10$. 
Elfii au deja o listă cu statusul fiecărui copil ,si anume fisierul 
Lista_copii_cuminti_obraznici.txt unde prima purtare corespunde copilului 1 s.a.m.d 
pana se ajunge la ultimul copil,copilul 6, și se atribuie suma în funcție de acesta.
Aici am creat un alt vector de obiecte tip Elfi care poarta numele Noua_Evidenta care
pe langa atributele din clasa Srisori si va avea si atributele din clasa Elfi(+ buget).
Purtarea fiecarui copil citita din fisier se retine in vectorul de string.uri purtare,
unde purtare[i] corespunde copilului i(din ordinea scrisorilor).
Creare vectorului Noua_Evidenta se face in main, in urma apelarii metodei de creare_purtare.

-Elfii parcurg după lista și se uită ce au copiii pe wishlist( elfii au acces la vectorul de
tip Scrisori Letters(variabila globala) si la metodele de set si get din clasa Scrisori
(prin mostenire)). 
PRIMELE DOUA CONDITII
Pasul 1: Se verifica daca copilul are wishlist.ul gol si in caz afirmativ
, acestuia i se ofera cadou DEFAULT pentru copil cuminte(daca este cuminte) sau cadou
DEFAULT pentru copil rau(se verifica daca este rau).
!pentru acesti copii se seteaza in vectorul de int, pe pozitia i corespondenta copilului i,
numarul de acadele=0;
A TREIA CONDITIE
Pasul 2: Daca cele doua conditii de mai sus nu au fost respectate se ajunge in al treilea else,
(unde copii au cadouri pe care si le doresc ), iar elfii trebuie sa verifice daca acele jucării 
există la ei în atelier adica in fisierul Lista_Cadouri_Inventar.txt. 
Dacă există le pun în punga de cadouri în ordinea înșiruită pana se depaseste bugetul copilului.
(De fiecare data cand gasim un cadou verificam daca copilul si-l permite si daca da, il scadem din
bugetul acestuia) !bugetul ramas se aduga in vectorul acadele pe pozitia curenta ca fiind numarul
de acadele= fiecare dolar necheltui:).

-Dacă nu există nimic pe inventar se va da un cadou default( adica daca dupa ce am verificat toate
cadourile in inventar string.ul lista ,in care salvam cadourile dorite si gasite, este egal cu""
(adica nimic - cum a fost reinitializat de fiecare data cand se trece la un nou copil) => se
acorda cadou default si 0 acadele.(ca in exemplul de la Pasul 1;)
-!!!!Dacă ce e pe listă depășește din start bugetul se va da un cadou default care valorează 
fix 100$ sau 10$ în funcție de copil. (este același cadou default)- aceasta cerinta a avut o 
formulare ambigua, deoarece putea fi inteleasa in doua moduri:
1. daca primul cadou(cuv cheie "din start") depaseste bugetul => cadou default (! indiferent ca 
dupa cadou unu mai exista cadouri pe care si le permite)
2. daca nu isi permite niciun cadou din cele dorite => cadou default 

!EU am ales a doua abordare, deoarece in cerinta se specifica urmatoarele
("Dacă au mai multe lucruri pe listă decât permite bugetul, 
se adaugă în pungă în ordinea lor până să se depășească ") Asta inseamna ca daca isi permite
cel putin un cadou acesta trebuie adaugat!!! Adica daca primul cadou dorit si gasit costa 101$, 
dar totusi exista alt cadou dorit si gasit in inventar mai ieftin de 100$ copilul il primeste.

Aceasta parte putea fi interpretata si imi cer scuze daca nu am interpretat cum ati dorit, insa mi
s-a parut gresit sa nu-i ofer copilului un cadou dorit daca il am si si l permite, doar pentru ca
primul cadou dorit este mult prea scump pentru bugetul lui.

Am creat un vector de obiecte de tip Evidenta_Orase care stocheaza orasul_x,orasul_y si diferenta de kilometri
intre acestea, informatii pe care le citeste din fisierul Lista_kilometri_orase.txt si le da .push_back() in vector.
(in fisier nu am repetat distantele, deoarece dist(oars_x,oras_y)=dist(oras_y,oras_x))

Prin friend class Trolii, Doamna_Claus si Domnul_Claus pot accesa lista cu cadouri creata, numarul
de acadele oferite pentru fiecare copil in parte si lista cu orase de vizitat.
friend class= o clasa poate accesa membrii private si protected ai unei clase.

La aceasta cerinta, am acoperit procesul de ABSTRACTIZARE prin crearea clasei abstracte Polul_Nord_Sarcini
care contine pure virtual function.( am ales aceasta abordare, deoarece recunosc ca nu simteam unde 
altundeva o pot include din cauza faptului ca aceasta clasa abstracta nu poate fi instantiata dupa cum stim
de la laborator!) Am facut de asemenea OVERRIDING-POLIMORFISM( redefinirea metodelor din clasa parinte in clasa copil,
acelasi return type necesar) la functia virtuala pentru ca Elfii sa nu fie si ei la 
randul lor o clasa abstracta. Am ales sa integrez si MULTIPLE INHERITANCE, desi nu cred ca m-am folosit in
special undeva de ea, deoarece am ales sa folosesc friend class.uri pentru a transmite prelua informatii
dintr-o clasa in alta. Am facut OVERLOADING pe constructori, avand atat constructori default pe care ii
apelez in int main,cat si constructori cu parametrii, la fel apelati in main( compilatorul decide ce constructor
apeleaza in functie de tipul referintei si a parametrilor - POLIMORFISM STATIC)

Cerinta #3 :

Trolii primesc de la elfi lista cu cadouri prin friend class și împachetează fiecare cadou cu 
un ambalaj specific pentru fete și unul specific pentru băieți.(se folosesc de vectorul global de 
obiecte numit Noua_Evidenta si de gettersii mosteniti de la Scrisori pentru a afla daca plicul
copilului i este roz, caz in care ambalaje_fete++, sau daca este albastru => ambalaj_baieti.
De asemenea, trolii pun și un cărbune în punga fiecărui copil rău. -vizibil la afisare
Dupa ce se executa for.ul din metoda impachetare() a trolilor, adica dupa ce se verifica toti copiii
din vector, verificand daca sunt fete sau baieti si daca au fost obraznici, stim numarul de ambalaje
de fete si de baieti necesare si in ce cadouri se gasesc carbuni.

-afisam cate ambalaje pentru fete și câte ambalaje pentru băieți au folosit trolii.

Pentru aceasta cerinta, am acoperit lucru basic cu clase si anume obiecte,constructor,destructor.

Cerinta #4 :

Doamna Crăciun primește lista cu numărul de acadele pe care trebuie să le facă, de la elfi 
(prin friend class), iar de la troli numărul de cărbuni folosiți(prin friend class).
Acadele reprezinta un vector cu numarul de acadele pe pozitia i care corespunde copilului i.
Doamna_Claus calculeaza prin metoda calculare_acadele suma tuturor acadelelor de pe fiecare pozitie,
iar in cazul carbunilor se seteaza atributul total_carbuni prin friend class.
Pentru a calcula bugetul extra am ales sa fac template pe metoda de inmultire acadele/carbuni * pret.
Astfel, cand apelez metoda pentru acadele folosind<int> primesc un return de tip int, si in cazul
carbunilor un return de tip float care se vor da ca parametrii metodei de calculare_buget_total.
Metoda care calculeaza (float)pret_total_acadele+pret_total_carbuni - se va afisa suma totală.

In cazul aceste cerinte am abordat conceptul de TEMPLATES( folosit cand mai multe functii realizeaza
operatii identice).

Cerinta #5 :
Moș Crăciun primește lista cu orașe de la elfi:
prin friend class, accesam lista_orase[i].kilometri si cream matricea de adiacenta a grafului cu
care vom lucra in felul urmator:
           nod 0     nod 1        nod 2      nod 3    nod 4    nod 5    nod 6
         Rovaniemi  Louvain     Bruxelles  Charleroi  Namur    Ronse    Bruges
Rovaniemi    0     dist(0->1)    d(0->2)    d(0->3)   d(0->4)  d(0->5)  d(0->6)
Louvain  dist(0->1)    0
Bruxelles  d(0->2)                  0
Charleroi  d(0->3)                              0
Namur      d(0->4)                                        0
Ronse      d(0->5)                                                 0
Bruges     d(0->6)                                                         0

Matrice simetrica fata de diagonala principala, deoarece dist(0->1) == dist(1->0)
!dist(0->1) = distanta in kilometri de la nodul 0 la nodul 1
0 = distanta de nodul i la nodul i va fi intotdeauna 0, distanta de la louvain la louvain este 0km.

Calculam drumul critic în număr de kilometrii(float) 
și ordinea destinațiilor având în vedere că el pleacă cu sania din aeroportul Rovaniemi din Laponia
(Finlanda). 

Drumul critic se va calcula prin algoritmul distantei lui DIJKSTRA( sursa geeksforgeeks)
care calculeaza si afiseaza distantele tuturor nodurilor fata de un nod dat = sursa.
=> cel mai apropiat nod fata de nodul sursa va fi primul oras care va trebui vizitat.
odata ce am ajuns in primul oras va trebui apelata functia dijkstra insa sursa va fi acum noul oras,
pentru a vedea din acest oras catre ce oras ne indreptam.
Algoritmul de pe site facea doar un pas din ce trebuia in cazul cerintei => l am adaptat sa calculeze
distanta minima pentru mos craciun astfel:

folosind algoritmul aflam distanta de la oricare nod la restul, deci intr un for pana la ultimul nod
am verificat daca este prima data cand se intra in for(deci dijkstra nu mai fusese apelat) si in caz
afirmativ se cere citirea nodului de plecare care in cazul nostru trebuie sa fie nodul 0 - orasul
Rovaniemi si se apeleaza dijkstra( de asemenea toate nodurile vizitate adica fata de care s-a apelat
functia dijkstra se vor trece ca vizitate in vectorul vizitat initializat initial cu 0
=> pe pozitia corespondenta nodului vizitat se va gasi acum valoarea 1).
in mom asta avem salvat in vectorul de float dist[] ,pe o anumita 
pozitie, cel mai apropiat nod => vom executa un proces de aflare minim pe acest vector pentru a afla
urmatoarea destinatie) am gasit nodul cel mai apropiat => aplicam dijkstra pe el si il trecem ca vizitat.
retinem acest minim de dist[] in variabila suma pentru a afla la final kilometri totali.

De asemenea, algoritmul initial lucra pentru distante de tip int si a trebuit sa modific pentru a calcula
kilometri reali(float).

-Afisam traseul cu numărul de kilometrii parcurși și ordinea de parcurgere a orașelor.

Am privit pas cu pas aplicarea algoritmului dijkstra si am inteles cum functioneaza, insa nu pot spune 
ca as reusi sa-l reproduc in totalitate daca nu as avea acces la internet. Mi s-a parut totusi super
interesant si aceasta a fost cerinta mea preferata :).

Cerinta #6 :

Înainte să plece, Doamna Crăciun vrea și ea să afle traseul lui Moș Crăciun,
așa că îl împărtășește și cu ea.
S-a realizat tot prin friend class :) si astfel Doamna Craciun a apelat metoda aflare_drum_min care ii
calculeaza drumul Mosului.

-----------------------------------------EXPLICATIE RULARE---------------------------------------

Rularea mea este una mai mult de verificare, deoarece am afisat vectorii Letters, Noua_Evidenta si purtare
strict pentru a observa daca implementarea este corecta. De asemenea, am ales sa afisez fiecare pas in cadrul
acordarii cadourilor, deoarece am avut multe probleme cu aceasta parte.(probleme de logica). La aceasta parte, am 
intalnit o eroare foarte dubioasa pentru stoi care semana cu eroarea aparuta cand exista cod dupa throw care nu 
se executa, asa ca am ales sa nu mai folosesc exceptii in aceasta parte a codului. Ciudat era ca eroarea se schimba 
daca comentam partile cu goto, iar in acest caz ma anunta ca lipseste o paranteza exact in acelasi loc cu goto.ul
comentat, iar atunci am ales sa comentez sfarsitul fiecarei paranteze :) ajungand la concluzia ca nu lipsea niciuna.
Am citit pe internet ca nu este recomandat sa folosim goto.uri drept break.uri pentru while, iar eu ieseam din doua
while.uri cu acel goto. O alternativa nu am gasit pe internet si nu vad cu ce as putea inlocui goto.urile.
Drept rezolvare am sters toata acea metoda si am luat-o de la inceput dupa doua zile de munca :) (in care jumate 
am cautat o paranteza) Acum pare ca.i convine goto.ul in cazul while.ului insa nu stiu ce e schimbat.

Singura parte interactiva este cand se cere sa se citeasca nodul de plecare pentru calcularea drumului minim, pentru 
care trebuie scris nodul 0, adica orasul Rovanieni, deoarece de acolo isi incepe mosul drumul.De asemenea, am pastrat
si afisarea pasilor algoritmului DIJKSTRA tot pentru o verificare mai usoara.

--------------------------------------  MULTUMESC PENTRU ATENTIE ! --------------------------------------------