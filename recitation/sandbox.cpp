#include <iostream>
#include <vector>
using namespace std;

// Instrument base class
class Instrument {
public:
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
    virtual ostream& display(ostream& os) const = 0;
    
    friend ostream& operator<<(ostream& os, const Instrument& instr) {
        return instr.display(os);
    }
    
    virtual ~Instrument() {}
};

// Brass instruments
class Brass : public Instrument {
protected:
    unsigned mouthpieceSize;
    
public:
    Brass(unsigned size) : mouthpieceSize(size) {}
    
    void makeSound() const override {
        cout << "To make a sound... blow on a mouthpiece of size " << mouthpieceSize << endl;
    }
    
    ostream& display(ostream& os) const override {
        return os;
    }
};

class Trumpet : public Brass {
public:
    Trumpet(unsigned size) : Brass(size) {}
    
    void play() const override {
        cout << "Toot";
    }
    
    ostream& display(ostream& os) const override {
        os << "Trumpet: " << mouthpieceSize;
        return os;
    }
};

class Trombone : public Brass {
public:
    Trombone(unsigned size) : Brass(size) {}
    
    void play() const override {
        cout << "Blat";
    }
    
    ostream& display(ostream& os) const override {
        os << "Trombone: " << mouthpieceSize;
        return os;
    }
};

// String instruments
class String : public Instrument {
protected:
    unsigned pitch;
    
public:
    String(unsigned p) : pitch(p) {}
    
    void makeSound() const override {
        cout << "To make a sound... bow a string with pitch " << pitch << endl;
    }
    
    ostream& display(ostream& os) const override {
        return os;
    }
};

class Violin : public String {
public:
    Violin(unsigned p) : String(p) {}
    
    void play() const override {
        cout << "Screech";
    }
    
    ostream& display(ostream& os) const override {
        os << "Violin: " << pitch;
        return os;
    }
};

class Cello : public String {
public:
    Cello(unsigned p) : String(p) {}
    
    void play() const override {
        cout << "Squawk";
    }
    
    ostream& display(ostream& os) const override {
        os << "Cello: " << pitch;
        return os;
    }
};

// Percussion instruments
class Percussion : public Instrument {
public:
    void makeSound() const override {
        cout << "To make a sound... hit me!" << endl;
    }
    
    ostream& display(ostream& os) const override {
        return os;
    }
};

class Drum : public Percussion {
public:
    void play() const override {
        cout << "Boom";
    }
    
    ostream& display(ostream& os) const override {
        os << "Drum";
        return os;
    }
};

class Cymbal : public Percussion {
public:
    void play() const override {
        cout << "Crash";
    }
    
    ostream& display(ostream& os) const override {
        os << "Cymbal";
        return os;
    }
};

// MILL class
class MILL {
private:
    vector<Instrument*> inventory;
    
public:
    MILL() {}
    
    void receiveInstr(Instrument& instr) {
        instr.makeSound();
        
        // Find first empty slot
        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i] == nullptr) {
                inventory[i] = &instr;
                return;
            }
        }
        
        // No empty slots, add to end
        inventory.push_back(&instr);
    }
    
    Instrument* loanOut() {
        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i] != nullptr) {
                Instrument* loaned = inventory[i];
                inventory[i] = nullptr;
                return loaned;
            }
        }
        return nullptr;
    }
    
    void dailyTestPlay() const {
        for (Instrument* instr : inventory) {
            if (instr != nullptr) {
                instr->makeSound();
            }
        }
    }
    
    friend ostream& operator<<(ostream& os, const MILL& mill) {
        os << "The MILL has the following instruments: ";
        if (mill.inventory.empty()) {
            os << "None";
            return os;
        }
        
        os << endl;
        bool first = true;
        for (Instrument* instr : mill.inventory) {
            if (instr != nullptr) {
                if (!first) os << endl;
                os << "\t" << *instr;
                first = false;
            }
        }
        return os;
    }
    
    ~MILL() {
        for (Instrument* instr : inventory) {
            delete instr;
        }
    }
};

// Musician class as provided to the students for Parts Two and Three
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
    void play() 
    {
        if (instr) instr->play();
    } // play
    
    const string& getName() const { return name; }
    
private:
    Instrument* instr;
    string name;
};

// Orchestra class for Part Three
class Orch {
private:
    vector<Musician*> musicians;
    
public:
    void addPlayer(Musician& musician) {
        musicians.push_back(&musician);
    }
    
    void play() const {
        for (Musician* musician : musicians) {
            musician->play();
        }
        cout << endl;
    }
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
    Trumpet trpt(12);
    Violin violin(567);

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

    return 0;
} // main