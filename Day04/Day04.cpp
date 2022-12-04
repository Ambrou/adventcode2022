// Day04.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

using namespace std::literals;

int main()
{
    std::ifstream input { "Input.txt"s };

    std::uint32_t count { };

    for (std::string line; std::getline(input, line); )
    {
        std::smatch rangeMatch;
        const std::regex rangeRegex("([[:digit:]]+)-([[:digit:]]+),([[:digit:]]+)-([[:digit:]]+)");
        std::regex_search(line, rangeMatch, rangeRegex);


        std::uint64_t firstRangeMin { std::stoul(rangeMatch[1]) };
        std::uint64_t firstRangeMax { std::stoul(rangeMatch[2]) };
        std::uint64_t secondRangeMin { std::stoul(rangeMatch[3]) };
        std::uint64_t secondRangeMax { std::stoul(rangeMatch[4]) };

        if ((firstRangeMin <= secondRangeMin && secondRangeMax <= firstRangeMax) || (secondRangeMin <= firstRangeMin && firstRangeMax <= secondRangeMax))
        {
            count++;
        }
    } 

    std::cout << "Hello World!\n" << count;
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
