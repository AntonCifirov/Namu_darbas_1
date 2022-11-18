#include "my_lib.h"
#include "Ivedimas_Isvedimas.h"
#include "Generavimas.h"


int main() {

    vector<duom> asmuo_vector;
    vector<duom> varg_vector;
    vector<duom> kiet_vector;
   

    list<duom> asmuo_list;
    list<duom> varg_list;
    list<duom> kiet_list;

    int nd_sk;
    string failo_pavadinimas;
    string pavadinimas;
    string txt;
    double diff_nusk{};
    double diff_nusk_proc{};
    double diff_rusiavimas_vector{};
    double diff_rusiavimas_vector_proc{};
    double diff_rusiavimas_list{};
    double diff_rusiavimas_list_proc{};

    double count{};
    cout << "Kiek namu darbu norite sugeneruot? " << endl;
    cin >> nd_sk;

    

    for (int i = 3; i < 5; i++)
    {  
        
        failo_pavadinimas = generuoja_faila(pow(10, (i + 3)), nd_sk);

        
        //Realizacija su list<duom>
        //-------------------------------------------------------------------
        auto start1 = chrono::high_resolution_clock::now();       

        Failo_nuskaitymas(failo_pavadinimas, asmuo_list);

        auto end1 = chrono::high_resolution_clock::now();         
        chrono::duration<double> diff1 = end1 - start1;
        cout << "Failo " << failo_pavadinimas << ".txt nuskaitymas naudojant list<duom> truko " << diff1.count() << "sek\n";
        
        //-------------------------------------------------------------------
/*
        auto start2 = std::chrono::high_resolution_clock::now(); 

        Failo_rusiavimas_list(asmuo_list, varg_list, kiet_list);

        auto end2 = std::chrono::high_resolution_clock::now();   
        std::chrono::duration<double> diff2 = end2 - start2;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant 1 strategija list<duom> truko:  " << diff2.count() << "sek\n";
*/
        //-------------------------------------------------------------------

        varg_list.clear();

        auto start3 = std::chrono::high_resolution_clock::now(); 

        Failo_rusiavimas_list_2str(asmuo_list, varg_list);

        auto end3 = std::chrono::high_resolution_clock::now();   
        std::chrono::duration<double> diff3 = end3 - start3;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant 2 strategija list<duom> truko:  " << diff3.count() << "sek\n";
        
        //-------------------------------------------------------------------

        auto start4 = chrono::high_resolution_clock::now();   

        //Isvedimas_i_failus_list(failo_pavadinimas, varg_list, asmuo_list);
        Isvedimas_i_failus_list(failo_pavadinimas, varg_list, kiet_list);

        auto end4 = chrono::high_resolution_clock::now();         
        chrono::duration<double> diff4 = end4 - start4;
        cout << "Duomenu isvedimas i failus " << failo_pavadinimas << "_vargseliai.txt ir " << failo_pavadinimas << "_kietakai.txt naudojant list<duom> truko : " << diff4.count() << "sek\n\n";


        //=========================================================================================================================================================================================================



       //Realizacija su vector<duom>
        //-------------------------------------------------------------------
        auto start5 = chrono::high_resolution_clock::now();       

        Failo_nuskaitymas(failo_pavadinimas, asmuo_vector);

        auto end5 = chrono::high_resolution_clock::now();         
        chrono::duration<double> diff5 = end5 - start5;
        cout << "Failo " << failo_pavadinimas << ".txt nuskaitymas truko " << diff5.count() << "sek\n";

        //-------------------------------------------------------------------
/*
        auto start6 = chrono::high_resolution_clock::now();       

        Failo_rusiavimas_vector(asmuo_vector, varg_vector, kiet_vector);
        

        auto end6 = chrono::high_resolution_clock::now();         
        chrono::duration<double> diff6 = end6 - start6;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant 1 strategija vector<duom> truko:  " << diff6.count() << "sek\n";
        varg_vector.clear();
        kiet_vector.clear();
        //-------------------------------------------------------------------
        auto start6_ = chrono::high_resolution_clock::now();

        Failo_rusiavimas_vector_mod(asmuo_vector, varg_vector, kiet_vector);
        

        auto end6_ = chrono::high_resolution_clock::now();
        chrono::duration<double> diff6_ = end6_ - start6_;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant std::copy_if vector<duom> truko:  " << diff6_.count() << "sek\n";

        //-------------------------------------------------------------------

        varg_vector.clear();
        vector<duom> asmuo_vector_ = asmuo_vector;
        auto start7 = chrono::high_resolution_clock::now();
        
        Failo_rusiavimas_vector_2str(asmuo_vector_, varg_vector);

        auto end7 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff7 = end7 - start7;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant 2 strategija vector<duom> truko:  " << diff7.count() << "sek\n";
*/
        //-------------------------------------------------------------------
        varg_vector.clear();

        auto start7_ = chrono::high_resolution_clock::now();

        Failo_rusiavimas_vector_2str_mod(asmuo_vector, varg_vector);

        auto end7_ = chrono::high_resolution_clock::now();
        chrono::duration<double> diff7_ = end7_ - start7_;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas naudojant std::remove_if vector<duom> truko:  " << diff7_.count() << "sek\n";

        //-------------------------------------------------------------------

        auto start8 = chrono::high_resolution_clock::now();

        Isvedimas_i_failus_vector(failo_pavadinimas, varg_vector, asmuo_vector);

        auto end8 = chrono::high_resolution_clock::now();
        chrono::duration<double> diff8 = end8 - start8;
        cout << "Duomenu isvedimas i failus " << failo_pavadinimas << "_vargseliai.txt ir " << failo_pavadinimas << "_kietakai.txt naudojant vector<duom> truko : " << diff8.count() << "sek\n\n";
        cout << "===========================================================================================================================\n\n";

        //count++;
        //diff_nusk += (diff5 - diff1).count() / diff1.count();
        //diff_rusiavimas_vector += (diff7-diff6).count() / diff6.count();
        //diff_rusiavimas_list += (diff2 - diff3).count() / diff3.count();

       
    }
    /*
    diff_nusk_proc = (diff_nusk / count) * 100;
    cout << "Vidutiniskai failu nuskaitimas naudojant list greitesnis uz vector: "<< fixed<<setprecision(2) << diff_nusk_proc << "%\n";

    diff_rusiavimas_vector_proc = (diff_rusiavimas_vector / count) * 100;
    cout << "Vidutiniskai 1 strategija greitesne uz 2 strategija naudojant vector: " << fixed << setprecision(2) << diff_rusiavimas_vector_proc << "%\n";

    diff_rusiavimas_list_proc = (diff_rusiavimas_list / count) * 100;
    cout << "Vidutiniskai 2 strategija greitesne uz 1 strategija naudojant list: " << fixed << setprecision(2) << diff_rusiavimas_list_proc << "%\n";
*/






    /*
    cout << "Norint pabaigti programma apauskite 0 ENTER" << endl;
    while(true)
    
    {
        cout << "Koki faila norite atidaryt?" << endl;
        cin >> pavadinimas;
        if (pavadinimas != "0")
        {
            auto start2 = std::chrono::high_resolution_clock::now();
            ifstream studentai(pavadinimas, ios::in);
            if (!studentai.fail())
            {

                while (getline(studentai, txt)) { cout << txt << endl; }
                auto end2 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff2 = end2 - start2;

                cout << "Isvedimo i ekrana operacijos laikas: " << diff2.count() << "sek" << endl;
            }
            else { cout << "Nera tokio failo"<<endl; }
        }
        else
        {
            cout << "Viso geriausio!";
            break;
            return 0;
        }
    
*/
   

    
    return 0;
}

