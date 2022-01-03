
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

### Constructeur de copie 

Parmis les constructeurs possibles et imaginable il en existe un qui est un peu particulier, il s'agit du constructeur de copie. Par exemple c'est ce constructeur qui sera appelé si nous voulons faire : 

\snippet ./src/copy_constructor.cpp copy 

Dans ce cas nous devons définir un constructeur qui va prendre comme argument d'entrée une instance de `Point`. Attention sur comment on fournit cet argument d'entrée. Si on ne réfléchit pas nous pourrions faire quelque chose du genre 

\snippet ./src/copy_constructor.cpp bad_idea 


Mais cela ne va compiler et c'est normal !! Pourquoi ?????? Et bien simplement parce que je vous le rappel par défaut le passage d'argument se fait par copie en C++. Or si pour appeler le constructeur de copie il faut commencer par faire une copie c'est un peu bizarre non ? Donc le constructeur de copie a toujours un prototype de la forme suivante : 

\snippet ./src/copy_constructor.cpp good_idea 

Pourquoi le `const` ? Simplement parce que quand je fais une copie de `other` il n'y a aucune raison pour que le fait de faire une copie modifie l'objet. Au niveau de l'implémentation de ce constructeur de copie nous pouvons alors faire quelque chose du genre : 

\snippet ./src/copy_constructor.cpp copy_constructor

### Laisser faire ou le compilateur ou lui imposer des choses ! 

Au niveau des constructeurs nous avons vu lorsque nous avons fait la première version de notre classe `Point` que le compilateur nous génère le constructeur par défaut si besoin ainsi que le constructeur de copie et l'opérateur d'affectation. Cependant cela est vrai tant qu'on ne définit aucun constructeur. A partir du moment ou vous avez défini un constucteur quelqu'il soit le compilateur ne fait plus rien pour nous.... On peut cependant lui demander gentiment de quand même générer ses constructeurs par défaut en utilisant le mot-clé `default`. 

\snippet ./src/default_delete_example.cpp default 


Dans un esprit similaire nous pouvons demander explicitement qu'un constructeur par défaut ne soit pas défini, par exemple si on souhaite empêcher la copie de nos objet il nous suffit de dire au compilateur que le constructeur de copie ne doit jamais être défini. Cela se fait à l'aide du mot-clé `delete`. 


\snippet ./src/default_delete_example.cpp delete




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

Nous allons à présent voir le premier lien qu'il existe entre classes et pointeurs. Car depuis un moment déjà je vous dit que les pointeurs nous servirons pour les classes et c'est le moment. Pour un rappel sur les notions de base des pointeurs voir [Notion de pointeur](@ref pointeurSection). Alors pourquoi a-t-on besoin de pointeur avec les classes ? Pour plusieurs raisons mais en voici une très concrète. Imaginons que je veuille faire une liste chaînée pour stocker des entiers. Pour cela il me suffit de faire une classe `Node` qui représentera un élément de la liste. 

Cette classe `Node` doit avoir pour attibus de classe : 

- Un entier : la valeur à stocker 
- L'élément suivant dans la liste. 

Une solution que nous pourrions envisagée est la suivante : 

\snippet ./src/bad_list.cpp node 

Cette solution présente deux problèmes : 

- Tout d'abord elle ne compile pas, oui c'est un problème, car on ne peut pas dans une classe `A` définir comme attribut une instance de la même classe.
- Même si le code compilait, à l'instanciation d'une instance de Node nous aurions un léger problème. En effet la création d'un `Node` entrainerait la création de son attribut `Node` qui lui-même créerait son attribut `Node` et ainsi de suite ... 

Donc si on veut pouvoir stocker en attribut le lien vers l'élément suivant de la liste pas le choix il nous faut en pratique avoir un pointeur vers l'élément suivant. 

\snippet ./src/good_list.cpp node 

Nous pourrons alors dynamiquement ajouter des éléments dans la liste en allouant des instances de `Node` et en les attachants au noeud précédent. Cela pourrait donner par exemple : 

\snippet ./src/good_list.cpp node2 

La méthode `append` va donc allouer un nouvel objet `Node` et faire pointer `next_` vers ce nouvel élément. Cependant cela ne fonctionnera ici que pour une liste de deux éléments. Afin de faire une vraie liste chaînée il est impératif que la méthode `append` soit récursive. Pour cela il faut appeler la méthode `append` de `next_` si ce dernier n'est pas le pointeur nul `nullptr`. 

Mais au fait comment j'appelle une méthode de classe lorsque je n'ai qu'un pointeur vers mon instance de classe ? Une première solution serait de déréférencer le pointeur en utilisant `*` par exemple : 

```
(*next_).append(x)
```

Mais le C++ nous offre une manière un peu plus simple de faire cela via l'opérateur `->`. Cela donne par exemple : 

```
next_->append(x)
```

Si nous revenons alors à notre fonction append une implémentation plus correcte serait : 

\snippet ./src/good_list.cpp node3 

\snippet ./src/good_list.cpp usage1 

Si maintenant nous voulons afficher le contenu de la liste. Nous pourrions définir un méthode `print` comme il suit : 

\snippet ./src/good_list.cpp node4

\snippet ./src/good_list.cpp usage2 


```
1, 2, 3,
```

Vous commencez donc à voir un peu plus l'intérêt des pointeurs, je l'espère en tout cas. Nous verrons un peu plus loin qu'il y a un autre intérêt lié à l'héritage et au polymorphisme ! Mais en attendant ... Je vous encourage à faire un tour sur cet [exercice](@ref TPList) et [celui ci](@ref TPList2)

## Notion de destructeur 

Nous allons à présent aborder une autre notion essentielle des classes en C++ il s'agit du destructeur. Le destructeur porte bien son nom puisqu'il s'agit de la méthode qui est appelée lorsqu'un objet est détruit. La définition du destructeur d'une classe se fait, de manière similaire au constructeur, en définissant une méthode de classe qui ne renvoie rien et s'appelle forcément comme la classe mais préfixée par un `~`. 

Par exemple pour notre classe `Point` la définition du destructeur se fait de la manière suivante : 

\snippet ./src/destructor_example.cpp point

Ici le desctucteur ne fait qu'afficher un message lorsqu'il est appelé. Regardons par exemple ce que cela donne dans le code simpliste suivant : 

\snippet ./src/destructor_example.cpp usage

A l'exécution nous obtenons alors la sortie suivante : 

```
start new scope
Dans le destructeur de Point
stop new scope
```

Nous pouvons donc constater que le destructeur est appelé automatique à la fin du scope d'existance de `pa`. 

**Remarque :** le destructeur, contrairement aux constructeurs, ne peut prendre aucun argument en entrée ! Il n'y a donc qu'un seul et unique destructeur par classe. 

Mais quel est l'intérêt du constructeur ? Alors oui afficher un message ne semble pas être un intérêt très pertinent. Alors pour la class `Point` telle que nous l'avons faites jusqu'à maintenant il n'y a aucun intérêt à définir un destructeur. Ok mais alors dans quel cas on doit faire un destructeur ? La rêgle est d'une simplicité absolue ! Il faut se préocuper du destructeur d'une classe dès que cette dernière fait des allocations dynamiques de mémoire et donc manipule des pointeurs.  

Considérons par exemple les deux classes `Jedi` et `LightSaber`. La classe jedi a un attribut pointeur vers un sabre laser. Les plus attentifs remarqueront que j'utilise ici des pointeurs nus, c'est fait exprès. Dans le constructeur de la classe `Jedi` je fais une allocation dynamique, à l'aide d'un `new`, pour créer le sabre laser associé. Considérons maintenant le cas où je ne fais rien de particulier pour les destructeurs : 

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

Est-ce qu'il n'y aurait pas un léger problème ? Non ? Et bien si ! Car on voit bien le message suite à l'appel du destructeur de `Jedi` en revanche aucun message disant qu'on aurait bien appelé le destructeur de `LightSaber`. Et c'est normal car on ne l'a pas fait et le C++ ne le fera pas pour nous. Tout ce que fait le C++ c'est détruire le pointeur `weapon_` mais il ne détruit pas la mémoire associée. On a donc ce qu'on appelle une fuite mémoire ! Du coup si on veut faire les choses proprement il faut dans le destructeur de `Jedi` appelé le destructeur de l'instance de `LightSaber` pointée par `weapon_`. Cela se fait simplement avec le mot clé `delete` : 

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

Nous sommes maintenant dans une situation plus propre car on constate bien que l'on appelle les destructeurs des sabres lasers ainsi toute la mémoire allouée dynamiquement est détruite et nous n'avons plus de fuite mémoire. Mais il existe une solution plus simple... Et oui il s'agit pour cela d'utiliser les choses modernes du C++ à savoir les `std::unique_ptr` et `std::shared_ptr`. En effet ces pointeurs intelligents ont l'extrème gentillesse de savoir quand détruire la mémoire qui leurs est associée. Si l'on refait la classe `Jedi` en utilisant un `std::unique_ptr<LightSaber>` par exemple : 

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
- De préférence il vaut mieux utiliser les `std::unique_ptr` et `std::shared_ptr` qui vous permettront de supprimer les fuites mémoires sans avoir besoin de vous préoccuper trop des constructeurs. 


# Surcharge d'opérateur 

## Opérateur d'affectation 

\snippet ./src/point_overload.cpp assignement 

\snippet ./src/point_overload.cpp assignement_impl 

## Opérateurs mathématiques 

\snippet ./src/point_overload.cpp equality 

\snippet ./src/point_overload.cpp equality_impl

\snippet ./src/point_overload.cpp comparison

\snippet ./src/point_overload.cpp comparison_impl


\snippet ./src/point_overload.cpp operations

\snippet ./src/point_overload.cpp operations_impl

## Opérateurs d'accès 

\snippet ./src/point_overload.cpp access

\snippet ./src/point_overload.cpp access_impl



# Héritage 

## Classe mère, classe fille 

## Méthodes virtuelle 

## Destructeur virtuel 

# Polymorphisme 

## Un mot compliqué pour un truc simple 

## Le polymorphisme un coût en plus ? 

## Faire du polymorphisme sans héritage c'est possible ! 


# Pour le fun : type litterals 




