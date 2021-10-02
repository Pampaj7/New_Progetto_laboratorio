#include <iostream>
#include "Date.h"
#include "Diary.h"
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;


int main() {

////new version read
    fstream myFile;
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
    Date d1;
    d1.setDay(5);
    d1.setMonth(Months::February);
    d1.setYear(2800);
    Date d2;
    d2.setDay(6);
    d2.setMonth(Months::September);
    d2.setYear(1200);
    Date d3;
    d3.setDay(12);
    d3.setMonth(Months::March);
    d3.setYear(2200);
    Date d4;
    d4.setDay(23);
    d4.setMonth(Months::March);
    d4.setYear(2200);

    ToDo allenareBicipiti;
    allenareBicipiti.setProgress(false);
    allenareBicipiti.setTitle("curl bicipiti");
    allenareBicipiti.setData(d1);
    allenareBicipiti.setPriority(10);

    ToDo allenareGambe;
    allenareGambe.setPriority(2);
    allenareGambe.setData(d1);
    allenareGambe.setPriority(2);
    allenareGambe.setProgress(false);

    ToDo faiSpesa;
    faiSpesa.setPriority(2);
    faiSpesa.setProgress(false);
    faiSpesa.setData(d1);
    faiSpesa.setTitle("compra uova e pesce");

    ToDo videogioca;
    videogioca.setPriority(7);
    videogioca.setData(d2);
    videogioca.setProgress(false);
    videogioca.setTitle("call of duty");

    ToDo palleggia;
    palleggia.setPriority(9);
    palleggia.setProgress(false);
    palleggia.setData(d2);
    palleggia.setTitle("palleggio");

    ToDo faiPasta;
    faiPasta.setPriority(7);
    faiPasta.setData(d3);
    faiPasta.setProgress(false);
    faiPasta.setTitle("stendi pasta");

    ToDo preparati;
    preparati.setPriority(5);
    preparati.setProgress(false);
    preparati.setData(d4);
    preparati.setTitle("preparati");

    ToDo dipingere;
    dipingere.setPriority(1);
    dipingere.setData(d4);
    dipingere.setProgress(false);
    dipingere.setTitle("dipingere");

    Activities sport;
    sport.setTitle("sport");
    sport.addToDo(allenareBicipiti);
    sport.addToDo(allenareGambe);

    Activities faccende;
    faccende.setTitle("faccende");
    faccende.addToDo(faiSpesa);

    Activities relax;
    relax.setTitle("relax");
    relax.addToDo(videogioca);
    relax.addToDo(dipingere);

    Activities Basket;
    Basket.setTitle(line);
    Basket.addToDo(palleggia);

    Activities farePizza;
    farePizza.setTitle("farePizza");
    farePizza.addToDo(faiPasta);

    Diary diariopersonale;
    diariopersonale.setNameDiary("il mio todo");

    diariopersonale.addActivities(relax);
    diariopersonale.addActivities(sport);
    diariopersonale.addActivities(faccende);
    diariopersonale.addActivities(farePizza);
    diariopersonale.addActivities(Basket);

//////////// scrittura

    ofstream fileX;
    fileX.open(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\riassuntoAttivita.txt)");
    if (fileX.is_open()) {
        fileX << diariopersonale.printActivities();
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
                std::string ac = diariopersonale.printActivities();
                std::cout << ac << std::endl;
                system("pause");
                break;
            }
            case '2' :
                cout << "IL TUO DIARIO CONTIENE I SEGUENTI TODO: " << endl;
                diariopersonale.printAllToDo();
                system("pause");
                break;
            case '3' : {
                cout << "IL TUO DIARIO CONTIENE I SEGUENTI TODO: " << endl;
                diariopersonale.printAllToDo();
                std::cout << "QUALE TODO' HAI COMPLETATO? " << std::endl;
                string act;
                std::cin >> act;
                diariopersonale.completedToDo(act);
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

    return 0;
}

