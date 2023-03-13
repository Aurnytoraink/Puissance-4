# Puissance 4

## Versions

### V1 (Mise en place de la base) ✅

accueil()
2 joueurs

? structure de données (détection de données)

- Affichage dans un terminal
- Saisir un coup
- Détection de victoire

### V2 (Jouer contre l'ordinateur)

2 modes :
- aléatoire ✅
- algorithme minimax avec élagage alphabeta

#### Aléatoire

Il faudrait que la fonction est accès colonne restante (non pleine), afin de réduire le choix et éviter le cas où le même nombre généré plusieurs fois de suite correspond à une colonne pleine

### V3 (GUI)

Utilisation de la bibliothèque graphique SDL 

## TODO

- Retirer tous les accents et caractères spéciaux
- Mettre les variables globales dans le header de `engine.h`
- Créer un fichier `test.c` qui réalise tous les tests
- Rajouter des commentaires et explications
- Utilisation de pseudo pour les joueurs
- Possibilité de rejouer ✅
  - Comptabiliser les victoires
  - Le premier joueur est choisi aléatoirement ensuite c'est le perdant
- Affichage spécial en cas de défaite du joueur contre IA