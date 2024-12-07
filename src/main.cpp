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