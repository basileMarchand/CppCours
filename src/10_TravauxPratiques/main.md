
Travaux pratiques    {#TPSection}
=================

On vous conseille dans un premier temps de ne lire que la section **Objectif de l'exercice** et de réfléchir soigneusement à la réalisation du code **chacun de votre côté**. N'adoptez surtout pas "*pour aller plus vite*" les idées des autres, vous devez imaginer par vous même les choses à faire, vous pouvez vous tromper et poser des questions à vos enseignants, et recommencer... mais si vous codez la solution de votre voisin, vous vous mettriez dans un simple rôle d'*exécutant* qui vous empêchera de progressez.

Ceux qui sont vraiment bloqués, peuvent ensuite lire la section  **Quelques conseils pour bien débuter**.

Vous pouvez tous lire la section **Quelques remarques**.

[TOC]

# TP sur la calculatrice en notation polonaise inversée 

## Objectif de l'exercice

Écrire un programme `C++` qui évalue une expression arithmétique fournie en notation polonaise inversée en argument à votre programme (i.e. sur la ligne de commande le programme), et affiche le résultat sur la sortie standard.

En notation polonaise inversée (**R**everse **P**olish **N**otation) les opérateurs suivent leurs opérandes et il n'est donc pas nécessaire de parenthéser les sous-expressions. Par exemple, `3+4*5` devient `3 4 5 x +` en polonaise inversée et `2*5+4/2` devient `2 5 x 4 2 / +`

Supposons que votre exécutable s'appelle `rpn_cpp`.

La première expression sera évaluée comme cela: 
```bash 
$ ./rpn_cpp 3 4 5 x +
23
```

La seconde comme cela:

```bash
$ ./rpn_cpp 2 5 x 4 2 / +
12
```

## Quelques remarques

1. séparez bien les termes de l'expression sur la ligne de commande par des espaces  
 **NON** `./rpn_cpp 3 5+`  
 **OUI** `./rpn_cpp 3 5 +`

 1. Attention à bien utiliser le symbole `x` pour la multiplication et pas `*` (parce que `*` est un caractère spécial quand il est sur la ligne de commande)

1. Utilisez `!` pour le moins unaire et pas `-`  
ainsi `2*-2` sera `2 2 ! *`

1. Comme vous ne savez pas encore gérer les exceptions, dans un premier temps vous pouvez considérer que les expressions (données en argument au programme) sont bien formées. Mais nous vous invitons à réfléchir et à repérer, dans votre code, les potentiels problèmes.

## *attention spoiler* Quelques conseils pour  débuter

1. Ne programmez pas tout d'un coup mais petit à petit en veillant à ce que votre code compile à chaque étape.  
Par exemple, une première version, peut être un exécutable qui prend les arguments sur la ligne de commande et les affiche.
```bash
./rpn_cpp 3 5 x
3  
5
x
```
2. Ensuite décomposez le traitement d'une expression:  
Que se passe-t-il quand votre programme va rencontrer l'entrée `3 5 x` ?  
   * il rencontre `3` (il ne sait rien calculer, il doit le garder)
   * il rencontre `5` (il ne sait rien calculer, il doit le garder)
   * il rencontre `x` (il sait que c'est la multiplication binaire dont il possède déjà les deux opérandes; il sait aussi qu'il n'aura plus besoin des deux opérandes mais du résultat du calcul ici `15`)
   * il n'y a plus rien après, l'expression est terminée, le résultat doit être affiché `15`

