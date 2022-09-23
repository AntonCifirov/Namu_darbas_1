#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::vector;
using std::vector;
using std::endl;


//using namespace std;
/*
Parašykite programą, kuri nuskaito šiuos studentų duomenis:

vardą ir pavardę.
n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis):
*/

struct duom {
    string var;
    string pav;
    float egz;
    float gal;
    vector <int> paz;
    
};

duom ivedimas() {
    duom asmuo;
    cout<<"Iveskite mokynio varda: "<<endl; cin>>asmuo.var;
    cout<<"Iveskite mokynio pavarde: "<<endl; cin>>asmuo.pav;
    
    /*if (asmuo.n < 0 || asmuo.n>= 20) {
        cout<<"Netinkamas namu darbu skaicius, iveskite dar karta: ";
        cin >>asmuo.n;
    }*/
    /*for (int kint = 0; kint<asmuo.n; kint++) {
        cout<<"Iveskite "<<kint + 1<<" namo darbo pazymi: ";
        int paz;
        cin>>paz;
        asmuo.paz.push_back(paz);
    }*//*
    for (int kint = 0; kint < 50; kint++) {
        cout<<"Iveskite "<<kint + 1<<" namo darbo pazymi: ";
        int paz;
        cin>>paz;
        if (paz == -1) {
            break;
        }
        else {
        asmuo.paz.push_back(paz);
        }*/
    int paz;
    int kint = 0;
    while (true) {
        
        cout<<"Iveskite "<<kint + 1<<" namo darbo pazymi, ";
        cout<<"Pabaigti ivedima - iveskite 0: ";
        cin>>paz;
        if (paz == 0) {
            break;
        }
        asmuo.paz.push_back(paz);
        kint = kint + 1;
    }
        
        
        
    cout<<"Egzamino pazymis: "; cin>>asmuo.egz;
    
    float vidurkis;
    float sum = 0;
    for (int i = 0; i < asmuo.paz.size(); i++) {
        sum = sum + asmuo.paz[i];
    }
    vidurkis = (sum)/(asmuo.paz.size());
    asmuo.gal = 0.4*vidurkis + 0.6*asmuo.egz;
    
    
    
    return asmuo;
}

int int_length(int x) {
    int a;
    a = floor(log10(x)+1);
    return a;
}

void isvedimas(duom temp) {
    
    string tab_1(6,' ');
    string tab_2(7,' ');
    string tab_3(5,' ');
    string egz_tab(11-int_length(temp.egz), ' ');
    string gal_tab(11-int_length(temp.gal), ' ');
    string V_ardas(temp.var.length(), ' ');
    string P_avarde(temp.pav.length(), ' ');
    
    
    //pirmos lenteles eilutes isvedimas
    cout<<"|Vardas"<<V_ardas<<"|Pavarde"<<P_avarde;
    for (int i = 0; i < temp.paz.size(); i++ ) {
        cout<<"|"<<i + 1<<"nd"<<tab_3;
    }
   
    cout<<"|Egzaminas  ";
    cout<<"|Galutinis  ";
    cout<<endl;
    
    
    // antros lenteles eilutes isvedimas
    cout<<"|"<<temp.var<<tab_1;
    cout<<"|"<<temp.pav<<tab_2;
    for (int i = 0; i < temp.paz.size(); i++) {
        string paz_tab(8-int_length(temp.paz[i]), ' ');
        cout<<"|"<<temp.paz[i]<<paz_tab;
        
        
    }
    cout<<"|"<<temp.egz<<egz_tab;
    cout<<"|"<<temp.gal<<gal_tab;
    //cout<<"|"<<endl;
    
}
int main() {


duom asmuo1;
asmuo1 = ivedimas();
isvedimas(asmuo1);


return 0;

     
}
















