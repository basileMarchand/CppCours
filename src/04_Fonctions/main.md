
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

Donc pour créer (on dit souvent pour *définir*) une fonction, vous devez préciser: son **type** de retour, son **nom**, ses éventuels **arguments** entre des parenthèses (parce que oui, il est souvent utile de passer des informations à la fonction) et son **corps** dans un bloc (à l'intérieur des fameuses `{}`).

Regardons une fonction très simple:

\snippet ./src/function_intro.cpp print_coucou

Son type de retour est vide (`void`) c'est à dire qu'elle ne renvoie pas d'information (c'est une simple procédure), elle ne prend pas d'arguments et son corps se contente d'afficher la chaîne de caractères "coucou" et pas 'coucou' ! on n'est pas `Python`...

## Prototype d'une fonction

Vous pouvez transmettre des données, appelées les paramètres, à une fonction.

# Un mot sur les fonctions anonymes 

## Une fonction anonyme pour quoi faire ? 

## Définition des lambda fonctions 


# Manipuler des fonctions comme des variables 



# Allons un peu plus loin 

Il est heureusement possible de séparer la **déclaration** des fonctions de leur **définition** pour optimiser les codes.

En effet, dans un code qui appelle une fonction, `C++`, pour faire ses habituelles vérifications de types, n'a besoin que du prototype de la fonction et pas du corps; le corps de la fonction peut être lui vérifié à un autre moment de la compilation.

On va donc pouvoir **déclarer** une fonction i.e. donner son prototype en remplaçant son corps par `;` et utiliser cette fonction. Bien sûr puisque vous l'utilisez, `C++`, pour faire votre exécutable, devra trouver le corps de la fonction quelque part. Ce code sera donné avec toute la fonction: prototype+corps.

Voyons un exemple:

\snippet ./src/function_declaration.cpp all


## Séparation dans différents fichiers 


### Compilation "monolitique" 

### Compilation en une librairie et un executable 





