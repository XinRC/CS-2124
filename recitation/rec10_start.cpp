/*
  Xin
  rec10_start.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

//
// Put your Instrument Hierachy here
//
class Instrument {
    private:
    public:
        virtual void makeSound() = 0; 
        virtual void play() = 0; 
        virtual ostream& display(ostream& os) const = 0;
        
        friend ostream& operator<<(ostream& os, const Instrument& instrument) {
            return instrument.display(os); 
        }

        virtual ~Instrument() {}
}; // instrument

// ==========================BRASS===============================//
class Brass : public Instrument {
    protected:
        unsigned mouthpiece;
    public:
        Brass(unsigned mouthpiece) : mouthpiece(mouthpiece) {}
        void makeSound() {
            cout << "To make a sound... blow on my mouthpiece of size " << mouthpiece << endl;
        }
        ostream& display(ostream& os) const { return os; }
}; // brass

class Trumpet : public Brass {
    private:
    public: 
        using Brass::Brass;
        ostream& display(ostream& os) const { 
            os << "Trumpet: " << mouthpiece;
            return os;
        }
        void play() { cout << "Toot"; } 
}; // brass\trumpet

class Trombone : public Brass {
    private:
    public:
        using Brass::Brass;
        ostream& display(ostream& os) const {
            os << "Trombone: " << mouthpiece;
            return os; 
        }
        void play() { cout << "Blat"; }
}; // brass\trombone

// =========================STRING==============================//
class String : public Instrument {
    protected:
        unsigned pitch;
    public:
        String(unsigned pitch) : pitch(pitch) {}
        void makeSound() {
            cout << "To make a sound... bow a string with pitch " << pitch << endl;
        }
        ostream& display(ostream& os) const { return os; }
}; // string

class Violin : public String {
    private:
    public:
        using String::String;
        ostream& display(ostream& os) const {
            os << "Violin: " << pitch;
            return os;
        }
        void play() { cout << "Screech"; }
}; // string\violin 

class Cello : public String {
    private:
    public:
        using String::String;
        ostream& display(ostream& os) const {
            os << "Cello: " << pitch;
            return os;
        }
        void play() { cout << "Squawk"; }
}; // string\cello

// =======================PERCUSSION===========================//
class Percussion : public Instrument {
    private:
    public:
        Percussion() {}
        void makeSound() {
            cout << "To make a sound... hit me!" << endl;
        }
        ostream& display(ostream& os) const { return os; }
}; // percussion

class Drum : public Percussion {
    private:
    public:
        using Percussion::Percussion;
        ostream& display(ostream& os) const {
            os << "Drum";
            return os;
        }
        void play() { cout << "Boom"; }
};

class Cymbal : public Percussion {
    private:
    public:
        using Percussion::Percussion; \
        ostream& display(ostream& os) const {
            os << "Cymbal";
            return os;
        }
        void play() { cout << "Crash"; }
};
// =======================MILL================================//

class MILL {
    private:
        vector<Instrument*> inventory; 
    public: 
        MILL() {}
        //  output operator, deconstructor

        void receiveInstr(Instrument& instr) {
            instr.makeSound(); 

            // check for empty slot in inventory 
            for (size_t i = 0; i < inventory.size(); ++i) {
                if (inventory[i] == nullptr) {
                    inventory[i] = &instr;
                    return;
                }
            }
            // if theres none
            inventory.push_back(&instr); 
        }

        Instrument* loanOut() {
            // check inventory from idx 0 -> size for non nullptr obj
            for (size_t i = 0; i < inventory.size(); ++i) {
                if (inventory[i] != nullptr) {
                    Instrument* loaned = inventory[i];
                    inventory[i] = nullptr;
                    return loaned;
                }
            }
            return nullptr; 
        } 

        void dailyTestPlay() {
            for (size_t i = 0; i < inventory.size(); ++i) {
                if (inventory[i] != nullptr) {
                    inventory[i]->makeSound(); 
                }
            }
        }

        friend ostream& operator<<(ostream& os, const MILL mill) {
            os << "The MILL has the follow instruments: ";
            if (mill.inventory.empty()) {
                os << "None"; 
                return os; 
            }
            cout << endl;
            for (Instrument* instr : mill.inventory) {
                if (instr != nullptr) {
                    os << "\t" << *instr << endl;     
                }
            }
            return os; 
        }

}; 

// =====================MUSICIAN==============================//
// 
// Musician class as provided to the students for Parts Two and Three
// 

class Musician {
public:
    Musician(const string& name) : instr(nullptr), name(name) {}

    // acceptInstr takes in an instrument for the Musician to later play.
    //  "loses" any instrument that it used to have.
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    // giveBackInstr: gives the instrument that the Musicial was holding "back"
    Instrument* giveBackInstr() 
    { 
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    } // giveBackInstr

    // testPlay: testing out my instrument
    void testPlay() const
    {
        if (instr) instr->makeSound(); 
        else cerr << name << " has no instr\n";
    } // testPlay

    // play: play the instrument

    //   Not making it const so that Instrument::play method does not
    //   need to be const. Allows the instrument to be modifed in the
    //   process of being played.
    void play() 
    {
        if (instr) instr->play();
        // Don't do anything if we don't have an instrument.
    } // play
private:
    Instrument* instr;
    string name;
};


int main()
{

    //
    // Part One
    //

    cout << "P A R T  O N E\n";
    cout << "Define some instruments ---------------------------------------\n";

    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;

    cout << "and test them out ---------------------------------------------\n";
    vector<Instrument*> insts {&drum, &cello, &cymbal, &tbone, &trpt, &violin};
    cout << "Testing makeSound:\n";
    for (Instrument* p : insts) {
        p->makeSound();
    }
    cout << "Testing output operator:\n";
    for (const Instrument* p : insts) {
        cout << *p << endl;
    }
    
    
    cout << "==============================================\n";

    //
    // End of Part One
    //

    //
    // PART TWO
    //
    cout << "P A R T  T W O\n";  

    // use the debugger to look at the mill
    cout << "Define the MILL -----------------------------------------------\n";
    MILL mill;
    cout << "The MILL before adding instruments:\n" << mill << "\n\n";

    cout << "Put the instruments into the MILL -----------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    cout << "\nThe MILL after adding some instruments:\n" << mill << "\n\n";

    cout << "Daily test ----------------------------------------------------\n"
         << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << "Define some Musicians------------------------------------------\n";
    Musician harpo("Harpo");
    Musician groucho("Groucho");
  	
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();	

    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    groucho.testPlay();	
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();
    harpo.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL after giving out some instruments:\n" 
          << mill << "\n\n";

    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
  
    // fifth
     mill.receiveInstr(*groucho.giveBackInstr());
    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
     mill.receiveInstr(*harpo.giveBackInstr());

  
    cout << endl;
    cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
  
     cout << "\nThe MILL at the end of Part Two:\n" << mill << endl;

    cout << "==============================================\n";
    //
    // PART THREE
    //
    cout << "\nP A R T  T H R E E\n";
    
    /*
    Musician bob("Bob");
    Musician sue("Sue");
    Musician mary("Mary");
    Musician ralph("Ralph");
    Musician jody("Judy");
    Musician morgan("Morgan");

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    cout << endl << mill << endl;
    */

} // main