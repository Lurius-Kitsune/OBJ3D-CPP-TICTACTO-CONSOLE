#include "Game.h"
// Les classe � cr�e 
// Ship
    // Grid
    // Position
    // Player
    // Game
    // Marker
    // Missile
    // Tile

// feature
// Menu d�roulant d�but du jeu - Game
// D�finition de la grille - Grid
//Etablissement des bateaux sur la grille - Grid
// Systeme de jeu tour par tour - Game
// Menu s�lection joueurs - Game
// 
// Choix de la position du tir - Player qui attaque
// Systeme de marquage - Marker
// System toucher couler - Player qui se fait attaquer
// D�terminer la fin de la partie - Game

// Game -> 2 joueur -> Grille -> Case  -> Position
int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de m�moire

    locale::global(locale("fr-FR")); // UTF8


   Game _myGame = Game(1, "Thomas", "Margeuritte");

   _myGame.LaunchGame();

    return EXIT_SUCCESS;
}
