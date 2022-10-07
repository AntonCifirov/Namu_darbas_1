#pragma once
#include "C:\Users\ARGO\source\repos\ND_1\mylib.h"

int int_length(int x) {
    int a;
    a = floor(log10(x) + 1);
    return a;
}
void isvedimasI()
{
    string V_ardas(10, ' ');
    string P_avarde(10, ' ');
    string Gal_vid(6, ' ');
    cout << " __________________________________________________________________________" << endl;
    cout << "|Vardas" << V_ardas << "|Pavarde" << P_avarde;
    cout << "|Galutinis (vid.)" << Gal_vid << "|Galutinis (med.)|" << endl;
    cout << "|                |                 |                      |                |" << endl;
    cout << "|--------------------------------------------------------------------------|" << endl;
    
}   
void isvedimasII(duom temp)
{   
    string var(16 - temp.var.length(), ' ');
    string pav(17 - temp.pav.length(), ' ');
    string gal(18, ' ');
    string gal_m(12, ' ');
    cout << "|" << temp.var << var;
    cout << "|" << temp.pav << pav;
    cout << "|" << fixed << setprecision(2) << temp.gal << gal;
    cout << "|" << fixed << setprecision(2) << temp.gal_m << gal_m << "|" << endl;

}
void isvedimasIII()
{
    cout << "|__________________________________________________________________________|" << endl;
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
/*
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
        cout << "|" << i + 1 << "nd" << tab_3;
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



}*/