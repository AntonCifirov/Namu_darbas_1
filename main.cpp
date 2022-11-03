#include "my_lib.h"
#include "Ivedimas_Isvedimas.h"
#include "Generavimas.h"


int main() {

    vector<duom> asmuo_vector;
    list<duom> asmuo_list;
    int nd_sk;
    string failo_pavadinimas;
    string pavadinimas;
    string txt;
    double diff_nusk{};
    double diff_nusk_proc{};
    double count{};
    cout << "Kiek namu darbu norite sugeneruot? " << endl;
    cin >> nd_sk;

    



    for (int i = 0; i < 5; i++)
    {
        
        failo_pavadinimas = generuoja_faila(pow(10,(i+3)), nd_sk);
//Realizacija su vector<duom>
        auto start1 = chrono::high_resolution_clock::now();       //timerio1 pradzia

        asmuo_vector = Failo_nuskaitymas(failo_pavadinimas);

        auto end1 = chrono::high_resolution_clock::now();         //timerio1 pabaiga
        chrono::duration<double> diff1 = end1 - start1;
        cout << "Failo " << failo_pavadinimas << ".txt nuskaitymas truko " << diff1.count() << "sek\n";



        auto start2 = chrono::high_resolution_clock::now();       //timerio2 pradzia

        Isvedimas_i_failus(failo_pavadinimas, asmuo_vector);

        auto end2 = chrono::high_resolution_clock::now();         //timerio2 pabaiga
        chrono::duration<double> diff2 = end2 - start2;
        cout << "Duomenu isvedimas i failus " << failo_pavadinimas << "_vargseliai.txt ir " << failo_pavadinimas << "_kietakai.txt truko : " << diff2.count() << "sek\n\n";


//Realizacija su list<duom>
        auto start3 = chrono::high_resolution_clock::now();       //timerio3 pradzia

        asmuo_list = Failo_nuskaitymas_list(failo_pavadinimas);

        auto end3 = chrono::high_resolution_clock::now();         //timerio3 pabaiga
        chrono::duration<double> diff3 = end3 - start3;
        cout << "Failo " << failo_pavadinimas << ".txt nuskaitymas naudojant list<duom> truko " << diff3.count() << "sek\n";

        auto start4 = chrono::high_resolution_clock::now();       //timerio4 pradzia
        Isvedimas_i_failus(failo_pavadinimas, asmuo_list);
        auto end4 = chrono::high_resolution_clock::now();         //timerio4 pabaiga
        chrono::duration<double> diff4 = end4 - start4;
        cout << "Duomenu isvedimas i failus " << failo_pavadinimas << "_vargseliai.txt ir " << failo_pavadinimas << "_kietakai.txt naudojant list<duom> truko : " << diff4.count() << "sek\n\n\n";

        diff_nusk += (diff1-diff3).count()/diff1.count();
        count++;


    }
    diff_nusk_proc = (diff_nusk / count) * 100;
    cout << "Vidutiniskai failu nuskaitimas naudojant list greitesnis uz vector: "<< fixed<<setprecision(2) << diff_nusk_proc << "%";

    



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
    

    }*/

    
    return 0;
}

