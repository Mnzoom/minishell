<div align="center">

# 🐚 Minishell — 42 School

*As beautiful as a shell*

[![Norminette](https://img.shields.io/badge/Norminette-Passing-brightgreen?style=flat-square)](https://github.com/42School/norminette)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Repo](https://img.shields.io/badge/GitHub-minishell-informational?style=flat-square)](https://github.com/Mnzoom/minishell)

</div>

---

## 📋 À propos du projet

**minishell** est un projet majeur du cursus 42 dont l'objectif est de recréer son propre shell Unix minimaliste en C, inspiré de Bash. 

Ce projet permet d'approfondir la compréhension de la gestion des processus (`fork`, `execve`), de la manipulation des descripteurs de fichiers (`dup2`, `pipe`), de l'analyse syntaxique (tokenisation et AST/parsing), ainsi que de la gestion des signaux POSIX.

---

## ✨ Fonctionnalités

### 🧠 Prompt & Historique
* Affichage d'un prompt interactif lors de la saisie des commandes.
* Historique des commandes géré via la bibliothèque `readline`.

### 🔀 Redirections & Pipes
* **`<`** : Redirection de l'entrée standard.
* **`>`** : Redirection de la sortie standard (écrasement).
* **`<<`** : Here-document avec délimiteur (`EOF`).
* **`>>`** : Redirection de la sortie standard en mode append (ajout).
* **`|`** : Tuyaux (pipes) pour relier la sortie d'une commande à l'entrée de la suivante.

### 💲 Variables & Quotes
* Expansion des variables d'environnement (`$VAR`, `$?` pour le code de retour de la dernière commande).
* **Simple quotes (`'`)** : Empêchent l'interprétation de tous les métacaractères.
* **Double quotes (`"`)** : Empêchent l'interprétation de la plupart des métacaractères, sauf le `$`.

### ⚡ Builtins intégrés
Le projet réimplémente les commandes internes suivantes :
* `echo` (avec l'option `-n`)
* `cd` (avec un chemin relatif ou absolu)
* `pwd` (sans aucune option)
* `export` (sans aucune option)
* `unset` (sans aucune option)
* `env` (sans aucune option ni argument)
* `exit` (avec gestion des codes de retour)

### 🔔 Signaux
* `Ctrl-C` : Affiche un nouveau prompt sur une nouvelle ligne.
* `Ctrl-D` : Quitte le shell (`EOF`).
* `Ctrl-\` : Ne fait rien en mode interactif (comme Bash).

---

## 🛠️ Architecture & Pipeline

```text
  [ Entrée utilisateur ]
            │
            ▼
      Lexer / Tokenizer      ──► Découpage de la commande en tokens (mots, quotes, pipes, redirections)
            │
            ▼
          Parser             ──► Validation de la syntaxe et création de la structure d'exécution
            │
            ▼
  Expansion des variables    ──► Remplacement des $VAR et résolution de $?
            │
            ▼
         Exécuteur           ──► Gestion des builtins, forks, pipes et redirections
```
🚀 Installation & Utilisation
Prérequis
Un compilateur C (gcc ou clang)
Make
La bibliothèque readline
Compilation
Clone le dépôt et compile le projet :
git clone [https://github.com/Mnzoom/minishell.git](https://github.com/Mnzoom/minishell.git)
cd minishell
make
Lancement 
./minishell
minishell$ export MY_VAR="Hello 42"
minishell$echo$MY_VAR | cat -e
Hello 42$minishell$ ls -la > output.txt
minishell$ cat output.txt | grep "minishell"
👨‍💻 Auteur
Clément N'GOÏE 42
GitHub : @Mnzoom
