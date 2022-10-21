#pragma once
#pragma once
#include "my_lib.h"
#include "_Ivedimas.h"
#include "_Isvedimas.h"


string generuoja_faila(int mokiniu_sk, int nd_sk)

{
    
    auto start = std::chrono::high_resolution_clock::now(); //timerio1 pradzia

    string failo_pavadinimas;

    failo_pavadinimas = "studentai" + to_string(mokiniu_sk);
    ofstream studentai(failo_pavadinimas + ".txt", ios::out, ios::trunc);

    studentai << "Vardas          Pavarde          ";
    for (int i = 1; i < nd_sk+1; i++)
    {
        studentai << "ND" << i << "      ";
    }
   
    studentai << "Egzaminas" << endl;

    string txt;
    string a;
    for (int i = 1; i < mokiniu_sk+1; i++)
    {
        string tab(10 - int_length(i), ' ');
        
        a = to_string(i);
        
        studentai << "Vardas" + a + tab + "Pavarde" + a + tab ;
        //studentai << txt; //Vardo Pavares isvedimas


        for (int i = 0; i < nd_sk; i++) //mokinio namu darbu pazymiu isvedimas
        {
            int random = (rand() % 10) + 1;
            studentai << random;
            if (random == 10) { studentai << "       "; }
            else { studentai << "        "; }
        }

        studentai << (rand() % 10) + 1 << endl;
    }
    studentai.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo " << failo_pavadinimas << ".txt generavimo laikas: " << diff.count() << endl;
    return failo_pavadinimas;
    
}





void Failo_rusiavimas(string failo_pavadinimas)
{
    vector<duom> asmuo_vector;

    auto start1 = std::chrono::high_resolution_clock::now(); //timerio1 pradzia
    asmuo_vector = Failo_nuskaitymas(failo_pavadinimas + ".txt");
    auto end1 = std::chrono::high_resolution_clock::now(); //timerio1 pabaiga
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo " << failo_pavadinimas << ".txt nuskaitymo laikas:  " << diff1.count() << "sek" << endl;

   // ifstream studentai1(failo_pavadinimas, ios::in);

    string failo_pavadinimas1 = failo_pavadinimas + "_vargseliai.txt";
    string failo_pavadinimas2 = failo_pavadinimas + "_kietakai.txt";

    ofstream studentai_varg(failo_pavadinimas1, ios::out, ios::trunc);
    ofstream studentai_kiet(failo_pavadinimas2, ios::out, ios::trunc);

    //Pirmos eilutes isvedimas i failus Vargseliai ir Kietakai
    studentai_varg << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)" << endl;
    studentai_kiet << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)" << endl;


    for (auto i : asmuo_vector)
    {
        string var(16 - i.var.length(), ' ');
        string pav(17 - i.pav.length(), ' ');
        string gal(18, ' ');
        string gal_m(18, ' ');
        if (i.gal < 5)
        {


            studentai_varg << i.var << var << i.pav << pav << fixed << setprecision(2) << i.gal << gal << i.gal_m << endl;

        }
        else
        {
            studentai_kiet << i.var << var << i.pav << pav << fixed << setprecision(2) << i.gal << gal << i.gal_m << endl;
        }

        
    }
    cout << "Sukurti failai " << failo_pavadinimas1 << " ir " << failo_pavadinimas2 << endl;
    studentai_varg.close();
    studentai_kiet.close();
}
