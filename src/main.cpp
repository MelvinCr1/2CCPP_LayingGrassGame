#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <set>

#include "Tile.hpp"
#include "Player.hpp"
#include "game.hpp"

using namespace std;


// Fonction main responsable de l’initialisation du jeu et de la boucle du jeu
int main() {
    srand(time(nullptr));
    std::set<char> chosenLetters;

    std::cout << "-----------------" << std::endl;
    std::cout << "LAYING GRASS GAME" << std::endl;
    std::cout << "-----------------" << std::endl;

    // Algorithme de gestion du nombre de joueurs et de leurs caractéristiques
    int numPlayers;
    do {
        std::cout << "Entrez le nombre de joueurs (2-9): ";
        std::cin >> numPlayers;

        if (numPlayers < 2 || numPlayers > 9) {
            std::cout << "Veuillez choisir un nombre de joueurs entre 2 et 9." << std::endl;
        }
    } while (numPlayers < 2 || numPlayers > 9);

    srand(time(nullptr));
    int gridSize = (numPlayers <= 4) ? 20 : 30;
    std::vector<std::vector<char>> commonGrid(gridSize, std::vector<char>(gridSize, '.'));

    placeAllLetters(commonGrid);

    std::vector<Player> players;
    for (int i = 0; i < numPlayers; ++i) {
        std::string playerName;
        std::cout << "Entrez le nom du joueur " << i + 1 << ": ";
        std::cin >> playerName;
        players.emplace_back(i + 1, playerName, gridSize);

        char letter;
        do {
            std::cout << "Joueur " << i + 1 << ", choisissez une lettre unique pour vos tuiles : ";
            char inputLetter;
            std::cin >> inputLetter;
            letter = std::toupper(inputLetter);

            if (letter == '.' || letter == '#' || letter == 'S' || letter == 'E' || letter == 'R') {
                std::cout << "Veuillez choisir une lettre differente de '.'; '#'; 'E'; 'S' ou 'R'." << std::endl;
                continue;
            }

        } while (chosenLetters.find(letter) != chosenLetters.end() || letter == '.' || letter == '#');

        chosenLetters.insert(letter);
        players[i].setTileLetter(letter);

        std::set<int> generatedNumbers;
        for (int j = 0; j < 5; ++j) {
            int randomNumber;
            do {
                randomNumber = rand() % 96 + 1;
            } while (generatedNumbers.find(randomNumber) != generatedNumbers.end());
            generatedNumbers.insert(randomNumber);
            players[i].addTile(randomNumber);
        }
    }

    // Boucle des tours de jeu
    int roundNumber = 0;

    for (int turn = 0; turn < 2; ++turn) {
        ++roundNumber;

        for (Player& player : players) {
            int couponCount = player.getExchangeCoupon();
            char playerLetter = player.getTileLetter();
            int choice, x, y;
            bool placed = false;

            std::cout << "--------------------------------------" << std::endl;
            std::cout << "Tour du joueur " << player.getId() << " (" << player.getName() << ") - Round " << roundNumber << std::endl;
            std::cout << "Nombre de coupon(s) d'echange disponible(s) : " << couponCount << std::endl;
            std::cout << "--------------------------------------" << std::endl;

            if (turn == 0) {
                printGrid(commonGrid);
                std::cout << "Premier tour : placez une tuile d'une seule case." << std::endl;
                std::cout << "Entrez les coordonnees de depart (Ligne Colonne) pour la tuile: ";
                int inputX, inputY;

                while (!(std::cin >> inputX >> inputY) || std::cin.peek() != '\n') {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Veuillez entrer des coordonnees valides (chiffres uniquement): ";
                }

                x = inputX;
                y = inputY;

                placeSingleTile(commonGrid, x, y, playerLetter);

            }
            else {
                const std::vector<Tile>& tiles = player.getTiles();
                for (int i = 0; i < tiles.size(); ++i) {
                    auto tileForm = tiles[i].Form(playerLetter);
                    std::cout << "Tuile " << i + 1 << ":" << std::endl;
                    for (const auto& row : tileForm) {
                        for (char c : row) {
                            std::cout << c << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }

                // Placement de tuile
                do {
                    std::cout << "Choisissez une tuile a placer (1, 2, 3, 4 OU 5): ";
                    std::cin >> choice;

                    if (choice < 1 || choice > 5) {
                        std::cout << "Veuillez choisir une tuile valide (1, 2, 3, 4 ou 5)." << std::endl;
                        continue;
                    }

                    std::cout << "Entrez les coordonnees de depart (Ligne Colonne) pour la lettre minuscule de la tuile: ";
                    std::cin >> x >> y;

                    placed = placeTileOnGrid(commonGrid, tiles[choice - 1].Form(playerLetter), x, y, playerLetter, turn == 0);

                    if (placed) {
                        // Algorithme de vérification pour accorder les bonus
                        for (int x = 0; x < gridSize; ++x) {
                            for (int y = 0; y < gridSize; ++y) {
                                // Vérifier si la lettre du joueur est à côté de 'E', 'S' ou 'R'
                                if (commonGrid[x][y] == playerLetter) {
                                    // Vérifier les positions adjacentes (horizontales et verticales)
                                    for (int dx = -1; dx <= 1; ++dx) {
                                        for (int dy = -1; dy <= 1; ++dy) {
                                            // Exclure les positions en diagonale
                                            if ((dx == 0 || dy == 0) && !(dx == 0 && dy == 0)) {
                                                int newX = x + dx;
                                                int newY = y + dy;

                                                // Vérifier si les nouvelles coordonnées sont dans la grille
                                                if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
                                                    char adjacentLetter = commonGrid[newX][newY];
                                                    // Vérifier si la lettre est 'E', 'S' ou 'R'
                                                    if (adjacentLetter == 'E' || adjacentLetter == 'R' || adjacentLetter == 'S') {
                                                        claimTerritory(commonGrid, gridSize, player, newX, newY, playerLetter);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                    }
                    else {
                        char decision;
                        std::cout << "Impossible de placer la tuile aux coordonnees donnees. Voulez-vous reessayer (R) ou passer votre tour (P) ? [R/P] ";
                        std::cin >> decision;
                        if (decision == 'P' || decision == 'p') {
                            break;
                        }
                    }

                } while (!placed);


                if (placed) {
                    player.removeTile(choice - 1);
                    player.addNewTile();
                }
            }
            printGrid(commonGrid);
        }
    }

    for (Player& player : players) {
        int tileCount = player.getExchangeTile();

        if (tileCount > 0) {
            char decision;
            std::cout << "Joueur " << player.getId() << ", vous avez " << tileCount << " coupon(s) d'echange de tuiles restant(s)." << std::endl;
            std::cout << "Voulez-vous utiliser un coupon pour placer une tuile de 1x1 sur la grille ? (O/N) ";
            std::cin >> decision;

            if (decision == 'O' || decision == 'o') {
                int x, y;
                std::cout << "Entrez les coordonnees (Ligne Colonne) pour placer la tuile de 1x1 : ";
                std::cin >> x >> y;

                if (x >= 0 && x < gridSize && y >= 0 && y < gridSize && (commonGrid[x][y] == '.' || commonGrid[x][y] == '#')) {
                    commonGrid[x][y] = player.getTileLetter();
                    std::cout << "Tuile de 1x1 placee avec succes." << std::endl;

                    // Décrémentez le compte de coupons après utilisation
                    player.useExchangeTile();
                }
                else {
                    std::cout << "Emplacement invalide. La tuile de 1x1 ne peut pas etre placee ici." << std::endl;
                }
            }
        }
    }

    printGrid(commonGrid);

    int maxSquare = 0, winningPlayer = 0;
    for (const Player& player : players) {
        int squareSize = findLargestSquareForPlayer(commonGrid, player.getTileLetter());
        if (squareSize > maxSquare) {
            maxSquare = squareSize;
            winningPlayer = player.getId();
        }
    }
    std::cout << "Le joueur " << winningPlayer << " a le plus grand carre de taille " << maxSquare << "." << std::endl;
    return 0;
}
