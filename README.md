<div align="center">

# 🔄 Push_swap — 42 School

*Because Swap_push isn't as natural*

[![Norminette](https://img.shields.io/badge/Norminette-Passing-brightgreen?style=flat-square)](https://github.com/42School/norminette)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Score](https://img.shields.io/badge/Score-100%2F100-success?style=flat-square)](https://github.com/Mnzoom/push_swap)

</div>

---

## 📋 À propos du projet

**push_swap** est un projet algorithmique de l'école 42 qui consiste à trier une liste d'entiers sur une pile (`a`) en utilisant un ensemble d'opérations limité, avec un nombre minimal de mouvements, et en s'aidant d'une seconde pile (`b`).

Le défi majeur réside dans la conception et l'optimisation d'un algorithme capable de trier des jeux de données de différentes tailles (de 3 à 500 nombres) en respectant des seuils stricts de complexité.

---

## ⚙️ Opérations autorisées

Pour manipuler les piles, les instructions suivantes sont disponibles :

* **`sa`** (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
* **`sb`** (swap b) : Intervertit les 2 premiers éléments au sommet de la pile b.
* **`ss`** : `sa` et `sb` en même temps.
* **`pa`** (push a) : Prend le premier élément au sommet de b et le met sur a.
* **`pb`** (push b) : Prend le premier élément au sommet de a et le met sur b.
* **`ra`** (rotate a) : Décale d'une position vers le haut tous les éléments de la pile a (le premier devient le dernier).
* **`rb`** (rotate b) : Décale d'une position vers le haut tous les éléments de la pile b.
* **`rr`** : `ra` et `rb` en même temps.
* **`rra`** (reverse rotate a) : Décale d'une position vers le bas tous les éléments de la pile a (le dernier devient le premier).
* **`rrb`** (reverse rotate b) : Décale d'une position vers le bas tous les éléments de la pile b.
* **`rrr`** : `rra` et `rrb` en même temps.

---

## 🚀 Installation & Utilisation

### Prérequis
* Un compilateur C (comme `gcc` ou `clang`)
* `Make`

### Compilation
Clone le dépôt et compile le projet à l'aide du `Makefile` :

bash
git clone [https://github.com/Mnzoom/push_swap.git](https://github.com/Mnzoom/push_swap.git)
cd push_swap
make

### Execution 
./push_swap 4 67 3 87 23
Tu peux également vérifier le nombre d'opérations ou tester le tri avec un checker (fourni par 42 ou personnalisé)
ARG="4 67 3 87 23"; ./push_swap $ARG \vert{} ./checker_linux$ARG

🛠️ Approche et Algorithme
Petites listes (3 à 5 nombres) : Traitement par des cas spécifiques et logiques de tri direct pour un coût minimal en opérations.
Grandes listes (100 à 500 nombres) : Utilisation d'un algorithme basé sur le calcul de coûts (Turk algorithm ou indexation par chunks) pour évaluer la position optimale de chaque élément de la pile b vers la pile a.
Gestion des erreurs : Validation rigoureuse des arguments d'entrée (non-entiers, dépassements de limites INT_MIN / INT_MAX, doublons).

👨‍💻 Auteur
Clément N'GOÏE — 42
GitHub : @Mnzoom
