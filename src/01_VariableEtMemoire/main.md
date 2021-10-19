
Déclaration de variables et quelques mots sur la mémoire    {#variableSection}
============

Dans cette partie nous allons voir comment définir des variables en `C++` et ce qui se cache derrière. Parce qu'il faut bien l'avouer vous avez l'habitude de définir des variables en Python mais ce dernier vous cache beaucoup de choses, normal c'est son rôle de langage de haut niveau. 

[TOC]

# Une variable c'est quoi ? 

## La mémoire 

Dans votre ordinateur il y a trois choses réellement importantes : 

- le processeur 
- la mémoire vive ou RAM 
- le disque dur 

Tout le reste n'est qu'accessoire, c'est du bonus. Nous pourrions même considérer le disque dur comme accessoire dans certains cas mais c'est un autre débat. 

Quel rapport avec les variables ? Ça dépend de ce qu'est une variable pour vous. Concrètement une variable peut être vue comme une *étiquette* à laquelle on associe une *valeur* mais concrètement cette valeur où est-elle ? Et bien elle est stocké dans la mémoire vive de votre ordinateur. Donc une variable ce n'est rien d'autre qu'un petit bout de la RAM dans lequel vous pouvez ranger des valeurs. 

Un petit bout ok mais petit comment ? Et bien c'est la grande question, le truc que vous cache Python et que le `C++` vous révèle: la taille du morceau de RAM associé à une variable dépend de ce que l'on va vouloir ranger dans cette variable... et oui c'est ça la vraie vie !!

## Notion de type 

Donc la dimension du morceau de RAM affecté à une variable dépend de ce qu'on va mettre dans la variable en question. C'est ce que l'on appelle la notion de typage. En effet si, par exemple, je veux ranger dans une variable `a` un nombre flottant double précision, il me faudra un zone mémoire de 64 bits (8 octets) tandis que si dans une variable `b` je veux stocker un nombre entier une zone mémoire de 32 bits (4 octets) me suffira. 

En Python toute cette tringlerie est cachée car Python est un langage a typage dynamique, c'est à dire la gestion de la mémoire est faites dynamiquement au runtime (lors de l'exécution). Tandis qu'en `C++` tout doit être spécifié à la compilation. L'intérêt est que l'on utilise la mémoire avec beaucoup plus de justesse, cela contribue au fait que `C++` est un langage plus performant.

Donc en `C++` il faudra toujours, au moment de déclarer une variable, spécifier son type. Cela se fait avec la syntaxe suivante 

```
<type> ma_variable;
```

Où `<type>` doit être un type `C++`. 

## Un mot sur le nommage des variables 

Pour information, `C++` impose quelques règles, concernant le nom des variables, qui ne peuvent pas être transgressées: 

- un nom de variable est constitué de lettre, chiffre et du symbole underscore 
- le premier caractère est forcément une lettre
- un nom de variable ne peut comporter aucun espace 

**Remarque :** depuis `C++11` il est possible d'utiliser n'importe quel caractère unicode dans des fichiers sources `C++` pour les noms de variables. 
Par exemple on peut donc choisir des variables avec accents 
\snippet ./src/example_unicode.cpp accent

Ou encore avec des lettres grecs, si l'on est puriste et que l'on veut rester proche de ses équations. 

\snippet ./src/example_unicode.cpp unicode 

Mais, de manière générale, il est plutôt recommandé de rester sur une approche *old-school*, à savoir: tout en anglais, sans accent ni caractère bizarre.

Pour ce qui est de la convention de nommage des variables, il n'y a pas de convention unique comme en Python avec la PEP 8. Chacun fait un peu comme il le souhaite. Cepedant il y a certains standard de style qui ont été défini notamment pour des gros projets. Par exemple on peut trouver la convention Google [https://google.github.io/styleguide/cppguide.html](https://google.github.io/styleguide/cppguide.html) ou bien des recommandations du commité de normalisation c++ [https://isocpp.org/wiki/faq/coding-standards](https://isocpp.org/wiki/faq/coding-standards). 

# Type intégrales 

Les premiers types que nous allons voir sont les types numériques, qui permettent donc de définir des nombres. 

## Entiers

Tout d'abord pour définir les entiers on utilise le type `int` pour `integer`.

Les entiers peuvent, en réalité, être de différents types. La liste des types possibles est: `char`, `short` (ou `short int`), `int`, `long` (ou `long int`) et `long long` (ou `long long int`). Tous peuvent être non-signés avec `unsigned` ou signés avec `signed`.

\snippet ./src/example_int.cpp intégraux 
- Les entiers `int` sur 32 bits
- Les entiers non signés `unsigned int` sur 32 bits  
- Les entiers "courts" `short int` sur 16 bits

Le nombre de bits sur lequel est stockée la valeur de l'entier va alors permettre de connaître l'étendue des valeurs possibles. Par exemple un entier signé sur 32 bits pourra avoir des valeurs entre -2 147 483 648 et +2 147 483 647. Tandis que le même entier mais non signé sur 32 bits pourra avoir des valeurs entre 0 et 4 294 967 295. 

Il existe depuis le c++11 un moyen plus simple de savoir les valeurs minimal et maximal d'un type numérique il s'agit des fonctionnalités présentes dans `numeric_limits` par exemple pour afficher les valeurs min et max représentables par des entiers nous pouvons faire : 

\snippet ./src/num_limits_int.cpp all

La taille de la mémoire, pour stocker ces différents types intégraux, diffère suivant les ordinateurs et les compilateurs. La norme du langage nous dit simplement que, dans la liste `char`, `short`, `int`, `long` et `long long` chaque type fournit au moins autant de stockage (de bits) que les types qui le précèdent dans la liste.

Ce qui à l'exécution nous affichera le message suivant : 
```
short int: -32768 -> 32767
int: -2147483648 -> 2147483647
unsigned int: 0 -> 4294967295
```

## Flottants 

### Représentation des nombres flottants 

Le second type numérique disponible dans le c++ est celui qui va permettre de représenter des nombres flottants. Il faut noter que la représentation en mémoire des nombres flottants est un peu plus complexe que pour les entiers. En effet pour les entiers c'est simple on converti le nombre en base 2 et le tour est jouer. Pour les flottants on ne peut malheureusement pas faire ça. 

Pour stocker en binaire un nombre flottant il existe une norme, la norme IEEE 754 [https://en.wikipedia.org/wiki/IEEE_754](https://en.wikipedia.org/wiki/IEEE_754). Cette dernière défini comment on représente sous forme binaire un nombre flottant. Et surtout elle précise comment la représentation se fait suivant l'espace mémoire que l'on souhaite allouer pour stocker une valeur flottante. 

Car en effet on considère classiquement deux types de valeurs flottantes : 

- Les `float` stockés sur 32 bits 
- Les `double` stockés sur 64 bits

### Float ou double 

Comment choisir entre `float` et `double` grande question. La rêgle est simple, ça dépend ... En réalité cela dépend de votre application et surtout de la précision que vous souhaitez sur vos valeurs numériques. Car avec des `float` la précision de 7 à 9 chiffres significatifs tandis qu'avec des `double` on est sur du 15~16 chiffres significatifs. 

De manière générale aujourd'hui les ordinateurs ont suffisamment de mémoire vive pour que l'on ne se pose pas trop de question est que l'on utilise des `double` par défaut. 

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

division int/int, int/float 


# Les booléens 


# Les chaines de caractère 

## Dans le monde d'avant 

## En `C++` "moderne" 


# Astuce 

***Petite astuce !*** Il peut arriver, suivant les applications, que l'on souhaites faire différentes versions d'une même librairie ou d'un même programme. La différence entre les versions reposant sur les types utilisés. Par exemple pour tout ce qui est algèbre linéaire il peut être pertinent suivant les applications d'avoir une version d'une librairie utilisant des `double` pour les réels mais également d'avoir une autre version de la même librairie utilisant des `float`. 

Pour faire ça, vous vous doutez certainement que faire un chercher remplacer `double` par `float` ne va surement pas être la solution pérenne. Mais il est possible de définir des alias de type en C++ qui peuvent vous permettre d'avoir un comportement similaire. Cette définition d'un alias de type se fait en utilisant le mot clé using. Si par exemple je veux définir un type `Real` qui par défaut correspondra à un `double` mais que facilement je puisse le changer à `float`. Il me suffit de procéder de la manière suivante : 

\snippet ./src/type_using.cpp using_real_double 

Et donc dans toute la suite de mon code il me suffit d'utiliser le type `Real`. Cela permet le jour où je veux me faire une version simple précision de ma librairie de n'avoir besoin de changer le type qu'au niveau de la déclaration de `Real` et ensuite tout le reste du code s'adapte 

\snippet ./src/type_using.cpp using_real_float 


# Définir des variables 

## Ne pas confondre déclaration et affectation 


Attention, un point important en `C++` est que la déclaration d'une variable peut être indépendante de l'affectation d'une valeur à cette dernière. Cela peut sembler bizarre quand on vient du Python mais en fait c'est logique. Par exemple, si je veux définir une variable `value` qui devra contenir un entier. Je ne sais pas nécessairement au moment où je définis cette variable la valeur qu'elle va contenir. 

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

Seule la troisième manière vous signalera d'éventuels problèmes d'overflow de la valeur quand la taille mémoire prévue pour le type n'est pas capable de contenir la valeur. 

## La déduction de type via decltype ou auto 

Depuis le C++11, oui encore je sais, il a été introduit un concept particulier qui permet d'alléger un peu le coé typage statique fort du langage C++. Il s'agit de la déduction de type. En effet il est maintenant possible de demander au compilateur de déduire du contexte le type d'une variable. 

La déduction de type se fait via le mot clé `auto`. Ce dernier va venir remplacer le type d'une variable et c'est à la compilation que le `auto` sera substitué par un vrai type c++. Par exemple considérons le code suivant : 

\snippet ./src/deduction_example.cpp deduction_auto 

Dans cet exemple on créé une variable `a` de type `int`. Et ensuite on créé une variable `b` de type `auto` que l'on initialize avec la valeur de `a`. Dans ce cas la déduction est très simple car b va hérité du type de `a`. 

Il peut arriver, dans des cas un peu tordu, que le compilateur n'arrive pas à déduire le type du variable déclarée `auto` dans ce cas nous avons à la compilation une erreur de type `type deduction failed`. 

Il existe une autre manière de faire de la déduction de type, un peu plus souple, qui repose sur l'utilisation de `decltype`. Par exemple regardons l'exemple suivant, qui ressemble beaucoup au premier : 

\snippet ./src/deduction_example.cpp decltype 

Dans cet exemple, on définit une variable `a` de type `int`. On utilise alors `decltype(a)`, ce qui va alors nous donner le type de la variable `a` ici `int`, pour déclarer une variable `b`. Autrement dit on a donc déclarer une variable `b` du même type que `a`. Cela permet alors de déclarer la variable `b` sans avoir besoin de lui affecter la valeur de `a` comme nous avions du le faire avec le `auto`. 

De plus en utilisant le mot clé `using` nous pouvons alors définir un nouveau type que l'on peut ensuite utiliser comme un type classique. Par exemple : 

\snippet ./src/deduction_example.cpp decltype_using 


## Les qualificateur de variable 

Lorsque l'on définit une variable on lui associe donc un type, ou bien on laisse le compilateur déduire le type. Mais il est possible de fournir des informations additionnelles sur les variables via les qualificateurs. 

L'intérêt de donner des informations additionnelles est que plus le compilateur connait de chose à la compilation plus efficace il sera. Autrement dit suivant les informations que l'on fourni au compilateur ce dernier pourra potentiellement faire des optimisation de votre code pour vous. Et ça c'est quand même sympa !

L'utilisation de ces qualificateurs se fait toujours de la manière suivante : 

```
qualifier type variableName {value};
```

### Le qualificateur `const` 

Le premier qualificateur de variable que l'on va rencontrer et que l'on risque de retrouver régulièrement est le le `const`. Le qualificateur `const` va permettre de déclarer qu'une variable est constante et donc que sa valeur ne changera **jamais**. 



### Le qualificateur `constexpr` 

Le second qualificateur de variable est le `constexpr`. Ce dernier est encore plus fort que le `const` dans le sens où il indique au compilateur que la variable en question est pleinement connue au moment de la compilation. Quel intérêt ? Et bien cela permet de faire des calculs à la compilation plutôt qu'au run-time. 

Par exemple pour définir une variable `constexpr` on procède de la manière suivante : 

\snippet ./src/qualifier_example.cpp constexpr

Tout l'intérêt va alors être de pouvoir faire du calcul à la compilation : 

\snippet ./src/qualifier_example.cpp constexpr_calc

Si vous n'êtes pas convaincu vous pouvez regarder le détail içi [https://godbolt.org/z/Y4z7cEc8e](https://godbolt.org/z/Y4z7cEc8e)

### Le qualificateur `volatile` 

Enfin le dernier qualificateur que l'on va voir est le `volatile` son usage est beaucoup moins courant que les deux précédents mais vous pouvez le croiser de temps en temps. Le fait de déclarer une variable comme `volatile` est un moyen de dire au compilateur, ne t'occupe pas de cette variable t'es pas capable de la gérer du coup ne fait pas d'optimisation dessus. 

Typiquement si on considère le bout de code suivant : 

```
int some_int = 100;

while(some_int == 100)
{
   //your code
}
```

Si dans le bloc d'instruction on ne touche pas à la valeur de `some_int` il est très probable que le compilateur fasse une optimisation un peu brutale du genre remplacer le `some_int==100` par un `true` ce qui accélèrerait l'exécution. Or il se peut que l'on ait designé le code de telle sorte qu'il y a bien un élément quelque part qui change la valeur de la variable `some_int` mais le compilateur ne s'en rend pas compte. Dans ce cas le code généré par le compilateur n'est pas conforme à ce que l'on attend. La solution pour résoudre ce problème est alors de dire au compilateur de ne pas chercher à faire des optimisations trop aggressive concernant cette variable. Pour cela il suffit de la déclarer comme `volatile` ce qui donnerai alors : 

```
volatile int some_int = 100;

while(some_int == 100)
{
   //your code
}
```






# Référence vers une variable 

## Une référence c'est quoi 

Nous avons dit au début de cette page qu'une variable ce n'est rien de plus qu'une case mémoire sur laquelle on a collé une étiquette, le nom de la variable. Du coup si on a pu coller une étiquette sur une case mémoire est-ce qu'on ne pourrait pas en coller d'autre ? Et bien oui et c'est à ça que serve les références ! 

Pour définir une référence il faut utiliser le symbole esperluette `&`. La syntaxe générale est la suivante : 

```
   type& reference_name = variable ;
```

Par exemple définissons un double et une référence vers ce double : 

\snippet ./src/example_reference.cpp reference_definition 

***Attention*** : la référence est forcément du même type que la variable à laquelle elle s'accroche ! 

Et donc à partir de maintenant nous pouvons indifféremment utiliser la variable directement ou sa référence pour modifier la valeur ou accéder à la valeur. 

Vous avez déjà rencontrer cela dans le monde Python en fait. Souvenez-vous : 

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

Et bien les références en C++ c'est le même principe si ce n'est que là il faut le faire exprès ! 

On peut également utiliser les références avec de la déduction de type, par exemple écrire quelque chose du genre : 

\snippet ./src/example_reference.cpp reference_auto



## Intérêts et dangers 

Vous pourriez alors vous demander mais quel intérêt de pouvoir accéder à une variable par différents noms ? Car concrètement c'est ce que fait une référence. Et bien pour le moment aucun je vous l'avoue mais rapidement vous allez voir il y a plein d'intérêt ! Notamment lorsque l'on commence à avoir des codes un peu touffu il peut s'avérer pertinent d'avoir des références vers des variables pour faciliter la programmation. Un autre grand intérêt sera lorsque l'on commencera à faire des fonctions. Vous le verrez alors mais, ***attention teaser***, le fonctionnement par défaut des fonctions c++ est de faire un passage d'arguments par copie ! Et donc en utilisant les références nous allons pouvoir nous économiser une paquet de copie et ça c'est cool pour avoir du code efficace. 

Alors par contre il peut y avoir quelques dangers à utiliser des références. Je pense que vous voyez venir le truc. On peut très rapidement penser que l'on affecte une valeur à une variable alors qu'en fait il s'agit d'une référence vers une autre variable et là on commence alors à avoir des comportements étranges. Un moyen, alors qui n'est pas forcément appliquable à tous les cas de figures, mais qui permet au moins de se prémunir de certaines erreur parfois est d'ajouter un qualificateur `const` aux références que l'on ne veut pas modifier cela se fait par exemple de la manière suivante : 

\snippet ./src/example_reference.cpp const_reference

Dans ce cas nous pourrons accéder à la valeur `42.0` en passant par la variable `value` ou sa référence `ref` en revanche en passant par la référence nous ne pourrons pas modifier la valeur. Ca peut éviter certaines bêtises ! 




