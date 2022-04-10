Programmation parallèle  {#threadSection}
=======================

[TOC]

# Vous avez une Formule 1 mais vous l'utilisez comme une 4L

## Architectures multicoeur moderne 

Pour le moment dans tous les cours de programmation que vous avez eus au premier semestre vous ne vous êtes pas vraiment posé la question de savoir si les programmes que vous avez écrits utilisaient pleinement vos ressources en terme de moyens de calcul.

Et je peux vous répondre tout de suite : non vous n'avez pas du tout utilisé l'intégralité de vos ressources informatiques. Et c'est bien normal car vous n'avez pas appris comment le faire !! En effet pour utiliser l'ensemble des ressources disponibles, sur votre ordinateur portable par exemple, il est nécessaire de le faire volontairement, et c'est ce que nous allons voir dans ce cours. 

L'objectif de ce cours est donc de vous donner les éléments de base pour que vous soyez à même de réaliser des programmes en **C++** capables d'exploiter vos ressources informatiques au maximum.

Pour commencer repartons de la base. Comment fonctionne votre ordinateur portable ? Alors vous avez déjà eu une introduction aux systèmes d'exploitation ce qui fait que les choses que je vais dire ne seront normalement que des banalités mais, comme on dit, il faut répéter pour que ça rentre. 

Un ordinateur portable (ou pas portable d'ailleurs) c'est : 

* Un hardware : l'objet physique et ses composants
* Du software : principalement votre système d'exploitation qui permet de faire fonctionner correctement la partie hardware

Je ne m'attarderai pas plus que cela sur la partie software/OS. Si on regarde la partie hardware, on peut à la louche décomposer un ordinateur en trois composants : 
* Le processeur
* La mémoire vive 
* Le disque dur 

Je sais, il y a plein d'autres trucs par exemple l'écran, la carte graphique, ... mais on va dire que selon ma définition le minimum vital pour que l'on puisse parler d'ordinateur c'est : processeur, mémoire vive et disque dur. Quoique, petit aparté, la prise en compte du disque dur peut être discutable dans ma définition car il y a aujourd'hui des ordinateurs dits *diskless*, mais c'est un autre débat.

Et donc à partir de ces éléments : comment fonctionne l'exécution d'un programme ? C'est simple : c’est à partir de votre programme binaire stocké sur le disque dur. Quand vous lancez l'exécution, il se passe les étapes suivantes : 

1. Le système d'exploitation charge votre programme en mémoire vive
2. Votre programme commence à dire au processeur qu'il doit réaliser des instructions 
3. Le processeur, quand c'est au tour de votre programme de travailler :  
    a. Récupère en mémoire les variables dont il a besoin  
    b. Exécute une série d'instructions ordonnée par votre programme  
    c. Range en mémoire le résultat issu de la série d'instructions  
    
Le point important se situe au niveau de l'étape 3, i.e. le **processeur** !

Mais avant, faisons un peu d'archéologie des processeurs.

Non je plaisante, je ne vais pas vous faire toute le genèse de l'informatique depuis les cartes perforées jusqu'à l'ordinateur quantique. Je me contenterai de vous donner une date clé : 2001 la sortie du POWER4 par IBM (je fais vieux sage, mais j'ai dû chercher sur Internet car à cette date je n'avais encore jamais touché un ordinateur…).

Qu'est ce qu'il a de particulier ce POWER4 ? vous vous demandez. Et bien c'est le premier processeur du marché à être équipé de **deux** cœurs ! Oui vous avez bien lu **deux**. Alors puisque l'on est dans les dates on peut également citer 2005 avec la sortie des premiers processeurs Intel et AMD en dual-core.

Et alors qu'est ce que ça a de révolutionnaire ? Eh bien, l'arrivée des processeurs multi-cœurs représente un changement de paradigme complet. Car avant cela il n'y avait que des processeurs mono-cœur, donc les instructions s’exécutaient en séquentiel. L'arrivée des multi-cœurs signe l'arrivée du traitement en parallèle des tâches. En effet à partir de ce moment on a deux fois plus de bras pour travailler donc on peut faire des choses simultanément. 

Pour la petite histoire, pourquoi ce changement de vision brusque, passage des architectures mono-cœur à des architectures multi-cœurs ? Pour une raison toute simple, pendant des années l'évolution et la montée en gamme des processeurs était directement proportionnelle au nombre de transistors intégrés dans le processeur. Il s'agit de la fameuse loi de Moore qui stipule que le nombre de transistors constituant un processeur, et donc sa puissance de calcul, double tous les deux ans. Et pendant des années cette loi a été vérifiée et la montée en gamme des processeurs se faisait "naturellement" avec l'évolution des transistors. Sauf que vers le début des années 2000 la loi de Moore a commencé à avoir du plomb dans l'aile... et donc il a fallu trouver une parade pour continuer à faire évoluer les processeurs. La solution la plus simple a été de se dire : si on ne peut pas aller deux fois plus vite avec un processeur, eh bien on va en faire deux fois plus. Et c'est comme ça que les processeurs dual-core ont commencé à apparaître.

Pour l'anecdote les objectifs d'Intel en terme de performance en 2002 étaient d'avoir à l'horizon 2005 des processeurs cadencés à 10 GHz. Ils ont abandonné en cours de route pour passer sur les architectures multi-cœurs. Visiblement ils ont bien fait car les processeurs récents les plus performants ont une fréquence d'horloge de 5 GHz et nécessitent pour cela un refroidissement à l'azote liquide...

Mais revenons à nos moutons, les processeurs multi-cœurs. Aujourd'hui cela peut sembler banal vous avez des processeurs multi-cœurs dans votre ordinateur, dans votre téléphone, avec en moyenne 4 cœurs. Sachant que pour les processeurs destinés aux serveurs les plus récents et les plus haut de gamme, on peut avoir jusqu'à 32, 64 voir même 96 cœurs par processeurs. On peut donc raisonnablement admettre qu’aujourd’hui le modèle standard est aux processeurs multi-cœurs. 


## Les modèles de parallelisme 

Il existe, en terme de moyens de calculs, différentes échelles :
* l'échelle de l'unité de calcul (le cœur)
* l'échelle du processeur qui comporte plusieurs cœurs
* l'échelle de l'ordinateur ou du nœud qui comporte plusieurs processeurs
* l'échelle du cluster qui est constitué d'un ensemble de nœuds.

Afin d'exploiter toutes ces échelles, diverses approches et solutions techniques ont été développées au fil du temps. Nous verrons cela peu après. Mais tout d'abord parlons modèle de parallélisme. En effet, suivant les applications cible et la finalité visée, les usages des architectures parallèles diffèrent beaucoup.

Il est communément admis qu'il existe 4 modèles de parallélisme différents :
* Le modèle ***Single Instruction Single Data*** qui est en fait le cas particulier du calcul séquentiel classique. C'est-à-dire une unité de calcul traite une donnée
* Le modèle ***Single Instruction Multiple Data*** qui correspond au cas des instructions de vectorisation. Donc littéralement : le CPU sait travailler avec des vecteurs. C'est-à-dire qu'une unité de calcul applique une instruction à plusieurs données en même temps ce qui donne plusieurs résultats. 
* Le modèle ***Multiple Instruction Multiple Data*** qui correspond au cas des processeurs multi-cœurs et également au cas du cluster. C'est-à-dire que différentes unités de calcul traitent des données différentes. Il s'agit donc du cas le plus général.
* Le modèle ***Multiple Instruction Single Data***, modèle plus atypique et peu utilisé

Dans la suite de ce cours, nous nous concentrerons uniquement sur le modèle de type ***Multiple Instructions Multiple Data***. Car il s'agit du modèle le plus répandu pour ce qui concerne le calcul parallèle. 

Je tiens toute fois à préciser que le modèle ***SIMD*** est de plus en plus en vogue et permet sur les générations récentes de processeurs, d'avoir des gains de performances assez remarquables. En revanche ce modèle se situe à un niveau de granularité relativement fin puisqu'il opère au niveau du cœur et ne travaille qu'avec des données de petite taille (en moyenne 8 données de 32s bit en simultané).

Pour ceux qui s'intéresseraient aux aspects vectorisation des instructions, je vous invite à [regarder cette présentation de l'IDRIS](http://www.idris.fr/media/formations/simd/idrissimd.pdf)

Il faut faire attention au fait que l'on a deux cas de figure bien distincts à considérer et cela vient de l'aspect multi-échelles des architectures de calcul modernes.

Le **premier cas** est celui qui se limite à l'échelle de l'ordinateur ou du nœud de calcul. Dans ce cas il y a un ou plusieurs processeurs (peu importe) comprenant plusieurs cœurs. Pas de difficulté majeure ici, chaque cœur exécute ses instructions, récupère ses données en RAM, prend les données de son voisin s'il en a besoin, ... C'est ce que l'on va appeler notamment du multi-threading. Attention : ne pas confondre multi-threading (qui est le fait d'utiliser en parallèle plusieurs cœurs d'un même processeur dans un programme) et hyper-threading qui est une technologie Intel permettant de multiplier par deux le nombre d'unités de calcul par rapport au nombre de cœurs du processeur). Concrètement l'hyper-threading vous fait croire que vous avez 4 cœurs sur votre ordinateur, alors qu'en réalité vous n'en avez que 2.

Là où les choses se compliquent un peu c'est dans **le second cas** qui se situe à l'échelle du cluster donc de plusieurs ordinateurs connectés entre eux. Au début tout se passe bien, chaque cœur (sur des machines différentes) exécute ses instructions, récupère ses données en RAM, ~~prend les données de son voisin~~ ... Ah oups il ne peut pas prendre les données de son voisin... Ah bon, mais pourquoi me direz vous ? Pour une raison simple voire stupide : les données elles sont où ? Elles sont dans la mémoire vive, or dans ce cas chaque instruction tourne sur des machines physiques différentes donc avec des mémoires vives différentes !! Eh oui voilà le drame : une instruction sur un cœur de l'ordinateur A ne peut pas aller piocher des données dans la RAM de l'ordinateur B.

Il s'agit là de la grande vérité : il y en fait deux types de parallélisme dans le modèle ***MIMD***. 

1. Le parallélisme dit à mémoire partagée, dans ce cas toutes les unités de calcul (cœurs) sont reliées à la mémoire vive et peuvent donc facilement piocher dans les données des voisins. 
2. Le parallélisme dit à mémoire distribuée, dans ce cas toutes les unités de calcul ont leurs propres mémoires vives indépendantes de celles des voisins.

### Une parenthèse sur le parallélisme à mémoire distribuée 

Mais du coup on fait comment en mémoire distribuée si on a besoin d'une valeur d'un voisin ? Eh bien il faut alors faire des opérations de communication entre les unités de calcul. C'est-à-dire ? Eh bien à un moment l'ordinateur A va dire : tiens je vais envoyer la valeur de la variable `ma_super_variable` à l'ordinateur B. Si ce n'était que cela ce serait trop simple, car la difficulté c'est que quand l'ordinateur A envoie sa variable à B il faut que dans le même temps B se dise : tiens, je vais recevoir une variable de A donc je me prépare. Et ça il n'y a pas de miracle il faut que ce soit prévu à la conception du programme. 

Pour mettre en place ce système d'envoi/réception de variables il existe des protocoles bien définis et relativement simples. Pendant plusieurs années les choix ont été multiples mais depuis maintenant plus de 10 ans on peut dire qu'il n'existe qu'une seule manière raisonnable de faire cela c'est en utilisant le protocole ***Message Passing Interface*** (MPI). Il s'agit d'une norme qui définit comment l'échange de données entre processus distants doit être réalisée. Ensuite cette norme est implémentée dans différents standards (Open Source ou propriétaire) et disponible dans de nombreux langages de programmation.

Au passage j'aimerais insister sur un point. Avec l'utilisation de MPI on peut procéder à l'échange de données entre processus distants. Mais à votre avis, est-ce que ce transfert est instantané ? La réponse est bien évidemment non. J'ajouterai même que le point clé dans l'exploitation des architectures fortement parallèles de type cluster, c'est le réseau entre les nœuds de calcul. En effet une donnée qui transite de A vers B passe par le réseau. Or si le réseau n'est pas assez rapide alors le temps de transfert peut devenir prépondérant dans les applications. Par exemple pour illustrer cela je vous propose de regarder le tableau suivant qui évalue les performances réseau entre le cluster moderne du centre de matériaux et notre ancien cluster (aujourd'hui en retraite). Pour réaliser ce test on fait juste un ping-pong d'un paquet de double. 

| Vector size | Time exchange (modern network) | Time exchange (old network) |
|-------------|--------------------------------|-----------------------------|
| 1           |             0.43               |   0.0019                    |
| 10          |             1.21e-5            | 5.69e-5                     |
| 100         |               0.00034231       | 0.002723222                 |
| 1000        |              0.0002660         | 0.00471687                  |
| 10000       |             0.0006988          | 0.016027                    |
| 100000      |            0.005841            | 0.1366                      |
| 10000000    |          0.0567                | 1.3633                      |
| 100000000   |            0.654               |  13.601                     |
| Better data rate |               2819 Mo/s   | 117 Mo/s                    |

On constate alors que sur les gros volumes de données on obtient des facteurs 20 en terme de rapidité de transfert, ce qui n'est pas négligeable.

Je tiens également à vous faire remarquer que ce n'est pas parce que j'ai dit que le parallélisme à mémoire distribuée était plus délicat à mettre en œuvre, qu'il faut en déduire que la version mémoire partagée est triviale ! Ce n'est pas le cas elle soulève un certain nombre de problématiques et c'est ce que nous allons voir dans le notebook qui vient juste après. 

Une question que vous pouvez alors vous poser est : pourquoi se compliquer la vie avec le parallélisme distribué, qui nécessite des infrastructures plus lourdes notamment en terme de réseau ? Pour diverses raisons en fait : 

* Le nombre de cœurs pouvant raisonnablement être contenu sur une seule machine est aujourd'hui limité à une grosse centaine environ
* De la même manière la mémoire vive est une limitation significative. L'intérêt de dispatcher un gros problème sur un ensemble de machines distinctes permet de répartir la charge en terme d'occupation mémoire. En effet pour les problématiques de simulation numérique, les ressources en terme de mémoire vive peuvent vite devenir monstrueuses. Si on reprend par exemple le calcul de l'aube de turbine que je vous ai montré dans l'introduction, la réalisation de ce calcul en séquentiel nécessiterait une machine disposant d'un peu plus de 700 Go de RAM. Ce type de machine existe de nos jours mais ces machines restent quand même relativement rares et excessivement chères.

## Rappel rapide sur les fonctions anonymes 

Pour commencer faisons juste un petit rappel sur les fonctions anonymes ou *lambda* fonctions. En effet lorsque l'on fait de la programmation concurrente en C++ les fonctions anonymes s'avèrent être extrêmement pratiques pour se simplifier la vie. Nous allons donc rapidement faire un tour d'horizon de leurs définitions et utilisations. 

La syntaxe générale des fonctions anonymes est la suivante : 

```c++
[capture]( params ) -> ret { body }
```

* `params` représente la liste des paramètres d'entrée de votre fonction, donc une suite de paramètres nommés et typés, comme dans une fonction classique
* `ret` est le type de retour de votre fonction anonyme, vous pouvez ne pas le préciser il est alors automatiquement déduit si le mot clé `return` est présent dans `body` sinon il est considéré comme `void`
* `body` est le corps de votre fonction
* `capture` est une liste de variables existant dans le scope de déclaration de la fonction anonyme et devant être transmises au scope interne à la fonction.

Vous pouvez si vous le souhaitez stocker votre fonction anonyme dans une variable (pour l'utiliser ensuite) de la manière suivante :

```c++
auto f = [capture](params) -> ret { body };
```

Regardons tout de suite un exemple: 

```c++
#include <iostream>
#include <string>

int main () {

    auto f = [](const std::string& msg){
        std::cout << msg << "\n";
    };

    f("coucou");

    return 0;
}
```

Pour expliquer cette histoire de `capture` regardons l'exemple suivant : 

```c++
double a=2.1;
auto f = [](){ std::cout << "a = " << a << "\n" ; };
// Compilation Error 'a' is not captured 
```

En effet ce code ne compile pas car `a` est bien défini mais n'est pas accessible depuis l'intérieur de la lambda fonction. Une solution me direz vous est alors de passer `a` comme argument d'entrée de la fonction. Oui c'est vrai. Mais on peut également utiliser la partie `capture` de la lambda fonction pour capturer `a` dans le scope de la fonction. Cela donne : 

```c++

double a=2.1;
auto f = [a](){ std::cout << "a = " << a << "\n" ; };
```

En revanche avec cette approche, la variable `a` est en lecture seule au sein de la fonction anonyme. C'est-à-dire que l'on ne peut pas modifier la variable `a` dans la fonction. Si vous souhaitez pouvoir modifier la valeur de `a` il faut la capturer par référence. 

```c++

double a=2.1;
auto f = [&a](){ 
    std::cout << "a = " << a << "\n" ; 
    a = 1024.0;
    };
```

*Remarque* il existe une syntaxe particulière au niveau de la capture permettant de capturer toutes les variables présentes dans le scope de définition de la fonction pour les injecter dans le scope interne de la fonction. Il s'agit de :

* `[=]` qui capture toutes les variables par copie *read-only*
* `[&]` qui capture toutes les variables par références, permettant ainsi de les modifier au sein de la fonction. 

*Remarque 2* bien évidemment ces notations qui ont l'air très pratiques d'utilisation sont plutôt à éviter car je suis sûr que vous en conviendrez ce n'est pas très propre comme approche. Ca manque de classe !


# Programmation multi-thread 

## Introduction 

Pour rappel le modèle de programmation multi-thread a pour principe d'exploiter au maximum l'architecture multi-cœurs des processeurs récents. Pour cela le programme principal va créer des threads qui vont s'exécuter de manière concurrente sur les différents cœurs de votre processeur. Pour ceux qui auraient oublié ce qu'est un thread, également appelé processus léger, c'est un ensemble d’instructions machine regroupées au sein d'une pile d'exécution partageant sa mémoire avec le processus l'ayant créé. Formulé autrement des threads sont des blocs d'instructions C++ partageant entre eux la même mémoire. 

Depuis la norme 2011 du C++, C++11, l'utilisation des threads est fortement simplifiée. Il vous suffit d'inclure le header file correspondant 

```c++
#include <thread>
```

L'élément de base est la classe `std::thread` qui va nous permettre de créer un thread pour une fonction donnée.  

**Minute culturelle :** avant la norme C++11 la programmation multi-thread était relativement pénible car chaque plateforme (comprendre OS) proposait son implémentation des threads qui n'était bien évidemment jamais compatible entre deux OS. L'ajout du support natif du multithread dans la librairie standard est donc un réel apport de la norme C++11. 


## Créer des threads

Considérons tout de suite l'exemple suivant d'une fonction `main` créant un `thread` chargé d'afficher dix fois le même message.

```c++
#include <thread>
#include <iostream>

int main(){
    std::thread t ([]()->void {
        for( int i=0; i<10; i++ ){
            std::cout << "Hello World from thread" << i << std::endl;
        }
    });

    std::cout << "Hello World from the main function " << std::endl;

    t.join();

    return 0;
}
```

```c++
$ g++ main.cpp -lpthread
```

On constate alors à l'exécution que le thread et le programme principal vivent chacun leur vie de leur côté. Bien évidemment il est possible de créer autant de threads qu'on le souhaite dans un programme.  

```c++
#include <thread>
#include <iostream>
#include <vector>

int main(){
    const int n_threads {10};

    std::vector<std::thread> _threads;

    for( int i=0; i<n_threads; i++){
        _threads.push_back(std::thread([](const int& tid)->void {
                            for( int i=0; i<10; i++ ){
                                 std::cout << "Hello World from thread "<< tid << std::endl;
                            }
            }, i) // i est la position du thread dans le vecteur
        );
    }

    std::cout << "Hello World from the main function " << std::endl;

    for(std::thread& t: _threads){
        t.join();
    }

    return 0;
}
```

En exécutant ce code plusieurs fois sur votre ordinateur portable vous allez alors voir apparaître quelque chose de potentiellement étrange... De temps en temps quelques lignes de la sortie sont entremêlées entre elles. Par exemple 

```
Hello World from thread 5Hello World from thread 7
Hello World from thread Hello World from thread 
Hello World from thread Hello World from thread 5
8
Hello World from thread 8
7
```

Bizarre non ? Un avis sur la question ? C'est un effet de ce que l'on appelle un `race condition` ! Le principe est simple, nous avons deux threads qui accèdent simultanément à la même variable partagée et la modifie. C'est le risque lorsque l'on fait du multithread. Pour prévenir cela il est nécessaire de mettre en place des mécanismes de verrouillage.

## Synchroniser des threads

Un mutex, *Mutual Exclusion*, est un objet utilisé en programmation concurrente pour éviter que différents threads n'accèdent simultanément à des ressources partagées. Pour utiliser un `mutex` en C++ il vous suffit d'inclure le header file correspondant :

```c++
#include <mutex>
```

L'objet de base est `std::mutex`, oui ça manque d'originalité tout ça je sais. Cet objet est extrêmement simple car il ne possède que deux méthodes `lock()` et `unlock()`. Comme le nom le laisse imaginer ces deux méthodes ont respectivement pour but de bloquer  et débloquer les threads. 


Reprenons tout de suite l'exemple précédent. 

```c++
#include <vector>
#include <thread>
#include <iostream>
#include <mutex>

std::mutex mtx;

int main(){
  const int n_threads {10};

  std::vector<std::thread> _threads;

  for( int i=0; i<n_threads; i++){
    _threads.push_back(std::thread([](const int& tid)->void {
          for( int i=0; i<10; i++ ){
            mtx.lock();
            std::cout << "Hello World from thread "<< tid << std::endl;
            mtx.unlock();
          }
	}, i)
      );
  }

  std::cout << "Hello World from the main function " << std::endl;

  for(std::thread& t: _threads){
    t.join();
  }

  return 0;
}
```

Afin d'assurer qu'il n'y a pas d'accès simultanés à la sortie standard, via le `std::cout`, on encadre donc la ligne `std::cout` par un appel à la méthode `lock()` entraînant ainsi l'arrêt des autres threads et ensuite un appel à `unlock` pour débloquer les threads.

**Attention** l'utilisation d'un mutex permet en effet de résoudre les problèmes d'accès concurrents aux ressources partagées. En revanche cela a un prix, il s'agit de la performance. En effet le fait de bloquer/débloquer des threads prend un temps, minime certes, mais non nul. Donc si on répète cette opération de nombreuses fois cela va fortement dégrader les performances. 

**Attention** il faut faire très attention lorsque vous utilisez un mutex au fait qu'un `lock` doit toujours être associé à un `unlock` sinon votre programme va se bloquer définitivement. Cela peut s'avérer parfois délicat notamment quand on doit en plus gérer les exceptions. Pour faciliter cela il existe dans la librairie standard, l'objet `std::unique_lock<Mutex>`. Ce dernier permet de faire un `lock` et surtout de déverrouiller le mutex à la sortie du contexte, i.e. sortie de fonction par exemple (l'objet `unique_lock` sera alors détruit et son destructeur libère le lock). Par exemple voici ci-dessous un usage où l'on ne fait pas le `unlock` manuellement :

```c++
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c) {
  std::unique_lock<std::mutex> lck (mtx);
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
}

int main (){
  std::thread th1 (print_block,50,'*');
  std::thread th2 (print_block,50,'$');

  th1.join();
  th2.join();

  return 0;
}
```

## Exemple : calcul de pi 

Pour illustrer cela considérons par exemple le calcul de \f$\pi\f$. Une manière possible pour calculer $\pi$ est d'évaluer numériquement l'intégrale suivante :

\f[
     \pi = \int_{0}^{1} \frac{4}{1+x^2}
\f]
Le calcul séquentiel classique peut se faire de la manière suivante : 

```c++
#include <iostream> 

int main(){

    int nb_point = 100000000;
    double l=1./nb_point;

    double pi=0;
    for( int i=0; i<nb_point; i++){
        double x=l*(i+0.5);
        pi += l*( 4. / (1. + x*x ) );
    }

    std::cout << "PI = " << pi << std::endl;

    return 0;
}
```

Si vous lancez alors ce code et mesurez le temps d'exécution vous obtenez le résultat suivant : 

```bash 
0.84user 0.00system 0:00.85elapsed 98%CPU
```


# Une autre approche des threads : OpenMP 

## Introduction 
OpenMP, pour Open Multi-Processing, est un protocole générique permettant de faire du calcul parallèle à mémoire partagée (multi-thread). L'avantage historique de OpenMP est son support universel sur Linux, Mac et Windows (avantage moins marquant maintenant que les threads sont dans la librairie standard C++).  

La grosse distinction entre OpenMP et de la programmation en thread comme on vient de le voir est que OpenMP se base sur la déclaration de directive dans le code source, on n'ajoute pas de code ou presque pas. 

Par exemple, faisons un programme qui lance plusieurs threads chaque threads traitant une partie des itérations d'une boucle `for`. En utilisant OpenMP ce programme serait : 

```c++
#include <iostream>
#include <omp.h>

int main(){
    #pragma omp parallel for 
    for(int i=0; i<20; i++){
        std::cout << "Element " << i << " dans le thread " << omp_get_thread_num() << std::endl;
    }

}
```

La compilation se fait de la manière suivante : 

```bash 
$ g++ -fopenmp main.cpp -o main
```
Nous pouvons alors remarquer plein de choses : 

* Le parallélisme de la boucle s'est fait en une seule ligne à l'aide de `#pragma omp parallel for`
* On ne précise à aucune moment le nombre de threads => suivant vos ordinateurs vous allez obtenir 2,4 ou 8 threads

Rq: le nombre de thread se contrôle facilement via la fonction `omp_set_num_threads(int)` ou bien par la variable d'environnement `OMP_NUM_THREADS`. 

## Notion de synchronisation en OpenMP 
Dans la programmation à base de threads nous avons vu juste avant que l'on peut être obligé à certains moment de synchroniser des threads ou à minima de vérouiller l'accès à certaines variables pour éviter les problèmes de Race Condition. Dans OpenMP il est également possible prévenir cela en utilisant l'instruction `#pragma omp critical`

Par exemple, si on reprend le calcul de \f$\pi\f$ dans sa version très mal écrite où on fait beaucoup trop de lock avec des directives OpenMP nous pourrions écrire :  

```c++
double pi_computer_bad_critical(const int nb_point, int n_thread ){
  omp_set_num_threads(n_thread);
  double l=1./nb_point;
  double pi=0; 
  #pragma omp parallel 
  {
    double tmp=0;
    #pragma omp for
    for( int i=0; i<nb_point; i++){
      double x = l*(i+0.5);
      #pragma omp critical 
      pi += l*( 4. / (1. + x*x ) );
    }
  }
  return pi;
}

```

Ainsi avec la directive `#pragma omp critical` on déclare que la ligne juste en dessous est critique, i.e. que lorqu'un thread l'exécute il ne faut surtout pas que les autres threads y touchent. 

Bien évidemment la bonne version du calcul de $\pi$ est la suivante : 

```c++
double pi_computer_critical(const int nb_point, int n_thread ){

  omp_set_num_threads(n_thread);
  double l=1./nb_point;

  double pi=0;
  
  #pragma omp parallel 
  {
    double tmp=0;
    #pragma omp for
    for( int i=0; i<nb_point; i++){
      double x = l*(i+0.5);
      tmp += l*( 4. / (1. + x*x ) );
    }
    #pragma omp critical 
    pi += tmp;
  }
  return pi;
}
```

## Opérations de réduction

Il existe en OpenMP une autre notion qui peut s'avérer fortement utile pour les applications type calcul scientifique c'est la notion de reduction. L'intérêt est d'optimiser les opérations cumulées sur une variable. Par exemple dans le cas de $\pi$ il y a la ligne faisant la somme `pi+=l*(4./(1+x*x));` En utilisant une directive de réduction nous pouvons simplifier le code parallèle de la manière suivante : 

```c++
double pi_computer_reduction(const int nb_point, int n_thread ){

  omp_set_num_threads(n_thread);
  double l=1./nb_point;

  double pi=0;
  #pragma omp parallel for reduction(+:pi)
  for( int i=0; i<nb_point; i++){
    double x = l*(i+0.5);
    pi += l*( 4. / (1. + x*x ) );
  }
  return pi;
}
```

## Différences entre OpenMP et Threads**
A première vu nous pourrions dire que OpenMP c'est vachement plus simple et qu'il ne faut pas se prendre la tête à utiliser les threads directement. 

Je nuancerai en donnant les élements suivants : 

* OpenMP est à visée calcul scientifique, ultra performant pour les boucles for 
* Dès que l'on veut un peu de finesse dans la gestion de threads, par exemple deux threads qui font deux choses complètement différentes, pas le choix on ne peut plus utiliser OpenMP. 


# Le modèle producteur/consommateur 

Pour finir ce premier tour d'horizon de la concurrence en C++ je vous propose de faire un exemple de gestion d'un ensemble de tâches. Il s'agit d'un système où l'on a une queue contenant les différents paramètres d'entrée, par exemple une requête à faire à une base de donnée, et des `workers` viennent piocher dans la queue font la requête et mettent le résultat dans une nouvelle `queue`.

Si vous êtes encore bien éveillé vous aurez peut-être remarqué que dans le scénario précédent on a besoin d'une `queue` mais il faut qu'elle soit un peu particulière puisque qu'elle va être partagée entre plusieurs fil d'exécution... Il faut donc que l'on s'occupe des problèmes d'accès concurrents. En d'autre mot quand on va faire un `pop()` par exemple et bien il faut être sur qu'un autre fil d'exécution ne fait pas un `pop()` exactement au même moment. Il nous faut donc une `queue` qui soit *thread-safe*.  Alors dans les cours Python vous avez l'habitude que je vous dise qu'il s'agit d'un langage merveilleux et donc que tout est déjà fait pour vous ... Et bien pas de chance en C++ c'est pas la même chose, néanmoins C++ reste un langage merveilleux pas de doute à ce sujet. Mais on vous prend moins la main donc pas de `queue` thread-safe sur étagère. Mais pas d'inquiétude vous allez voir c'est facile. 

Alors pour faire notre `queue` asynchrone, que l'on appellera avec beaucoup d'originalité `AsyncQueue` nous allons avoir besoin de trois choses : 

* La queue synchrone classique de la librairie standard `std::queue`
* Un mutex qui nous permettra de verrouiller la queue lorsque l'on opère dessus
* Une variable conditionnelle `std::condition_variable`, il s'agit d'un objet de la librairie standard qui permet de synchroniser les threads et de notifier des threads de certains évènements. 

Le fonctionnement attendu de la `AsyncQueue` est le suivant : lorsqu'un thread fait une action sur la queue (`push`, `pop` ou `empty`), un thread qui voudrait faire une action quelconque sur la queue est bloqué, un thread qui ne touche pas à la queue continue son exécution. 
 
Ci-dessous un exemple d'implémentation de cette `AsyncQueue`, vous remarquerez l'usage de la méthode `wait` dans la méthode `pop` qui, dans le cas où la queue est vide, permet à un thread d'attendre qu'un autre thread fasse un `push` pour retourner un résultat.

```c++
#include<iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <sstream>
#include <thread>

template<typename T>
class AsyncQueue {
private:
    std::queue<T> _queue;
    std::mutex _mtx;
    std::condition_variable _notifier;

public:
    AsyncQueue()=default;
    AsyncQueue(const AsyncQueue&) = delete;
    AsyncQueue& operator=(const AsyncQueue&) = delete;

    bool empty(){
        std::unique_lock<std::mutex> lock(this->_mtx);
        bool ret = this->_queue.empty();
        lock.unlock();
        return ret;
    }

    void push(const T& x){
        std::unique_lock<std::mutex> lock(this->_mtx);
        this->_queue.push(x);
        lock.unlock();
        this->_notifier.notify_one();
    }

    T pop(){
        std::unique_lock<std::mutex> lock(this->_mtx);
        while(this->_queue.empty()){
            this->_notifier.wait(lock);
        }
        T val = this->_queue.front();
        this->_queue.pop();
        return val;
    }
};
```

Une fois que nous avons fait notre `AsyncQueue` nous avons fait le plus dur !! Le reste c'est facile. Alors juste pour le cosmétique nous allons commencer par faire une fonction `async_print` qui va s'assurer que l'on ait pas de chevauchement des lignes à l'affichage. 

```c++

void async_print(std::string x) {     // Thread safe print 
  static std::mutex mutex;
  std::unique_lock<std::mutex> locker(mutex);
  std::cout << x << "\n";
  locker.unlock();
}
```

Ensuite on fait notre fonction `worker` qui prend en entrée la queue contenant les données d'entrées et la queue initialement vide qui va nous permettre de stocker les résultats. Le principe de cette fonction est très simple, tant que la queue des entrées n'est pas vide on fait quelque chose. Le quelque chose en question dans ce cas étant de dormir pendant X secondes avec X le numéro du worker. 

```c++
void worker(AsyncQueue<int>& input,
	    unsigned int id,
	    AsyncQueue<std::string>& output) {
  while( ! input.empty() ){
    auto item = input.pop();
    std::ostringstream tmp;
    tmp << " " << item << " --> C" << id;
    async_print(tmp.str());
    std::this_thread::sleep_for(std::chrono::seconds(id));
    tmp.str("");
    tmp << "       " << item << " done " << "C" << id << " --->  results";
    async_print(tmp.str());
    tmp.str("");
    tmp << "done " << item;
    output.push( tmp.str() );
  }
}
```

Pour finir nous pouvons alors écrire notre `main` de la manière suivante par exemple.

```c++
int main()
{
  const int nbWorker {4};
  const int nbInput {14};

  AsyncQueue<int> q;
  AsyncQueue<std::string> results;

  for( int i=0; i<nbInput ; i++){
    q.push( i );
  }

  std::vector<std::future<void> > workers;
  for (int i = 0 ; i < nbWorker ; ++i) {
    std::future<void> w = std::async(std::launch::async, worker, std::ref(q), i + 1, std::ref(results));
    workers.push_back(std::move(w));
  }

  for (auto& w : workers) {
    w.get();
  }

  while(!results.empty()){
    std::cout << results.pop() << std::endl;
  }
  return 0;
}
```

L'exécution de ce code donne alors le résultat suivant : 

```
 1 --> Worker2
 0 --> Worker1
 2 --> Worker3
 3 --> Worker4
       0 done Worker1 --->  results
 4 --> Worker1
       1 done Worker2 --->  results
 5 --> Worker2
       4 done Worker1 --->  results
 6 --> Worker1
       2 done Worker3 --->  results
 7 --> Worker3
       6 done Worker1 --->  results
 8 --> Worker1
       5 done Worker2 --->  results
 9 --> Worker2
       3 done Worker4 --->  results
 10 --> Worker4
       8 done Worker1 --->  results
 11 --> Worker1
       11 done Worker1 --->  results
 12 --> Worker1
       9 done Worker2 --->  results
 13 --> Worker2
       7 done Worker3 --->  results
       12 done Worker1 --->  results
       10 done Worker4 --->  results
       13 done Worker2 --->  results
done 0
done 1
done 4
done 2
done 6
done 5
done 3
done 8
done 11
done 9
done 7
done 12
done 10
done 13
```