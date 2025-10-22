// Sample 1

/*
Sample code for Substituability and Polymorphism.
3 of the video games are derived under the GameGenre's class and we are overloading 
the main GameGenre's .displayData() method. This requires us to use polymorphism,
(aka  "virtual") to ensure that the derived classes' overloaded method is used instead.
*/

#include <iostream>
#include <string>
using namespace std;

class GameGenres {
    private:
        string name;
        string genre; 
        bool multiplayer = false; 
    public:
        GameGenres(const string& name, const string& genre, bool multiplayer) 
            : name(name), genre(genre), multiplayer(multiplayer) {}
        
        virtual void displayData() { cout << name << " is of " << genre 
            << " and is " << isMultiplayer() << "." << endl; }

        const string isMultiplayer() {
            if (multiplayer == false) {
                return "not multiplayer compatible"; 
            } return "multiplayer compatible";
        }

        const string getName() { return name; }
        const string getGenre() { return genre; }
};

class ResidentEvil : public GameGenres {
    private:
    public:
        ResidentEvil(const string& name, const string& genre, bool multiplayer)
            : GameGenres(name, genre, multiplayer) {}

        void displayData() { cout << "Name of the game is: " << GameGenres::getName() << endl;}
};

class SilentHill : public GameGenres {
    private:
    public:
        SilentHill(const string& name, const string& genre, bool multiplayer) 
            : GameGenres(name, genre, multiplayer){}
};

class Valorant : public GameGenres {
    private:
    public:
        Valorant(const string& name, const string& genre, bool multiplayer) 
            : GameGenres(name, genre, multiplayer ){}

        void displayData() { 
            cout << "Game: " << GameGenres::getName() << "; Genre: " 
                << GameGenres::getGenre() << endl; }
};


int main() {
    ResidentEvil ResidentEvil4("Resident Evil 4", "Action Horror", false);
    SilentHill SilentHill2("Silent Hill 2", "Survival Horror", false);
    Valorant ValorantGame("Valorant", "FPS", true);

    ResidentEvil4.displayData();
    SilentHill2.displayData();
    ValorantGame.displayData();
} //main