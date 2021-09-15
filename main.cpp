#include <iostream>
#include "Date.h"
#include "Diary.h"
#include "Activities.h"
#include <fstream>
#include <vector>
using namespace std;

int main() {

    Date d1(1999, Months::February, 28);
    Date d2(2000, Months::September, 12);
    Date d3(2001, Months::March, 32);

    ToDo allenareBicipiti(false, "curl bicipiti", 10, d1);
    ToDo faiSpesa(false, "compra uova e pesce", 2, d1);
    ToDo videogioca(false, "call of duty", 7, d2);

    Activities sport("palestra");
    sport.addToDo(allenareBicipiti);

    Activities faccende("faccende");
    faccende.addToDo(faiSpesa);

    Activities relax("relax");
    relax.addToDo(videogioca);

    Diary diariopersonale("il mio todo");
    diariopersonale.addActivities(relax);
    diariopersonale.addActivities(sport);
    diariopersonale.addActivities(faccende);


    std::ifstream OpenFile(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\Basket.txt)");
    char ch;
    std::string todo;

    while(!OpenFile.eof())
    {
        OpenFile.get(ch);
        std::cout << ch;
        todo += ch; // posso immagazzinare una cosa anche come intero?

    }
    OpenFile.close();  //Fori di testa
    std::cout << todo << std::endl;

    std::ifstream OpenFileX(R"(C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\Calcio.txt)");
    int chr;
    int t;

    while(!OpenFile.eof())
    {
        OpenFile.get(chr);
        std::cout << chr;
        t += chr; // posso immagazzinare una cosa anche come intero?

    }
    OpenFile.close();  //Fori di testa
    std::cout << t << std::endl;



/*
    std::ifstream  geo;
    std::string line;
    geo.open(R"((C:\Users\uffa\CLionProjects\New_Progetto_laboratorio\File.txt))", std::ios::in );
    vector<string> tokens;
    while(!geo.eof()) {

        getline(geo, line);
        istringstream iss(line);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(tokens)
        );
    }
    for (auto i:tokens) {
        cout << i << ", " ;
    }
    cout << endl;
    */
        return 0;
}
