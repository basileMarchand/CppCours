
Déclaration de variables et quelques mots sur la mémoire    {#variableSection}
============

Dans cette partie nous allons voir comment définir des variables en `C++` et ce qui se cache derrière. Parce qu'il faut bien l'avouer vous avez l'habitude de définir des variables en Python mais ce dernier vous cache beaucoup de choses, normal c'est son rôle de langage de haut niveau. 

[TOC]

# Une variable c'est quoi ? 

## La mémoire 

Dans votre ordinateur il y a trois choses réellement importantes : 

- le processeur 
- la mémoire vive ou RAM 
- le disque dur 

Tout le reste n'est qu'accessoire, c'est du bonus. Nous pourrions même considérer le disque dur comme accessoire dans certains cas mais c'est un autre débat. 

Quel rapport avec les variables ? Ça dépend de ce qu'est une variable pour vous. Concrètement une variable peut être vue comme une *étiquette* à laquelle on associe une *valeur* mais concrètement cette valeur où est-elle ? Et bien elle est stocké dans la mémoire vive de votre ordinateur. Donc une variable ce n'est rien d'autre qu'un petit bout de la RAM dans lequel vous pouvez ranger des valeurs. 

Un petit bout ok mais petit comment ? Et bien c'est la grande question, le truc que vous cache Python et que le `C++` vous révèle: la taille du morceau de RAM associé à une variable dépend de ce que l'on va vouloir ranger dans cette variable... et oui c'est ça la vraie vie !!

## Notion de type 

Donc la dimension du morceau de RAM affecté à une variable dépend de ce qu'on va mettre dans la variable en question. C'est ce que l'on appelle la notion de typage. En effet si, par exemple, je veux ranger dans une variable `a` un nombre flottant double précision, il me faudra un zone mémoire de 64 bits (8 octets) tandis que si dans une variable `b` je veux stocker un nombre entier une zone mémoire de 32 bits (4 octets) me suffira. 

En Python toute cette tringlerie est cachée car Python est un langage a typage dynamique, c'est à dire la gestion de la mémoire est faites dynamiquement au runtime (lors de l'exécution). Tandis qu'en `C++` tout doit être spécifié à la compilation. L'intérêt est que l'on utilise la mémoire avec beaucoup plus de justesse, cela contribue au fait que `C++` est un langage plus performant.

Donc en `C++` il faudra toujours, au moment de déclarer une variable, spécifier son type. Cela se fait avec la syntaxe suivante 

```
<type> ma_variable;
```

Où `<type>` doit être un type `C++`. 

## Un mot sur le nommage des variables 

Pour information, `C++` impose quelques règles, concernant le nom des variables, qui ne peuvent pas être transgressées: 

- un nom de variable est constitué de lettre, chiffre et du symbole underscore 
- le premier caractère est forcément une lettre
- un nom de variable ne peut comporter aucun espace 

**Remarque :** depuis `C++11` il est possible d'utiliser n'importe quel caractère unicode dans des fichiers sources `C++` pour les noms de variables. 
Par exemple on peut donc choisir des variables avec accents 
\snippet ./src/example_unicode.cpp accent

Ou encore avec des lettres grecs, si l'on est puriste et que l'on veut rester proche de ses équations. 

\snippet ./src/example_unicode.cpp unicode 

Mais, de manière générale, il est plutôt recommandé de rester sur une approche *old-school*, à savoir: tout en anglais, sans accent ni caractère bizarre.


# Type intégraux 

Les premiers types que nous allons voir sont les types numériques, qui permettent donc de définir des nombres. 

## Entiers

Tout d'abord pour définir les entiers on utilise le type `int` pour `integer`.

Les entiers peuvent, en réalité, être de différents types. La liste des types possibles est: `char`, `short` (ou `short int`), `int`, `long` (ou `long int`) et `long long` (ou `long long int`). Tous peuvent être non-signés avec `unsigned` ou signés avec `signed`.

\snippet ./src/example_int.cpp intégraux 

La taille de la mémoire, pour stocker ces différents types intégraux, diffère suivant les ordinateurs et les compilateurs. La norme du langage nous dit simplement que, dans la liste `char`, `short`, `int`, `long` et `long long` chaque type fournit au moins autant de stockage (de bits) que les types qui le précèdent dans la liste.

## Flottants 

### Représentation des nombres flottants 

### Float ou double 


## Le type un truc pas si anecdotique que ça 

division int/int, int/float 


# Les booléens 


# Les chaines de caractère 

## Dans le monde d'avant 

## En `C++` "moderne" 


# Astuce 



```
using Real = double;
```


# Définir des variables 

## Ne pas confondre déclaration et affectation 


Attention, un point important en `C++` est que la déclaration d'une variable peut être indépendante de l'affectation d'une valeur à cette dernière. Cela peut sembler bizarre quand on vient du Python mais en fait c'est logique. Par exemple, si je veux définir une variable `value` qui devra contenir un entier. Je ne sais pas nécessairement au moment où je définis cette variable la valeur qu'elle va contenir. 

La déclaration se fera donc de la manière suivante : 

```
int value;
```

Et ensuite dans un second temps je peux affecter une valeur à cette variable, par exemple `10`. 

```
value = 10; 
```

Néanmoins si au moment de la déclaration, on veut en même temps affecter une valeur à notre variable, c'est possible de trois manières différentes : 

```
int value = 10; 
```

ou bien 

```
int value(10);
```

ou enfin la notation, valide uniquement en `C++11`

```
int value {10};
```

Seule la troisième manière vous signalera d'éventuels problèmes d'overflow de la valeur quand la taille mémoire prévue pour le type n'est pas capable de contenir la valeur. 

## La déduction de type via `decltype` ou `auto` 

# Référence vers une variable 

## Une référence c'est quoi 

## Intérêts et dangers 

