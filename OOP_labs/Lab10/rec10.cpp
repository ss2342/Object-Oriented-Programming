// Satyen Singh
// rec 10


#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    virtual void makeSound() = 0;
    virtual void play() = 0;
protected:
private:
};


class Brass : public Instrument {

public:
    Brass(unsigned sizeOfMouthPiece) : size(sizeOfMouthPiece) {}
    void makeSound() {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << size << endl;
    }
protected:
private:
    unsigned size;
};

class String : public Instrument {
public:
    String(unsigned pitchSize) : pitch(pitchSize) {}
    void makeSound() {
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
protected:
private:
    unsigned pitch;
};

class Percussion : public Instrument {
public:
    Percussion() {}
    void makeSound() {
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
protected:
private:
};

class Trumpet : public Brass {
public:
    Trumpet(unsigned size) : Brass(size) {}

    void play() {
        cout << "Toot";
    }
protected:
private:
};

class Trombone : public Brass {
public:
    Trombone(unsigned size) : Brass(size) {}

    void play() {
        cout << "Blat";
    }
protected:
private:
};

class Violin : public String {
public:
    Violin(unsigned pitch) : String(pitch) {}

    void play() {
        cout << "Screech";
    }
protected:
private:
};

class Cello : public String {
public:
    Cello(unsigned pitch) : String(pitch) {}

    void play() {
        cout << "Squawk";
    }
protected:
private:
};

class Drum : public Percussion {
public:
    Drum() {}

    void play() {
        cout << "Boom";
    }
protected:
private:
};

class Cymbal : public Percussion {
public:
    Cymbal() {}

    void play() {
        cout << "Crash";
    }
protected:
private:
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }

    void play() const {
        if (instr) {
            instr->play();
        }
        else {
            cerr << "have no instr" << endl;
        }
    }

private:
    Instrument* instr;
};

class MILL {
public:

    MILL() : instruments{nullptr} {}

    void receiveInstr(Instrument& aInstrument) {
        aInstrument.makeSound();
        for (unsigned i = 0; i < instruments.size(); ++i) {
            if (instruments[i] == nullptr) {
                instruments[i] = &aInstrument;
                return;
            }
        }
        instruments.push_back(&aInstrument);
    }

    void dailyTestPlay() {
        for (unsigned i = 0; i < instruments.size(); ++i) {
            if (instruments[i] != nullptr) {
                instruments[i]->makeSound();
            }
        }
    }

    Instrument* loanOut() {
        for (unsigned i = 0; i < instruments.size(); ++i) {
            if (instruments[i] != nullptr) {
                Instrument* loanedInstrument(instruments[i]);
                instruments[i] = nullptr;
                return loanedInstrument;
            }
        }
        return nullptr;

    }
protected:
private:
    vector<Instrument*>instruments;
};

class Orch {
public:
    Orch() {}

    void addPlayer(Musician& aMusician) {
        musicians.push_back(&aMusician);
    }

    void play() {
        bool instrumentPlayed = false;
        for (unsigned i = 0; i < musicians.size(); ++i) {
            musicians[i]->play();
            instrumentPlayed = true;
        }
        if (!instrumentPlayed) {
            cerr << "No instruments were played" << endl;
        }
        cout << endl;



    }
protected:
private:
    vector<Musician*> musicians;
};

void Instrument::makeSound() {
    cout << "To make a sound...";
}


// PART ONE
//int main() {
//
//     cout << "Define some instruments ------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12) ;
//     Violin violin(567) ;
//
//     // use the debugger to look at the mill
//     cout << "Define the MILL --------------------------------------------\n";
//     MILL mill;
//
//     cout << "Put the instruments into the MILL --------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//     cout << "Daily test -------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << "Define some Musicians---------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     groucho.testPlay();
//     cout << endl;
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << endl << endl;
//
//     groucho.testPlay();
//     cout << endl;
//     mill.receiveInstr(*groucho.giveBackInstr());
//     harpo.acceptInstr(mill.loanOut());
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;
//}

//// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

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
//
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

} // main


