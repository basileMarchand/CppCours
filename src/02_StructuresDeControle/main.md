
Structures de contrôle    {#controlSection}
======================

[TOC]

Dans cette partie nous allons aborder deux aspects du C++. Tout d'abord la notion de bloc d'instruction et de portée des variables car maintenant que vous savez définir des variables vous allez voir qu'en réalité ce n'est pas parce que vous avez défini une variable que cette dernière va exister tout au long de votre programme. Le second point que nous aborderons sont les structures de contrôles, il s'agit de l'ensemble des instructions d'un langage permettant d'altérer le flux d'exécution du programme. 

# Bloc d'instruction et portée des variables 

## La variable a une durée de vie limitée 

Comme nous venons de le dire en introduction lorsque vous définissez une variable cette dernière a une durée de vie limité. Cette durée de vie est liée au bloc d'instruction dans lequel cette variable se trouve, on parle également du scope d'une variable. 

Par exemple considérons le programme suivant : 

\snippet ./src/example_scope_main.cpp all

Dans le code précédent la variable `une_variable` est définie dans la fonction `main` elle peut donc être utilisée sans soucis au sein de cette dernière. On peut donc dire que le scope de `une_variable` c'est la fonction `main`. 

De manière générale en C++ un bloc d'instruction se caractérise toujours par une paire d'accolade `{}`. Ainsi pour déterminer le scope d'une variable il suffit d'identifier ***la paire d'accolade de plus bas niveau contenant la déclaration de la variable***. 

Il est tout à fait possible est assez commun en c++ de définir des sous-scopes au sein de blocs d'instruction. Pour cela il suffit d'encadrer la portion de code par une paire d'accolade. Par exemple : 

\snippet ./src/example_scope_local.cpp all

Dans l'exemple ci-dessus on définit une variable `nbVals` dont le scope est définit par la paire d'accolade de la fonction `main`. On définit alors un sous-scope dans lequel on déclare une autre variable `another`. Deux remarques à faire : 

- Vous constatez que dans le scope local nous pouvons accéder à la variable `nbVals` car cette dernière est déclarée dans un scope d'un niveau supérieur. 
- Une fois que l'on sort du scope local la variable `another` est détruite elle n'est donc plus utilisable. 

Regardons une exemple un peu plus compliqué : 

\snippet ./src/example_scope_complex.cpp all


Nous le verrons par la suite, lorsque nous verrons comment définir des fonctions, mais une variable lorsqu'elle est définie au sein d'une fonction n'existe que dans cette dernière, ça peut être sujet à quelques bugs bizarre quand on ne sait pas trop ce qu'on fait d'ailleurs ! 

Du coup la question que l'on peut se poser et que vous vous posez j'en suis certain. C'est n'y aurait-il pas un moyen de déclarer des espèces de variables globales à scope illimité ? Alors oui mais non. Oui c'est faisable, la solution est simple il suffit de déclarer la variable en dehors de la fonction `main`. Voici par exemple : 

\snippet ./src/example_scope_global.cpp all

Dans ce cas on définit la variable `variableGlobale` en dehors de la fonction `main` il s'agit donc d'une variable globale. En revanche ce n'est pas recommandée car cela créé des variables qui occupe de l'espace mémoire tout au long du programme et en plus cela nuit à la lisibilité du code. Donc on peut définir des variables globales mais on évite tant que faire ce peut.

## La pile d'exécution 

TODO 

# Instructions conditionnelles

Maintenant que vous en savez un peu plus sur la notion de bloc d'exécution et de scope d'une variable nous allons pouvoir entrer dans le vif du sujet de cette partie à savoir les structures de contrôle. Et pour commencer nous allons nous intéresser à celles qui vont nous permettre de faire varier le comportement de notre programme suivant certains critères. On parle de branchements.

## If

### Structure générale 

La première approche pour faire varier le comportement de vos programmes est d'utiliser le bloc `if`, `else if`, `else`. Qui peut litéralement se comprendre comme `si` quelque chose, `sinon si` autre chose, `alors`. La syntaxe d'utilisation de ce bloc d'instruction est la suivante : 

```
if( une_condition ){
    // bloc d'instruction 
}
else if( une_autre_condition ){
    // bloc d'instruction 
}
else{
    // bloc d'instruction 
}
```

Les éléments `une_condition` et `une_autre_condition` peuvent être : (i) des variables ; (ii) des expressions booléennes ; (ii) des appels de fonctions. La seule et unique contrainte est que lorsque l'expression entre parenthèse derrière un `if` ou un `else if` est évaluée le résultat final doit être assimilable à un booléen `true` ou `false`. 

Par exemple considérons l'exemple concret suivant : 

\snippet ./src/example_if.cpp all

Bien évidemment la syntaxe de l'instruction `if` est bien plus souple que cela. Nous pouvons avoir les cas suivants : 
- Un `if` sans `else if` et sans `else`
- Un `if` sans `else if` et avec un `else`
- Un `if` avec ***N*** `else if` et avec un `else`
- Un `if` avec ***N*** `else if` et sans `else`

En gros la seule contrainte est d'avoir un `if` le reste c'est comme on veut. 


### Cas particulier des constexpr (C++17)

Depuis la norme C++17 il existe un autre usage de l'instruction `if` en coopération avec le qualificateur `constexpr`. Voici ci-dessous un exemple : 

\snippet ./src/example_if_constexpr.cpp all 

Vous voyez donc apparaître le `if constexpr`. A votre avis qu'est ce que cela va changer dans le code généré par rapport à un `if` classique ? Allez je suis sympa pour vous aider vous trouverez ci-dessous un petit extrait du site [godbolt.org](godbolt.org) qui vous permet de voir le code assembleur généré à la compilation de ce code : 

\htmlonly
<iframe width="100%" height="400px" src="https://godbolt.org/e?readOnly=true&hideEditorToolbars=true#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Ciostream%3E%0A%0Aint+main()%7B%0A++++constexpr+int+age+%7B30%7D%3B%0A%0A++++if+constexpr(+age+%3C+18+)%7B%0A++++++++std::cout+%3C%3C+%22Mineur+(mais+pas+du+60+bvd+St.+Michel)%22+%3C%3C+std::endl%3B%0A++++%7D%0A++++else+if(+(age+%3E%3D+18)+%26%26+(age%3C%3D30)+)%7B%0A++++++++std::cout+%3C%3C+%22Pas+encore+trop+vieux%22+%3C%3C+std::endl%3B+%0A++++%7D%0A++++else+%7B%0A++++++++std::cout+%3C%3C+%22L!'age+de+sagesse%22+%3C%3C+std::endl%3B+%0A++++%7D%0A++++return+EXIT_SUCCESS%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g112,filters:(b:'0',binary:'1',commentOnly:'0',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'',selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1,tree:'1'),l:'5',n:'0',o:'x86-64+gcc+11.2+(C%2B%2B,+Editor+%231,+Compiler+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>
\endhtmlonly

Non ? Vous ne trouvez toujours pas ? Et bien c'est simple, le principe du `if constexpr` c'est que le branchement, c'est à dire le choix du bloc d'instruction, n'est pas fait au runtime mais à la compilation !!! Et donc ce qu'il fallait voir dans le code assembleur ci-dessus c'est que les deux branches inutilisées dans ce cas ne sont même pas compilées. Alors oui ce n'est pas possible tout le temps car cela implique de pouvoir évaluer à la compilation les conditions du `if` mais quand c'est possible il ne faut surtout pas s'en priver car ça va grandement accélérer votre programme dans certains cas. 

### Aider le compilateur (C++20)

Je viens de vous le dire moins on fait de branchement au runtime meilleur est la performance. Mais parfois je le reconnais pas le choix il faut conserver des instructions `if` y compris dans des sections critiques en terme de performance. Néanmoins depuis la norme C++20 il existe un moyen d'aider le compilateur a optimiser ces branchements y compris s'ils sont indéterminés à la compilation. Cela se fait en faisant des paris. Dis autrement nous allons indiquer au compilateur quel branche va probablement être la plus utilisées ou bien laquelle sera probablement la moins utilisée. Cette indication se fait en ajoutant les attributs `[[likely]]` et `[[unlikely]]` aux blocs d'instruction. 

TODO : add exemple 




## Switch 


# Instructions d'itération

## Boucle while 

## Boucle for 

# Gestion des exceptions 

## La notion d'exception 

## Essai - erreur 



