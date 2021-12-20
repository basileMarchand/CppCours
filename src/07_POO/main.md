
Programmation Orientée Objet     {#pooSection}
============================

[TOC]


# La programmation orientée objet 

## Un paradigme parmi d'autres

La notion de Programmation Orientée Objet, communément appelée POO, est un paradigme de programmation au même titre que la programmation fonctionnelle. C'est à dire qu'il s'agit d'un style de programmationn definissant un certain nombre de rêgles à suivre pour développer. Le principe du paradigme POO est de considéré qu'un programme informatique est un assemblage de briques, les fameux objets, et ces briques vont interagir entre elle ce qui va alors définir le comportement de notre programme. Pour information la notion de programmation orientée objet a été conceptualisée par [Alan Kay](https://fr.wikipedia.org/wiki/Alan_Kay) vers la fin des années 70 mais sa mise en oeuvre a plutôt explosée dans les années 90. 

Mais concrètement un objet c'est quoi ? Et bien dans les fait c'est ce que vous voulez il peut s'agir d'un concept ou une entité du monde physique. Dans tous les cas cet objet sera caractérisée par : 

* Une structure interne, définissant les quantités contenues dans cet objet
* Un comportement, définissant comment cet objet interagi avec le monde exterieur 
  

## Les grandes rêgles de la POO 

Pour qu'un langage de programmation puisse s'inscrire dans le paradigme orienté objet il est nécessaire qu'il mette à disposition un certain nombre de concepts.

### La définition d'objet 

Ca peut paraître évident mais pour faire de la programmation orientée objet il faut pouvoir définir des objets ... C'est à dire des structures de données possédant un état et étant capable d'interragir avec le monde exterieur. Les données qui définissent la structure interne d'un objet sont appelés **attributs** tandis que les "fonctions" qui vont définir son comportement sont appelées **méthodes**, on parle également de l'interface de l'objet ou API car c'est via ces méthodes que l'on va pouvoir interragir avec l'objet. 

Ces attributs et méthodes peuvent être de différentes natures dans le sens où ils peuvent être caché du monde extérieurs, c'est à dire visible uniquement en interne,  on parle du principe d'encapsulation alors. Mais ils peuvent aussi être publique et dans ce cas visibles et utilisables depuis l'exterieur de l'objet. 

Quel intérêt d'encapsuler et de n'offrir que des interfaces ? Plusieurs mais entre autre la simplicité d'utilisation, la robustesse et la maintenabilité du code. Par exemple considérons un objet traceur de courbe. Il s'agirait d'un objet assez compliqué devant faire appel à des librairies graphique pour tracer une courbe. Si je n'offre pas une interface donc des méthodes simples : (i) la plupart des gens n'utiliseront pas cet objet car trop compliqués ; (ii) les quelques utilisateurs qui passeront le cap de la difficulté devront manipuler les attributs interne de l'objet pour tracer leur graphes. Maintenant imaginons que pour une raison quelconque je choisisse de changer la librairie graphique utilisée en interne de mon objet. Dans le cas où il n'y avais pas d'encapsulation et bien le code de l'utilisateur ne fonctionnera plus du tout alors que si l'on a une encapsulation propre toute la logique interne est cachée et donc le changement devient transparent pour l'utilisateur final. 

### Notion de polymorphisme 

Le concept de polymorphisme est essentiel pour la programmation orientée objet c'est ce qui va permettre de faire passer un objet d'un certain type pour un objet d'un autre type. Ce n'est pas générique en revanche il faut qu'il existe une certaine relation entre les types. Le plus courant est d'utiliser la notion d'héritage c'est à dire de créer un objet qui hérite d'un autre objet. L'intérêt de l'héritage est de définir des objets de base très génériques et ensuite de venir les spécialiser en héritant. 

### La surcharge 

Enfin pour que nos objets puissent interagir entre eux et avec le monde extérieur il est nécessaire que l'on puisse surcharger des opérateurs. Par exemple imaginons que l'on définisse un objet `Matrice` il faut par exemple que l'on soit capable de surchager l'opérateur `+` afin de pouvoir faire la somme de deux matrices. 

## Le C++ un langage historiquement pour la POO 

Historiquement rappelons le le C++ s'appelait le C With Class et donc il avait notamment vocation d'étendre le C au paradigme orientée objet. De ce fait le C++ dispose de tous les éléments nécessaire à la programmation objet. Dans les années 90 c'était même **le** langage orienté objet à la mode, en effet il était assez courant de voir des personnes se vanter d'avoir un code C++ orienté objet à cet époque c'était la classe (sans mauvais jeu de mots). 

# Définition de classes 

## Attributs et méthodes

Le premier ingrédient dans la programmation orientée objet est la définition d'objet. En C++ cela passe par la définition de classes. Une classe va donc nous permettre de définir un nouveau type qui aura sa structures interne et une logique de fonctionnement. Donc une classe **=** un objet ! 

La définition d'une classe se fait en utilisant le mot clé `class`, pas très très original je sais. Avec la syntaxe suivante : 

```
class NomDeMaClasse {
    // la structure interne 
};
```

Dans cette classe nous allons alors définir des attributs qui vont être des variables définissant l'état de notre objet ainsi que des méthodes qui sont en réalité des fonctions. 

Par exemple faisons une classe `Point` qui va représenter un point géométrique dans l'espace 2D.  Cet objet doit avoir dans sa structure interne les coordonnées du point `(x,y)` et aussi le nom du point. 

\snippet ./src/point1.cpp point1 

**Attention :** par défaut le C++ respecte strictement le principe d'encapsulation. C'est à dire que par défaut les attribut d'une classe sont privé donc ne sont pas accessible de l'extérieur. C'est une bonne chose mais pour le moment on va passer outre et pour cela nous allons définir nos attribut comme publique en utilisant `public`: 

\snippet ./src/point2.cpp point 

Nous pouvons alors créer un objet de type `Point` et lui assigner des valeurs de la manière suivante :

\snippet ./src/point2.cpp point_instance


Nous pouvons également ajouter des méthodes, c'est à dire définir un comportement pour notre objet `Point`. Par exemple nous allons définir une méthode `print()` qui va afficher dans la console l'état du point considéré. Pour définir les méthodes deux approches existent 

1. On déclare et on définit la méthode dans le corps de la classe
2. On déclare la méthode dans le corps de la classe mais on la définit en dehors. 

Par exemple si on fait tout dans le corps de la classe cela donne 

\snippet ./src/point3.cpp point


Tandis que si on sépare déclaration et définition cela donne : 

\snippet ./src/point4.cpp point

On déclare juste le fait qu'il existe dans la classe `Point` une méthode `print()` qui ne prend aucun argument et ne retourne rien en revanche on explique pas ici ce que fait cette méthode. Tandis que la définition se fait en dehors de la classe de la manière suivante : 

\snippet ./src/point4.cpp print_def 


Pourquoi ces deux possibilités ? Pour une raison simple. la déclaration d'une classe doit dans de nombreux cas se trouver dans un fichier d'en-tête (les .hpp) pour que la classe soit utilisable dans différents fichiers .cpp. Et donc si on ne pouvais pas séparer déclaration et définition tout le code se trouverai dans les .hpp et au moment de la compilation cela engendrerai alors des temps de compilation assez monstrueux. L'autre raison plus pragmatique est que lorsqu'on diffuse un programme binaire il faut généralement diffuser les fichiers d'en-tête pour permettre aux utilisateurs de faire des plugins, utiliser le logiciel dans d'autre programmes, ... et donc si tout le code est dans les .hpp il semble difficile de garder le code propriétaire... Mais ça c'est si on veut faire de l'argent en vendant du logiciel uniquement. 

A l'usage dans les deux cas cela donne alors : 

\snippet ./src/point4.cpp point_instance 

Et ensuite on appelle la méthode print de la manière suivante ; 

\snippet ./src/point4.cpp point_print

Cela donne alors le résultat suivant : 

```
A (10, 5)
```


### Initialisation des attributs 

Une question que vous vous posez peut-être est est-il possible d'initialiser les attributs de différentes manières ? La réponse est évidemment oui par exemple précédemment nous avons initialisé nos attribut de la manière suiviante : 

\snippet ./src/point5.cpp point_A

Cela donne alors à l'usage le résultat suivant : 

```
A (10, 5)
```

Depuis le C++11 il est également possible d'utiliser une liste d'initialization comme illustré ci-dessous : 

\snippet ./src/point5.cpp point_B

**Attention** les valeurs dans la liste d'initialization doivent être dans le même sens que celui de déclaration des attributs dans la classe !! Et à l'usage cela donne alors le bon résultat : 

```
B (10, 5)
```

Les deux approches précédentes ne sont possible uniquement parce que nous avons déclaré les attributs de notre classe comme `public` ! Or je vous rappel que ce n'est pas forcément le mieux à faire. Dans le cas où nous aurions respecté le principe d'encapsulation nous pourrions uniquement faire (pour le moment): 

\snippet ./src/point5.cpp point_C

Et à l'usage là c'est le drame car les attributs sont alors initialisés de manière aléatoire :  

```
 (6.9503e-310, 6.9503e-310)
```

Pour fournir des valeurs à la construction de l'objet nous le verrons dans la suite nous devront définir un constructeur de classe. Néanmoins nous pouvons déjà définir des valeurs par défaut à nos attributs. En effet depuis la norme C++11 nous pouvons dans la déclaration de la classe donner des valeurs par défaut. Par exemple :

\snippet ./src/point_default.cpp point 

Et alors à l'utilisation nous obtenons 

\snippet ./src/point_default.cpp point_decl

```
O (0, 0)
```

## Portée des membres : private, protected, public 

Revenons un peu sur les notions de `public` pas `public` ! Dans la définition de nos classes nous pouvons donner trois status différentes aux atributs et méthodes : 

* `public` : l'attribut/méthode est visible depuis l'intérieur et l'extérieur de l'objet 
* `protected` : l'attribut/méthode est visible depuis l'intérieur de l'objet, depuis l'intérieur de tout sous-objet qui hériterait de objet mais n'est pas accessible de l'exterieur
* `private` : l'attribut/méthode est visible depuis l'intérieur de l'objet lui-même et c'est tout. 

Pour le moment il n'y a donc pas de différence entre `protected` et `private` car vous ne savez pas faire d'héritage !! Mais je vous conseille néanmoins d'utiliser plutôt protected par défault lorsque vous ne voulez pas que des choses soient `public`. 


Regardons par exemple la définition de classe suivante : 

\snippet ./src/point_protected.cpp point 

Nous pouvons alors constater : 

- Les attributs `x`, `y` et `name` sont protected donc inaccessible depuis l'exterieur de la classe. 
- Il y a une méthode publique `setValues` qui permet de fournir des valeurs à `x`, `y`, `name` donc depuis l'intérieur de la classe nous pouvons bien modifier nos attributs `protected`
- Il y a une méthode `print` publique qui en interne appelle la méthode `print_protected` qui elle est `protected`. Ainsi nos offrons une interface unique qui en réalité peut cacher tout un tas de plomberie interne 

A l'usage nous pouvons donc faire : 

\snippet ./src/point_protected.cpp point_inst 


C'est grace à ce jeu de `protected`/`public` que nous pouvons donc mettre en place le concept d'encapsulation c'est à dire ne rien exposer directement mais offrir une interface permettant au passage de vérifier que les valeurs fournies ont du sens. C'est ce qu'on appelle des `setter`. 

## Notion de constructeur 

Dans l'exemple précédent pour renseigner les attributs `protected` de la classe `Point` nous sommes passé par une méthode `setValues`. Cela fonctionne cependant il serait un peu plus sympa de pouvoir renseigner ces valeurs directement à l'instanciation de l'objet en faisant quelque chose du genre : 

\snippet ./src/constructeur_example.cpp point_inst 

Cela est possible si on définit ce que l'on appel le constructeur de la classe. Le constructeur est une méthode de classe qui a pour nom, le nom de la classe forcément et surtout qui ne renvoie rien (par rien `void` mais rien rien) ! Par exemple pour dire que l'on ajoute un cnstructeur prenant en entrée trois argument nous pouvons faire de la manière suivante : 

\snippet ./src/constructeur_example.cpp point 

Et alors pour implémenter ce constructeur deux syntaxes sont envisageables. La première utilise une notation un peu particulière qui est la suivante : 

\snippet ./src/constructeur_example.cpp construct1 


Tandis que la second ressemble plus à ce que l'on ferait naturellement : 

\snippet ./src/constructeur_example.cpp construct2 

Quelle différence entre ces deux approches. Conceptuellement pas tant que ça car à la fin le résultat est le même. En revanche en pratique il y a une différence notable qui est que dans le second cas les attributs de class pendant un moment ont des valeurs indéterminées tant qu'on ne leurs a pas affecté les valeurs `a`, `b` et `pname`. Tandis que dans le premier cas à la création de l'objet les valeurs des attributs ne passent pas par cet état indeterminé mais sont directement construit et initialisé avec les valeurs fournies au constructeur. 


Si vous êtes familier du Python le constructeur c'est exactement la même chose que la méthode `__init__` d'une classe Python. Mais en réalité en C++ c'est mieux :) car il y a une fonctionnalité qui n'existe pas en Python que l'on a c'est la possibilité de définir plusieurs constructeurs. Wait wait wait !!! Comment c'est possible vu que la constructeur a forcément le même nom que la classe ? Et bien c'est possible grâce au concept de surcharge. Car je vous rappel au cas où vous auriez oublié le C++ est capable de faire la différence entre deux fonctions du même nom en regardant le nombre et le type des arguments d'entrée des fonctions. Et bien le même principe est exactement applicable aux méthodes de classe et aux constructeurs. Par exemple nous pouvons faire : 

\snippet ./src/constructeur_example2.cpp point 

Et les différentes implémentations serez les suivantes : 

\snippet ./src/constructeur_example2.cpp construct 

Ainsi à l'utilisation nous pourrions créer des objets points des quatre manières suivantes : 

\snippet ./src/constructeur_example2.cpp point_inst 

## Constructeur de copie 

Parmis les constructeurs possibles et imaginable il en existe un qui est un peu particulier, il s'agit du constructeur de copie. Par exemple c'est ce constructeur qui sera appelé si nous voulons faire : 

\snippet ./src/copy_constructor.cpp copy 

Dans ce cas nous devons définir un constructeur qui va prendre comme argument d'entrée une instance de `Point`. Attention sur comment on fournit cet argument d'entrée. Si on ne réfléchit pas nous pourrions faire quelque chose du genre 

\snippet ./src/copy_constructor.cpp bad_idea 


Mais cela ne va compiler et c'est normal !! Pourquoi ?????? Et bien simplement parce que je vous le rappel par défaut le passage d'argument se fait par copie en C++. Or si pour appeler le constructeur de copie il faut commencer par faire une copie c'est un peu bizarre non ? Donc le constructeur de copie a toujours un prototype de la forme suivante : 

\snippet ./src/copy_constructor.cpp good_idea 

Pourquoi le `const` ? Simplement parce que quand je fais une copie de `other` il n'y a aucune raison pour que le fait de faire une copie modifie l'objet. Au niveau de l'implémentation de ce constructeur de copie nous pouvons alors faire quelque chose du genre : 

\snippet ./src/copy_constructor.cpp copy_constructor


## Déclarer des méthodes const

Pour finir ce premier tour d'horizon de la définition des classes nous allons regarder un comportement un peu particulier lié au fait que l'on peut être amené à déclarer des instances de nos classes comme étant `const`. Par exemple imaginons que j'ai une fonction `callPrint` qui prend en argument une instance de `Point` et appelle la méthode `print` de cette instance. Par réflexe, j'espère en tout cas que vous avez acquis ce réflexe, le prototype de la fonction `callPrint` serait de la forme suivante : 

\snippet ./src/const_method.cpp const_arg

On passe l'instance de Point par référence constante car on n'a aucune raison de modifier l'instance. Vous êtes d'accord ? Du coup si je prends la définition suivante pour la classe `Point` tout le monde est content. 

\snippet ./src/const_method.cpp print_no_const 

Et bien dans les faits cela vous convient peut-être mais le compilateur lui n'est pas d'accord (et c'est toujours lui qui a le dernier mot....). En effet à la compilation on obtient l'erreur suivante : 

```
const_method.cpp: Dans la fonction « void callPointPrint(const Point&) »:
const_method.cpp:55:13: erreur: le passage de « const Point » comme argument « this » abandonne les qualificatifs [-fpermissive]
   55 |     p.print();
      |             ^
const_method.cpp:21:6: note:   dans l'appel de « void Point::print() »
   21 | void Point::print(){
      |      ^~~~~
```

Ce que le compilateur essaye de vous dire c'est que vous considérez l'instance de `Point` comme `const` dans la fonction `callPointPrint` **mais** ensuite vous appelez sur cette instance la méthode `print` or a aucun moment vous n'avez dit au compilateur que le fait d'appeler `print` ne modifie rien dans l'instance. Et donc il part du principe que par défaut chaque méthode risque de modifier l'instance donc l'instance ne peut pas être `const`. Pour expliquer au compilateur que promis la méthode ne change rien à l'instance il suffit d'ajouter le qualificateur `const` derrière la déclaration **et** la définition de la méthode. Cela donne par exemple dans notre cas : 

\snippet ./src/const_method.cpp print_const 

Et ainsi la compilation devient valide puisque nous avons bien précisé maintenant que la méthode `print` ne modifie pas l'instance donc nous pouvons appeler `print` sur une instance de `Point` `const`. 


## Pointeur vers une instance de classe 

## Notion de destructeur 


# Surcharge d'opérateur 

## Opérateur d'affectation 

## Opérateurs mathématiques 

## Opérateurs d'accès 


# Héritage 

## Classe mère, classe fille 

## Méthodes virtuelle 

## Destructeur virtuel 

# Polymorphisme 

## Un mot compliqué pour un truc simple 

## Le polymorphisme un coût en plus ? 

## Faire du polymorphisme sans héritage c'est possible ! 


# Pour le fun : type litterals 




