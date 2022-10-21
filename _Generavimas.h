#pragma once
#include "my_lib.h"
#include "_Ivedimas.h"


duom generuoja_mokini(int num, int nd_sk)

{
    
    duom asmuo;
    string a;
    a = to_string(num);

    asmuo.var = "Vardas" + a;
    asmuo.pav = "Pavarde" + a;
    

    for (int i = 0; i < nd_sk; i++)
    {

        asmuo.paz.push_back((rand() % 10) + 1);
\
    }
    asmuo.egz = ((rand() % 10) + 1);

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

    if (asmuo.gal < 5 && asmuo.gal >0) { asmuo.st = "Vargselis"; }
    else if (asmuo.gal >= 5 && asmuo.gal <= 10) { asmuo.st = "Kietakas"; }
    

    return asmuo;

}


vector<duom> generuoja_sarasa_i_faila(int mokiniu_sk, int nd_sk)
{
    auto start = std::chrono::high_resolution_clock::now(); //timerio1 pradzia

    string failo_pavadinimas;

    failo_pavadinimas = "studentai" + to_string(mokiniu_sk);
    ofstream studentai(failo_pavadinimas + ".txt", ios::out , ios::trunc);



    vector<duom> asmuo1;
    duom asmuo2;
    //Pirmos eilutes isvedimas i faila

    studentai << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)      Statusas"<<endl;


    for (int i = 1; i < mokiniu_sk + 1; i++)
    {
        asmuo2 = generuoja_mokini(i, nd_sk);

        asmuo1.push_back(asmuo2);

        string var(16 - asmuo2.var.length(), ' ');
        string pav(17 - asmuo2.pav.length(), ' ');
        string gal(18, ' ');
        string gal_m(18, ' ');
        studentai << asmuo2.var << var;
        studentai << asmuo2.pav << pav;
        studentai << fixed << setprecision(2) << asmuo2.gal << gal;
        studentai << fixed << setprecision(2) << asmuo2.gal_m << gal_m;


        
        if (asmuo2.st == "Vargselis") { studentai << "Vargselis" << endl; }
        else { studentai << "Kietakas" << endl; }
    }
    studentai.close();

    auto end = std::chrono::high_resolution_clock::now();         //timerio1 pabaiga
    std::chrono::duration<double> diff = end - start;
    
    cout <<"Failo kurimas truksta: " << diff.count() << "sek"<<endl;
   // std::chrono::duration<double> sum = sum + diff;

    
    auto start1 = std::chrono::high_resolution_clock::now();      //timerio2 pradzia
    string failo_pavadinimas1 = failo_pavadinimas + "_vargseliai";
    string failo_pavadinimas2 = failo_pavadinimas + "_kietakai";
    ofstream studentai_varg(failo_pavadinimas1 + ".txt", ios::out, ios::trunc);
    ofstream studentai_kiet(failo_pavadinimas2 + ".txt", ios::out, ios::trunc);

    //Pirmos eilutes isvedimas i failus Vargseliai ir Kietakai
    studentai_varg << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)      Statusas" << endl;
    studentai_kiet << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)      Statusas"<<endl;
    
    string gal(18, ' ');
    string gal_m(18, ' ');
    ifstream studentai1(failo_pavadinimas + ".txt", ios::in);

    string txt;
    getline(studentai1, txt);
    for (auto i : asmuo1)
    {
        string var(16 - i.var.length(), ' ');
        string pav(17 - i.pav.length(), ' ');
        

        
        getline(studentai1, txt);
        
        if (i.gal < 5)
        {
            studentai_varg << txt << endl;           
        }
        else 
        { 
            studentai_kiet << txt << endl;
        }
    } 
    auto end1 = std::chrono::high_resolution_clock::now();               //timerio2  pabaiga
    std::chrono::duration<double> diff1 = end1 - start1;

    cout << "Failo rusiavimas truksta: " << diff1.count() << "sek" << endl;

    studentai.close();
    studentai_varg.close();
    studentai_kiet.close();
    return asmuo1;
}