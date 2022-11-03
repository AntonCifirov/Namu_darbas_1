#pragma once
#pragma once
#include "my_lib.h"
#include "Ivedimas_Isvedimas.h"


string generuoja_faila(int mokiniu_sk, int nd_sk);

void RemoveStudent(vector<duom>& students, int gal);

/*
vector<duom> Failo_rusiavimas_vargseliai(vector<duom> asmuo_vector)
{
 
    vector<duom> varg_vector;
    for (vector<duom>::iterator it = asmuo_vector.begin(); it != asmuo_vector.end();)
    {
        cout << (*it).var << endl;
        if ((*it).gal < 5)
        {
            varg_vector.push_back(*it);
            cout <<"Deleting: " <<(*it).var << endl;
            cout << "Deleting: " << (*it).pav << endl;
            cout << "Deleting: " << (*it).gal << endl;

            
            asmuo_vector.erase(it);
            cout<<(*it).pav << endl;
            cout << "_____" << endl;
            
        }
        else
        {
            it++;
        }
        //cout << iter << endl;
        //cout << iter << endl;
    
    }

    return varg_vector;

}*/

vector<duom> Failo_rusiavimas_vargseliai(vector<duom> asmuo_vector);

list<duom> Failo_rusiavimas_vargseliai(list<duom> asmuo_list);

vector<duom> Failo_rusiavimas_kietakai(vector<duom> asmuo_vector);

list<duom> Failo_rusiavimas_kietakai(list<duom> asmuo_list);


void Isvedimas_i_failus(string failo_pavadinimas, vector<duom> asmuo_vector);

void Isvedimas_i_failus(string failo_pavadinimas, list<duom> asmuo_list);
