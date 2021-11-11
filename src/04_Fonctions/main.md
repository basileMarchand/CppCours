
Fonctions    {#fonctionSection}
=========

[TOC]


# Faire des fonctions 

## L'intéret de cloisonner et organiser son code 

Pour bien organiser son code et avoir quelque chose de maintenable il est impératif d'en cloisonner les fonctionnalités et cela passe, entre autre, par le découpage en fonctions.

On verra plus tard que l'organisation du code passe aussi par la création de nouveaux types de données les fameuses `class` pour faire de la *programmation orientée objet* mais chaque chose en son temps...

Donc une fonction c'est un bloc de code qui ne sera exécuté que quand la fonction sera appelée dans votre code. Pourquoi c'est bien ? Parce que vous définissez une seule fois un code bien spécifique (une *fonctionnalité* précise de votre code) et vous l'utilisez autant de fois que vous voulez: vous évitez ainsi la redondance de codes qui est une source d'erreurs non négligeable. Et si vous n'appelez cette fonction qu'un seule fois ? pas de problème elle vous aura permis de structurer votre code en en séparant les fonctionnalités et cela l'aura ainsi rendu lisible et maintenable.

D'ailleurs la librairie de `C++` vous fournit des tas de fonctions prédéfinies pour simplifier l'écriture de vos codes.

Vous pouvez naturellement aussi créer vos propres fonctions pour des actions non couvertes par la librairie de `C++` (ou par d'autres librairies que vous trouveriez), parce que refaire une fonction existante ce serait vraiment bête... le programmeur est paresseux: il code tout d'abord en réutilisant tout ce qu'il peut et ne fait son propre code que *contraint et forcé*.

Une chose très très importante pour ne pas dire capitale ! La rêgle de base à retenir et **à appliquer** est que l'on ne doit jamais faire de copier-coller dans un code ! Dès que vous êtes tenté de faire un copié-collé dans votre code c'est que vous devez faire une fonction. Pourquoi ? Mais tout simplement parce que le copié-collé c'est la source d'erreur assurée ! Car si vous avez un bout de code que vous copiez 20 fois dans votre projet. Quelques temps plus tard vous vous appercevez qu'il y a un bug, vous le corrigez mais vous devez ensuite retrouver les 20 endroits où vous avez le même bug pour le corriger et il y a de forte chance que vous loupiez une correction ! Et là c'est le drame !


## Définir des fonctions

Pour créer (on dit souvent pour *définir*) une fonction, vous devez préciser: son **type** de retour, son **nom**, ses éventuels **arguments** entre des parenthèses (parce que oui, il est souvent utile de passer des informations à la fonction) et son **corps** dans un bloc (à l'intérieur des fameuses `{}`).

Concrètement cela va ressemble à quelque chose du genre : 

```
type_retour nomFonction( type_arg1, type_arg2, .... ){
    corps de la fonction; 
    return un_truc;
}
```

Par exemple regardons une fonction, certe inutile mais au moins très simple : 

\snippet ./src/function_intro.cpp print_coucou

Son type de retour est vide (`void`) c'est à dire qu'elle ne renvoie pas d'information (c'est une simple procédure), elle ne prend pas d'arguments et son corps se contente d'afficher la chaîne de caractères "coucou" et pas 'coucou' ! on n'est pas `Python`...

Dans le cas où une fonction doit renvoyer une valeur de retour, on utilise le mot clé `return` pour spécifier quelle valeur retourner ! Par exemple considérons la fonction qui va calculer la moyenne des éléments d'un `std::vector<int>`. Cette fonction va donc prendre en entrée (en argument) un `std::vector<double>` et en sortie elle nous retournera une valeur numérique disons par exemple un `double`. 

\snippet ./src/function_intro.cpp mean_function 

Alors **attention** définir la fonction ne suffit pas pour que votre code fasse quelque chose ! Il ne faut pas oublier d'utiliser la fonction, on parle généralement d'un appel de fonction. Par exemple pour le cas de la moyenne nous pourrions faire dans le main : 

\snippet ./src/function_intro.cpp mean_call 

Et du coup si j'appelle ma fonction `mean` sur un `std::vector<double>` il se passe quoi ? Et bien ça ne marche pas évidemment ! 

```
function_intro.cpp:45:21: error: could not convert ‘values’ from ‘vector<double>’ to ‘vector<int>’
   45 |     double m = mean(values);
      |                     ^~~~~~
      |                     |
      |                     vector<double>
```

C'est à mon sens l'une des forces du C++ et de son côté typage fort c'est qu'une fonction est faite pour manger un certain type d'argument et si on ne lui donne pas les bonnes choses en entrée ça ne compile pas. Bon en fait dans la vraie vie ça peut compiler dans certains cas en faisant des conversions implicites et ça c'est un peu moins cool parfois !  

Mais du coup si je veux faire une fonction `mean` pour un `std::vector<double>` maintenant je dois faire une autre fonction avec un autre nom ? **Non** c'est encore une marque de génie du C++ c'est qu'il offre un mécanisme génial qui s'appelle la surcharge de fonctions ! 


## Surcharge de fonctions 

Le C++ dans son génie sans limite met à disposition des développeurs le mécanisme génial de la surcharge de fonctions. Le principe est simple, pour différencier deux fonctions entre elles le C++ regarde **deux** choses : 
1. L'identificateur de la fonction, son petit nom donc 
2. Le nombre et le type des arguments d'entrée de la fonction 

Le nombre et le type ? Je peux définir `n` fonctions ayant le même nom tant que les arguments d'entrées sont de types différents entre toutes les versions ça marche ? Et oui ça marche et ça c'est beau !! Je ne ferai pas de comparaison avec Python içi car ce mécanisme n'existe pas en Python. Si on reprend maintenant notre problème de fonction calculant la moyenne, nous pouvons donc faire quelque chose du genre : 

\snippet ./src/function_intro.cpp mean_function 
\snippet ./src/function_intro.cpp mean_function_dbl

Et à l'usage nous pouvons alors calculer la moyenne d'un tableau de `int` ou d'un tableau de `double` en appelant la même fonction c'est le compilateur qui s'occupe du reste ! 

\snippet ./src/function_intro.cpp mean_call_double


**Attention** : avant que vous ne vous emballiez un peu trop il faut noter une chose ! Le compilateur sait faire la différence entre deux fonctions du même nom uniquement sur le nombre et le type des arguments en **entrée**. En revanche il ne sait pas faire la distinction sur les types de sortie d'une fonction ! 


## Passage par copie ou par référence ? 

Attardons nous maintenant sur une petite subtilité du C++. Considérons par exemple une fonction qui prend en entrée un `std::vector<int>` modifie une valeur de ce vector et ne renvoie rien : 

\snippet ./src/function_intro.cpp copy_arg

Si on appelle cette fonction et que l'on affiche le contenu du `std::vector` à l'issue de cet appel voici ce qu'on obtient : 
\snippet ./src/function_intro.cpp copy_arg_call

```
1, 2, 3,
```

Pas vraiment ce qu'on avait en tête non ? Mais pourquoi ça ne marche pas ?! Et bien si ça marche c'est juste que vous n'avez pas su parler correctement au C++. Et du coup il fait exactement ce que vous lui avez demandé ! Il s'agit là de la grande subtilité du C++, ***le passage des arguments d'une fonction se fait toujours par copie*** ! Donc le tableau que l'on modifie dans la fonction est une copie de `v` donc en le modifiant on ne modifie pas `v` tout simplement ! 

Mais ça coûte cher non ? Alors oui faire une copie des arguments quand c'est un `int` ou un `double` ça passe mais quand c'est un `std::array<double, 10000>` ça commence à se faire sentir ! C'est pour cela qu'il existe un moyen de dire au c++ de ne pas faire de copies c'est ce qu'on appelle le passage par référence ! Et le nom doit vous rappeler quelque chose non ;) car oui le principe va être d'utiliser des références plutôt que les variables elles mêmes. Pour cela c'est au moment de la déclaration de la fonction qu'il faut dire que l'on ne veut pas la variables mais une référence vers cette dernière. Et cela se fait simplement en ajoutant un esperluette `&` derrière le type de l'argument que l'on ne veut pas copier ! Par exemple : 

\snippet ./src/function_intro2.cpp ref_arg

\snippet ./src/function_intro2.cpp ref_arg_call

```
10, 2, 3,
```
Dans ce cas on obtient donc le résultat attendu ! 

Par contre attention c'est à double tranchant ! Et oui si on passe tout par référence il y a le risque que l'on modifie une variable qui ne devait pas l'être et après dans le reste de notre code c'est la catastrophe ! Heureusement il y a un moyen de prévenir cela. Par exemple si on reprend l'exemple du calcul d'une moyenne nous pourrions passer le tableau des valeur par référence pour économiser une copie mais en revanche notre fonction ne doit en aucun cas pouvoir modifier les valeurs du tableau. Pour cela le qualificateur `const` est votre ami ! En effet nous pouvons déclarer un argument d'entrée comme const ce qui assure alors qu'aucune modification de la variable ne sera faite : 

\snippet ./src/function_intro2.cpp const_ref

Enfin dernière mise en garde ! N'ayez surtout pas l'idée d'essayer de renvoyer une référence via en sortie d'une fonction. Autrement dit n'essayez pas de faire : 

\snippet ./src/function_intro2.cpp bad_idea

Vous avez une petite idée de pourquoi ce code est tout sauf l'idée du siècle ? Tout simplement parce qu'une référence c'est une variable qui utilise la mémoire d'une autre variable donc en renvoyant en sortie de votre fonction la référence d'une variable locale à la fonction vous renvoyez en fait la zone mémoire de votre variable locale. Sauf que cette variable est **locale** donc quand on sort de la fonction elle est détruite et la zone mémoire associée est libérée du coup on se retrouve avec une référence vers une zone mémoire qui n'est plus réservé pour la variable initiale. Et là c'est le début de gros problème ... 

## Une pointe de modernité ! 

### Retourner plusieurs valeurs 

Tout d'abord vous avez peut-être constaté que les fonctions C++ par défaut ne retourne soit rien soit une **et une seule** variable. Du coup se pose la question de comment je fais si j'ai une fonction qui doit me retourner deux choses ? Alors avant le C++11 c'était tout simplement impossible ! Mais il existe une parade et elle est très simple. En effet il suffit de définir un argument supplémentaire que l'on passe par référence (non constante) et qui va jouer le rôle de notre seconde variable. Par exemple faisons une fonctions qui prend en entrée un `std::vector<double>` et retourne le tableau contenant toutes les valeurs sauf celle supérieures à un seuil fourni par l'utilisateur et retourne également le nombre de valeur supprimées. Dans le monde pré-c++11 nous pourrions procéder de la manière suivante : 

\snippet ./src/function_intro2.cpp in_out

A l'usage cela donnerai alors : 

\snippet ./src/function_intro2.cpp in_out_call 

Cela fait le travail et donc ne soyez pas surpris si vous tombez sur des structures dans ce style car on en trouve encore énormément dans beaucoup de codes ! 

Cependant le C++11 (gloire à lui) a permi de faire des fonctions qui retourne vraiment plusieurs valeurs sans passer par l'astuce des références. Et vous savez déjà comment faire ça en fait ! Non ? Pas d'idée ? C'est pourtant évident si vous ne pouvez renvoyer qu'un truc, renvoyez un conteneur hétérogène `std::tuple`. Et bah oui si on dit que notre fonction retourne un `std::tuple` on peut alors mettre autant de valeur en sortie qu'on le souhaite. Par exemple sur mon exemple de seuillage cela donnerai : 

\snippet ./src/function_intro2.cpp out11

Cela donnerai alors à l'usage : 

\snippet ./src/function_intro2.cpp out11_call 

C'est pas mal non ? J'avoue que le fait de manipuler un `std::tuple` est un peu lourd après à cause des `std::get` ce serait sympa d'avoir un truc un peu plus conci un jour... Oh mais au fait le C++17 a résolu ce problème je vous en ai parlé dans la partie sur les conteneurs. Et oui le C++17 a introduit le truc génial du *structured binding* et ça c'est cool car ça nous permet d'écrire directement : 

\snippet ./src/function_intro2.cpp out11_call17

Là je pense qu'on peut dire qu'on est content car c'est quand même vachement pratique et lisible surtout ! Donc maintenant n'hésitez plus si vos fonctions doivent renvoyer plusieurs choses qu'elles le fassent explicitemant plutôt que de faire un jeu de référence pas clair ! 





### Fonctions constexpr 




# Un mot sur les fonctions anonymes 

## Une fonction anonyme pour quoi faire ? 

## Définition des lambda fonctions 


# Manipuler des fonctions comme des variables 

## Pourquoi pas mais dans quel but ? 

## Le foncteur moderne 

## Imposer des valeurs de paramètres 


# Allons un peu plus loin 

Il est heureusement possible de séparer la **déclaration** des fonctions de leur **définition** pour optimiser les codes.

En effet, dans un code qui appelle une fonction, `C++`, pour faire ses habituelles vérifications de types, n'a besoin que du prototype de la fonction et pas du corps; le corps de la fonction peut être lui vérifié à un autre moment de la compilation.

On va donc pouvoir **déclarer** une fonction i.e. donner son prototype en remplaçant son corps par `;` et utiliser cette fonction. Bien sûr puisque vous l'utilisez, `C++`, pour faire votre exécutable, devra trouver le corps de la fonction quelque part. Ce code sera donné avec toute la fonction: prototype+corps.

Voyons un exemple:

\snippet ./src/function_declaration.cpp all


## Séparation dans différents fichiers 


### Compilation "monolitique" 

### Compilation en une librairie et un executable 

### Automatisons tout ça : CMake ! 

# Une fonction qui marche pour tout type c'est possible ? 

## La limitation du c++ 

## La notion de template 

## C++20 et les fonctions génériques 

## Mettons quelques rêgles en place ! 



