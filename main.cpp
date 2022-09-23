#include <cmath>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
#include <typeinfo>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setprecision;



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
    int n;
    vector <int> paz;
    
};


duom ivedimas() {
    duom asmuo;
    cout<<"Iveskite mokynio varda: "<<endl; cin>>asmuo.var;
    cout<<"Iveskite mokynio pavarde: "<<endl; cin>>asmuo.pav;
    cout<<"Iveskite namu darbų kieki: "<<endl; cin>>asmuo.n;

    
    if (asmuo.n < 0 || asmuo.n>= 20) {
        cout<<"Netinkamas ivedimo formatas, iveskite dar karta: ";
        cin >>asmuo.n;
    }
    for (int kint = 0; kint<asmuo.n; kint++) {
        cout<<"Iveskite "<<kint + 1<<" namo darbo pazymi: ";
        int paz;
        cin>>paz;
        asmuo.paz.push_back(paz);
        
    }
    
    cout<<"Egzamino pazymis: "; cin>>asmuo.egz;
    
    float vidurkis;
    float sum = 0;
    for (int i = 0; i < asmuo.n; i++) {
        sum = sum + asmuo.paz[i];
    }
    vidurkis = (sum)/(asmuo.n);
    asmuo.gal = 0.40*vidurkis + 0.60*asmuo.egz;
    
    
    
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
    for (int i = 0; i < temp.n; i++ ) {
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
    cout<<"|"<<setprecision(2)<<temp.gal<<gal_tab;
    
    
}
int main() {


duom asmuo1;
asmuo1 = ivedimas();
isvedimas(asmuo1);


return 0;

     
}















