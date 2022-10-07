#pragma once
#include "mylib.h"
#include "C:\Users\ARGO\source\repos\ND_1\mediana.h"


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
    
    /*
    kursiokai >> asmuo.var;
    kursiokai >> asmuo.pav;
    for (int k = 0; k < nd_sk; k++)
    {
        int p;
        kursiokai >> p;
        asmuo.paz.push_back(p);
        cout << "___________________" << endl;
    }
    kursiokai >> asmuo.egz;
    cout << "------------" << endl;
    double median;
    cout << "------------" << endl;
    median = findMedian(asmuo, nd_sk);
    cout << "------------" << endl;
    asmuo.gal_m = 0.4 * median + 0.6 * asmuo.egz;
    cout << "------------" << endl;
    float vidurkis;
    cout << "------------" << endl;
    float sum = 0;
    cout << "------------" << endl;
    for (int z = 0; z < nd_sk; z++) {
        cout << "------------" << endl;
        sum = sum + asmuo.paz[z];
        cout << "------------" << endl;
    }
    vidurkis = (sum) / (nd_sk);
    cout << "------------" << endl;
    asmuo.gal = 0.4 * vidurkis + 0.6 * asmuo.egz;
    cout << "------------" << endl;
    */
    return asmuo;
}


    vector<duom> Failo_nuskaitymas() {
    vector<duom> asmuo1;
    kursiokai.open("C:/Users/ARGO/source/repos/ND_1__v_0.2/ND_1__v_0.2/Studentai10000.txt");
    
    
    //counting the number of students stud_sk
    vector<string> eilutes;
    cout << kursiokai.tellg()<<endl;
    while (getline(kursiokai, txt))
    {   
        
        eilutes.push_back(txt);
    }
    int stud_sk = eilutes.size() - 1;
    cout << "Studentu skaicius: " << stud_sk << endl;
    
    
    cout << kursiokai.tellg()<<endl;
    kursiokai.clear();
    kursiokai.seekg(0); //pointer to begging
    cout << kursiokai.tellg()<<endl;
    while (kursiokai >> txt)
    {
        nd_sk++;
    }
    nd_sk = (nd_sk - 3*(stud_sk + 1)) / (stud_sk + 1);
    cout << "nd_sk: "<<nd_sk<<endl;

    kursiokai.clear();
    kursiokai.seekg(0);
    getline(kursiokai, txt);

    for (int i = 0; i < stud_sk; i++)
    {
        asmuo1.push_back(eilutes_nuskaitymas());
    }
    /* 
    duom eilutes_nuskaitymas()
    {
        duom asmuo
        kursiokai >> asmuo.var;
        kursiokai >> asmuo.pav;
        for (int k = 0; k < nd_sk; k++)
        {
            kursiokai >> asmuo.paz[k];
        }
        kursiokai >> asmuo.egz;
        cout << "------------" << endl;
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
        
        
    }
    */

    /*
    for (int i = 0; i<stud_sk; i++)
    {   
        cout << "-------1" << endl;
        kursiokai >> txt;
        cout << txt;
        kursiokai >> asmuo[i].var;
        cout << "-------2" << endl;
        kursiokai >> asmuo[i].pav;
        cout << "-------3" << endl;
        for (int k = 0; i < nd_sk; k++)
        {
            cout << "-------4" << endl;
            kursiokai >> asmuo[i].paz[k];
            cout << "-------5" << endl;
        }
        kursiokai >> asmuo[i].egz;
        cout << "-------6" << endl;
        double median;
        median = findMedian(asmuo[i], nd_sk);
        asmuo[i].gal_m = 0.4 * median + 0.6 * asmuo[i].egz;
        cout << "-------7" << endl;
        float vidurkis;
        float sum = 0;
        for (int z = 0; i < nd_sk; z++) {
            cout << "------8" << endl;
            sum = sum + asmuo[i].paz[z];
            cout << "-------9" << endl;
        }
        vidurkis = (sum) / (nd_sk);
        cout << "-------10" << endl;
        asmuo[i].gal = 0.4 * vidurkis + 0.6 * asmuo[i].egz;
        cout << "-------11" << endl;
        
    }*/

    


    return asmuo1;
}
