
Déclaration de variables et quelques mots sur la mémoire {#variableSection}
============

Dans cette partie nous allons voir comment définir des variables en `C++` et ce qui se cache derrière. Parce qu'il faut bien l'avouer vous avez l'habitude de définir des variables en `python` mais ce dernier vous cache beaucoup de choses, normal c'est son rôle de langage de haut niveau. 

[TOC]

# Une variable c'est quoi ? 

## La mémoire 

Dans votre ordinateur il y a trois choses réellement importantes : 

- le processeur 
- la mémoire vive ou RAM 
- le disque dur 

Tout le reste n'est qu'accessoire, c'est du bonus. Nous pourrions même considérer le disque dur comme accessoire dans certains cas mais c'est un autre débat. 

Quel rapport avec les variables ? Ça dépend de ce qu'est une variable pour vous. Concrètement une variable peut être vue comme une *étiquette* à laquelle on associe une *valeur* mais concrètement cette valeur où est-elle ? Et bien elle est stockée dans la mémoire vive de votre ordinateur. Donc une variable ce n'est rien d'autre qu'un petit bout de la RAM dans lequel vous pouvez ranger des valeurs. 

Un petit bout ok mais petit comment ? Et bien c'est la grande question, le truc que vous cache `python` et que le `C++` vous révèle: la taille du morceau de RAM associé à une variable dépend de ce que l'on va vouloir ranger dans cette variable... et oui c'est ça la vraie vie !!

## Notion de type 

Donc la dimension du morceau de RAM affecté à une variable dépend de ce qu'on va mettre dans la variable en question. C'est ce que l'on appelle la notion de typage. En effet si, par exemple, je veux ranger dans une variable `a` un nombre flottant double précision, il me faudra un zone mémoire de 64 bits (8 octets) tandis que si dans une variable `b` je veux stocker un nombre entier une zone mémoire de 32 bits (4 octets) me suffira. 

En `python` toute cette tringlerie est cachée car `python` est un langage à typage dynamique, c'est à dire la gestion de la mémoire est faite dynamiquement au runtime (lors de l'exécution). Tandis qu'en `C++` tout doit être spécifié à la compilation. L'intérêt est que l'on utilise la mémoire avec beaucoup plus de justesse, cela contribue au fait que `C++` est un langage plus performant.

Donc en `C++` il faudra toujours, au moment de déclarer une variable, spécifier son type. Cela se fait avec la syntaxe suivante 

```
<type> ma_variable;
```

Où `<type>` doit être un type `C++`. 

## Un mot sur le nommage des variables 

Pour information, `C++` impose quelques règles, concernant le nom des variables, qui ne peuvent pas être transgressées: 

- un nom de variable est constitué de lettres, chiffres et du symbole underscore 
- le premier caractère est forcément une lettre
- un nom de variable ne peut comporter aucun espace 

**Remarque :** depuis `C++11` il est possible d'utiliser n'importe quel caractère unicode dans des fichiers sources `C++` pour les noms de variables. 
Par exemple on peut donc choisir des variables avec accents 
\snippet ./src/example_unicode.cpp accent

Ou encore avec des lettres grecs, si l'on est puriste et que l'on veut rester proche de ses équations. 

\snippet ./src/example_unicode.cpp unicode 

Mais, de manière générale, il est plutôt recommandé de rester sur une approche *old-school*, à savoir: tout en anglais, sans accent ni caractère bizarre.

Pour ce qui est de la convention de nommage des variables, il n'y a pas de convention unique comme en `python` avec la PEP 8. Chacun fait un peu comme il le souhaite. Cependant il y a certains standards de style qui ont été définis notamment pour des gros projets. Par exemple on peut trouver la convention Google [https://google.github.io/styleguide/cppguide.html](https://google.github.io/styleguide/cppguide.html) ou bien des recommandations du commité de normalisation c++ [https://isocpp.org/wiki/faq/coding-standards](https://isocpp.org/wiki/faq/coding-standards). 

# Type intégraux 

Les premiers types que nous allons voir sont les types numériques, qui permettent donc de définir des nombres. 

## Entiers

Tout d'abord pour définir les entiers on utilise le type `int` pour `integer`.

\snippet ./src/example_int.cpp integraux 

- Les entiers `int` (en général) sur 32 bits
- Les entiers non signés `unsigned int` sur 32 bits  
- Les entiers "courts" `short int` sur 16 bits

Le nombre de bits sur lequel est stocké la valeur de l'entier va alors permettre de connaître l'étendue des valeurs possibles. Par exemple un entier signé sur 32 bits pourra avoir des valeurs entre -2.147.483.648 et +2.147.483.647. Tandis que le même entier, mais non signé, sur 32 bits pourra avoir des valeurs entre 0 et 4.294.967.295. 

Il existe depuis le `C++11` un moyen plus simple de savoir les valeurs minimales et maximales d'un type numérique: il s'agit des fonctionnalités présentes dans `numeric_limits`. Par exemple, pour afficher les valeurs min et max représentables par des entiers, nous pouvons faire : 

\snippet ./src/num_limits_int.cpp all


Ce qui à l'exécution nous affichera le message suivant : 
```
short int: -32768 -> 32767
int: -2147483648 -> 2147483647
unsigned int: 0 -> 4294967295
```

Les entiers peuvent, en réalité, être de différents types. La liste des types possibles est: `char`, `short` (ou short int), `int`, `long` (ou long int) et `long long` (ou long long int). Tous peuvent être non-signés avec `unsigned` ou signés avec `signed`.

La taille de la mémoire, pour stocker ces différents types intégraux, diffère suivant les ordinateurs et les compilateurs. La norme du langage nous dit simplement que, dans la liste `char`, `short`, `int`, `long` et `long long`, chaque type fournit au moins autant de stockage (de bits) que les types qui le précèdent dans la liste.

## Flottants 

### Représentation des nombres flottants 

Le second type numérique disponible dans le `C++` est celui qui va permettre de représenter des nombres flottants. Il faut noter que la représentation en mémoire des nombres flottants est un peu plus complexe que celle des entiers. En effet pour les entiers c'est simple on convertit le nombre en base 2 et le tour est joué. Pour les flottants, on ne peut malheureusement pas faire ça. 

Pour stocker en binaire un nombre flottant il existe une norme, la norme IEEE 754 [https://en.wikipedia.org/wiki/IEEE_754](https://en.wikipedia.org/wiki/IEEE_754). Cette dernière définit comment on représente sous forme binaire un nombre flottant. Et surtout elle précise comment la représentation se fait suivant l'espace mémoire que l'on souhaite allouer pour stocker une valeur flottante. 

Car en effet on considère classiquement deux types de valeurs flottantes : 

- Les `float` stockés sur 32 bits 
- Les `double` stockés sur 64 bits

### Float ou double 

Comment choisir entre `float` et `double` grande question. La règle est simple, ça dépend ... En réalité cela dépend de votre application et surtout de la précision que vous souhaitez sur vos valeurs numériques. Car avec des `float` la précision de 7 à 9 chiffres significatifs tandis qu'avec des `double` on est sur du 15 à 16 chiffres significatifs. 

De manière générale aujourd'hui les ordinateurs ont suffisamment de mémoire vive pour que l'on ne se pose pas trop de questions et que l'on utilise des `double` par défaut. 

Considérons par exemple le cas tout simple où l'on veut faire la somme de 0.1 et de 0.2. Nous pouvons écrire le code suivant : 

\snippet ./src/example_float.cpp all

Le résultat que l'on obtient alors à l'exécution est le suivant : 

```
precision : 6
a + b = 0.30000001
precision : 15
a + b = 0.30000000000000004
```


## Le type un truc pas si anecdotique que ça 

Alors nous l'avons dit en introduction de cette partie la notion de type est importante car c'est elle qui va permettre de gérer la mémoire et ainsi faciliter la vie du compilateur. Il y a cependant un autre aspect tout aussi important, voir plus, des types qui est que le type d'une variable va définir son comportement. Autrement dit certaines opérations en présence d'un type vont faire quelque chose tandis qu'en présence d'un autre type feront autre choses. Et c'est d'autant plus flagrant sur les opérations mathématiques. 

Par exemple que va afficher le code suivant selon vous : 

\snippet ./src/operation_type.cpp nomix 

```
int_a / int_b=0
f_a / f_b=0.333333
```

Cela vous semble-t-il normal ou pas ? Et bien oui c'est normal pour `C++`. Car dans le standard il est écrit que la division de deux entiers est une division entière. Dit comme ça c'est logique en plus ! 

Donc le choix du type va directement impacter le comportement de notre programme. 

Vu que vous êtes curieux vous vous demandez certainement mais qu'est ce qui se passe si je fais la division entre un entier et un flottant ? Vous avez raison de vous poser cette question ! Le meilleur moyen de savoir c'est de tester : 

\snippet ./src/operation_type.cpp mix 

A l'exécution ce code nous donne le résultat suivant : 
```
f_a / int_b=0.333333
int_a / f_b=0.333333
```

Et donc là visiblement le C++ a choisi la division flottante. Mais pourquoi ? Tout simplement parce qu'en fait, ce qu'il y a de caché derrière, c'est le mécanisme de promotion de type. Le principe est le suivant le compilateur lorsqu'il arrive sur l'expression `f_a / int_b`, par exemple, regarde cette expression et se dit : "j'ai un `int` et un `float` est-ce que j'ai quelque part l'opération de division d'un float par un int ?". La réponse est non: il existe la division d'un `float` par un `float`, d'un `double` par un `double`, d'un `int` par un `int` mais pas de mélange des types. Face à cette difficulté, le compilateur, très débrouillard ce garçon, se dit bon ok est-ce que je sais convertir l'un des deux arguments dans le type de l'autre ? Et là oui il sait même faire les deux: convertir un `float` en `int` et un `int` en `float`. Alors là grande question "quelle conversion choisir ?" C'est là où apparaît la promotion de type, le principe est simple: face à ce dilemme le compilateur va choisir la conversion pour laquelle il est certain qu'il ne perdra aucune information. Et donc ici c'est la conversion de `int_b` en `float`.

***Minute papillon*** ça veut dire qu'on peut changer le type d'une variable ?  

## Caster des variables 

Alors on ne peut pas exactement changer le type d'une variable. En revanche on peut créer une copie du contenu d'une variable dans un nouveau type. 

Par exemple considérons le code suivant : 

\snippet ./src/example_cast.cpp implicit 

On définit une variable de type `double` et ensuite on range la valeur de cette variable dans une variable de type `int`. Implicitement on fait une conversion. Dans ce cas c'est le compilateur qui fait le travail pour nous. Mais nous pourrions très bien l'expliciter en utilisant la fonction `static_cast<type>(variable)`. Cela donnera dans ce cas : 

\snippet ./src/example_cast.cpp explicit

Pour le moment l'intérêt est assez limité mais nous verrons dans la partie Programmation Orientée Objet qu'il y a en fait un réel intérêt à cela. 

Après il peut y avoir quelques risques à faire du cast. Par exemple : 

\snippet ./src/example_cast.cpp static_overflow 

Ce code va fonctionner en revanche le résultat que l'on obtient est le suivant : 

```
value: 32777
sivalue: -32759
```

# Les booléens 

Le second grand type du `C++`, qui est aussi le plus simple c'est les booléens, le type `bool`. Un booléen ne peut avoir que deux valeurs `true` ou `false`. 

Vient avec le type booléen, bien évidemment, les opérations d'algèbre booléenne, à savoir le `and`, le `or` et la négation `not`. Ces trois opérations sont symbolisées respectivement par `&&`, `||` et `!`. Cela donne par exemple : 

\snippet ./src/example_bool.cpp all

Ce qui à l'exécution nous affiche les résultats suivants : 
```
vrai: true
faux: false
!vrai: false
!faux:true
vrai && faux:false
vrai||faux: true
```
Au passage, les plus attentifs auront peut-être remarqué que, pour les expressions avec les `&&` et `||`, il a fallu mettre des parenthèses autour de l'expression. Ce n'est pas pour le style mais il s'agit d'une nécessité pour que le programme compile. Pourquoi ? A cause de la précédence des opérateurs. Si vous êtes curieux, vous pouvez regarder le lien suivant et vous devriez comprendre [https://en.cppreference.com/w/cpp/language/operator_precedence](https://en.cppreference.com/w/cpp/language/operator_precedence). 

# Les chaines de caractère 

Pour finir nous allons voir comment définir des chaînes de caractères. Alors pour cela nous allons faire la distinction entre le `C++` old-school et le `C++` moderne, car les deux ont des approches quelques peu différentes. Avec bien évidemment encore une fois un `C++`  moderne qui va grandement nous faciliter la vie. 

## Dans le monde d'avant 

Dans le `C++` du monde d'avant, je ne parle pas du monde avant Covid, les chaînes de caractères n'existaient tout simplement pas. En revanche il existait, et existe toujours d'ailleurs, le type `char`. Le type `char` permet de représenter **un** caractère.

La définition d'un `char` se fait de la manière suivante : 

\snippet ./src/example_string.cpp char 

Les caractères pouvant être pris en charge avec le type `char` sont assez limités puisqu'il s'agit uniquement des 127 caractères de la table ASCII [https://fr.wikibooks.org/wiki/Les_ASCII_de_0_%C3%A0_127/La_table_ASCII](https://fr.wikibooks.org/wiki/Les_ASCII_de_0_%C3%A0_127/La_table_ASCII)

Toute la difficulté apparaît lorsque l'on veut travailler avec des chaînes de caractère. En `C++` pré-historique une chaîne de caractère n'est rien de plus qu'un tableau de `char`... Rien de bien subtile me direz vous. 

D'ailleurs je vous ai dit, dans le chapitre d'intro, que la fonction `main` (le fameux point d'entrée des programmes) peut prendre des arguments d'entrée: il s'agit des arguments passés à la suite de l'appel du programme. Et bien il s'agit d'un tableau de tableau de `char`. Cela se symbolise par `char**`. Par exemple nous pourrions faire la fonction `main` suivante : 

\snippet main_args.cpp all

La compilation `g++ main.cpp` et l'exécution donneraient alors : 

```
$ ./a.out arg1 arg2
0: ./a.out
1: arg1
2: arg2
```

## En `C++` "moderne" 

Dans le monde moderne, il existe un type permettant de gérer nativement et **simplement** des chaînes de caractères: il s'agit du type `std::string`. La définition d'une `string` en `C++` se fait en utilisant les guillemets. C'est bizarre, pourquoi le `std::` devant `string` ? Très bonne question ! Le `std::string` est un type un peu particulier dans le sens où il s'agit en réalité du premier type que l'on voit qui n'existait pas du tout dans le `C`. Ce type fait donc partie de la librairie standard `C++` et nécessite donc un `include` associé. Pour utiliser des `std::string` il ne faut donc pas oublier de faire : 

\snippet ./src/example_string.cpp string_include 

Ensuite vous pouvez très facilement définir un `std::string` de la manière suivante : 

\snippet ./src/example_string.cpp string 

L'intérêt des `std::string` par rapport aux chaînes de caractère old-school est tout d'abord la simplicité d'utilisation et ensuite, le fait qu'il existe plein d'opérations sur les `std::string`. Par exemple, reprenons le fait que, suivant les types en présence des opérateurs, ils n'ont pas le même comportement. Et bien l'opérateur `+` a un comportement pour les `std::string` qui est la concaténation. Typiquement nous pouvons écrire : 

\snippet ./src/example_string.cpp string_sum 

Et il existe plein d'opérations utiles disponibles instantanément, pour une liste exhaustive [ici](https://en.cppreference.com/w/cpp/string/basic_string). 

Voici, par exemple, deux opérations très utiles ayant été ajoutées récemment (dans la norme C++20)

\snippet ./src/example_string.cpp selection 


# Astuce 

***Petite astuce !*** Il peut arriver, suivant les applications, que l'on souhaite faire différentes versions d'une même librairie ou d'un même programme; la différence entre les versions reposant sur les types utilisés. Par exemple pour tout ce qui est algèbre linéaire il peut être pertinent suivant les applications d'avoir une version d'une librairie utilisant des `double` pour les réels mais également d'avoir une autre version de la même librairie utilisant des `float`. 

Pour faire ça, vous vous doutez certainement que faire un chercher remplacer `double` par `float` ne va sûrement pas être la solution pérenne. Mais il est possible de définir des alias de type en `C++` qui peuvent vous permettre d'avoir un comportement similaire. Cette définition d'un alias de type se fait en utilisant le mot clé `using`. Si par exemple je veux définir un type `Real` qui par défaut correspondra à un `double` mais que facilement je puisse le changer à `float`. Il me suffit de procéder de la manière suivante : 

\snippet ./src/type_using.cpp using_real_double 

Et donc dans toute la suite de mon code il me suffit d'utiliser le type `Real`. Cela permet, le jour où je veux me faire une version simple précision de ma librairie, de n'avoir besoin de changer le type qu'au niveau de la déclaration de `Real` et ensuite tout le reste du code s'adapte 

\snippet ./src/type_using.cpp using_real_float 


# Définir des variables 

## Ne pas confondre déclaration et affectation 


Attention, un point important en `C++` est que la déclaration d'une variable peut être indépendante de l'affectation d'une valeur à cette dernière. Cela peut sembler bizarre quand on vient du `python` mais en fait c'est logique. Par exemple, si je veux définir une variable `value` qui devra contenir un entier. Je ne sais pas nécessairement, au moment où je définis cette variable, la valeur qu'elle va contenir. 

La déclaration se fera donc de la manière suivante : 

```
int value;
```

Et ensuite dans un second temps je peux affecter une valeur à cette variable, par exemple `10`. 

```
value = 10; 
```

Néanmoins si au moment de la déclaration, on veut en même temps affecter une valeur à notre variable, c'est possible de trois manières différentes : 

```
int value = 10; 
```

ou bien 

```
int value(10);
```

ou enfin la notation, valide uniquement en `C++11`

```
int value {10};
```

Seule la troisième manière vous signalera d'éventuels problèmes d'overflow de la valeur quand la taille mémoire prévue pour le type n'est pas suffisante pour contenir la valeur. 

## La déduction de type via decltype ou auto 

Depuis le `C++11`, oui encore je sais, il a été introduit un concept particulier qui permet d'alléger un peu le côté typage statique fort du langage `C++`. Il s'agit de la déduction de type. En effet il est maintenant possible de demander au compilateur de déduire du contexte le type d'une variable. 

La déduction de type se fait via le mot clé `auto`. Ce dernier va venir remplacer le type d'une variable et c'est à la compilation que le `auto` sera substitué par un vrai type `C++`. Par exemple considérons le code suivant : 

\snippet ./src/deduction_example.cpp deduction_auto 

Dans cet exemple on crée une variable `a` de type `int`. Et ensuite on crée une variable `b` de type `auto` que l'on initialize avec la valeur de `a`. Dans ce cas la déduction est très simple car `b` va hériter du type de `a`. 

Il peut arriver, dans des cas un peu tordus, que le compilateur n'arrive pas à déduire le type de la variable déclarée `auto` et, dans ce cas, nous avons à la compilation une erreur de type `type deduction failed`. 

Il existe une autre manière de faire de la déduction de type, un peu plus souple, qui repose sur l'utilisation de `decltype`. Regardons l'exemple suivant, qui ressemble beaucoup au premier : 

\snippet ./src/deduction_example.cpp decltype 

Dans cet exemple, on définit une variable `a` de type `int`. On utilise alors `decltype(a)`, ce qui va alors nous donner le type de la variable `a` ici `int`, pour déclarer une variable `b`. Autrement dit on a donc déclaré une variable `b` du même type que `a`. Cela permet alors de déclarer la variable `b` sans avoir avoir à lui affecter la valeur de `a`, comme nous avions dû le faire avec `auto`. 

De plus en utilisant le mot clé `using` nous pouvons alors définir un nouveau type que l'on peut ensuite utiliser comme un type classique. Par exemple : 

\snippet ./src/deduction_example.cpp decltype_using 


## Les qualificateur de variable 

Lorsque l'on définit une variable on lui associe donc un type, ou bien on laisse le compilateur déduire le type. Mais il est possible de fournir des informations additionnelles sur les variables via les qualificateurs. 

L'intérêt de donner des informations additionnelles est que plus le compilateur connaît de chose à la compilation plus efficace il sera. Autrement dit, suivant les informations que l'on fournit au compilateur, ce dernier pourra potentiellement faire des optimisations de votre code pour vous. Et ça c'est quand même sympa !

L'utilisation de ces qualificateurs se fait toujours de la manière suivante : 

```
qualifier type variableName {value};
```

### Le qualificateur `const` 

Le premier qualificateur de variable que l'on va rencontrer et que l'on risque de retrouver régulièrement est le `const`. Le qualificateur `const` va permettre de déclarer qu'une variable est constante et donc que sa valeur ne changera **jamais**. 



### Le qualificateur `constexpr` 

Le second qualificateur de variable est le `constexpr`. Ce dernier est encore plus fort que le `const` dans le sens où il indique au compilateur que la variable en question est pleinement connue au moment de la compilation. Quel intérêt ? Et bien cela permet de faire des calculs à la compilation plutôt qu'au run-time. 

Par exemple pour définir une variable `constexpr` on procède de la manière suivante : 

\snippet ./src/qualifier_example.cpp constexpr

Tout l'intérêt va alors être de pouvoir faire du calcul à la compilation : 

\snippet ./src/qualifier_example.cpp constexpr_calc

Si vous n'êtes pas convaincu vous pouvez regarder le détail içi [https://godbolt.org/z/Y4z7cEc8e](https://godbolt.org/z/Y4z7cEc8e)

### Le qualificateur `volatile` 

Enfin le dernier qualificateur que l'on va voir est le `volatile` son usage est beaucoup moins courant que les deux précédents mais vous pouvez le croiser de temps en temps. Le fait de déclarer une variable comme `volatile` est un moyen de dire au compilateur, ne t'occupe pas de cette variable, t'es pas capable de la gérer, du coup ne fait pas d'optimisation dessus. 

Typiquement si on considère le bout de code suivant : 

```
int some_int = 100;

while(some_int == 100)
{
   //your code
}
```

Si dans le bloc d'instruction on ne touche pas à la valeur de `some_int`, il est très probable que le compilateur fasse une optimisation un peu brutale du genre remplacer le `some_int==100` par un `true` ce qui accélérerait l'exécution. Or il se peut que l'on ait *designé* le code de telle sorte qu'il y a bien un élément quelque part qui change la valeur de la variable `some_int` mais le compilateur ne s'en rend pas compte. Dans ce cas le code généré par le compilateur n'est pas conforme à ce que l'on attend. La solution pour résoudre ce problème est alors de dire au compilateur de ne pas chercher à faire des optimisations trop agressives concernant cette variable. Pour cela il suffit de la déclarer comme `volatile` ce qui donnerait alors : 

```
volatile int some_int = 100;

while(some_int == 100)
{
   //your code
}
```

## Fournir des entrées à un programme 

Généralement un programme informatique, opère sur des données fournies par un utilisateur c'est données peuvent être de différentes natures :

- Un fichier texte à traiter 
- Un paramètre qui va définir certains comportement du programme
- Une addresse url a aller interrogée 
- ... 

Peut importe la nature de la données d'entrée dans tous les cas nous allons avoir une variable dont la valeur va dépendre de ce que l'utilsateur souhaite faire. La question qui se pose alors est comment permettre à l'utilisateur de fournir cette valeur dont on a besoin ? La première solution qui pourrait nous venir en tête serait de dire à l'utilisateur de modifier la ligne XYZ du fichier `main.cpp` et de recompiler le programme.... Bon on sent bien que ce n'est pas vraiment la solution optimale pour plein de raisons. 

Du coup pour avoir quelque chose de plus simple d'utilisation pour l'utilisateur final ne serait-il pas plus simple d'ajouter à notre programme des portions de code qui interrogerai l'utilisateur sur quelles sont les données à traiter ? La réponse et **oui** évidemment !! Pour cela nous avons deux approches possibles pour interragir avec l'utilisateur. 

- La première approche est de permettre à l'utilisateur de fournir au lancement du programme des arguments à la ligne de commande. Par exemple dans le cas d'un programme qui doit traiter les données d'un fichier csv nous pourrions faire quelque chose du genre : 
```
$ ./mon_programme.out mon_fichier.csv
```
et dans le code nous pourrons récupérer le nom du fichier `mon_fichier.csv` a traiter. 

- La deuxième approche possible est d'ajouter dans le code à certains moments l'instruction `std::cin` qui va permettre de demander à l'utilisateur de saisir du texte dans le terminal que l'on récupérera alors comme variable. Cela donnerai par exemple : 
```
$ ./mon_programme.out 
Nom du fichier: <saisie utilisateur>
```

### Passage d'argument à la ligne de commande 

La première solution, à savoir passer des arguments à la ligne de commande au moment où l'on lance le programme est la solution la plus classique que l'on retrouve dans énormément de programmes qu'ils soient en c++ ou pas d'ailleur. 
 
Pour faire cela en c++ il suffit simplement de changer légèrement la fonction `main`, c'est-à-dire le point d'entrée de notre programme c++ pour lui expliquer qu'il va y a voir des arguments d'entrée au programme. Alors par contre, on ne modifie cette fonction main comme on le souhaite, il y a une convention à suivre impérativement, sinon le programme de compile tout simplement pas. La convention est la suivante : 

```
int main( int argc, char** argv){
   // votre code ensuite 
}
```

Nous venons donc de dire à notre fonction `main` qu'elle va avoir deux `inputs` à savoir : 

- `argc` de type `int`: il s'agit du nombre d'argument qui sera fourni au programme à l'exécution ***+1***. Plus un car c++ considère que le premier argument c'est le nom du programme lui-même ! 
- `argv` de type `char**`: que veut dire cette syntaxe cabalistique ? Alors là oui désolé mais c'est hérité du C. Un peu plus haut je vous ais dit que dans le monde d'avant une chaine de caractère n'était rien de plus qu'un tableau de `char` que l'on pouvait définir comme étant de type `char*`. Bon et bien là le `char**` veut juste dire que l'on a un tableau de tableau de caractères. Ce tableau contiendra donc l'ensemble des arguments fournis à la ligne de comme **+1** car le premier argument est le nom du programme. La taille de ce tableau est donc égale à `nargc` 

Par exemple si on reprend le cas d'un programme qui doit traiter un fichier csv nous pourrions écrire quelque chose du genre : 

\snippet ./src/example_argv.cpp all

### Interrogation de l'utilisateur 

La seconde solution envisageable quand il s'agit d'interragir avec l'utilisateur est d'ajouter dans votre code des instructions `std::cin` qui vont permettre d'interrompre le programme en attendant une saisie de l'utilisateur. 

Pour utiliser `std::cin` il ne faut pas oublier de faire l'include correspondant à savoir 

```
#include <iostream>
```

Par exemple nous pouvons écrire le programme suivant : 

\snippet ./src/example_cin.cpp all

L'utilisation de `std::cin` peut sembler un peu particulière avec cette notation `std::cin >> variable` mais en fait c'est assez naturel car on injecte le flux de `std::cin`, c'est-à-dire ce qui a été saisie par l'utilisateur dans le terminal dans la variable `variable`. 

**Attention** la variable dans laquelle on injecte la saisie utilisateur doit forcément être une chaîne de caractère. 

**Remarque** : de manière générale le `std::cin` n'est pas énormément utilisé car bien que cela puisse sembler sympatique au premier abord de demander des saisies par l'utilisateur dans un programme c'est en pratique assez chiant. En effet si on place des `std::cin` dans un programme cela impliquer qu'il y aura forcément quelqu'un derrière son terminal pour donner les informations nécessaires au moment où le programme les demandes. Alors que si on fait tout en passant les infos à la ligne de commande comme nous l'avons montré précédemment et bien c'est beaucoup plus commode car on lance le programme avec toutes les infos dont il a besoin et on va prendre un café pendant que ca calcul ! 

### Les entrées uniquement des chaînes de caractères ? 

Vous vous en êtes peut-être rendu compte mais les entrées pour le moment ne sont que des chaînes de caractères. Alors comment je fais quand je veux fournir un nombre, par exemple les N premières lignes de mon fichiers CSV que mon programme doit traiter ? Et bien on lui donne un nombre mais quand vous allez le récupérer dans le monde votre c++ ce ne sera pas un nombre mais une chaîne de caractère ... Par exemple : 

\snippet ./src/example_argv_int.cpp all

Et du coup dans cet exemple j'ai bien mon nombre de ligne dans la variable `nbLineStr` mais je ne peux, en l'état, pas en faire grand chose car c'est une chaîne de caractère. Si l'on veut récupérer la valeur numérique cachée dans cette `std::string` une solution simple est d'utiliser les fonctions de la librairie `<string>` à savoir `std::stoi` dans le cas qui nous intéresse. Cela nous donne la solution suivante : 

\snippet ./src/example_argv_int2.cpp all

Dans le même registre il existe : 

- `std::stof` pour convertir en `float`
- `std::stod` pour convertir en `double`

Et si vous souhaitez, pour une raison ou une autre, réaliser l'opération inverse qui consiste en la conversion d'un nombre en chaîne de caractère vous avez la fonction `std::to_string( x )` qui fait le travail. 

# Référence vers une variable 

## Une référence c'est quoi 

Nous avons dit au début de cette page qu'une variable ce n'est rien de plus qu'une case mémoire sur laquelle on a collé une étiquette: le nom de la variable. Du coup si on a pu coller une étiquette sur une case mémoire, ne pourrait-on pas en coller d'autre ? Et bien oui et c'est à ça que servent les références ! 

Pour définir une référence il faut utiliser le symbole esperluette `&`. La syntaxe générale est la suivante : 

```
   type& reference_name = variable ;
```

Par exemple définissons un `double` et une référence vers ce `double` : 

\snippet ./src/example_reference.cpp reference_definition 

***Attention*** : la référence est forcément du même type que la variable à laquelle elle s'accroche ! 

Et donc à partir de maintenant nous pouvons indifféremment utiliser la variable directement ou sa référence pour modifier la valeur ou accéder à la valeur. 

Vous avez déjà rencontré cela dans le monde `python` en fait. Souvenez-vous : 

```
>>> l = [1,2,3,4,5]
>>> print(l)
[1,2,3,4,5]
>>> ll = l
>>> ll[0] = 10
>>> print(ll)
[10,2,3,4,5]
>>> print(l)
[10,2,3,4,5]
```

Et bien les références en `C++` c'est le même principe si ce n'est que là il faut le faire explicitement ! 

On peut également utiliser les références avec de la déduction de type, par exemple écrire quelque chose du genre : 

\snippet ./src/example_reference.cpp reference_auto



## Intérêts et dangers 

Vous pourriez alors vous demander mais quel intérêt de pouvoir accéder à une variable par différents noms ? Car concrètement c'est ce que fait une référence. Et bien pour le moment aucun je vous l'avoue mais rapidement vous allez voir il y a plein d'intérêts ! Notamment lorsque l'on commence à avoir des codes un peu touffus il peut s'avérer pertinent d'avoir des références vers des variables pour faciliter la programmation.
Un autre grand intérêt sera lorsque l'on commencera à faire des fonctions. Vous le verrez alors mais, ***attention teaser***, le fonctionnement par défaut des fonctions c++ est de faire un passage d'arguments par copie ! Et donc en utilisant les références nous allons pouvoir nous économiser un paquet de copies et ça c'est cool pour avoir du code efficace. 

Alors par contre il peut y avoir quelques dangers à utiliser des références. Je pense que vous voyez venir le truc. On peut très rapidement penser que l'on affecte une valeur à une variable alors qu'en fait il s'agit d'une référence vers une autre variable et là on commence alors à avoir des comportements étranges. Un moyen alors, qui n'est pas forcément applicable à tous les cas de figures mais qui permet au moins de se prémunir de certaines erreur parfois, est d'ajouter un qualificateur `const` aux références que l'on ne veut pas modifier cela se fait par exemple de la manière suivante : 

\snippet ./src/example_reference.cpp const_reference

Dans ce cas nous pourrons accéder à la valeur `42.0` en passant par la variable `value` ou sa référence `ref` en revanche, en passant par la référence, nous ne pourrons pas modifier la valeur. Ça peut éviter certaines bêtises ! 




