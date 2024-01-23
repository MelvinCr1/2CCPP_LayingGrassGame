#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>
#include <set>

#include "Tile.hpp"

class Player {
private:
    int id_player;
    std::string name_player;
    std::vector<Tile> tiles;
    std::vector<std::vector<char>> grid;
    char tileLetter;
    int exchangeCoupon;
    int exchangeTile;

public:
    Player(int id, std::string name, int gridSize) : id_player(id), name_player(name), grid(gridSize, std::vector<char>(gridSize, '.')), exchangeCoupon(1), exchangeTile(0) {}
    
    int getId() const { return id_player; }
    std::string getName() const { return name_player; }
    const std::vector<Tile>& getTiles() const { return tiles; }
    std::vector<std::vector<char>>& getGrid() { return grid; }
    void setTileLetter(char letter) { tileLetter = letter; }
    char getTileLetter() const { return tileLetter; }
    
    void addTile(const int& num_tile);
    void printGrid() const;
    bool placeTileOnGrid(const std::vector<std::vector<char>>& tile, int x, int y, char refChar);
    int findLargestSquare() const;
    void removeTile(int tileIndex);
    void addNewTile();

    int getExchangeCoupon() const;
    void useExchangeCoupon();

    int getExchangeTile() const;
    void addExchangeTile();
    void useExchangeTile();
};

#endif // PLAYER_HPP
