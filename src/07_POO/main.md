
Programmation Orientée Objet     {#pooSection}
============================

[TOC]


# La programmation orientée objet 

## Un paradigme parmi d'autres

La notion de Programmation Orientée Objet, communément appelée POO, est un paradigme de programmation au même titre que la programmation fonctionnelle. C'est à dire qu'il s'agit d'un style de programmation définissant un certain nombre de règles à suivre pour développer. Le principe du paradigme POO est de considérer qu'un programme informatique est un assemblage de briques, les fameux objets, et ces briques vont interagir entres elles ce qui va alors définir le comportement de notre programme. Pour information la notion de programmation orientée objet a été conceptualisée par [Alan Kay](https://fr.wikipedia.org/wiki/Alan_Kay) vers la fin des années 70 mais sa mise en oeuvre a plutôt explosé dans les années 90. 

Mais concrètement un objet c'est quoi ? Et bien dans les faits c'est ce que vous voulez il peut s'agir d'un concept ou une entité du monde physique. Dans tous les cas cet objet sera caractérisé par : 

* Une structure interne, définissant les quantités contenues dans cet objet
* Un comportement, définissant comment cet objet interagit avec le monde extérieur 
  

## Les grandes règles de la POO 

Pour qu'un langage de programmation puisse s'inscrire dans le paradigme orienté objet il est nécessaire qu'il mette à disposition un certain nombre de concepts.

### La définition d'objet 

Ça peut paraître évident mais pour faire de la programmation orientée objet il faut pouvoir définir des objets ... C'est à dire des structures de données possédant un état et étant capable d'interagir avec le monde extérieur. Les données qui composent la structure interne d'un objet sont appelées **attributs** tandis que les "fonctions" qui vont définir son comportement sont appelées **méthodes**, on parle également de l'interface de l'objet ou API car c'est via ces méthodes que l'on va pouvoir interagir avec l'objet. 

Ces attributs et méthodes peuvent être de différentes natures dans le sens où ils peuvent être cachés au monde extérieur, c'est à dire visible uniquement en interne,  on parle alors du principe d'encapsulation. Mais ils peuvent aussi être publics et dans ce cas visibles et utilisables depuis l'extérieur de l'objet. 

Quel intérêt d'encapsuler et de n'offrir que des interfaces ? Plusieurs mais entre autre la simplicité d'utilisation, la robustesse et la maintenabilité du code. Par exemple, considérons un objet traceur de courbe. Il s'agirait d'un objet assez compliqué devant faire appel à des librairies graphiques pour dessiner une courbe. Si je n'offre pas une interface donc des méthodes simples : (i) la plupart des gens n'utiliseront pas cet objet car considéré comme trop compliqué ; (ii) les quelques utilisateurs qui passeront le cap de la difficulté devront manipuler les attributs internes de l'objet pour tracer leur graphes. Maintenant imaginons que pour une raison quelconque je choisisse de changer la librairie graphique utilisée en interne de mon objet. Dans le cas où il n'y avait pas d'encapsulation et bien le code de l'utilisateur ne fonctionnera plus du tout alors que si l'on a une encapsulation propre, toute la logique interne est cachée et donc le changement devient transparent pour l'utilisateur final. 

### Notion de polymorphisme 

Le concept de polymorphisme est essentiel pour la programmation orientée objet, c'est ce qui va permettre de faire passer un objet d'un certain type pour un objet d'un autre type. Ce n'est pas générique en revanche il faut qu'il existe une certaine relation entre les types. Le plus courant est d'utiliser la notion d'héritage c'est à dire de créer un objet qui hérite d'un autre objet. L'intérêt de l'héritage est de définir des objets de base très génériques et ensuite de venir les spécialiser en héritant. 

### La surcharge 

Enfin pour que nos objets puissent interagir entre eux et avec le monde extérieur il est nécessaire que l'on puisse surcharger des opérateurs. Par exemple imaginons que l'on définisse un objet `Matrice` il faut par exemple que l'on soit capable de surcharger l'opérateur `+` afin de pouvoir faire la somme de deux matrices. 

## Le C++ un langage historiquement pour la POO 

Historiquement rappelons le, le `C++` s'appelait le *C With Class* et donc il avait notamment vocation d'étendre le `C` au paradigme orienté objet. De ce fait le `C++` dispose de tous les éléments nécessaires à la programmation objet. Dans les années 90 c'était même **le** langage orienté objet à la mode, en effet il était assez courant de voir des personnes se vanter d'avoir un code `C++` orienté objet à cette époque c'était la classe (sans mauvais jeu de mots). 

# Définition de classes 

## Attributs et méthodes

Le premier ingrédient dans la programmation orientée objet est la définition d'objet. En `C++` cela passe par la définition de classes. Une classe va donc nous permettre de définir un nouveau type qui aura sa structure interne et une logique de fonctionnement. Donc une classe `=` un objet ! 

La définition d'une classe se fait en utilisant le mot clé `class`, pas très très original je sais. Avec la syntaxe suivante : 

```
class NomDeMaClasse {
    // la structure interne 
};
```

Dans cette classe nous allons alors définir des attributs qui vont être des variables définissant l'état de notre objet ainsi que des méthodes qui sont en réalité des fonctions. 

Par exemple, faisons une classe `Point` qui va représenter un point géométrique dans l'espace 2D.  Cet objet doit avoir dans sa structure interne les coordonnées du point `(x,y)` ainsi que le nom du point. 

\snippet ./src/point1.cpp point1 

**Attention :** par défaut le `C++` respecte strictement le principe d'encapsulation. C'est à dire que par défaut les attributs d'une classe sont privés et donc ne sont pas accessibles de l'extérieur. C'est une bonne chose, mais pour le moment on va passer outre et pour cela nous allons définir nos attribut comme publics en utilisant `public`: 

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

On déclare juste le fait qu'il existe dans la classe `Point` une méthode `print()` qui ne prend aucun argument et ne retourne rien en revanche on n'explique pas ici ce que fait cette méthode. Tandis que la définition se fait en dehors de la classe de la manière suivante : 

\snippet ./src/point4.cpp print_def 


Pourquoi ces deux possibilités ? Pour une raison simple: la déclaration d'une classe doit, dans de nombreux cas, se trouver dans un fichier d'en-tête (les `.hpp`) pour que la classe soit utilisable dans différents fichiers `.cpp`. Et donc si on ne pouvait pas séparer déclaration et définition tout le code se trouverait dans les `.hpp` et au moment de la compilation cela engendrerait alors des temps de compilation assez monstrueux. L'autre raison plus pragmatique est que lorsqu'on diffuse un programme binaire il faut généralement diffuser les fichiers d'en-tête pour permettre aux utilisateurs de faire des *plugins*, i.e. d'utiliser le logiciel dans d'autres programmes, ... et donc si tout le code est dans les `.hpp` il semble difficile de garder le code propriétaire... Mais ça c'est si on veut faire de l'argent en vendant du logiciel uniquement. 

À l'usage dans les deux cas cela donne alors : 

\snippet ./src/point4.cpp point_instance 

Et ensuite on appelle la méthode `print` de la manière suivante ; 

\snippet ./src/point4.cpp point_print

Cela donne alors le résultat suivant : 

```
A (10, 5)
```


### Initialisation des attributs 

Une question que vous vous posez peut-être est: Est-il possible d'initialiser les attributs de différentes manières ? La réponse est évidemment oui par exemple précédemment nous avons initialisé nos attributs de la manière suivante : 

\snippet ./src/point5.cpp point_A

Cela donne alors à l'usage le résultat suivant : 

```
A (10, 5)
```

Depuis le `C++11` il est également possible d'utiliser une liste d'initialization comme illustré ci-dessous : 

\snippet ./src/point5.cpp point_B

**Attention** les valeurs dans la liste d'initialisation doivent être dans le même ordre que l'ordre de déclaration des attributs dans la classe !! Et à l'usage cela donne alors le bon résultat : 

```
B (10, 5)
```

Les deux approches précédentes ne sont possibles uniquement parce que nous avons déclaré les attributs de notre classe comme `public` ! Or je vous rappelle que ce n'est pas forcément le mieux à faire. Dans le cas où nous aurions respecté le principe d'encapsulation nous pourrions uniquement faire (pour le moment): 

\snippet ./src/point5.cpp point_C

Et à l'usage là c'est le drame car les attributs sont alors initialisés de manière aléatoire :  

```
 (6.9503e-310, 6.9503e-310)
```

Pour fournir des valeurs à la construction de l'objet, nous le verrons dans la suite, nous devrons définir un constructeur de classe. Néanmoins nous pouvons déjà définir des valeurs par défaut à nos attributs. En effet depuis la norme `C++11` nous pouvons dans la déclaration de la classe donner des valeurs par défaut. Par exemple :

\snippet ./src/point_default.cpp point 

Et alors à l'utilisation nous obtenons 

\snippet ./src/point_default.cpp point_decl

```
O (0, 0)
```

## Portée des membres : private, protected, public 

Revenons un peu sur les notions de `public` pas `public` ! Dans la définition de nos classes nous pouvons donner trois status différents aux attributs et méthodes : 

* `public` : l'attribut/méthode est visible depuis l'intérieur et l'extérieur de l'objet 
* `protected` : l'attribut/méthode est visible depuis l'intérieur de l'objet, depuis l'intérieur de tout sous-objet qui hériterait de objet mais n'est pas accessible de l'extérieur
* `private` : l'attribut/méthode est visible depuis l'intérieur de l'objet lui-même et c'est tout. 

Pour le moment il n'y a donc pas de différence entre `protected` et `private` car vous ne savez pas faire d'héritage !! Mais je vous conseille néanmoins d'utiliser plutôt `protected` par défaut lorsque vous ne voulez pas que des choses soient `public`. 


Regardons par exemple la définition de classe suivante : 

\snippet ./src/point_protected.cpp point 

Nous pouvons alors constater : 

- Les attributs `x`, `y` et `name` sont `protected` donc inaccessibles depuis l'extérieur de la classe. 
- Il y a une méthode publique `setValues` qui permet de fournir des valeurs à `x`, `y`, `name` donc, depuis l'intérieur de la classe nous pouvons bien modifier nos attributs `protected`
- Il y a une méthode `print` publique qui en interne appelle la méthode `print_protected` qui elle est `protected`. Ainsi nous offrons une interface unique qui en réalité peut cacher tout un tas de plomberie interne 

A l'usage nous pouvons donc faire : 

\snippet ./src/point_protected.cpp point_inst 


C'est grace à ce jeu de `protected`/`public` que nous pouvons donc mettre en place le concept d'encapsulation c'est à dire ne rien exposer directement mais offrir une interface permettant au passage de vérifier que les valeurs fournies ont du sens. C'est ce qu'on appelle des `setter`. 

## Notion de constructeur 

Dans l'exemple précédent, pour renseigner les attributs `protected` de la classe `Point`, nous sommes passés par une méthode `setValues`. Cela fonctionne, cependant il serait un peu plus sympa de pouvoir renseigner ces valeurs directement à l'instanciation de l'objet en faisant quelque chose du genre : 

\snippet ./src/constructeur_example.cpp point_inst 

Cela est possible si on définit ce que l'on appelle le constructeur de la classe. Le constructeur est une méthode de classe qui a pour nom forcément le nom de la classe et surtout qui ne renvoie rien (par rien `void` mais rien rien) ! Par exemple pour dire que l'on ajoute un constructeur prenant en entrée trois arguments nous pouvons faire de la manière suivante : 

\snippet ./src/constructeur_example.cpp point 

Et alors pour implémenter ce constructeur, deux syntaxes sont envisageables: la première utilise une notation un peu particulière qui est la suivante : 

\snippet ./src/constructeur_example.cpp construct1 


Tandis que la seconde ressemble plus à ce que l'on ferait naturellement : 

\snippet ./src/constructeur_example.cpp construct2 

Quelle est la différence entre ces deux approches ? Conceptuellement pas tant que ça car à la fin le résultat est le même. En revanche en pratique il y a une différence notable qui est que dans le second cas les attributs de `class`, pendant un moment, ont des valeurs indéterminées (tant qu'on ne leur a pas affecté les valeurs `a`, `b` et `pname`). Tandis que dans le premier cas, à la création de l'objet, les valeurs des attributs ne passent pas par cet état indéterminé mais sont directement construites et initialisées avec les valeurs fournies au constructeur. 


Si vous êtes familier du Python le constructeur c'est exactement la même chose que la méthode `__init__` d'une classe Python. Mais en réalité en `C++` c'est mieux :) car il y a une fonctionnalité qui n'existe pas en `Python`: c'est la possibilité de définir plusieurs constructeurs. Wait wait wait !!! Comment c'est possible vu que la constructeur a forcément le même nom que la classe ? Et bien c'est possible grâce au concept de surcharge. Car je vous rappelle, au cas où vous auriez oublié, que le `C++` est capable de faire la différence entre deux fonctions de même nom en regardant le nombre et le type des arguments d'entrée des deux fonctions. Et bien le même principe est exactement applicable aux méthodes de classes et aux constructeurs. Par exemple nous pouvons faire : 

\snippet ./src/constructeur_example2.cpp point 

Et les différentes implémentations seront les suivantes : 

\snippet ./src/constructeur_example2.cpp construct 

Ainsi à l'utilisation nous pourrions créer des objets: des quatre manières suivantes : 

\snippet ./src/constructeur_example2.cpp point_inst 

Notons enfin que les arguments du constructeur peuvent prendre des valeurs par défaut, nous pouvons ainsi réunir plusieurs (4) constructeurs en un seul, notons que les noms des arguments et des attributs peuvent être les mêmes (cela simplifie la recherche des noms...) 

\snippet ./src/constructeur_example3.cpp point_

Et à l'utilisation, on a bien quatre constructeurs.

\snippet ./src/constructeur_example3.cpp point_default


### Constructeur de copie 

Parmi les constructeurs possibles et imaginables, il en existe un qui est un peu particulier, il s'agit du constructeur de copie. Par exemple c'est ce constructeur qui sera appelé si nous voulons faire : 

\snippet ./src/copy_constructor.cpp copy 

Dans ce cas nous devons définir un constructeur qui va prendre comme argument d'entrée une instance de `Point`. Attention sur comment on fournit cet argument d'entrée. Si on ne réfléchit pas nous pourrions faire quelque chose du genre 

\snippet ./src/copy_constructor.cpp bad_idea 


Mais cela ne va compiler et c'est normal !! Pourquoi ?????? Et bien simplement parce que je vous le rappelle: par défaut le passage d'argument se fait par copie en C++. Or si pour appeler le constructeur de copie il faut commencer par faire une copie c'est un peu bizarre non ? Donc le constructeur de copie a toujours un prototype de la forme suivante : 

\snippet ./src/copy_constructor.cpp good_idea 

Pourquoi le `const` ? Simplement parce que quand je fais une copie de `other` il n'y a aucune raison pour que la copie modifie l'objet copié. Au niveau de l'implémentation de ce constructeur de copie nous pouvons alors faire quelque chose du genre : 

\snippet ./src/copy_constructor.cpp copy_constructor

### Laisser faire ou le compilateur ou lui imposer des choses ! 

Au niveau des constructeurs, nous avons vu lorsque nous avons fait la première version de notre classe `Point` que le compilateur nous génère le constructeur par défaut si besoin ainsi que le constructeur de copie et l'opérateur d'affectation. Cependant cela est vrai tant qu'on ne définit aucun constructeur. A partir du moment ou vous avez défini un constructeur quelqu'il soit le compilateur ne fait plus rien pour nous.... On peut cependant lui demander gentiment de quand même générer son constructeur par défaut en utilisant le mot-clé `default`. 

\snippet ./src/default_delete_example.cpp default 


Dans un esprit similaire nous pouvons demander explicitement qu'un constructeur par défaut ne soit pas défini, par exemple si on souhaite empêcher la copie de nos objets il nous suffit de dire au compilateur que le constructeur de copie ne doit jamais être défini. Cela se fait à l'aide du mot-clé `delete`. 


\snippet ./src/default_delete_example.cpp delete




## Déclarer des méthodes const

Pour finir ce premier tour d'horizon de la définition des classes nous allons regarder un comportement un peu particulier lié au fait que l'on peut être amené à déclarer des instances de nos classes comme étant `const`. Par exemple imaginons que j'ai une fonction `callPrint` qui prend en argument une instance de `Point` et appelle la méthode `print` de cette instance. Par réflexe, j'espère en tout cas que vous avez acquis ce réflexe, le prototype de la fonction `callPrint` serait de la forme suivante : 

\snippet ./src/const_method.cpp const_arg

On passe l'instance de Point par référence constante car on n'a aucune raison de modifier l'instance. Vous êtes d'accord ? Du coup si je prends la définition suivante pour la classe `Point` tout le monde est content ? 

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

Ce que le compilateur essaye de vous dire c'est que vous considérez l'instance de `Point` comme `const` dans la fonction `callPointPrint` **mais** ensuite vous appelez, sur cette instance, la méthode `print` or à aucun moment vous n'avez dit au compilateur que le fait d'appeler `print` ne modifie rien dans l'instance de l'objet. Et donc il part du principe que par défaut chaque méthode risque de modifier l'instance donc l'instance ne peut pas être `const`. Pour expliquer au compilateur que promis la méthode ne change rien à l'instance il suffit d'ajouter le qualificateur `const` derrière la déclaration **et** la définition de la méthode. Cela donne par exemple dans notre cas : 

\snippet ./src/const_method.cpp print_const 

Et ainsi la compilation devient valide puisque nous avons bien précisé maintenant que la méthode `print` ne modifie pas l'instance donc nous pouvons appeler `print` sur une instance de `Point` `const`. 


## Pointeur vers une instance de classe 

Nous allons à présent voir le premier lien qu'il existe entre classes et pointeurs. Car depuis un moment déjà je vous dit que les pointeurs nous servirons pour les classes et c'est le moment. Pour un rappel sur les notions de base des pointeurs voir [Notion de pointeur](@ref pointeurSection). Alors pourquoi a-t-on besoin de pointeur avec les classes ? Pour plusieurs raisons mais en voici une très concrète. Imaginons que je veuille faire une liste chaînée pour stocker des entiers. Pour cela il me suffit de faire une classe `Node` qui représentera un élément de la liste. 

Cette classe `Node` doit avoir pour attributs de classe : 

- Un entier : la valeur à stocker 
- L'élément suivant dans la liste. 

Une solution que nous pourrions envisager est la suivante : 

\snippet ./src/bad_list.cpp node 

Cette solution présente deux problèmes : 

- Tout d'abord elle ne compile pas, oui c'est un problème, car on ne peut pas dans une classe `A` définir comme attribut une instance de la même classe.
- Même si le code compilait, à l'instanciation d'une instance de Node nous aurions un léger problème. En effet la création d'un `Node` entraînerait la création de son attribut `Node` qui lui-même créerait son attribut `Node` et ainsi de suite ... 

Donc si on veut pouvoir stocker en attribut le lien vers l'élément suivant de la liste pas le choix il nous faut en pratique avoir un pointeur vers l'élément suivant. 

\snippet ./src/good_list.cpp node 

Nous pourrons alors dynamiquement ajouter des éléments dans la liste en allouant des instances de `Node` et en les attachant au noeud précédent. Cela pourrait donner par exemple : 

\snippet ./src/good_list.cpp node2 

La méthode `append` va donc allouer un nouvel objet `Node` et faire pointer `next_` vers ce nouvel élément. Cependant cela ne fonctionnera ici que pour une liste de deux éléments. Afin de faire une vraie liste chaînée il est impératif que la méthode `append` soit récursive. Pour cela il faut appeler la méthode `append` de `next_` si ce dernier n'est pas le pointeur nul `nullptr`. 

Mais au fait comment j'appelle une méthode de classe lorsque je n'ai qu'un pointeur vers mon instance de classe ? Une première solution serait de déréférencer le pointeur en utilisant `*` par exemple : 

```
(*next_).append(x)
```

Mais le `C++` nous offre une manière un peu plus simple de faire cela via l'opérateur `->`. Cela donne par exemple : 

```
next_->append(x)
```

Si nous revenons alors à notre fonction `append` une implémentation plus correcte serait : 

\snippet ./src/good_list.cpp node3 

\snippet ./src/good_list.cpp usage1 

Si maintenant nous voulons afficher le contenu de la liste. Nous pourrions définir une méthode `print` comme suit : 

\snippet ./src/good_list.cpp node4

\snippet ./src/good_list.cpp usage2 


```
1, 2, 3,
```

Vous commencez donc à voir un peu plus l'intérêt des pointeurs, je l'espère en tout cas. Nous verrons un peu plus loin qu'il y a un autre intérêt lié à l'héritage et au polymorphisme ! Mais en attendant ... Je vous encourage à faire un tour sur cet [exercice](@ref TPList) et [celui ci](@ref TPList2)

## Notion de destructeur 

Nous allons à présent aborder une autre notion essentielle des classes en `C++` il s'agit du destructeur. Le destructeur porte bien son nom puisqu'il s'agit de la méthode qui est appelée lorsqu'un objet est détruit. La définition du destructeur d'une classe se fait, de manière similaire au constructeur, en définissant une méthode de classe qui ne renvoie rien et s'appelle forcément comme la classe mais préfixée par un `~`. 

Par exemple pour notre classe `Point` la définition du destructeur se fait de la manière suivante : 

\snippet ./src/destructor_example.cpp point

Ici le destructeur ne fait qu'afficher un message lorsqu'il est appelé. Regardons par exemple ce que cela donne dans le code simpliste suivant : 

\snippet ./src/destructor_example.cpp usage

À l'exécution nous obtenons alors la sortie suivante : 

```
start new scope
Dans le destructeur de Point
stop new scope
```

Nous pouvons donc constater que le destructeur est appelé automatiquement à la fin du scope d'existence de `pa`. 

**Remarque :** le destructeur, contrairement aux constructeurs, ne peut prendre aucun argument en entrée ! Il n'y a donc qu'un seul et unique destructeur par classe. 

Mais quel est l'intérêt du constructeur ? Alors oui afficher un message ne semble pas être un intérêt très pertinent. Pour la class `Point` telle que nous l'avons faite jusqu'à maintenant il n'y a aucun intérêt à définir un destructeur et nous ne devons surtout pas faire des choses inutiles. Ok mais alors dans quels cas on doit faire un destructeur ? La règle est d'une simplicité absolue ! Il faut se préoccuper du destructeur d'une classe dès que cette dernière fait des allocations dynamiques de mémoire et donc manipule des pointeurs (bon c'est vrai, il peut exister d'autres opérations faites dans un constructeur qui demandent à être correctement défaites comme l ouverture d'un fichier... mais restons sur l'exemple de l'allocation dynamique).  

Considérons les deux classes `Jedi` et `LightSaber`. La classe `Jedi` a un attribut pointeur vers un sabre laser. Les plus attentifs remarqueront que j'utilise ici des pointeurs nus, c'est fait exprès. Dans le constructeur de la classe `Jedi` je fais une allocation dynamique, à l'aide d'un `new`, pour créer le sabre laser associé. Considérons maintenant le cas où je ne fais rien de particulier pour les destructeurs : 

\snippet ./src/bad_destructor.cpp example

Si j'exécute le code suivant 

\snippet ./src/bad_destructor.cpp usage

Voici la sortie : 

```
Jedi with light saber blue constructor 
LightSaber blue constructor
Jedi with light saber green constructor 
LightSaber green constructor
Jedi destructor
Jedi destructor
```

Est-ce qu'il n'y aurait pas un léger problème ? Non ? Et bien si ! Car on voit bien le message suite à l'appel du destructeur de `Jedi` en revanche aucun message disant qu'on aurait bien appelé le destructeur de `LightSaber`. Et c'est normal car on ne l'a pas fait et le `C++` ne le fera pas pour nous. Tout ce que fait le `C++` c'est détruire le pointeur `weapon_` mais il ne détruit pas la mémoire associée. On a donc ce qu'on appelle une fuite mémoire (memory leak) ! Du coup si on veut faire les choses proprement il faut, dans le destructeur de `Jedi`, appeler le destructeur de l'instance de `LightSaber` pointée par `weapon_`. Cela se fait simplement avec le mot clé `delete` : 

\snippet ./src/good_destructor.cpp example

\snippet ./src/good_destructor.cpp usage

```
Jedi with light saber blue constructor 
LightSaber blue constructor
Jedi with light saber green constructor 
LightSaber green constructor
Jedi destructor
LightSaber green destructor
Jedi destructor
LightSaber blue destructor
```

Nous sommes maintenant dans une situation plus propre car on constate bien que l'on appelle les destructeurs des sabres lasers ainsi toute la mémoire allouée dynamiquement est détruite et nous n'avons plus de fuite mémoire. Mais il existe une solution plus simple... Et oui il s'agit pour cela d'utiliser les choses modernes du `C++` à savoir les `std::unique_ptr` et `std::shared_ptr`. En effet ces pointeurs intelligents ont l'extrême gentillesse de savoir quand détruire la mémoire qui leur est associée. Si l'on refait la classe `Jedi` en utilisant un `std::unique_ptr<LightSaber>` par exemple : 

\snippet ./src/ptr_destructor.cpp example

Et bien nous n'avons plus besoin de nous préoccuper du destructeur. Et à l'usage : 

\snippet ./src/ptr_destructor.cpp usage

on obtient la sortie correspondant au comportement souhaité : 

```
Jedi with light saber blue constructor 
LightSaber blue constructor
Jedi with light saber green constructor 
LightSaber green constructor
Jedi destructor
LightSaber green destructor
Jedi destructor
LightSaber blue destructor
```

En conclusion : 
- Il faut commencer à se préoccuper du destructeur d'une classe uniquement lorsqu'il y a des allocations dynamiques au sein de cette dernière 
- De préférence il vaut mieux utiliser les `std::unique_ptr` et `std::shared_ptr` qui vous permettront de supprimer les fuites mémoires sans avoir besoin de vous préoccuper trop des destructeurs. 

# Surcharge d'opérateur 

Maintenant que l'on sait définir des classes nous allons voir comment rendre ces classes plus facilement utilisable en définissant un certain nombre d'opérations "standards". Pour cela nous allons voir le concept de surcharge d'opérateur. Le principe est très simple, tout est dans le nom, il s'agit de redéfinir le comportement d'opérateur spécifiquement pour nos objet. Il est possible en c++ de surcharger différents types d'opérateurs : 

- Opérateurs mathématiques : `+`, `-`, `*`, `/`
- Opérateurs booléen : `==`, `>=`, `>`, `<=`, `<`
- Opérateur d'affectation : `=`
- Opérateur d'accès : `(...)`, `[]`


## Opérateur d'affectation 

\snippet ./src/point_overload.cpp assignement 

\snippet ./src/point_overload.cpp assignement_impl 

## Opérateurs booléen

\snippet ./src/point_overload.cpp equality 

\snippet ./src/point_overload.cpp equality_impl

\snippet ./src/point_overload.cpp comparison

\snippet ./src/point_overload.cpp comparison_impl

## Opérateurs mathématiques 
\snippet ./src/point_overload.cpp operations

\snippet ./src/point_overload.cpp operations_impl

## Opérateurs d'accès 

\snippet ./src/point_overload.cpp access

\snippet ./src/point_overload.cpp access_impl


## Surcharge par l'exterieur (friend) 

La grande question que l'on peut se poser maintenant est comment faire si je dois surcharger un opérateur en dehors de la classe ? Et bien c'est tout à fait possible mais il faut cependant faire attention au fait que si on définit un opérateur en dehors de la classe alors au sein de la définition de l'opérateur nous n'avons plus accès aux attributs/méthodes protected ou private de la classe ! Il existe néanmoins un moyen de contourner cela en utilisant l'instruction `friend`. Cette instruction permet de déclarer dans une classe qu'une fonction est "amie" et donc qu'au sein de cette fonction nous avons le droit d'accéder aux éléments protected/private de la classe. 

### Flux 

Par exemple un cas où nous sommes obligé de définir l'opérateur en dehors de la classe c'est pour la surcharge de l'opérateur de flux `<<` qui nous permet en autre de faire du `std::cout` sur notre objet. 

\snippet ./src/point_overload.cpp flux_impl

Pour que l'implémentation que l'on propose ici fonctionne il est nécessaire içi que l'on puisse accéder aux éléments protected de la classe `Point` et donc que la surcharge de l'opérateur soit déclarée comme `friend` dans la classe `Point` : 

\snippet ./src/point_overload.cpp flux

### Opération mathématique 

Il est également possible de surcharger les opérateurs mathématiques en dehors de la classe. C'est même obligatoire dans l'exemple suivant par exemple où on veut définir l'opération `*` entre un `double` et un `Point`, ce qui n'est pas la même chose qu'entre un `Point` et un `double`. Là encore nous devons définir notre opérateur comme `friend` dans la classe `Point`. 

\snippet ./src/point_overload.cpp math2

\snippet ./src/point_overload.cpp math2_impl


# Héritage 

## Classe mère, classe fille 

Nous allons à présent rentrer dans le coeur du sujet de la programmation orientée objet avec la notion d'heritage. Le principe de l'héritage est très simple est consiste a créer des hiérarchies de classes qui ont des liens logiques. Autrement dit l'idée va être de créer une classe de base générique, que l'on appelera par la suite classe mère, et à partir de cette classe mère de faire différentes classes filles qui correspondent chacune à une spécialisation. 

Pour définir une classe fille à partir d'une classe mère la syntaxe est la suivante : 

```
class Fille: public Mere{

};
```


Par exemple si je reprend l'exemple de la classe `Jedi` que j'ai utilisé plus haut. Je peux très bien me dire que la classe Jedi est une classe générique et je vais la spécialisée en créant trois classes filles : 

- `Padawan` : les apprentis Jedi 
- `Knight` : les chevaliers Jedi 
- `Master` : les maitres Jedi 

Ces trois classes filles ont comme lien le fait qu'il s'agit dans les trois cas de Jedi. Et donc par exemple les padawan, chevalier ou maitres ont tous un sabre laser. 

Considérons par exemple l'implémentation suivante de la classe `Jedi`
\snippet ./src/jedi_base.cpp jedi 

Nous pouvons à partir de `Jedi` définir la classe fille `Padawan` de la manière suivante : 

\snippet ./src/jedi_base.cpp padawan

Et également les classes `Knight` et `Master`. 

\snippet ./src/jedi_base.cpp knight

\snippet ./src/jedi_base.cpp master

Le premier intérêt de l'héritage est que l'on dispose dans les classes filles des méthodes et attributs définis au niveau de la classe mère. Par exemple nous pouvons utiliser sur un `Padawan`, `Knight` ou `Master` la méthode `info()` : 

\snippet ./src/jedi_base.cpp usage

```
I am a Jedi with a blue light saber
I am a Jedi with a blue light saber
I am a Jedi with a green light saber
```

Le second intérêt de l'héritage est alors que l'on peut redéfinir pour chaque classe fille un comportement particulier. Par exemple nous pouvons spécifier la méthode `info` pour chacune des classes  filles. 

\snippet ./src/jedi_base2.cpp padawan

\snippet ./src/jedi_base2.cpp knight

\snippet ./src/jedi_base2.cpp master

Ainsi nous avons pour chacune de nos classes filles définit un comportement particulier pour `info()` 

\snippet ./src/jedi_base2.cpp usage

```
I am a Padawan with a blue light saber
I am a Jedi Knight with a blue light saber
I am a Jedi Master with a green light saber
```

# Polymorphisme 

## Un mot compliqué pour un truc simple 

Nous allons maintenant abordé un point particulier de la programmation orientée objet en C++, la notion de Polymorphisme. Qu'est ce que ça veut dire ??? Le principe est simple en réalité, mais le mot compliqué peut faire bien dans une conversation ;), l'idée du polymorphisme est d'avoir un mécanisme qui va nous permettre de faire passer une classe fille pour sa mère ! Ok mais pourquoi on a besoin de ça ? La réponse est simple, c'est pour ne pas devoir ré-implémenter 20 fois les mêmes fonctions pour des arguments d'entrée différents. Par exemple reprenons nos classes `Jedi`, `LightSaber` et compagnie 

\snippet ./src/polymorphism_example.cpp classes

Nous pouvons voir que nos trois classes filles ont toutes en communs une méthode `info()` qui suivant l'objet considéré affichera un certain message. 

Maintenant imaginons que l'on veuille faire une fonction `callInfo` qui prend en argument une instance d'une classe fille de Jedi. Comment feriez vous cela ? Une solution pourrait être d'utiliser la surcharge de fonction et donc de définir trois versions de `callInfo` : (i) `callInfo(Padawan&)` ; (ii) `callInfo(Knight&)` ; (iii) `callInfo(Master&)`. Ca marche mais ça manque un peu d'élégance non ? Il existe une autre solution qui est de définir : 

\snippet ./src/polymorphism_example.cpp call_info 

Et ensuite à l'usage cela donne : 

\snippet ./src/polymorphism_example.cpp call_info 

Wait, wait !!! On a le droit d'appeler `callInfo(Jedi&)` avec autre chose qu'un `Jedi` ? Eh bien oui on a le droit car on n'appelle pas la fonction sur n'importe quoi non plus ! Nos arguments sont des `Padawan`, `Knight` et `Master` qui héritent tous les trois de `Jedi`. Donc pour le compilateur, loué soit-il, un `Padawan` est un `Jedi` donc ça marche ! Enfin ça marche ... presque car si on regarde le résultat du code précédent on obtient : 

```
I am a Padawan with a blue light saber
In callInfo: I am a Jedi with a blue light saber
I am a Jedi Knight with a blue light saber
In callInfo: I am a Jedi with a blue light saber
I am a Jedi Master with a green light saber
In callInfo: I am a Jedi with a green light saber
```

C'est pas tout a fait ce qu'on attendait ... Car vous voyez dans `callInfo(Jedi& j)` l'appel à `j.info()` appelle la version de la méthode `info()` définie dans la classe de base `Jedi` et pas les versions re-définies dans les classes filles. C'est pas vraiment ce qu'on veut ! Mais pas d'inquiétude ! Il y a bien évidemment une combine magique pour que ça marche il s'agit des méthodes virtuelles. 

## Méthodes virtuelle

Nous venons de le voir grace au polymorphisme nous pouvons dire qu'un `Padawan` est un `Jedi` par exemple mais en faisant cela on perd en quelque sorte l'information que la variable que l'on manipule est un `Padawan`. Par exemple 

\snippet ./src/polymorphism_example.cpp call_info 

Ce qui nous donne comme résultat : 

```
I am a Padawan with a blue light saber
I am a Jedi with a blue light saber
```

C'est vraiment pas ce qu'on veut. Ce que l'on veut en réalité c'est qu'il y est un mécanisme de vérification dynamique, donc à l'exécution et pas à la compilation, qui au moment de l'appel à la méthode info regarde un peu plus en détail le contexte dans lequel cette méthode est appelé pour si besoin aller chercher la bonne version dans une des classes filles. Et bien surprise cce mécanisme existe il suffit pour cela de déclarer la méthode considéré comme virtuelle et cela se fait simplement avec le mot clé virtual devans la déclaration de la méthode dans la classe mère. Par exemple dans notre cas : 

\snippet ./src/polymorphism_example2.cpp classes

Au passage vous remarquez que j'ai dans mon exemple déclarer comme `virtual` la méthode `info` dans `Jedi` mais également dans les classes filles `Padawan`, `Knight`, `Master`. En réalité ce n'est pas nécessaire, il suffit uniquement de le déclarer dans la classe mère. Mais dans les faits je vous invite, par souci de clarté du code, à remettre les virtual dans les classes filles. 

Et alors le simple fait d'ajouter le `virtual` devant `info` fait que le code suivant : 

\snippet ./src/polymorphism_example2.cpp reference

Nous donne le bon résultat à savoir : 

```
I am a Padawan with a blue light saber
I am a Padawan with a blue light saber
```

De la même manière si on utilise maintenant la fonction `callInfo(Jedi&)` : 

\snippet ./src/polymorphism_example2.cpp usage 

on obtient le résultat escompté : 

```
I am a Padawan with a blue light saber
In callInfo: I am a Padawan with a blue light saber
I am a Jedi Knight with a blue light saber
In callInfo: I am a Jedi Knight with a blue light saber
I am a Jedi Master with a green light saber
In callInfo: I am a Jedi Master with a green light saber
```
### Qualificateur override et final 

Depuis la norme 2011 du C++ il existe pour les méthodes virtuelles deux mots clé additionnels : (i) `override` ; (ii) `final` qui permettent d'expliciter certaines chose et ainsi limiter les erreurs de programmation. Par exemple reprenons notre classe `Jedi` avec la méthode `info` déclarée comme `virtual`. 

\snippet ./src/polymorphism_example3.cpp jedi 

Implémentons maintenant notre classe `Padawan`, attention il y a une erreur ;)  

\snippet ./src/polymorphism_example3.cpp padawan

Et si maintenant j'utilise tout ça 

\snippet ./src/polymorphism_example3.cpp reference

```
I am a Padawan with a blue light saber
I am a Jedi with a blue light saber
```

C'est le drame ça ne fonctionne plus comme il faut !!!! Pourtant j'ai bien mis `info` comme méthode virtuelle ! Que se passe-t-il ? Pas d'idée ? Et bien c'est simple dans `Jedi` j'ai défini la méthode `virtual void info() const` tandis que dans `Padawan` j'ai défini `virtual void info()`. Il manque le `const` dans ma classe fille et du coup pour le c++ la méthode `info` de la classe mère n'est pas redéfinit dans la classe fille donc il prend celle de la classe mère ! Certains diraient que le diable est dans les détails. 

C'est pour éviter de tomber dans ce cas qu'il existe le mot-clé `override` le principe est que si dans la déclaration d'une fonction virtuelle dans une classe **fille** j'ajoute le qualificateur `override` alors la méthode que je suis en train de définir doit forcément exister dans la classe mère. Ce qui n'était pas le cas dans mon exemple. Donc si je reprend ma classe `Padawan` en ajoutant le `override` qui va bien 

\snippet ./src/polymorphism_example3.cpp padawan2

j'obtiens l'erreur de compilation suivante : 

```
polymorphism_example3.cpp:48:22: error: ‘virtual void Padawan::info()’ marked ‘override’, but does not override
   48 |         virtual void info() override {
```

Alors que si je remets le `const` qui va bien dans `Padawan` le `override` ne provoque plus d'erreur de compilation et tout refonctionne comme avant : 


\snippet ./src/polymorphism_example3.cpp padawan2


L'autre qualificateur spécifique aux méthodes virtuelles est le `final`. Lui a porte rôle de mettre fin à la possibilité de surcharger une fonction virtuelle dans une classe fille. Par exemple imaginons que je déclare la méthode `info` comme `final` dans la classe `Knight` et bien si je définis une classe fille à `Knight` par exemple `KnightAtJediCouncil` qui représenterai un chevalier qui siègerait au conseil des Jedi (chose très rare). Dans ce cas je ne pourrai plus redéfinir la méthode `info` dans `KnightAtJediCouncil`. 

\snippet ./src/polymorphism_example3.cpp knight

\snippet ./src/polymorphism_example3.cpp knight_at_council

Ce code engendre alors l'erreur de compilation suivante : 

```
polymorphism_example3.cpp:78:22: error: virtual function ‘virtual void KnightAtJediCouncil::info() const’ overriding final function
   78 |         virtual void info() const {
      |                      ^~~~
polymorphism_example3.cpp:69:22: note: overridden function is ‘virtual void Knight::info() const’
   69 |         virtual void info() const override final {
      |                      ^~~~
```


### Classe abstraite 





## Destructeur virtuel 

## Faire du polymorphisme sans héritage c'est possible ! 

Maintenant que nous avons vu les grands classiques du C++ avec l'héritage, le polymorphisme et les fonctions virtuelles prenons un peu de temps pour nous intéresser à un truc qui sort du cadre standard !! Considérons trois classes `A`, `B`, `C` qui n'ont entre elles aucun lien, pas d'héritage, mais qui auraient le bon goût d'offrir la même interface à savoir dans notre cas une méthode `print`. 

\snippet variant_example.cpp classes

Dans ce cas, une possibilité depuis la norme 2017 du C++ est d'utiliser le type `std::variant`, disponible dans la librairie `<variant>`, qui permet d'encapsuler plusieurs types. L'utilisation se fait de la manière suivante 

```
std::variant<type1, type2, ...> variable_name; 
```

Par exemple dans le cas de nos trois classes `A`, `B` et `C` nous pouvons l'utiliser de la manière suivante : 

\snippet variant_example.cpp variant

Ainsi nous pouvons créer une variable `ptr` qui va contenir un pointeur vers une instance de `A` ou une instance de `B` ou une instance de `C`. On obtient donc le même résultat qu'avec de l'héritage "standard". Là où la distinction est plus marquée c'est sur l'appel des méthodes. Par exemple pour appeler la méthode `print` nous ne pouvons pas faire `ptr->print()` comme nous le ferions avec un pointeur. Il faut passer par l'utilisation de la fonction `std::visit` qui va prendre en entrée une fonction (la plupart du temps anonyme) et le `std::variant`. Par exemple cela donne : 

\snippet variant_example.cpp visitor 

Vous remarquerez l'usage du `auto` qui traduit le fait qu'on utilise ici une fonction générique et surtout de la syntaxe `auto&&`. Le `&&` signifie que l'on passe l'argument comme une `rvalue`, c'est-à-dire que l'argument d'entrée peut-être un objet temporaire. Pour plus de détail sur le principe des r-value je vous invite à jeter un oeil sur [https://en.cppreference.com/w/cpp/language/reference](https://en.cppreference.com/w/cpp/language/reference). 

Une fois notre `std::variant` déclarer nous pouvons à tout moment lui affecter un nouveau contenu correspond à l'un des types autorisé : 

\snippet variant_example.cpp again 


## Le polymorphisme un coût en plus ? 

Nous venons donc de voir qu'avec l'héritage et les fonctions virtuelles il est possible d'élaborer des architectures relativement complexes mais que visiblement il est également possible de le faire sans en utilisant les `std::variant`. La question que l'on peut alors se poser est si les deux approches sont équivalentes ou pas ? En terme d'usage nous avons bien vu que non, personnellement j'aurai tendance à dire que l'approche par héritage avec des fonctions virtuelles est plus simple. Mais est-ce qu'au niveau des performances c'est la même chose ? Et bien la réponse est non pas tout à fait. Car, attention grosse révélation, le polymorphisme c'est vachement pratique et permet de faire des choses très souples mais ça à un coût ! Vraiment ? Oui vraiment car le principe du polymorphisme est le suivant : 

Pour chaque classe dérivée, il existe en interne une structure de données qui s'appelle la `vtable` pour virtual table. L'objectif de la vtable est de contenir le pointeur vers les fonctions `virtual`. A chaque appel d'une fonction virtuelle, le C++ doit donc : 

1. charger la vtable de l'objet considéré, 
2. trouver dans la vtable le pointeur vers la fonction virtuelle que l'on appelle 
3. charger la fonction virtuelle dans le cache d'instruction 
4. exécuter la fonction 

C'est totalement transparent pour nous évidemment, mais toutes ces opérations ont un coût. Tandis qu'avec une approche à base de std::variant la mise en oeuvre peut nécessiter un peu plus de travail de la part du développeur mais le surcoût est moindre car pas de jeu de pointeur. 

Pour vous en assurer, voici ci-dessous un benchmark comparant l'approche héritage classique, de l'approche `std::variant`. 

\htmlonly
<iframe width="100%" height="800px" src="https://quick-bench.com/q/wybWwNqbHOIodMDunQO8DFplua0"></iframe>
\endhtmlonly


**Attention :** l'objectif n'est pas de dire qu'il faut faire du std::variant tout le temps et jamais d'héritage ! Comme pour beaucoup de chose ça dépend de votre problématique ! Mais dans la plupart des cas vous avez certainement plein d'autre piste d'optimisation à explorer avant de ne vous lancer dans la suppression de l'héritage ;) 


# Subtilitée : convertir this en shared_ptr 

Alors juste une petite subtilité du C++ moderne, j'en parle car on peut vite y arriver... Nous avons vu jusqu'à maintenant que le C++ depuis la norme 2011 offre tout un tas d'outils super sympa, notamment les `std::shared_ptr`. Or il se peut que vous soyer amené assez rapidement a essayer de faire quelque chose du genre : 

\snippet ./src/astuce.cpp main 

Cela peut sembler une bonne idée, cependant à l'exécution on obtient le message, peu sympatique suivant : 

```
double free or corruption (out)
Aborted (core dumped)
```

Néanmoins pas d'inquiétude il existe bien évidemment un moyen de faire cela. Il faut cependant faire un petit effort pour que cela fonctionne. En effet la librairie `<memory>` met à disposition une classe, qui porte très bien son nom, `std::enable_shared_from_this`. Difficile de faire plus explicite comme nom. Pour que vous puissiez convertir votre pointeur nu `this` comme un `std::shared_ptr` il faut que votre classe hérite de la classe `enable_shared_from_this`. Alors attention à l'usage !! Dans notre exemple cela donne quelque chose du genre :  

\snippet ./src/astuce_work.cpp main 

Donc vous voyez deux choses : 

* Pour convertir `this` en `std::shared_ptr<A>` on appelle la méthode `shared_from_this()` dont on hérite de la classe `std::enable_shared_from_this`. 
* Au niveau de l'héritage vous voyez la syntaxe bizarre `class A: public std::enable_shared_from_this<A>`. On peut traduire cela en la classe `A` hérite de la classe `std::enable_shared_from_this` qui est templatée par `A`.... c'est louche non ? Alors oui un peu mais c'est un pattern plutôt standard, c'est ce qu'on appelle un CRTP (Curiously Recuring Template Parameter) nous verrons dans le chapitre suivant sur les templates qu'il y a beaucoup de possibilité offerte par ce pattern.  



# Pour le fun : type litterals 




