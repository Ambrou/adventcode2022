// Day06.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std::literals;


bool ifContain(const std::string& line, const size_t loop, const size_t size )
{
    bool found = true;
    for (size_t index = 0; index < size - 1; ++index && found)
    {
        found &= std::find(line.begin() + index + 1 + loop, line.begin() + size + loop, line[index + loop]) == line.begin() + size + loop;
    }
    return found;
}

int main()
{
    std::ifstream input { "Input.txt"s };
    std::string line; 
    std::getline(input, line);
    size_t position {};



    for (size_t loop = 0; loop < line.size(); ++loop)
    {
        if(ifContain(line, loop, 14))
        {
            position = loop + 14;
            break;
        }
    }

    


    std::cout << "Hello World!\n" << position;
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
