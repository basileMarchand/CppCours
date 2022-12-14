# Travaux pratiques {#TPSection}

On vous conseille dans un premier temps de ne lire que la section **Objectif de l'exercice** et de réfléchir soigneusement à la réalisation du code **chacun de votre côté**. N'adoptez surtout pas _pour aller plus vite_ les idées des autres, vous devez imaginer par vous même les choses à faire, vous pouvez vous tromper et poser des questions à vos enseignants, et recommencer... mais si vous codez la solution de votre voisin, vous vous mettriez dans un simple rôle d'_exécutant_ qui vous empêchera de progressez.

Ceux qui sont vraiment bloqués, peuvent ensuite lire la section **Quelques conseils pour bien débuter**.

Vous pouvez tous lire la section **Quelques remarques**.

[TOC]

# Exercice manipulation des types et gestion des inputs utilisateur

## Exercice 1 : basique

Écrire un programme qui affiche le message suivant à l'execution

```
$ ./a.out
Hello World from 60 boulmich
```

## Exercice 2 : input

Écrire un programme qui demande à l'utilisateur de saisir deux dimensions longueur et largeur et affiche en retour l'air et le périmètre du rectangle.

Par exemple :

```
$ ./a.out
Saisir la longueur (m) : 10.05
Saisir la largeur (m): 3.42
La surface est 34.371 m2
Le périmètre est 26.94 m
```

## Exercice 3

Écrire un programme qui demande à l'utilisateur de saisir 5 entiers et qui en calcul la moyenne. Vous ne devez définir que deux variables `int` dans votre programme.

## Exercice 4

Ecrire un programme qui demande à l'utilisateur de renseigner le prix HT d'un produit, le nombre de produit acheté et la TVA applicable et qui affiche en retour le montant TTC total à payer.

**Variante**: Refaire le même programme mais où les trois valeurs d'entrée sont fournies à la ligne de commande au lancement du programme.

# Exercices structures de contrôle

## Exercice 1

Écrire un programme qui demande à l'utilisateur de saisir `N` entiers, `N` étant fourni par l'utilisateur et qui affiche la somme de ces `N` entiers.

## Exercice 2

Écrire un programme qui demande à l'utilisateur de saisir `N` entiers positifs, `N` étant fourni par l'utilisateur et qui affiche la somme de ces `N` entiers. Si l'utilisateur fourni un nombre négatif alors le programme doit afficher un message d'erreur et offrir la possibilité à l'utilisateur de saisir une nouvelle valeur.

## Exercice 3

Écrire un programme qui demande à l'utilisateur de saisir un entier N et qui affiche la figure suivante.

```
N=1
*
N=2
**
 *
N=3
***
 **
  *
```

## Exercice 4 : suite hongroise

On considère la suite hongroise : `u(0)=a` (a entier)
si `u(n)` pair alors `u(n+1)=u(n)/2` sinon `u(n+1)=3*u(n)+1`

Pour toutes les valeurs `a`, il existe un entier `N` tel que `u(N)=1`.

**Partie 1** Écrire un programme qui demande à l'utilisateur de taper `a` et qui affiche toutes les valeurs de `u(n)` de n=1 à n=N.

**Partie 2** Écrire un programme qui demande à l'utilisateur de taper un entier M puis qui cherche la valeur de a comprise entre 2 et M qui maximise la valeur de N. On appelle A cette valeur. La programme doit afficher la valeur A et la valeur N correspondante.

# TP sur la calculatrice en notation polonaise inversée {#TPpolonaiseInversee}

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

## (attention spoiler) Quelques conseils pour débuter

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
   - il rencontre `3` (il ne sait rien calculer, il doit le garder)
   - il rencontre `5` (il ne sait rien calculer, il doit le garder)
   - il rencontre `x` (il sait que c'est la multiplication binaire dont il possède déjà les deux opérandes; il sait aussi qu'il n'aura plus besoin des deux opérandes mais du résultat du calcul ici `15`)
   - il n'y a plus rien après, l'expression est terminée, le résultat doit être affiché `15`

# Spirale d'Archimède

L'objectif de cet exercice est de développer le code permettant d'afficher la [spirale d'archimède](https://en.wikipedia.org/wiki/Archimedean_spiral). La sortie doit se faire sous la forme d'une image au format [PPM](https://fr.wikipedia.org/wiki/Portable_pixmap#PPM)

# Ensemble de Mandelbrot

L'objectif est de développer le code permettant de tracer la célèbre image de l'ensemble de [mandelbrot](https://fr.wikipedia.org/wiki/Ensemble_de_Mandelbrot)

# Liste chaînée {#TPList}

## Objectif de l'exercice

L'objectif de cet exercice est que vous fassiez votre propre implémentation de la liste chaînée. Les fonctionnalitées attendues sont les suivantes :

- Insertion à la fin
- Insertion à un indice quelconque
- Récupérer la taille de la liste
- Supprimer un élément à un indice quelconque
- Afficher le contenu de la liste

# Liste doublement chaînée {#TPList2}

## Objectif de l'exercice

L'objectif de cet exercice est que vous fassiez votre propre implémentation de la liste doublement chaînée. Les fonctionnalitées attendues sont les suivantes :

- Insertion à la fin
- Insertion à un indice quelconque
- Récupérer la taille de la liste
- Supprimer un élément à un indice quelconque
- Afficher le contenu de la liste

# Evaluateur expression

## Objectif de l'exercice

L'objectif de cette exercice est de mettre en place un système d'évaluation d'expression mathématique. Par exemple le code attendu pour l'évaluation de l'expression y\*(10+x) est le suivant :

```
int main(){

   std::unique_ptr<Node> left = std::make_unique<ConstantNode>(10.);
   std::unique_ptr<Node> right = std::make_unique<VarNode>("x");
   std::unique_ptr<Node> toto =  std::make_unique<VarNode>("y");

   std::unique_ptr<Node> tmp =  std::make_unique<BinaryNode>("+", left, right, ope_add);
   std::unique_ptr<Node> root=  std::make_unique<BinaryNode>("*", toto, tmp, [](const double&a, const double&b ){return a*b;});

   root->print();

   std::map<std::string, double> vars = {{"x", 10.}, {"y", 10.}};

   std::cout << "Value of toy example : " << root->eval( vars ) << std::endl;

   return EXIT_SUCCESS;
}
```

Pour cela il vous faut définir une hiérarchie de classes avec les bonnes interfaces. Enjoy ;)

# Calcul matriciel et multi-threading

Dans cet exercice on vous propose de mettre en place une fonction pour réaliser un produit matrice vecteur. On vous fourni le squelette de code suivant :

\snippet ./src/thread_matvecmul_skeleton.cpp all

L'objectif est de faire la version parallèle en utilisant des `std::thread` ou de l'OpenMP.
