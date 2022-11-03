

vector<duom> Sort(vector<duom>);
//rusiuoja

duom sorting(duom);
// rusiuoja duom.paz
double findMedian(duom, int);
//randa mediana vektoriaus duom.paz;

duom ivedimas();
//ivedimas ranka arba atsitiktinis generavimas

duom eilutes_nuskaitymas();
//patalpina viena failo eilute i duom tipo objecta

vector<duom> Failo_nuskaitymas();
//nuskaito visa faila ir patalpina info i vector<duom>

vector<duom> Failo_nuskaitymas(string failo_pavadinimas);
//overoad funkcijos Failo_nuskaitymas
// nuskaito faila - failo_pavadinimas.txt

list<duom> Failo_nuskaitymas_list(string failo_pavadinimas);
//nuskaito visa faila ir patalpina info i list<duom>


int int_length(int);
//grazina skaiciaus ilgi;


void isvedimas(duom);
//isveda dveju eiluciu lentele tipo:
//Vardas   Pavarde   ND1   ND2  ... EGZAMINAS   GALUTINIS
//Iosif    Mainhem   10    10

void ISVEDIMAS(vector<duom>);

void ISVEDIMAS2(vector<duom> temp);
