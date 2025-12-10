#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Entity {
    int x, y;
    int hp;
    bool alive;
};

struct Item {
    int x, y;
    bool taken;
};

const int SIZE = 15; // Dungeon size

// Check if a position is adjacent (1 tile away)
bool isAdjacent(int px, int py, int x, int y) {
    return abs(px - x) <= 1 && abs(py - y) <= 1;
}

// Check if a tile is occupied during initialization
bool isOccupied(int x, int y, const vector<Entity>& enemies, const vector<Item>& potions, int playerX, int playerY, int keyX, int keyY) {
    if (x == playerX && y == playerY) return true;
    if (x == keyX && y == keyY) return true;
    for (auto& e : enemies) if (e.x == x && e.y == y) return true;
    for (auto& p : potions) if (p.x == x && p.y == y) return true;
    return false;
}

void printMap(int playerX, int playerY,
              const vector<Entity>& enemies,
              const vector<Item>& potions,
              int keyX, int keyY, bool hasKey)
{
    cout << "\n============== DUNGEON MAP ==============\n";
    for (int y = SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < SIZE; x++) {

            bool printed = false;

            if (playerX == x && playerY == y) {
                cout << "[ P ]";
                printed = true;
            }

            for (auto& e : enemies) {
                if (!printed && e.alive && isAdjacent(playerX, playerY, e.x, e.y)) {
                    cout << "[ E ]";
                    printed = true;
                }
            }

            for (auto& p : potions) {
                if (!printed && !p.taken && isAdjacent(playerX, playerY, p.x, p.y)) {
                    cout << "[ H ]";
                    printed = true;
                }
            }

            if (!printed && keyX == x && keyY == y && !hasKey) {
                cout << "[ K ]";
                printed = true;
            }

            if (!printed)
                cout << "[ . ]";
        }
        cout << "\n";
    }
    cout << "==========================================\n";
}

int main()
{
    srand(time(0));

    // Player stats
    int playerX = 0, playerY = 0;
    int hp = 100;
    int attackMin = 10, attackMax = 20;
    bool hasKey = false;

    // Key & Exit positions
    int keyX = SIZE - 1, keyY = SIZE - 1;
    int exitX = 0, exitY = SIZE - 1;

    // Create enemies
    vector<Entity> enemies;
    for (int i = 0; i < 10; i++) {
        Entity e;
        do {
            e.x = rand() % SIZE;
            e.y = rand() % SIZE;
        } while (isOccupied(e.x, e.y, enemies, {}, playerX, playerY, keyX, keyY));
        e.hp = 20 + rand() % 11; // 20–30 HP
        e.alive = true;
        enemies.push_back(e);
    }

    // Create potions (more than enemies)
    vector<Item> potions;
    for (int i = 0; i < 15; i++) {
        Item p;
        do {
            p.x = rand() % SIZE;
            p.y = rand() % SIZE;
        } while (isOccupied(p.x, p.y, enemies, potions, playerX, playerY, keyX, keyY));
        p.taken = false;
        potions.push_back(p);
    }

    cout << "WELCOME TO THE EXPANDED DUNGEON ADVENTURE!\n";
    cout << "15x15 Dungeon. Defeat enemies, find potions, retrieve the key after defeating all enemies, escape.\n";

    string cmd;

    while (true) {

        printMap(playerX, playerY, enemies, potions, keyX, keyY, hasKey);

        // Report remaining enemies and potions
        int remainingEnemies = 0, remainingPotions = 0;
        for (auto& e : enemies) if (e.alive) remainingEnemies++;
        for (auto& p : potions) if (!p.taken) remainingPotions++;
        cout << "Remaining Enemies: " << remainingEnemies << " | Remaining Potions: " << remainingPotions << "\n";
        cout << "HP: " << hp << "\n";

        cout << "Command (w/a/s/d, look, inv, use, quit): ";
        cin >> cmd;

        // Movement
        if (cmd == "w" && playerY < SIZE - 1) playerY++;
        else if (cmd == "s" && playerY > 0) playerY--;
        else if (cmd == "d" && playerX < SIZE - 1) playerX++;
        else if (cmd == "a" && playerX > 0) playerX--;
        else if (cmd == "look") {
            cout << "You look around...\n";
            continue;
        }
        else if (cmd == "quit") {
            cout << "You gave up.\n";
            break;
        }
        else if (cmd == "inv") {
            cout << "Inventory:\n";
            cout << "- Key: " << (hasKey ? "Yes" : "No") << "\n";
            int count = 0;
            for (auto& p : potions) if (p.taken) count++;
            cout << "- Potions: " << count << "\n";
            continue;
        }
        else if (cmd == "use") {
            bool used = false;
            for (auto& p : potions) {
                if (p.taken) {
                    hp += 25;
                    if (hp > 100) hp = 100;
                    p.taken = false;
                    cout << "You use a potion. HP: " << hp << "\n";
                    used = true;
                    break;
                }
            }
            if (!used) cout << "You have no potions.\n";
            continue;
        }
        else if (cmd != "w" && cmd != "a" && cmd != "s" && cmd != "d") {
            cout << "Unknown command.\n";
            continue;
        }

        // Enemy encounter
        for (auto& e : enemies) {
            if (e.alive && e.x == playerX && e.y == playerY) {
                cout << "An enemy attacks you!\n";

                while (e.alive && hp > 0) {
                    cout << "(f)ight or (r)un? ";
                    cin >> cmd;

                    if (cmd == "f") {
                        int playerAttack = attackMin + rand() % (attackMax - attackMin + 1);
                        int enemyAttack = 5 + rand() % 11;

                        e.hp -= playerAttack;
                        hp -= enemyAttack;

                        cout << "You hit for " << playerAttack
                             << ", enemy hits for " << enemyAttack << "\n";
                        cout << "Your HP: " << hp << " | Enemy HP: " << e.hp << "\n";

                        if (e.hp <= 0) {
                            cout << "You defeated the enemy!\n";
                            e.alive = false;
                        }
                        if (hp <= 0) {
                            cout << "You were slain. GAME OVER.\n";
                            return 0;
                        }
                    }
                    else if (cmd == "r") {
                        cout << "You attempt to run!\n";
                        int escapeDir = rand() % 4;
                        if (escapeDir == 0 && playerY < SIZE - 1) playerY++; // up
                        else if (escapeDir == 1 && playerY > 0) playerY--;    // down
                        else if (escapeDir == 2 && playerX < SIZE - 1) playerX++; // right
                        else if (escapeDir == 3 && playerX > 0) playerX--;       // left
                        cout << "You escape to a nearby tile.\n";
                        goto escapeLoop;
                    }
                    else {
                        cout << "Invalid option! You must fight or run.\n";
                    }
                }
            }
        }

        // Potion pickup
        for (auto& p : potions) {
            if (!p.taken && playerX == p.x && playerY == p.y) {
                cout << "You found a potion!\n";
                p.taken = true;
            }
        }

        // Key unlock after all enemies are defeated
        bool allEnemiesDefeated = true;
        for (auto& e : enemies) if (e.alive) allEnemiesDefeated = false;

        if (allEnemiesDefeated && !hasKey && playerX == keyX && playerY == keyY) {
            cout << "You found the key! All enemies are defeated.\n";
            hasKey = true;
        }

        // Exit
        if (hasKey && playerX == exitX && playerY == exitY) {
            cout << "You unlock the exit and escape! CONGRATULATIONS!\n";
            break;
        }

    escapeLoop:
        continue;
    }

    return 0;
}
