#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <set>

#include "game.hpp"
#include "player.hpp"


// Algorithme de gestion des coupons d'échange
void claimTerritory(std::vector<std::vector<char>>& commonGrid, int gridSize, Player& player, int x, int y, char playerLetter) {
    char territoryLetter = commonGrid[x][y];

    switch (territoryLetter) {
    case 'E':
        player.addExchangeTile();
        // Remplace la lettre bonus par la lettre du joueur
        commonGrid[x][y] = playerLetter;
        break;

    case 'R':
        player.useExchangeCoupon();
        std::cout << "Coupon d'echange de tuiles utilise avec succes." << std::endl;

        int x, y;
        std::cout << "Entrez les coordonnees (Ligne Colonne) pour voler un carre d'un autre joueur : ";
        std::cin >> x >> y;

        // Vérification si les coordonnées sont valides
        if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
            char tileOwner = commonGrid[x][y];

            // Vérification si la tuile appartient à un autre joueur
            if (tileOwner != '.' && tileOwner != player.getTileLetter()) {
                // Vole du carré en le remplaçant par une tuile du joueur actuel
                commonGrid[x][y] = player.getTileLetter();
                std::cout << "Carre vole avec succes !" << std::endl;
                printGrid(commonGrid);
            }
            else {
                std::cout << "Aucun carre a voler sur ces coordonnees." << std::endl;
            }
        }
        else {
            std::cout << "Coordonnees invalides. Veuillez reessayer." << std::endl;
        }
        break;

    case 'S':
        int newX, newY;
        std::cout << "Entrez les coordonnees (Ligne Colonne) pour placer la tuile de pierre : ";
        std::cin >> newX >> newY;

        if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize && commonGrid[newX][newY] == '.') {
            commonGrid[newX][newY] = '#';
            std::cout << "Tuile de pierre placee avec succes." << std::endl;
            printGrid(commonGrid);
        }
        else {
            std::cout << "Emplacement invalide. La tuile de pierre ne peut pas etre placee ici." << std::endl;
        }
        break;

    default:
        // Pas de bonus ne rien faire dans ce cas
        break;
    }
}

// Fonction pour placer deux lettres aléatoires sur la grille
void placeLetters(std::vector<std::vector<char>>& grid, char letter, int count) {
    int gridSize = grid.size();

    for (int i = 0; i < count; ++i) {
        int x = rand() % gridSize;
        int y = rand() % gridSize;

        // Assurez-vous que l'emplacement est vide
        while (grid[x][y] != '.') {
            x = rand() % gridSize;
            y = rand() % gridSize;
        }

        // Placez la lettre à l'emplacement aléatoire
        grid[x][y] = letter;
    }
}

// Fonction pour placer les lettres 'S', 'R' et 'E' sur la grille
void placeAllLetters(std::vector<std::vector<char>>& grid) {
    placeLetters(grid, 'S', 2);
    placeLetters(grid, 'R', 2);
    placeLetters(grid, 'E', 2);
}

// Fonction pour afficher la grille principale
void printGrid(const std::vector<std::vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Fonction pour vérifier si une case adjacente fait partie du joueur
bool isAdjacentToOwnTile(const std::vector<std::vector<char>>& grid, int x, int y, char playerLetter) {
    // Vérifier les cases adjacentes
    std::vector<std::pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (const auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == playerLetter) {
            return true;
        }
    }
    return false;
}

// Fonction pour vérifier la possibilité de pose d'une tuile sur la grille
bool placeTileOnGrid(std::vector<std::vector<char>>& grid, const std::vector<std::vector<char>>& tile, int startX, int startY, char refChar, bool isFirstTurn) {
    int refX = -1, refY = -1;
    for (int i = 0; i < tile.size(); ++i) {
        for (int j = 0; j < tile[i].size(); ++j) {
            if (tile[i][j] == tolower(refChar)) {
                refX = i; refY = j;
                break;
            }
        }
        if (refX != -1) break;
    }
    if (refX == -1 || refY == -1) return false;

    startX -= refX; startY -= refY;

    bool touchesOwnTile = false;
    for (int i = 0; i < tile.size(); ++i) {
        for (int j = 0; j < tile[i].size(); ++j) {
            int x = startX + i; int y = startY + j;
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || (tile[i][j] != '.' && grid[x][y] != '.')) {
                return false;
            }
            // Ajoutez cette vérification pour empêcher le placement sur une case avec '#'
            if (grid[x][y] == '#') {
                std::cout << "Impossible de placer la tuile sur une case avec '#'. Veuillez choisir une autre case." << std::endl;
                return false;
            }
            if (!isFirstTurn && tile[i][j] != '.' && isAdjacentToOwnTile(grid, x, y, refChar)) {
                touchesOwnTile = true;
            }
        }
    }

    if (!isFirstTurn && !touchesOwnTile) return false;

    for (int i = 0; i < tile.size(); ++i) {
        for (int j = 0; j < tile[i].size(); ++j) {
            int x = startX + i; int y = startY + j;
            if (tile[i][j] != '.') {
                grid[x][y] = tile[i][j];
            }
        }
    }
    return true;
}

// Fonction pour placer une tuile de 1x1 au début du jeu
void placeSingleTile(std::vector<std::vector<char>>& grid, int x, int y, char letter) {
    while (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '.') {
        std::cout << "La case specifiee n'est pas vide ou est hors des limites. Veuillez choisir une case valide." << std::endl;

        // Demander au joueur de saisir de nouvelles coordonnées
        std::cout << "Entrez les nouvelles coordonnees (Ligne Colonne) pour la tuile: ";
        std::cin >> x >> y;
    }

    // Placer la tuile une fois que des coordonnées valides ont été fournies
    grid[x][y] = letter;
}

// Fonction pour calculer le plus grand carré en fonction des joueurs
int findLargestSquareForPlayer(const std::vector<std::vector<char>>& grid, char playerLetter) {
    std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), 0));
    int maxSize = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == playerLetter) {
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] += std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
                maxSize = std::max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize;
}