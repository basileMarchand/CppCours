
Un tour d'horizon des templates     {#templateSection}
===============================

[TOC]

# Templates et fonctions 

## Le principe de base 

Nous l'avons déjà vu dans la partie sur les fonctions, mais un petit rappel ne fait pas de mal, le principe des `template` en C++ est d'écrire un patron de code qui sera utilisé par le compilateur lorsqu'il en aura besoin. L'idée caché derrière les templates est de minimiser le code à écrire pour le développeur. Par exemple, si nous voulons écrire une fonction qui affiche le contenu d'un `std::vector` plutôt que de faire N versions de la même fonction nous pouvons utiliser les templates de la manière suivante : 

\snippet ./src/example_function.cpp print

Et ensuite nous pouvons utiliser cette fonction pour n'importe quel `std::vector<T>`. 
\snippet ./src/example_function.cpp usage_cpp

Avec du c++ moderne on peut se passer de spécifier le type de `T` à l'appel de la fonction. Le compilateur est malin maintenant il le déduit du contexte : 

\snippet ./src/example_function.cpp usage_cpp1X

## Spécialisation de template 

Maintenant imaginons que nous voulions afficher en plus du contenu du `std::vector<T>` un message spécifiant de quel type est `T`. Pour cela nous allons définir une fonction `myType` templatée par `T` qui va renvoyer une chaine de caractère définissant le type de `T`. Il va donc nous falloir faire des versions spécifiques, une pour chaque type. C'est ce qu'on va appeler de la spécialisation de templates. Le principe est de définir la version générique par exemple ici : 

\snippet ./src/example_function.cpp type_info 

Et ensuite on spécialise la fonction template en spécifiant explicitement son comportement pour certaines valeur du paramètre template `T` par exemple : 

\snippet ./src/example_function.cpp type_info_spec

Nous pouvons alors définir la fonction qui affiche le contenu d'un `std::vector<T>` de la manière suivante : 

\snippet ./src/example_function.cpp printVecType

\snippet ./src/example_function.cpp usage_type 

```
std::vector<int>: 1, 2, 3, 4, 5
```

\snippet ./src/example_function.cpp myType_cpp17

## Les templates de template

Il y a quand même une limite à la version de `printVector` que l'on vient de faire. Considérons par exemple le cas où l'on a un `std::vector<std::vector<int>>` : 

\snippet ./src/example_function.cpp usage_vecvec

Dans ce cas la fonction template que l'on a faite ne va pas bien fonctionner.... Cependant il est possible de faire une spécialisation un peu particulière : 

\snippet ./src/example_function.cpp print_vecvec



# Template de classes 

## Méthodes template

Nous venons de le voir nous pouvons templater des fonctions. Bon et bien par extension il paraît plutôt évident que l'on peut templater des méthodes de classe, car fondamentalement il s'agit de fonctions. Et bien oui je vous confirme on peut faire ça ! 

Par exemple : 

\snippet ./src/method_template.cpp printer 

\snippet ./src/method_template.cpp printer_usage

```
[Printer] - 2.34
[Printer] - coucou
```

\snippet ./src/method_template.cpp data 

\snippet ./src/method_template.cpp data_usage

```
1.27
42
```

## Classe template 

### Généralités

\snippet ./src/class_template.cpp number

\snippet ./src/class_template.cpp number_usage



### Une classe Matrice

# Allons plus loin 

# Quelques utilisations avancées des templates 

## CRTP 

### Idée générale

### Singleton 

\snippet ./src/crtp_singleton.cpp singleton

\snippet ./src/crtp_singleton.cpp class

\snippet ./src/crtp_singleton.cpp usage


### Composition 

\snippet ./src/crtp_composition.cpp logger

\snippet ./src/crtp_composition.cpp format

\snippet ./src/crtp_composition.cpp usage

### Polymorphisme statique 


\snippet ./src/static_polymorphisme.cpp base

\snippet ./src/static_polymorphisme.cpp derived

\snippet ./src/static_polymorphisme.cpp usage


## Variadic templates 