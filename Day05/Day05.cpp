// Day05.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <array>
#include <regex>

using namespace std::literals;

int main()
{
    std::array<std::vector<std::int8_t>, 9> stacks;
    std::ifstream input { "Input.txt"s };
    const std::regex moveRegex("move ([[:digit:]]+) from ([[:digit:]]+) to ([[:digit:]]+)");
    std::smatch moveMatch;
    for (std::string line; std::getline(input, line); )
    {
        if (line.find('[') != std::string::npos)
        {
            if (line[1] != ' ')
            {
                stacks[0].insert(stacks[0].begin(), line[1]);
            }
            if (line[5] != ' ')
            {
                stacks[1].insert(stacks[1].begin(), line[5]);
            }
            if (line[9] != ' ')
            {
                stacks[2].insert(stacks[2].begin(), line[9]);
            }
            if (line[13] != ' ')
            {
                stacks[3].insert(stacks[3].begin(), line[13]);
            }
            if (line[17] != ' ')
            {
                stacks[4].insert(stacks[4].begin(), line[17]);
            }
            if (line[21] != ' ')
            {
                stacks[5].insert(stacks[5].begin(), line[21]);
            }
            if (line[25] != ' ')
            {
                stacks[6].insert(stacks[6].begin(), line[25]);
            }
            if (line[29] != ' ')
            {
                stacks[7].insert(stacks[7].begin(), line[29]);
            }
            if (line[33] != ' ')
            {
                stacks[8].insert(stacks[8].begin(), line[33]);
            }
        }
        if (std::regex_search(line, moveMatch, moveRegex))
        {
            const auto howMany { stoul(moveMatch[1]) };
            const auto from { stoul(moveMatch[2]) };
            const auto to { stoul(moveMatch[3]) };

            for (auto loop = 0l; loop < howMany; ++loop)
            {
                stacks[to-1].push_back(stacks[from - 1].back());
                stacks[from - 1].pop_back();
            }
        }

    }

    std::string result { };

     for (auto& stack : stacks)
    {
        result += stack.back();
    }

    std::cout << "Hello World!\n" << result;
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
