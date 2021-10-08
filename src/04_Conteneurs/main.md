
Les conteneurs en c++    {#conteneurSection}
=====================

[TOC]


# Introduction 

Dans ce chapitre nous allons nous focaliser sur les conteneurs. Précédemment nous avons vu comment faire des variables utilisant des types de bases relativement simple mais dans beaucoup de cas c'est loin d'être suffisant. En effet dans un grand nombre d'application on ne fait pas un programme pour traiter une valeur mais pour traiter un ensemble de valeur. D'où les conteneurs. 

## Un conteneur : une variable contenant d'autres variables 

Un conteneur peut-être vu comme une variable contenant d'autre variables. Autrement dit le conteneur va nous permettre avec un identifiant unique de référencer un ensemble de valeurs. Ces valeurs sont ordonnées au sein du conteneur en suivant une logique qui est propre au conteneur. 


## Conteneur statique vs dynamique 

Les conteneurs se distinguent entre eux selon deux points : 

1. La logique interne au conteneur, i.e. comment les valeurs sont ordonnées dans le conteneur 
2. Le fait que la taille du conteneur soit statique ou dynamique 


# Le tableau statique

Le premier conteneur possible est le tableau statique ou array, i.e. un tableau dont la taille est fixe et idéalement connue à la compilation. 




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

Depuis la norme `c++11` il existe dans la librairie standard une alternative au tableau à la C historique. Il s'agit du conteneur `std::array`. Le `std::array` encapsule un tableau à la C en offrant un certain nombre de fonctions utilitaire permettant de simplifier l'usage quotidien. Pour utiliser les `std::array` il ne faut pas oublier de faire le bon include ;) 

\snippet ./src/std_array_example.cpp include 




La déclaration d'un `std::array` se fait en utilisant la syntaxe, qui peut sembler particulière mais s'expliquera lorsque l'on verra les templates, suivante : 

`std::array<type, size>`


Où `type` doit être remplacer par le type d'éléments que l'on veut contenir dans le `array` et `size` est la taille du array. 

Par exemple pour créer un tableau de 10 `double` nous pouvons procéder de la manière suivante : 

\snippet ./src/std_array_example.cpp create 

Nous pouvons également créer un `array` et lui fournir des valeurs initiales à l'aide d'une liste d'initialisation, par exemple : 

\snippet ./src/std_array_example.cpp create_initializer_list 

Pour le moment rien de révolutionnaire par rapport au tableau old-school je vous l'accorde. Et pourtant il y a bien des choses sympa !! 
Pour commencer le conteneur `std::array` dispose d'une méthode `fill` qui permet de remplir votre tableau avec un valeur donnée. Par exemple nous pouvons créer un tableau de 10 `double` et le remplir de la valeur `1.5` de la manière suivante : 

\snippet ./src/std_array_example.cpp create_and_fill

Ensuite la seconde révolution de taille, c'est le cas de le dire d'ailleurs, c'est le fait qu'un `std::array` est capable de nous dire sa taille ! Cela se fait en passant par la méthode `size()`. Par exemple : 

\snippet ./src/std_array_example.cpp size

De plus au niveau des méthodes d'accès aux valeurs le `std::array` offre certaines fonctionnalités intéressantes. Par exemple la possibilité d'accéder au premier et dernier élément du `array` via `front()` et `back()`. 

\snippet ./src/std_array_example.cpp front_back

Où encore la possibilité d'échanger le contenu de deux `array` avec la méthode `swap`. 

\snippet ./src/std_array_example.cpp swap


## Pourquoi et quand utilisé un tableau statique 

Les tableaux statiques semblent quelque peu limités de par le fait que la taille est fixe et qu'il faut que cette dernière soit connue à la compilation. Oui c'est vrai mais en fait dans plein de cas nous avons des tableaux respectant ces deux critères. Dans plein de programmes nous avons des petits tableaux écrit en dur dans le code et lorsque c'est le cas il ne faut surtout pas se priver d'utiliser des `std::array`. 

Pourquoi ? 

Et bien parce que le fait d'avoir un tableau dont la taille est connue à la compilation va permettre au compilateur de faire tout un tas d'optimisation pour vous et donc vous aurez au final un code bien plus performant.




<iframe width="800px" height="200px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:33,endLineNumber:9,positionColumn:33,positionLineNumber:9,selectionStartColumn:33,selectionStartLineNumber:9,startColumn:33,startLineNumber:9),source:'%23include+%3Carray%3E%0A%23include+%3Cvector%3E%0A%0Avoid+fixed_size()%7B%0A++++std::array+arr+%7B1,2,3,4,5%7D%3B%0A%7D%0A%0Avoid+not_fixed_size()%7B%0A++++std::vector+vec+%7B1,2,3,4,5%7D%3B%0A%7D%0A%0A%0Aint+main()%7B%0A%0A%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g112,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1,tree:'1'),l:'5',n:'0',o:'x86-64+gcc+11.2+(C%2B%2B,+Editor+%231,+Compiler+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>


Cependant le tableau statique n'est pas la solution miracle car dans énormément de cas on ne peut pas déterminer à l'avance la taille des tableau, cette taille n'est connu qu'à l'exécution. 


# Le tableau dynamique utile dans 99% des cas 

\snippet ./src/vector_example.cpp include_vector

## Généralité sur le std::vector 

### Créer un vector 

\snippet ./src/vector_example.cpp create

\snippet ./src/vector_example.cpp create_sized

\snippet ./src/vector_example.cpp create_sized_init

\snippet ./src/vector_example.cpp create_initializer_list

### Accéder aux éléments d'un vector 

Pour accéder aux éléments d'un vector, **attention on rappel que les indices commencent à 0**, il suffit de procéder de la manière suivante : 
\snippet ./src/vector_example.cpp access_bracket

on peut également passer par la méthode *at* : 

\snippet ./src/vector_example.cpp access_at

Quelle différence entre les deux ? A première vue aucune... En réalité si, la méthode *at* procède à une vérification de la validité de l'indice avant de vous retourner une valeur. C'est à dire que si vous demandez l'élément d'indice 3 d'un vector de taille 3 l'utilisation de *at* va lever une exception de type *std::out_of_range* tandis que l'opérateur [] dans le même contexte aura un comportement indéfini. 

**Remarque :** il est possible avec GCC de forcer pour l'opérateur [] une vérification des bornes. Il suffit pour cela de spécifier l'option de compilation suivante **-D_GLIBCXX_DEBUG**. 

### Modifier des valeurs

Pour modifier des valeurs dans un std::vector la démarche est très proche de ce que l'on vient de voir pour accéder aux valeurs. Il suffit de mettre **= quelque chose** est ça marche !! 

\snippet ./src/vector_example.cpp modify_bracket

ou bien en utilisant le *at*

\snippet ./src/vector_example.cpp modify_at

Là encore la distinction entre [] et *at* se situe au niveau de la vérification ou non de la validité de l'indice fourni. 

### Parcourir les valeurs d'un std::vector 

\snippet ./src/vector_example.cpp parcour_old_school

\snippet ./src/vector_example.cpp parcour_post_cpp11


## Pourquoi le std::vector est si bien 

Maintenant la question est pourquoi le std::vector répond-il à 99% des besoins ? Majoritairement parce qu'il est redimensionnable 



# Le conteneur associatif : std::map et std::unordered_map 

## Principe 


## Différence entre map et unordered_map 

## Utilisation  


# Et plein d'autres 


# Les itérateurs 

## Principe 

## Utilisation des itérateurs 


