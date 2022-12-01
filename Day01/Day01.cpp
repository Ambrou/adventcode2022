// Day01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::literals;
namespace ranges = std::ranges;

int main()
{
    std::ifstream input { "Input.txt"s };

    std::uint64_t calories {};
    std::vector<std::uint64_t> listOfCalories {};
    std::uint64_t maxCalory {};
    for (std::string line; std::getline(input, line); )
    {
        if (!line.empty())
        {
            calories += std::stoi(line);
        }
        else
        {
            listOfCalories.push_back(calories);
            calories = 0;
        }
    }
    ranges::sort(listOfCalories, ranges::greater());
    std::cout << "Max calories = "s << listOfCalories[0] + listOfCalories[1] + listOfCalories[2];
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
