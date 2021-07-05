# 42sh

Le 42sh est un projet qui a toujours existé a Epitech.  Ce projet fais partis des 3 projet de fin de premiere année, c'est un shell unix inspiré du celebre TCSH.  Le but de ce projet est de faire une replique de ce shell deja existant qui lui meme a été inspiré du shell existant a l'epoque.  Le TCSH est basé sur le C shell soit CSH.  Il a apporté plusieurs amelioration par rapport au CSH dont l'edition de commande en ligne.  TCSH a remplacé le C shell sur la plupart des systeme unix comme le Mac OS X jusqu'a la version Mac OS X v10.2 ou il sera remplacé par bash.  Malgré qu'il ne soit plus le shell par defaut des systemes UNIX il reste quand meme present et est regulierement mis a jour.
Eemple d'une session de TCSH :

![220px-Tcsh_screenshot](https://user-images.githubusercontent.com/71844868/124453657-e2c7cb00-dd87-11eb-849b-87fdd82e6bbe.png)

# Utilisation

Avant d'utiliser le projet, il faut le compiler, ce projet est ecris en C donc un language qui demande une compilation.  Pour cela vous avez a disposition dans le projet un Makefile avec plusieurs regles que vous pouvez utiliser.
Il y a 4 regles :
  - all : cette regles est la regle par defaut, c'est elle qui vas permettre de compiler le projet.  Pour l'utiliser faites dans votre terminal : "make".
  - clean : cette regle elle s'occupe d'effacer les fichier .o qui ont servis a la compilation afin d'y voir plus clair dans votre projet.  Pour l'utiliser faites dans votre terminal : "make clean"
  - fclean : cette regles permet de faire le meme travail que clean mais en plus elle va effacer le binaire que vous avez créé en utilisant la premiere regles.  Pour utiliser cette regle faites dans votre terminal : "make fclean"
  - re : cette regles vas utiliser deux regles, elle vas utiliser fclean et all, ce qui veut dire que cette regle vas supprimer les fichier de la compilation ainsi que le binaire pour ensuite le recréer derriere.  Cette regles est tres utilisé quand on met a jour un projet pour pouvoir tester ce qu'on viens d'ajouter au projet.

Maintenant queje vous ai expliqué ca vous savez compiler le peojet et vous pouvez donc executer le binaire en l'exutant dans votre terminal en faisant "./42sh".
Apres l'execution vous devriez avoir ceci qui s'affciher dans votre terminal :

![execution](https://user-images.githubusercontent.com/71844868/124455318-bad96700-dd89-11eb-9328-c8cb99eec407.png)

Vous etes maintant dans le shell 42sh.  D'ici vous allez pouvoir lancer les commandes de bases tel que ls ou bien pwd qui permet de savoir ou on se trouve ou encore cd permettant de se deplacer dans votre ordinateur.  Voici un exemple :

![utilisation_42sh](https://user-images.githubusercontent.com/71844868/124455829-4a7f1580-dd8a-11eb-818f-eaf168e32dfb.png)

Comme je vous l'ai dis plus tot, TCSH a son lot de nouveauté par rapport a CSH, c'est pourquoi le 42sh doit contenir les nouveaté de TCSH.  Grace a TCSH on peu definir des varaibles d'environement en utilisant les commandes setenv et unsetenv.  Ces deux commandes vont directement modifier l'environnement et peu donc aussi supprimer des variables par defaut de l'environement.  Voici un exemple :

![setenv](https://user-images.githubusercontent.com/71844868/124469176-5377e300-dd9a-11eb-8fd7-49842fdc0f86.png)

Ici je vais set la variable d'environnement coucou et faire apparaitre l'environnement avec la commande env.  Voyez ensuite que la variable coucou existe :

![coucou](https://user-images.githubusercontent.com/71844868/124469304-7904ec80-dd9a-11eb-9269-4e5bff943483.png)

on peu egalement faire le contraire, on vas supprimer la varaible coucou de l'env :

![unsetenv](https://user-images.githubusercontent.com/71844868/124469369-920d9d80-dd9a-11eb-87e9-69acf4fc65f0.png)

J'effectue la commande unsetenv et fais apparaitre l'env par la suite pour verifier que coucou n'existe plus :

![rm_coucou](https://user-images.githubusercontent.com/71844868/124469444-abaee500-dd9a-11eb-9ebe-e9e16eefe323.png)

Ainsi nous pouvons voir que coucou n'existe plus.
