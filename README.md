```markdown
# My_pong

## Description
"My_pong" est un jeu Pong développé en utilisant la bibliothèque SDL2. Ce projet vise à recréer l'expérience classique du jeu Pong avec une interface simple et intuitive.

## Prérequis
Avant de compiler le projet, assurez-vous d'avoir installé les éléments suivants :

- **CMake** (version 3.10 ou supérieure)
- **Make** (pour les systèmes basés sur Unix)
- **SDL2** (Simple DirectMedia Layer 2)

## Compilation

### Avec CMake

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/Jaures229/My_pong.git
   cd My_pong
   ```

2. Créez un répertoire de construction :
   ```bash
   mkdir build
   cd build
   ```

3. Exécutez CMake pour configurer le projet :
   ```bash
   cmake ..
   ```

4. Compilez le projet :
   ```bash
   make
   ```

### Avec Makefile

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/Jaures229/My_pong.git
   cd My_pong
   ```

2. Compilez le projet directement avec Make :
   ```bash
   make
   ```

## Lancer le jeu
Après la compilation, vous pouvez lancer le jeu avec la commande suivante :
```bash
./My_pong
```

## Commandes de jeu
- **Joueur 1** (paddle à gauche) : Utilisez les touches **W** (haut) et **S** (bas) pour déplacer votre paddle.
- **Joueur 2** (paddle à droite) : Utilisez les flèches directionnelles **Haut** et **Bas** pour déplacer votre paddle.
- Le jeu commence automatiquement après le lancement.
