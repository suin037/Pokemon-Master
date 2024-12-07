#include <iostream> // Includes standard input and output functionality
#include <string> // Includes string handling functionality
#include <vector> // Includes vector for dynamic arrays
#include <iomanip> // includes functionality for formatted output

using namespace std; // Allows using standard namespace components without prefixing 'std::'

// Enumeration for Pokemon types
enum Type { Normal, Ground, Electric, Water, Grass, Fire };

// Function to convert Type enum to its corresponding string representation
string typeToString(Type type) {
    switch (type) {
        case Normal: return "Normal";       // Converts 'Normal' type to string
        case Ground: return "Ground";       // Converts 'Ground' type to string
        case Electric: return "Electric";   // Converts 'Electric' type to string
        case Water: return "Water";         // Converts 'Water' type to string
        case Grass: return "Grass";         // Converts 'Grass' type to string
        case Fire: return "Fire";           // Converts 'Fire' type to string
        default: return "Unknown";          // Returns 'Unknown' for undefined types
    }
}

// Struct for Skill
struct Skill {
    string name;         // The name of the skill 
    Type type;           // The type of the skill 
    int damage;          // The damage value of the skill
    int maxTry;          // The maximum number of times the skill can be used
    int remainingUses;   // The remaining number of uses for the skill

    // Constructor to initialize a Skill object with given values
    Skill(string n, Type t, int d, int m) 
        : name(n), type(t), damage(d), maxTry(m), remainingUses(m) {}
        // Initializes the skill's name, type, damage, maximum uses, 
        // and sets the remaining uses to the maximum uses
};


// Struct for Pokemon
struct Pokemon {
    string name;         // The name of the Pokémon (e.g., "Pikachu")
    Type type;           // The type of the Pokémon (e.g., Electric, Water)
    int maxHP;           // The maximum health points (HP) of the Pokémon
    int currentHP;       // The current health points (HP) of the Pokémon
    vector<Skill> skills; // A list of skills the Pokémon can use

    // Constructor to initialize a Pokemon object with given values
    Pokemon(string n, Type t, int hp, vector<Skill> s) 
        : name(n), type(t), maxHP(hp), currentHP(hp), skills(s) {}
        // Initializes the Pokémon's name, type, maximum HP, current HP, 
        // and the list of skills. Sets current HP equal to max HP by default.
};

// Function to create all Pokemons with their predefined skills
vector<Pokemon> createPokemons() {
    vector<Pokemon> pokemons; // A list to store all the created Pokémon

    // Pikachu
    vector<Skill> pikachuSkills = {
        Skill("Tackle", Normal, 4, 5),         // A basic Normal-type move
        Skill("Grass Knot", Grass, 8, 5),     // A Grass-type move
        Skill("Thunderbolt", Electric, 10, 5),// A powerful Electric-type move
        Skill("Megabolt", Electric, 15, 3)    // A high-damage Electric-type move with limited uses
    };
    pokemons.push_back(Pokemon("Pikachu", Electric, 35, pikachuSkills));
    // Adds Pikachu with its skills and stats to the Pokémon list

    // Dratini
    vector<Skill> dratiniSkills = {
        Skill("Wrap", Normal, 4, 10),          // A Normal-type move with multiple uses
        Skill("Aqua Tail", Water, 3, 5),      // A basic Water-type move
        Skill("Water Pulse", Water, 13, 2),   // A powerful Water-type move
        Skill("Hyper Beam", Normal, 20, 1)    // A very strong Normal-type move with a single use
    };
    pokemons.push_back(Pokemon("Dratini", Water, 41, dratiniSkills));
    // Adds Dratini with its skills and stats to the Pokémon list

    // Eevee
    vector<Skill> eeveeSkills = {
        Skill("Tackle", Normal, 4, 5),         // A common Normal-type move
        Skill("Sand Attack", Ground, 8, 3),   // A Ground-type move with moderate power
        Skill("Bite", Normal, 12, 3),         // A strong Normal-type move
        Skill("Rain Dance", Water, 15, 1)     // A single-use Water-type move
    };
    pokemons.push_back(Pokemon("Eevee", Normal, 55, eeveeSkills));
    // Adds Eevee with its skills and stats to the Pokémon list

    // Charmander
    vector<Skill> charmanderSkills = {
        Skill("Tackle", Normal, 4, 5),         // A basic Normal-type move
        Skill("Flamethrower", Fire, 11, 5),   // A powerful Fire-type move
        Skill("Dig", Ground, 7, 5),           // A Ground-type move with balanced power
        Skill("Heat Wave", Fire, 14, 5)       // A high-damage Fire-type move
    };
    pokemons.push_back(Pokemon("Charmander", Fire, 39, charmanderSkills));
    // Adds Charmander with its skills and stats to the Pokémon list

    // Palkia
    vector<Skill> palkiaSkills = {
        Skill("Hydro Pump", Water, 12, 10),    // A strong Water-type move
        Skill("Earth Power", Ground, 15, 10), // A powerful Ground-type move
        Skill("Surf", Water, 13, 10),         // A consistent Water-type move
        Skill("Spatial Rend", Normal, 30, 10) // A very high-damage Normal-type move
    };
    pokemons.push_back(Pokemon("Palkia", Water, 90, palkiaSkills));
    // Adds Palkia with its skills and stats to the Pokémon list

    return pokemons; // Returns the list of created Pokémon
}

// Function to calculate the effectiveness of a skill based on the types of the skill and the opponent
int calculateEffectiveness(Type skillType, Type opponentType) {
    // Cases where the skill is super effective against the opponent's type
    if ((skillType == Ground && opponentType == Electric) || // Ground is super effective against Electric
        (skillType == Ground && opponentType == Fire) ||     // Ground is super effective against Fire
        (skillType == Electric && opponentType == Water) ||  // Electric is super effective against Water
        (skillType == Water && opponentType == Fire) ||      // Water is super effective against Fire
        (skillType == Water && opponentType == Ground) ||    // Water is super effective against Ground
        (skillType == Fire && opponentType == Grass) ||      // Fire is super effective against Grass
        (skillType == Grass && opponentType == Water)) {     // Grass is super effective against Water
        return 5;  // Super effective: return a positive value to indicate high effectiveness
    }
    // Cases where the skill is not very effective against the opponent's type
    else if ((skillType == Electric && opponentType == Electric) ||  // Electric vs Electric is not very effective
             (skillType == Fire && opponentType == Fire) ||          // Fire vs Fire is not very effective
             (skillType == Water && opponentType == Water) ||        // Water vs Water is not very effective
             (skillType == Water && opponentType == Grass) ||        // Water vs Grass is not very effective
             (skillType == Grass && opponentType == Fire) ||         // Grass vs Fire is not very effective
             (skillType == Fire && opponentType == Water) ||         // Fire vs Water is not very effective
             (skillType == Electric && opponentType == Ground) ||    // Electric vs Ground is not very effective
             (skillType == Electric && opponentType == Grass) ||     // Electric vs Grass is not very effective
             (skillType == Ground && opponentType == Grass) ||       // Ground vs Grass is not very effective
             (skillType == Grass && opponentType == Ground) ||       // Grass vs Ground is not very effective
             (skillType == Grass && opponentType == Grass)) {        // Grass vs Grass is not very effective
        return -3; // Not very effective: return a negative value to indicate low effectiveness
    }
    // Cases where the skill has normal effectiveness
    return 0;  // Normal effectiveness: return zero for balanced matchups
}

// Helper function to resize two strings to a fixed width and align them with a separator
string resizeToFixedWidth(const string& leftStr, const string& rightStr, char sep = '|', size_t width = 63) {
    size_t sectionWidth = 29; // Each section (left and right) is fixed to 29 characters
    string left = leftStr;    // Copy of the left string
    string right = rightStr;  // Copy of the right string

    // Adjust the left string to the fixed width
    if (left.size() < sectionWidth) {
        // If the string is shorter than the section width, pad with spaces
        left += string(sectionWidth - left.size(), ' ');
    } else {
        // If the string exceeds the section width, truncate it
        left = left.substr(0, sectionWidth);
    }

    // Adjust the right string to the fixed width
    if (right.size() < sectionWidth) {
        // If the string is shorter than the section width, pad with spaces
        right += string(sectionWidth - right.size(), ' ');
    } else {
        // If the string exceeds the section width, truncate it
        right = right.substr(0, sectionWidth);
    }

    // Combine the adjusted strings with the separator and spaces
    return left + " " + sep + " " + right;
}