Achour Nawresse 11706748
Altay Fatmana 11706619
HASSANI Yawoumihani 11503521

Vous trouverez ici l'Application Youhpi, qui permet de "visiter" des pays et des monuments que nous avons répertorié et que nous suggerons,
et d'ajouter des pays et des monuments non répertoriés. 
Vous pouvez retrouver 4 sous-répertoires:
- data qui contient les images des Continents, des Pays et des Monuments,une police ttf, une image d'accueil et une image de menu.
- doc qui nous permet de générer la documentation sur une page html.
- obj regroupant les fichier objets (fichiers.o).
- src contenant les fichiers Image.cpp, Pixel.cpp, Image.h, Pixel.h, Application.cpp,Application.h, Carte.cpp, Carte.h, Pays.cpp, Pays.h,Continent.cpp,Continent.h,Monument.cpp,Monument.h, ElementTD.cpp, ElementTD.h, TableauDynamique.cpp, TableauDynamique.h . 

Ainsi qu'un fichier Makefile qui permet de lancer la compilation en tapant la commande make.
Pour éxecuter il faut lancer la commande ./bin/nom_executable.

Nous proposons deux executables pour cette application. Une version texte et une version graphique.

La classe Application inclut Carte.h, Continent.h, Pays.h, et Monument.h.
C'est la classe avec laquelle nous avons implémenté la version texte. Elle nous permet, via une boucle évenementielle d'afficher(nos continents,pays,monuments avec leurs informations). 
La version texte permet à l'utilisateur de visiter les différents continents,pays et monuments que nous avons choisis.
De plus on propose à l'utilisateur une sélection de monuments à visiter selon la saison,de pouvoir liker un monument,d'ajouter des monuments et des pays non répertoriés, et de se rediriger vers une page web.

La classe sdlApp inclut dans Image.cpp nous permet d'implémenter la version graphique.  
Elle nous permet, via une boucle évenementielle d'afficher nos continents,pays,monuments. 
La version graphique permet à l'utilisateur de visiter les différents continents,pays et monuments que nous avons choisis.
Cependant nous avions prévu que la version graphique permettrais aussi d'avoir les mêmes fonctionnalités que la version texte.
C'est à dire, l'ajout de pays et de monuments, liker un monument, consulter la sélection selon les saisons, et pouvoir se rediriger vers une page web.
En effet nous avons rencontré des problèmes avec SDL2 surtout pour la saisie de texte, et la récupération de cette saisie.




