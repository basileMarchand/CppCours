
Les pointeurs    {#pointeurSection}
=============

[TOC]


# Les pointeurs, la terreur des apprentis c++  

## Manipuler la mémoire plutôt que la valeur 

Dans cette partie nous allons voir **LE** truc du c++ qui fait peur à tous les apprentis programmeurs lorsqu'il se lance dans ce langage. La notion de pointeur ! Mais c'est quoi un pointeur ? Avant de répondre à cette question revenons un peu aux fondamentaux. 

Nous avons vu il y a longtemps maintenant que la mémoire vive de votre ordinateur est organisée en une multitude de cases chaque case faisant huit bits ou 1 octet. Lorsque l'on créé une variable en C++, par exemple un `double` que l'on appelerait `monDouble` caché derrière il y a un processus d'allocation mémoire qui vient prendre dans la RAM le nombre de case nécessaire pour stocker un double, à savoir 64 bits donc 8 octets. La valeur de notre variable `monDouble` est alors stockée dans ces 8 octets. Pour finir lorsque dans le code on manipule la variable `monDouble` on récupère bien la valeur stockée par exemple `42.0`. 

\snippet ./src/intro.cpp base 

```
monDouble = 42
```

Donc pour le moment l'aspect gestion de la mémoire est en réalité totalement transparent pour vous n'est ce pas ? Si on regarde un peu plus dans le détail. Nous pouvons en C++ demander à afficher l'adresse mémoire d'une variable, c'est-à-dire l'adresse de la case en mémoire où commence le stockage de la valeur associée à la variable. Pour cela il suffit de préfixer le nom de la variable par le symbole `&`. 

\snippet ./src/intro.cpp address

Cela nous retourne alors à l'exécution le message suivant : 

```
addresse de monDouble: 0x7fffe281b678
```

Ainsi nous pouvons voir que notre variable `monDouble` correspond à la case mémoire numérotée `0x7fffe281b678`. Vous pourriez me dire c'est bien joli mais je vois pas bien ce que je vais en faire ... Et pour le moment je ne peux qu'être d'accord avec vous ! 

Mais nous allons voir très bientôt que l'objectif ne va pas être d'afficher des adresses de variables mais de stocker ces addresses dans des variables différentes. **C'est ce qu'on va appeler un pointeur**.

## L'intéret des pointeurs 

Ok mais à quoi ça va me servir de stocker l'addresse d'une variable dans une autre variable ? Et bien à plein de chose en fait. Par exemple cela nous permettra de partager entre différents endroits du code un même morceau de RAM permettant de s'affranchir de faire du passage d'argument compliqué. De plus l'autre énorme intérêt des pointeurs est de nous permettre de faire de l'allocation dynamique de la mémoire. C'est à dire que l'espace mémoire ne sera allouer qu'à l'exécution de notre programme suivant une logique interne propre à notre code faisant ainsi que tout n'est pas nécessairement alloué suivant les options d'utilisation. 

Et enfin l'autre intérêt que nous verrons dans le chapitre suivant est que la maniulation de pointeur dans le cadre de la programmation orientée objet permet d'utiliser le concept de polymorphisme qui permet de faire passer un type pour un autre sous certaines conditions. 

Comme beaucoup de chose en C++ il existe maintenant deux manières de faire des pointeurs : (i) la version historique qui vient du C ; (ii) la version moderne introduite par la norme 2011 du C++. Nous allons içi voir les deux car la version historique est encore majoritairement utilisée dans les codes que l'on peut trouver en ligne il est donc impératif de bien la comprendre. 

# Version historique, pre c++11

## Définition d'un pointeur 

En C++ historique la définition d'un pointeur, i.e. d'une variable stockant une addresse mémoire se fait en déclarant notre pointeur comme étant du type 

```
type* pointeur_vers_un_type;
```

Par exemple pour créer un pointeur vers un double : 

```
double* pointeur_vers_un_double;
```

Vous pouvez déjà remarquer qu'il n'existe pas un type pointeur mais il y en a autant que de type pointés. Pourquoi ? Alors oui c'est vrai que stricto sensus une addresse c'est une addresse peu importe que cette dernière soit associée à un `double` ou un `int` par exemple. Mais dans les faits ce n'est pas la même chose car nous le verrons très rapidement il existe un mécanisme qui permet à partir d'un pointeur d'obtenir la valeur pointée, c'est ce qu'on appelle le déréférencement de pointeur. Or pour à partir de l'addresse d'une case mémoire récupérer une valeur il faut savoir combien d'octet nous devons prendre en compte et ce nombre d'octet est en réalité intrinsèquement lié au type de la valeur pointée ! 

### Initialisation d'un pointeur 

Lorsque l'on créé un pointeur vers un entier il faut faire attention que le pointeur, comme une variable standard, n'est pas initialisé. Par exemple : 

\snippet ./src/ptr_init.cpp no_init

A l'exécution nous obtenons le résultat suivant : 

```
0x7ffe51aaec50
```

Donc notre pointeur pointe soit-disant vers une case mémoire. Mais en réalité ce qui a été fait c'est qu'il a juste été mis une addresse random dans le pointeur. Donc à l'usage cela peut s'avérer extrèmement risqué et conduire au fameux segfault. Pour cela il est donc impératif d'initialiser un pointeur dès sa décalaration. Si l'on souhaite l'initialiser pour dire que pour le moment il ne pointe vers rien de valide il existe les mots clés `NULL` ou `nullptr` depuis C++11 permettant de faire pointer le pointeur vers l'addresse spécifique `0x0`. 


\snippet ./src/ptr_init.cpp init_null

ou bien 

\snippet ./src/ptr_init.cpp init_nullptr

L'intérêt d'initialiser ses pointeur à `NULL` ou `nullptr` est qu'il est alors possible de tester dans le code si un pointeur pointe vers quelque chose ou pas.

\snippet ./src/ptr_init.cpp test_ptr

### Faire pointer un pointeur vers quelque chose d'existant 

Maintenant que l'on sait créer un pointeur il serait sympatique que l'on soit capable de le faire pointer vers quelque chose ! Pour cela c'est très simple en fait. Nous avons vu quelques lignes plus haut qu'en préfixant un nom de variable par le symbole `&` nous obtenions l'addresse mémoire de cette variable. Et bien c'est cette addresse que nous allons ranger dans notre pointeur ! 

\snippet ./src/ptr_example.cpp ptr_affectation 

Pour vérifier il nous suffit de regarder les addresses mémoires : 

\snippet ./src/ptr_example.cpp ptr_print 

ce qui nous donne à l'exécution 

```
&unEntier : 0x7ffc2d0b5534
pInt : 0x7ffc2d0b5534
```

Bien évidemment nous pourrions tout à fait initialiser directement le pointeur avec l'adresse à pointer 

\snippet ./src/ptr_example.cpp ptr_init

### Accéder à la valeur pointée : le déréférencement de pointeur 

Maintenant que nous savons créer un pointeur et le faire pointer vers une zone mémoire il serait pratique de pouvoir accéder à la valeur contenue dans la zone mémoire pointée n'est ce pas ? Et bien c'est possible sans grande difficulté. Il suffit pour cela de déréférencer le pointeur, c'est à dire demandé gentiement à interprété le contenu de la zone mémoire comme le type correspondant au pointeur. Cela se fait en préfixant le pointeur du symbole `*`. Par exemple : 

\snippet ./src/ptr_init.cpp dereferencement

A l'usage cela donne : 

```
ptrInt: 0x7fff8707567c
*ptrInt: 42
```

## Attention au segfault 

Lorsque l'on commence a jouer avec les pointeurs il faut faire attention à une chose, le segfault. Segfault est la contraction de `Segmentation Fault`. C'est l'erreur qui apparaît lorsque qu'un programme essaye d'accéder à de la mémoire qui ne lui est pas allouée. Lorsqu'on commence à mettre des pointeurs partout on joue donc avec la mémoire et si on est pas un petit peu rigoureux on se retrouve très très rapidement dans le cas où un segfault peut pointer le bout de son nez. 

Considérons par exemple le code suivant : 

\snippet ./src/segfault.cpp main 

A votre avis l'exécution de ce code se passe bien ou pas ? Naturellement non ça se passe mal : 

```
Erreur de segmentation (core dumped)
```



## Allocation mémoire 

### Les mots-clé new et delete 

\snippet ./src/alloc.cpp main 

### On peut aussi allouer des tableaux mais c'est old-school 

\snippet ./src/array.cpp allocate

\snippet ./src/array.cpp fill

\snippet ./src/array.cpp iterate

\snippet ./src/array.cpp deallocate


# Version moderne, post c++11

## La différence 

A présent nous allons voir ce que le C++ moderne nous propose comme alternative aux pointeurs classiques. Tout d'abord nous pouvons nous poser la question de pourquoi proposer une alternative ? Qu'est ce qu'il peut bien manquer aux pointeurs qui nécessiterait une autre manière de faire. C'est très simple les pointeurs classiques fonctionnent très bien mais ont le gros défaut qu'il est nécessaire une fois qu'on a fait une allocation mémoire avec un `new` de bien penser à faire le `delete` associé sinon on a des fuites mémoires. Or parfois il peut s'avérer compliqué de bien identifier à quel moment il faut faire le `delete` pour libérer la mémoire sans courrir le risque de provoquer un `segfault`.... 

La norme c++11 offre donc une surcouche aux pointeurs qui permet de ne plus se préoccuper des `delete`, c'est génial je sais ! Le principe est extrèmement simple en réalité, il suffit d'avoir en interne pour chaque zone mémoire un compteur permettant de savoir à chaque instant le nombre de pointeur pointant vers une zone et lorsque ce compteur tombe à 0 et bien là le `delete` est fait automatiquement ! 

En pratique le standard c++11 offre deux encapsulation des pointeurs : 

- Le `std::unique_ptr` 
- Le `std::shared_ptr` 

La distinction entre les deux est très simple, comme indiqué dans le nom le `unique_ptr` va servir a encapsuler un pointeur qui pointe vers une zone mémoire qui ne peut pas être partagée. Tandis que le `shared_ptr` lui correspond à un pointeur vers une zone mémoire partagée entre plusieurs `shared_ptr`. Pour utiliser ces deux types spécifiques il faut tout d'abord l'include de la librairie `memory` 

```
#include <memory>
```

## Utilisation des unique_ptr 

La déclaration d'un `std::unique_ptr` se fait simplement en suivant la syntaxe suivante : 

```
std::unique_ptr<type> ptr_name; 
```

Par exemple pour déclarer un pointeur de type entier il suffit de procéder de la manière suivante : 

\snippet ./src/unique_ptr.cpp decl 

Le premier intérêt du `unique_ptr` par rapport a un pointeur nu est que même si on ne l'initialize pas au moment de sa déclaration, le c++ moderne fait le travail pour nous car notre pointeur est initialisé automatique à `nullptr`. Par exemple : 

\snippet ./src/unique_ptr.cpp well_initialized

Pour le moment nous avons donc un `std::unique_ptr` mais il ne pointe vers rien donc ne nous sert pas à grand chose. Si nous voulons allouer de la mémoire à ce pointeur nous pourrions comme avec les pointeurs historique utiliser le mot clé `new` cependant le c++ moderne nous offre un autre outils la fonction `std::make_unique` qui cache en réalité l'allocation mémoire via un `new` et l'encapsule directement dans un `std::unique_ptr`. Par exemple pour allouer de la mémoire à notre pointeur d'entier nous pouvons procéder de la manière suivante : 

\snippet ./src/unique_ptr.cpp make_unique

Evidemment nous pouvons faire l'allocation au moment de la déclaration du `std::unique_ptr` pour cela il suffit de faire : 

\snippet ./src/unique_ptr.cpp decl_alloc 

La fonction `std::make_unique` peut prendre des arguments en entrée suivant le contexte. Par exemple `std::unique_ptr` peut nous servir à encapsuler un tableau alloué dynamiquement. Dans ce cas au moment de l'allocation il faut fournir à la fonction `std::make_unique` la taille du tableau à allouer. Par exemple pour créer un tableau de 10 entiers : 

\snippet ./src/unique_ptr.cpp array  

**Remarque :** personellement je ne recommande pas d'utiliser des tableaux de ce genre je vous invite plutôt à utiliser des `std::vector` qui sont beaucoup plus sympatique à utiliser. 

Maintenant entrons dans le vif du sujet avec **la** subtilité des `std::unique_ptr` à savoir le fait qu'ils soient unique. Cela implique une petite bizarrerie dans le fonctionnement qui est que je ne peux pas écrire le code suivant : 

\snippet ./src/unique_ptr.cpp error

En effet l'opération d'affectation d'un `std::unique_ptr` par un autre `std::unique_ptr` est bloquée. Pourquoi ? Et bien simplement pour être sur que l'on a pas deux `std::unique_ptr` pointant vers la même zone mémoire. Bon ok mais c'est pas très grave vous vous dites. Alors en réalité si car le code suivant n'est pas plus valide : 

\snippet ./src/unique_ptr.cpp error2

Avec la fonction `do_something` : 

\snippet ./src/unique_ptr.cpp func 

Et bien là ca commence à devenir génant un peu non ? En tout moi je trouve que oui car avoir un pointeur que je ne peux pas passer dans un autre scope je ne vois pas bien l'intérêt. Mais pas de panique !! Il y a bien évidemment un moyen de faire ce qu'on veut. Ce moyen c'est de dire explicitement que l'on tranfère la propriété de la mémoire pointée à un autre pointeur. Cela se fait en utilisant la fonction `std::move`. Par exemple : 

\snippet ./src/unique_ptr.cpp move_unique 

En utilisant le `std::move` ici nous avons explicitement spécifié que la mémoire pointée par `ptrInt` devient la propriété de `ptr2`. De ce fait le pointeur `ptrInt` est alors automatiquement invalidé et pointe alors vers `nullptr`. 

\snippet ./src/unique_ptr.cpp released

Et c'est exactement le même principe si on veut appeler la fonction `do_something` : 

\snippet ./src/unique_ptr.cpp move_func 


## Utilisation des shared_ptr 

Nous allons maintenant voir les `std::shared_ptr` à la différence des `std::unique_ptr` ils n'imposent aucune restriction sur le nombre de pointeurs pour une même zone mémoire. En ce sens les `std::shared_ptr` sont similaires aux pointeurs nus classiques du c++ old-school. 

Pour déclarer un `std::shared_ptr` la démarche est similaire à celle que l'on vient de voir pour les `std::unique_ptr` à savoir 

```
std::shared_ptr<type> ptr_name; 
```

Par exemple pour créer un pointeur partagé vers un entier : 

\snippet ./src/shared_ptr.cpp decl 

Comme pour le `std::unique_ptr`, à la déclaration le pointeur est initialisé à `nullptr` pour prévenir tout usage dangereux. Pour allouer une zone mémoire à notre pointeur nous pourrions là encore utiliser le mot-clé `new` mais le c++ moderne nous met à disposition la fonction `std::make_shared` exactement sur le même principe que la fonction `std::make_unique`. Par exemple : 

\snippet ./src/shared_ptr.cpp make_shared

Là où il existe les différences entre `std::shared_ptr` et `std::unique_ptr` commencent c'est tout d'abord dans la fonction `use_count` disponible dans le `std::shared_ptr`. L'intérêt de cette fonction est de nous retourner le nombre de pointeurs pointant actuellement vers la zone mémoire pointée. Par exemple : 

\snippet ./src/shared_ptr.cpp count1

Pour le moment nous n'avons qu'un pointeur vers la zone mémoire de `ptr`, donc `ptr`. Maintenant nous allons déclarer un second pointeur qui va faire référence à la même zone mémoire, pour cela on utilise simplement l'opérateur d'affectation `=`. 

\snippet ./src/shared_ptr.cpp assignement

Si nous regardons alors les valeurs retournées par la fonction `use_count` sur `ptr` et `ptr2` nous obtenons : 

\snippet ./src/shared_ptr.cpp count2

```
ptr.use_count() = 2
ptr2.use_count() = 2
```

Nous avons maintenant deux pointeurs `ptr` et `ptr2` qui pointent vers la zone mémoire. Si maintenant nous passons l'un de nos pointeur comme argument de la fonction suivante par exemple : 

\snippet ./src/shared_ptr.cpp func

\snippet ./src/shared_ptr.cpp call_func

Nous obtenons alors la sortie suivante : 

```
in do_something, ptr.use_count() = 3
```

En effet nous avions déjà `ptr` et `ptr2` qui pointaient vers la zone mémoire, or le passage d'argument se faisant ici par copie nous avons donc dans le scope local de la fonction `do_something` un troisième pointeur qui sera automatiquement détruit à la sortie de la fonction, mais la zone mémoire associée est préservée puisque le compteur de pointage n'arrive pas à 0. 

## Attention à ne pas mélanger avec des pointeurs nus. 

Pour finir ce premier apercu des pointeurs, pas d'inquiétude nous reviendrons dessus dans le chapitre suivant sur les classes car c'est là que les pointeurs vont avoir un réel intérêt, nous allons juste mettre un petit warning pour la suite. Nous venons de voir qu'il existe deux approches pour manipuler les pointeurs 

- La version historique, old-school, où l'on manipule ce qu'on appelle des pointeurs nus. Et où la gestion de la mémoire doit se faire intégralement à la main du `new` jusqu'au `delete` ! 
- La version post C++ 11 qui se base sur les `std::unique_ptr` et `std::shared_ptr`. 

La rêgle que vous devez retenir et appliquer est qu'une fois que vous avez choisi une des deux façons de faire il faut vous y tenir et ne surtout pas mélanger les deux ! Perso je vous conseillerais plutôt d'utiliser la syntaxe moderne à base de `std::unique_ptr` ou `std::shared_ptr`. 

Dans les faits nous pouvons très bien mélanger les deux approches car il est possible depuis un `std::shared_ptr` de récupérer le pointeur nu encaspulé à l'aide de la méthode `get` et inversement il est possible de créer un `std::shared_ptr` à partir d'un pointeur nu. Ci-dessous deux exemples de mélange des genres qui provoquent tous les deux une erreur à l'exécution de type `double free`, c'est à dire qu'une même zone de la mémoire est désallouée deux fois !

\snippet ./src/conclusion.cpp bad_idea1


\snippet ./src/conclusion.cpp bad_idea2
