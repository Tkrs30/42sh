# 42sh

Le 42sh est un projet qui a toujours existé à Epitech. Ce projet fait partie des 3 projets de fin de première année, c'est un shell UNIX inspiré du célèbre TCSH. Le but de ce projet est de faire une réplique de ce shell déjà existant qui lui-même a été inspiré d'un shell existant de l'époque. Le TCSH est basé sur le C shell soit CSH. Il a apporté plusieurs améliorations par rapport au CSH dont l'édition de commande en ligne. TCSH a remplacé le C shell sur la plupart des systèmes UNIX comme le Mac OS X jusqu'à la version Mac OS X v10.2 où il sera remplacé par bash.  Bien qu'il ne soit plus le shell par défaut des systèmes UNIX il reste quand même présent et est régulièrement mis à jour. Exemple d'une session de TCSH 

![220px-Tcsh_screenshot](https://user-images.githubusercontent.com/71844868/124453657-e2c7cb00-dd87-11eb-849b-87fdd82e6bbe.png)

# Utilisation

Avant d'utiliser le projet, il faut le compiler, ce projet est écris en C donc un langage qui demande une compilation. Pour cela, vous avez à disposition dans le projet un Makefile avec plusieurs règles que vous pouvez utiliser.
Il y a 4 règles :
  - all : cette règle est la règle par défaut, c'est elle qui va permettre de compiler le projet. Pour l'utiliser faites dans votre terminal : "make".
  - clean : cette règle s'occupe d'effacer les fichiers.o qui ont servi à la compilation afin d'y voir plus clair dans votre projet. Pour l'utiliser faites dans votre terminal : "make clean"
  - fclean : cette règle permet de faire le meme travail que clean mais en plus, elle va effacer le binaire que vous avez créé en utilisant la première règle. Pour utiliser cette règle faites dans votre terminal : "make fclean"
  - re : cette règle va utiliser deux règles, elle va utiliser fclean et all, ce qui veut dire que cette règle va supprimer les fichiers de la compilation ainsi que le binaire pour ensuite le recréer derrière. Cette règle est très utilisée quand on met à jour un projet pour pouvoir tester ce qu'on vient d'ajouter au projet.

Maintenant, que je vous ai expliqué cela, vous savez compiler le projet et vous pouvez donc exécuter le binaire dans votre terminal en faisant "./42sh".
Après l'exécution, vous devriez avoir ceci qui s'affiche dans votre terminal :

![execution](https://user-images.githubusercontent.com/71844868/124455318-bad96700-dd89-11eb-9328-c8cb99eec407.png)

Vous êtes maintenant dans le shell 42sh. D'ici, vous allez pouvoir lancer les commandes de bases tel que ls permettant d'afficher dans le terminal les fichiers du repertoire dans lequel on se trouve, ou bien pwd qui permet de savoir où on se trouve ou encore cd permettant de se deplacer dans votre ordinateur. Voici un exemple :

![utilisation_42sh](https://user-images.githubusercontent.com/71844868/124455829-4a7f1580-dd8a-11eb-818f-eaf168e32dfb.png)

Comme je vous l'ai dit plus tôt, TCSH a son lot de nouveauté par rapport à CSH, c'est pourquoi le 42sh doit contenir les nouveauté de TCSH. Grace a TCSH on peut définir des variables d'environnement en utilisant les commandes setenv et unsetenv. Ces deux commandes vont directement modifier l'environnement et peu donc aussi supprimer des variables par défaut de l'environnement. Voici un exemple :

![setenv](https://user-images.githubusercontent.com/71844868/124469176-5377e300-dd9a-11eb-8fd7-49842fdc0f86.png)

Ici, je vais set la variable d'environnement coucou et faire apparaître l'environnement avec la commande env. Voyez ensuite que la variable coucou existe :

![coucou](https://user-images.githubusercontent.com/71844868/124469304-7904ec80-dd9a-11eb-9269-4e5bff943483.png)

On peut également faire le contraire, on va supprimer la variable coucou de l'env :

![unsetenv](https://user-images.githubusercontent.com/71844868/124469369-920d9d80-dd9a-11eb-87e9-69acf4fc65f0.png)

J'effectue la commande unsetenv et fais apparaître l'env par la suite pour vérifier que coucou n'existe plus :

![rm_coucou](https://user-images.githubusercontent.com/71844868/124469444-abaee500-dd9a-11eb-9ebe-e9e16eefe323.png)

Ainsi, nous pouvons voir que la variable coucou n'existe plus.
