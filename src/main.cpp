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