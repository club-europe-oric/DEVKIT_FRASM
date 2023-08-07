# DEVKIT_FRASM
Cross-Development Kit basé sur Frankenstein Assembleur

Historique : 
FRASM est crée par Mark Zenier, en domaine public et distribué sans garantie, aucune responsabilité ne saurait être liée à son utlisation
HEX2ORIC a été créé par Fabrice F, modifié par Didier V. dans le fonctionnement des options suite à quelques demandes d'utilisateurs.
Le source d'origine est disponible à l'adresse : https://sourceforge.net/projects/euphorictools/files/Assembler%20tools/
FRASM permet également de produire un listing du code assemblé, avec une table de labels exploitable avec Euphoric pour faciliter le déboguage.

Utilisation : 
La traduction de l'assembleur en objet au format tap se fait en 2 étapes.
1. la phase d'assemblage au format hex avec FRASM
2. la création du fichier hex en fichier TAP classique
~~~
    bin\frasm -o salut.hex salut.asm
    bin\hex2oric salut.tap salut.hex -auto
~~~
