// Day02.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdint>

using namespace std::literals;

int main()
{
    std::ifstream input { "Input.txt"s };
    constexpr std::uint32_t rock { 1 };
    constexpr std::uint32_t paper { 2 };
    constexpr std::uint32_t scissors { 3 };
    constexpr std::uint32_t lost { 0 };
    constexpr std::uint32_t draw { 3 };
    constexpr std::uint32_t won { 6 };


    const std::map<std::string, std::uint32_t> resultTable { 
        {"A X"s, draw + rock},
        {"A Y"s, won + paper},
        {"A Z"s, lost + scissors},
        {"B X"s, lost + rock},
        {"B Y"s, draw + paper},
        {"B Z"s, won + scissors},
        {"C X"s, won + rock},
        {"C Y"s, lost + paper},
        {"C Z"s, draw + scissors}
    };

    std::uint32_t score { 0 };

    for (std::string line; std::getline(input, line); )
    {
        score += resultTable.at(line);
    }

    std::cout << "Hello World!\n" << score;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
