
Introduction    {#introSection}
============


[TOC]

# Un historique rapide du C++ 

Le C++ trouve son origine dans l'expérience de Bjarne Stroustrup qui au cours de sa thèse, qu'il réalise avec le langage C trouve ce dernier quelque peu limité et manquant de certaines fonctionnalités. Le début du C++, qui s'appelait C with Class à l'époque date donc de l'année 1979. Comme son nom l'indiquait alors la principale évolution par rapport au C était donc la possibilité de définir des classes. Le nom C++ est adopté en 1984. C'est uniquement en 1998 qu'une première normalisation du C++ est mise en place. Ensuite une évolution mineure, principalement de la correction de bug, est proposée en 2003. 

C'est en 2011 que les choses sérieuses commencent, ou s'accélèrent, avec la norme C++11 qui apparaît comme une vraie révolution car modernise considérablement le langage en offrant de nombreuses fonctionnalités. Depuis 2011 des évolutions régulières ont lieux, en 2014 le c++14 qui offre quelques modifications mineures, en 2017 le C++17 qui apporte quelques amélioration notables (`if constexpr`, structured binding `auto [a, b] = getTwoValues()`, meilleur déduction des templates `std::vector a {1,2,3}`, ...) et enfin en 2020 le C++20 qui est encore une grosse révolution dans le monde c++ avec de nouvelles fonctionnalitées introduites telles que : (i) notion de `concept`, (ii) Ajout de la librairie `ranges` et des `span` ; (iii) ajout des coroutines ; ... 

C++ est donc en langage "vieux" mais qui reste bien vivant et en évolution surtout depuis cette dernière décennie. On peut noter également que C++ se place en quatrième position de l'index Tiobe 2021, classement de popularité des langages de programmation. 

# Le C++ versus le reste du monde 

Vous êtes très certainement familié de Python et c'est très bien car Python joue vraiment le rôle de couteau suisse de la programmation. Cependant vous allez certainement être quelque peu perdu en entrant dans le monde c++ car il existe des différences significatives entre un langage tel que Python et un langage comme le C++. Si nous devions faire la liste des différences nous en aurions pour un moment mais nous pouvons en retenir 3 qui vont vraiment vous perturber je pense à savoir : 

- C++ est un langage compilé alors que Python est interprété 
- C++ est un langage de bas niveau alors que Python est un langage de haut niveau 
- C++ est fortement typé alors que Python n'est pas typé (en fait si un peu mais c'est caché)

## Langage compilé vs interprété

La première distinction significative, peut-être la plus importante, est le fait que C++ est un langage compilé tandis que Python est un langage interpreté. Quelle distinction entre les deux ? C'est simple : 

Quand vous faites un programme Python, vous écrivez un fichier contenant votre code Python (le fichier avec l'extension `.py`) et pour éxecuter votre programme vous donnez votre fichier à manger au programme Python via la commande : 

```
python monFichier.py
```

Et c'est ce programme `python` qui se charge de lire votre fichier et de l'interpréter, c'est à dire d'exécuter les lignes instructions que vous avez déclaré dans ce fichier. Sans le programme `python` votre programme n'est qu'un fichier texte qui ne fait rien. Python est donc un langage interprété. 

C++ ne fonctionne pas du tout comme cela. Quand vous écrivez un programme C++, vous écrivez des instructions dans un fichier texte (avec l'extension `.cpp`) par exemple voici ci dessous un programme c++ affichant le message `Hello World` 

\snippet ./src/exampleCpp.cpp example

Ensuite ce code va être traduit en un programme executable. C'est ce que l'on appel l'étape de compilation, i.e. un programme extérieur le compilateur va lire votre fichier c++ et traduire son contenu en instruction binaire directement exécutable par l'ordinateur. Cela vous génère alors un programme pouvant être exécuté tout seul sans avoir besoin de personne d'autre. 

Par exemple pour compiler mon fichier `exampleCpp.cpp` précédent il suffit de faire : 

```
$ g++ exampleCpp.cpp -o example.exe 
```

Cela vous génère alors le fichier example.exe, donc vous ne pouvez pas voir le contenu car il s'agit d'un fichier binaire mais que vous pouvez exécuter de la manière suivante : 

```
$ ./example.exe
Hello World
```

Si l'on synthétyse le processus de développement Python vs C++ est le suivant : 

- Python : 2 étapes 
    - J'écris le code dans un fichier `.py`
    - J'exécute le code à l'aide de l'interpréteur `python`
- C++ : 3 étapes 
    - J'écris le code dans un fichier `.cpp` 
    - Je compile le code à l'aide du compilateur 
    - J'éxecute le programme binaire généré par le compilateur 

Vous vous demandez peut-être quel est l'intérêt de cet étape de compilation, pourquoi ne pas faire comme Python car ca parait plus simple ? La réponse est très simple. L'étape de compilation cache en réalité une étape d'optimisation du code. Tout d'abord le fait d'avoir au final un code binaire directement exécuter par l'ordinateur permet de s'affranchier du temps d'interprétation du code source, soit dit en passant l'interpréteur Python est lui un programme compilé écrit en C. De plus avec le C++ l'étape de compilation s'accompagne d'une étape d'optimisation du code, en effet les compilateurs c'est un peu les arcanes de la magie noire. Du coup si en écrivant votre code C++ vous pensez à aider un peu le compilateur (on verra dans ce cours comment faire) et bien à la compilation le compilateur va pouvoir faire un certain nombre d'optimisation et ça c'est sympa de sa part. 

### Minute culturelle 

Juste une petite parenthèse. Quand je vous ais dit que le compilateur mange votre code c++ pour en faire un programme binaire executable c'est vrai mais j'ai été un peu rapide. Il y a en fait unne étape intermédiaire qui est la génération du code en assembleur. Assembleur c'est quoi ? C'est l'ancêtre des langages de programmation, introduit dans les années 1950. Il s'agit des premiers langages de programmation qui en fait consiste juste en une série de jeu d'instruction. C'était une révolution à l'époque mais aujourd'hui cela fait plus peur qu'autre chose. Par exemple vous trouverez ci-dessous le code assembleur généré par la compilation de mon exemple qui affiche `Hello World`. 

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

La seconde particularité est que le C++ est de bas niveau par rapport à Python qui lui est de haut niveau. Mais qu'est ce que cela veut dire ? Je vous rassure tout de suite ce n'est pas à prendre dans le sens Python c'est top et C++ c'est nul !! 
La distinction entre un langage de haut niveau et bas niveau se fait principalement sur le niveau d'abstraction vis-à-vis du code binaire généré et ainsi du fonctionnement de la machine.

C'est en ce sens que Python est considéré de haut-niveau car pas besoin d'être expert de l'architecture matériel de votre ordinateur ni même de savoir ce qu'est le Cache pour faire un code Python fonctionnel. Je vous rassure tout de suite, vous n'allez pas avoir besoin de savoir ce genre de chose pour faire du c++ ;) en revanche lorsque l'on sait ces choses il est possible d'adapter son programme C++ afin de tirer le plus de performance possible et c'est en cela que C++ est un langage bas-niveau. 

Après tout n'est qu'une question de perspective car si on devait comparer C++ et l'Assembleur dans ce cas je dirai sans hésiter que C++ est de haut niveau par rapport à l'assembleur ;) 

## Langagé fortemment typé

Pour finir la dernière distinction, que l'on détaille, entre C++ et Python est le fait que C++ est un langage fortement typé. Concrétement lorsqu'en Python vous créez une variable vous vous contentez de nommer la variable et de lui affecter une valeur sans trop vous posez de question. Et ensuite si dans la même variable vous voulez stocker une valeur d'un autre type, par exemple une chaine de caractère puis ensuite un nombre flottant, et bien tout marche tout seul. 

Et bien préparez vous mais en C++ c'est finis le temps de l'insouciance. Car en c++ si vous créez une variable il faut toujours dire le type de valeur que cette variable va contenir et une fois que c'est fait on ne change plus ! Nous verrons dans le chapitre précédent comment faire cela justement. 

Si le C++ est un langage fortement typé c'est encore une fois une histoire de performance. En effet le fait de spécifier le type de chaque variable à la compilation va permettre au compilateur de faire son travail d'optimisation, notamment au niveau de la gestion de la mémoire. 

# Le setup de base 

Maintenant que nous avons vu dans les grandes lignes en quoi un langage comme C++ diffère du Python par exemple nous allons rapidement voir ce qu'il vous faut pour faire du C++. 

Si vous avez bien suivi le début vous savez déjà qu'il vous faut deux choses : 

1. Un compilateur : **le** programme essentiel qui va s'occuper de traduire vos fichiers c++ en programme binaires exécutables 
2. Un éditeur de code : il faut bien écrire vos fichiers C++ donc pour ça il vous faut un éditeur de code ! Rien de bien différents à Python pour le coup. 

## Installation d'un compilateur 

L'étape la plus délicate potentiellement c'est l'installation d'un compilateur. La procédure va dépendre de votre système d'exploitation. 

### Si vous êtes utilisateur Linux 

Dans ce cas c'est super simple, oui parfois c'est plus simple sous Linux. C'est simple car le gestionnaire de paquet de votre système d'exploitation vous propose forcément un paquet GCC. Pour installer le compilateur c++ il vous suffit alors, si vous êtes sous Debian/Ubuntu, de taper la commande suivante dans un terminal 

```bash 
sudo apt-get install build-essentials gcc 
```

### Si vous êtes utilisateur Mac OS

Si vous êtes utilisateur Mac OS pour avoir un compilateur c++ il faut que vous installiez XCode. 

### Si vous êtes utilisateur Windows 

Enfin si vous utilisez windows, c'est mal, pour installer un environnement C++ facilement voici la démarche : 

1. Il faut que vous installiez WSL, Windows Subsystem Linux, qui est un module microsoft vous permettant d'avoir un environnement Linux embarqué dans votre Windows. Pour les instuctions d'installation voir [https://docs.microsoft.com/fr-fr/windows/wsl/install](https://docs.microsoft.com/fr-fr/windows/wsl/install)
2. Une fois WSL installé reporté vous à la section pour les utilisateurs Linux. 


## Un éditeur de texte qui va bien 

Nous vous laissons libre d'utiliser votre éditeur préféré. Pour celles et ceux qui n'auraient pas de croyance à ce sujet nous vous recommandons fortement d'utiliser Visual Studio Code. 

Pour les **utilisateurs Windows** il faut que vous installiez l'extension WSL de VSCode pour avoir un environnement de travail agréable. 


## Quelques outils annexes 

Avoir un compilateur et un éditeur c'est le minimum syndicale. Pour la suite du cours nous allons également avoir besoin des outils suivants, qui ont pour but de vous simplifier la vie :  

* CMake : un système de build qui permet d'automatiser les compilations 
* gdb : un debuggeur 
* valgrind : un inspecteur des allocations mémoires des programmes C++ 
* doxygen : un outil de génération de documentation (le sphynx de C++) qui est entre autre utilisé pour générer ces supports de cours 


## Vérifier que tout fonctionne 

TODO : faire un dépôt avec une compil cmake et une doc bidon doxygen 


# Le point d'entré d'un programme C++

## La fonction `main` 

**Tout** programme écrit en C++ a un point d'entrée. C'est à dire une section de code qui est la première à être éxécutée. 



\snippet ./src/pointEntree.cpp main


Pour compiler notre programme nous allons utiliser le compilateur. La compilation se fait via le terminal de la manière suivante : 

```bash 
$ g++ pointEntree.cpp -o pointEntree.out 
```

Cela nous génère alors une programme binaire executable, pointEntree.out, que l'on peut lancer de la manière suivante : 

```bash 
$ ./pointEntree.out 
```

Nous verrons pas la suite que cette fonction main peut prendre des arguments d'entrée. Ces arguments seront en fait les arguments passé au programme au lancement de ce dernier. 



