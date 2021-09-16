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
    for (const string& name: names) {
        app = name; //assegnazione
    }

    ////////////// lettura
    ifstream fileS(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\farePizza.txt)");
    vector<std::string> namesS;
    string inputS;
    string appS;
    while (fileS >> inputS) {
        namesS.push_back(inputS);
    }
    for (const string& name: namesS) {
        appS = name; //assegnazione
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

    Activities sport("sport");
    sport.addToDo(allenareBicipiti);
    sport.addToDo(allenareGambe);
    sport.removeToDo(allenareGambe);

    Activities faccende("faccende");
    faccende.addToDo(faiSpesa);

    Activities relax("relax");
    relax.addToDo(videogioca);

    Activities Basket(app); //app vale basket da lettura
    Basket.addToDo(palleggia);

    Activities farePizza(appS); //appS vale farePizza da lettura
    farePizza.addToDo(faiPasta);

    Diary diariopersonale("il mio todo");

    diariopersonale.addActivities(relax);
    diariopersonale.addActivities(sport);
    diariopersonale.addActivities(faccende);
    diariopersonale.addActivities(farePizza);
    diariopersonale.addActivities(Basket);

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
 //////////// menù
    std::cout << "Il tuo diario ha i seguenti impegni: " << std::endl;
    std::string ac = diariopersonale.stampActivities();
    std::cout << ac << std::endl;

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


    return 0;
}
