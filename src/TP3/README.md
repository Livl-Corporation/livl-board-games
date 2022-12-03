# TP3 v2 - implémentation des principes SOLID

- Déplacement de la méthode `firstRowAvailableInCol()` de la classe `power4` à la classe `grid`, car sinon la classe `power4` a plusieurs responsabilités et si dans le futur on modifie l'état de notre grille on devra aussi faire la modification dans la classe `power4` ce qui n'est pas du tout une bonne manière d’après le principe de *Single Responsability*.

- Création d’interfaces `cellRequester` et `gameEvaluator` permettant d'implémenter n’importe quelle méthode de demande de case au joueur et de détermination du gagnant sans altérer le code en place :

    - `cellRequester` : Une classe qui s’occupe de demander une cellule du joueur avec plusieurs implémentations possibles selon les jeux (dans game) créer une classe qui aura une méthode dedans (askForCell)

    - Dans `power4` et `tictactoe` on va créer une classe qui va définir l’interface `CellRequester` qui va s’occuper de `gameEvaluator` : on retire à la grille la responsabilité de compter les pions consécutifs d'un joueur. A la place, on crée une nouvelle classe  dont l’unique responsabilité sera de déterminer si un joueur a gagné a un jeu ou non.


> Travail effectué en groupe de deux personnes avec Franck Gutmann et Julien Von Der Marck. Modification et évaluation du code fait en live share sur VScode. 
