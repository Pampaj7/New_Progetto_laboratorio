#include <iostream>
#include "Date.h"
#include "Diary.h"
#include <fstream>
#include <vector>

using namespace std;

int main() {

/////////lettura
    ifstream file(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\Basket.txt)");
    vector<std::string> names;
    string input;
    string app;
    while (file >> input) {
        names.push_back(input);
    }

    for (string name: names) {
        cout << name << std::endl; // verifica
        app = name; //assegnazione
    }

    ////////////// lettura
    ifstream fileS(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\farePizza.txt)");
    vector<std::string> namesS;
    string inputS;
    string appS;
    while (file >> input) {
        names.push_back(input);
    }

    for (string name: names) {
        cout << name << std::endl; // verifica
        appS = name; //assegnazione
    }


////////////// dati base

    Date d1(1999, Months::February, 28);
    Date d2(2000, Months::September, 12);
    Date d3(2001, Months::March, 32);

    ToDo allenareBicipiti(false, "curl bicipiti", 10, d1);
    ToDo faiSpesa(false, "compra uova e pesce", 2, d1);
    ToDo videogioca(false, "call of duty", 7, d2);
    ToDo palleggia(false, "palleggio", 9, d2);
    ToDo faiPasta(false, "stendi pasta", 7, d3);

    Activities sport("palestra");
    sport.addToDo(allenareBicipiti);

    Activities faccende("faccende");
    faccende.addToDo(faiSpesa);

    Activities relax("relax");
    relax.addToDo(videogioca);

    Activities Basket(app); //app vale basket
    Basket.addToDo(palleggia);
    Activities farePizza(appS); //appS vale farePizza
    farePizza.addToDo(faiPasta);

    Diary diariopersonale("il mio todo");

    diariopersonale.addActivities(relax);
    diariopersonale.addActivities(sport);
    diariopersonale.addActivities(faccende);


//////////// scrittura

    //scrittura
    ofstream fileX;
    fileX.open((R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\riassuntoAttivita.txt)"));
    //fileX << "hey"; //output
    vector<string> namesX;
    namesX.push_back(diariopersonale.stampActivities());
    for (string name: namesX) {
        fileX << name << std::endl;
    }
    file.close();

    return 0;
}
