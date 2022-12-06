# TP3 v2 - implémentation des principes SOLID

- Déplacement de la méthode `firstRowAvailableInCol()` de la classe `Power4` à la classe `Grid`, car sinon la classe `Power4` a plusieurs responsabilités et si dans le futur on modifie l'état de notre grille on devra aussi faire la modification dans la classe `Power4` ce qui n'est pas du tout une bonne manière d’après le principe de *Single Responsability*.

- Création d’interfaces `CellRequester` et `GameEvaluator` permettant d'implémenter n’importe quelle méthode de demande de case au joueur et de détermination du gagnant sans altérer le code en place :

    **Modification efféctué dans la classe Game**
    ![](../../img/rapport-one.jpg)

    - La classe `Game` a deux variables nommés `gameEvaluator` de type `GameEvaluator` et `cellRequester` de type `CellRequester` qui sont toutes les deux des interfaces. 

    - Interface `CellRequester` : Une classe qui s’occupe de demander une cellule du joueur avec plusieurs implémentations possibles selon les jeux (dans `Game`). Dans `Power4` et `TicTacToe` on va créer une classe qui va implémenter l’interface `CellRequester` s'appellant `Power4CellRequester` et `TicTacToeCellRequester` qui vont définir la méthode `askForCell()` qui est différente des deux modes de jeux. On respecte donc le principe *Single Responsability*.  

    Comme le montre l'image ci-dessus, on utilise le principe de *Dependency Inversion*, à la ligne 53 (`this->cellRequester->askForCell(getPlayerChar(playerId));`), la variable `cellRequester` est de type `CellRequester` qui provient de l'interface directement, on n'indique pas ici une variable de type `Power4CellRequester` ou `TicTacToeCellRequester`, cela évite de faire des conditions inutile et d'éviter un couplage fort.  

    - Interface `GameEvaluator` : Dans le package `defaults`, on crée une classe `DefaultGameEvaluator` (qui implémente l'interface `GameEvaluator`) qui sera par défaut commune pour les deux modes de jeux `Power4` et `TicTacToe`. Le but étant de retirer à la grille la responsabilité de compter les pions consécutifs d'un joueur. L'interface `GameEvaluator` aura donc pour unique responsabilité de déterminer si un joueur a gagné un jeu ou non en mettant une unique méthode appellée `hasPlayerWon()`. On respecte donc le principe *Single Responsability*.  


> Travail effectué en groupe de deux personnes avec Franck Gutmann et Julien Von Der Marck. Modification et évaluation du code fait en live share sur VScode. 
