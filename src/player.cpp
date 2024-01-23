#include <iostream>
#include <set>
#include "Player.hpp"

void Player::addTile(const int& num_tile) {
    tiles.push_back(Tile(num_tile));
}

void Player::printGrid() const {
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}

bool Player::placeTileOnGrid(const std::vector<std::vector<char>>& tile, int startX, int startY, char refChar) {
    int refX = -1, refY = -1;
    for (int i = 0; i < tile.size(); ++i) {
        for (int j = 0; j < tile[i].size(); ++j) {
            if (tile[i][j] == tolower(refChar)) {
                refX = i;
                refY = j;
                break;
            }
        }
        if (refX != -1) break;
    }

    if (refX == -1 || refY == -1) return false;

    startX -= refX;
    startY -= refY;

    for (int i = 0; i < tile.size(); ++i) {
        for (int j = 0; j < tile[i].size(); ++j) {
            int x = startX + i;
            int y = startY + j;
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || (tile[i][j] != '.' && grid[x][y] != '.')) {
                return false;
            }
        }
    }

    for (int i = 0; i < tile.size(); ++i) {
        for (int j = 0; j < tile[i].size(); ++j) {
            int x = startX + i;
            int y = startY + j;
            if (tile[i][j] != '.') {
                grid[x][y] = tile[i][j];
            }
        }
    }

    return true;
}

int Player::findLargestSquare() const {
    std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), 0));
    int maxSize = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] != '.') {
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

void Player::removeTile(int tileIndex) {
    if (tileIndex >= 0 && tileIndex < tiles.size()) {
        tiles.erase(tiles.begin() + tileIndex);
    }
}

void Player::addNewTile() {
    int randomNumber;
    std::set<int> existingTiles;

    for (const auto& tile : tiles) {
        existingTiles.insert(tile.getType());
    }

    do {
        randomNumber = rand() % 96 + 1;
    } while (existingTiles.find(randomNumber) != existingTiles.end());

    tiles.push_back(Tile(randomNumber));
}

int Player::getExchangeCoupon() const {
    return exchangeCoupon;
}

void Player::useExchangeCoupon() {
    if (exchangeCoupon > 0) {
        --exchangeCoupon;
    }
}

int Player::getExchangeTile() const {
    return exchangeTile;
}

void Player::useExchangeTile() {
    if (exchangeTile > 0) {
        --exchangeTile;
    }
}

void Player::addExchangeTile() {
    ++exchangeTile;
}