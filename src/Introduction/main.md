
Introduction    {#introSection}
============


[TOC]

# Un historique rapide du C++ 


# Le C++ versus le reste du monde 

## Langage de haut niveau vs bas niveau 

## Langage compilé vs interprété


# Le setup de base 

Pour faire du C++ sur vos ordinateurs perso il vous faut deux choses : 

1. Un compilateur 
2. Un éditeur de code 

## Installation d'un compilateur 

```bash 
sudo apt-get install build-essentials gcc 
```

## Un éditeur de texte qui va bien 

Nous vous laissons libre d'utiliser votre éditeur préféré. Pour celles et ceux qui n'auraient pas de croyance à ce sujet nous vous recommandons fortement d'utiliser Visual Studio Code. 

## Quelques outils annexes 

Dans la suite du cours nous serons amené à utiliser quelques outils annexes au C++ qui ne sont pas indispensables mais facilite la vie. Il s'agit de : 

* CMake : un système de build qui permet d'automatiser les compilations 
* gdb : un debuggeur 
* valgrind : 

# Le point d'entré d'un programme C++

## La fonction `main` 

**Tout** programme écrit en C++ a un point d'entrée. C'est à dire une section de code qui est la première à être éxécutée. 



\snippet ./src/pointEntree.cpp main


Pour compiler notre programme nous allons utiliser le compilateur. La compilation se fait via le terminal de la manière suivante : 

```bash 
$ g++ pointEntree.cpp -o pointEntree.out 
```

Cela nous génère alors une programme binaire executable, pointEntree.out, que l'on peut lancer de la manière suivante : 

```bash 
$ ./pointEntree.out 
```

Nous verrons pas la suite que cette fonction main peut prendre des arguments d'entrée. Ces arguments seront en fait les arguments passé au programme au lancement de ce dernier. 



