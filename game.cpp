#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printMap(int playerX, int playerY, int goblinX, int goblinY, int monsterAlive, int potionX, int potionY, int hasPotion, int keyX, int keyY) {
    printf("\nDungeon Map:\n");
    for (int y = 2; y >= 0; y--) {  // top row first
        for (int x = 0; x < 3; x++) {
            if (playerX == x && playerY == y && keyX == x && keyY == y) {
                printf("[P,K] ");
            } else if (playerX == x && playerY == y) {
                printf("[P] ");
            } else if (monsterAlive && goblinX == x && goblinY == y) {
                printf("[G] ");
            } else if (!hasPotion && potionX == x && potionY == y) {
                printf("[H] ");
            } else if (keyX == x && keyY == y) {
                printf("[K] ");
            } else {
                printf("[ . ] ");
            }
        }
        printf("\n");
    }
}

int main() {
    char command[20];
    int hasKey = 0, hasPotion = 0;
    int health = 10, monsterHealth = 8;
    int playerX = 0, playerY = 0; // player starting at (0,0)
    int goblinX, goblinY, potionX, potionY;
    int monsterAlive = 1;
    int keyX = 2, keyY = 2; // fixed key room

    srand(time(0)); // random seed

    // Randomly place goblin and potion (excluding starting position and key room)
    do { goblinX = rand() % 3; goblinY = rand() % 3; } while ((goblinX == 0 && goblinY == 0) || (goblinX == keyX && goblinY == keyY));
    do { potionX = rand() % 3; potionY = rand() % 3; } while ((potionX == 0 && potionY == 0) || (potionX == goblinX && potionY == goblinY) || (potionX == keyX && potionY == keyY));

    printf("??? Welcome to the Dungeon Adventure! ???\n");
    printf("You find yourself in a mysterious dungeon. Your goal: escape!\n");

    while (1) {
        printMap(playerX, playerY, goblinX, goblinY, monsterAlive, potionX, potionY, hasPotion, keyX, keyY);

        printf("\nWhat do you want to do? (north/east/south/west/look/inventory/quit): ");
        scanf("%s", command);

        // Move player
        if (strcmp(command, "north") == 0) {
            if (playerY < 2) playerY++;
            else { printf("A wall blocks your way.\n"); continue; }
        } else if (strcmp(command, "south") == 0) {
            if (playerY > 0) playerY--;
            else { printf("A wall blocks your way.\n"); continue; }
        } else if (strcmp(command, "east") == 0) {
            if (playerX < 2) playerX++;
            else { printf("A wall blocks your way.\n"); continue; }
        } else if (strcmp(command, "west") == 0) {
            if (playerX > 0) playerX--;
            else { printf("A wall blocks your way.\n"); continue; }
        } else if (strcmp(command, "look") == 0) {
            printf("You are in a dungeon room.\n");
            if (playerX == goblinX && playerY == goblinY && monsterAlive) printf("- A goblin is here! ??\n");
            if (playerX == potionX && playerY == potionY && !hasPotion) printf("- A healing potion is here! ??\n");
            if (playerX == keyX && playerY == keyY && !hasKey) printf("- A golden key is here! ???\n");
            if (hasKey) printf("- You have a golden key.\n");
            continue;
        } else if (strcmp(command, "inventory") == 0) {
            printf("Inventory:\n");
            if (hasKey) printf("- Golden Key\n");
            if (hasPotion) printf("- Healing Potion\n");
            if (!hasKey && !hasPotion) printf("- Empty\n");
            continue;
        } else if (strcmp(command, "quit") == 0) {
            printf("You give up and remain trapped in the dungeon... ??\n");
            break;
        } else {
            printf("I don't understand that command.\n");
            continue;
        }

        // Goblin encounter
        if (playerX == goblinX && playerY == goblinY && monsterAlive) {
            printf("A scary goblin blocks your path! ??\n");
            while (monsterAlive && health > 0) {
                printf("Do you want to fight or run? (fight/run): ");
                scanf("%s", command);
                if (strcmp(command, "fight") == 0) {
                    int playerAttack = rand() % 4 + 1;
                    int monsterAttack = rand() % 3 + 1;
                    monsterHealth -= playerAttack;
                    health -= monsterAttack;
                    printf("You deal %d damage, goblin deals %d damage. Your health: %d, Goblin health: %d\n", playerAttack, monsterAttack, health, monsterHealth);
                    if (monsterHealth <= 0) {
                        printf("You defeated the goblin! ??\n");
                        monsterAlive = 0;
                        break;
                    } else if (health <= 0) {
                        printf("The goblin defeated you... ?? Game over.\n");
                        return 0;
                    }
                } else if (strcmp(command, "run") == 0) {
                    printf("You run back to the previous room.\n");
                    if (playerY > 0) playerY--; // move back south
                    break;
                } else {
                    printf("Invalid command.\n");
                }
            }
        }

        // Potion pickup
        if (playerX == potionX && playerY == potionY && !hasPotion) {
            printf("You see a healing potion on the floor. You take it. ??\n");
            hasPotion = 1;
        }

        // Use potion if available
        if (hasPotion && health < 10) {
            printf("Do you want to use your healing potion? (yes/no): ");
            scanf("%s", command);
            if (strcmp(command, "yes") == 0) {
                health += 5;
                if (health > 10) health = 10;
                printf("You feel rejuvenated! Health is now %d.\n", health);
                hasPotion = 0;
            }
        }

        // Check escape (key room at (2,2))
        if (playerX == keyX && playerY == keyY) {
            if (!hasKey) {
                printf("You find a golden key here! ???\n");
                hasKey = 1;
            } else {
                printf("You use the key to unlock the northern door and escape the dungeon! ??\n");
                break;
            }
        }
    }

    printf("Thanks for playing Dungeon Adventure! ??\n");
    return 0;
}
