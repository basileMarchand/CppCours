
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

Une chose très très importante pour ne pas dire capitale ! La règle de base à retenir et **à appliquer** est que *l'on ne doit jamais faire de copier-coller dans un code* ! Dès que vous êtes tenté de faire un copier-coller dans votre code c'est que vous devez faire une fonction. Pourquoi ? Mais tout simplement parce que le copier-coller c'est la source d'erreur assurée ! Car si vous avez un bout de code que vous copiez 20 fois dans votre projet, quelques temps plus tard vous vous apercevez qu'il y a un bug, vous le corrigez mais vous devez ensuite retrouver les 20 endroits où vous avez le même bug pour le corriger et il y a de fortes chances que vous loupiez une correction ! Et là c'est le drame !


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

Le `C++` dans son génie sans limite met à disposition des développeurs le mécanisme génial de la surcharge de fonctions. Le principe est simple, pour différencier deux fonctions entre elles le C++ regarde **deux** choses : 
1. L'identificateur de la fonction, son petit nom donc 
2. Le nombre et le type des arguments d'entrée de la fonction 

Le nombre et le type ? Je peux définir `n` fonctions ayant le même nom tant que les arguments d'entrées sont de types différents entre toutes les versions et ça marche ? Et oui ça marche et ça c'est beau !! Je ne ferai pas de comparaison avec Python ici car ce mécanisme n'existe pas en Python. Si on reprend maintenant notre problème de fonction calculant la moyenne, nous pouvons donc faire quelque chose du genre : 

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

Pas vraiment ce qu'on avait en tête non ? Mais pourquoi ça ne marche pas ?! Et bien si ça marche c'est juste que vous n'avez pas su parler correctement au `C++`. Et du coup il fait exactement ce que vous lui avez demandé ! Il s'agit là de la grande subtilité du C++, ***le passage des arguments d'une fonction se fait toujours par copie*** ! Donc le tableau que l'on modifie dans la fonction est une copie de `v` donc en le modifiant on ne modifie pas `v` tout simplement ! 

Mais ça coûte cher non ? Alors oui faire une copie des arguments quand c'est un `int` ou un `double` ça passe mais quand c'est un `std::array<double, 10000>` ça commence à se faire sentir ! C'est pour cela qu'il existe un moyen de dire au `C++` de ne pas faire de copies c'est ce qu'on appelle le passage par référence ! Et le nom doit vous rappeler quelque chose non ;) car oui le principe va être d'utiliser des références plutôt que les  (les objets) elles mêmes. Pour cela c'est au moment de la déclaration de la fonction qu'il faut dire que l'on ne veut pas la variable mais une référence vers cette variable. Et cela se fait simplement en ajoutant un esperluette `&` derrière le type de l'argument que l'on ne veut pas copier ! Par exemple : 

\snippet ./src/function_intro2.cpp ref_arg

\snippet ./src/function_intro2.cpp ref_arg_call

```
10, 2, 3,
```
Dans ce cas on obtient donc le résultat attendu ! 

Par contre attention c'est à double tranchant ! Et oui si on passe tout par référence il y a le risque que l'on modifie une variable qui ne devait pas l'être et après dans le reste de notre code c'est la catastrophe ! Heureusement il y a un moyen de prévenir cela. Par exemple si on reprend l'exemple du calcul d'une moyenne nous pourrions passer le tableau des valeur par référence pour économiser une copie mais en revanche notre fonction ne doit en aucun cas pouvoir modifier les valeurs du tableau. Pour cela le qualificateur `const` est votre ami ! En effet nous pouvons déclarer un argument d'entrée comme `const` ce qui assure alors qu'aucune modification de la variable ne pourra être faite dans cette fonction : 

\snippet ./src/function_intro2.cpp const_ref

Enfin dernière mise en garde ! N'ayez surtout pas l'idée d'essayer de renvoyer une référence via en sortie d'une fonction. Autrement dit n'essayez pas de faire : 

\snippet ./src/function_intro2.cpp bad_idea

Vous avez une petite idée de pourquoi ce code est tout sauf l'idée du siècle ? Tout simplement parce qu'une référence c'est une variable qui utilise la mémoire d'une autre variable donc, en renvoyant en sortie de votre fonction la référence d'une variable locale à la fonction, vous renvoyez en fait la zone mémoire de votre variable locale. Sauf que si cette variable est **locale** quand on sort de la fonction elle est détruite et la zone mémoire associée est libérée et du coup on se retrouve avec une référence vers une zone mémoire qui n'est plus réservée. Et là c'est le début de gros problème ... 

## Une pointe de modernité ! 

### Retourner plusieurs valeurs 

Tout d'abord vous avez peut-être constaté que les fonctions `C++` par défaut soit elles ne retournent rien soit elles retournent **une et une seule** variable. Du coup se pose la question de *Comment je fais si j'ai une fonction qui doit me retourner deux choses ?* Alors avant le `C++11` c'était tout simplement impossible ! Mais il existe quand même une parade et elle est très simple. En effet il suffit de définir un argument supplémentaire que l'on passe par référence (non constante) et qui va jouer le rôle de notre seconde variable (de retour). Par exemple faisons une fonction qui prend en entrée un `std::vector<double>` et retourne le tableau contenant toutes les valeurs sauf celles qui sont supérieures à un seuil fourni par l'utilisateur, et retourne également le nombre de valeur supprimées. Dans le monde pré-`C++11` nous pourrions procéder de la manière suivante : 

\snippet ./src/function_intro2.cpp in_out

A l'usage cela donnerait alors : 

\snippet ./src/function_intro2.cpp in_out_call 

Cela fait le travail et donc ne soyez pas surpris si vous tombez sur des structures dans ce style car on en trouve encore énormément dans de très nombreux codes ! 

Cependant le `C++11` (gloire à lui) a permis de faire des fonctions qui retournent vraiment plusieurs valeurs sans passer par l'astuce des références. Et vous savez déjà comment faire ça en fait ! Non ? Pas d'idée ? C'est pourtant évident: si vous ne pouvez renvoyer qu'un truc, renvoyez alors un conteneur hétérogène `std::tuple`. Et bah oui si on dit que notre fonction retourne un `std::tuple` on peut alors mettre autant de valeurs en sortie qu'on le souhaite. Par exemple sur mon exemple de seuillage cela donnerait : 

\snippet ./src/function_intro2.cpp out11

Cela donnerait alors à l'usage : 

\snippet ./src/function_intro2.cpp out11_call 

C'est pas mal non ? J'avoue que le fait de manipuler un `std::tuple` est un peu lourd après à cause des `std::get` ce serait sympa d'avoir un truc un peu plus concis un jour... Oh mais au fait le `C++17` a résolu ce problème, je vous en ai parlé dans la partie sur les conteneurs. Et oui le `C++17` a introduit le truc génial du *structured binding* et ça c'est cool car ça nous permet d'écrire directement : 

\snippet ./src/function_intro2.cpp out11_call17

Là je pense qu'on peut dire qu'on est content car c'est quand même vachement pratique et lisible surtout ! Donc maintenant n'hésitez plus: si vos fonctions doivent renvoyer plusieurs choses qu'elles le fassent explicitement plutôt que de faire un jeu de références peu clair ! 


### Fonctions constexpr 

Avec le `C++11` est arrivée la notion de `constexpr` nous avons déjà parlé des variables `constexpr` pour rappel il s'agit des variables connues à la compilation. Mais nous pouvons également déclarer des fonctions comme `constexpr` c'est à dire que le résultat de l'évaluation de la fonction peut se calculer à la compilation. Le concept des fonctions `constexpr` a été initialement introduit dans le `C++11` cependant il a été largement enrichi par les normes `C++14` et `C++17` en faisant quelque chose de vraiment exploitable désormais. Par exemple nous pouvons définir une fonction factorielle `constexpr` de la manière suivante : 

\snippet ./src/constexpr_example.cpp factorial 

Comment être sûr que je ne vous baratine pas et que la fonction est vraiment calculée à la compilation ? Facile on va faire un tour sur [godbolt.org](godbolt.org) et on regarde le code assembleur généré ;) 

\htmlonly 
<iframe width="100%" height="300px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:2,endLineNumber:13,positionColumn:2,positionLineNumber:13,selectionStartColumn:2,selectionStartLineNumber:13,startColumn:2,startLineNumber:13),source:'constexpr+int+factorial(const+int+n)%7B%0A++++if(n%3C1)%7B%0A++++++++return+1%3B%0A++++%7D%0A++++return+n*factorial(n-1)%3B%0A%7D%0A%0A%0Aint+main()%7B%0A%0A++++int+f10+%7Bfactorial(10)%7D%3B%0A++++return+f10%3B%0A%7D'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g112,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'0',intel:'0',libraryCode:'0',trim:'1'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1,tree:'1'),l:'5',n:'0',o:'x86-64+gcc+11.2+(C%2B%2B,+Editor+%231,+Compiler+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>
\endhtmlonly 

Et sinon qu'est ce qu'on est censé voir ? Deux choses : 

1. Vous pouvez remarquer que le code associé à la définition de la fonction `factorial` n'apparaît pas dans l'onglet de droite. Cela veut tout simplement dire que la définition de la fonction n'est pas dans le code généré car le code n'en a pas (plus) besoin
2. Vous remarquerez qu'à la ligne 4 du code assembleur il y a la valeur `3628800`. Alors ce n'est pas vraiment un hasard mais il s'agit de la valeur de factorielle 10... Et donc oui la valeur de `factorial(10)` est écrite en dur dans le code généré preuve que le résultat de la fonction a bien été calculé à la compilation et qu'à l'exécution il n'y a plus rien à faire ! Et c'est très beau...

### Déduction de type 

Pour finir sur les fonctions de base, il existe depuis le c++11 une pratique de déduction de type assez sympatique à l'usage reposant sur `decltype`. Le principe est qu'il est possible de définir une variable du même type que le type de retour d'une fonction. Par exemple : 

\snippet ./src/example_decl.cpp main

Et la force de la chose est que `computeArea` n'est pas évaluée pour faire cela. Cela peut paraître bizarre comme approche mais nous verrons plus tard lorsque nous regarderons en détail la notion de template qu'il y a en réalité plein de contexte où connaître le type à la compilation ce n'est pas si simple que ça en fait ;) 

Et sinon avec un petit `using` c'est toujours plus sympa à lire : 

\snippet ./src/example_decl.cpp main2

# Un mot sur les fonctions anonymes 

## Une fonction anonyme pour quoi faire ? 

Maintenant que vous savez faire des fonctions classiques nous allons voir une autre manière de faire des fonctions que l'on va qualifier d'anonymes (i.e. sans nom lors de leur définition), on parle également de lambda fonctions. Pourquoi anonyme ? Tout simplement par opposition aux fonctions classiques. Concrètement une fonction classique se définit de manière globale et est par conséquent visible et utilisable par "tout le monde dans votre code". Tandis qu'une fonction anonyme va être définie localement (au sein d'une fonction par exemple) et ne sera donc pas visible par tout le monde. Les fonctions anonymes ont donc vocation à être définies au fil de l'eau lorsqu'en on a besoin. 

L'intérêt de ces fonctions va vous apparaître de manière flagrante dans le prochain chapitre lorsque nous verrons le paradigme de la programmation fonctionnelle. 

## Définition des lambda fonctions 

La définition d'une fonction anonyme se fait en suivant la syntaxe suivante : 

```
[capture](arguments) -> type_retour { corps de la fonction };
```

On identifie donc quatre éléments : 

- La capture : permet de spécifier les variables (du scope de définition de la lambda) qui seront accessibles dans le corps de la lambda. Par défaut la capture est vide ce qui signifie qu'au sein de la fonction anonyme on ne pourra accéder à **aucune** variable du scope supérieur: la fonction anonyme est isolée du reste du monde. 
- Les arguments : il s'agit des arguments d'entrée de la fonction anonyme, les règles sont exactement les mêmes que pour les fonctions classiques
- Le type de retour : comme pour une fonction classique il faut spécifier le type de la variable retournée par la fonction anonyme. Le type de retour peut ne pas être indiqué, généralement le compilateur s'en sort, mais par soucis de lisibilité (et pour être sympa avec le compilo) il est préférable de toujours le spécifier. 
- Le corps de la fonction : rien de nouveau c'est comme dans les fonctions classiques. 

### La notion de capture 

La notion de capture est l'élément qui nous permet de définir l'environnement en quelque sorte dans lequel va s'exécuter le corps de notre fonction anonyme. Par exemple dans l'exemple ci-dessou nous définissons un capture vide. 

\snippet ./src/lambda_example.cpp lambda_no_capture

Le corps de la fonction anaonyme ne peut donc utiliser aucune variables défini en-dehors puisque le capture est vide. Une autre façon de voir le capture est de se dire qu'il s'agit d'un moyen d'étendre le scope de notre lambda fonction. Par exemple si on définit une variable `a` en dehors du corps de la lambda. Pour utiliser cette variable `a` dans la fonction anonyme, sans passer `a` comme argument de la fonction, il faut ajouter `a` au scope de la lambda via le capture. 

\snippet ./src/lambda_example.cpp lambda_copy_capture

La définition du capture suit des règles similaires à celles du passage d'argument à une fonction. Par défaut lorsque dans l'exemple précédent nous avons ajouté `a` au scope de la fonction anonyme cela s'est fait en utilisant une copie de `a` en réalité. Mais évidemment il est possible de le faire via une référence !! Et là pas de grande surprise cela passe par l'utilisation du symbole `&` ! Par exemple dans l'extrait suivant nous passons `a` par référence au scope de la lambda et il est alors possible de modifier la valeur de `a` via un appel à notre fonction anonyme. 

\snippet ./src/lambda_example.cpp lambda_ref_capture

Il existe deux syntaxes un peu particulières pour les captures il s'agit de `[=]` et `[&]`. Le principe avec ces syntaxes est de capturer tout les variables présentes dans le scope de **définition** de la lambda, que ce soit respectivement par copie ou bien par référence. 

\snippet ./src/lambda_example.cpp lambda_copy_all_capture

\snippet ./src/lambda_example.cpp lambda_ref_all_capture

Enfin, voici une capture un peu particulière. Depuis `C++11` on peut demander qu'une variable *capturée par copie* dans une lambda puisse être modifiée. En quoi c'est différent d'une capture par référence ? parce que la modification n'est effective que dans la lambda. 

\snippet ./src/lambda_example.cpp mutable 

\snippet ./src/lambda_example.cpp mutable_call 

**Remarque :** le mot clé `mutable` a en réalité d'autres usages possibles et ne se limite pas uniquement aux fonctions anonymes. 


### Un exemple concret 

Quel intérêt de faire des fonctions anonymes ? Plein !!! L'intérêt majeur est de ne pas polluer tout son code avec des fonctions accessoires qui ne servent qu'une fois. Par exemple imaginons que l'on ait une fonction `forEach` qui mange un `std::vector` et une fonction et applique la fonction à chaque élément du `std::vector`.  

\snippet ./src/lambda_example.cpp for_each_call 

Dans ce cas il est plus simple et plus propre de définir une fonction anonyme qui calcul le carré d'un nombre plutôt que de faire une fonction globale qui n'aurait que peu d'intérêt. 

# Manipuler des fonctions comme des variables 

## Pourquoi pas mais dans quel but ? 

Dans l'exemple précédent, cela vous a peut-être choqué ... ou pas (et vous noterez au passage le travail de transition entre les parties), nous avions une fonction `forEach` et j'ai donné a mangé à cette fonction une fonction anonyme... Rien qui vous choque ? Et oui nous avons donné comme argument d'entrée une fonction donc nous avons utilisé une fonction comme une variable. Et c'est super pratique car c'est ce qui va permettre de faire du code générique et ça c'est cool ! 

Par exemple imaginons que, pour une raison quelconque, nous devions résoudre une équation non-linéaire via la méthode de Newton. \f$\cos(x) - x^3 = 0 \f$. Une implémentation possible serait la suivante : 

\snippet ./src/functor_example.cpp newton_no_functor 

Et à l'usage cela donnerai alors : 

\snippet ./src/functor_example.cpp newton_no_functor_call 

Mais dans ce cas notre fonction `newton` ne peut servir qu'à la résolution de cette équation et pas une autre. Alors que si on réfléchit un peu ce serait plus sympa d'avoir une fonction newton qui mange une fonction `f` l'équation à résoudre et une fonction `df` la dérivée. Car ainsi nous aurions un résolution de newton utilisable pour tout nos problèmes ! C'est ce qu'on va voir tout de suite ! 


## Le foncteur moderne 

Le fait de manipuler une fonction comme une variable se fait à l'aide de ce qu'on appel un foncteur, comprendre pointeur de fonction. L'utilisation de foncteur a toujours été possible en C++ néanmoins, comme pour d'autres choses la norme C++11 a introduit une bonne couche de simplicité ! 

Tout d'abord, comme toujours, il faut faire le bon include à savoir ici la librairie `functionnal`. 

\snippet ./src/functor_example.cpp include

Cette librairie défini un nouveau type le `std::function` qui va nous permettre de définir nos variables fonctions. L'utilisation du `std::function` se fait de la manière suivante : 

```
std::function<type_out(type_in1, type_in2, ...)>
```
Regardons alors ce que l'on peut faire avec ça pour notre fonction `newton`. 

\snippet ./src/functor_example.cpp newton_functor 

Vous voyez donc que l'on a définit deux arguments d'entrée qui sont des `std::function<double(double)>` et qui vont donc représenter les fonctions `f` et `df`. Nous pouvons alors utiliser `f` et `df` comme des fonctions classiques dans le corps de la fonction `newton` et ainsi avoir un algorithme générique ! 

Cela donne alors à l'usage : 

\snippet ./src/functor_example.cpp newton_functor_call_glob

Un autre truc sympa des `std::function` est qu'ils permettent d'encapsuler indifférement des fonctions globales ou des fonctions anonymes. Ainsi nous aurions pu écrire notre problème via des fonctions anonymes : 

\snippet ./src/functor_example.cpp newton_functor_call_lambda1

Ou bien de manière encore plus conscise : 

\snippet ./src/functor_example.cpp newton_functor_call_lambda2


## Imposer des valeurs de paramètres 

Un autre utilitaire introduit par la librairie `functional` est la fonction `std::bind` qui va permette de fixer certains paramètres d'entrée sur des fonctions. Par exemple imaginons que mon problème que je cherche à résoudre par la méthode de newton dépende d'un paramètre : 

\snippet ./src/functor_example.cpp model 

Dans ce cas la signature des mes fonctions change et ma super fonction `newton` générique ne fonctionne plus ... mince ! Une solution serait de tricher un peu en utilisant des lambda par exemple : 

\snippet ./src/functor_example.cpp bind_manual

Cela fait le boulot mais c'est pas forcément ce qu'il y a de plus sympa ! Alors qu'il existe la fonction `std::bind` qui va vous permettre simplement de faire la même chose. Par exemple : 

\snippet ./src/functor_example.cpp bind_std

Ainsi les variables `f` et `df` seront des fonctions d'une seule variables. Vous voyez au passage apparaître le `std::placeholder::_1` cela permet de dire que le premier argument de `f` devra être transmis à `fnewton2`. 

Un autre intérêt de `std::bind` est de permettre de faire de la composition de fonction. Par exemple pouvez vous deviner ce que fait le code ci-dessous ? 

\snippet ./src/functor_example.cpp bind_composition

```
f(x) = 1.11022e-16
```


# Allons un peu plus loin 

Il est heureusement possible de séparer la **déclaration** des fonctions de leur **définition** pour optimiser les codes.

En effet, dans un code qui appelle une fonction, `C++`, pour faire ses habituelles vérifications de types, n'a besoin que du prototype de la fonction et pas du corps; le corps de la fonction peut être lui vérifié à un autre moment de la compilation.

On va donc pouvoir **déclarer** une fonction i.e. donner son prototype en remplaçant son corps par `;` et utiliser cette fonction. Bien sûr puisque vous l'utilisez, `C++`, pour faire votre exécutable, devra trouver le corps de la fonction quelque part. Ce code indiquera toute la fonction: prototype+corps.

Voyons un exemple:

\snippet ./src/function_declaration.cpp all


## Séparation dans différents fichiers 


### Compilation "monolitique" 

### Compilation en une librairie et un executable 

### Automatisons tout ça : CMake ! 

# Une fonction qui marche pour tout type c'est possible ? 

## La limitation du c++ 

\snippet ./src/template_example.cpp print_specific_int_call 

\snippet ./src/template_example.cpp print_specific_int 

\snippet ./src/template_example.cpp print_specific_double_call 

\snippet ./src/template_example.cpp print_specific_double


## La notion de template 

### La grande idée ! 

### Définition d'une fonction template 

\snippet ./src/template_example.cpp print_template

\snippet ./src/template_example.cpp print_template_call

\htmlonly
<iframe width="100%" height="500px" src="https://cppinsights.io/s/040a23ff"> </iframe>
\endhtmlonly

### Les paramètre templates 

\snippet ./src/template_example.cpp increment 

\snippet ./src/template_example.cpp increment_call


\snippet ./src/template_example.cpp increment_default
\snippet ./src/template_example.cpp increment_default_call

\snippet ./src/template_example.cpp increment_no_cast
\snippet ./src/template_example.cpp increment_no_cast_call

### Branchement à la compilation dans les templates (C++17)

\snippet ./src/template_example.cpp fibonacci 

\htmlonly
<iframe width="100%" height="500px" src="https://cppinsights.io/lnk?code=dGVtcGxhdGU8aW50IE4+CmludCBmaWJvbmFjY2koKXsKICAgIGlmIGNvbnN0ZXhwciggTiA9PSAwKXsKICAgICAgICByZXR1cm4gMDsKICAgIH0KICAgIGVsc2UgaWYgY29uc3RleHByKCBOID09IDEpewogICAgICAgIHJldHVybiAxOwogICAgfQogICAgZWxzZXsKICAgICAgICByZXR1cm4gZmlib25hY2NpPE4tMT4oKSArIGZpYm9uYWNjaTxOLTI+KCk7CiAgICB9Cn0KCmludCBtYWluKCl7CiAgCiAgYXV0byBmNCA9IGZpYm9uYWNjaTw0PigpOwogIAogIHJldHVybiAwOyAKfQogIA==&insightsOptions=cpp2a&std=cpp2a&rev=1.0"> </iframe>
\endhtmlonly





### La notion de traits

## C++20 et les fonctions génériques 

### Du template en mode super simple 

\snippet ./src/template_example.cpp print_auto 

### Retrouver le type ! 


## Mettons quelques règles en place ! 

### La notion de concept 
\snippet ./src/concept_example.cpp include

\snippet ./src/concept_example.cpp increment_base

```
concept_example.cpp:8:16: error: invalid ‘static_cast’ from type ‘int’ to type ‘x_t’ {aka ‘const char*’}
    8 |     return x + static_cast<x_t>(N);
      |                ^~~~~~~~~~~~~~~~~~~
```

\snippet ./src/concept_example.cpp increment_concept


```
concept_example.cpp:18:23: error: no matching function for call to ‘increment(const char [7])’
   18 |     auto z = increment("coucou");
      |              ~~~~~~~~~^~~~~~~~~~
concept_example.cpp:6:6: note: candidate: ‘template<int N, class auto:3>  requires  integral<auto:3> auto increment(auto:3)’
    6 | auto increment( std::integral auto  x ){
      |      ^~~~~~~~~
concept_example.cpp:6:6: note:   template argument deduction/substitution failed:
concept_example.cpp:6:6: note: constraints not satisfied
```

La notion de concept peut également s'utiliser avec les templates plus classiques en utilisant l'instruction `requires`. La syntaxe générale est la suivante : 

```
template<typename T>
requires LeConcept<T>
type_sortie nomFonction( ... ){

}
```

En pratique si on reprend la fonction incrémente cela donne : 

\snippet ./src/concept_example.cpp increment_concept_template 

### Une librairie de concepts 

Il existe un ensemble de concepts pré-définis dans la librairie standard c++ au sein de la librairie `concepts`. Pour une liste exhaustive je vous encourage fortement à faire un tour sur [https://en.cppreference.com/w/cpp/concepts](https://en.cppreference.com/w/cpp/concepts) vous trouverez l'ensemble des concepts pré-existants. 

Parmi ceux dans le même esprit que ce qu'on a vu juste au-dessus il y a : 

- `std::integral` : qui contraint l'argument à être de type intégral 
- `std::floating_point` : qui contraint l'argument à être de type flottant
- `std::signed_integral`
- `std::unsigned_integral` 

Il existe cependant d'autre type de concepts. Par exemple 

\snippet ./src/concept_example.cpp increment_concept_convertible


### Définir ses propres concepts 


```
template<typename T, ...>
concept ConceptName = contrainte
```

```
template<typename T, ...>
concept ConceptName = requires(T a, ...){
  { expression } -> return-type (optional);
};
```

\snippet ./src/concept_example.cpp concept_is_iterable 

\snippet ./src/concept_example.cpp print_with_concept 


Pour les conteneurs il existe de nombreux concepts déjà définis dans la librairie `ranges` que l'on va voir dans le chapitre suivant ! 


