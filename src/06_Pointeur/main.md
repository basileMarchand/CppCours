
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

## Utilisation des shared_ptr 

## Utilisation des unique_ptr 


