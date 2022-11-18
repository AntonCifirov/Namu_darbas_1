#pragma once
#include "my_lib.h"

string generuoja_faila(int mokiniu_sk, int nd_sk)

{

    auto start = std::chrono::high_resolution_clock::now(); //timerio1 pradzia

    string failo_pavadinimas;

    failo_pavadinimas = "studentai" + to_string(mokiniu_sk);
    ofstream studentai(failo_pavadinimas + ".txt", ios::out, ios::trunc);

    studentai << "Vardas          Pavarde          ";
    for (int i = 1; i < nd_sk + 1; i++)
    {
        studentai << "ND" << i << "      ";
    }

    studentai << "Egzaminas" << endl;

    string txt;
    string tab;
    for (int i = 1; i < mokiniu_sk + 1; i++)
    {
        //string tab(10 - int_length(i), ' '); sena versija
        if (i < 10) { tab = "         "; } //nauja versija
        else { tab = "        "; }



        //studentai << "Vardas" + to_string(i) + tab + "Pavarde" + to_string(i) + tab; sena versija
        txt += "Vardas" + to_string(i) + tab + "Pavarde" + to_string(i) + tab; //nauja versija


        for (int i = 0; i < nd_sk; i++) //mokinio namu darbu pazymiu isvedimas
        {
            int random = (rand() % 10) + 1;
            txt += to_string(random);
            if (random == 10) { txt += "       "; }
            else { txt += "        "; }
        }

        txt += to_string((rand() % 10) + 1) + "\n";
    }
    studentai << txt;
    studentai.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo " << failo_pavadinimas << ".txt generavimo laikas: " << diff.count() << "\n\n";
    return failo_pavadinimas;

}

void RemoveStudent(vector<duom>& students, int gal) {
    students.erase(
        remove_if(students.begin(), students.end(), [&](duom const& stud) {return stud.gal < gal; }), students.end());
}

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

void Failo_rusiavimas_vector(vector<duom> asmuo_vector, vector<duom>& varg_vector, vector<duom>& kiet_vector)
{
    for (auto i : asmuo_vector)
    {
        if (i.gal < 5)
        {
            varg_vector.push_back(i);
        }
        else
        {
            kiet_vector.push_back(i);
        }
    }

}

void Failo_rusiavimas_vector_2str(vector<duom>& asmuo_vector, vector<duom>& varg_vector)
{
    auto it = asmuo_vector.begin();
    while (it != asmuo_vector.end())
    {
        if ((*it).gal < 5)
        {
            varg_vector.push_back(*it);
            it = asmuo_vector.erase(it);
        }
        else
        {
            it++;
        }
    }
}


void Failo_rusiavimas_vector_mod(vector<duom> asmuo_vector, vector<duom>& varg_vector, vector<duom>& kiet_vector)
{
    kiet_vector.resize(0.8 * size(asmuo_vector));
    int count_{};
    copy_if(asmuo_vector.begin(), asmuo_vector.end(), kiet_vector.begin(), [&](duom i) {if (i.gal < 5) { count_++; return true; } else { return false; } });
    kiet_vector.resize(count_);

    varg_vector.resize(0.8 * size(asmuo_vector));
    count_ = 0;
    copy_if(asmuo_vector.begin(), asmuo_vector.end(), varg_vector.begin(), [&](duom i) {if (i.gal >= 5) { count_++; return true; } else { return false; } });
    varg_vector.resize(count_);
}

void Failo_rusiavimas_vector_2str_mod(vector<duom>& asmuo_vector, vector<duom>& varg_vector)
{
    int count{};
    remove_if(asmuo_vector.begin(), asmuo_vector.end(), [&](duom i) {if (i.gal < 5) { count++; varg_vector.push_back(i); return true; } else { return false; } });
    asmuo_vector.resize(size(asmuo_vector) - count);
}

void Failo_rusiavimas_list(list<duom> asmuo_list, list<duom>& varg_list, list<duom>& kiet_list)
{
    for (list<duom>::iterator i = asmuo_list.begin(); i != asmuo_list.end(); i++)
    {
        if ((*i).gal < 5)
        {
            varg_list.push_back(*i);
        }
        else
        {
            kiet_list.push_back(*i);
        }
    }
}

void Failo_rusiavimas_list_2str(list<duom>& asmuo_list, list<duom>& varg_list)
{
    auto it = asmuo_list.begin();
    while (it != asmuo_list.end())
    {
        if ((*it).gal < 5)
        {
            varg_list.push_back(*it);
            it = asmuo_list.erase(it);
        }
        else
        {
            it++;
        }
    }
}

/*
void Failo_rusiavimas_vargseliai(vector<duom> asmuo_vector, vector<duom>& varg_vector)
{

    for (auto i : asmuo_vector)
    {
        if (i.gal < 5)
        {
            //cout << i.gal << endl;
            varg_vector.push_back(i);
        }
    }

}

void Failo_rusiavimas_vargseliai(list<duom> asmuo_list, list<duom>& varg_list)
{
    for (list<duom>::iterator i = asmuo_list.begin(); i != asmuo_list.end(); i++)
    {
        if ((*i).gal < 5)
        {
            varg_list.push_back(*i);
        }
    }

}

void Failo_rusiavimas_kietakai(vector<duom> asmuo_vector, vector<duom>& kiet_vector)
{

    for (auto  i : asmuo_vector)
    {
        if (i.gal >= 5)
        {
            kiet_vector.push_back(i);
        }
    }

}

void Failo_rusiavimas_kietakai(list<duom> asmuo_list, list<duom>& kiet_list)
{

    for (list<duom>::iterator i = asmuo_list.begin(); i != asmuo_list.end(); i++)
    {
        if (( * i).gal >= 5)
        {
            kiet_list.push_back(*i);
        }
    }
}

*/


void Isvedimas_i_failus_vector(string failo_pavadinimas, vector<duom> varg, vector<duom> kiet )
{

    string txt = "";
    string failo_pavadinimas1 = failo_pavadinimas + "_vargseliai.txt";
    string failo_pavadinimas2 = failo_pavadinimas + "_kietakai.txt";

    ofstream studentai_varg(failo_pavadinimas1, ios::out, ios::trunc);
    ofstream studentai_kiet(failo_pavadinimas2, ios::out, ios::trunc);

    auto start1 = std::chrono::high_resolution_clock::now(); //timerio1 pradžia

    //Pirmos eilutes isvedimas i failus Vargseliai ir Kietakai
    studentai_varg << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)" << endl;
    studentai_kiet << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)" << endl;


    for (auto i : varg)
    {
        string var(16 - i.var.length(), ' ');
        string pav(17 - i.pav.length(), ' ');
        string gal(18, ' ');
        string gal_m(18, ' ');


        studentai_varg << i.var + var + i.pav + pav << fixed << setprecision(2) << i.gal << gal << i.gal_m << endl;
    }
   
    txt = "";

        for (auto i : kiet)
        {

            string var(16 - i.var.length(), ' ');
            string pav(17 - i.pav.length(), ' ');
            string gal(18, ' ');
            string gal_m(18, ' ');

            studentai_kiet << i.var + var + i.pav + pav << fixed << setprecision(2) << i.gal << gal << i.gal_m << endl;
        }

    studentai_varg.close();
    studentai_kiet.close();
}

void Isvedimas_i_failus_list(string failo_pavadinimas, list<duom> varg, list<duom> kiet)
{

    string txt = "";
    string failo_pavadinimas1 = failo_pavadinimas + "_vargseliai.txt";
    string failo_pavadinimas2 = failo_pavadinimas + "_kietakai.txt";

    ofstream studentai_varg(failo_pavadinimas1, ios::out, ios::trunc);
    ofstream studentai_kiet(failo_pavadinimas2, ios::out, ios::trunc);



    auto start1 = std::chrono::high_resolution_clock::now(); //timerio1 pradžia

    //Pirmos eilutes isvedimas i failus Vargseliai ir Kietakai
    studentai_varg << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)" << endl;
    studentai_kiet << "Vardas          Pavarde          Galutinis (vid.)      Galutinis (med.)" << endl;


    for (const duom& i : varg)
        {
            string var(16 - i.var.length(), ' ');
            string pav(17 - i.pav.length(), ' ');
            string gal(18, ' ');
            string gal_m(18, ' ');

            studentai_varg << i.var + var + i.pav + pav << fixed << setprecision(2) << i.gal << gal << i.gal_m << endl;
        }


 
    for (const duom& i : kiet)
    {
        string var(16 - i.var.length(), ' ');
        string pav(17 - i.pav.length(), ' ');
        string gal(18, ' ');
        string gal_m(18, ' ');

        studentai_kiet << i.var + var + i.pav + pav << fixed << setprecision(2) << i.gal << gal << i.gal_m << endl;

    }
    kiet.clear();
    varg.clear();
    studentai_varg.clear();
    studentai_kiet.clear();
    studentai_varg.seekp(0);
    studentai_kiet.seekp(0);
    studentai_varg.close();
    studentai_kiet.close();
}
