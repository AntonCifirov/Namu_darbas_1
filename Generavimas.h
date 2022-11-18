#pragma once
#pragma once
#include "my_lib.h"
#include "Ivedimas_Isvedimas.h"


string generuoja_faila(int mokiniu_sk, int nd_sk);

void RemoveStudent(vector<duom>& students, int gal);


void Failo_rusiavimas_vector(vector<duom> asmuo_vector, vector<duom>& varg_vector, vector<duom>& kiet_vector);

void Failo_rusiavimas_vector_mod(vector<duom> asmuo_vector, vector<duom>& varg_vector, vector<duom>& kiet_vector);

void Failo_rusiavimas_vector_2str(vector<duom>& asmuo_vector, vector<duom>& varg_vector);

void Failo_rusiavimas_vector_2str_mod(vector<duom>& asmuo_vector, vector<duom>& varg_vector);

void Failo_rusiavimas_list(list<duom> asmuo_list, list<duom>& varg_list, list<duom>& kiet_list);

void Failo_rusiavimas_list_2str(list<duom>& asmuo_list, list<duom>& varg_list);

/*
void Failo_rusiavimas_vargseliai(vector<duom> asmuo_vector, vector<duom>& varg_vector);

void Failo_rusiavimas_vargseliai(list<duom> asmuo_list, list<duom>& varg_list);

void Failo_rusiavimas_kietakai(vector<duom> asmuo_vector, vector<duom>& kiet_vector);

void Failo_rusiavimas_kietakai(list<duom> asmuo_list, list<duom>& kiet_vector);
*/

void Isvedimas_i_failus_vector(string failo_pavadinimas, vector<duom> varg, vector<duom> kiet);

void Isvedimas_i_failus_list(string failo_pavadinimas, list<duom> varg, list<duom> kiet);
