#include <iostream>
#include "Date.h"
#include "Diary.h"
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;


int main() {

    fstream myFile; ////new version read
    myFile.open(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\readActivities.txt)", ios::in); //read

    string line;
    string lead;

    string s;
    stringstream ss(s);
    int i;

    if (myFile.is_open()) {
        getline(myFile, lead);
        getline(myFile, line);
        getline(myFile, s);
        ss >> i;
        myFile.close();
    }

////////////// dati base

    Date d1(5, Months::February, 2800);
    Date d2(6, Months::September, 1200);
    Date d3(12, Months::March, 3200);
    Date d4(21, Months::March, 3200);

    ToDo allenareBicipiti(false, "curl bicipiti", 10, d1);
    ToDo allenareGambe(false, "gambe", 2, d1);
    ToDo faiSpesa(false, "compra uova e pesce", 2, d1);
    ToDo videogioca(false, "call of duty", 7, d2);
    ToDo palleggia(false, "palleggio", 9, d2);
    ToDo faiPasta(false, "stendi pasta", 7, d3);
    ToDo preparati(false, "prepararsi", 5, d4);
    ToDo dipingere(false, "dipingere", 1, d4);

    Activities sport("sport");
    sport.addToDo(allenareBicipiti);
    sport.addToDo(allenareGambe);

    Activities faccende("faccende");
    faccende.addToDo(faiSpesa);

    Activities relax("relax");
    relax.addToDo(videogioca);
    relax.addToDo(dipingere);

    Activities Basket(line); //app vale farepizza da lettura
    Basket.addToDo(palleggia);

    Activities farePizza(lead); //appS vale Basket da lettura
    farePizza.addToDo(faiPasta);

    Diary diariopersonale("il mio todo");

    diariopersonale.addActivities(relax);
    diariopersonale.addActivities(sport);
    diariopersonale.addActivities(faccende);
    diariopersonale.addActivities(farePizza);
    diariopersonale.addActivities(Basket);

//////////// scrittura

    ofstream fileX;
    fileX.open(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\riassuntoAttivita.txt)");
    if (fileX.is_open()) {
        fileX << diariopersonale.stampActivities();
        fileX.close();
    }

    //////////// menù
    system("cls");
    cout << "----INTERFACCIA MENU'----" << endl;
    cout << "1) Mostra le attivita' presenti nella mia agenda" << endl;
    cout << "2) Mostra tutti i ToDo nella mia agenda" << endl;
    cout << "3) Completare un ToDo" << endl;
    cout << "4) Esci" << endl;


    char scelta;
    do {

        cout << "Inserisci una scelta[1-4]: ";
        cin >> scelta;
        cin.ignore(80, '\n');
        switch (scelta) {
            case '1' : {
                std::cout << "IL TUO DIARIO HA I SEGUENTI IMPEGNI: " << std::endl;
                std::string ac = diariopersonale.stampActivities();
                std::cout << ac << std::endl;
                system("pause");
                break;
            }
            case '2' :
                cout << "IL TUO DIARIO CONTIENE I SEGUENTI TODO: " << endl;
                diariopersonale.stampAllToDo();
                system("pause");
                break;
            case '3' : { //rimozione
                cout << "IL TUO DIARIO CONTIENE I SEGUENTI TODO: " << endl;
                diariopersonale.stampAllToDo();
                std::cout << "QUALE TODO' HAI COMPLETATO? " << std::endl;
                string act;
                std::cin >> act; // prendo il titolo del todo
                diariopersonale.markProgressToDo(act); //non fa
                system("pause");
                break;
            }
            case '4' :
                return 0;
                break;
            default:
                cout << "Attenzione, scelta non ammessa!" << endl;
                system("pause");
        }

    } while (scelta != '4');


    /*
   std::cout << "vuoi modificare qualcosa? si o no?" << std::endl;
   std::string a;
   std::string b;
   std::cin >> a;
   if (a == "si") {
       std::cout << "hai completato qualche ToDo?" << std::endl;
       std::cin >> b;
       if (b == "si") {
           std::cout << "quale toDo hai completato?" << std::endl;
           std::string acty;
           std::cin >> acty;
           if (acty == "curl bicipiti") {
               allenareBicipiti.makeProgeress();
               std::cout << "ottimo lavoro!" << std::endl;
           }
           if (acty == "compra uova e pesce") {
               faiSpesa.makeProgeress();
               std::cout << "ottimo lavoro!" << std::endl;
           }
           if (acty == "call of duty") {
               videogioca.makeProgeress();
               std::cout << "ottimo lavoro!" << std::endl;
           }
           if (acty == "palleggio") {
               palleggia.makeProgeress();
               std::cout << "ottimo lavoro!" << std::endl;
           }
           if (acty == "stendi pasta") {
               faiPasta.makeProgeress();
               std::cout << "ottimo lavoro!" << std::endl;
           }
           if (acty == "prepararsi") {
               preparati.makeProgeress();
               std::cout << "ottimo lavoro!" << std::endl;
           }
       }
   } else {
       std::cout << "hai completato qualche attività?" << std::endl;
   }
*/


    return 0;
}

