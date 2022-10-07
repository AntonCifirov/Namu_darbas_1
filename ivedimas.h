#pragma once
#include "mylib.h"

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
