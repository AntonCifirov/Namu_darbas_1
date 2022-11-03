#pragma once
#include "my_lib.h"

//
//IVEDIMAS
//



vector<duom> Sort(vector<duom> temp)
{
    for (int k = 0; k < temp.size(); k++)
    {
        for (int i = 0; i < temp.size() - 1; i++)
        {
            string a = temp[i].pav;
            string b = temp[i + 1].pav;
            if ((a.compare(b) > 0))
            {
                duom z;
                z = temp[i];
                temp[i] = temp[i + 1];
                temp[i + 1] = z;
            }
        }
    }
    return temp;
}




duom sorting(duom temp)
{
    sort(temp.paz.begin(), temp.paz.end());

    return temp;

}

double findMedian(duom temp, int n)
{
    duom temp1 = sorting(temp);
    if (n % 2 == 0)
    {
        double median = (temp1.paz[n / 2] + temp1.paz[(n / 2) - 1]) / 2 + 0.5;
        return median;
    }
    else
    {
        double median = (temp1.paz[(n / 2)]);
        return median;
    }
}



duom ivedimas() {
    duom asmuo;
    int random;
    cout << "Ar norite atsitiktinai sugeneruoti duomenys, ar ivesti. Ivesti - spauskite 0 ENTER. Sugeneruoti - spauskite 1 ENTER." << endl;
    cin >> random;



    if (random) //atsitiktinai generuoojame duomenys
    {
        string Vardai[15] = { "James", "Robert", "John", "Michael", "David",  "William",  "Richard",  "Mary",  "Patricia",  "Jennifer", "Linda", "Elizabeth", "Barbara", "Susan", "Jessica" };
        string Pavardes[15] = { "Smith", "Johnson", "Williams", "Brown", "Jones",  "Miller",  "Davis",  "Garcia",  "Rodriguez",  "Wilson", "Martinez", "Anderson", "Taylor", "Thomas", "Hernandez" };


        asmuo.var = Vardai[rand() % 15];

        asmuo.pav = Pavardes[rand() % 15];
        cout << "Kiek namu darbu pazymiu norite sugeneruot ? ";
        cin >> asmuo.n;
        for (int i = 0; i < asmuo.n; i++)
        {
            asmuo.paz.push_back((rand() % 10) + 1);
        }
        asmuo.egz = ((rand() % 10) + 1);

    }



    // ivedame duomenys ranka
    else {
        cout << "Iveskite mokynio varda: " << endl; cin >> asmuo.var;
        cout << "Iveskite mokynio pavarde: " << endl; cin >> asmuo.pav;

        for (int i = 0; i > -5; i++) {
            cout << "Iveskite " << i + 1 << "nd pazymi, baigus ivedima spauskite 0 ENTER: " << endl;
            int k;
            cin >> k;
            while (true) {
                if (!cin) {
                    cout << "Neteisingas ivedimo formatas, iveskite dar karta: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> k;
                    if (!cin) {
                        continue;
                    }
                    else break;
                }
                else   break;
            }
            if (k == 0) break;
            else if (k <= 10 && k >= 1) {
                asmuo.paz.push_back(k);
                asmuo.n++;
            }
        }
        cout << "Iveskite mokinio egzamino pazymi: " << endl;
        while (true) {
            cin >> asmuo.egz;
            if (!cin) {
                cout << "Neteisingas ivedimo formatas, iveskite is naujo: " << endl;
                cin.clear();
                cin.ignore();
            }
            else break;
        }
    }



    cout << "Ar galutini pazymi norite skaiciuoti su Vidurkiu ar su Mediana? Mediana - spauskite 1 ENTER. Vidurkis - spauskite 0 ENTER." << endl;
    int if_median;

    cin >> if_median;
    if (if_median) // skaicuojam mediana
    {
        double median;
        median = findMedian(asmuo, asmuo.n);
        asmuo.gal = 0.4 * median + 0.6 * asmuo.egz;
    }

    else // skaicuojam vidurki
    {

        float vidurkis;
        float sum = 0;
        for (int i = 0; i < asmuo.n; i++) {
            sum = sum + asmuo.paz[i];
        }
        vidurkis = (sum) / (asmuo.n);
        asmuo.gal = 0.4 * vidurkis + 0.6 * asmuo.egz;
    }


    return asmuo;
}

// This function has to read a file, and coresponding to the number of students and the number of ND, fill out objects of duom structure.
// Number_of_students = number_of_lines - 1
// Number_of_ND = number_of_words_in_line - 3
//vector<duom> 
string txt;
int nd_sk = 0;
duom asmuo;
ifstream kursiokai;

duom eilutes_nuskaitymas()
{
    duom asmuo;


    kursiokai >> asmuo.var;
    kursiokai >> asmuo.pav;
    int p;
    for (int k = 0; k < nd_sk; k++)
    {
        kursiokai >> p;
        asmuo.paz.push_back(p);

    }

    kursiokai >> asmuo.egz;

    double median;
    median = findMedian(asmuo, nd_sk);
    asmuo.gal_m = 0.4 * median + 0.6 * asmuo.egz;
    float vidurkis;
    float sum = 0;
    for (int z = 0; z < nd_sk; z++) {
        sum = sum + asmuo.paz[z];
    }
    vidurkis = (sum) / (nd_sk);
    asmuo.gal = 0.4 * vidurkis + 0.6 * asmuo.egz;


    return asmuo;
}


vector<duom> Failo_nuskaitymas() {
    int word = 0;
    char failo_pavadinimas[20];
    cout << "Iveskite failo pavadinima: ";
    cin >> failo_pavadinimas;
    try
    {
        kursiokai.open(failo_pavadinimas);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Nera tokio failo";
    }


    //cout << "Toks failas neegzistuoja" << endl;


    vector<duom> asmuo1;

    //counting the number of students stud_sk
    vector<string> eilutes;
    while (getline(kursiokai, txt))
    {

        eilutes.push_back(txt);
    }
    int stud_sk = eilutes.size() - 1;

    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging
    txt = "";
  
    while (kursiokai >> txt)
    {

        nd_sk++;
    }
    nd_sk = (nd_sk - 3 * (stud_sk + 1)) / (stud_sk + 1);
    


    kursiokai.clear();
    kursiokai.seekg(0);
    getline(kursiokai, txt);

    for (int i = 0; i < stud_sk; i++)
    {
        asmuo1.push_back(eilutes_nuskaitymas());
    }




    return asmuo1;
}

vector<duom> Failo_nuskaitymas(string failo_pavadinimas) {

//    try
//    {
        kursiokai.open(failo_pavadinimas + ".txt");
/*    }
    
    catch (const ifstream::failure& e)
    {
        cout << "Nera tokio failo";
    }
*/

    //cout << "Toks failas neegzistuoja" << endl;


    vector<duom> asmuo1;

    //counting the number of students stud_sk
    vector<string> eilutes;
    while (getline(kursiokai, txt))
    {

        eilutes.push_back(txt);
    }
    int stud_sk = eilutes.size() - 1;

    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging

    // counting nd skaicius nd_sk 1 variant

   getline(kursiokai, txt);
    istringstream line(txt);
    while (line >> txt)
    {      
        nd_sk++;
    }
    nd_sk = nd_sk - 3;

    kursiokai.clear();
    kursiokai.seekg(0);


    getline(kursiokai, txt);

    for (int i = 0; i < stud_sk; i++)
    {
        asmuo1.push_back(eilutes_nuskaitymas());
    }


    kursiokai.clear();
    kursiokai.seekg(0);
    kursiokai.close();

    return asmuo1;
}


list<duom> Failo_nuskaitymas_list(string failo_pavadinimas) {

    //    try
    //    {
    kursiokai.open(failo_pavadinimas + ".txt");
    /*    }

        catch (const ifstream::failure& e)
        {
            cout << "Nera tokio failo";
        }
    */

    //cout << "Toks failas neegzistuoja" << endl;


    list<duom> asmuo1;

    //counting the number of students stud_sk
    list<string> eilutes;
    while (getline(kursiokai, txt))
    {

        eilutes.push_back(txt);
    }
    int stud_sk = eilutes.size() - 1;

    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging

    getline(kursiokai, txt);
    istringstream line(txt);
    while (line >> txt)
    {
        nd_sk++;
    }
    nd_sk = nd_sk - 3;

    kursiokai.clear();
    kursiokai.seekg(0);
    getline(kursiokai, txt);

    for (int i = 0; i < stud_sk; i++)
    {
        asmuo1.push_back(eilutes_nuskaitymas());
    }


    kursiokai.clear();
    kursiokai.seekg(0);
    kursiokai.close();

    return asmuo1;
}


//
//ISVEDIMAS
//




int int_length(int x) {
    int a;
    a = floor(log10(x) + 1);
    return a;
}



void isvedimas(duom temp) {

    string tab_1(6, ' ');
    string tab_2(7, ' ');
    string tab_3(5, ' ');
    string egz_tab(11 - int_length(temp.egz), ' ');
    string gal_tab(11 - int_length(temp.gal), ' ');
    string V_ardas(temp.var.length(), ' ');
    string P_avarde(temp.pav.length(), ' ');



    //pirmos lenteles eilutes isvedimas
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    for (int i = 0; i < temp.paz.size(); i++) {
        string nd_tab(7 - int_length(i + 1), ' ');
        cout << "|" << i + 1 << "nd" << nd_tab;
    }


    cout << "|Egzaminas  ";
    cout << "|Galutinis  ";
    cout << endl;


    // antros lenteles eilutes isvedimas
    cout << "|" << temp.var << tab_1;
    cout << "|" << temp.pav << tab_2;
    for (int i = 0; i < temp.paz.size(); i++) {
        string paz_tab(8 - int_length(temp.paz[i]), ' ');
        cout << "|" << temp.paz[i] << paz_tab;


    }
    cout << "|" << temp.egz << egz_tab;
    cout << "|" << setprecision(2) << temp.gal << gal_tab << endl << endl;



}
void ISVEDIMAS(vector<duom> temp)
{
    string V_ardas(10, ' ');
    string P_avarde(10, ' ');
    string Gal_vid(6, ' ');
    cout << " __________________________________________________________________________" << endl;
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    cout << "|Galutinis (vid.)" << Gal_vid << "|Galutinis (med.)|" << endl;
    cout << "|                |                 |                      |                |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;

    for (auto i : temp)
    {
        string var(16 - i.var.length(), ' ');
        string pav(17 - i.pav.length(), ' ');
        string gal(18, ' ');
        string gal_m(12, ' ');
        cout << "|" << i.var << var;
        cout << "|" << i.pav << pav;
        cout << "|" << fixed << setprecision(2) << i.gal << gal;
        cout << "|" << fixed << setprecision(2) << i.gal_m << gal_m << "|" << endl;

    }

    cout << "|__________________________________________________________________________|" << endl;
}

void ISVEDIMAS2(vector<duom> temp)
{
    string V_ardas(10, ' ');
    string P_avarde(10, ' ');
    string egz(6, ' ');
    cout << " __________________________________________________________________________" << endl;
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    cout << "|Egzaminas" << egz << "|Galutinis" << endl;
    cout << "|                |                 |               |                       |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;

    for (auto i : temp)
    {
        string var(16 - i.var.length(), ' ');
        string pav(17 - i.pav.length(), ' ');
        string gal(19, ' ');
        string egz(11, ' ');
        cout << "|" << i.var << var;
        cout << "|" << i.pav << pav;
        cout << "|" << fixed << setprecision(2) << i.egz << egz;
        cout << "|" << fixed << setprecision(2) << i.gal << gal << "|" << endl;

    }

    cout << "|__________________________________________________________________________|" << endl;
}