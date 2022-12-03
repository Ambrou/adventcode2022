// Day03.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ranges>
#include <vector>
#include <algorithm>
#include <set>

using namespace std::literals;

std::set<char> FindInterSection(const std::set<char>& st1, const std::set<char>& st2)
{
    std::set<char> st0;
    std::set_intersection(st1.begin(), st1.end(),
                          st2.begin(), st2.end(),
                          std::inserter(st0, st0.end()));

    return st0;
}

std::set<char> FindSharedLetters(const std::string& s1, const std::string& s2)
{
    std::set<char> st1(s1.begin(), s1.end());
    std::set<char> st2(s2.begin(), s2.end());

    return FindInterSection(st1, st2);
}


int main()
{

    const auto toValue = [] (const auto& found) 
    {
        if ('a' <= found && found <= 'z')
        {
            return found - 'a' + 1;
        }
        else
        {
            return found - 'A' + 27;
        }
    };

    std::uint32_t prioritiesSum {0};
    std::ifstream input { "Input.txt"s };
    for (std::string line1; std::getline(input, line1); )
    {
        std::string line2;
        std::string line3;
        std::getline(input, line2);
        std::getline(input, line3);

        auto a = FindSharedLetters(line1, line2);
        auto b = FindSharedLetters(line3, line2);

        auto st0 = FindInterSection(a, b);

        prioritiesSum += toValue(*st0.begin());
    }
    std::cout << "Hello World!\n" << prioritiesSum;
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
