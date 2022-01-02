# backpack-project
## 1) Etat du projet
### 1.1) Version exécutable
- [x] Version récursive
- [x] Version dynamique à mémoire statique
- [ ] Version dynamique à mémoire dynamique
### 1.2) Version non-exécutable
Malheureusement, après avoir essayé de faire la version dynamique à mémoire dynamique,  nous n'avons pas réussi. Donc la fonction dp-list ne fait rien. 
## 2) Consigne à l'éxécution
Pour exécuter le projet, il suffit : 
* D'ouvrir un terminal à la racine de notre projet.
* Puis écrire ```make``` dans le terminal afin de compiler le projet.
* Une fois la compilation terminée vous pouvez effectuer la commande ```clear``` pour que l'affichage soit plus clair.
* Taper ensuite dans le terminal la commande :
  * Si l'utilité est à 0 : ```bin/backpack A|R|L 0 Vmax V0 V1 ... Vn```
  * Si l'utilité est à 1 : ```bin/backpack A|R|L 1 Vmax V0 U0 V1 U1 ... Vn Un```

Le résultat s'affichera à la suite de cette commande
### 2.1) Explication des modes d'exécution
* R : Version récursive.
* A : Version dynamique à mémoire statique.
* L : Version dynamique à mémoire dynamique.
## 3) Jeux d'essais
Voici quelques jeux d'essais de chaque mode d'exécution.
### 3.1) Version récursive
#### Jeu d'essai n°1 (Utilité = 0)
```cmd
bin/backpack R 0 10 1 2 3
mode=R usefullness=N Vmax=10
Object set full with 3 objects

*** View objet set ***
(1 , 1) (2 , 2) (3 , 3) 
**********************

*****************
VIEW BAGPACKAGING       Final selection
[
(3 , 3) (2 , 2) (1 , 1) ]

With utilities sum = 6
````
#### Jeu d'essai n°2 (Utilité = 0)
```cmd
bin/backpack R 0 10 14 3 22 6 8
mode=R usefullness=N Vmax=10
Object set full with 5 objects

*** View objet set ***
(14 , 14) (3 , 3) (22 , 22) (6 , 6) (8 , 8) 
**********************

*****************
VIEW BAGPACKAGING       Final selection
[
(6 , 6) (3 , 3) ]

With utilities sum = 9
````
#### Jeu d'essai n°3 (Utilité = 1)
```cmd
bin/backpack R 1 10 4 3 5 2 12 8 1 6 3 4
mode=R usefullness=U Vmax=10
Object set full with 5 objects

*** View objet set ***
(4 , 3) (5 , 2) (12 , 8) (1 , 6) (3 , 4) 
**********************

*****************
VIEW BAGPACKAGING       Final selection
[
(3 , 4) (1 , 6) (4 , 3) ]

With utilities sum = 13
```` 
#### Jeu d'essai n°4 (Utilité = 1)
```cmd
bin/backpack R 1 24 4 3 5 2 12 8 1 6 3 4
mode=R usefullness=U Vmax=24
Object set full with 5 objects

*** View objet set ***
(4 , 3) (5 , 2) (12 , 8) (1 , 6) (3 , 4) 
**********************

*****************
VIEW BAGPACKAGING       Final selection
[
(1 , 6) (12 , 8) (5 , 2) (4 , 3) ]

                With utilities sum = 19
````
### 3.2) Version dynamique à mémoire statique
#### Jeu d'essai n°1 (Utilité = 0)
```cmd
bin/backpack A 0 10 1 2 3
mode=A usefullness=N Vmax=10
Object set full with 3 objects

*** View objet set ***
(1 , 1) (2 , 2) (3 , 3) 
**********************
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   UND     UND     UND     UND     UND     UND     UND     UND      0      UND     UND
  2 |   UND     UND     UND      0      UND     UND     UND     UND     UND      0      UND
  3 |    0       0      UND      0       0      UND      0       0       0       0       0

#1 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     INF     INF     INF
  2 |   INF     INF     UND     UND     UND     INF     INF     INF     UND      0      UND
  3 |    0       0      UND      0       0      UND      0       0       0       0       0

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     UND     UND     UND     PRE     PRE     PRE
  2 |   UND      0      UND      0       0      UND      0       0      UND      0       0
  3 |    0       0       0       0       0       0       0       0       0       0       0

#2 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     INF     INF     INF
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     INF     INF     INF
  3 |   UND     UND     UND     UND     UND     INF     INF     INF      0       0       0

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     UND     UND     UND     UND     UND     UND     UND     UND
  2 |   PRE     PRE     PRE     UND     UND     UND     UND     UND     PRE     PRE     PRE
  3 |    0       0       0       0       0       0       0       0       0       0       0

#3 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     INF     INF     INF
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     INF     INF     INF
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     INF     INF     INF

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     UND     UND     UND     UND     UND     UND     UND     UND
  2 |   PRE     PRE     PRE     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   PRE     PRE     PRE     UND     UND     UND     UND     UND     PRE     PRE     PRE

******
Total packaging utility : -1
******
        objet #2(2, 2)
        objet #1(1, 1)
````
