
Introduction    {#introSection}
============


[TOC]

# Un historique rapide du ``C++`` 

Le ``C++`` trouve son origine dans l'expérience de Bjarne Stroustrup qui, au cours de la thèse qu'il réalise avec le langage C, trouve ce dernier quelque peu limité manquant de certaines fonctionnalités. Le début du `C++`, qui s'appelait C with Class à l'époque date donc de l'année 1979. Comme son nom l'indiquait alors la principale évolution par rapport au C était donc la possibilité de définir des classes. Le nom `C++` est adopté en 1984. C'est uniquement en 1998 qu'une première normalisation du `C++` est mise en place. Ensuite une évolution mineure, principalement de la correction de bug, est proposée en 2003. 

C'est en 2011 que les choses sérieuses commencent, ou s'accélèrent, avec la norme `C++11` qui apparaît comme une vraie révolution car elle modernise considérablement le langage en offrant de nombreuses fonctionnalités. Depuis 2011 des évolutions régulières ont lieux, en 2014 le `C++14` qui offre quelques modifications mineures, en 2017 le `C++`17 qui apporte quelques améliorations notables (`if constexpr`, structured binding `auto [a, b] = getTwoValues()`, meilleur déduction des templates `std::vector a {1,2,3}`, ...) et enfin en 2020 le `C++`20 qui est encore une grosse révolution dans le monde `C++` avec de nouvelles fonctionnalités introduites telles que : (i) notion de `concept`, (ii) ajout de la librairie `ranges` et des `span` ; (iii) ajout des coroutines ; ... 

`C++` est donc un "vieux" langage mais il reste bien vivant et en évolution surtout depuis cette dernière décennie. On peut noter également que `C++` se place en quatrième position de l'index Tiobe 2021, classement de popularité des langages de programmation. 

# Le `C++` versus le reste du monde

Vous êtes très certainement familiers de Python et c'est très bien car Python joue vraiment le rôle de couteau suisse de la programmation. Cependant vous allez certainement être quelque peu perdus en entrant dans le monde `C++` car il existe des différences significatives entre les deux langages. La liste des différences est grande mais nous pouvons en retenir 3 qui peuvent vous perturber à savoir : 

- `C++` est un langage compilé alors que Python est interprété; 
- `C++` est un langage de bas niveau alors que Python est un langage de haut niveau; 
- `C++` est fortement typé alors que Python n'est pas typé (en fait si un peu mais c'est caché).

## Langage compilé vs interprété

La première distinction significative, peut-être la plus importante, est le fait que `C++` est un langage compilé tandis que Python est un langage interprété. Quelle distinction entre les deux ? C'est simple : 

Quand vous faites un programme Python, vous écrivez un fichier contenant votre code Python (le fichier avec l'extension `.py`) et pour exécuter votre programme vous donnez votre fichier à manger au programme Python via la commande : 

```
python monFichier.py
```

Le programme `python` se charge de lire votre fichier et de l'interpréter, c'est à dire d'exécuter les instructions que vous avez déclarées dans ce fichier. Sans le programme `python` votre programme n'est qu'un fichier texte qui ne fait rien. Python est donc un langage interprété. 

`C++` ne fonctionne pas du tout comme cela. Quand vous écrivez un programme `C++`, vous écrivez des instructions dans un fichier texte (avec l'extension `.cpp`) par exemple voici ci dessous un programme `C++` affichant le message `Hello World` 

\snippet ./src/exampleCpp.cpp example

Ensuite ce code va être traduit en un programme exécutable. C'est ce qu'on appelle l'étape de compilation pendant laquelle un programme extérieur, le compilateur, va lire votre fichier `C++` et traduire son contenu en instruction binaire directement exécutable par l'ordinateur. Cela génère un programme pouvant s'exécuter tout seul sans avoir besoin de personne d'autre. 

Par exemple pour compiler mon fichier `exampleCpp.cpp` précédent il suffit de faire : 

```
$ g++ exampleCpp.cpp -o example.exe 
```

Cela génère le fichier `example.exe`, donc vous ne pouvez pas voir le contenu car il s'agit d'un fichier binaire mais que vous pouvez exécuter de la manière suivante : 

```
$ ./example.exe
Hello World
```

Si l'on synthétise, le processus de développement `Python` vs ``C++`` est le suivant : 

- `Python` : 2 étapes 
    - J'écris le code dans un fichier `.py`
    - J'exécute le code à l'aide de l'interpréteur `python`
- ``C++`` : 3 étapes 
    - J'écris le code dans un fichier `.cpp` 
    - Je compile le code à l'aide du compilateur 
    - J'exécute le programme binaire généré par le compilateur 

Vous vous demandez peut-être quel est l'intérêt de cette étape de compilation ? Pourquoi ne pas faire comme Python car ça parait plus simple ?
La réponse est très simple. L'étape de compilation cache en réalité une étape d'optimisation du code.
* Tout d'abord le fait d'avoir un code binaire directement exécuté par l'ordinateur permet de s'affranchir du temps d'interprétation du code source (soit dit en passant l'interpréteur `Python` est lui-même un programme compilé écrit en `C`)
* De plus, l'étape de compilation s'accompagne d'une étape d'optimisation du code. En effet les compilateurs sont un peu les arcanes de la magie noire. Du coup, si en écrivant votre code ``C++``, vous pensez à aider un peu le compilateur (on verra dans ce cours comment faire), et bien lors de la compilation le compilateur va pouvoir faire un certain nombre d'optimisation et ça c'est sympa de sa part. 

### Minute culturelle 

Juste une petite parenthèse. Quand je vous ai dit que le compilateur mange votre code ``C++`` pour en faire un programme binaire exécutable, c'est vrai mais j'ai été un peu rapide. Il y a en fait nne étape intermédiaire qui est la génération du code en assembleur. Assembleur c'est quoi ? C'est l'ancêtre des langages de programmation, introduit dans les années 1950. Il s'agit des premiers langages de programmation qui en fait consistent juste en un jeu d'instruction. C'était une révolution à l'époque mais aujourd'hui cela fait plus peur qu'autre chose. Par exemple vous trouverez ci-dessous le code assembleur généré par la compilation de mon exemple qui affiche `Hello World`. 

```
.LC0:
        .string "Hello World"
main:
        push    rbp
        mov     rbp, rsp
        mov     esi, OFFSET FLAT:.LC0
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    _ZNSolsEPFRSoS_E
        mov     eax, 0
        pop     rbp
        ret
_Z41__static_initialization_and_destruction_0ii:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], edi
        mov     DWORD PTR [rbp-8], esi
        cmp     DWORD PTR [rbp-4], 1
        jne     .L5
        cmp     DWORD PTR [rbp-8], 65535
        jne     .L5
        mov     edi, OFFSET FLAT:_ZStL8__ioinit
        call    _ZNSt8ios_base4InitC1Ev
        mov     edx, OFFSET FLAT:__dso_handle
        mov     esi, OFFSET FLAT:_ZStL8__ioinit
        mov     edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
        call    __cxa_atexit
.L5:
        nop
        leave
        ret
_GLOBAL__sub_I_main:
        push    rbp
        mov     rbp, rsp
        mov     esi, 65535
        mov     edi, 1
        call    _Z41__static_initialization_and_destruction_0ii
        pop     rbp
        ret
```

## Langage de haut niveau vs bas niveau 

La seconde particularité est que le ``C++`` est de bas niveau par rapport à Python qui lui est de haut niveau. Qu'est ce que cela veut dire ? Je vous rassure tout de suite ce n'est pas à prendre dans le sens Python c'est top et ``C++`` c'est nul !! 
La distinction entre un langage de haut niveau et un de bas niveau se fait principalement sur le niveau d'abstraction vis-à-vis du code binaire généré et ainsi vis à vis du fonctionnement de la machine.

C'est en ce sens que Python est considéré de haut-niveau car pas besoin d'être expert de l'architecture matériel de votre ordinateur ni même de savoir ce qu'est le Cache pour faire un code Python fonctionnel. Je vous rassure tout de suite, vous n'allez pas avoir besoin de savoir ce genre de chose pour faire du ``C++`` ;) en revanche lorsque l'on sait ces choses il est possible d'adapter son programme ``C++`` afin de tirer le plus de performance possible et c'est en cela que ``C++`` est un langage bas-niveau. 

Après tout ce n'est qu'une question de perspective car si on devait comparer ``C++`` et l'Assembleur, dans ce cas je dirai sans hésiter que ``C++`` est de haut niveau par rapport à l'assembleur ;) 

## Langage fortement typé

Pour finir, la dernière distinction que l'on détaille entre ``C++`` et Python, est le fait que ``C++`` est un langage fortement typé.
Concrètement lorsqu'en Python vous créez une variable vous vous contentez de nommer la variable et de lui affecter une valeur sans trop vous poser de question. Et ensuite si, dans la même variable, vous voulez stocker une valeur d'un autre type, par exemple une chaîne de caractères puis ensuite un nombre flottant, et bien tout marche tout seul. 

Et bien préparez vous mais en ``C++`` le temps de l'insouciance est fini. Car en ``C++``, quand vous créez une variable, il faut toujours dire le type de valeur que cette variable va contenir et une fois que c'est fait on ne le change plus ! Nous verrons dans le chapitre suivant comment faire cela. 

Si le ``C++`` est un langage fortement typé, c'est encore une fois une histoire de performance. En effet le fait de spécifier le type de chaque variable à la compilation va permettre au compilateur de faire son travail d'optimisation, notamment au niveau de la gestion de la mémoire. 

# Le setup de base 

Maintenant, que nous avons vu dans les grandes lignes en quoi un langage comme ``C++`` diffère du Python par exemple, nous allons rapidement voir ce qu'il vous faut pour faire du ``C++``. 

Si vous avez bien suivi le début vous savez déjà qu'il vous faut deux choses : 

1. Un compilateur : **le** programme essentiel qui va s'occuper de traduire vos fichiers ``C++`` en programmes binaires exécutables 
2. Un éditeur de code : il faut bien écrire vos fichiers ``C++`` donc pour ça il vous faut un éditeur de code ! Rien de bien différent avec Python pour le coup. 

## Installation d'un compilateur 

L'étape la plus délicate potentiellement est l'installation d'un compilateur. La procédure va dépendre de votre système d'exploitation. 

### Si vous êtes utilisateur Linux 

Dans ce cas c'est super simple, oui parfois c'est plus simple sous Linux. C'est simple car le gestionnaire de paquet de votre système d'exploitation vous propose forcément un paquet `GCC`. Pour installer le compilateur ``C++`` il vous suffit alors, si vous êtes sous Debian/Ubuntu, de taper la commande suivante dans un terminal 

```bash 
sudo apt-get install build-essentials gcc 
```

### Si vous êtes utilisateur Mac OS

Si vous êtes utilisateur Mac OS pour avoir un compilateur ``C++`` il faut que vous installiez `XCode`. 

### Si vous êtes utilisateur Windows 

Enfin si vous utilisez windows, c'est mal, pour installer un environnement ``C++`` facilement voici la démarche : 

1. Il faut que vous installiez `WSL` (Windows Subsystem for Linux), qui est un module microsoft vous permettant d'avoir un environnement Linux embarqué dans votre Windows. Pour les instructions d'installation voir [https://docs.microsoft.com/fr-fr/windows/wsl/install](https://docs.microsoft.com/fr-fr/windows/wsl/install)
2. Une fois `WSL` installé, reportez-vous à la section pour les utilisateurs Linux. 


## Un éditeur de texte qui va bien 

Nous vous laissons libre d'utiliser votre éditeur préféré. Mais pour celles et ceux qui n'auraient pas (encore) de croyances à ce sujet nous vous recommandons très fortement d'utiliser `Visual Studio Code`. 

Pour les **utilisateurs Windows** il faut que vous installiez l'extension `WSL` de `VSCode` pour avoir un environnement de travail agréable. 


## Quelques outils annexes 

Avoir un compilateur et un éditeur c'est le minimum syndical. Pour la suite du cours, nous allons également avoir besoin des outils suivants qui ont pour but de vous simplifier la vie :  

* `CMake` : un système de build qui permet d'automatiser les compilations 
* `gdb` : un debugger 
* `valgrind` : un inspecteur des allocations mémoires des programmes ``C++`` 
* `doxygen` : un outil de génération de documentation (le `sphynx` de ``C++``) qui est, entre autre, utilisé pour générer ces supports de cours 


## Vérifier que tout fonctionne 

Pour vérifier que votre installation fonctionne nous vous avons préparé un dépôt git contenant un programme de test. Vous pouvez trouver le dépôt à l'adresse suivante [https://github.com/ue12-p21/cpp-test-install](https://github.com/ue12-p21/cpp-test-install)

Ce dépôt contient un programme qui va permettre de vérifier que le compilateur que vous avez installé fonctionne et surtout qu'il supporte les normes récentes du c++. 


# Le point d'entré d'un programme ``C++``

## La fonction `main` 

**Tout** programme écrit en ``C++`` a un point d'entrée. C'est à dire une section de code qui est la première à être exécutée. C'est cette section qui va appeler toutes les autres. Par défaut ce point d'entrée est une fonction C++ qui s'appelle forcément `main`. Si dans un programme il n'y a pas de main alors il ne se passera rien. Par exemple pour faire un programme minimal qui ne fait qu'afficher un message on peut écrire le code c++ suivant : 

\snippet ./src/pointEntree.cpp main

Vous pouvez remarquer que la fonction retourne une valeur, içi 0. C'est une convention assez classique en informatique, qui est que si le déroulement d'un programme se déroule correctement alors ce dernier doit renvoyer 0 à l'environnement qui l'appelle, dans notre cas le terminal en bash. 

Une fois ce code écrit il faut le compiler pour en faire un programme exécutable. Pour réaliser cette étape de compilation  nous allons utiliser le compilateur. La compilation se fait via le terminal de la manière suivante : 

```bash 
$ g++ pointEntree.cpp -o pointEntree.out 
```

Cela génère alors un programme binaire exécutable, `pointEntree.out`, que l'on peut lancer de la manière suivante : 

```bash 
$ ./pointEntree.out 
```

Nous verrons, par la suite, que cette fonction main peut prendre des arguments en entrée. Ces arguments seront en fait les arguments passés au programme lors du lancement de ce dernier. 



