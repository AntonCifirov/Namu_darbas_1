#include "my_lib.h"
#include "_Ivedimas.h"
#include "_Isvedimas.h"
#include "Generavimas_naujas.h"


int main() {

   // auto start = std::chrono::high_resolution_clock::now(); //timerio1 pradzia
    //auto end = std::chrono::high_resolution_clock::now();         //timerio1 pabaiga
    //std::chrono::duration<double> diff = end - start;
    vector<duom> asmuo_vector;
    int mok_sk;
    int nd_sk;
    string failo_pavadinimas1;
    string failo_pavadinimas2;
    string failo_pavadinimas3;
    string failo_pavadinimas4;
    string failo_pavadinimas;


    string pavadinimas;
    string txt;

    cout << "Kiek namu darbu norite sugeneruot? " << endl;
    cin >> nd_sk;


    for (int i = 0; i < 5; i++)
    {
        
        failo_pavadinimas = generuoja_faila(pow(10,(i+3)), nd_sk);

        auto start = std::chrono::high_resolution_clock::now();       //timerio1 pradzia
        Failo_rusiavimas(failo_pavadinimas);
        auto end = std::chrono::high_resolution_clock::now();         //timerio1 pabaiga
        std::chrono::duration<double> diff = end - start;
        cout << "Failo " << failo_pavadinimas << ".txt rusiavimas truko:  " << diff.count() << "sek\n\n";
        
        
    }
    
    


    
   

    /*
    cout << "Kiek namu darbu norite sugeneruot? " << endl;
    cin >> nd_sk;

    generuoja_sarasa_i_faila(1000, nd_sk);
    cout << "Sukurtas failas \"studentai1000.txt\", \"studentai1000_vargseliai.txt\", studentai1000_kietakai.txt\"\n" << endl;

    generuoja_sarasa_i_faila(10000, nd_sk);
    cout << "Sukurtas failas \"studentai10000.txt\", \"studentai10000_vargseliai.txt\", studentai10000_kietakai.txt\"\n" << endl;

    generuoja_sarasa_i_faila(100000, nd_sk);
    cout << "Sukurtas failas \"studentai100000.txt\", \"studentai100000_vargseliai.txt\", studentai100000_kietakai.txt\"\n" << endl;


    //generuoja_sarasa_i_faila(1000000, nd_sk);
    //cout << "Sukurtas failas \"studentai1000000.txt\", \"studentai1000000_vargseliai.txt\", studentai1000000_kietakai.txt\"\n" << endl;


    //generuoja_sarasa_i_faila(10000000, nd_sk);
    //cout << "Sukurtas failas \"studentai10000000.txt\", \"studentai10000000_vargseliai.txt\", studentai10000000_kietakai.txt\"\n" << endl;

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

    
    //generuoja_sarasa_i_faila(1000000, nd_sk);
   // cout << "Sukurtas failas \"studentai1000000.txt\"\n" << endl;

    return 0;
}

