/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


#include <iostream>

/*
 copied UDT 1:
 */

struct HarmonicSet
{
    HarmonicSet(float bass = 110.f, float gen = 220.f) : 
        bassFrequency(bass), 
        genFrequency(gen), 
        current(gen), 
        previous(bass)
    {
        reset();
    }
    ~HarmonicSet();

    float bassFrequency, genFrequency;
    float current, previous;

    void playSet(float minFrequency, float maxFrequency);

    float calculateHarmonicity();
    float next();
    float prev();
    void reset();

    void playFiltered(float minFrequency, float maxFrequency, int genRule);
};

HarmonicSet::~HarmonicSet()
{
    std::cout << "Destructor of Harmonic Set with bass " << bassFrequency << " and gen " << genFrequency << std::endl;
}

float HarmonicSet::next() 
{
    float temp = current;
    current = previous + current;
    previous = temp;
    return current;
}

float HarmonicSet::prev() 
{
    float temp = previous;
    previous = current - previous;
    current = temp; 
    return current;
}

void HarmonicSet::reset() 
{
    current = genFrequency;
    previous = bassFrequency;
}


void HarmonicSet::playSet(float minFrequency, float maxFrequency)
{
    std::cout << "Harmonic set of bass " << bassFrequency << " and generator " << genFrequency << std::endl;
    float outputNote = (bassFrequency + genFrequency);
    previous = genFrequency;
    while (outputNote < maxFrequency) 
    {
        if (minFrequency < outputNote)
        {
            std::cout << outputNote << " ";
        }
        current = outputNote;
        outputNote += previous;
        previous = current;
    }
    std::cout << std::endl;
}


float HarmonicSet::calculateHarmonicity()
{
    return bassFrequency + genFrequency;
}

void HarmonicSet::playFiltered(float minFrequency, float maxFrequency, int genRule)
{
    float outputNote = (bassFrequency + genFrequency); 
    genRule += 1; 
    if (minFrequency < outputNote)
    {
        if (maxFrequency > outputNote)
        {
            std::cout << outputNote << std::endl;
        }
    }
}


/*
 copied UDT 2:
 */

struct Distortion
{
    Distortion();
    ~Distortion();

    float brightness;
    int numEchoes;
    float roughness;
    int vinylTap;

    void processInput();

    float calculateBrightness(float roomSize, float hiPass, float loPass);

    bool toggleBypass(bool bypass = false);
};

Distortion::Distortion()
{
    brightness = 0.5f;
    numEchoes = 3;
    roughness = 0.8f;
    vinylTap = 11;
}

Distortion::~Distortion()
{
    std::cout << "Distortion switched off" << std::endl;
    for (float shriek = brightness; shriek > 0.03f; shriek *= 0.75f)
    {
        for (int i = int(shriek * 30); i > 0; i -= 1)
        {
            std::cout << "+-";
        }
        std::cout << std::endl;
    }
}

void Distortion::processInput()
{
    std::cout << "DISTORRTIIOOOOON"<< std::endl;
    for (int n = numEchoes; n > 0; n -= 1)
    {
        std::cout << "DISTORRTI";
        for (int m = n; m > 0; m -= 1)
        {
            if (rand() < roughness * RAND_MAX)
            {
                std::cout << "O";
            }
            else
            {
                std::cout << "o";
            }
        }
        std::cout << "N" << std::endl;
    }
}

float Distortion::calculateBrightness(float roomSize, float hiPass, float loPass)
{
    if (roomSize < loPass)
    {
        return loPass;
    }
    if (roomSize > hiPass)
    {
        return hiPass;
    }
    return roomSize;
}

bool Distortion::toggleBypass(bool bypass)
{
    return !bypass;
}

/*
 copied UDT 3:
 */

struct PatternGenerator
{
    PatternGenerator();
    ~PatternGenerator();
    float rootedness;
    float repetitionPercentage;
    int stepSize;
    float variability;
    float fractalDimension;

    struct Pattern
    {
        Pattern();
        bool repeat; 
        int numberOfNotes;  
        int startingNote;  
        bool isArpeggio;    
        std::string patternName;

        void printName();
        void reverse();
        void stop();
    };

    void calculateNote(HarmonicSet harmonies);
    Pattern generatePattern();
};

PatternGenerator::PatternGenerator()
{
    rootedness = 1.0f;
    repetitionPercentage = 0.15f;
    stepSize = 2;
    variability = 1.0f;
    fractalDimension = 1.618f;
}

PatternGenerator::~PatternGenerator()
{
    std::cout << "pattern generator destructor" << std::endl;
}

PatternGenerator::Pattern::Pattern()
{
    repeat = true; 
    numberOfNotes = 5;  
    startingNote = 1;  
    isArpeggio = true;    
    patternName = "spectra";
}

void PatternGenerator::calculateNote(HarmonicSet harmonies)
{
    harmonies.calculateHarmonicity();
}
    
PatternGenerator::Pattern PatternGenerator::generatePattern()
{
    PatternGenerator::Pattern newPattern;
    return newPattern;
}

void PatternGenerator::Pattern::printName()
{
    std::cout << patternName << std::endl;
}

void PatternGenerator::Pattern::reverse()
{

}

void PatternGenerator::Pattern::stop()
{

}


/*
 new UDT 4:
 */

struct PatternPlayer 
{
    PatternPlayer();
    PatternPlayer(float bass, float gen);
    ~PatternPlayer();

    PatternGenerator patternGenerator;
    PatternGenerator::Pattern pattern = patternGenerator.generatePattern();
    HarmonicSet harmonicSet;
    Distortion distortion;

    int currentNote = 1;

    void printDescription();
    void matchNote(int i);
    void play();
};

PatternPlayer::PatternPlayer() 
{
    std::cout << "PatternPlayer default constructor: " << std::endl;
    printDescription();
}

PatternPlayer::PatternPlayer(float bass, float gen)
{
    std::cout << "PatternPlayer constructor with bass " << bass << " and gen " << gen << std::endl;
    harmonicSet.bassFrequency = bass;
    harmonicSet.genFrequency = gen;
    harmonicSet.reset();
    printDescription();
}

PatternPlayer::~PatternPlayer() 
{
    std::cout << "Pattern Player switched off" << std::endl;

}

void PatternPlayer::printDescription () 
{
    std::cout << "Harmonic set: " << harmonicSet.bassFrequency << " and " << harmonicSet.genFrequency << std::endl;
}

void PatternPlayer::matchNote(int i) 
{
    if (i < currentNote) 
    {
        harmonicSet.prev();
        currentNote -= 1;
        std::cout << "matchNote rewind to " << currentNote << std::endl;
        matchNote(i);
    }
    else if (i > currentNote) 
    {
        harmonicSet.next();
        currentNote += 1;
        std::cout << "matchNote forward to " << currentNote << std::endl;
        matchNote(i);
    }
}

void PatternPlayer::play() 
{

    pattern.printName();

    matchNote(pattern.startingNote);
    int endingNote = pattern.startingNote + pattern.numberOfNotes;

    for (int i = pattern.startingNote; i < endingNote; i++) 
    {
        std::cout << harmonicSet.next() << " ";
        currentNote += 1;
        for (int j = 0; j < distortion.numEchoes; j++)
        {
            std::cout << "*";
        }
    }

    if (pattern.repeat)
    {
        std::cout << std::endl;
        std::cout << pattern.startingNote << " and " << currentNote << std::endl;
        matchNote(pattern.startingNote);

        for (int i = pattern.startingNote; i < endingNote; i++) 
        {
            std::cout << harmonicSet.next() << " ";
            currentNote += 1;
            for (int j = 0; j < distortion.numEchoes; j++)
            {
                std::cout << "#";
            }
        }
    }

    std::cout << std::endl;
    
}

/*
 new UDT 5:
 */

struct NoiseMaker 
{
    NoiseMaker();
    ~NoiseMaker();

    Distortion distortion;

    void makeSomeNoise();
};

NoiseMaker::NoiseMaker() 
{
    distortion.brightness = 1.0f;
    distortion.roughness = 0.5f;
    distortion.numEchoes = 6;
}

NoiseMaker::~NoiseMaker() 
{
    std::cout << "Shutting off NoiseMaker" << std::endl;
}

void NoiseMaker::makeSomeNoise() 
{
    distortion.processInput();
}



#include <iostream>
int main()
{

    HarmonicSet hs;
    std::cout << hs.bassFrequency << std::endl;
    std::cout << hs.genFrequency << std::endl;
    std::cout << hs.next() << " ^";
    std::cout << hs.next() << " ^";
    std::cout << hs.next() << " ^";
    std::cout << hs.next() << " v";
    std::cout << hs.prev() << " ^";
    std::cout << hs.next() << " v";
    std::cout << hs.prev() << " v";
    std::cout << hs.prev() << std::endl;

    std::cout << "current: " << hs.current << std::endl;
    std::cout << "previous: " << hs.previous << std::endl;

    HarmonicSet hs2(130.f, 450.f);
    std::cout << hs2.bassFrequency << std::endl;
    std::cout << hs2.genFrequency << std::endl;
    std::cout << hs2.next() << " ^";
    std::cout << hs2.next() << " ^";
    std::cout << hs2.next() << " ^";
    std::cout << hs2.next() << " v";
    std::cout << hs2.prev() << " ^";
    std::cout << hs2.next() << " v";
    std::cout << hs2.prev() << " v";
    std::cout << hs2.prev() << std::endl;

    std::cout << "current: " << hs2.current << std::endl;
    std::cout << "previous: " << hs2.previous << std::endl;

    Distortion distorition;

    PatternPlayer pp;
    pp.play();

    PatternPlayer pp2(440.f, 442.f);
    pp2.distortion.numEchoes = 5;
    pp2.pattern.patternName = "pattern 2";
    pp2.pattern.startingNote = 6;
    pp2.pattern.numberOfNotes = 7;
    pp2.play();

    NoiseMaker nm;
    nm.makeSomeNoise();

    std::cout << "*=-=*=-=*=-=*=-=*=-=* old stuff *=-=*=-=*=-=*=-=*=-=*" << std::endl;

    PatternGenerator::Pattern pattern;
    std::cout << "pattern's name: " << pattern.patternName << std::endl;
    pattern.printName(); // prints the same name

    PatternGenerator pg;
    pg.generatePattern(); // prints "new pattern: 12345"

    Distortion ds;
    ds.processInput();
    std::cout << "brightness: " << ds.calculateBrightness(250.f, 300.f, 100.f) << std::endl;
    std::cout << "brightness: " << ds.calculateBrightness(350.f, 300.f, 200.f) << std::endl;

    HarmonicSet harmonicSet = HarmonicSet(220.0f, 440.0f);
    harmonicSet.playSet(220.0f, 22000.0f);
    HarmonicSet harmonicSetTwo(100.0f, 360.0f);
    harmonicSetTwo.playSet(10.f, 22000.0f);
    std::cout << "Sum of bass and generator is " << harmonicSetTwo.calculateHarmonicity() << std::endl;

    Distortion ds2;
    ds2.processInput();

    ds2.numEchoes = 15;
    ds2.processInput();


    std::cout << "good to go!" << std::endl;
}
