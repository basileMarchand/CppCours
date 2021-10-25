
Les conteneurs en c++    {#conteneurSection}
=====================

[TOC]


# Introduction 

Dans ce chapitre nous allons nous focaliser sur les conteneurs. Précédemment nous avons vu comment faire des variables en utilisant des types de bases relativement simples mais, dans de nombreux de cas, c'est loin d'être suffisant. En effet, dans la plupart des applications, on ne fait pas un programme pour traiter une valeur mais pour traiter un ensemble de valeurs. D'où les conteneurs. 

## Un conteneur : une variable contenant d'autres variables 

Un conteneur peut-être vu comme une variable contenant d'autre variables. Autrement dit le conteneur va nous permettre avec un identifiant unique de référencer un ensemble de valeurs. Ces valeurs sont ordonnées au sein du conteneur en suivant une logique propre au conteneur. 


## Conteneur statique vs dynamique 

Les conteneurs se distinguent entre eux selon deux points : 

1. La logique interne au conteneur, i.e. comment les valeurs sont ordonnées dans le conteneur 
2. Le fait que la taille du conteneur soit statique ou dynamique 


# Le tableau statique

Le premier conteneur possible est le tableau statique ou `array`, i.e. un tableau dont la taille est fixe et idéalement connue à la compilation. 



## Version historique 

\snippet ./src/c_array_example.cpp create


\snippet ./src/c_array_example.cpp create_constexpr

Sous-réserve que la fonction `getSize` soit de type `constexpr` c'est à dire que son résultat peut-être évalué à la compilation. Par exemple : 

\snippet ./src/c_array_example.cpp getSize


Pour accéder aux valeurs d'un tableau statique on utilise l'opérateur `[i]` avec `i` l'indice de l'élément que l'on veut. Cet opérateur s'utilise pour les accès en lecture : 

\snippet ./src/c_array_example.cpp acces_read

Mais également pour les accès en écriture. 

\snippet ./src/c_array_example.cpp acces_write 

## Version moderne 

Depuis la norme `c++11` il existe, dans la librairie standard, une alternative au tableau à la `C` historique. Il s'agit du conteneur `std::array`. Le `std::array` encapsule un tableau à la `C` en offrant un certain nombre de fonctions utilitaires en simplifiant l'usage. Pour utiliser les `std::array` il ne faut pas oublier de faire le bon include ;) 

\snippet ./src/std_array_example.cpp include 



La déclaration d'un `std::array` se fait en utilisant la syntaxe suivante, qui peut sembler particulière, mais qui s'expliquera lorsqu'on verra les templates :

`std::array<type, size>`


Où `type` doit être remplacé par le type des élément que l'on veut mettre dans le `array` et `size` est la taille du array. 

Par exemple, pour créer un tableau de 10 `double` nous pouvons procéder de la manière suivante : 

\snippet ./src/std_array_example.cpp create 

Nous pouvons également créer un `array` en lui fournissant des valeurs initiales à l'aide d'une liste d'initialisation, par exemple : 

\snippet ./src/std_array_example.cpp create_initializer_list 

Pour le moment rien de révolutionnaire par rapport au tableau old-school je vous l'accorde. Et pourtant il y a bien des choses sympa !! 
Pour commencer le conteneur `std::array` dispose d'une méthode `fill` qui permet de remplir votre tableau avec un valeur donnée. Par exemple nous pouvons créer un tableau de 10 `double` et le remplir de la valeur `1.5` de la manière suivante : 

\snippet ./src/std_array_example.cpp create_and_fill

Ensuite la seconde révolution de taille, c'est le cas de le dire d'ailleurs, c'est le fait qu'un `std::array` est capable de nous dire sa taille ! Cela se fait en passant par la méthode `size()`. Par exemple : 

\snippet ./src/std_array_example.cpp size

De plus au niveau des méthodes d'accès aux valeurs, le `std::array` offre certaines fonctionnalités intéressantes, comme par exemple la possibilité d'accéder au premier et au dernier élément du `array` via `front()` et `back()`. 

\snippet ./src/std_array_example.cpp front_back

Où encore la possibilité d'échanger le contenu de deux `array` avec la méthode `swap`. 

\snippet ./src/std_array_example.cpp swap


## Pourquoi et quand utiliser un tableau statique 

Les tableaux statiques semblent quelque peu limités de par le fait que leur taille est fixe et qu'il faut que cette dernière soit connue à la compilation. C'est vrai mais en fait dans de nombreux cas nous voulons des tableaux respectant ces deux critères. En effet, dans des tas de programmes, nous avons besoin de petits tableaux écrits *en dur* dans le code et, lorsque c'est le cas, il ne faut surtout pas se priver d'utiliser des `std::array`. 

Pourquoi ? 

Et bien parce que le fait d'avoir un tableau dont la taille est connue à la compilation va permettre au compilateur de faire tout un tas d'optimisation pour vous et donc vous aurez au final un code bien plus performant.


\htmlonly 

<iframe width="100%" height="400px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:33,endLineNumber:9,positionColumn:33,positionLineNumber:9,selectionStartColumn:33,selectionStartLineNumber:9,startColumn:33,startLineNumber:9),source:'%23include+%3Carray%3E%0A%23include+%3Cvector%3E%0A%0Avoid+fixed_size()%7B%0A++++std::array+arr+%7B1,2,3,4,5%7D%3B%0A%7D%0A%0Avoid+not_fixed_size()%7B%0A++++std::vector+vec+%7B1,2,3,4,5%7D%3B%0A%7D%0A%0A%0Aint+main()%7B%0A%0A%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g112,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1,tree:'1'),l:'5',n:'0',o:'x86-64+gcc+11.2+(C%2B%2B,+Editor+%231,+Compiler+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>

\endhtmlonly 

Cependant, le tableau statique n'est pas la solution miracle car, dans énormément de cas, on ne peut pas déterminer à l'avance la taille des tableaux, cette taille n'est connue qu'à l'exécution. 


# Le tableau dynamique utile dans 99% des cas 

Le second type de conteneur que l'on va être amenés à utiliser est le tableau dynamique, celui ci comme son nom l'indique, et contrairement au tableau statique, n'a pas besoin d'être complètement déterminé au moment de la compilation. Il s'agit donc du conteneur passe-partout qui va nous servir dans la plupart des cas. 
Ce tableau dynamique s'appelle le `std::vector`. Pour l'utiliser il ne faut pas oublier de faire l'include associé : 

\snippet ./src/vector_example.cpp include_vector

**Attention** : le nom de `vector` est très malheureux car le `std::vector` n'a rien à voir avec un vecteur au sens mathématique du terme. Il s'agit ici uniquement d'un paquet de valeurs de n'importe quel type et sans aucune propriété mathématique associée. 

## Généralité sur le std::vector 

### Créer un vector 

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

Néanmoins, il est possible de spécifier à la déclaration du `std::vector` une valeur initiale. Pour cela il suffit de fournir, en plus de la taille, un second argument qui est la valeur initiale.

Pour créer un `std::vector` d'entiers, de taille 10 et de valeur initiale 2 il suffit de procéder de la manière suivante : 

\snippet ./src/vector_example.cpp create_sized_init

Pour finir, si on souhaite à l'initialisation fournir une liste de valeur c'est tout à fait possible en utilisant une `initializer-list`. Par exemple : 

\snippet ./src/vector_example.cpp create_initializer_list

Dans ce cas, la taille du `std::vector` est automatiquement déduite de la liste d'initialisation. 

**Pour information** : en utilisant un compilateur `C++` récent, vous pouvez vous passer de spécifier le type des éléments du `std::vector` lorsque vous utilisez une liste d'initialisation. Cela donne par exemple : 

\snippet ./src/vector_example.cpp create_initializer_list_without_type


### Accéder aux éléments d'un vector 

Pour accéder aux éléments d'un vector, **attention on rappelle que les indices en `C++` commencent à 0**, il suffit de procéder de la manière suivante : 

\snippet ./src/vector_example.cpp access_bracket

on peut également passer par la méthode *at* : 

\snippet ./src/vector_example.cpp access_at

Quelle est la différence entre les deux méthodes ? A première vue aucune... En réalité oui: la méthode `at` procède à une vérification de la validité de l'indice avant de vous retourner une valeur. C'est à dire que, si vous demandez l'élément d'indice 3 d'un vector de taille 3, l'utilisation de `at` va lever une exception de type *std::out_of_range* tandis que l'opérateur `[]`, dans le même contexte, aura un comportement **indéfini**. 

**Remarque :** il est possible avec `GCC` de forcer, pour l'opérateur `[]`, la vérification des bornes. Il suffit de spécifier l'option de compilation suivante **-D_GLIBCXX_DEBUG**. 

### Modifier des valeurs

Pour modifier des valeurs dans un `std::vector`, la démarche est très proche de ce que l'on vient de voir pour accéder aux valeurs. Il suffit de mettre **= quelque chose** est ça fonctionne !! 

\snippet ./src/vector_example.cpp modify_bracket

ou bien en utilisant le `at`

\snippet ./src/vector_example.cpp modify_at

Là encore la distinction entre `[]` et `at` se situe au niveau de la vérification ou non de la validité de l'indice fourni.

### Parcourir les valeurs d'un std::vector 

Pour itérer sur les valeurs d'un `std::vector`, plusieurs solutions s'offrent à vous. La première solution, que je qualifierai de old-school, est de créer une variable d'itération, à tout hasard `i` et d'accéder aux éléments du `std::vector` en utilisant ce `i`. Cela donne par exemple : 

\snippet ./src/vector_example.cpp parcour_old_school

Cette méthode était la seule possible avant la norme `c++11`. Mais depuis le `C++11` est apparu la notion d'itérateur et donc une syntaxe beaucoup plus sympathique à utiliser. D'ailleurs, si vous avez suivi attentivement les cours de Python, cette syntaxe old-school doit fortement vous faire penser à une syntaxe que l'on vous à interdit d'utiliser à savoir :

```python 
for i in range(len(data)):
    ...
```

Non ça ne vous fait pas penser à ça ?  En Python pour itérer sur les valeurs d'un conteneur nous avons fortement insisté sur le fait que la syntaxe tolérée c'est : 

\code{python} 
for x in data: 
    ...
\endcode

Et bien avec le `C++11` nous avons une syntaxe similaire qui est la suivante : 

\snippet ./src/vector_example.cpp parcour_post_cpp11



## Pourquoi le std::vector est si bien 

Maintenant la question est: Pourquoi le std::vector répond-il à 99% des besoins ? Majoritairement parce qu'il est redimensionnable ! 


# Le conteneur associatif : std::map et std::unordered_map 

## Principe 


## Différence entre map et unordered_map 

## Utilisation  


# Et plein d'autres 


# Les itérateurs 

## Principe 

## Utilisation des itérateurs 


