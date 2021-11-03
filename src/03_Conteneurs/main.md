
Les structures de données en c++    {#structuresDeDonnees}
================================

[TOC]


# Introduction 

Dans ce chapitre nous allons aborder un aspect essentiel de la programmation les structures de données. Jusqu'à maintenant nous avons vu comment déclarer des variables, c'est bien pour commencer mais c'est loin d'être suffisant. La plupart du temps un programme informatique ne sert qu'à une chose: traiter des gros paquets de données. La grande question qui apparaît alors est: *Comment représenter ces données dans notre programme ?* Il semble évident que faire une variable pour chaque donnée n'est pas la bonne approche, sauf si vous ne savez plus quoi faire de vos soirées mais j'en doute ! C'est là que les structures de données viennent à notre secours !

Le principe est simple: on va faire une seule variable pour contenir notre gros paquet de données, c'est pour cela que l'on parle aussi de conteneurs. 

Wait ! wait !! Pourquoi des structures de données ? Un gros paquet c'est un gros paquet il n'y a pas 20.000 manières de le ranger non ? **Que nenni** !! Il existe différents types de conteneurs car, selon les données que l'on manipule et les algorithmes que l'on met en place, il faudra utiliser une structure de données plutôt qu'une autre.

Il existe des tas de structures de données. Nous verrons même plus loin dans le cours que l'on peut créer ses propres structures de données. Mais, pour le moment, nous allons déjà faire un tour d'horizon des structures de données disponibles nativement dans le `C++`. 

# Les tableaux

## Le conteneur indispensable 

Les tableaux sont des conteneurs homogènes: ils ne contiendront donc que des données du même type. On aura ainsi des tableaux de `int`, des tableaux de `double`, ... mais pas de mélange des genres. Il faut faire attention dans le vocabulaire à ne pas mélanger tableau et liste. Car nous le verrons plus loins il existe également une structure de données liste. **La** particularité des tableaux réside dans la représentation en mémoire. En effet un tableau est stocké de manière contiguë en mémoire ! C'est à dire que, si par exemple je veux faire un tableau de 10 `double`, et bien en mémoire mon tableau sera stocké sur un segment de la ram de taille 10\*64 bits. Et cet aspect *stockage contigu en mémoire* va s'avérer être une particularité essentielle des tableaux car elle permet un certain nombre d'optimisation.

D'ailleurs, pour la petite histoire, dans le monde d'avant maintenant le monde du **C**, l'allocation d'un tableau, de taille 10, se faisait en demandant explicitement un morceau de la RAM pouvant contenir 10 fois le nombre de bits nécessaire pour stocker un double. La commande était la suivante :
```
malloc( 10*sizeof(double));
```
Je vous rassure c'est la seule et unique fois où vous verrez un `malloc` dans ce cours car le C++ permet désormais des syntaxes beaucoup plus sympathiques, de mon point de vue. 

Depuis le début, je dis **les** tableaux car il existe en réalité deux types de tableaux: les tableaux **statiques** et les tableaux **dynamiques**. La distinction entre les deux repose principalement sur le fait de savoir s'il est possible ou non de changer, à l'exécution, la taille du tableau.  

## Le tableau statique

Le premier conteneur possible est le tableau statique ou `array` i.e. un tableau dont la taille est fixe et connue à la compilation. Alors comme pour beaucoup de chose en `C++` il existe deux manières de faire des tableaux statiques. La version old-school et la version post `C++11`. Étant donné que vous risquez très probablement de tomber sur un bout de code qui utilise la version old-school, nous allons en parler, mais je vous conseille fortement d'utiliser la version moderne pour tous les codes que vous écririez vous même.

### Version historique 

La définition d'un tableau statique en `C++` du monde d'avant se fait en utilisant la syntaxe générique suivante :

```
type nomVariable[taille_tableau];
```
Par exemple pour créer une tableau de 10 entiers nous pouvons faire : 
\snippet ./src/c_array_example.cpp create


Nous pouvons également faire : 
\snippet ./src/c_array_example.cpp create_constexpr

Sous-réserve que la fonction `getSize` soit de type `constexpr` c'est à dire que son résultat puisse-être évalué à la compilation (différence entre `const` et `constexpr`). Par exemple :

\snippet ./src/c_array_example.cpp getSize

Pour accéder aux valeurs d'un tableau statique, on utilise l'opérateur d'indexation `[i]` avec `i` l'indice de l'élément que l'on veut. Cet opérateur s'utilise pour les accès en lecture :

\snippet ./src/c_array_example.cpp acces_read

Mais également pour les accès en écriture.

\snippet ./src/c_array_example.cpp acces_write 

Depuis le `C++11` il est également possible de fournir, à la construction du tableau, une **liste d'initialization**. Nous pouvons alors distinguer trois cas de figures.

Pour commencer nous voulons créer un tableau de 5 entiers valant 1, 2, 3, 4, 5. Nous pouvons alors procéder de la manière suivante : 
\snippet ./src/c_array_example.cpp list_init_1

Vous voyez que la taille n'est pas spécifiée, ici elle est déduite par le compilateur à partir de la taille de la liste d'initialization. Du coup que se passe-t-il si on met une taille et une liste d'initialization et surtout si les deux tailles ne collent pas ? Par exemple : 

\snippet ./src/c_array_example.cpp list_init_2

Dans ce cas le tableau sera alors `[1,2,3,4,5,0,0,0,0,0]` et oui le tableau prendra les valeurs de la liste d'initialisation et mettra des zéros (du type `int`) ensuite. 

Et enfin, si on fournit une taille et une liste d'initialisation vide ? Et bien là c'est magique car automatiquement le tableau sera mis à zéro pour chaque élément alors que, sans la liste d'initialisation, les valeurs sont non déterministes ! 

\snippet ./src/c_array_example.cpp list_init_3

Alors l'un des gros point noir des tableaux statiques old-school, en tout cas le truc bloquant de mon point de vue, est que cet idiot ne connait pas sa taille ! C'est à dire que dans tous les vieux code en C on se trimballe un `int` en plus du tableau qui est la taille ! Il existe en réalité une manière de retrouver la taille d'un tableau C mais ça manque un peu d'élégance : 

\snippet ./src/c_array_example.cpp array_size


### Version moderne 

Depuis la norme `C++11` il existe, dans la librairie standard, une alternative au tableau à la `C` historique. Il s'agit du conteneur `std::array`. Le `std::array` encapsule un tableau à la `C` en offrant un certain nombre de fonctions utilitaires qui en simplifient l'usage. Pour utiliser les `std::array` il ne faut pas oublier de faire le bon include ;) 

\snippet ./src/std_array_example.cpp include 

La déclaration d'un `std::array` se fait en utilisant la syntaxe suivante, qui peut sembler particulière, mais qui s'expliquera lorsqu'on verra les templates :

`std::array<type, size>`


Où `type` doit être remplacé par le type des élément que l'on veut mettre dans le `array` et `size` est la taille du array. 

Par exemple, pour créer un tableau de 10 `double`, nous pouvons procéder de la manière suivante : 

\snippet ./src/std_array_example.cpp create 

Nous pouvons également créer un `array` en lui fournissant des valeurs initiales à l'aide d'une liste d'initialisation, par exemple : 

\snippet ./src/std_array_example.cpp create_initializer_list 

Pour le moment rien de révolutionnaire par rapport au tableau old-school ,je vous l'accorde. Et pourtant il y a bien des choses sympa !! 
Pour commencer le conteneur `std::array` dispose d'une méthode `fill` qui permet de remplir votre tableau avec une valeur donnée. Par exemple, nous pouvons créer un tableau de 10 `double` et le remplir de la valeur `1.5` de la manière suivante : 

\snippet ./src/std_array_example.cpp create_and_fill

Ensuite la seconde révolution de taille, c'est le cas de le dire d'ailleurs, c'est le fait qu'un `std::array` est capable de nous dire sa taille ! Cela se fait en passant par la méthode `size()`. Par exemple : 

\snippet ./src/std_array_example.cpp size

De plus, au niveau des méthodes d'accès aux valeurs, le `std::array` offre certaines fonctionnalités intéressantes, comme par exemple la possibilité d'accéder au premier et au dernier élément du `array` via `front()` et `back()`. 

\snippet ./src/std_array_example.cpp front_back

Où encore la possibilité d'échanger le contenu de deux `array` avec la méthode `swap`. 

\snippet ./src/std_array_example.cpp swap

### Pourquoi et quand utiliser un tableau statique 

Les tableaux statiques semblent quelque peu limités, de par le fait que leur taille est fixe et qu'il faut que cette dernière soit connue à la compilation. C'est vrai mais en fait, dans de nombreux cas, nous voulons des tableaux respectant ces deux critères. En effet, dans des tas de programmes, nous avons besoin de petits tableaux écrits *en dur* dans le code et, lorsque c'est le cas, il ne faut surtout pas se priver d'utiliser des `std::array`. 

Pourquoi ? 

Et bien parce que le fait d'avoir un tableau dont la taille est connue à la compilation va permettre au compilateur de faire tout un tas d'optimisation pour vous et donc vous aurez au final un code bien plus performant. Dans l'extrait ci-dessous on fait deux fonctions ; (i) la première crée un tableau statique de 5 éléments ; (ii) la seconde crée un tableau dynamique (*teaser* de la partie suivante). En observant l'onglet de droite on peut alors voir que le code assembleur généré par le compilateur est minimaliste dans le cas du tableau statique tandis que pour le tableau dynamique il y a beaucoup plus d'instructions, c'est lié au fait que le tableau dynamique va nécessiter des opérations de gestion de la mémoire supplémentaires.


\htmlonly 

<iframe width="100%" height="400px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:33,endLineNumber:9,positionColumn:33,positionLineNumber:9,selectionStartColumn:33,selectionStartLineNumber:9,startColumn:33,startLineNumber:9),source:'%23include+%3Carray%3E%0A%23include+%3Cvector%3E%0A%0Avoid+fixed_size()%7B%0A++++std::array+arr+%7B1,2,3,4,5%7D%3B%0A%7D%0A%0Avoid+not_fixed_size()%7B%0A++++std::vector+vec+%7B1,2,3,4,5%7D%3B%0A%7D%0A%0A%0Aint+main()%7B%0A%0A%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g112,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1,tree:'1'),l:'5',n:'0',o:'x86-64+gcc+11.2+(C%2B%2B,+Editor+%231,+Compiler+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

\endhtmlonly 

Cependant, le tableau statique n'est pas la solution miracle car, dans de nombreux cas, on ne peut pas déterminer à l'avance la taille des tableaux, cette taille n'étant connue qu'à l'exécution. Il est donc nécessaire d'avoir sous la main un tableau plus souple d'usage.  


## Le tableau dynamique utile dans 99% des cas 

Le second type de tableau que l'on va être amené à utiliser est le tableau dynamique. Celui ci comme son nom l'indique, et contrairement au tableau statique, n'a pas besoin d'être complètement déterminé au moment de la compilation. Il s'agit donc du conteneur passe-partout qui va nous servir dans la plupart des cas. De plus l'autre intérêt majeur par rapport au tableau statique est que l'on va pouvoir, à l'exécution, changer la taille du tableau: la réduire ou l'agrandir. 
En `C++` ce tableau dynamique s'appelle le `std::vector`. Pour l'utiliser il ne faut pas oublier de faire l'include associé : 

\snippet ./src/vector_example.cpp include_vector

**Attention** : le nom de `vector` est très malheureux car le `std::vector` n'a rien à voir avec un vecteur au sens mathématique du terme. Il s'agit ici uniquement d'un paquet de valeurs de n'importe quel type et sans aucune propriété mathématique associée.

### Généralité sur le std::vector 

#### Créer un vector 

Pour créer un `std::vector` il n'est pas nécessaire de fournir à la compilation la taille de ce dernier, c'est tout l'intérêt de l'aspect dynamique de la chose, en revanche il faut bien évidemment spécifier le type des valeurs qui seront contenues dans ce `std::vector`. Pour cela la syntaxe, quelque peu similaire au `std::array` vu précédemment, est la suivante : 

```
std::vector<type>
```

Pour déclarer un `std::vector` qui ne contiendra que des entiers il suffit de procéder de la manière suivante : 

\snippet ./src/vector_example.cpp create

Le `std::vector` créé est de taille 0. Nous verrons par la suite comment modifier dynamiquement la taille du `std::vector`. Dans le cas où l'on souhaite créer un `std::vector` dont la taille initiale est non nulle, il suffit de fournir un argument lors de la construction: la taille. 

Pour créer le même vecteur d'entiers, mais de taille initiale 10, il suffit de procéder de la manière suivante : 

\snippet ./src/vector_example.cpp create_sized

Question que vous vous posez très certainement: Quelles valeurs initiales ont été données à ce `std::vector` de taille 10 ? 
Et bien par défaut, c'est-à-dire si vous ne spécifiez rien, la valeur initiale prise est l'élément `nul` du type contenu dans le `std::vector` donc ici `int(0)`.

Néanmoins, il est possible de spécifier, à la déclaration du `std::vector`, une valeur initiale. Pour cela il suffit de fournir, en plus de la taille, un second argument qui est la valeur initiale.

Pour créer un `std::vector` d'entiers, de taille 10 et de valeur initiale `2` il suffit de procéder de la manière suivante : 

\snippet ./src/vector_example.cpp create_sized_init

Pour finir, si on souhaite à l'initialisation fournir une liste de valeur c'est tout à fait possible en utilisant une liste d'initialisation ou `initializer-list`. Par exemple : 

\snippet ./src/vector_example.cpp create_initializer_list

Dans ce cas, la taille du `std::vector` est automatiquement déduite de la liste d'initialisation. 

**Pour information** : en utilisant un compilateur `C++` récent, vous pouvez vous passer de spécifier le type des éléments du `std::vector` lorsque vous utilisez une liste d'initialisation. Cela donne par exemple : 

\snippet ./src/vector_example.cpp create_initializer_list_without_type


#### Accéder aux éléments d'un vector 

Pour accéder aux éléments d'un vector, **attention on rappelle que les indices en `C++` commencent à 0**, il suffit de procéder de la manière suivante : 

\snippet ./src/vector_example.cpp access_bracket

on peut également passer par la méthode *at* : 

\snippet ./src/vector_example.cpp access_at

Quelle est la différence entre les deux méthodes ? À première vue aucune... En réalité oui: la méthode `at` procède à une vérification de la validité de l'indice avant de retourner une valeur. C'est à dire que, si vous demandez l'élément d'indice `3` d'un vector de taille 3, l'utilisation de `at` va lever une exception de type *std::out_of_range* tandis que l'opérateur `[]`, dans le même contexte, aura un comportement **indéfini**. 

**Remarque :** il est possible avec `GCC` de forcer, pour l'opérateur `[]`, la vérification des bornes. Il suffit de spécifier l'option de compilation suivante **-D_GLIBCXX_DEBUG**. 

#### Modifier des valeurs

Pour modifier des valeurs dans un `std::vector`, la démarche est très proche de ce que l'on vient de voir pour accéder aux valeurs. Il suffit de mettre **= quelque chose** est ça fonctionne !! 

\snippet ./src/vector_example.cpp modify_bracket

ou bien en utilisant le `at`

\snippet ./src/vector_example.cpp modify_at

Là encore, la distinction entre `[]` et `at` se situe au niveau de la vérification ou non de la validité de l'indice fourni.

#### Parcourir les valeurs d'un std::vector 

Pour itérer sur les valeurs d'un `std::vector`, plusieurs solutions s'offrent à vous. La première solution, que je qualifierai de old-school, est de créer une variable d'itération, à tout hasard `i` et d'accéder aux éléments du `std::vector` en utilisant ce `i`. Cela donne par exemple : 

\snippet ./src/vector_example.cpp parcour_old_school

Cette méthode était la seule possible avant la norme `C++11`. Mais depuis le `C++11` est apparu la notion d'itérateur et donc une syntaxe beaucoup plus sympathique à utiliser. D'ailleurs, si vous avez suivi attentivement les cours de Python, cette syntaxe old-school doit fortement vous faire penser à une syntaxe que l'on vous à interdit d'utiliser à savoir :

```python 
for i in range(len(data)):
    ...
```

Non ça ne vous fait pas penser à ça ?  En Python pour itérer sur les valeurs d'un conteneur nous avons fortement insisté sur le fait que la syntaxe tolérée c'est : 

\code{python} 
for x in data: 
    ...
\endcode

Et bien maintenant nous pouvons faire quelque chose de similaire avec le `C++11`. Et vous le savez déjà en réalité ! Il suffit d'utiliser la syntaxe `for( type x: iterable){}` du `C++11.` Par exemple nous pouvons faire : 

\snippet ./src/vector_example.cpp parcour_post_cpp11

Et c'est quand même vachement plus sympa comme syntaxe non ? 

### Pourquoi le std::vector est si bien 

Maintenant la question est: Pourquoi le `std::vector` répond-il à 99% des besoins ? Majoritairement parce qu'il est redimensionnable ! Nous allons pouvoir changer à l'exécution la taille de notre conteneur. Pour cela plusieurs approches sont possibles, qui dépendent de la finalité souhaitée. 

#### Ajouter/supprimer des éléments  

Tout d'abord nous pouvons dans un `std::vector` ajouter/supprimer des éléments à la fin. Pour cela il existe deux méthodes respectivement `push_back` et `pop_back`. 

Par exemple pour ajouter des valeurs à la fin : 

\snippet ./src/vector_example.cpp push_back

Ensuite si l'on veut retirer la dernière valeur nous pouvons utiliser `pop_back` : 

\snippet ./src/vector_example.cpp pop_back


Par contre attention le `pop_back` ne renvoie rien. Donc, si vous voulez récupérer la dernière valeur **et** la supprimer du `std::vector`, il faut le faire en deux étapes : 

\snippet ./src/vector_example.cpp back_pop_back

Question que vous vous posez peut-être : Peut-on ajouter des éléments ailleurs qu'à la fin ? La réponse est oui mais ce n'est pas recommandé du tout ! car en terme de performance le `std::vector` n'est pas fait pour ça. Par exemple nous pouvons insérer un élément à n'importe quel endroit d'un `std::vector` en utilisant `insert`. 

\snippet ./src/vector_example.cpp insert

La syntaxe est un peu particulière car, pour insérer, il faut dire où on souhaite mettre la valeur à partir du début du conteneur. D'où l'apparition de ce `vd.begin()`. Nous verrons à la fin de ce chapitre qu'en fait caché derrière ce `begin()` il y a la notion d'itérateur. 

#### Changer la taille 

Nous venons de voir qu'ajouter/retirer des éléments d'un `std::vector` modifie implicitement sa taille. Mais ce n'est pas le seul moyen. Il existe en effet la méthode `resize` qui va permettre de réduire ou d'agrandir notre `std::vector`. 

\snippet ./src/vector_example.cpp resize

L'exécution donnerait alors

```
1,2,3,4,5,0,0,0,0,0,
```

Vous voyez donc que le vector a grandi de 5 cases et qu'il a été mis comme valeur par défaut l'élément `nul` du type  `int` considéré ici donc `0`. En revanche, le truc sympa, c'est que nos 5 premières valeurs n'ont pas été modifiées.

De la même manière si maintenant on donne une taille plus petite : 

\snippet ./src/vector_example.cpp resize2

L'exécution donnerait alors 

```
1,2,3,
```

#### Ce qui se cache derrière tout ça

Du coup le `std::vector` est super souple d'utilisation car on peut le trafiquer dans tous les sens. Mais peut-être que vous vous demandez alors comment il fait pour rester performant, car je vous rappelle que le principe des tableaux est que le stockage en mémoire est contigu !! Or le fait de pouvoir changer la taille dynamiquement, notamment ajouter des éléments à la fin, laisse sous-entendre qu'il faut que *la mémoire à la fin du vector* soit disponible et non déjà utilisée par d'autres variables. Et bien en fait le `std::vector` est très malin et en plus il vous ment !! 

En effet le `std::vector` a un mécanisme interne de réservation de mémoire. Dans les faits, il y a une distinction entre la taille d'un vector, que l'on obtient par `size()`, et sa capacité qui est (sa taille maximale sans avoir besoin de redemander tout un bloc mémoire), que l'on obtient avec `capacity()`. 

Considérons l'exemple suivant. Pour commencer on créé un `std::vector` d'entiers de taille nulle.

\snippet ./src/vector_example.cpp part1

On ajoute trois valeurs supplémentaires et on regarde la taille et la capacité : 

\snippet ./src/vector_example.cpp part2

On constate donc que la capacité est maintenant supérieure à la taille du vector. Cela veut dire que l'on peut ajouter une valeur supplémentaire sans que le `std::vector` n'ait besoin de bouger en mémoire. Que se passe-t-il si on est plus gourmand et que l'on ajoute deux valeurs ? 

\snippet ./src/vector_example.cpp part3

Et bien la `capacity` a changé. Cela veut dire que le `std::vector` en interne a dû bouger dans la mémoire et au passage il se dit qu'on a l'air gourmand donc il a demandé une capacité plus grande ! Dans cet exemple on constate que la capacité a été multipliée par `2` mais ce n'est pas forcément la règle générale:  la norme `C++` n'a pas de règle pour cela donc ça dépend de l'implémentation et donc du compilateur ! 

Il est important de noter que du coup il est possible de spécifier la capacité plutôt que la taille à un `std::vector`. L'intérêt est alors qu'au moment de la création du `std::vector` nous pouvons demander à réserver un certain espace mémoire et ensuite lorsqu'on remplira le `std::vector` à coup de `push_back` par exemple il n'y aura aucune réallocation nécessaire, tant que l'on reste dans la limite de ce que nous avons réservé. Cette réservation se fait simplement à l'aide de la méthode `reserve` : 

\snippet ./src/vector_example.cpp vector_reserve

Enfin une fois que l'on a rempli notre `std::vector` et que l'on sait que l'on ne va plus ajouter d'éléments dans ce dernier nous pouvons simplement libérer la mémoire excédentaire de notre réservation en utilisant la méthode `shrink_to_fit` qui vient réduire la capacité du `std::vector` à sa taille. 

\snippet ./src/vector_example.cpp vector_shrink


## Mise en pratique ! 


# Les conteneurs associatifs  

## Principe 

A présent nous allons nous intéresser à une autre structure de données, très différente des tableaux, il s'agit des conteneurs associatifs. La problématique est la suivante : imaginons que je doive traiter un ensemble de données indexées sans aucune hiérarchie ni continuité. Les tableaux ne semblent pas pertinents dans ce cas. C'est pour cela que les conteneurs associatifs existent. Le principe de ces conteneurs va être de manipuler des paire de (clé, valeur). À chaque valeur sera associée une clé unique qui permettra de retrouver très rapidement dans le conteneur la valeur correspondante. Par conséquent il n'y aura plus du tout de notion d'ordre au sein du conteneur. 

Il existe dans le standard C++ deux versions différentes de ces conteneurs associatifs : 

- `std::map`
- `std::unordered_map` 

La distinction entre les deux est en fait une histoire d'implémentation (de la plomberie interne). 

Pour celles et ceux qui n'auraient pas fait le rapprochement, les conteneurs associatifs c'est exactement ce que vous appelez un dictionnaire en Python ;) 

## Différence entre map et unordered_map 

La distinction entre `std::map` et `std::unordered_map` se fait sur l'implémentation interne du rangement du conteneur. En effet les conteneurs associatifs fonctionnent sur un système de clés, il faut donc que les clés soient bien rangées si on veut pouvoir accéder rapidement à un élément du conteneur. Pour cela il existe dans le standard `C++` les deux styles suivants : 

- L'utilisation d'un *Red Black Tree*, c'est ce qui est utilisé dans les `std::map` 
- L'utilisation d'une *table de hash*, c'est ce qui est utilisé dans les `std::unordered_map`

La différence entre ces deux approches est une question de complexité algorithmique des opérations courantes 


|Opération  | `std::map`   | `std::unordered_map`|
|-----------|--------------|---------------------|
| Recherche |  O(log n) | O(1) -> O(n)      | 
| Insertion |  O(log n)+Rééquilibrage | O(1) -> O(n)      |
| Suppression |  O(log n)+Rééquilibrage | O(1) -> O(n)     |

Donc sur le papier la `std::unordered_map` est l'idéal sauf dans le cas où ça se passe mal évidemment ;). 

\htmlonly 

<iframe width="100%" height="800px" src="https://quick-bench.com/q/cGkNnha0FgAIc7uRy-u1C7C6m2U"> </iframe>
\endhtmlonly 

## Utilisation  

Pour utiliser un `std::map` ou un `std::unordered_map` il faut bien évidemment commencer par faire le bon include !

\snippet ./src/map_example.cpp include 

**Remarque :** dans toute la suite les morceaux de code ne porteront que sur les `std::map` mais l'intégralité de ce qui sera montré est transposable en l'état aux `std::unordered_map`. 

La création d'une `map` se fait avec la syntaxe suivante : 

```
std::map<type_clé, type_valeur> nomDeLaMap;
```

On retrouve une syntaxe similaire à ce qu'on a vu avec les `std::array` et `std::vector` à la petite différence qu'il faut renseigner deux types ! Et oui deux car les clés et les valeurs associées n'ont pas forcément le même type, c'est même quasiment jamais le cas. Il faut donc dire que les clés seront d'un certain type tandis que les valeurs seront d'un autre type.

Par exemple pour créer une `map` qui, à des chaînes de caractères, va associer des entiers, il nous suffit de procéder de la manière suivante : 

\snippet ./src/map_example.cpp decl 

Bien évidemment depuis le `C++11` il est possible, à la déclaration d'un `std::map`, de l'initialiser en utilisant une liste d'initialisation comme illustré ci-dessous : 

\snippet ./src/map_example.cpp initializer_list 

Une fois que l'on a une `map` nous pouvons accéder aux éléments stockés via leurs clés. Pour cela on utilise alors l'opérateur crochet `[]`. Par exemple : 

\snippet ./src/map_example.cpp access_read

Comme pour les `std::vector` il existe en complément de l'opérateur `[]` une méthode `at` qui dans le cas d'une `map` va vérifier que la clé demandée existe bel et bien. Car si elle n'existe pas, l'opérateur `[]` ne va rien nous dire et on risque d'avoir des surprises. Si par exemple on demande l'age de `michelle` qui n'est pas une clé du dictionnaire et bien nous allons quand même avoir une valeur en retour, qui correspondra en réalité à l'élément nul des `int` dans notre cas, donc 0. 

\snippet ./src/map_example.cpp access_read_no_check

Avec la méthode `.at` si la clé n'existe pas, une exception de type `std::out_of_range` sera levée. Exception que vous êtes à même de traiter car vu dans le chapitre précédent ;) 

\snippet ./src/map_example.cpp access_read_check

Du coup ce qui pourrait être sympa ce serait de vérifier si une clé existe ou pas dans une `map` non ? Et bien c'est possible évidemment. Cela se fait via la méthode `find`. 

\snippet ./src/map_example.cpp find

La syntaxe est un peu particulière car elle fait intervenir la notion d'itérateur que l'on a pas encore vu en détail. Disons juste que pour le moment vous pouvez le comprendre comme "Est-ce que `find` a trouvé quelque chose avant d'arriver à la fin du conteneur ?". 

La norme `C++20` a introduit la méthode `contains` beaucoup plus explicite et simple à utiliser pour ce cas. 

\snippet ./src/map_example.cpp contains

Bon et maintenant si on veut ajouter un nouveau couple clé/valeur dans notre `map`. Et bien c'est très simple. Vous pouvez tout d'abord passer par l'opérateur `[]` en ajoutant derrière un `=` et une valeur du bon type. Par exemple pour ajouter mon age il suffirait de faire : 

\snippet ./src/map_example.cpp add

Alors là où il y a un petit risque, c'est qu'en faisant ça et bien s'il y a déjà une clé `basile` dans la `map` l'opération précédente ne va rien dire mais elle va écraser l'ancienne valeur. Suivant les applications, il peut s'agir du comportement souhaité ou pas ... Par exemple je peux faire l'opération suivante et cela va m'affecter l'age de 31 ans avec quelques jours d'avance ! 

\snippet ./src/map_example.cpp overwrite

Si on veut contrôler plus finement le comportement de notre `map` lors de l'insertion d'une valeur pour empêcher d'écraser une valeur existante, nous pouvons utiliser la méthode `insert`. 

\snippet ./src/map_example.cpp insert

Vous voyez que la méthode `insert` nous renvoie une valeur. Par soucis de simplicité, j'ai utilisé le type `auto`. En réalité le type de ce qui nous est renvoyé est `std::pair<std::conditional<false, std::map<std::string, int>::const_iterator, std::_Rb_tree_iterator<std::pair<const std::string, int>>>::type, bool>` un peu long non ? `auto` c'est pas mal pour le coup ! Concrètement on récupère un `std::pair`, on va en parler plus en détail juste après, qui contient deux choses : (i) un itérateur (on ne va pas s'attarder là dessus pour le moment) ; (ii) un booléen qui vaudra `true` si la valeur a été insérée (donc si la clé n'existait pas déjà) et `false` sinon et alors rien ne sera fait car la clé existe déjà aussi la valeur associée ne sera pas modifiée. 

\snippet ./src/map_example.cpp insert_details

La norme `C++17` a introduit la méthode `insert_or_assign` qui, comme son nom l'indique, va insérer ou affecter la valeur si la clé existe déjà. C'est comme l'opérateur `[]` sauf qu'ici on sera capable de déterminer a posteriori si c'est une insertion ou une affectation qui vient d'être réalisée. 

\snippet ./src/map_example.cpp insert_or_assign 

Pour finir, revenons sur notre histoire de `std::pair`. Un `std::pair` est un couple (clé, valeur). Très grossièrement, on peut donc dire d'une `map` est un ensemble de `pair`. Pour le moment, nous avons manipulé les `std::map` sans trop nous soucier de ces `std::pair` mais il y a un moment où nous allons devoir nous en préoccuper: c'est lorsque l'on va vouloir itérer sur (parcourir) une `map`. Depuis le `C++11`, en utilisant la syntaxe `for( auto p: conteneur)`, nous pouvons itérer sur les éléments d'un `std::map` de la manière suivante : 

\snippet ./src/map_example.cpp loop_auto

La grande question qui se pose alors est: C'est quoi `p` ? Et bien `p` c'est notre fameux `std::pair`. Dans notre cas, plus précisément, c'est un `std::pair<std::string, int>`. Il s'agit donc du type contenant le couple (nom, age). Pour accéder aux valeurs stockées, on utilise les attributs `first` et `second`. Par exemple : 

\snippet ./src/map_example.cpp loop_auto_details

Alors juste pour se simplifier la vie, la norme `C++17` a introduit un concept assez sympathique qui est le `structured binding`. Le principe est de pouvoir "éclater" une structure de données en plusieurs variables distinctes. Comme par exemple dans `Python` où vous pouvez facilement faire : 

```python
>>> p = ("toto", 10)
>>> a,b = p
>>> a
'toto'
>>> b
10
>>> 
```

Et bien le `structured binding` fait la même chose mais en `C++` ! (*`C++` is the new Python*). Donc si on reprend notre boucle sur le `std::map`, nous pouvons alors écrire en `C++17` : 

\snippet ./src/map_example.cpp loop_auto_17

Pour les plus curieux, si vous vous voulez voir ce que le compilateur écrit à votre place vous pouvez faire un tour sur le site [cppinsights.io](cppinsights.io). Par exemple dans le cas de notre boucle `for` précédente le vrai code, généré par le compilateur avant la phase de traduction en assembleur, est le suivant : 

\htmlonly
<iframe width="100%" height="400px" src="https://cppinsights.io/s/35be28b8"></iframe>
\endhtmlonly

Je pense qu'on sera tous d'accord pour dire merci le compilateur et le `C++` moderne ;) 

# Un conteneur hétérogène ! 

## C'est bizarre non ? 

## Le tuple 

# Encore d'autres structures 

## Liste chaînée 

## Pile et File 


# Les itérateurs : merci le C++11 (encore) 

## Principe 

## Utilisation des itérateurs 


