#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <unordered_map> 
std::vector<std::string> allColleges = {

    // ⭐ FBS Schools
    "Boston College","Clemson","Duke","Florida State","Georgia Tech","Louisville","Miami",
    "NC State","North Carolina","Pitt","Syracuse","Virginia","Virginia Tech","Wake Forest",

    "Illinois","Indiana","Iowa","Maryland","Michigan","Michigan State","Minnesota","Nebraska",
    "Northwestern","Ohio State","Penn State","Purdue","Rutgers","Wisconsin",

    "Baylor","BYU","Cincinnati","Houston","Iowa State","Kansas","Kansas State","Oklahoma State",
    "TCU","Texas Tech","UCF","West Virginia",

    "Alabama","Arkansas","Auburn","Florida","Georgia","Kentucky","LSU","Mississippi State",
    "Missouri","Ole Miss","South Carolina","Tennessee","Texas","Texas A&M","Vanderbilt",

    "Arizona","Arizona State","Cal","Colorado","Oregon","Oregon State","Stanford","UCLA","USC",
    "Utah","Washington","Washington State",

    "Charlotte","East Carolina","Florida Atlantic","Memphis","Navy","North Texas","Rice","SMU",
    "South Florida","Temple","Tulane","Tulsa","UAB","UTSA",

    "Air Force","Boise State","Colorado State","Fresno State","Hawaii","Nevada","New Mexico",
    "San Diego State","San Jose State","UNLV","Utah State","Wyoming",

    "Akron","Ball State","Bowling Green","Buffalo","Central Michigan","Eastern Michigan",
    "Kent State","Miami (OH)","Northern Illinois","Ohio","Toledo","Western Michigan",

    "Appalachian State","Arkansas State","Coastal Carolina","Georgia Southern","Georgia State",
    "James Madison","Louisiana","Louisiana-Monroe","Marshall","Old Dominion","South Alabama",
    "Southern Miss","Texas State","Troy",

    "Army","Notre Dame","UConn","UMass",

    "FIU", "Jackson State", "Liberty", "Louisania Tech", "Middle Tennessee", "New Mexico State",
    "Sam Houston", "UTEP", "Western Kentucky", "Kennesaw State",

    // ⭐ FCS Schools (ALL)
    "Abilene Christian","Alabama A&M","Alabama State","Albany","Alcorn State","Arkansas-Pine Bluff",
    "Austin Peay","Bethune-Cookman","Brown","Bryant","Bucknell","Butler","Cal Poly","Campbell",
    "Central Arkansas","Charleston Southern","Chattanooga","Colgate","Columbia","Cornell",
    "Dartmouth","Davidson","Dayton","Delaware","Delaware State","Drake","Duquesne","Eastern Illinois",
    "Eastern Kentucky","Eastern Washington","Elon","Florida A&M","Fordham","Furman","Gardner-Webb",
    "Georgetown","Grambling State","Hampton","Harvard","Holy Cross","Houston Christian","Howard",
    "Idaho","Idaho State","Illinois State","Incarnate Word","Indiana State","Jackson State",
    "Lafayette","Lamar","Lehigh", "West Georgia",
    "Lindenwood","Long Island","Maine","Marist","McNeese State","Mercer","Mississippi Valley State",
    "Missouri State","Monmouth","Montana","Montana State","Morehead State","Morgan State","Murray State",
    "New Hampshire","Nicholls","Norfolk State","North Alabama","North Carolina A&T","North Carolina Central",
    "North Dakota","North Dakota State","Northern Arizona","Northern Colorado","Northern Iowa",
    "Northwestern State","Penn","Portland State","Prairie View A&M","Presbyterian","Princeton",
    "Rhode Island","Richmond","Robert Morris","Sacramento State","Sacred Heart","Saint Francis (PA)",
    "Sam Houston State","Samford","San Diego","Savannah State","SE Louisiana","SE Missouri State",
    "South Carolina State","South Dakota","South Dakota State","Southern","Southern Illinois",
    "Southern Utah","Stetson","Stonehill","Tennessee State","Tennessee Tech","Texas Southern",
    "The Citadel","Towson","UC Davis","UT Martin","Valparaiso","Villanova","VMI","Wagner","Weber State",
    "Western Carolina","Western Illinois","William & Mary","Wofford","Yale","Youngstown State",
};
std::unordered_map<std::string, std::vector<std::string>> hometownMap = {
    // Florida
    {"Florida", {"Jacksonville", "Tampa Bay", "Miami"}},
    {"FSU", {"Jacksonville", "Tampa Bay", "Miami"}},
    {"Miami", {"Miami"}},
    {"UCF", {"Jacksonville", "Tampa Bay"}},
    {"USF", {"Tampa Bay"}},
    {"FIU", {"Miami"}},
    {"FAU", {"Miami"}},

    // Oklahoma
    {"Oklahoma", {"Dallas"}},

    // Texas
    {"Texas", {"Dallas", "Houston"}},
    {"Texas A&M", {"Dallas", "Houston"}},
    {"TCU", {"Dallas"}},
    {"Baylor", {"Dallas"}},
    {"Texas Tech", {"Dallas"}},
    {"SMU", {"Dallas"}},
    {"North Texas", {"Dallas"}},
    {"Tarleton", {"Dallas"}},
    {"Lamar", {"Houston"}},
    {"Houston Christian", {"Houston"}},
    {"SFA", {"Houston"}},
    {"Houston", {"Houston"}},
    {"Sam Houston State", {"Houston"}},
    {"Texas Southern", {"Dallas", "Houston"}},
    {"Rice", {"Houston"}},

    // California
    {"USC", {"Los Angeles", "San Francisco"}},
    {"UCLA", {"Los Angeles"}},
    {"Fresno State", {"San Francisco"}},
    {"Stanford", {"San Francisco"}},
    {"Cal", {"San Francisco"}},
    {"San Jose State", {"San Francisco"}},
    {"San Diego State", {"Los Angeles"}},

    // Ohio
    {"Ohio State", {"Cleveland", "Cincinnati"}},
    {"Kent State", {"Cleveland"}},
    {"Miami (OH)", {"Cincinnati"}},
    {"Ohio", {"Cleveland", "Cincinnati"}},
    {"Bowling Green", {"Detroit", "Cleveland"}},

    // Pennsylvania
    {"Penn State", {"Philadelphia", "Pittsburgh"}},
    {"Pitt", {"Pittsburgh"}},
    {"Temple", {"Philadelphia"}},
    {"Lehigh", {"Philadelphia"}},

    // Alabama
    {"Alabama", {"Tennessee", "Atlanta"}},
    {"Auburn", {"Tennessee", "Atlanta"}},

    // New York
    {"Army", {"New York"}},
    {"Columbia", {"New York"}},
    {"Cornell", {"New York"}},
    {"Colgate", {"New York"}},
    {"Buffalo", {"New York"}},

    // Georgia
    {"Georgia", {"Atlanta"}},
    {"Georgia Tech", {"Atlanta"}},
    {"Kennesaw State", {"Atlanta"}},
    {"Georgia Southern", {"Atlanta"}},

    // Indiana
    {"Notre Dame", {"Chicago", "Detroit"}},
    {"Indiana", {"Indianapolis"}},
    {"Purdue", {"Indianapolis", "Chicago"}},
    {"Ball State", {"Indianapolis"}},

    // Louisiana
    {"LSU", {"New Orleans"}},
    {"Louisiana", {"New Orleans"}},
    {"Nicholls State", {"New Orleans"}},
    {"McNeese State", {"Houston"}},
    {"Tulane", {"New Orleans"}},
    {"Southeastern Louisiana", {"New Orleans"}},

    // Tennessee
    {"Memphis", {"Tennessee"}},
    {"Tennessee", {"Tennessee"}},
    {"Vanderbilt", {"Tennessee"}},

    // Kentucky
    {"Kentucky", {"Cincinnati", "Indianapolis"}},
    {"Louisville", {"Cincinnati", "Indianapolis", "Tennessee"}},

    // North Carolina
    {"Appalachian State", {"Carolina"}},
    {"Duke", {"Carolina"}},
    {"NC State", {"Carolina"}},
    {"UNC", {"Carolina"}},
    {"Wake Forest", {"Carolina"}},

    // Massachusetts
    {"Boston College", {"New England"}},

    // Maryland
    {"Navy", {"Washington", "Baltimore"}},
    {"Maryland", {"Washington", "Baltimore"}},

    // Colorado
    {"Colorado State", {"Denver"}},
    {"Air Force", {"Denver"}},
    {"Colorado", {"Denver"}},

    // Kansas
    {"Kansas State", {"Kansas City"}},
    {"Kansas", {"Kansas City"}},

    // Nevada
    {"UNLV", {"Las Vegas"}},

    // Illinois
    {"Northern Illinois", {"Chicago"}},
    {"Northwestern", {"Chicago"}},
    {"Illinois", {"Chicago"}},

    // Minnesota
    {"Minnesota", {"Minnesota"}},

    // Michigan
    {"Central Michigan", {"Detroit"}},
    {"Eastern Michigan", {"Detroit"}},
    {"Michigan State", {"Detroit"}},
    {"Michigan", {"Detroit"}},
    {"Western Michigan", {"Detroit"}},

    // Washington
    {"Washington", {"Seattle"}},

    // Arizona
    {"Arizona", {"Arizona"}},
    {"Arizona State", {"Arizona"}},
};

// 1) Random helper
int randRange(int min, int max) {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int calculateContractDemand(const Player& p)
{
    // 1. Base salary from overall (FM-style tiering)
    float base = 0.0f;

    if (p.overall >= 90) base = 28000000;
    else if (p.overall >= 85) base = 18000000;
    else if (p.overall >= 80) base = 12000000;
    else if (p.overall >= 75) base = 7000000;
    else if (p.overall >= 70) base = 3500000;
    else if (p.overall >= 65) base = 1800000;
    else if (p.overall >= 60) base = 900000;
    else base = 600000;

    // 2. Position value multiplier (FM-style positional importance)
    static std::unordered_map<std::string, float> posMultiplier = {
        {"QB", 2.2f}, {"WR", 1.6f}, {"CB", 1.6f}, {"EDGE", 1.8f},
        {"DT", 1.4f}, {"OT", 1.5f}, {"LB", 1.2f}, {"RB", 0.9f},
        {"S", 1.1f}, {"C", 1.0f}, {"OG", 1.0f},
        {"K", 0.4f}, {"P", 0.4f}
    };

    float posMult = posMultiplier.count(p.position) ? posMultiplier.at(p.position) : 1.0f;
    base *= posMult;

    // 3. Age curve (FM-style)
    if (p.age <= 24) base *= 1.25f;
    else if (p.age <= 28) base *= 1.10f;
    else if (p.age <= 31) base *= 0.95f;
    else base *= 0.75f;

    // 4. Form / performance multiplier (FM-style)
    float formMult = 1.0f + ((p.form - 6) * 0.08f);
    base *= formMult;

    // 5. Season performance multiplier (FM-style)
    float perfMult = 1.0f + ((p.seasonRating - 6.5f) * 0.15f);
    base *= perfMult;

    // 6. Trait modifiers (FM-style personality system)
    base *= (1.0f + (p.egoTrait - 50) / 300.0f);
    base *= (1.0f - (p.loyaltyTrait - 50) / 500.0f);
    base *= (1.0f - (p.professionalismTrait - 50) / 600.0f);
    base *= (1.0f + (p.divaTrait - 50) / 400.0f);
    base *= (1.0f + (p.volatilityTrait - 50) / 700.0f);

    // 7. Minimum / maximum sanity caps
    if (base < 500000) base = 500000;
    if (base > 60000000) base = 60000000;

    return static_cast<int>(base);
}
// 4) Player definition

struct Player {
    std::string name;
    std::string position;
    std::string college;
    std::string draftedTeam;
    int age;
    int overall;
    int potential;

    // Physical
    int height;
    int weight;
    int speed;
    int strength;
    int agility;
    int stamina;

    // Mental
    int awareness;
    int discipline;
    int morale;
    float form = 6.0f;          // 1–10
    float seasonRating = 6.5f;  // 1–10 average match rating


    // Universal Technical Attributes (every player has these)
    int throwPower;
    int throwAccuracyShort;
    int throwAccuracyMid;
    int throwAccuracyDeep;

    int catchRating;
    int catchInTraffic;
    int spectacularCatch;
    int routeRunningShort;
    int routeRunningMedium;
    int routeRunningDeep;

    int passBlock;
    int runBlock;
    int impactBlock;

    int blockShed;
    int powerMoves;
    int finesseMoves;

    int tackle;
    int hitPower;
    int pursuit;
    int playRecognition;

    int manCoverage;
    int zoneCoverage;
    int pressCoverage;

    int kickPower;
    int kickAccuracy;
    int puntPower;
    int puntAccuracy;

    // Tendencies
    int aggression;        // 1–100
    int riskTaking;        // 1–100
    int consistency;       // 1–100
    int clutch;            // 1–100
    int leadership;        // 1–100
    int motor;             // 1–100
    int disciplineTendency;// 1–100 (separate from discipline rating)
    int playStyle;         // 0–10 (archetype ID)

    // Traits
    int leadershipTrait;
    int volatilityTrait;
    int workEthicTrait;
    int divaTrait;
    int loyaltyTrait;
    int clutchGeneTrait;
    int trashTalkTrait;
    int professionalismTrait;
    int mentorTrait;
    int egoTrait;
    int mediaFriendlyTrait;
    int enigmaticTrait;
    int hometownHeroTrait; 

    // Health
    bool injured;
    int injuryWeeks;

    // Finance
    int contractYears;
    int contractSalary;      // yearly salary
    int contractBonus;       // signing bonus
    int contractTotalValue;  // salary * years + bonus
    int contractDemand;      // what they WANT
    bool wantsExtension;
    bool holdingOut;

    Player(std::string n, std::string pos, int o)
        : name(std::move(n)), position(std::move(pos)),
        age(randRange(21, 40)),
        overall(o),
        potential(o + randRange(1, 15)),
        college("Unknown"),
        draftedTeam("Unknown"),

        // Physical
        speed(0), strength(0), agility(0), stamina(100),

        // Mental
        awareness(0), discipline(0), morale(5),

        // Technical
        throwPower(0), throwAccuracyShort(0), throwAccuracyMid(0), throwAccuracyDeep(0),
        catchRating(0), catchInTraffic(0), spectacularCatch(0),
        routeRunningShort(0), routeRunningMedium(0), routeRunningDeep(0),
        passBlock(0), runBlock(0), impactBlock(0),
        blockShed(0), powerMoves(0), finesseMoves(0),
        tackle(0), hitPower(0), pursuit(0), playRecognition(0),
        manCoverage(0), zoneCoverage(0), pressCoverage(0),
        kickPower(0), kickAccuracy(0), puntPower(0), puntAccuracy(0),

        // Tendencies
        aggression(0), riskTaking(0), consistency(0), clutch(0),
        leadership(0), motor(0), disciplineTendency(0), playStyle(0),

        // Behavior Traits
        leadershipTrait(0), volatilityTrait(0), workEthicTrait(0),
        divaTrait(0), loyaltyTrait(0), clutchGeneTrait(0),
        trashTalkTrait(0), professionalismTrait(0), mentorTrait(0),
        egoTrait(0), mediaFriendlyTrait(0), enigmaticTrait(0),
        hometownHeroTrait(0),

        // Health
        injured(false), injuryWeeks(0),

        // Contract
        contractYears(0),
        contractSalary(0),
        contractBonus(0),
        contractTotalValue(0),
        contractDemand(0),
        wantsExtension(false),
        holdingOut(false)

    {

    }
};
std::vector<Player> generateDraftClass() {
    std::vector<Player> draftClass;
    draftClass.reserve(256);

    for (int pick = 1; pick <= 256; pick++) {

        int round = (pick - 1) / 32 + 1;

        // 1. Generate name + position
        std::string name = generateRandomName();
        std::string pos = generateRandomPosition();

        // 2. Generate OVR (rare generational players)
        int ovr = 0;

        if (round == 1) {
            int roll = randRange(1, 1000);

            if (roll == 1) ovr = randRange(85, 90);        // generational (0.1%)
            else if (roll <= 30) ovr = randRange(80, 84);  // elite (3%)
            else ovr = randRange(74, 79);                  // normal 1st rounder
        }
        else if (round == 2) ovr = randRange(70, 75);
        else if (round == 3) ovr = randRange(68, 73);
        else if (round == 4) ovr = randRange(65, 70);
        else if (round == 5) ovr = randRange(63, 68);
        else if (round == 6) ovr = randRange(61, 66);
        else ovr = randRange(60, 64); // Round 7

        // 3. Create player
        Player p(name, pos, ovr);

        // 4. Generate attributes
        generateAttributesForPosition(p);

        // 5. Apply rookie contract
        applyRookieContract(p, round, pick);

        // 6. Add to draft class
        draftClass.push_back(p);
    }

    return draftClass;
}
// 4) Function definition AFTER Player
void generateAttributesForPosition(Player& p) {
    if (p.position == "QB") {
        // Physical
        p.speed = randRange(55, 75);
        p.strength = randRange(50, 70);
        p.agility = randRange(60, 80);
        // Mental
        p.awareness = randRange(70, 95);
        p.discipline = randRange(6, 10);
        p.morale = randRange(5, 10);
        // Technical
        p.throwPower = randRange(80, 99);
        p.throwAccuracyShort = randRange(75, 95);
        p.throwAccuracyMid = randRange(70, 92);
        p.throwAccuracyDeep = randRange(65, 90);

        p.catchRating = randRange(20, 40);
        p.runBlock = randRange(5, 20);

        p.tackle = randRange(10, 30);
        p.manCoverage = randRange(5, 20);
        p.zoneCoverage = randRange(5, 20);

        p.kickPower = randRange(5, 20);
        p.puntPower = randRange(5, 20);
        // Tendencies
        p.aggression = randRange(20, 60);
        p.riskTaking = randRange(30, 95);  // gunslinger vs safe
        p.consistency = randRange(40, 90);
        p.clutch = randRange(40, 99);
        p.leadership = randRange(60, 99);
        p.motor = randRange(30, 60);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = randRange(0, 3); // 0 Pocket, 1 Scrambler, 2 Balanced, 3 Gunslinger

        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = weighted(40, 70, 85);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "RB") {
        // Physical
        p.speed = randRange(80, 97);
        p.strength = randRange(65, 85);
        p.agility = randRange(80, 97);
        // Mental
        p.awareness = randRange(60, 85);
        p.discipline = randRange(4, 10);
        p.morale = randRange(4, 10);
       // Technical
        p.catchRating = randRange(50, 80);
        p.catchInTraffic = randRange(40, 70);
        p.spectacularCatch = randRange(30, 60);

        p.routeRunningShort = randRange(40, 70);
        p.routeRunningMedium = randRange(30, 60);

        p.passBlock = randRange(40, 70);
        p.runBlock = randRange(30, 60);

        p.tackle = randRange(20, 40);
        p.pursuit = randRange(20, 40);
        // Tendencies
        p.aggression = randRange(60, 95);
        p.riskTaking = randRange(40, 80);
        p.consistency = randRange(40, 85);
        p.clutch = randRange(40, 90);
        p.leadership = randRange(20, 60);
        p.motor = randRange(70, 99);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = randRange(4, 6); // 4 Power, 5 Elusive, 6 Receiving
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);
       
    }
    else if (p.position == "WR") {
        // Physical
        p.speed = randRange(85, 99);
        p.strength = randRange(50, 70);
        p.agility = randRange(85, 99);
        // Mental
        p.awareness = randRange(60, 85);
        p.discipline = randRange(5, 10);
        p.morale = randRange(4, 10);
        p.catchRating = randRange(70, 99);
        p.catchInTraffic = randRange(60, 95);
        p.spectacularCatch = randRange(70, 99);
        // Technical
        p.routeRunningShort = randRange(70, 95);
        p.routeRunningMedium = randRange(70, 95);
        p.routeRunningDeep = randRange(70, 99);

        p.passBlock = randRange(20, 40);
        p.runBlock = randRange(30, 50);

        p.tackle = randRange(20, 40);
        // Tendencies
        p.aggression = randRange(40, 75);
        p.riskTaking = randRange(50, 95); // deep threats take risks
        p.consistency = randRange(30, 85);
        p.clutch = randRange(40, 99);
        p.leadership = randRange(20, 70);
        p.motor = randRange(40, 75);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = randRange(7, 10); // 7 Deep Threat, 8 Slot, 9 Possession, 10 Gadget
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "TE") {
        // Physical
        p.speed = randRange(70, 88);   // slower than WR, faster than most OL
        p.strength = randRange(70, 90);   // strong enough to block
        p.agility = randRange(70, 88);   // decent but not WR-level
        // Mental
        p.awareness = randRange(65, 90);   // smart players, find soft zones
        p.discipline = randRange(5, 10);    // generally reliable
        p.morale = randRange(4, 10);
        // Technical
        p.catchRating = randRange(60, 90);
        p.catchInTraffic = randRange(60, 90);
        p.spectacularCatch = randRange(50, 80);

        p.routeRunningShort = randRange(55, 80);
        p.routeRunningMedium = randRange(50, 75);
        p.routeRunningDeep = randRange(30, 65);

        p.passBlock = randRange(50, 75);
        p.runBlock = randRange(55, 80);
        p.impactBlock = randRange(60, 85);

        p.tackle = randRange(30, 50);
        // Tendencies
        p.aggression = randRange(50, 85);
        p.riskTaking = randRange(30, 70);
        p.consistency = randRange(40, 90);
        p.clutch = randRange(40, 95);
        p.leadership = randRange(40, 80);
        p.motor = randRange(50, 85);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = randRange(11, 13); // 11 Blocking, 12 Vertical, 13 Balanced
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "C") {
        // Physical
        p.speed = randRange(55, 80);
        p.strength = randRange(75, 95); // strongest OL position
        p.agility = randRange(60, 80);
        // Mental
        p.awareness = randRange(75, 99);
        p.discipline = randRange(6, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.passBlock = randRange(75, 95);
        p.runBlock = randRange(75, 95);
        p.impactBlock = randRange(80, 99);

        p.blockShed = randRange(20, 40);
        p.tackle = randRange(30, 50);
        // Tendencies
        p.aggression = randRange(70, 99);
        p.riskTaking = randRange(10, 30);
        p.consistency = randRange(60, 99);
        p.clutch = randRange(40, 80);
        p.leadership = randRange(50, 99);
        p.motor = randRange(60, 95);
        p.disciplineTendency = randRange(10, 40);
        p.playStyle = randRange(14, 16); // 14 Power, 15 Agile, 16 Balanced
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "OG") {
        p.speed = randRange(50, 68);
        p.strength = randRange(80, 99);   // strongest OL position
        p.agility = randRange(55, 75);
        p.awareness = randRange(65, 90);
        p.discipline = randRange(5, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.passBlock = randRange(70, 95);
        p.runBlock = randRange(80, 95);
        p.impactBlock = randRange(80, 99);
        // Tendencies
        p.aggression = randRange(70, 99);
        p.riskTaking = randRange(10, 30);
        p.consistency = randRange(60, 99);
        p.clutch = randRange(40, 80);
        p.leadership = randRange(50, 99);
        p.motor = randRange(60, 95);
        p.disciplineTendency = randRange(10, 40);
        p.playStyle = randRange(14, 16); // 14 Power, 15 Agile, 16 Balanced
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "OT") {
        p.speed = randRange(60, 78);
        p.strength = randRange(70, 90);
        p.agility = randRange(65, 85);   // best footwork on OL
        p.awareness = randRange(70, 95);
        p.discipline = randRange(5, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.passBlock = randRange(80, 99);
        p.runBlock = randRange(70, 90);
        p.impactBlock = randRange(75, 95);
        // Tendencies
        p.aggression = randRange(70, 99);
        p.riskTaking = randRange(10, 30);
        p.consistency = randRange(60, 99);
        p.clutch = randRange(40, 80);
        p.leadership = randRange(50, 99);
        p.motor = randRange(60, 95);
        p.disciplineTendency = randRange(10, 40);
        p.playStyle = randRange(14, 16); // 14 Power, 15 Agile, 16 Balanced
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "DT") {
        p.speed = randRange(50, 70);
        p.strength = randRange(85, 99);   // strongest on defense
        p.agility = randRange(55, 75);
        p.awareness = randRange(65, 90);
        p.discipline = randRange(4, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.blockShed = randRange(80, 99);
        p.powerMoves = randRange(75, 95);
        p.finesseMoves = randRange(50, 75);

        p.tackle = randRange(70, 95);
        p.hitPower = randRange(70, 95);
        // Tendencies
        p.aggression = randRange(80, 99);
        p.riskTaking = randRange(40, 90);
        p.consistency = randRange(40, 90);
        p.clutch = randRange(40, 95);
        p.leadership = randRange(30, 80);
        p.motor = randRange(80, 99); // high motor guys dominate
        p.disciplineTendency = randRange(20, 70);
        p.playStyle = randRange(17, 20); // 17 Power Rusher, 18 Speed Rusher, 19 Run Stopper, 20 Hybrid
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "DE") {
        p.speed = randRange(65, 85);
        p.strength = randRange(70, 90);
        p.agility = randRange(65, 85);
        p.awareness = randRange(60, 90);
        p.discipline = randRange(4, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.blockShed = randRange(70, 95);
        p.powerMoves = randRange(65, 90);
        p.finesseMoves = randRange(65, 90);

        p.tackle = randRange(65, 90);
        // Tendencies
        p.aggression = randRange(80, 99);
        p.riskTaking = randRange(40, 90);
        p.consistency = randRange(40, 90);
        p.clutch = randRange(40, 95);
        p.leadership = randRange(30, 80);
        p.motor = randRange(80, 99); // high motor guys dominate
        p.disciplineTendency = randRange(20, 70);
        p.playStyle = randRange(17, 20); // 17 Power Rusher, 18 Speed Rusher, 19 Run Stopper, 20 Hybrid
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "EDGE") {
        p.speed = randRange(75, 95);   // fastest DL
        p.strength = randRange(65, 85);
        p.agility = randRange(75, 95);   // elite bend + quickness
        p.awareness = randRange(65, 90);
        p.discipline = randRange(4, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.blockShed = randRange(70, 90);
        p.finesseMoves = randRange(75, 99);
        p.powerMoves = randRange(60, 85);

        p.pursuit = randRange(75, 99);
        // Tendencies
        p.aggression = randRange(80, 99);
        p.riskTaking = randRange(40, 90);
        p.consistency = randRange(40, 90);
        p.clutch = randRange(40, 95);
        p.leadership = randRange(30, 80);
        p.motor = randRange(80, 99); // high motor guys dominate
        p.disciplineTendency = randRange(20, 70);
        p.playStyle = randRange(17, 20); // 17 Power Rusher, 18 Speed Rusher, 19 Run Stopper, 20 Hybrid
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "SAM") {
        // Physical
        p.speed = randRange(70, 85);   // athletic but not elite
        p.strength = randRange(75, 95);   // must take on TEs & tackles
        p.agility = randRange(65, 85);
        p.awareness = randRange(65, 90);
       // Mental
        p.discipline = randRange(5, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.tackle = randRange(70, 95);
        p.blockShed = randRange(65, 90);
        p.powerMoves = randRange(50, 75);
        
        p.manCoverage = randRange(50, 75);
        p.zoneCoverage = randRange(55, 80);
        p.pressCoverage = randRange(60, 85);
        // Tendencies
        p.aggression = randRange(75, 99);
        p.riskTaking = randRange(40, 70);
        p.consistency = randRange(50, 90);
        p.clutch = randRange(40, 90);
        p.leadership = randRange(40, 80);
        p.motor = randRange(70, 99);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = 21; // Edge-setting enforcer
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "MIKE") {
        // Physical
        p.speed = randRange(65, 82);   // not the fastest
        p.strength = randRange(75, 95);   // strong interior presence
        p.agility = randRange(60, 80);
        // Mental
        p.awareness = randRange(75, 99);   // highest awareness on defense
        p.discipline = randRange(6, 10);    // reliable leader
        p.morale = randRange(4, 10);
        // Tecnhical
        p.tackle = randRange(75, 99);
        p.blockShed = randRange(70, 95);
        p.playRecognition = randRange(75, 99);

        p.zoneCoverage = randRange(50, 70);
        p.manCoverage = randRange(45, 65);
        // Tendencies
        p.aggression = randRange(60, 85);
        p.riskTaking = randRange(20, 50);
        p.consistency = randRange(70, 99);
        p.clutch = randRange(50, 95);
        p.leadership = randRange(70, 99); // captain
        p.motor = randRange(60, 90);
        p.disciplineTendency = randRange(10, 40);
        p.playStyle = 22; // Field general
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "WILL") {
        p.speed = randRange(80, 95);   // fastest LB type
        p.strength = randRange(60, 80);   // weaker than SAM/MIKE
        p.agility = randRange(75, 95);   // elite movement
        p.awareness = randRange(60, 85);
        p.discipline = randRange(4, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.manCoverage = randRange(65, 90);
        p.zoneCoverage = randRange(70, 95);
        p.pressCoverage = randRange(50, 75);

        p.pursuit = randRange(75, 99);
        p.tackle = randRange(60, 85);
        p.blockShed = randRange(40, 65);   // weaker vs blocks
        p.playRecognition = randRange(60, 85);   // good but not MIKE
        p.hitPower = randRange(50, 75);   // not a thumper
        p.powerMoves = randRange(30, 55);   // low pass rush
        p.finesseMoves = randRange(40, 65);   // some finesse ability
        // Tendencies
        p.aggression = randRange(60, 85);
        p.riskTaking = randRange(50, 90);
        p.consistency = randRange(40, 85);
        p.clutch = randRange(40, 90);
        p.leadership = randRange(30, 70);
        p.motor = randRange(70, 99);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = 23; // Coverage/pursuit specialist
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);


    }
    else if (p.position == "CB") {
        p.speed = randRange(88, 99);   // elite speed
        p.strength = randRange(45, 65);
        p.agility = randRange(90, 99);   // best agility in football
        p.awareness = randRange(65, 95);
        p.discipline = randRange(4, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.manCoverage = randRange(75, 99);
        p.zoneCoverage = randRange(70, 95);
        p.pressCoverage = randRange(70, 95);

        p.catchRating = randRange(40, 70);
        p.pursuit = randRange(60, 85);
        p.tackle = randRange(40, 65);
        // Tendencies
        p.aggression = randRange(50, 90);
        p.riskTaking = randRange(50, 95); // ball hawks gamble
        p.consistency = randRange(40, 90);
        p.clutch = randRange(40, 99);
        p.leadership = randRange(20, 70);
        p.motor = randRange(50, 85);
        p.disciplineTendency = randRange(20, 70);
        p.playStyle = randRange(24, 27); // 24 Man, 25 Zone, 26 Press, 27 Ball Hawk
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "FS") {
        // Physical
        p.speed = randRange(82, 95);
        p.strength = randRange(50, 70);
        p.agility = randRange(80, 95);
        // Mental
        p.awareness = randRange(70, 99);   // highest DB awareness
        p.discipline = randRange(5, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.zoneCoverage = randRange(75, 99);
        p.manCoverage = randRange(60, 85);
        p.pursuit = randRange(70, 95);
        p.tackle = randRange(55, 80);
        // Tendencies
        p.aggression = randRange(40, 75);
        p.riskTaking = randRange(50, 95);
        p.consistency = randRange(50, 90);
        p.clutch = randRange(40, 95);
        p.leadership = randRange(40, 80);
        p.motor = randRange(50, 85);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = 28; // Center fielder
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "SS") {
        p.speed = randRange(75, 90);
        p.strength = randRange(65, 85);   // physical enforcer
        p.agility = randRange(70, 88);
        p.awareness = randRange(65, 90);
        p.discipline = randRange(5, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.zoneCoverage = randRange(60, 85);
        p.manCoverage = randRange(50, 75);

        p.tackle = randRange(70, 95);
        p.hitPower = randRange(70, 95);
        // Tendencies
        p.aggression = randRange(70, 99);
        p.riskTaking = randRange(40, 80);
        p.consistency = randRange(50, 90);
        p.clutch = randRange(40, 95);
        p.leadership = randRange(40, 80);
        p.motor = randRange(70, 99);
        p.disciplineTendency = randRange(20, 60);
        p.playStyle = 29; // Box enforcer
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "K") {
        p.speed = randRange(40, 60);
        p.strength = randRange(60, 85);   // leg power
        p.agility = randRange(40, 60);
        p.awareness = randRange(60, 90);
        p.discipline = randRange(7, 10);    // must be consistent
        p.morale = randRange(4, 10);
        // Technical
        p.kickPower = randRange(80, 99);
        p.kickAccuracy = randRange(75, 99);
        // Tendencies
        p.aggression = randRange(1, 20);
        p.riskTaking = randRange(1, 20);
        p.consistency = randRange(60, 99);
        p.clutch = randRange(60, 99);
        p.leadership = randRange(20, 60);
        p.motor = randRange(10, 40);
        p.disciplineTendency = randRange(1, 20);
        p.playStyle = 30; // Pure specialist
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else if (p.position == "P") {
        p.speed = randRange(40, 60);
        p.strength = randRange(65, 90);   // leg power
        p.agility = randRange(45, 65);
        p.awareness = randRange(65, 95);   // directional punting
        p.discipline = randRange(6, 10);
        p.morale = randRange(4, 10);
        // Technical
        p.puntPower = randRange(80, 99);
        p.puntAccuracy = randRange(75, 99);
        // Tendencies
        p.aggression = randRange(1, 20);
        p.riskTaking = randRange(1, 20);
        p.consistency = randRange(60, 99);
        p.clutch = randRange(40, 90);
        p.leadership = randRange(20, 60);
        p.motor = randRange(10, 40);
        p.disciplineTendency = randRange(1, 20);
        p.playStyle = 31; // Field position specialist
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

    }
    else {
        // Physical
        p.speed = randRange(60, 90);
        p.strength = randRange(60, 90);
        p.agility = randRange(60, 90);

        // Mental
        p.awareness = randRange(50, 90);
        p.discipline = randRange(1, 10);
        p.morale = randRange(1, 10);

        // Technical (generic averages)
        p.throwPower = randRange(20, 60);
        p.throwAccuracyShort = randRange(20, 60);
        p.throwAccuracyMid = randRange(20, 60);
        p.throwAccuracyDeep = randRange(20, 60);

        p.catchRating = randRange(20, 60);
        p.catchInTraffic = randRange(20, 60);
        p.spectacularCatch = randRange(20, 60);

        p.routeRunningShort = randRange(20, 60);
        p.routeRunningMedium = randRange(20, 60);
        p.routeRunningDeep = randRange(20, 60);

        p.passBlock = randRange(20, 60);
        p.runBlock = randRange(20, 60);
        p.impactBlock = randRange(20, 60);

        p.blockShed = randRange(20, 60);
        p.powerMoves = randRange(20, 60);
        p.finesseMoves = randRange(20, 60);

        p.tackle = randRange(20, 60);
        p.hitPower = randRange(20, 60);
        p.pursuit = randRange(20, 60);
        p.playRecognition = randRange(20, 60);

        p.manCoverage = randRange(20, 60);
        p.zoneCoverage = randRange(20, 60);
        p.pressCoverage = randRange(20, 60);

        p.kickPower = randRange(20, 60);
        p.kickAccuracy = randRange(20, 60);
        p.puntPower = randRange(20, 60);
        p.puntAccuracy = randRange(20, 60);
        }
        // UNIVERSAL TRAIT GENERATION (any position can get any trait)
        p.leadershipTrait = randRange(1, 100);
        p.volatilityTrait = randRange(1, 100);
        p.workEthicTrait = randRange(1, 100);
        p.divaTrait = randRange(1, 100);
        p.loyaltyTrait = randRange(1, 100);
        p.clutchGeneTrait = randRange(1, 100);
        p.trashTalkTrait = randRange(1, 100);
        p.professionalismTrait = randRange(1, 100);
        p.mentorTrait = randRange(1, 100);
        p.egoTrait = randRange(1, 100);
        p.mediaFriendlyTrait = randRange(1, 100);
        p.enigmaticTrait = randRange(1, 100);

}



struct Team {
    std::string name;
    std::string city;
    std::string abbreviation;
    std::vector<Player> roster;

    int offenseRating;
    int defenseRating;

    int wins;
    int losses;

    int teamMorale;
    int chemistry;
    int fanInterest;

    int capSpace;
    int totalPayroll;

    Team(std::string teamName, std::string teamCity, std::string abbr, int off, int def)
        : name(std::move(teamName)),
        city(std::move(teamCity)),
        abbreviation(std::move(abbr)),
        offenseRating(off),
        defenseRating(def),
        wins(0),
        losses(0),
        teamMorale(50),
        chemistry(50),
        fanInterest(50),
        capSpace(301200000),
        totalPayroll(0)
    {
    }

    void addPlayer(const Player& p) {
        roster.push_back(p);
    }

    int overallRating() const {
        return (offenseRating + defenseRating) / 2;
    }
};
void applyLeadershipAura(Team& team);
void applyMentorBoosts(Team& team);
void applyVolatilityChaos(Team& team);
void applyHometownHero(Player& p, Team& team);
// 1. Cap hit calculation
int calculateCapHit(const Player& p) {
    if (p.contractYears <= 0) return 0;
    return p.contractSalary + (p.contractBonus / p.contractYears);
}

// 2. Update team payroll + cap space
void updateTeamPayroll(Team& team) {
    int total = 0;

    for (const Player& p : team.roster) {
        total += calculateCapHit(p);
    }

    team.totalPayroll = total;
    team.capSpace = 301200000 - total; // NFL-style cap
}

// 3. Sign a player (assign contract + check cap)
bool signPlayer(Team& team, Player& p, int years, int salary, int bonus) {
    p.contractYears = years;
    p.contractSalary = salary;
    p.contractBonus = bonus;
    p.contractTotalValue = years * salary + bonus;

    int capHit = calculateCapHit(p);

    if (team.capSpace < capHit) {
        return false; // Not enough cap space
    }

    team.roster.push_back(p);
    updateTeamPayroll(team);
    return true;
}

// 4. Release a player (dead money applies)
void releasePlayer(Team& team, int index) {
    Player& p = team.roster[index];

    int capHit = calculateCapHit(p);
    int deadMoney = (p.contractBonus / p.contractYears);

    team.totalPayroll -= capHit;
    team.capSpace += capHit;
    team.capSpace -= deadMoney;

    team.roster.erase(team.roster.begin() + index);
}

void updateTeamDynamics(Team& team) {
    applyLeadershipAura(team);
    applyMentorBoosts(team);
    applyVolatilityChaos(team);

    // Recalculate chemistry
    int avgPro = 0;
    int avgVol = 0;

    for (auto& p : team.roster) {
        avgPro += p.professionalismTrait;
        avgVol += p.volatilityTrait;
    }

    if (!team.roster.empty()) {
        avgPro /= team.roster.size();
        avgVol /= team.roster.size();
    }

    team.chemistry = avgPro - (avgVol / 2);
    team.chemistry = std::clamp(team.chemistry, 0, 100);
}
void applyLeadershipAura(Team& team) {
    for (Player& leader : team.roster) {
        if (leader.leadershipTrait >= 85) {
            for (Player& teammate : team.roster) {
                if (&teammate != &leader) {
                    teammate.overall += 5;
                }
            }
        }
    }
}
void applyMentorBoosts(Team& team) {
    for (Player& mentor : team.roster) {
        if (mentor.mentorTrait >= 80) {
            for (Player& rookie : team.roster) {
                if (rookie.age <= 23) {
                    rookie.potential += 3;
                    rookie.morale += 5;
                }
            }
        }
    }
}
void applyVolatilityChaos(Team& team) {
    for (Player& p : team.roster) {
        if (p.volatilityTrait >= 90 && p.enigmaticTrait >= 80) {
            team.chemistry -= 5;
            team.teamMorale -= 5;
        }
    }
}
void applyHometownHero(Player& p, Team& team) {
    if (p.hometownHeroTrait < 80) return;

    auto it = hometownMap.find(p.college);
    if (it == hometownMap.end()) return;

    const auto& validCities = it->second;

    if (std::find(validCities.begin(), validCities.end(), team.city) != validCities.end()) {
        p.morale += 10;
        p.loyaltyTrait += 20;
        p.professionalismTrait += 10;
        p.contractDemand = static_cast<int>(p.contractDemand * 0.85);
        team.fanInterest += 5;
    }
}
struct GameResult {
    int homeScore;
    int awayScore;
};

class GameSimulator {
public:
    GameSimulator() {
        rng.seed(static_cast<unsigned>(std::time(nullptr)));
    }

    GameResult simulateGame(Team& home, Team& away,
        int homeAggression, int awayAggression) {
        // Very simple model: base on ratings + aggression + randomness
        std::uniform_int_distribution<int> dist(-10, 10);

        int homeBase = home.offenseRating - away.defenseRating / 2;
        int awayBase = away.offenseRating - home.defenseRating / 2;

        homeBase += homeAggression;
        awayBase += awayAggression;

        homeBase += dist(rng);
        awayBase += dist(rng);

        int homeScore = clampScore(homeBase);
        int awayScore = clampScore(awayBase);

        // Update W/L
        if (homeScore > awayScore) {
            home.wins++;
            away.losses++;
        }
        else if (awayScore > homeScore) {
            away.wins++;
            home.losses++;
        }
        else {
            // Overtime coin flip
            if (dist(rng) >= 0) {
                homeScore++;
                home.wins++;
                away.losses++;
            }
            else {
                awayScore++;
                away.wins++;
                home.losses++;
            }
        }

        // Simple stamina/morale changes
        applyPostGameEffects(home, homeScore > awayScore);
        applyPostGameEffects(away, awayScore > homeScore);

        return { homeScore, awayScore };
    }

private:
    std::mt19937 rng;

    static int clampScore(int base) {
        if (base < 3) base = 3;
        if (base > 45) base = 45;
        return base;
    }

    void applyPostGameEffects(Team& team, bool won) {
        for (auto& p : team.roster) {
            p.stamina = std::max(0, p.stamina - 5);
            if (won) {
                p.morale = std::min(100, p.morale + 3);
            }
            else {
                p.morale = std::max(0, p.morale - 3);
            }
        }
    }
};

class League {
public:
    std::vector<Team> teams;
    int currentWeek = 1;
    int totalWeeks = 8; // small test league

    League() = default;

    void addTeam(const Team& t) {
        teams.push_back(t);
    }

    void printStandings() const {
        std::cout << "\n=== Standings ===\n";
        for (const auto& t : teams) {
            std::cout << t.name << "  "
                << t.wins << "-" << t.losses
                << " (Ovr " << t.overallRating() << ")\n";
        }
        std::cout << "=================\n";
    }

    void simulateWeek(GameSimulator& sim, int userTeamIndex) {
        std::cout << "\n--- Week " << currentWeek << " ---\n";

        // Simple pairing: team 0 vs 1, 2 vs 3, etc.
        for (size_t i = 0; i + 1 < teams.size(); i += 2) {
            bool userInGame = (static_cast<int>(i) == userTeamIndex ||
                static_cast<int>(i + 1) == userTeamIndex);

            int homeAgg = 0, awayAgg = 0;
            if (userInGame) {
                // Let user choose aggression if their team is in this game
                bool userIsHome = (static_cast<int>(i) == userTeamIndex);
                int choice = chooseAggression(userIsHome ? teams[i] : teams[i + 1]);
                if (userIsHome) {
                    homeAgg = choice;
                    awayAgg = 0;
                }
                else {
                    awayAgg = choice;
                    homeAgg = 0;
                }
            }

            GameResult result = sim.simulateGame(teams[i], teams[i + 1],
                homeAgg, awayAgg);

            std::cout << teams[i].name << " " << result.homeScore
                << " - " << result.awayScore << " " << teams[i + 1].name
                << "\n";
        }

        currentWeek++;
        if (currentWeek > totalWeeks) {
            std::cout << "\nRegular season finished!\n";
        }
    }

    bool seasonFinished() const {
        return currentWeek > totalWeeks;
    }

private:
    int chooseAggression(const Team& userTeam) {
        std::cout << "\nYou are coaching: " << userTeam.name << "\n";
        std::cout << "Choose offensive aggression level:\n";
        std::cout << "1) Conservative\n";
        std::cout << "2) Balanced\n";
        std::cout << "3) Aggressive\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1: return -5;
        case 3: return 5;
        default: return 0;
        }
    }
};

void printRoster(const Team& t) {
    std::cout << "\nRoster for " << t.name << ":\n";
    for (const auto& p : t.roster) {
        std::cout << p.name << " (" << p.position << ") "
            << "OVR " << p.overall
            << " STA " << p.stamina
            << " MOR " << p.morale << "\n";
    }
}

void mainMenu() {
    std::cout << "\n=== American Football Manager (Prototype) ===\n";
    std::cout << "1) View team roster\n";
    std::cout << "2) View league standings\n";
    std::cout << "3) Advance to next week\n";
    std::cout << "4) Quit\n";
    std::cout << "Choose: ";
}

void loadCowboysRoster(Team& cowboys) {

    // === QUARTERBACKS ===
    {
        Player p("Dak Prescott", "QB", 91);
        generateAttributesForPosition(p);

        p.college = "Mississippi State";
        p.draftedTeam = "DAL";
        p.age = 33;

        p.height = 74;
        p.weight = 238;

        p.injured = false;
        p.injuryWeeks = 0;

        p.contractYears = 4;
        p.contractSalary = 47000000;
        p.contractBonus = 25000000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 50000000;
        p.wantsExtension = true;
        p.holdingOut = false;

        p.awareness = std::max(p.awareness, 92);
        p.throwPower = std::max(p.throwPower, 90);
        p.throwAccuracyShort = std::max(p.throwAccuracyShort, 94);
        p.throwAccuracyMid = std::max(p.throwAccuracyMid, 92);
        p.throwAccuracyDeep = std::max(p.throwAccuracyDeep, 86);
        p.consistency = std::max(p.consistency, 88);
        p.clutch = std::max(p.clutch, 90);
        p.leadership = std::max(p.leadership, 95);

        p.leadershipTrait = 90;
        p.volatilityTrait = 20;
        p.workEthicTrait = 95;
        p.divaTrait = 20;
        p.loyaltyTrait = 85;
        p.clutchGeneTrait = 90;
        p.trashTalkTrait = 40;
        p.professionalismTrait = 98;
        p.mentorTrait = 90;
        p.egoTrait = 55;
        p.mediaFriendlyTrait = 85;
        p.enigmaticTrait = 20;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }
    // Sam Howell — QB — 65 OVR
    {
        Player p("Sam Howell", "QB", 65);
        generateAttributesForPosition(p);

        p.college = "North Carolina";
        p.draftedTeam = "WAS";
        p.age = 25;

        p.height = 73;   // 6'1"
        p.weight = 220;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract
        p.contractYears = 2;
        p.contractSalary = 1500000;
        p.contractBonus = 200000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 2500000;
        p.wantsExtension = false;
        p.holdingOut = false;

        // Physical (from Madden 26 baselines)
        p.speed = 82;
        p.strength = 64;
        p.agility = 78;
        p.stamina = 92;      // scaled from INJ 93

        // Mental
        p.awareness = 51;
        p.discipline = 60;
        p.morale = 75;

        // QB Throwing Attributes (realistic to Howell)
        p.throwPower = 88;
        p.throwAccuracyShort = 74;
        p.throwAccuracyMid = 70;
        p.throwAccuracyDeep = 72;

        // Receiving (QB baseline)
        p.catchRating = 40;
        p.catchInTraffic = 35;
        p.spectacularCatch = 30;

        // Route running (irrelevant)
        p.routeRunningShort = 25;
        p.routeRunningMedium = 20;
        p.routeRunningDeep = 15;

        // Blocking (QB baseline)
        p.passBlock = 25;
        p.runBlock = 25;
        p.impactBlock = 25;

        // Defense (QB baseline)
        p.blockShed = 25;
        p.powerMoves = 20;
        p.finesseMoves = 20;
        p.tackle = 30;
        p.hitPower = 25;
        p.pursuit = 30;
        p.playRecognition = 40;
        p.manCoverage = 20;
        p.zoneCoverage = 20;
        p.pressCoverage = 20;

        // Tendencies (Howell‑accurate)
        p.aggression = 85;          // gunslinger
        p.riskTaking = 90;          // high TWP rate
        p.consistency = 55;
        p.clutch = 60;
        p.leadership = 55;
        p.motor = 90;
        p.disciplineTendency = 60;
        p.playStyle = 10;           // Gunslinger QB

        // Traits
        p.workEthicTrait = 75;
        p.volatilityTrait = 70;     // very streaky
        p.professionalismTrait = 75;
        p.leadershipTrait = 55;
        p.clutchGeneTrait = 60;
        p.loyaltyTrait = 65;
        p.egoTrait = 40;
        p.mediaFriendlyTrait = 55;
        p.enigmaticTrait = 10;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }

    {
        Player p("Joe Milton", "QB", 68);
        generateAttributesForPosition(p);

        p.college = "Tennessee";
        p.draftedTeam = "DAL";
        p.age = 24;

        p.height = 77;
        p.weight = 235;

        p.injured = false;
        p.injuryWeeks = 0;

        p.contractYears = 2;
        p.contractSalary = 1800000;
        p.contractBonus = 250000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 2500000;
        p.wantsExtension = false;
        p.holdingOut = false;

        p.throwPower = std::max(p.throwPower, 96);
        p.throwAccuracyShort = std::max(p.throwAccuracyShort, 72);
        p.throwAccuracyMid = std::max(p.throwAccuracyMid, 68);
        p.throwAccuracyDeep = std::max(p.throwAccuracyDeep, 70);
        p.awareness = std::max(p.awareness, 60);
        p.riskTaking = std::max(p.riskTaking, 90);
        p.motor = std::max(p.motor, 70);

        p.leadershipTrait = 45;
        p.volatilityTrait = 65;
        p.workEthicTrait = 70;
        p.divaTrait = 25;
        p.loyaltyTrait = 60;
        p.clutchGeneTrait = 55;
        p.trashTalkTrait = 40;
        p.professionalismTrait = 70;
        p.mentorTrait = 20;
        p.egoTrait = 50;
        p.mediaFriendlyTrait = 60;
        p.enigmaticTrait = 40;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }

    // === RUNNING BACKS ===

    // Javonte Williams — RB1 — 85 OVR
    {
        Player p("Javonte Williams", "RB", 85);
        generateAttributesForPosition(p);

        p.college = "North Carolina";
        p.draftedTeam = "DEN";
        p.age = 26;

        p.height = 70;   // 5'10"
        p.weight = 220;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract
        p.contractYears = 3;
        p.contractSalary = 6500000;
        p.contractBonus = 2000000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 8000000;
        p.wantsExtension = true;
        p.holdingOut = false;

        // Physical tuning
        p.speed = std::max(p.speed, 90);
        p.strength = std::max(p.strength, 85);
        p.agility = std::max(p.agility, 86);
        p.stamina = std::max(p.stamina, 90);

        // Receiving
        p.catchRating = std::max(p.catchRating, 70);
        p.catchInTraffic = std::max(p.catchInTraffic, 68);
        p.spectacularCatch = std::max(p.spectacularCatch, 65);

        // Route running (RB baseline)
        p.routeRunningShort = std::max(p.routeRunningShort, 65);
        p.routeRunningMedium = std::max(p.routeRunningMedium, 60);
        p.routeRunningDeep = std::max(p.routeRunningDeep, 55);

        // Blocking
        p.passBlock = std::max(p.passBlock, 65);
        p.runBlock = std::max(p.runBlock, 70);
        p.impactBlock = std::max(p.impactBlock, 75);

        // Defensive attributes (RB defaults)
        p.blockShed = 40;
        p.powerMoves = 35;
        p.finesseMoves = 35;
        p.tackle = 40;
        p.hitPower = 45;
        p.pursuit = 40;
        p.playRecognition = 50;
        p.manCoverage = 30;
        p.zoneCoverage = 35;
        p.pressCoverage = 30;

        // Tendencies
        p.aggression = 75;
        p.riskTaking = 70;
        p.consistency = 85;
        p.clutch = 80;
        p.leadership = 70;
        p.motor = 85;
        p.disciplineTendency = 75;
        p.playStyle = 3; // Power back archetype

        // Traits
        p.workEthicTrait = 85;
        p.volatilityTrait = 20;
        p.leadershipTrait = 70;
        p.clutchGeneTrait = 75;
        p.professionalismTrait = 85;
        p.loyaltyTrait = 80;
        p.egoTrait = 45;
        p.mediaFriendlyTrait = 70;
        p.enigmaticTrait = 15;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }
    // Dominic Richardson — RB — 67 OVR (Rookie)
    {
        Player p("Dominic Richardson", "RB", 67);
        generateAttributesForPosition(p);

        p.college = "Tulsa";
        p.draftedTeam = "DAL";
        p.age = 22;

        p.height = 72;   // 6'0"
        p.weight = 204;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract (rookie 4-year)
        p.contractYears = 4;
        p.contractSalary = 1100000;
        p.contractBonus = 150000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 1800000;
        p.wantsExtension = false;
        p.holdingOut = false;

        // Physical (rookie RB profile)
        p.speed = 88;
        p.strength = 74;
        p.agility = 86;
        p.stamina = 88;

        // Mental
        p.awareness = 60;
        p.discipline = 70;
        p.morale = 75;

        // Receiving
        p.catchRating = 68;
        p.catchInTraffic = 60;
        p.spectacularCatch = 55;
        p.routeRunningShort = 60;
        p.routeRunningMedium = 50;
        p.routeRunningDeep = 40;

        // Blocking
        p.passBlock = 60;
        p.runBlock = 55;
        p.impactBlock = 55;

        // Defense (RB baseline)
        p.blockShed = 25;
        p.powerMoves = 20;
        p.finesseMoves = 20;
        p.tackle = 30;
        p.hitPower = 25;
        p.pursuit = 30;
        p.playRecognition = 40;
        p.manCoverage = 25;
        p.zoneCoverage = 25;
        p.pressCoverage = 20;

        // Tendencies
        p.aggression = 80;
        p.riskTaking = 55;
        p.consistency = 68;
        p.clutch = 65;
        p.leadership = 55;
        p.motor = 90;
        p.disciplineTendency = 70;
        p.playStyle = 20; // Balanced RB

        // Traits
        p.workEthicTrait = 80;
        p.volatilityTrait = 25;
        p.professionalismTrait = 78;
        p.leadershipTrait = 55;
        p.clutchGeneTrait = 60;
        p.loyaltyTrait = 70;
        p.egoTrait = 30;
        p.mediaFriendlyTrait = 50;
        p.enigmaticTrait = 10;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }

    // Jaydon Blue — RB3 — 73 OVR
    {
        Player p("Jaydon Blue", "RB", 73);
        generateAttributesForPosition(p);

        p.college = "Texas";
        p.draftedTeam = "DAL";
        p.age = 22;

        p.height = 72;   // 6'0"
        p.weight = 205;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract
        p.contractYears = 4;
        p.contractSalary = 1200000;
        p.contractBonus = 300000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 2000000;
        p.wantsExtension = false;
        p.holdingOut = false;

        // Physical tuning
        p.speed = std::max(p.speed, 91);
        p.strength = std::max(p.strength, 78);
        p.agility = std::max(p.agility, 90);
        p.stamina = std::max(p.stamina, 85);

        // Receiving
        p.catchRating = std::max(p.catchRating, 70);
        p.catchInTraffic = std::max(p.catchInTraffic, 65);
        p.spectacularCatch = std::max(p.spectacularCatch, 60);

        // Route running (RB baseline)
        p.routeRunningShort = std::max(p.routeRunningShort, 65);
        p.routeRunningMedium = std::max(p.routeRunningMedium, 60);
        p.routeRunningDeep = std::max(p.routeRunningDeep, 55);

        // Blocking
        p.passBlock = std::max(p.passBlock, 60);
        p.runBlock = std::max(p.runBlock, 65);
        p.impactBlock = std::max(p.impactBlock, 65);

        // Defensive attributes (RB defaults)
        p.blockShed = 38;
        p.powerMoves = 35;
        p.finesseMoves = 35;
        p.tackle = 40;
        p.hitPower = 40;
        p.pursuit = 40;
        p.playRecognition = 45;
        p.manCoverage = 30;
        p.zoneCoverage = 35;
        p.pressCoverage = 30;

        // Tendencies
        p.aggression = 70;
        p.riskTaking = 65;
        p.consistency = 75;
        p.clutch = 70;
        p.leadership = 55;
        p.motor = 80;
        p.disciplineTendency = 70;
        p.playStyle = 2; // Balanced RB

        // Traits
        p.workEthicTrait = 80;
        p.volatilityTrait = 30;
        p.professionalismTrait = 80;
        p.leadershipTrait = 55;
        p.clutchGeneTrait = 60;
        p.loyaltyTrait = 75;
        p.egoTrait = 40;
        p.mediaFriendlyTrait = 60;
        p.enigmaticTrait = 20;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }


    // Malik Davis — RB4 — 73 OVR
    {
        Player p("Malik Davis", "RB", 73);
        generateAttributesForPosition(p);

        p.college = "Florida";
        p.draftedTeam = "DAL";
        p.age = 26;

        p.height = 70;   // 5'10"
        p.weight = 205;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract
        p.contractYears = 1;
        p.contractSalary = 1100000;
        p.contractBonus = 100000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 1500000;
        p.wantsExtension = false;
        p.holdingOut = false;

        // Physical tuning
        p.speed = std::max(p.speed, 89);
        p.strength = std::max(p.strength, 78);
        p.agility = std::max(p.agility, 88);
        p.stamina = std::max(p.stamina, 84);

        // Receiving
        p.catchRating = std::max(p.catchRating, 68);
        p.catchInTraffic = std::max(p.catchInTraffic, 60);
        p.spectacularCatch = std::max(p.spectacularCatch, 58);

        // Route running (RB baseline)
        p.routeRunningShort = std::max(p.routeRunningShort, 60);
        p.routeRunningMedium = std::max(p.routeRunningMedium, 55);
        p.routeRunningDeep = std::max(p.routeRunningDeep, 50);

        // Blocking
        p.passBlock = std::max(p.passBlock, 60);
        p.runBlock = std::max(p.runBlock, 65);
        p.impactBlock = std::max(p.impactBlock, 60);

        // Defensive attributes (RB defaults)
        p.blockShed = 38;
        p.powerMoves = 35;
        p.finesseMoves = 35;
        p.tackle = 40;
        p.hitPower = 40;
        p.pursuit = 40;
        p.playRecognition = 45;
        p.manCoverage = 30;
        p.zoneCoverage = 35;
        p.pressCoverage = 30;

        // Tendencies
        p.aggression = 65;
        p.riskTaking = 60;
        p.consistency = 70;
        p.clutch = 65;
        p.leadership = 55;
        p.motor = 75;
        p.disciplineTendency = 70;
        p.playStyle = 2; // Balanced RB

        // Traits
        p.workEthicTrait = 78;
        p.volatilityTrait = 25;
        p.professionalismTrait = 80;
        p.leadershipTrait = 55;
        p.clutchGeneTrait = 60;
        p.loyaltyTrait = 70;
        p.egoTrait = 40;
        p.mediaFriendlyTrait = 60;
        p.enigmaticTrait = 20;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }


    // Phil Mafah — RB5 — 68 OVR
    {
        Player p("Phil Mafah", "RB", 68);
        generateAttributesForPosition(p);

        p.college = "Clemson";
        p.draftedTeam = "DAL";
        p.age = 22;

        p.height = 72;   // 6'0"
        p.weight = 230;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract
        p.contractYears = 4;
        p.contractSalary = 950000;
        p.contractBonus = 150000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 1200000;
        p.wantsExtension = false;
        p.holdingOut = false;

        // Physical tuning
        p.speed = std::max(p.speed, 86);
        p.strength = std::max(p.strength, 88);
        p.agility = std::max(p.agility, 82);
        p.stamina = std::max(p.stamina, 85);

        // Receiving
        p.catchRating = std::max(p.catchRating, 65);
        p.catchInTraffic = std::max(p.catchInTraffic, 60);
        p.spectacularCatch = std::max(p.spectacularCatch, 58);

        // Route running (RB baseline)
        p.routeRunningShort = std::max(p.routeRunningShort, 55);
        p.routeRunningMedium = std::max(p.routeRunningMedium, 50);
        p.routeRunningDeep = std::max(p.routeRunningDeep, 45);

        // Blocking
        p.passBlock = std::max(p.passBlock, 55);
        p.runBlock = std::max(p.runBlock, 60);
        p.impactBlock = std::max(p.impactBlock, 65);

        // Defensive attributes (RB defaults)
        p.blockShed = 40;
        p.powerMoves = 35;
        p.finesseMoves = 35;
        p.tackle = 40;
        p.hitPower = 45;
        p.pursuit = 40;
        p.playRecognition = 45;
        p.manCoverage = 30;
        p.zoneCoverage = 35;
        p.pressCoverage = 30;

        // Tendencies
        p.aggression = 70;
        p.riskTaking = 60;
        p.consistency = 70;
        p.clutch = 65;
        p.leadership = 55;
        p.motor = 80;
        p.disciplineTendency = 70;
        p.playStyle = 3; // Power back archetype

        // Traits
        p.workEthicTrait = 80;
        p.volatilityTrait = 25;
        p.professionalismTrait = 85;
        p.leadershipTrait = 55;
        p.clutchGeneTrait = 60;
        p.loyaltyTrait = 75;
        p.egoTrait = 40;
        p.mediaFriendlyTrait = 60;
        p.enigmaticTrait = 20;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }
    // Israel Abanikanda — RB — 70 OVR
    {
        Player p("Israel Abanikanda", "RB", 70);
        generateAttributesForPosition(p);

        p.college = "Pittsburgh";
        p.draftedTeam = "NYJ";
        p.age = 22;

        p.height = 71;   // 5'11"
        p.weight = 216;

        // Health
        p.injured = false;
        p.injuryWeeks = 0;

        // Contract (rookie)
        p.contractYears = 4;
        p.contractSalary = 1100000;
        p.contractBonus = 150000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 1800000;
        p.wantsExtension = false;
        p.holdingOut = false;

        // Physical (based on real testing)
        p.speed = 93;          // elite burst
        p.strength = 72;
        p.agility = 88;
        p.stamina = 90;

        // Mental
        p.awareness = 60;
        p.discipline = 70;
        p.morale = 78;
        // Receiving
        p.catchRating = 66;
        p.catchInTraffic = 58;
        p.spectacularCatch = 55;
        p.routeRunningShort = 58;
        p.routeRunningMedium = 48;
        p.routeRunningDeep = 40;

        // Blocking
        p.passBlock = 55;
        p.runBlock = 50;
        p.impactBlock = 50;

        // Defense (RB baseline)
        p.blockShed = 25;
        p.powerMoves = 20;
        p.finesseMoves = 20;
        p.tackle = 30;
        p.hitPower = 25;
        p.pursuit = 30;
        p.playRecognition = 40;
        p.manCoverage = 25;
        p.zoneCoverage = 25;
        p.pressCoverage = 20;

        // Tendencies
        p.aggression = 78;
        p.riskTaking = 70;     // bounce‑outside tendency
        p.consistency = 65;
        p.clutch = 60;
        p.leadership = 50;
        p.motor = 90;
        p.disciplineTendency = 70;
        p.playStyle = 21;      // Speed back

        // Traits
        p.workEthicTrait = 78;
        p.volatilityTrait = 30;
        p.professionalismTrait = 75;
        p.leadershipTrait = 50;
        p.clutchGeneTrait = 60;
        p.loyaltyTrait = 65;
        p.egoTrait = 35;
        p.mediaFriendlyTrait = 50;
        p.enigmaticTrait = 10;
        p.hometownHeroTrait = 0;

        cowboys.addPlayer(p);
    }

    // === FULLBACK ===
    // Hunter Luepke — FB1 — 72 OVR
    {
        Player p("Hunter Luepke", "FB", 72);
        generateAttributesForPosition(p);

        p.college = "North Dakota State";
        p.draftedTeam = "DAL";
        p.age = 25;

        p.height = 73;
        p.weight = 238;

        p.injured = false;
        p.injuryWeeks = 0;

        p.contractYears = 2;
        p.contractSalary = 1250000;
        p.contractBonus = 150000;
        p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
        p.contractDemand = 1800000;

        // Physical
        p.speed = std::max(p.speed, 84);
        p.strength = std::max(p.strength, 88);
        p.agility = std::max(p.agility, 80);
        p.stamina = std::max(p.stamina, 88);

        // Blocking
        p.passBlock = std::max(p.passBlock, 72);
        p.runBlock = std::max(p.runBlock, 80);
        p.impactBlock = std::max(p.impactBlock, 85);

        // Receiving
        p.catchRating = std::max(p.catchRating, 70);
        p.catchInTraffic = std::max(p.catchInTraffic, 68);

        // Tendencies
        p.aggression = 80;
        p.motor = 90;
        p.consistency = 75;

        // Traits
        p.workEthicTrait = 85;
        p.professionalismTrait = 90;
        p.leadershipTrait = 65;

        cowboys.addPlayer(p);
    }
    // === WIDE RECEIVERS ===

     // CeeDee Lamb — WR1 — 93 OVR
     {
         Player p("CeeDee Lamb", "WR", 93);
         generateAttributesForPosition(p);

         p.college = "Oklahoma";
         p.draftedTeam = "DAL";
         p.age = 27;

         p.height = 74;   // 6'2"
         p.weight = 198;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 28000000;
         p.contractBonus = 20000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 32000000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 93);
         p.strength = std::max(p.strength, 78);
         p.agility = std::max(p.agility, 95);
         p.stamina = std::max(p.stamina, 92);

         // Mental
         p.awareness = std::max(p.awareness, 95);
         p.discipline = std::max(p.discipline, 85);
         p.morale = std::max(p.morale, 90);

         // Receiving
         p.catchRating = std::max(p.catchRating, 96);
         p.catchInTraffic = std::max(p.catchInTraffic, 94);
         p.spectacularCatch = std::max(p.spectacularCatch, 95);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 96);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 95);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 92);

         // Blocking (WR baseline)
         p.passBlock = std::max(p.passBlock, 45);
         p.runBlock = std::max(p.runBlock, 55);
         p.impactBlock = std::max(p.impactBlock, 50);

         // Defensive attributes (WR defaults)
         p.blockShed = 35;
         p.powerMoves = 30;
         p.finesseMoves = 30;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = std::max(p.playRecognition, 70);
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Tendencies
         p.aggression = 70;
         p.riskTaking = 65;
         p.consistency = 90;
         p.clutch = 95;
         p.leadership = 80;
         p.motor = 85;
         p.disciplineTendency = 80;
         p.playStyle = 1; // Elite route technician

         // Traits
         p.leadershipTrait = 75;
         p.volatilityTrait = 20;
         p.workEthicTrait = 90;
         p.divaTrait = 40;
         p.loyaltyTrait = 85;
         p.clutchGeneTrait = 95;
         p.trashTalkTrait = 60;
         p.professionalismTrait = 90;
         p.mentorTrait = 70;
         p.egoTrait = 55;
         p.mediaFriendlyTrait = 85;
         p.enigmaticTrait = 20;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
    }

     // George Pickens — WR2 — 88 OVR
     {
         Player p("George Pickens", "WR", 88);
         generateAttributesForPosition(p);

         p.college = "Georgia";
         p.draftedTeam = "PIT";
         p.age = 25;

         p.height = 75;   // 6'3"
         p.weight = 200;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 12000000;
         p.contractBonus = 6000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 16000000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 92);
         p.strength = std::max(p.strength, 80);
         p.agility = std::max(p.agility, 92);
         p.stamina = std::max(p.stamina, 90);

         // Mental
         p.awareness = std::max(p.awareness, 88);
         p.discipline = std::max(p.discipline, 75);
         p.morale = std::max(p.morale, 85);

         // Receiving
         p.catchRating = std::max(p.catchRating, 94);
         p.catchInTraffic = std::max(p.catchInTraffic, 95);
         p.spectacularCatch = std::max(p.spectacularCatch, 97);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 86);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 87);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 90);

         // Blocking (WR baseline)
         p.passBlock = std::max(p.passBlock, 45);
         p.runBlock = std::max(p.runBlock, 55);
         p.impactBlock = std::max(p.impactBlock, 50);

         // Defensive attributes (WR defaults)
         p.blockShed = 35;
         p.powerMoves = 30;
         p.finesseMoves = 30;
         p.tackle = 40;
         p.hitPower = 40;
         p.pursuit = 40;
         p.playRecognition = std::max(p.playRecognition, 65);
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Tendencies
         p.aggression = 85;       // Pickens plays angry
         p.riskTaking = 80;
         p.consistency = 78;
         p.clutch = 80;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 65;
         p.playStyle = 4; // Physical vertical WR

         // Traits
         p.leadershipTrait = 55;
         p.volatilityTrait = 60;   // Pickens personality
         p.workEthicTrait = 80;
         p.divaTrait = 45;
         p.loyaltyTrait = 70;
         p.clutchGeneTrait = 80;
         p.trashTalkTrait = 85;
         p.professionalismTrait = 70;
         p.mentorTrait = 40;
         p.egoTrait = 75;
         p.mediaFriendlyTrait = 65;
         p.enigmaticTrait = 35;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // Ryan Flournoy — WR — 76 OVR
     {
         Player p("Ryan Flournoy", "WR", 76);
         generateAttributesForPosition(p);

         p.college = "Southeast Missouri State";
         p.draftedTeam = "DAL";
         p.age = 26;

         p.height = 73;   // 6'1"
         p.weight = 205;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 91);
         p.strength = std::max(p.strength, 78);
         p.agility = std::max(p.agility, 90);
         p.stamina = std::max(p.stamina, 88);

         // Mental
         p.awareness = std::max(p.awareness, 75);
         p.discipline = std::max(p.discipline, 70);
         p.morale = std::max(p.morale, 80);

         // Receiving
         p.catchRating = std::max(p.catchRating, 80);
         p.catchInTraffic = std::max(p.catchInTraffic, 78);
         p.spectacularCatch = std::max(p.spectacularCatch, 80);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 78);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 76);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 75);

         // Blocking (WR baseline)
         p.passBlock = std::max(p.passBlock, 45);
         p.runBlock = std::max(p.runBlock, 55);
         p.impactBlock = std::max(p.impactBlock, 50);

         // Defensive attributes (WR defaults)
         p.blockShed = 35;
         p.powerMoves = 30;
         p.finesseMoves = 30;
         p.tackle = 40;
         p.hitPower = 40;
         p.pursuit = 40;
         p.playRecognition = std::max(p.playRecognition, 60);
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Tendencies
         p.aggression = 70;
         p.riskTaking = 65;
         p.consistency = 75;
         p.clutch = 70;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 5; // Athletic depth WR

         // Traits
         p.leadershipTrait = 55;
         p.volatilityTrait = 25;
         p.workEthicTrait = 80;
         p.divaTrait = 20;
         p.loyaltyTrait = 75;
         p.clutchGeneTrait = 65;
         p.trashTalkTrait = 50;
         p.professionalismTrait = 80;
         p.mentorTrait = 40;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 60;
         p.enigmaticTrait = 20;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // KaVontae Turpin — WR — 76 OVR
     {
         Player p("KaVontae Turpin", "WR", 76);
         generateAttributesForPosition(p);

         p.college = "TCU";
         p.draftedTeam = "DAL";
         p.age = 29;

         p.height = 67;   // 5'7"
         p.weight = 158;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2200000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 96);     // elite speed
         p.strength = std::max(p.strength, 65);
         p.agility = std::max(p.agility, 96); // elite agility
         p.stamina = std::max(p.stamina, 88);

         // Mental
         p.awareness = std::max(p.awareness, 78);
         p.discipline = std::max(p.discipline, 70);
         p.morale = std::max(p.morale, 80);

         // Receiving
         p.catchRating = std::max(p.catchRating, 78);
         p.catchInTraffic = std::max(p.catchInTraffic, 70);
         p.spectacularCatch = std::max(p.spectacularCatch, 75);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 76);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 74);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 78);

         // Blocking (WR baseline)
         p.passBlock = std::max(p.passBlock, 40);
         p.runBlock = std::max(p.runBlock, 50);
         p.impactBlock = std::max(p.impactBlock, 45);

         // Defensive attributes (WR defaults)
         p.blockShed = 30;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 35;
         p.hitPower = 30;
         p.pursuit = 40;
         p.playRecognition = std::max(p.playRecognition, 60);
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Tendencies
         p.aggression = 70;
         p.riskTaking = 85;   // gadget player, high-risk style
         p.consistency = 70;
         p.clutch = 75;
         p.leadership = 50;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 6; // Speed/utility WR

         // Traits
         p.leadershipTrait = 50;
         p.volatilityTrait = 30;
         p.workEthicTrait = 80;
         p.divaTrait = 20;
         p.loyaltyTrait = 70;
         p.clutchGeneTrait = 70;
         p.trashTalkTrait = 60;
         p.professionalismTrait = 80;
         p.mentorTrait = 40;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 70;
         p.enigmaticTrait = 25;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Tyler Johnson — WR — 70 OVR
     {
         Player p("Tyler Johnson", "WR", 70);
         generateAttributesForPosition(p);

         p.college = "Minnesota";
         p.draftedTeam = "TB";
         p.age = 27;

         p.height = 73;   // 6'1"
         p.weight = 208;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = 87;
         p.strength = 74;
         p.agility = 84;
         p.stamina = 88;

         // Mental
         p.awareness = 68;
         p.discipline = 72;
         p.morale = 78;

         // Receiving
         p.catchRating = 80;
         p.catchInTraffic = 82;
         p.spectacularCatch = 76;

         // Route running
         p.routeRunningShort = 74;
         p.routeRunningMedium = 70;
         p.routeRunningDeep = 66;

         // Blocking
         p.passBlock = 42;
         p.runBlock = 55;
         p.impactBlock = 55;

         // Defense
         p.blockShed = 25;
         p.powerMoves = 20;
         p.finesseMoves = 20;
         p.tackle = 30;
         p.hitPower = 25;
         p.pursuit = 30;
         p.playRecognition = 40;
         p.manCoverage = 25;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 50;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 74; // Possession WR

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 65;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // Jonathan Mingo — WR — 71 OVR
     {
         Player p("Jonathan Mingo", "WR", 71);
         generateAttributesForPosition(p);

         p.college = "Ole Miss";
         p.draftedTeam = "CAR";
         p.age = 23;

         p.height = 74;   // 6'2"
         p.weight = 220;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 1600000;
         p.contractBonus = 300000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2600000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 89);
         p.strength = std::max(p.strength, 80);
         p.agility = std::max(p.agility, 86);
         p.stamina = std::max(p.stamina, 85);

         // Mental
         p.awareness = std::max(p.awareness, 72);
         p.discipline = std::max(p.discipline, 70);
         p.morale = std::max(p.morale, 78);

         // Receiving
         p.catchRating = std::max(p.catchRating, 78);
         p.catchInTraffic = std::max(p.catchInTraffic, 80);
         p.spectacularCatch = std::max(p.spectacularCatch, 80);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 75);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 74);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 73);

         // Blocking (WR baseline)
         p.passBlock = std::max(p.passBlock, 45);
         p.runBlock = std::max(p.runBlock, 55);
         p.impactBlock = std::max(p.impactBlock, 50);

         // Defensive attributes (WR defaults)
         p.blockShed = 35;
         p.powerMoves = 30;
         p.finesseMoves = 30;
         p.tackle = 40;
         p.hitPower = 40;
         p.pursuit = 40;
         p.playRecognition = std::max(p.playRecognition, 60);
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Tendencies
         p.aggression = 70;
         p.riskTaking = 60;
         p.consistency = 72;
         p.clutch = 65;
         p.leadership = 55;
         p.motor = 80;
         p.disciplineTendency = 70;
         p.playStyle = 7; // Big-bodied possession WR

         // Traits
         p.leadershipTrait = 55;
         p.volatilityTrait = 20;
         p.workEthicTrait = 80;
         p.divaTrait = 15;
         p.loyaltyTrait = 75;
         p.clutchGeneTrait = 60;
         p.trashTalkTrait = 40;
         p.professionalismTrait = 80;
         p.mentorTrait = 40;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 60;
         p.enigmaticTrait = 20;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Camden Brown — WR — 67 OVR (Rookie)
     {
         Player p("Camden Brown", "WR", 67);
         generateAttributesForPosition(p);

         p.college = "Georgia Southern";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 74;   // 6'2"
         p.weight = 204;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie)
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (big WR profile)
         p.speed = 88;
         p.strength = 72;
         p.agility = 84;
         p.stamina = 88;

         // Mental
         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         // Receiving
         p.catchRating = 78;
         p.catchInTraffic = 76;
         p.spectacularCatch = 74;

         // Route running
         p.routeRunningShort = 68;
         p.routeRunningMedium = 66;
         p.routeRunningDeep = 70;

         // Blocking (WR baseline)
         p.passBlock = 40;
         p.runBlock = 55;
         p.impactBlock = 55;

         // Defense (WR baseline)
         p.blockShed = 25;
         p.powerMoves = 20;
         p.finesseMoves = 20;
         p.tackle = 30;
         p.hitPower = 25;
         p.pursuit = 30;
         p.playRecognition = 40;
         p.manCoverage = 25;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 70; // Physical outside WR

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Parris Campbell — WR — 72 OVR
     {
         Player p("Parris Campbell", "WR", 72);
         generateAttributesForPosition(p);

         p.college = "Ohio State";
         p.draftedTeam = "IND";
         p.age = 27;

         p.height = 72;   // 6'0"
         p.weight = 210;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 2500000;
         p.contractBonus = 500000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 3500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (speed WR profile)
         p.speed = 94;
         p.strength = 70;
         p.agility = 90;
         p.stamina = 85;

         // Mental
         p.awareness = 68;
         p.discipline = 72;
         p.morale = 78;

         // Receiving
         p.catchRating = 74;
         p.catchInTraffic = 68;
         p.spectacularCatch = 70;

         // Route running
         p.routeRunningShort = 76;
         p.routeRunningMedium = 72;
         p.routeRunningDeep = 78;

         // Blocking
         p.passBlock = 40;
         p.runBlock = 50;
         p.impactBlock = 50;

         // Defense (WR baseline)
         p.blockShed = 25;
         p.powerMoves = 20;
         p.finesseMoves = 20;
         p.tackle = 30;
         p.hitPower = 25;
         p.pursuit = 30;
         p.playRecognition = 40;
         p.manCoverage = 25;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 70;
         p.riskTaking = 65;   // YAC runner
         p.consistency = 60;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 71;    // Speed/YAC WR

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 35;   // streaky
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 65;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Traeshon Holden — WR — 69 OVR
     {
         Player p("Traeshon Holden", "WR", 69);
         generateAttributesForPosition(p);

         p.college = "Oregon";
         p.draftedTeam = "DAL";
         p.age = 24;

         p.height = 74;   // 6'2"
         p.weight = 208;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie)
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (big WR profile)
         p.speed = 87;
         p.strength = 76;
         p.agility = 84;
         p.stamina = 88;

         // Mental
         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         // Receiving
         p.catchRating = 80;
         p.catchInTraffic = 78;
         p.spectacularCatch = 76;

         // Route running
         p.routeRunningShort = 66;
         p.routeRunningMedium = 64;
         p.routeRunningDeep = 68;

         // Blocking (big WR)
         p.passBlock = 42;
         p.runBlock = 58;
         p.impactBlock = 58;

         // Defense (WR baseline)
         p.blockShed = 25;
         p.powerMoves = 20;
         p.finesseMoves = 20;
         p.tackle = 30;
         p.hitPower = 25;
         p.pursuit = 30;
         p.playRecognition = 40;
         p.manCoverage = 25;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 78;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 62;
         p.leadership = 55;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 72; // Physical outside WR

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Jordan Hudson — WR — 68 OVR (Rookie)
     {
         Player p("Jordan Hudson", "WR", 68);
         generateAttributesForPosition(p);

         p.college = "SMU";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 73;   // 6'1"
         p.weight = 199;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = 89;
         p.strength = 72;
         p.agility = 86;
         p.stamina = 88;

         // Mental
         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         // Receiving
         p.catchRating = 76;
         p.catchInTraffic = 74;
         p.spectacularCatch = 72;

         // Route running
         p.routeRunningShort = 66;
         p.routeRunningMedium = 64;
         p.routeRunningDeep = 70;

         // Blocking
         p.passBlock = 40;
         p.runBlock = 55;
         p.impactBlock = 55;

         // Defense
         p.blockShed = 25;
         p.powerMoves = 20;
         p.finesseMoves = 20;
         p.tackle = 30;
         p.hitPower = 25;
         p.pursuit = 30;
         p.playRecognition = 40;
         p.manCoverage = 25;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 62;
         p.leadership = 55;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 72; // Physical/athletic WR

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Marquez Valdes-Scantling — WR — 73 OVR
     {
         Player p("Marquez Valdes-Scantling", "WR", 73);
         generateAttributesForPosition(p);

         p.college = "USF";
         p.draftedTeam = "GB";
         p.age = 31;

         p.height = 76;   // 6'4"
         p.weight = 206;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 3500000;
         p.contractBonus = 500000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 5000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (deep threat)
         p.speed = 95;
         p.strength = 72;
         p.agility = 90;
         p.stamina = 88;

         // Mental
         p.awareness = 70;
         p.discipline = 72;
         p.morale = 80;

         // Receiving
         p.catchRating = 72;
         p.catchInTraffic = 66;
         p.spectacularCatch = 78;

         // Route running
         p.routeRunningShort = 66;
         p.routeRunningMedium = 70;
         p.routeRunningDeep = 82;

         // Blocking
         p.passBlock = 40;
         p.runBlock = 52;
         p.impactBlock = 52;

         // Defense
         p.blockShed = 25;
         p.powerMoves = 20;
         p.finesseMoves = 20;
         p.tackle = 30;
         p.hitPower = 25;
         p.pursuit = 30;
         p.playRecognition = 40;
         p.manCoverage = 25;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 70;
         p.riskTaking = 75; // deep shots, high aDOT
         p.consistency = 55; // streaky
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 75; // Deep threat WR

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 40; // inconsistent hands
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 65;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // ===== Tight Ends =====
     // Jake Ferguson — TE1 — 82 OVR
     {
         Player p("Jake Ferguson", "TE", 82);
         generateAttributesForPosition(p);

         p.college = "Wisconsin";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 77;   // 6'5"
         p.weight = 244;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 2500000;
         p.contractBonus = 500000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 5500000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 86);
         p.strength = std::max(p.strength, 82);
         p.agility = std::max(p.agility, 84);
         p.stamina = std::max(p.stamina, 90);

         // Mental
         p.awareness = std::max(p.awareness, 88);
         p.discipline = std::max(p.discipline, 85);
         p.morale = std::max(p.morale, 90);

         // Receiving
         p.catchRating = std::max(p.catchRating, 88);
         p.catchInTraffic = std::max(p.catchInTraffic, 90);
         p.spectacularCatch = std::max(p.spectacularCatch, 85);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 84);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 82);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 78);

         // Blocking (TE strength)
         p.passBlock = std::max(p.passBlock, 75);
         p.runBlock = std::max(p.runBlock, 80);
         p.impactBlock = std::max(p.impactBlock, 82);

         // Defensive attributes (TE defaults)
         p.blockShed = 45;
         p.powerMoves = 40;
         p.finesseMoves = 40;
         p.tackle = 50;
         p.hitPower = 45;
         p.pursuit = 50;
         p.playRecognition = std::max(p.playRecognition, 70);
         p.manCoverage = 35;
         p.zoneCoverage = 40;
         p.pressCoverage = 35;

         // Tendencies
         p.aggression = 80;
         p.riskTaking = 55;
         p.consistency = 85;
         p.clutch = 80;
         p.leadership = 75;
         p.motor = 90;
         p.disciplineTendency = 80;
         p.playStyle = 8; // Balanced TE (block + catch)

         // Traits
         p.leadershipTrait = 75;
         p.volatilityTrait = 20;
         p.workEthicTrait = 90;
         p.divaTrait = 10;
         p.loyaltyTrait = 85;
         p.clutchGeneTrait = 80;
         p.trashTalkTrait = 40;
         p.professionalismTrait = 90;
         p.mentorTrait = 70;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 70;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Luke Schoonmaker — TE2 — 69 OVR
     {
         Player p("Luke Schoonmaker", "TE", 69);
         generateAttributesForPosition(p);

         p.college = "Michigan";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 77;   // 6'5"
         p.weight = 250;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 1500000;
         p.contractBonus = 300000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 84);
         p.strength = std::max(p.strength, 82);
         p.agility = std::max(p.agility, 82);
         p.stamina = std::max(p.stamina, 86);

         // Mental
         p.awareness = std::max(p.awareness, 75);
         p.discipline = std::max(p.discipline, 78);
         p.morale = std::max(p.morale, 80);

         // Receiving
         p.catchRating = std::max(p.catchRating, 74);
         p.catchInTraffic = std::max(p.catchInTraffic, 72);
         p.spectacularCatch = std::max(p.spectacularCatch, 70);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 70);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 68);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 65);

         // Blocking
         p.passBlock = std::max(p.passBlock, 72);
         p.runBlock = std::max(p.runBlock, 78);
         p.impactBlock = std::max(p.impactBlock, 80);

         // Defensive attributes (TE defaults)
         p.blockShed = 45;
         p.powerMoves = 40;
         p.finesseMoves = 40;
         p.tackle = 50;
         p.hitPower = 45;
         p.pursuit = 50;
         p.playRecognition = std::max(p.playRecognition, 60);
         p.manCoverage = 35;
         p.zoneCoverage = 40;
         p.pressCoverage = 35;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 50;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 55;
         p.motor = 80;
         p.disciplineTendency = 75;
         p.playStyle = 9; // Blocking TE archetype

         // Traits
         p.leadershipTrait = 55;
         p.volatilityTrait = 20;
         p.workEthicTrait = 80;
         p.divaTrait = 10;
         p.loyaltyTrait = 75;
         p.clutchGeneTrait = 60;
         p.trashTalkTrait = 35;
         p.professionalismTrait = 80;
         p.mentorTrait = 40;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Brevyn Spann-Ford — TE3 — 65 OVR
     {
         Player p("Brevyn Spann-Ford", "TE", 65);
         generateAttributesForPosition(p);

         p.college = "Minnesota";
         p.draftedTeam = "DAL";
         p.age = 24;

         p.height = 79;   // 6'7"
         p.weight = 270;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical tuning
         p.speed = std::max(p.speed, 80);
         p.strength = std::max(p.strength, 88);
         p.agility = std::max(p.agility, 78);
         p.stamina = std::max(p.stamina, 84);

         // Mental
         p.awareness = std::max(p.awareness, 70);
         p.discipline = std::max(p.discipline, 75);
         p.morale = std::max(p.morale, 78);

         // Receiving
         p.catchRating = std::max(p.catchRating, 70);
         p.catchInTraffic = std::max(p.catchInTraffic, 72);
         p.spectacularCatch = std::max(p.spectacularCatch, 68);

         // Route running
         p.routeRunningShort = std::max(p.routeRunningShort, 65);
         p.routeRunningMedium = std::max(p.routeRunningMedium, 62);
         p.routeRunningDeep = std::max(p.routeRunningDeep, 58);

         // Blocking (his strength)
         p.passBlock = std::max(p.passBlock, 75);
         p.runBlock = std::max(p.runBlock, 82);
         p.impactBlock = std::max(p.impactBlock, 85);

         // Defensive attributes (TE defaults)
         p.blockShed = 45;
         p.powerMoves = 40;
         p.finesseMoves = 40;
         p.tackle = 50;
         p.hitPower = 45;
         p.pursuit = 50;
         p.playRecognition = std::max(p.playRecognition, 55);
         p.manCoverage = 35;
         p.zoneCoverage = 40;
         p.pressCoverage = 35;

         // Tendencies
         p.aggression = 78;
         p.riskTaking = 45;
         p.consistency = 68;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 75;
         p.playStyle = 10; // Blocking-first TE

         // Traits
         p.leadershipTrait = 55;
         p.volatilityTrait = 20;
         p.workEthicTrait = 80;
         p.divaTrait = 5;
         p.loyaltyTrait = 75;
         p.clutchGeneTrait = 55;
         p.trashTalkTrait = 30;
         p.professionalismTrait = 80;
         p.mentorTrait = 40;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // ===== LT =====
     // Tyler Guyton — LT1 — 73 OVR
     {
         Player p("Tyler Guyton", "LT", 73);
         generateAttributesForPosition(p);

         p.college = "Oklahoma";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 79;   // 6'7"
         p.weight = 328;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 2100000;
         p.contractBonus = 500000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 3500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 78);
         p.strength = std::max(p.strength, 88);
         p.agility = std::max(p.agility, 80);
         p.stamina = std::max(p.stamina, 85);

         // Mental
         p.awareness = std::max(p.awareness, 72);
         p.discipline = std::max(p.discipline, 78);
         p.morale = std::max(p.morale, 80);

         // Blocking (primary)
         p.passBlock = std::max(p.passBlock, 78);
         p.runBlock = std::max(p.runBlock, 80);
         p.impactBlock = std::max(p.impactBlock, 82);

         // Receiving (OL baseline)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant for OL)
         p.routeRunningShort = 30;
         p.routeRunningMedium = 25;
         p.routeRunningDeep = 20;

         // Defensive attributes (OL defaults)
         p.blockShed = 40;
         p.powerMoves = 35;
         p.finesseMoves = 30;
         p.tackle = 45;
         p.hitPower = 45;
         p.pursuit = 40;
         p.playRecognition = 55;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 80;
         p.riskTaking = 40;
         p.consistency = 75;
         p.clutch = 70;
         p.leadership = 60;
         p.motor = 85;
         p.disciplineTendency = 75;
         p.playStyle = 11; // Athletic pass-pro LT

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 20;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 75;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Nathan Thomas — LT2 — 66 OVR
     {
         Player p("Nathan Thomas", "LT", 66);
         generateAttributesForPosition(p);

         p.college = "Louisiana";
         p.draftedTeam = "DAL";
         p.age = 23;

         p.height = 78;   // 6'6"
         p.weight = 320;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 74);
         p.strength = std::max(p.strength, 85);
         p.agility = std::max(p.agility, 76);
         p.stamina = std::max(p.stamina, 82);

         // Mental
         p.awareness = std::max(p.awareness, 62);
         p.discipline = std::max(p.discipline, 70);
         p.morale = std::max(p.morale, 75);

         // Blocking
         p.passBlock = std::max(p.passBlock, 68);
         p.runBlock = std::max(p.runBlock, 72);
         p.impactBlock = std::max(p.impactBlock, 74);

         // Receiving (OL baseline)
         p.catchRating = 38;
         p.catchInTraffic = 32;
         p.spectacularCatch = 28;

         // Route running (irrelevant)
         p.routeRunningShort = 28;
         p.routeRunningMedium = 24;
         p.routeRunningDeep = 20;

         // Defensive attributes (OL defaults)
         p.blockShed = 38;
         p.powerMoves = 32;
         p.finesseMoves = 30;
         p.tackle = 42;
         p.hitPower = 40;
         p.pursuit = 38;
         p.playRecognition = 50;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 40;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 50;
         p.motor = 80;
         p.disciplineTendency = 70;
         p.playStyle = 12; // Developmental LT

         // Traits
         p.workEthicTrait = 75;
         p.volatilityTrait = 25;
         p.professionalismTrait = 75;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Marcellus Johnson — OL — 68 OVR (LG)
     {
         Player p("Marcellus Johnson", "OL", 68);
         generateAttributesForPosition(p);

         p.college = "Missouri";
         p.draftedTeam = "DAL";
         p.age = 26;

         p.height = 76;   // 6'4"
         p.weight = 307;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 3;
         p.contractSalary = 1200000;
         p.contractBonus = 150000;

         p.speed = 68;
         p.strength = 86;
         p.agility = 74;
         p.stamina = 86;

         p.awareness = 60;
         p.discipline = 72;
         p.morale = 75;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 76;
         p.runBlock = 78;
         p.impactBlock = 80;

         p.blockShed = 35;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = 55;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.aggression = 78;
         p.riskTaking = 40;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 88;
         p.disciplineTendency = 72;
         p.playStyle = 82; // LG

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 65;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Drew Shelton — OL — 71 OVR (LT)
     {
         Player p("Drew Shelton", "OL", 71);
         generateAttributesForPosition(p);

         p.college = "Penn State";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 78;   // 6'6"
         p.weight = 310;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 72;
         p.strength = 84;
         p.agility = 80;
         p.stamina = 88;

         p.awareness = 62;
         p.discipline = 72;
         p.morale = 75;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 80;
         p.runBlock = 76;
         p.impactBlock = 82;

         p.blockShed = 35;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = 55;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.aggression = 78;
         p.riskTaking = 45;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 72;
         p.playStyle = 83; // LT

         p.workEthicTrait = 82;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 58;
         p.loyaltyTrait = 65;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Nate Thomas — DL — 69 OVR
     {
         Player p("Nate Thomas", "DL", 69);
         generateAttributesForPosition(p);

         p.college = "Louisiana";
         p.draftedTeam = "DAL";
         p.age = 23;

         p.height = 75;   // 6'3"
         p.weight = 305;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 3;
         p.contractSalary = 1200000;
         p.contractBonus = 150000;

         p.speed = 70;
         p.strength = 88;
         p.agility = 74;
         p.stamina = 86;

         p.awareness = 60;
         p.discipline = 72;
         p.morale = 75;

         p.powerMoves = 74;
         p.finesseMoves = 62;
         p.blockShed = 72;

         p.tackle = 78;
         p.hitPower = 80;
         p.pursuit = 72;
         p.playRecognition = 60;

         p.manCoverage = 20;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 82;
         p.riskTaking = 45;
         p.consistency = 62;
         p.clutch = 58;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 72;
         p.playStyle = 84; // Power DT

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 58;
         p.loyaltyTrait = 65;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }


     // ===== LG =====
     // Tyler Smith — LG1 — 88 OVR
     {
         Player p("Tyler Smith", "LG", 88);
         generateAttributesForPosition(p);

         p.college = "Tulsa";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 76;   // 6'4"
         p.weight = 324;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 8500000;
         p.contractBonus = 6000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 12000000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 80);
         p.strength = std::max(p.strength, 94);
         p.agility = std::max(p.agility, 82);
         p.stamina = std::max(p.stamina, 90);

         // Mental
         p.awareness = std::max(p.awareness, 88);
         p.discipline = std::max(p.discipline, 85);
         p.morale = std::max(p.morale, 90);

         // Blocking
         p.passBlock = std::max(p.passBlock, 88);
         p.runBlock = std::max(p.runBlock, 92);
         p.impactBlock = std::max(p.impactBlock, 94);

         // Receiving (OL baseline)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant)
         p.routeRunningShort = 30;
         p.routeRunningMedium = 25;
         p.routeRunningDeep = 20;

         // Defensive attributes
         p.blockShed = 45;
         p.powerMoves = 40;
         p.finesseMoves = 35;
         p.tackle = 50;
         p.hitPower = 45;
         p.pursuit = 45;
         p.playRecognition = 65;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 90;
         p.riskTaking = 45;
         p.consistency = 90;
         p.clutch = 85;
         p.leadership = 75;
         p.motor = 95;
         p.disciplineTendency = 80;
         p.playStyle = 13; // Power LG

         // Traits
         p.workEthicTrait = 90;
         p.volatilityTrait = 20;
         p.professionalismTrait = 90;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 80;
         p.loyaltyTrait = 85;
         p.egoTrait = 40;
         p.mediaFriendlyTrait = 60;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Nick Leverett — OL — 70 OVR (LG)
     {
         Player p("Nick Leverett", "OL", 70);
         generateAttributesForPosition(p);

         p.college = "Rice";
         p.draftedTeam = "TB";
         p.age = 28;

         p.height = 75;   // 6'3"
         p.weight = 310;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 1;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;
         p.contractTotalValue = 1700000;
         p.contractDemand = 2500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 70;
         p.strength = 86;
         p.agility = 76;
         p.stamina = 88;

         p.awareness = 72;
         p.discipline = 80;
         p.morale = 78;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 78;
         p.runBlock = 80;
         p.impactBlock = 82;

         p.blockShed = 35;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = 60;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.aggression = 78;
         p.riskTaking = 40;
         p.consistency = 80;
         p.clutch = 70;
         p.leadership = 70;
         p.motor = 88;
         p.disciplineTendency = 80;
         p.playStyle = 62; // Interior OL

         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 85;
         p.leadershipTrait = 60;
         p.clutchGeneTrait = 65;
         p.loyaltyTrait = 70;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 5;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // Trevor Keegan — LG3 — 66 OVR
     {
         Player p("Trevor Keegan", "LG", 66);
         generateAttributesForPosition(p);

         p.college = "Michigan";
         p.draftedTeam = "DAL";
         p.age = 23;

         p.height = 78;   // 6'6"
         p.weight = 320;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 72);
         p.strength = std::max(p.strength, 86);
         p.agility = std::max(p.agility, 74);
         p.stamina = std::max(p.stamina, 80);

         // Mental
         p.awareness = std::max(p.awareness, 60);
         p.discipline = std::max(p.discipline, 70);
         p.morale = std::max(p.morale, 75);

         // Blocking
         p.passBlock = std::max(p.passBlock, 66);
         p.runBlock = std::max(p.runBlock, 70);
         p.impactBlock = std::max(p.impactBlock, 72);

         // Receiving (OL baseline)
         p.catchRating = 35;
         p.catchInTraffic = 30;
         p.spectacularCatch = 25;

         // Route running
         p.routeRunningShort = 25;
         p.routeRunningMedium = 22;
         p.routeRunningDeep = 18;

         // Defensive attributes
         p.blockShed = 38;
         p.powerMoves = 32;
         p.finesseMoves = 28;
         p.tackle = 42;
         p.hitPower = 38;
         p.pursuit = 38;
         p.playRecognition = 50;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 40;
         p.consistency = 60;
         p.clutch = 55;
         p.leadership = 50;
         p.motor = 78;
         p.disciplineTendency = 70;
         p.playStyle = 15; // Developmental LG

         // Traits
         p.workEthicTrait = 75;
         p.volatilityTrait = 25;
         p.professionalismTrait = 75;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // ===== C =====
     // Cooper Beebe — C1 — 75 OVR
     {
         Player p("Cooper Beebe", "C", 75);
         generateAttributesForPosition(p);

         p.college = "Kansas State";
         p.draftedTeam = "DAL";
         p.age = 23;

         p.height = 75;   // 6'3"
         p.weight = 322;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1800000;
         p.contractBonus = 400000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 3000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 76);
         p.strength = std::max(p.strength, 92);
         p.agility = std::max(p.agility, 78);
         p.stamina = std::max(p.stamina, 86);

         // Mental
         p.awareness = std::max(p.awareness, 78);
         p.discipline = std::max(p.discipline, 80);
         p.morale = std::max(p.morale, 82);

         // Blocking
         p.passBlock = std::max(p.passBlock, 78);
         p.runBlock = std::max(p.runBlock, 84);
         p.impactBlock = std::max(p.impactBlock, 86);

         // Receiving (OL baseline)
         p.catchRating = 38;
         p.catchInTraffic = 32;
         p.spectacularCatch = 28;

         // Route running (irrelevant)
         p.routeRunningShort = 25;
         p.routeRunningMedium = 22;
         p.routeRunningDeep = 18;

         // Defensive attributes
         p.blockShed = 42;
         p.powerMoves = 35;
         p.finesseMoves = 30;
         p.tackle = 45;
         p.hitPower = 42;
         p.pursuit = 40;
         p.playRecognition = 60;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 82;
         p.riskTaking = 40;
         p.consistency = 75;
         p.clutch = 70;
         p.leadership = 65;
         p.motor = 88;
         p.disciplineTendency = 78;
         p.playStyle = 16; // Power center

         // Traits
         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 85;
         p.leadershipTrait = 60;
         p.clutchGeneTrait = 65;
         p.loyaltyTrait = 75;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Matt Hennessy — OL — 73 OVR
     {
         Player p("Matt Hennessy", "OL", 73);
         generateAttributesForPosition(p);

         p.college = "Temple";
         p.draftedTeam = "ATL";
         p.age = 26;

         p.height = 76;   // 6'4"
         p.weight = 295;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 2;
         p.contractSalary = 2500000;
         p.contractBonus = 500000;
         p.contractTotalValue = 5500000;
         p.contractDemand = 4000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = 72;
         p.strength = 86;
         p.agility = 78;
         p.stamina = 90;

         // Mental
         p.awareness = 80;
         p.discipline = 85;
         p.morale = 82;

         // Receiving (irrelevant for OL)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant)
         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         // Blocking (OL bread & butter)
         p.passBlock = 82;
         p.runBlock = 84;
         p.impactBlock = 86;

         // Defense (OL baseline)
         p.blockShed = 35;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = 60;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         // Tendencies
         p.aggression = 78;
         p.riskTaking = 40;
         p.consistency = 85;
         p.clutch = 70;
         p.leadership = 75;
         p.motor = 90;
         p.disciplineTendency = 85;
         p.playStyle = 61; // Interior OL technician

         // Traits
         p.workEthicTrait = 88;
         p.volatilityTrait = 20;
         p.professionalismTrait = 90;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 70;
         p.loyaltyTrait = 75;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 5;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // ===== RG =====
         // Tyler Booker — RG1 — 82 OVR
     {
         Player p("Tyler Booker", "RG", 82);
         generateAttributesForPosition(p);

         p.college = "Alabama";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 78;   // 6'6"
         p.weight = 335;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 2400000;
         p.contractBonus = 600000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 4500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 78);
         p.strength = std::max(p.strength, 94);
         p.agility = std::max(p.agility, 80);
         p.stamina = std::max(p.stamina, 88);

         // Mental
         p.awareness = std::max(p.awareness, 82);
         p.discipline = std::max(p.discipline, 85);
         p.morale = std::max(p.morale, 88);

         // Blocking
         p.passBlock = std::max(p.passBlock, 84);
         p.runBlock = std::max(p.runBlock, 90);
         p.impactBlock = std::max(p.impactBlock, 92);

         // Receiving (OL baseline)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running
         p.routeRunningShort = 30;
         p.routeRunningMedium = 25;
         p.routeRunningDeep = 20;

         // Defensive attributes
         p.blockShed = 45;
         p.powerMoves = 40;
         p.finesseMoves = 35;
         p.tackle = 50;
         p.hitPower = 45;
         p.pursuit = 45;
         p.playRecognition = 65;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 88;
         p.riskTaking = 45;
         p.consistency = 85;
         p.clutch = 80;
         p.leadership = 70;
         p.motor = 92;
         p.disciplineTendency = 80;
         p.playStyle = 18; // Power RG

         // Traits
         p.workEthicTrait = 90;
         p.volatilityTrait = 20;
         p.professionalismTrait = 90;
         p.leadershipTrait = 65;
         p.clutchGeneTrait = 75;
         p.loyaltyTrait = 80;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // T.J. Bass — RG2 — 69 OVR
     {
         Player p("T.J. Bass", "RG", 69);
         generateAttributesForPosition(p);

         p.college = "Oregon";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 76;   // 6'4"
         p.weight = 325;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 72);
         p.strength = std::max(p.strength, 88);
         p.agility = std::max(p.agility, 74);
         p.stamina = std::max(p.stamina, 82);

         // Mental
         p.awareness = std::max(p.awareness, 65);
         p.discipline = std::max(p.discipline, 72);
         p.morale = std::max(p.morale, 78);

         // Blocking
         p.passBlock = std::max(p.passBlock, 68);
         p.runBlock = std::max(p.runBlock, 72);
         p.impactBlock = std::max(p.impactBlock, 74);

         // Receiving (OL baseline)
         p.catchRating = 35;
         p.catchInTraffic = 30;
         p.spectacularCatch = 25;

         // Route running
         p.routeRunningShort = 25;
         p.routeRunningMedium = 22;
         p.routeRunningDeep = 18;

         // Defensive attributes
         p.blockShed = 38;
         p.powerMoves = 32;
         p.finesseMoves = 28;
         p.tackle = 42;
         p.hitPower = 38;
         p.pursuit = 38;
         p.playRecognition = 50;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 78;
         p.riskTaking = 35;
         p.consistency = 62;
         p.clutch = 55;
         p.leadership = 50;
         p.motor = 82;
         p.disciplineTendency = 70;
         p.playStyle = 19; // Depth RG

         // Traits
         p.workEthicTrait = 75;
         p.volatilityTrait = 25;
         p.professionalismTrait = 75;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Shiyazh Pete — OL — 69 OVR (Rookie, RG)
     {
         Player p("Shiyazh Pete", "OL", 69);
         generateAttributesForPosition(p);

         p.college = "Kentucky";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 81;   // 6'9"
         p.weight = 309;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = 4550000;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 68;
         p.strength = 88;
         p.agility = 74;
         p.stamina = 86;

         p.awareness = 58;
         p.discipline = 70;
         p.morale = 75;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 76;
         p.runBlock = 80;
         p.impactBlock = 84;

         p.blockShed = 35;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = 55;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.aggression = 82;
         p.riskTaking = 45;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 63; // Power RG

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 65;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // ===== RT =====
         // Terence Steele — RT1 — 78 OVR
     {
         Player p("Terence Steele", "RT", 78);
         generateAttributesForPosition(p);

         p.college = "Texas Tech";
         p.draftedTeam = "DAL";
         p.age = 27;

         p.height = 78;   // 6'6"
         p.weight = 320;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 8500000;
         p.contractBonus = 6000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 11000000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 78);
         p.strength = std::max(p.strength, 90);
         p.agility = std::max(p.agility, 80);
         p.stamina = std::max(p.stamina, 88);

         // Mental
         p.awareness = std::max(p.awareness, 80);
         p.discipline = std::max(p.discipline, 82);
         p.morale = std::max(p.morale, 88);

         // Blocking
         p.passBlock = std::max(p.passBlock, 80);
         p.runBlock = std::max(p.runBlock, 88);
         p.impactBlock = std::max(p.impactBlock, 90);

         // Receiving (OL baseline)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running
         p.routeRunningShort = 30;
         p.routeRunningMedium = 25;
         p.routeRunningDeep = 20;

         // Defensive attributes
         p.blockShed = 45;
         p.powerMoves = 40;
         p.finesseMoves = 35;
         p.tackle = 50;
         p.hitPower = 45;
         p.pursuit = 45;
         p.playRecognition = 60;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 85;
         p.riskTaking = 45;
         p.consistency = 80;
         p.clutch = 75;
         p.leadership = 70;
         p.motor = 90;
         p.disciplineTendency = 80;
         p.playStyle = 20; // Power RT

         // Traits
         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 85;
         p.leadershipTrait = 65;
         p.clutchGeneTrait = 70;
         p.loyaltyTrait = 80;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Ajani Cornelius — RT2 — 65 OVR
     {
         Player p("Ajani Cornelius", "RT", 65);
         generateAttributesForPosition(p);

         p.college = "Oregon";
         p.draftedTeam = "DAL";
         p.age = 23;

         p.height = 77;   // 6'5"
         p.weight = 315;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 74);
         p.strength = std::max(p.strength, 84);
         p.agility = std::max(p.agility, 76);
         p.stamina = std::max(p.stamina, 82);

         // Mental
         p.awareness = std::max(p.awareness, 60);
         p.discipline = std::max(p.discipline, 70);
         p.morale = std::max(p.morale, 75);

         // Blocking
         p.passBlock = std::max(p.passBlock, 66);
         p.runBlock = std::max(p.runBlock, 70);
         p.impactBlock = std::max(p.impactBlock, 72);

         // Receiving (OL baseline)
         p.catchRating = 35;
         p.catchInTraffic = 30;
         p.spectacularCatch = 25;

         // Route running
         p.routeRunningShort = 25;
         p.routeRunningMedium = 22;
         p.routeRunningDeep = 18;

         // Defensive attributes
         p.blockShed = 38;
         p.powerMoves = 32;
         p.finesseMoves = 28;
         p.tackle = 42;
         p.hitPower = 38;
         p.pursuit = 38;
         p.playRecognition = 50;
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 40;
         p.consistency = 60;
         p.clutch = 55;
         p.leadership = 50;
         p.motor = 80;
         p.disciplineTendency = 70;
         p.playStyle = 21; // Developmental RT

         // Traits
         p.workEthicTrait = 75;
         p.volatilityTrait = 25;
         p.professionalismTrait = 75;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // DJ Wingfield — OL — 68 OVR (Rookie, RT)
     {
         Player p("DJ Wingfield", "OL", 68);
         generateAttributesForPosition(p);

         p.college = "USC";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 76;   // 6'4"
         p.weight = 294;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = 4550000;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 70;
         p.strength = 84;
         p.agility = 78;
         p.stamina = 88;

         p.awareness = 56;
         p.discipline = 70;
         p.morale = 75;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 78;
         p.runBlock = 76;
         p.impactBlock = 82;

         p.blockShed = 35;
         p.powerMoves = 25;
         p.finesseMoves = 25;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 40;
         p.playRecognition = 55;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.aggression = 80;
         p.riskTaking = 45;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 90;
         p.disciplineTendency = 70;
         p.playStyle = 64; // Athletic RT

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 65;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // ===== DT =====
         // Quinnen Williams — DT1 — 90 OVR
     {
         Player p("Quinnen Williams", "DT", 90);
         generateAttributesForPosition(p);

         p.college = "Alabama";
         p.draftedTeam = "NYJ";
         p.age = 28;

         p.height = 75;   // 6'3"
         p.weight = 303;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 24000000;
         p.contractBonus = 8000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 28000000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 82);
         p.strength = std::max(p.strength, 96);
         p.agility = std::max(p.agility, 84);
         p.stamina = std::max(p.stamina, 92);

         // Mental
         p.awareness = std::max(p.awareness, 92);
         p.discipline = std::max(p.discipline, 88);
         p.morale = std::max(p.morale, 95);

         // Pass rush
         p.powerMoves = std::max(p.powerMoves, 95);
         p.finesseMoves = std::max(p.finesseMoves, 88);
         p.blockShed = std::max(p.blockShed, 94);

         // Run defense
         p.tackle = std::max(p.tackle, 92);
         p.hitPower = std::max(p.hitPower, 90);
         p.pursuit = std::max(p.pursuit, 88);
         p.playRecognition = std::max(p.playRecognition, 92);

         // Coverage (DT baseline)
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Receiving (irrelevant)
         p.catchRating = 35;
         p.catchInTraffic = 30;
         p.spectacularCatch = 25;

         // Tendencies
         p.aggression = 95;
         p.riskTaking = 60;
         p.consistency = 95;
         p.clutch = 90;
         p.leadership = 80;
         p.motor = 98;
         p.disciplineTendency = 85;
         p.playStyle = 30; // Elite interior disruptor

         // Traits
         p.workEthicTrait = 95;
         p.volatilityTrait = 20;
         p.professionalismTrait = 95;
         p.leadershipTrait = 80;
         p.clutchGeneTrait = 90;
         p.loyaltyTrait = 85;
         p.egoTrait = 40;
         p.mediaFriendlyTrait = 70;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Kenny Clark — DT2 — 78 OVR
     {
         Player p("Kenny Clark", "DT", 78);
         generateAttributesForPosition(p);

         p.college = "UCLA";
         p.draftedTeam = "GB";
         p.age = 28;

         p.height = 75;   // 6'3"
         p.weight = 314;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 17000000;
         p.contractBonus = 6000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 20000000;
         p.wantsExtension = true;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 74);
         p.strength = std::max(p.strength, 94);
         p.agility = std::max(p.agility, 76);
         p.stamina = std::max(p.stamina, 88);

         // Mental
         p.awareness = std::max(p.awareness, 82);
         p.discipline = std::max(p.discipline, 85);
         p.morale = std::max(p.morale, 88);

         // Pass rush
         p.powerMoves = std::max(p.powerMoves, 88);
         p.finesseMoves = std::max(p.finesseMoves, 70);
         p.blockShed = std::max(p.blockShed, 86);

         // Run defense
         p.tackle = std::max(p.tackle, 88);
         p.hitPower = std::max(p.hitPower, 85);
         p.pursuit = std::max(p.pursuit, 78);
         p.playRecognition = std::max(p.playRecognition, 82);

         // Coverage
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Receiving
         p.catchRating = 35;
         p.catchInTraffic = 30;
         p.spectacularCatch = 25;

         // Tendencies
         p.aggression = 88;
         p.riskTaking = 45;
         p.consistency = 82;
         p.clutch = 75;
         p.leadership = 70;
         p.motor = 90;
         p.disciplineTendency = 80;
         p.playStyle = 31; // Power NT/DT

         // Traits
         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 85;
         p.leadershipTrait = 65;
         p.clutchGeneTrait = 70;
         p.loyaltyTrait = 80;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Jonathan Bullard — DT — 73 OVR
     {
         Player p("Jonathan Bullard", "DL", 73);
         generateAttributesForPosition(p);

         p.college = "Florida";
         p.draftedTeam = "CHI";
         p.age = 32;

         p.height = 75;   // 6'3"
         p.weight = 290;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 1;
         p.contractSalary = 2000000;
         p.contractBonus = 300000;
         p.contractTotalValue = 2300000;
         p.contractDemand = 3500000;

         p.speed = 78;
         p.strength = 88;
         p.agility = 78;
         p.stamina = 86;

         p.awareness = 78;
         p.discipline = 80;
         p.morale = 80;

         p.powerMoves = 78;
         p.finesseMoves = 70;
         p.blockShed = 82;

         p.tackle = 82;
         p.hitPower = 80;
         p.pursuit = 78;
         p.playRecognition = 78;

         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 85;
         p.riskTaking = 45;
         p.consistency = 80;
         p.clutch = 70;
         p.leadership = 70;
         p.motor = 88;
         p.disciplineTendency = 80;
         p.playStyle = 71;

         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 85;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 70;
         p.loyaltyTrait = 75;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 5;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Tommy Dunn — DL — 68 OVR (Rookie)
     {
         Player p("Tommy Dunn", "DL", 68);
         generateAttributesForPosition(p);

         p.college = "Kansas";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 75;   // 6'3"
         p.weight = 291;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 70;
         p.strength = 88;
         p.agility = 72;
         p.stamina = 84;

         p.awareness = 58;
         p.discipline = 70;
         p.morale = 75;

         p.powerMoves = 72;
         p.finesseMoves = 60;
         p.blockShed = 74;

         p.tackle = 78;
         p.hitPower = 80;
         p.pursuit = 72;
         p.playRecognition = 58;

         p.manCoverage = 20;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 82;
         p.riskTaking = 45;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 72;

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;

         cowboys.addPlayer(p);
     }
     // Kelvin Gilliam — DL — 67 OVR (Rookie)
     {
         Player p("Kelvin Gilliam", "DL", 67);
         generateAttributesForPosition(p);

         p.college = "Virginia Tech";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 75;   // 6'3"
         p.weight = 285;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 78;
         p.strength = 82;
         p.agility = 80;
         p.stamina = 86;

         p.awareness = 56;
         p.discipline = 70;
         p.morale = 75;

         p.powerMoves = 70;
         p.finesseMoves = 72;
         p.blockShed = 68;

         p.tackle = 72;
         p.hitPower = 75;
         p.pursuit = 78;
         p.playRecognition = 56;

         p.manCoverage = 20;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 80;
         p.riskTaking = 50;
         p.consistency = 58;
         p.clutch = 55;
         p.leadership = 50;
         p.motor = 90;
         p.disciplineTendency = 70;
         p.playStyle = 73;

         p.workEthicTrait = 80;
         p.volatilityTrait = 30;
         p.professionalismTrait = 75;

         cowboys.addPlayer(p);
     }

     // Jay Toia — DT6 — 65 OVR
     {
         Player p("Jay Toia", "DT", 65);
         generateAttributesForPosition(p);

         p.college = "UCLA";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 75;   // 6'3"
         p.weight = 325;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1700000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = std::max(p.speed, 70);
         p.strength = std::max(p.strength, 90);
         p.agility = std::max(p.agility, 70);
         p.stamina = std::max(p.stamina, 80);

         // Mental
         p.awareness = std::max(p.awareness, 55);
         p.discipline = std::max(p.discipline, 65);
         p.morale = std::max(p.morale, 72);

         // Pass rush
         p.powerMoves = std::max(p.powerMoves, 68);
         p.finesseMoves = std::max(p.finesseMoves, 60);
         p.blockShed = std::max(p.blockShed, 72);

         // Run defense
         p.tackle = std::max(p.tackle, 75);
         p.hitPower = std::max(p.hitPower, 72);
         p.pursuit = std::max(p.pursuit, 70);
         p.playRecognition = std::max(p.playRecognition, 55);

         // Coverage
         p.manCoverage = 25;
         p.zoneCoverage = 30;
         p.pressCoverage = 25;

         // Receiving
         p.catchRating = 30;
         p.catchInTraffic = 28;
         p.spectacularCatch = 25;

         // Tendencies
         p.aggression = 80;
         p.riskTaking = 35;
         p.consistency = 60;
         p.clutch = 55;
         p.leadership = 45;
         p.motor = 78;
         p.disciplineTendency = 65;
         p.playStyle = 35; // Space-eating NT

         // Traits
         p.workEthicTrait = 75;
         p.volatilityTrait = 20;
         p.professionalismTrait = 75;
         p.leadershipTrait = 45;
         p.clutchGeneTrait = 50;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Adedayo Odeleye — DL — 66 OVR
     {
         Player p("Adedayo Odeleye", "DL", 66);
         generateAttributesForPosition(p);

         p.college = "Loughborough";
         p.draftedTeam = "HOU";
         p.age = 28;

         p.height = 77;   // 6'5"
         p.weight = 283;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 1;
         p.contractSalary = 1200000;
         p.contractBonus = 100000;

         p.speed = 80;
         p.strength = 80;
         p.agility = 82;
         p.stamina = 86;

         p.awareness = 55;
         p.discipline = 70;
         p.morale = 75;

         p.powerMoves = 68;
         p.finesseMoves = 70;
         p.blockShed = 66;

         p.tackle = 70;
         p.hitPower = 75;
         p.pursuit = 78;
         p.playRecognition = 55;

         p.manCoverage = 20;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 80;
         p.riskTaking = 50;
         p.consistency = 55;
         p.clutch = 55;
         p.leadership = 50;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 74;

         p.workEthicTrait = 78;
         p.volatilityTrait = 30;
         p.professionalismTrait = 75;

         cowboys.addPlayer(p);
     }
     // DJ Withers — DL — 67 OVR (Rookie)
     {
         Player p("DJ Withers", "DL", 67);
         generateAttributesForPosition(p);

         p.college = "Kansas";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 75;   // 6'3"
         p.weight = 285;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie)
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (penetrating DT)
         p.speed = 78;
         p.strength = 82;
         p.agility = 84;
         p.stamina = 86;

         // Mental
         p.awareness = 56;
         p.discipline = 70;
         p.morale = 75;

         // Pass rush
         p.powerMoves = 70;
         p.finesseMoves = 74;
         p.blockShed = 66;

         // Run defense
         p.tackle = 72;
         p.hitPower = 76;
         p.pursuit = 80;
         p.playRecognition = 56;

         // Coverage (DL baseline)
         p.manCoverage = 20;
         p.zoneCoverage = 25;
         p.pressCoverage = 20;

         // Ball skills (DL baseline)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant)
         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         // Blocking (DL baseline)
         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         // Tendencies
         p.aggression = 82;
         p.riskTaking = 55;
         p.consistency = 58;
         p.clutch = 55;
         p.leadership = 50;
         p.motor = 92;
         p.disciplineTendency = 70;
         p.playStyle = 78; // Penetrating 3-tech DT

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 55;
         p.loyaltyTrait = 65;
         p.egoTrait = 25;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // ===== R DE =====
     // Donovan Ezeiruaku — DE — 75 OVR
     {
         Player p("Donovan Ezeiruaku", "DE", 75);
         generateAttributesForPosition(p);

         p.college = "Boston College";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 75;   // 6'3"
         p.weight = 253;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (from your baseline)
         p.speed = 83;
         p.strength = 77;
         p.agility = 85;
         p.stamina = 88;       // scaled from INJ 91

         // Mental
         p.awareness = 73;
         p.discipline = 75;
         p.morale = 80;

         // Pass rush
         p.powerMoves = 78;
         p.finesseMoves = 82;
         p.blockShed = 76;

         // Run defense
         p.tackle = 78;
         p.hitPower = 76;
         p.pursuit = 82;
         p.playRecognition = 73;

         // Coverage (DE baseline)
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Receiving (irrelevant)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Tendencies
         p.aggression = 85;
         p.riskTaking = 55;
         p.consistency = 72;
         p.clutch = 70;
         p.leadership = 55;
         p.motor = 92;
         p.disciplineTendency = 75;
         p.playStyle = 40; // Speed rusher DE

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 20;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 65;
         p.loyaltyTrait = 75;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Malachi Lawrence — OLB (Right EDGE) — 69 OVR ( 1st Round Rookie)
     {
         Player p("Malachi Lawrence", "OLB", 69);
         generateAttributesForPosition(p);

         p.college = "UCF";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 76;   // 6'4"
         p.weight = 253;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie)
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (speed EDGE)
         p.speed = 88;
         p.strength = 76;
         p.agility = 86;
         p.stamina = 88;

         // Mental
         p.awareness = 60;
         p.discipline = 70;
         p.morale = 78;

         // Pass rush (rookie EDGE)
         p.powerMoves = 72;
         p.finesseMoves = 80;
         p.blockShed = 68;

         // Run defense
         p.tackle = 72;
         p.hitPower = 78;
         p.pursuit = 86;
         p.playRecognition = 60;

         // Coverage (OLB baseline)
         p.manCoverage = 45;
         p.zoneCoverage = 50;
         p.pressCoverage = 40;

         // Receiving (irrelevant)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant)
         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         // Blocking (non‑OL baseline)
         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         // Tendencies
         p.aggression = 88;
         p.riskTaking = 65;
         p.consistency = 60;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 95; // signature trait
         p.disciplineTendency = 70;
         p.playStyle = 47; // Speed rusher OLB

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 30;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Tyrus Wheat — RDE — 71 OVR
     {
         Player p("Tyrus Wheat", "RDE", 71);
         generateAttributesForPosition(p);

         p.college = "Mississippi State";
         p.draftedTeam = "DAL";
         p.age = 24;

         p.height = 74;   // 6'2"
         p.weight = 260;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 2;
         p.contractSalary = 1200000;
         p.contractBonus = 200000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (power EDGE)
         p.speed = 84;
         p.strength = 84;
         p.agility = 82;
         p.stamina = 88;

         // Mental
         p.awareness = 64;
         p.discipline = 70;
         p.morale = 78;

         // Pass rush
         p.powerMoves = 78;
         p.finesseMoves = 70;
         p.blockShed = 76;

         // Run defense
         p.tackle = 78;
         p.hitPower = 80;
         p.pursuit = 82;
         p.playRecognition = 64;

         // Coverage (EDGE baseline)
         p.manCoverage = 35;
         p.zoneCoverage = 40;
         p.pressCoverage = 35;

         // Receiving (irrelevant)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant)
         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         // Blocking (non‑OL baseline)
         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         // Tendencies
         p.aggression = 88;
         p.riskTaking = 55;
         p.consistency = 62;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 92;
         p.disciplineTendency = 70;
         p.playStyle = 46; // Power EDGE

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // Sam Williams — DE — 73 OVR
     {
         Player p("Sam Williams", "DE", 73);
         generateAttributesForPosition(p);

         p.college = "Ole Miss";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 76;   // 6'4"
         p.weight = 261;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 2;
         p.contractSalary = 2000000;
         p.contractBonus = 300000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 3500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (from your baseline)
         p.speed = 88;
         p.strength = 79;
         p.agility = 82;
         p.stamina = 88;       // scaled from INJ 88

         // Mental
         p.awareness = 68;
         p.discipline = 70;
         p.morale = 78;

         // Pass rush
         p.powerMoves = 78;
         p.finesseMoves = 84;
         p.blockShed = 76;

         // Run defense
         p.tackle = 78;
         p.hitPower = 80;
         p.pursuit = 86;
         p.playRecognition = 68;

         // Coverage
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Receiving
         p.catchRating = 38;
         p.catchInTraffic = 32;
         p.spectacularCatch = 28;

         // Tendencies
         p.aggression = 88;
         p.riskTaking = 60;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 50;
         p.motor = 95;
         p.disciplineTendency = 70;
         p.playStyle = 42; // Speed rusher DE

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 30;
         p.professionalismTrait = 75;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // ===== L DE =====
     // Rashan Gary — DE — 90 OVR
     {
         Player p("Rashan Gary", "DE", 90);
         generateAttributesForPosition(p);

         p.college = "Michigan";
         p.draftedTeam = "GB";
         p.age = 28;

         p.height = 77;   // 6'5"
         p.weight = 277;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 18000000;
         p.contractBonus = 8000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 22000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (elite EDGE)
         p.speed = 88;
         p.strength = 92;
         p.agility = 86;
         p.stamina = 92;

         // Mental
         p.awareness = 85;
         p.discipline = 82;
         p.morale = 90;

         // Pass rush
         p.powerMoves = 94;
         p.finesseMoves = 86;
         p.blockShed = 90;

         // Run defense
         p.tackle = 90;
         p.hitPower = 92;
         p.pursuit = 92;
         p.playRecognition = 85;

         // Coverage (DE baseline)
         p.manCoverage = 35;
         p.zoneCoverage = 40;
         p.pressCoverage = 35;

         // Receiving (irrelevant)
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Route running (irrelevant)
         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         // Blocking (non‑OL baseline)
         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         // Tendencies
         p.aggression = 95;
         p.riskTaking = 55;
         p.consistency = 88;
         p.clutch = 85;
         p.leadership = 75;
         p.motor = 99; // signature trait
         p.disciplineTendency = 80;
         p.playStyle = 46; // Power EDGE

         // Traits
         p.workEthicTrait = 90;
         p.volatilityTrait = 20;
         p.professionalismTrait = 88;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 80;
         p.loyaltyTrait = 75;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // Jadeveon Clowney — DE — 80 OVR
     {
         Player p("Jadeveon Clowney", "DE", 80);
         generateAttributesForPosition(p);

         p.college = "South Carolina";
         p.draftedTeam = "HOU";
         p.age = 31;

         p.height = 77;   // 6'5"
         p.weight = 255;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 6000000;
         p.contractBonus = 2000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 8000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (baseline)
         p.speed = 82;
         p.strength = 84;
         p.agility = 82;
         p.stamina = 86; // scaled from INJ 83

         // Mental
         p.awareness = 78;
         p.discipline = 80;
         p.morale = 85;

         // Pass rush
         p.powerMoves = 88;
         p.finesseMoves = 78;
         p.blockShed = 84;

         // Run defense
         p.tackle = 86;
         p.hitPower = 88;
         p.pursuit = 82;
         p.playRecognition = 78;

         // Coverage
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Receiving
         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         // Tendencies
         p.aggression = 90;
         p.riskTaking = 55;
         p.consistency = 80;
         p.clutch = 75;
         p.leadership = 70;
         p.motor = 92;
         p.disciplineTendency = 75;
         p.playStyle = 43; // Power DE

         // Traits
         p.workEthicTrait = 85;
         p.volatilityTrait = 30;
         p.professionalismTrait = 80;
         p.leadershipTrait = 60;
         p.clutchGeneTrait = 70;
         p.loyaltyTrait = 70;
         p.egoTrait = 40;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Dante Fowler Jr — DE — 76 OVR
     {
         Player p("Dante Fowler Jr", "DE", 76);
         generateAttributesForPosition(p);

         p.college = "Florida";
         p.draftedTeam = "JAX";
         p.age = 29;

         p.height = 75;   // 6'3"
         p.weight = 255;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 1;
         p.contractSalary = 3000000;
         p.contractBonus = 500000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 4500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (baseline)
         p.speed = 82;
         p.strength = 73;
         p.agility = 80;
         p.stamina = 86; // scaled from INJ 83

         // Mental
         p.awareness = 82;
         p.discipline = 78;
         p.morale = 82;

         // Pass rush
         p.powerMoves = 78;
         p.finesseMoves = 82;
         p.blockShed = 74;

         // Run defense
         p.tackle = 76;
         p.hitPower = 78;
         p.pursuit = 80;
         p.playRecognition = 82;

         // Coverage
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Receiving
         p.catchRating = 38;
         p.catchInTraffic = 32;
         p.spectacularCatch = 28;

         // Tendencies
         p.aggression = 85;
         p.riskTaking = 55;
         p.consistency = 72;
         p.clutch = 70;
         p.leadership = 60;
         p.motor = 88;
         p.disciplineTendency = 75;
         p.playStyle = 44; // Balanced DE

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 65;
         p.loyaltyTrait = 70;
         p.egoTrait = 35;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // James Houston IV — DE — 72 OVR
     {
         Player p("James Houston IV", "DE", 72);
         generateAttributesForPosition(p);

         p.college = "Jackson State";
         p.draftedTeam = "DET";
         p.age = 27;

         p.height = 73;   // 6'1"
         p.weight = 248;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 2;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (baseline)
         p.speed = 84;
         p.strength = 72;
         p.agility = 70;
         p.stamina = 90; // scaled from INJ 91

         // Mental
         p.awareness = 72;
         p.discipline = 70;
         p.morale = 78;

         // Pass rush
         p.powerMoves = 74;
         p.finesseMoves = 82;
         p.blockShed = 70;

         // Run defense
         p.tackle = 72;
         p.hitPower = 76;
         p.pursuit = 84;
         p.playRecognition = 72;

         // Coverage
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         // Receiving
         p.catchRating = 35;
         p.catchInTraffic = 30;
         p.spectacularCatch = 25;

         // Tendencies
         p.aggression = 85;
         p.riskTaking = 60;
         p.consistency = 68;
         p.clutch = 65;
         p.leadership = 50;
         p.motor = 95;
         p.disciplineTendency = 70;
         p.playStyle = 45; // Speed rusher DE

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 75;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 15;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // ===== WILL LB =====
     // DeMarvion Overshown — WILL — 77 OVR
     {
         Player p("DeMarvion Overshown", "WILL", 77);
         generateAttributesForPosition(p);

         p.college = "Texas";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 75;   // 6'3"
         p.weight = 230;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 3;
         p.contractSalary = 1800000;
         p.contractBonus = 400000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 3000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = 88;
         p.strength = 72;
         p.agility = 86;
         p.stamina = 90;

         // Mental
         p.awareness = 74;
         p.discipline = 78;
         p.morale = 82;

         // Coverage (WILL strength)
         p.manCoverage = 72;
         p.zoneCoverage = 78;
         p.pressCoverage = 55;

         // Run defense
         p.tackle = 80;
         p.hitPower = 76;
         p.pursuit = 90;
         p.playRecognition = 74;
         p.blockShed = 66;

         // Pass rush (WILL weak)
         p.powerMoves = 55;
         p.finesseMoves = 62;

         // Receiving (LB baseline)
         p.catchRating = 55;
         p.catchInTraffic = 50;
         p.spectacularCatch = 45;

         // Tendencies
         p.aggression = 82;
         p.riskTaking = 60;
         p.consistency = 75;
         p.clutch = 72;
         p.leadership = 65;
         p.motor = 95;
         p.disciplineTendency = 78;
         p.playStyle = 50; // Coverage WILL LB

         // Traits
         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 85;
         p.leadershipTrait = 60;
         p.clutchGeneTrait = 70;
         p.loyaltyTrait = 75;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Dee Winters — LB — 71 OVR
     {
         Player p("Dee Winters", "LB", 71);
         generateAttributesForPosition(p);

         p.college = "TCU";
         p.draftedTeam = "SF";
         p.age = 23;

         p.height = 71;   // 5'11"
         p.weight = 230;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 1200000;
         p.contractBonus = 200000;
         p.contractTotalValue = 2600000;
         p.contractDemand = 2500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 90;
         p.strength = 76;
         p.agility = 90;
         p.stamina = 90;

         p.awareness = 65;
         p.discipline = 72;
         p.morale = 78;

         p.tackle = 80;
         p.hitPower = 82;
         p.pursuit = 92;
         p.playRecognition = 65;
         p.blockShed = 66;

         p.powerMoves = 50;
         p.finesseMoves = 60;

         p.manCoverage = 66;
         p.zoneCoverage = 70;
         p.pressCoverage = 58;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 85;
         p.riskTaking = 60;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 95;
         p.disciplineTendency = 72;
         p.playStyle = 57; // Speed LB

         p.workEthicTrait = 82;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // Marist Liufau — WILL — 71 OVR
     {
         Player p("Marist Liufau", "WILL", 71);
         generateAttributesForPosition(p);

         p.college = "Notre Dame";
         p.draftedTeam = "DAL";
         p.age = 24;

         p.height = 75;   // 6'3"
         p.weight = 234;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 90;
         p.strength = 78;
         p.agility = 90;
         p.stamina = 92;

         p.awareness = 72;
         p.discipline = 75;
         p.morale = 80;

         p.tackle = 84;
         p.hitPower = 82;
         p.pursuit = 92;
         p.playRecognition = 72;
         p.blockShed = 70;

         p.powerMoves = 55;
         p.finesseMoves = 60;

         p.manCoverage = 70;
         p.zoneCoverage = 74;
         p.pressCoverage = 60;

         p.catchRating = 60;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 85;
         p.riskTaking = 60;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 60;
         p.motor = 95;
         p.disciplineTendency = 75;
         p.playStyle = 53;

         p.workEthicTrait = 85;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;

         cowboys.addPlayer(p);
     }
     // Justin Barron — S / LB — 72 OVR
     {
         Player p("Justin Barron", "S", 72);
         generateAttributesForPosition(p);

         p.college = "Syracuse";
         p.draftedTeam = "DAL";
         p.age = 23;

         p.height = 75;   // 6'3"
         p.weight = 220;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 3;
         p.contractSalary = 1200000;
         p.contractBonus = 150000;

         p.speed = 89;
         p.strength = 78;
         p.agility = 86;
         p.stamina = 90;

         p.awareness = 66;
         p.discipline = 72;
         p.morale = 78;

         p.manCoverage = 66;
         p.zoneCoverage = 70;
         p.pressCoverage = 65;

         p.tackle = 82;
         p.hitPower = 85;
         p.pursuit = 86;
         p.playRecognition = 66;
         p.blockShed = 65;

         p.powerMoves = 45;
         p.finesseMoves = 50;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 82;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 72;
         p.playStyle = 52;

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;

         cowboys.addPlayer(p);
     }
     // ===== MIKE =====
    // Langston Patterson — LB — 68 OVR (Rookie)
     {
         Player p("Langston Patterson", "LB", 68);
         generateAttributesForPosition(p);

         p.college = "Vanderbilt";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 73;   // 6'1"
         p.weight = 230;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 86;
         p.strength = 78;
         p.agility = 84;
         p.stamina = 88;

         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         p.tackle = 80;
         p.hitPower = 78;
         p.pursuit = 84;
         p.playRecognition = 60;
         p.blockShed = 65;

         p.powerMoves = 45;
         p.finesseMoves = 50;

         p.manCoverage = 62;
         p.zoneCoverage = 66;
         p.pressCoverage = 55;

         p.catchRating = 55;
         p.catchInTraffic = 50;
         p.spectacularCatch = 45;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 80;
         p.riskTaking = 55;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 70;
         p.playStyle = 55;

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;

         cowboys.addPlayer(p);
     }
     // Jaishawn Barham — LB — 74 OVR (Rookie)
     {
         Player p("Jaishawn Barham", "LB", 74);
         generateAttributesForPosition(p);

         p.college = "Michigan";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 74;   // 6'2"
         p.weight = 240;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 200000;
         p.contractTotalValue = 4600000;
         p.contractDemand = 2000000;

         p.speed = 88;
         p.strength = 84;
         p.agility = 86;
         p.stamina = 90;

         p.awareness = 68;
         p.discipline = 72;
         p.morale = 78;

         p.tackle = 88;
         p.hitPower = 90;
         p.pursuit = 90;
         p.playRecognition = 68;
         p.blockShed = 78;

         p.powerMoves = 70;
         p.finesseMoves = 65;

         p.manCoverage = 62;
         p.zoneCoverage = 66;
         p.pressCoverage = 55;

         p.catchRating = 55;
         p.catchInTraffic = 50;
         p.spectacularCatch = 45;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 90;
         p.riskTaking = 60;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 60;
         p.motor = 95;
         p.disciplineTendency = 75;
         p.playStyle = 51; // downhill LB

         p.workEthicTrait = 85;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;
         p.leadershipTrait = 60;
         p.clutchGeneTrait = 65;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // ===== SAM =====
     // Shemar James — LB — 73 OVR
     {
         Player p("Shemar James", "LB", 73);
         generateAttributesForPosition(p);

         p.college = "Florida";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 74;   // 6'2"
         p.weight = 230;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 90;
         p.strength = 76;
         p.agility = 88;
         p.stamina = 90;

         p.awareness = 65;
         p.discipline = 70;
         p.morale = 75;

         p.tackle = 82;
         p.hitPower = 80;
         p.pursuit = 90;
         p.playRecognition = 65;
         p.blockShed = 68;

         p.powerMoves = 50;
         p.finesseMoves = 55;

         p.manCoverage = 68;
         p.zoneCoverage = 72;
         p.pressCoverage = 58;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 82;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 92;
         p.disciplineTendency = 70;
         p.playStyle = 54;

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;

         cowboys.addPlayer(p);
     }
     // Curtis Robinson — LB — 68 OVR
     {
         Player p("Curtis Robinson", "LB", 68);
         generateAttributesForPosition(p);

         p.college = "Stanford";
         p.draftedTeam = "DEN";
         p.age = 25;

         p.height = 75;   // 6'3"
         p.weight = 235;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 1;
         p.contractSalary = 1200000;
         p.contractBonus = 150000;
         p.contractTotalValue = 1350000;
         p.contractDemand = 2000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 86;
         p.strength = 78;
         p.agility = 84;
         p.stamina = 88;

         p.awareness = 66;
         p.discipline = 72;
         p.morale = 78;

         p.tackle = 78;
         p.hitPower = 75;
         p.pursuit = 84;
         p.playRecognition = 66;
         p.blockShed = 65;

         p.powerMoves = 45;
         p.finesseMoves = 50;

         p.manCoverage = 62;
         p.zoneCoverage = 66;
         p.pressCoverage = 55;

         p.catchRating = 55;
         p.catchInTraffic = 50;
         p.spectacularCatch = 45;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 78;
         p.riskTaking = 55;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 72;
         p.playStyle = 56; // Smart, rangy LB

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 58;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }

     // ===== CB, DB, FS, SS =====
     {
         Player p("Corey Ballentine", "CB", 69);
         generateAttributesForPosition(p);

         p.college = "Washburn";
         p.draftedTeam = "NYG";
         p.age = 30;

         p.height = 72;
         p.weight = 196;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 1;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;
         p.contractTotalValue = 1700000;
         p.contractDemand = 2500000;

         p.speed = 94;
         p.strength = 70;
         p.agility = 92;
         p.stamina = 90;

         p.awareness = 68;
         p.discipline = 72;
         p.morale = 78;

         p.manCoverage = 72;
         p.zoneCoverage = 70;
         p.pressCoverage = 74;

         p.tackle = 65;
         p.hitPower = 60;
         p.pursuit = 72;
         p.playRecognition = 68;
         p.blockShed = 55;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 60;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 75;
         p.riskTaking = 60;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 12;

         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;

         cowboys.addPlayer(p);
     }
     {
         Player p("DaRon Bland", "CB", 85);
         generateAttributesForPosition(p);

         p.college = "Fresno State";
         p.draftedTeam = "DAL";
         p.age = 26;

         p.height = 74;
         p.weight = 200;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 3;
         p.contractSalary = 4500000;
         p.contractBonus = 3000000;
         p.contractTotalValue = 16500000;
         p.contractDemand = 9000000;

         p.speed = 93;
         p.strength = 74;
         p.agility = 94;
         p.stamina = 92;

         p.awareness = 88;
         p.discipline = 85;
         p.morale = 90;

         p.manCoverage = 88;
         p.zoneCoverage = 90;
         p.pressCoverage = 86;

         p.tackle = 78;
         p.hitPower = 75;
         p.pursuit = 88;
         p.playRecognition = 90;
         p.blockShed = 60;

         p.powerMoves = 35;
         p.finesseMoves = 40;

         p.catchRating = 78;
         p.catchInTraffic = 72;
         p.spectacularCatch = 70;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 80;
         p.riskTaking = 70;
         p.consistency = 90;
         p.clutch = 88;
         p.leadership = 75;
         p.motor = 95;
         p.disciplineTendency = 85;
         p.playStyle = 13;

         p.workEthicTrait = 90;
         p.volatilityTrait = 20;
         p.professionalismTrait = 90;
         p.leadershipTrait = 75;
         p.clutchGeneTrait = 90;
         p.loyaltyTrait = 75;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;

         cowboys.addPlayer(p);
     }
     {
         Player p("Trikweze Bridges", "CB", 70);
         generateAttributesForPosition(p);

         p.college = "Oregon";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 74;
         p.weight = 200;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 90;
         p.strength = 74;
         p.agility = 86;
         p.stamina = 88;

         p.awareness = 62;
         p.discipline = 70;
         p.morale = 75;

         p.manCoverage = 70;
         p.zoneCoverage = 72;
         p.pressCoverage = 78;

         p.tackle = 70;
         p.hitPower = 72;
         p.pursuit = 78;
         p.playRecognition = 62;
         p.blockShed = 55;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 62;
         p.catchInTraffic = 58;
         p.spectacularCatch = 55;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 78;
         p.riskTaking = 55;
         p.consistency = 62;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 14;

         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 60;

         cowboys.addPlayer(p);
     }
     {
         Player p("Josh Butler", "CB", 67);
         generateAttributesForPosition(p);

         p.college = "Michigan State";
         p.draftedTeam = "DAL";
         p.age = 29;

         p.height = 72;
         p.weight = 192;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 1;
         p.contractSalary = 1200000;
         p.contractBonus = 100000;

         p.speed = 92;
         p.strength = 68;
         p.agility = 90;
         p.stamina = 88;

         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         p.manCoverage = 68;
         p.zoneCoverage = 70;
         p.pressCoverage = 65;

         p.tackle = 62;
         p.hitPower = 60;
         p.pursuit = 70;
         p.playRecognition = 60;
         p.blockShed = 50;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 72;
         p.riskTaking = 55;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 15;

         p.workEthicTrait = 75;
         p.volatilityTrait = 25;
         p.professionalismTrait = 75;

         cowboys.addPlayer(p);
     }
     {
         Player p("Caelen Carson", "CB", 73);
         generateAttributesForPosition(p);

         p.college = "Wake Forest";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 72;
         p.weight = 198;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 91;
         p.strength = 72;
         p.agility = 90;
         p.stamina = 90;

         p.awareness = 68;
         p.discipline = 72;
         p.morale = 78;

         p.manCoverage = 76;
         p.zoneCoverage = 74;
         p.pressCoverage = 78;

         p.tackle = 70;
         p.hitPower = 68;
         p.pursuit = 78;
         p.playRecognition = 68;
         p.blockShed = 55;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 62;
         p.catchInTraffic = 58;
         p.spectacularCatch = 55;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 78;
         p.riskTaking = 55;
         p.consistency = 68;
         p.clutch = 65;
         p.leadership = 55;
         p.motor = 88;
         p.disciplineTendency = 70;
         p.playStyle = 16;

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;

         cowboys.addPlayer(p);
     }
     {
         Player p("Cobie Durant", "CB", 74);
         generateAttributesForPosition(p);

         p.college = "South Carolina State";
         p.draftedTeam = "LAR";
         p.age = 28;

         p.height = 71;
         p.weight = 181;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 2000000;
         p.contractBonus = 300000;

         p.speed = 94;
         p.strength = 66;
         p.agility = 94;
         p.stamina = 90;

         p.awareness = 72;
         p.discipline = 75;
         p.morale = 80;

         p.manCoverage = 78;
         p.zoneCoverage = 76;
         p.pressCoverage = 70;

         p.tackle = 65;
         p.hitPower = 60;
         p.pursuit = 78;
         p.playRecognition = 72;
         p.blockShed = 50;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 65;
         p.catchInTraffic = 60;
         p.spectacularCatch = 58;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 78;
         p.riskTaking = 60;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 75;
         p.playStyle = 17;

         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;

         cowboys.addPlayer(p);
     }
     {
         Player p("Derion Kendrick", "CB", 72);
         generateAttributesForPosition(p);

         p.college = "Georgia";
         p.draftedTeam = "LAR";
         p.age = 25;

         p.height = 72;
         p.weight = 205;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;

         p.speed = 90;
         p.strength = 72;
         p.agility = 88;
         p.stamina = 88;

         p.awareness = 70;
         p.discipline = 72;
         p.morale = 78;

         p.manCoverage = 74;
         p.zoneCoverage = 72;
         p.pressCoverage = 76;

         p.tackle = 70;
         p.hitPower = 68;
         p.pursuit = 75;
         p.playRecognition = 70;
         p.blockShed = 55;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 60;
         p.catchInTraffic = 55;
         p.spectacularCatch = 52;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 75;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 60;
         p.leadership = 55;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 18;

         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;

         cowboys.addPlayer(p);
     }
     {
         Player p("Devin Moore", "CB", 68);
         generateAttributesForPosition(p);

         p.college = "Florida";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 75;
         p.weight = 198;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 91;
         p.strength = 70;
         p.agility = 88;
         p.stamina = 88;

         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         p.manCoverage = 70;
         p.zoneCoverage = 68;
         p.pressCoverage = 72;

         p.tackle = 65;
         p.hitPower = 62;
         p.pursuit = 72;
         p.playRecognition = 60;
         p.blockShed = 50;

         p.powerMoves = 30;
         p.finesseMoves = 35;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 52;

         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         p.aggression = 72;
         p.riskTaking = 55;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 19;

         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;

         cowboys.addPlayer(p);
     }
     // Shavon Revel Jr — CB — 67 OVR
     {
         Player p("Shavon Revel Jr", "CB", 67);
         generateAttributesForPosition(p);

         p.college = "Louisville";
         p.draftedTeam = "DAL";
         p.age = 24;

         p.height = 74;   // 6'2"
         p.weight = 198;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie)
         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 1800000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical (long outside CB)
         p.speed = 90;
         p.strength = 70;
         p.agility = 86;
         p.stamina = 88;

         // Mental
         p.awareness = 58;
         p.discipline = 70;
         p.morale = 75;

         // Coverage
         p.manCoverage = 68;
         p.zoneCoverage = 66;
         p.pressCoverage = 74;

         // Run support
         p.tackle = 66;
         p.hitPower = 62;
         p.pursuit = 72;
         p.playRecognition = 58;
         p.blockShed = 50;

         // Pass rush (CB baseline)
         p.powerMoves = 25;
         p.finesseMoves = 30;

         // Ball skills
         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 52;

         // Route running (irrelevant)
         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         // Blocking (CB baseline)
         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         // Tendencies
         p.aggression = 75;
         p.riskTaking = 55;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 20; // Long press CB

         // Traits
         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;
         p.leadershipTrait = 50;
         p.clutchGeneTrait = 58;
         p.loyaltyTrait = 65;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Reddy Steward — CB — 70 OVR
     {
         Player p("Reddy Steward", "CB", 70);
         generateAttributesForPosition(p);

         p.college = "Troy";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 71;   // 5'11"
         p.weight = 178;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie/young player)
         p.contractYears = 3;
         p.contractSalary = 1200000;
         p.contractBonus = 150000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 2000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = 91;
         p.strength = 70;
         p.agility = 90;
         p.stamina = 90;

         // Mental
         p.awareness = 66;
         p.discipline = 72;
         p.morale = 78;

         // Coverage
         p.manCoverage = 74;
         p.zoneCoverage = 72;
         p.pressCoverage = 70;

         // Run support
         p.tackle = 68;
         p.hitPower = 62;
         p.pursuit = 74;
         p.playRecognition = 66;
         p.blockShed = 52;

         // Pass rush (CB baseline)
         p.powerMoves = 28;
         p.finesseMoves = 32;

         // Ball skills
         p.catchRating = 60;
         p.catchInTraffic = 55;
         p.spectacularCatch = 52;

         // Route running (irrelevant)
         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         // Blocking (CB baseline)
         p.passBlock = 30;
         p.runBlock = 30;
         p.impactBlock = 35;

         // Tendencies
         p.aggression = 78;
         p.riskTaking = 55;
         p.consistency = 65;
         p.clutch = 62;
         p.leadership = 55;
         p.motor = 90;
         p.disciplineTendency = 72;
         p.playStyle = 21; // Competitive coverage CB

         // Traits
         p.workEthicTrait = 80;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;
         p.leadershipTrait = 55;
         p.clutchGeneTrait = 62;
         p.loyaltyTrait = 70;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Caleb Downs — FS — 85 OVR
     {
         Player p("Caleb Downs", "FS", 85);
         generateAttributesForPosition(p);

         p.college = "Ohio State";
         p.draftedTeam = "DAL";
         p.age = 21;

         p.height = 72;   // 6'0"
         p.weight = 205;

         // Health
         p.injured = false;
         p.injuryWeeks = 0;

         // Contract (rookie star)
         p.contractYears = 4;
         p.contractSalary = 3500000;
         p.contractBonus = 5000000;
         p.contractTotalValue = p.contractYears * p.contractSalary + p.contractBonus;
         p.contractDemand = 9000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         // Physical
         p.speed = 92;
         p.strength = 74;
         p.agility = 92;
         p.stamina = 94;

         // Mental
         p.awareness = 88;
         p.discipline = 85;
         p.morale = 90;

         // Coverage
         p.manCoverage = 78;
         p.zoneCoverage = 90;
         p.pressCoverage = 70;

         // Run defense
         p.tackle = 92;
         p.hitPower = 88;
         p.pursuit = 94;
         p.playRecognition = 90;
         p.blockShed = 72;

         // Pass rush (FS baseline)
         p.powerMoves = 40;
         p.finesseMoves = 50;

         // Receiving (DB ball skills)
         p.catchRating = 70;
         p.catchInTraffic = 65;
         p.spectacularCatch = 60;

         // Route running (irrelevant)
         p.routeRunningShort = 25;
         p.routeRunningMedium = 20;
         p.routeRunningDeep = 15;

         // Blocking (DB baseline)
         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         // Tendencies
         p.aggression = 85;
         p.riskTaking = 55;
         p.consistency = 88;
         p.clutch = 85;
         p.leadership = 75;
         p.motor = 95;
         p.disciplineTendency = 85;
         p.playStyle = 32; // Elite FS

         // Traits
         p.workEthicTrait = 90;
         p.volatilityTrait = 20;
         p.professionalismTrait = 90;
         p.leadershipTrait = 75;
         p.clutchGeneTrait = 85;
         p.loyaltyTrait = 75;
         p.egoTrait = 30;
         p.mediaFriendlyTrait = 55;
         p.enigmaticTrait = 10;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Markquese Bell — SS — 74 OVR
     {
         Player p("Markquese Bell", "SS", 74);
         generateAttributesForPosition(p);

         p.college = "Florida A&M";
         p.draftedTeam = "DAL";
         p.age = 25;

         p.height = 74;   // 6'3"
         p.weight = 215;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 2000000;
         p.contractBonus = 300000;
         p.contractTotalValue = 4300000;
         p.contractDemand = 3500000;

         p.speed = 91;
         p.strength = 78;
         p.agility = 88;
         p.stamina = 92;

         p.awareness = 70;
         p.discipline = 75;
         p.morale = 80;

         p.manCoverage = 68;
         p.zoneCoverage = 72;
         p.pressCoverage = 65;

         p.tackle = 86;
         p.hitPower = 90;
         p.pursuit = 88;
         p.playRecognition = 72;
         p.blockShed = 70;

         p.powerMoves = 55;
         p.finesseMoves = 60;

         p.catchRating = 60;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 88;
         p.riskTaking = 55;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 60;
         p.motor = 95;
         p.disciplineTendency = 75;
         p.playStyle = 33;

         p.workEthicTrait = 85;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;

         cowboys.addPlayer(p);
     }
     // Alijah Clark — S — 69 OVR
     {
         Player p("Alijah Clark", "S", 69);
         generateAttributesForPosition(p);

         p.college = "Rutgers";
         p.draftedTeam = "DAL";
         p.age = 22;

         p.height = 73;   // 6'1"
         p.weight = 200;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 4;
         p.contractSalary = 1100000;
         p.contractBonus = 150000;

         p.speed = 90;
         p.strength = 70;
         p.agility = 88;
         p.stamina = 88;

         p.awareness = 60;
         p.discipline = 70;
         p.morale = 75;

         p.manCoverage = 66;
         p.zoneCoverage = 70;
         p.pressCoverage = 62;

         p.tackle = 72;
         p.hitPower = 70;
         p.pursuit = 76;
         p.playRecognition = 60;
         p.blockShed = 55;

         p.powerMoves = 35;
         p.finesseMoves = 40;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 75;
         p.riskTaking = 55;
         p.consistency = 60;
         p.clutch = 58;
         p.leadership = 50;
         p.motor = 85;
         p.disciplineTendency = 70;
         p.playStyle = 34;

         p.workEthicTrait = 78;
         p.volatilityTrait = 25;
         p.professionalismTrait = 78;

         cowboys.addPlayer(p);
     }
     // Malik Hooker — FS — 82 OVR
     {
         Player p("Malik Hooker", "FS", 82);
         generateAttributesForPosition(p);

         p.college = "Ohio State";
         p.draftedTeam = "IND";
         p.age = 30;

         p.height = 73;
         p.weight = 215;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 3;
         p.contractSalary = 6000000;
         p.contractBonus = 4000000;

         p.speed = 92;
         p.strength = 72;
         p.agility = 94;
         p.stamina = 90;

         p.awareness = 88;
         p.discipline = 85;
         p.morale = 90;

         p.manCoverage = 78;
         p.zoneCoverage = 90;
         p.pressCoverage = 70;

         p.tackle = 72;
         p.hitPower = 70;
         p.pursuit = 88;
         p.playRecognition = 90;
         p.blockShed = 55;

         p.powerMoves = 35;
         p.finesseMoves = 40;

         p.catchRating = 78;
         p.catchInTraffic = 70;
         p.spectacularCatch = 68;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 70;
         p.riskTaking = 65;
         p.consistency = 85;
         p.clutch = 82;
         p.leadership = 75;
         p.motor = 88;
         p.disciplineTendency = 85;
         p.playStyle = 35;

         p.workEthicTrait = 85;
         p.volatilityTrait = 20;
         p.professionalismTrait = 90;

         cowboys.addPlayer(p);
     }
     // P.J. Locke — S — 73 OVR
     {
         Player p("P.J. Locke", "S", 73);
         generateAttributesForPosition(p);

         p.college = "Texas";
         p.draftedTeam = "DEN";
         p.age = 29;

         p.height = 70;
         p.weight = 202;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 2500000;
         p.contractBonus = 300000;

         p.speed = 91;
         p.strength = 78;
         p.agility = 90;
         p.stamina = 90;

         p.awareness = 72;
         p.discipline = 75;
         p.morale = 80;

         p.manCoverage = 70;
         p.zoneCoverage = 72;
         p.pressCoverage = 68;

         p.tackle = 82;
         p.hitPower = 88;
         p.pursuit = 86;
         p.playRecognition = 72;
         p.blockShed = 65;

         p.powerMoves = 45;
         p.finesseMoves = 50;

         p.catchRating = 58;
         p.catchInTraffic = 55;
         p.spectacularCatch = 50;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 30;
         p.runBlock = 35;
         p.impactBlock = 40;

         p.aggression = 88;
         p.riskTaking = 55;
         p.consistency = 70;
         p.clutch = 65;
         p.leadership = 60;
         p.motor = 95;
         p.disciplineTendency = 75;
         p.playStyle = 36;

         p.workEthicTrait = 85;
         p.volatilityTrait = 25;
         p.professionalismTrait = 80;

         cowboys.addPlayer(p);
     }
     // ===== Special Teams =====
     // Trent Sieg — LS — 69 OVR
     {
         Player p("Trent Sieg", "LS", 69);
         generateAttributesForPosition(p);

         p.college = "Colorado State";
         p.draftedTeam = "OAK";
         p.age = 28;

         p.height = 76;   // 6'4"
         p.weight = 235;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 1500000;
         p.contractBonus = 200000;
         p.contractTotalValue = 3200000;
         p.contractDemand = 2500000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 72;
         p.strength = 82;
         p.agility = 70;
         p.stamina = 88;

         p.awareness = 78;
         p.discipline = 85;
         p.morale = 80;

         p.catchRating = 55;
         p.catchInTraffic = 50;
         p.spectacularCatch = 45;

         p.routeRunningShort = 20;
         p.routeRunningMedium = 15;
         p.routeRunningDeep = 10;

         p.passBlock = 78;
         p.runBlock = 75;
         p.impactBlock = 70;

         p.blockShed = 55;
         p.powerMoves = 40;
         p.finesseMoves = 35;
         p.tackle = 60;
         p.hitPower = 55;
         p.pursuit = 60;
         p.playRecognition = 75;
         p.manCoverage = 30;
         p.zoneCoverage = 35;
         p.pressCoverage = 30;

         p.aggression = 70;
         p.riskTaking = 40;
         p.consistency = 90;
         p.clutch = 75;
         p.leadership = 70;
         p.motor = 85;
         p.disciplineTendency = 85;
         p.playStyle = 90; // LS specialist

         p.workEthicTrait = 85;
         p.volatilityTrait = 10;
         p.professionalismTrait = 90;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 75;
         p.loyaltyTrait = 80;
         p.egoTrait = 20;
         p.mediaFriendlyTrait = 50;
         p.enigmaticTrait = 5;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Brandon Aubrey — K — 83 OVR
     {
         Player p("Brandon Aubrey", "K", 83);
         generateAttributesForPosition(p);

         p.college = "Notre Dame";
         p.draftedTeam = "DAL";
         p.age = 31;

         p.height = 75;   // 6'3"
         p.weight = 218;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 3;
         p.contractSalary = 3500000;
         p.contractBonus = 1000000;
         p.contractTotalValue = 11500000;
         p.contractDemand = 5000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 70;
         p.strength = 72;
         p.agility = 75;
         p.stamina = 88;

         p.awareness = 82;
         p.discipline = 90;
         p.morale = 90;

         p.catchRating = 40;
         p.catchInTraffic = 35;
         p.spectacularCatch = 30;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 25;
         p.runBlock = 25;
         p.impactBlock = 25;

         p.blockShed = 20;
         p.powerMoves = 10;
         p.finesseMoves = 10;
         p.tackle = 35;
         p.hitPower = 30;
         p.pursuit = 40;
         p.playRecognition = 70;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.kickPower = 94;
         p.kickAccuracy = 96;
         p.puntPower = 40;
         p.puntAccuracy = 35;

         p.aggression = 40;
         p.riskTaking = 30;
         p.consistency = 95;
         p.clutch = 92;
         p.leadership = 70;
         p.motor = 80;
         p.disciplineTendency = 90;
         p.playStyle = 99; // Kicker specialist

         p.workEthicTrait = 90;
         p.volatilityTrait = 10;
         p.professionalismTrait = 95;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 95;
         p.loyaltyTrait = 75;
         p.egoTrait = 20;
         p.mediaFriendlyTrait = 60;
         p.enigmaticTrait = 5;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }
     // Bryan Anger — P — 82 OVR
     {
         Player p("Bryan Anger", "P", 82);
         generateAttributesForPosition(p);

         p.college = "California";
         p.draftedTeam = "JAX";
         p.age = 35;

         p.height = 75;   // 6'3"
         p.weight = 214;

         p.injured = false;
         p.injuryWeeks = 0;

         p.contractYears = 2;
         p.contractSalary = 3000000;
         p.contractBonus = 1000000;
         p.contractTotalValue = 7000000;
         p.contractDemand = 4000000;
         p.wantsExtension = false;
         p.holdingOut = false;

         p.speed = 72;
         p.strength = 75;
         p.agility = 78;
         p.stamina = 90;

         p.awareness = 85;
         p.discipline = 88;
         p.morale = 90;

         p.catchRating = 55;
         p.catchInTraffic = 50;
         p.spectacularCatch = 45;

         p.routeRunningShort = 10;
         p.routeRunningMedium = 5;
         p.routeRunningDeep = 5;

         p.passBlock = 25;
         p.runBlock = 25;
         p.impactBlock = 25;

         p.blockShed = 20;
         p.powerMoves = 10;
         p.finesseMoves = 10;
         p.tackle = 40;
         p.hitPower = 35;
         p.pursuit = 45;
         p.playRecognition = 75;
         p.manCoverage = 20;
         p.zoneCoverage = 20;
         p.pressCoverage = 20;

         p.kickPower = 40;
         p.kickAccuracy = 35;
         p.puntPower = 95;
         p.puntAccuracy = 94;

         p.aggression = 40;
         p.riskTaking = 30;
         p.consistency = 92;
         p.clutch = 88;
         p.leadership = 70;
         p.motor = 80;
         p.disciplineTendency = 88;
         p.playStyle = 98; // Punter specialist

         p.workEthicTrait = 85;
         p.volatilityTrait = 10;
         p.professionalismTrait = 95;
         p.leadershipTrait = 70;
         p.clutchGeneTrait = 90;
         p.loyaltyTrait = 75;
         p.egoTrait = 20;
         p.mediaFriendlyTrait = 60;
         p.enigmaticTrait = 5;
         p.hometownHeroTrait = 0;

         cowboys.addPlayer(p);
     }


}
std::vector<Player> generateDraftClass() {
    std::vector<Player> draftClass;
    draftClass.reserve(256);

    for (int pick = 1; pick <= 256; pick++) {

        int round = (pick - 1) / 32 + 1;
        int pickInRound = (pick - 1) % 32 + 1;

        // 1. Generate name, position, and OVR
        std::string name = generateRandomName();
        std::string pos = generateRandomPosition();

        int ovr = 0;

        // ⭐ OVR generation by round (realistic)
        if (round == 1) {
            // Rare generational players
            int roll = randRange(1, 1000);
            if (roll == 1) ovr = randRange(85, 90);        // 0.1% chance generational
            else if (roll <= 30) ovr = randRange(80, 84);  // 3% chance elite
            else ovr = randRange(74, 79);                  // normal 1st rounder
        }
        else if (round == 2) {
            ovr = randRange(70, 75);
        }
        else if (round == 3) {
            ovr = randRange(68, 73);
        }
        else if (round == 4) {
            ovr = randRange(65, 70);
        }
        else if (round == 5) {
            ovr = randRange(63, 68);
        }
        else if (round == 6) {
            ovr = randRange(61, 66);
        }
        else { // Round 7
            ovr = randRange(60, 64);
        }

        // 2. Create player
        Player p(name, pos, ovr);

        // 3. Generate attributes
        generateAttributesForPosition(p);

        // 4. Apply REAL rookie contract
        applyRookieContract(p, round, pick);

        // 5. Add to draft class
        draftClass.push_back(p);
    }

    return draftClass;
}


int main() {

    League league;

    // NFC EAST
    Team cowboys("Dallas Cowboys", "Dallas", "DAL", 83, 82);
    loadCowboysRoster(cowboys);
    league.teams.push_back(cowboys);

    Team commanders("Washington Commanders", "Washington", "WAS", 80, 83);
    loadCommandersRoster(commanders);
    league.teams.push_back(commanders);

    Team giants("New York Giants", "New York", "NYG", 78, 80);
    loadGiantsRoster(giants);
    league.teams.push_back(giants);

    Team eagles("Philadelphia Eagles", "Philadelphia", "PHI", 87, 79);
    loadEaglesRoster(eagles);
    league.teams.push_back(eagles);

    // NFC NORTH
    Team packers("Green Bay Packers", "Green Bay", "GB", 84, 82);
    loadPackersRoster(packers);
    league.teams.push_back(packers);

    Team lions("Detroit Lions", "Detroit", "DET", 86, 81);
    loadLionsRoster(lions);
    league.teams.push_back(lions);

    Team bears("Chicago Bears", "Chicago", "CHI", 79, 77);
    loadBearsRoster(bears);
    league.teams.push_back(bears);

    Team vikings("Minnesota Vikings", "Minnesota", "MIN", 82, 80);
    loadVikingsRoster(vikings);
    league.teams.push_back(vikings);

    // NFC SOUTH
    Team buccaneers("Tampa Bay Buccaneers", "Tampa Bay", "TB", 81, 80);
    loadBuccaneersRoster(buccaneers);
    league.teams.push_back(buccaneers);

    Team saints("New Orleans Saints", "New Orleans", "NO", 82, 83);
    loadSaintsRoster(saints);
    league.teams.push_back(saints);

    Team falcons("Atlanta Falcons", "Atlanta", "ATL", 80, 79);
    loadFalconsRoster(falcons);
    league.teams.push_back(falcons);

    Team panthers("Carolina Panthers", "Carolina", "CAR", 75, 78);
    loadPanthersRoster(panthers);
    league.teams.push_back(panthers);

    // NFC WEST
    Team rams("Los Angeles Rams", "Los Angeles", "LAR", 85, 82);
    loadRamsRoster(rams);
    league.teams.push_back(rams);

    Team sf49ers("San Francisco 49ers", "San Francisco", "SF", 92, 90);
    load49ersRoster(sf49ers);
    league.teams.push_back(sf49ers);

    Team seahawks("Seattle Seahawks", "Seattle", "SEA", 82, 80);
    loadSeahawksRoster(seahawks);
    league.teams.push_back(seahawks);

    Team cardinals("Arizona Cardinals", "Arizona", "ARI", 76, 78);
    loadCardinalsRoster(cardinals);
    league.teams.push_back(cardinals);

    // AFC EAST
    Team bills("Buffalo Bills", "Buffalo", "BUF", 88, 84);
    loadBillsRoster(bills);
    league.teams.push_back(bills);

    Team dolphins("Miami Dolphins", "Miami", "MIA", 87, 81);
    loadDolphinsRoster(dolphins);
    league.teams.push_back(dolphins);

    Team patriots("New England Patriots", "New England", "NE", 75, 79);
    loadPatriotsRoster(patriots);
    league.teams.push_back(patriots);

    Team jets("New York Jets", "New York", "NYJ", 83, 85);
    loadJetsRoster(jets);
    league.teams.push_back(jets);

    // AFC NORTH
    Team ravens("Baltimore Ravens", "Baltimore", "BAL", 90, 88);
    loadRavensRoster(ravens);
    league.teams.push_back(ravens);

    Team bengals("Cincinnati Bengals", "Cincinnati", "CIN", 89, 84);
    loadBengalsRoster(bengals);
    league.teams.push_back(bengals);

    Team steelers("Pittsburgh Steelers", "Pittsburgh", "PIT", 82, 86);
    loadSteelersRoster(steelers);
    league.teams.push_back(steelers);

    Team browns("Cleveland Browns", "Cleveland", "CLE", 84, 85);
    loadBrownsRoster(browns);
    league.teams.push_back(browns);

    // AFC SOUTH
    Team jaguars("Jacksonville Jaguars", "Jacksonville", "JAX", 84, 80);
    loadJaguarsRoster(jaguars);
    league.teams.push_back(jaguars);

    Team colts("Indianapolis Colts", "Indianapolis", "IND", 82, 79);
    loadColtsRoster(colts);
    league.teams.push_back(colts);

    Team texans("Houston Texans", "Houston", "HOU", 86, 82);
    loadTexansRoster(texans);
    league.teams.push_back(texans);

    Team titans("Tennessee Titans", "Tennessee", "TEN", 78, 80);
    loadTitansRoster(titans);
    league.teams.push_back(titans);

    // AFC WEST
    Team chiefs("Kansas City Chiefs", "Kansas City", "KC", 93, 88);
    loadChiefsRoster(chiefs);
    league.teams.push_back(chiefs);

    Team chargers("Los Angeles Chargers", "Los Angeles", "LAC", 84, 81);
    loadChargersRoster(chargers);
    league.teams.push_back(chargers);

    Team broncos("Denver Broncos", "Denver", "DEN", 80, 79);
    loadBroncosRoster(broncos);
    league.teams.push_back(broncos);

    Team raiders("Las Vegas Raiders", "Las Vegas", "LV", 78, 77);
    loadRaidersRoster(raiders);
    league.teams.push_back(raiders);

    return 0;
}


    int userTeamIndex = 0; // control Dallas Cowboys
    GameSimulator simulator;

    bool running = true;
    while (running) {
        mainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            printRoster(league.teams[userTeamIndex]);
            break;
        case 2:
            league.printStandings();
            break;
        case 3:
            if (!league.seasonFinished()) {
                league.simulateWeek(simulator, userTeamIndex);
            }
            else {
                std::cout << "Season already finished. Start a new one (not implemented yet).\n";
            }
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Thanks for playing the prototype.\n";
    return 0;
}
