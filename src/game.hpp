#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

#include "player.hpp"

void claimTerritory(std::vector<std::vector<char>>& commonGrid, int gridSize, Player& player, int x, int y, char playerLetter);

// Fonction pour placer deux lettres aléatoires sur la grille
void placeLetters(std::vector<std::vector<char>>& grid, char letter, int count);

// Fonction pour placer les lettres 'S', 'R' et 'E' sur la grille
void placeAllLetters(std::vector<std::vector<char>>& grid);

// Fonction pour afficher la grille principale
void printGrid(const std::vector<std::vector<char>>& grid);

// Fonction pour vérifier si une case adjacente fait partie du joueur
bool isAdjacentToOwnTile(const std::vector<std::vector<char>>& grid, int x, int y, char playerLetter);

// Fonction pour vérifier la possibilité de pose d'une tuile sur la grille
bool placeTileOnGrid(std::vector<std::vector<char>>& grid, const std::vector<std::vector<char>>& tile, int startX, int startY, char refChar, bool isFirstTurn);

// Fonction pour placer une tuile de 1x1 au début du jeu
void placeSingleTile(std::vector<std::vector<char>>& grid, int x, int y, char letter);

// Fonction pour calculer le plus grand carré en fonction des joueurs
int findLargestSquareForPlayer(const std::vector<std::vector<char>>& grid, char playerLetter);

#endif // GAME_HPP
