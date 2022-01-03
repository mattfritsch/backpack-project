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

Le résultat s'affichera à la suite de cette commande.
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
bin/backpack A 0 10 1 3 5 6
mode=A usefullness=N Vmax=10
Object set full with 4 objects

*** View objet set ***
(1 , 1) (3 , 3) (5 , 5) (6 , 6) 
**********************
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#1 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       1       1       1       1       1       1       1       1       1       1
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#2 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       1       1       1       1       1       1       1       1       1       1
  2 |    0       1       1       3       4       4       4       4       4       4       4
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#3 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       1       1       1       1       1       1       1       1       1       1
  2 |    0       1       1       3       4       4       4       4       4       4       4
  3 |    0       1       1       3       4       5       6       6       8       9       9
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#4 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       1       1       1       1       1       1       1       1       1       1
  2 |    0       1       1       3       4       4       4       4       4       4       4
  3 |    0       1       1       3       4       5       6       6       8       9       9
  4 |    0       1       1       3       4       5       6       7       8       9      10

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4

******
Total packaging utility : 10
******
        objet #4(6, 6)
        objet #2(3, 3)
        objet #1(1, 1)
````
#### Jeu d'essai n°2 (Utilité = 0)
```cmd
bin/backpack A 0 30 12 3 5 6 25 14 3 9 7 4
mode=A usefullness=N Vmax=30
Object set full with 10 objects

*** View objet set ***
(12 , 12) (3 , 3) (5 , 5) (6 , 6) (25 , 25) (14 , 14) (3 , 3) (9 , 9) (7 , 7) (4 , 4) 
**********************
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#1 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#2 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#3 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#4 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#5 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      25      26      26      28      28      30
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE      0      PRE     PRE      3       4       5
  6 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#6 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      25      26      26      28      28      30
  6 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      23      25      26      26      28      29      30
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE      0      PRE     PRE      3       4       5
  6 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE       8       9      10      11      12      13      14      15      PRE
  7 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#7 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      25      26      26      28      28      30
  6 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      23      25      26      26      28      29      30
  7 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      26      28      29      30
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE      0      PRE     PRE      3       4       5
  6 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE       8       9      10      11      12      13      14      15      PRE
  7 |   PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      10      11      12      13      14      15      PRE     17      18       19      20      21      22      23      24      25      26      PRE
  8 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#8 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      25      26      26      28      28      30
  6 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      23      25      26      26      28      29      30
  7 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      26      28      29      30
  8 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      27      28      29      30
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE      0      PRE     PRE      3       4       5
  6 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE       8       9      10      11      12      13      14      15      PRE
  7 |   PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      10      11      12      13      14      15      PRE     17      18       19      20      21      22      23      24      25      26      PRE
  8 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      PRE     11      12       PRE     14      15      PRE     17      18      19      20      21
  9 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#9 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      25      26      26      28      28      30
  6 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      23      25      26      26      28      29      30
  7 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      26      28      29      30
  8 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      27      28      29      30
  9 |    0       0       0       3       3       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE      0      PRE     PRE      3       4       5
  6 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE       8       9      10      11      12      13      14      15      PRE
  7 |   PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      10      11      12      13      14      15      PRE     17      18       19      20      21      22      23      24      25      26      PRE
  8 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      PRE     11      12       PRE     14      15      PRE     17      18      19      20      21
  9 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE      8       9      PRE     11      12      PRE     14       15      PRE     17      18      19      20      21      22      23
 10 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#10 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       0       0       0       0       0       0       0       0       0       0       0      12      12      12      12      12      12      12      12      12      12       12      12      12      12      12      12      12      12      12
  2 |    0       0       0       3       3       3       3       3       3       3       3       3      12      12      12      15      15      15      15      15      15      15       15      15      15      15      15      15      15      15      15
  3 |    0       0       0       3       3       5       5       5       8       8       8       8      12      12      12      15      15      17      17      17      20      20       20      20      20      20      20      20      20      20      20
  4 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      23      26      26      26      26      26
  5 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      18      20      21       21      23      23      25      26      26      28      28      30
  6 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      23      25      26      26      28      29      30
  7 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      26      28      29      30
  8 |    0       0       0       3       3       5       6       6       8       9       9      11      12      12      14      15      15      17      18      19      20      21       22      23      24      25      26      27      28      29      30
  9 |    0       0       0       3       3       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
 10 |    0       0       0       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15      16      17      18
  2 |   PRE     PRE     PRE      0       1       2       3       4       5       6       7       8      PRE     PRE     PRE     12      13      14      15      16      17      18       19      20      21      22      23      24      25      26      27
  3 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6      PRE     PRE     PRE     PRE     PRE     12      13      14      15      16       17      18      19      20      21      22      23      24      25
  4 |   PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5      PRE     PRE      8      PRE     PRE     PRE     12      13      PRE     15       16      17      18      19      20      21      22      23      24
  5 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE      0      PRE     PRE      3       4       5
  6 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE       8       9      10      11      12      13      14      15      PRE
  7 |   PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      10      11      12      13      14      15      PRE     17      18       19      20      21      22      23      24      25      26      PRE
  8 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1      PRE      3       4       5       6       7       8       9      PRE     11      12       PRE     14      15      PRE     17      18      19      20      21
  9 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6      PRE      8       9      PRE     11      12      PRE     14       15      PRE     17      18      19      20      21      22      23
 10 |   PRE     PRE     PRE     PRE      0      PRE     PRE      3      PRE      5       6       7       8       9      10      11      12      13      14      15      16      17       18      19      20      21      22      23      24      25      26

******
Total packaging utility : 30
******
        objet #10(4, 4)
        objet #9(7, 7)
        objet #6(14, 14)
        objet #3(5, 5)
````
#### Jeu d'essai n°3 (Utilité = 1)
```cmd
bin/backpack A 1 10 2 3 4 9 5 6 1 8
mode=A usefullness=U Vmax=10
Object set full with 4 objects

*** View objet set ***
(2 , 3) (4 , 9) (5 , 6) (1 , 8) 
**********************
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#1 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       0       3       3       3       3       3       3       3       3       3
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE      0       1       2       3       4       5       6       7       8
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#2 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       0       3       3       3       3       3       3       3       3       3
  2 |    0       0       3       3       9       9      12      12      12      12      12
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE      0       1       2       3       4       5       6       7       8
  2 |   PRE     PRE     PRE     PRE      0       1       2       3       4       5       6
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#3 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       0       3       3       3       3       3       3       3       3       3
  2 |    0       0       3       3       9       9      12      12      12      12      12
  3 |    0       0       3       3       9       9      12      12      12      15      15
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE      0       1       2       3       4       5       6       7       8
  2 |   PRE     PRE     PRE     PRE      0       1       2       3       4       5       6
  3 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      4       5
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND

#4 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0
  1 |    0       0       3       3       3       3       3       3       3       3       3
  2 |    0       0       3       3       9       9      12      12      12      12      12
  3 |    0       0       3       3       9       9      12      12      12      15      15
  4 |    0       8       8      11      11      17      17      20      20      20      23

CHM |    0       1       2       3       4       5       6       7       8       9      10
----|----------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE     PRE      0       1       2       3       4       5       6       7       8
  2 |   PRE     PRE     PRE     PRE      0       1       2       3       4       5       6
  3 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      4       5
  4 |   PRE      0       1       2       3       4       5       6       7       8       9

******
Total packaging utility : 23
******
        objet #4(1, 8)
        objet #3(5, 6)
        objet #2(4, 9)
````
#### Jeu d'essai n°4 (Utilité = 1)
```cmd
bin/backpack A 1 30 1 3 5 6 42 8 9 10
mode=A usefullness=U Vmax=30
Object set full with 4 objects

*** View objet set ***
(1 , 3) (5 , 6) (42 , 8) (9 , 10) 
**********************
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#1 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3        3       3       3       3       3       3       3       3       3
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20       21      22      23      24      25      26      27      28      29
  2 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#2 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3        3       3       3       3       3       3       3       3       3
  2 |    0       3       3       3       3       6       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9        9       9       9       9       9       9       9       9       9
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20       21      22      23      24      25      26      27      28      29
  2 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16       17      18      19      20      21      22      23      24      25
  3 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#3 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3        3       3       3       3       3       3       3       3       3
  2 |    0       3       3       3       3       6       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9        9       9       9       9       9       9       9       9       9
  3 |    0       3       3       3       3       6       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9        9       9       9       9       9       9       9       9       9
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20       21      22      23      24      25      26      27      28      29
  2 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16       17      18      19      20      21      22      23      24      25
  3 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE
  4 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND

#4 Object
OPT |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |    0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0       0        0       0       0       0       0       0       0       0       0
  1 |    0       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3       3        3       3       3       3       3       3       3       3       3
  2 |    0       3       3       3       3       6       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9        9       9       9       9       9       9       9       9       9
  3 |    0       3       3       3       3       6       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9       9        9       9       9       9       9       9       9       9       9
  4 |    0       3       3       3       3       6       9       9       9      10      13      13      13      13      16      19      19      19      19      19      19      19       19      19      19      19      19      19      19      19      19

CHM |    0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20      21       22      23      24      25      26      27      28      29      30
----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  0 |   UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND     UND      UND     UND     UND     UND     UND     UND     UND     UND     UND
  1 |   PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16      17      18      19      20       21      22      23      24      25      26      27      28      29
  2 |   PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9      10      11      12      13      14      15      16       17      18      19      20      21      22      23      24      25
  3 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE
  4 |   PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE     PRE      0       1       2       3       4       5       6       7       8       9      10      11      12       13      14      15      16      17      18      19      20      21

******
Total packaging utility : 19
******
        objet #4(9, 10)
        objet #2(5, 6)
        objet #1(1, 3)
````
