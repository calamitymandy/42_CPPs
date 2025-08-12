# 42_CPPs

## CPP 00
### Ex01:

1. Structure du projet:

Le projet est composé de deux classes principales :

- Contact : représente un contact avec des informations (prénom, nom, surnom, numéro, secret).

- PhoneBook : représente le répertoire contenant un tableau de contacts (max 8).



Le programme doit gérer trois commandes utilisateur :

- ADD : Ajouter un contact au répertoire.

- SEARCH : Afficher la liste des contacts et permettre d’en voir un en détail.

- EXIT : Quitter le programme.



⚠️ Contraintes importantes :

- Pas d’allocation dynamique → Pas de new ou std::vector, on utilise un tableau Contact contacts[8].

- Si un 9ᵉ contact est ajouté, remplacer le plus ancien (on peut utiliser un index circulaire).


2. Définition des Classes

On crée deux classes Contact et PhoneBook :

a) La classe Contact
Elle doit stocker les informations d’un contact et fournir des méthodes pour :

- Récupérer et afficher ses données.

- Vérifier que toutes les données sont remplies.



b) La classe PhoneBook
Elle doit :

- Stocker jusqu’à 8 contacts.

- Gérer l’ajout de nouveaux contacts (remplacement du plus ancien si plein).

- Afficher la liste des contacts formatée.

- Permettre de consulter un contact par son index.



3. Fichiers du Projet
Le projet contiendra au minimum :

- Contact.hpp : Déclaration de la classe Contact.

- Contact.cpp : Implémentation de Contact.

- PhoneBook.hpp : Déclaration de PhoneBook.

- PhoneBook.cpp : Implémentation de PhoneBook.

- main.cpp : Gère les entrées utilisateur et la boucle principale du programme.

- Makefile : Pour compiler.
