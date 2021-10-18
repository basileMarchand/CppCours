
Déclaration de variables et quelques mots sur la mémoire    {#variableSection}
============

Dans cette partie nous allons voir comment dans le langage c++ nous pouvons définir des variables et ce qui se cache derrière. Parce qu'il faut bien l'avouer vous avez l'habitude de définir des variables quand vous faites du Python mais ce dernier vous cache beaucoup de choses, normal c'est son rôle de lanage de haut niveau. 

[TOC]

# Une variable c'est quoi ? 

## La mémoire 

Dans votre ordinateur il y a trois choses réellement importantes : 

- Le processeur 
- Le disque dur 
- La mémoire vive ou RAM 

Tout le reste n'est qu'accessoire, c'est du bonus. Nous pourrions même considérer le disque dur comme accessoire dans certains cas mais c'est un autre débat. 

Quel rapport avec les variables ? Ca dépend de ce qu'est une variable pour vous. Concrètement une variable on peut voir ça comme une étiquette à laquelle on associe une valeur. Mais concrètement cette valeur elle est où ? Et bien elle est stocké dans la mémoire vive de votre ordinateur. Donc une variable ce n'est rien d'autre qu'un petit bout de la RAM dans lequel vous pouvez ranger des valeurs. 

Un petit bout ok mais petit comment ? Et bien c'est la grande question, le truc que vous cache Python et que le c++ vous révèle ... La taille du morceau de RAM qui est associé à une variable dépend de ce que l'on va vouloir ranger dans cette variable et oui c'est ça la vraie vie !!

## Notion de type 

Donc la dimension du morceau de RAM affecté à une variable dépend de ce qu'on va mettre dans la variable en question. C'est ce que l'on appelle la notion de typage. En effet si par exemple je veux ranger dans une variable `a` un nombre flottant double précision il me faudra un zone mémoire de 64 bits (8 octets) tandis que si dans une variable `b` je veux stocker un nombre entier une zone mémoire de 32 bits (4 octets) me suffira. 

En Python toute cette tringlerie est cachée car Python est un langage a typage dynamique, c'est à dire la gestion de la mémoire est faites dynamiquement au runtime. Tandis qu'avec C++ tout doit être spécifié à la compilation. L'intérêt est que l'on utilise la mémoire avec beaucoup plus de justesse, cela contribue au fait que C++ est un langage plus performant. 

Donc en c++ il faudra toujours au moment de déclarer une variable spécifier son type. Cela se fait avec la syntaxe suivante 

```
<type> ma_variable;
```

Où `<type>` doit être un type c++. 

## Un mot sur le nommage des variables 

Pour information, c++ impose quelques règles concernant le nom des variables. Les rêgles qui ne peuvent pas être transgréssée : 

- Un nom de variable est constitué de lettre, chiffre et underscore 
- Le premier caracètre est forcément une lettre
- Aucun espace 

**Remarque :** depuis C++11 il est possible d'utiliser n'importe quel caractère unicode dans des fichiers sources c++ pour les noms de variables. 
Par exemple on peut donc faire des variables avec accents 
\snippet ./src/example_unicode.cpp accent

Ou encore écrire des variables avec des lettres grecs, si l'on est puriste et que l'on veut rester proche de ses équations. 

\snippet ./src/example_unicode.cpp unicode 

Mais de manière générale il est plutôt recommandé de rester sur une approche old-school, à savoir tout en anglais, sans accent ni caractère bizarre. 



# Type intégrales 

Les premiers types que nous allons voir sont les types numériques, qui permettent donc de définir des nombres. 

## Entiers

Tout d'abord pour définir les entiers on utilise le type `int` pour integer. Les entiers peuvent en réalité être de différents types : 

-   



## Flottants 

### Représentation des nombres flottants 

### Float ou double 


## Le type un truc pas si anecdotique que ça 

division int/int, int/float 


# Les booléens 


# Les chaines de caractère 

## Dans le monde d'avant 

## En c++ "moderne" 


# Astuce 



```
using Real = double;
```


# Définir des variables 

## Ne pas confondre déclaration et affectation 


Attention, un point important en C++ est que la déclaration d'une variable peut être indépendante de l'affectation d'une valeur à cette dernière. Cela peut sembler bizarre quand on vient du Python mais en fait c'est logique. Par exemple si je veux définir une variable `value` qui devra contenir un entier. Je ne sais pas nécessairement au moment où je défini cette variable la valeur qu'elle va contenir. 

La déclaration se fera donc de la manière suivante : 

```
int value;
```

Et ensuite dans un second temps je peux affecter une valeur à cette variable, par exemple `10`. 

```
value = 10; 
```

Néanmoins si au moment de la déclaration on veut affecter une valeur à notre variable en même c'est possible de trois manières différentes : 

```
int value = 10; 
```

ou bien 

```
int value(10);
```

ou enfin la notation, valide uniquement en c++11 

```
int value {10};
```


## La déduction de type via decltype ou auto 



# Référence vers une variable 

## Une référence c'est quoi 

## Intérêts et dangers 

