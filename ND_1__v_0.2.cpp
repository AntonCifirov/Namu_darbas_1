#include "C:\Users\ARGO\source\repos\ND_1\mylib.h"
#include "C:\Users\ARGO\source\repos\ND_1\mediana.h"
#include "C:\Users\ARGO\source\repos\ND_1\ivedimas.h"
#include "C:\Users\ARGO\source\repos\ND_1\isvedimas.h"
#include "C:\Users\ARGO\source\repos\ND_1\Failo_nuskaitymas.h"
#include "C:\Users\ARGO\source\repos\ND_1__v_0.2\ND_1__v_0.2\Sort.h"



int main() {
    vector<duom> asmuo1;
    int nuskaityti_is_failo;
    cout << "Ar norite nuskaityti duomenys is failo? 1 - Taip. 0 - Ne" << endl;
    cin >> nuskaityti_is_failo;
    if (nuskaityti_is_failo) 
    {
        
        asmuo1 = Failo_nuskaitymas();
        asmuo1 = Sort(asmuo1);
        isvedimasI();
        for (auto i : asmuo1) {
            isvedimasII(i);
        }
        isvedimasIII();

    }





    else
    {
        
        cout << "Kiek studentu turesite? ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            asmuo1.push_back(ivedimas());
        }

        for (auto i : asmuo1) {
            isvedimas(i);
        }
    }
    



    return 0;
}

