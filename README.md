# DEVKIT_FRASM
Cross-Development Kit basé sur Frankenstein Assembleur FRASM

## Historique : 
FRASM est crée par Mark Zenier, en domaine public et distribué sans garantie, aucune responsabilité ne saurait être liée à son utlisation
HEX2ORIC a été créé par Fabrice F, modifié par Didier V. dans le fonctionnement des options suite à quelques demandes d'utilisateurs.
Le source d'origine est disponible à l'adresse : https://sourceforge.net/projects/euphorictools/files/Assembler%20tools/
FRASM permet également de produire un listing du code assemblé, avec une table de labels exploitable avec Euphoric pour faciliter le déboguage.

## Utilisation : 
La traduction de l'assembleur en objet au format tap se fait en 2 étapes.
1. la phase d'assemblage au format hex avec FRASM v2.0
2. la création du fichier hex en fichier TAP classique avec Hex2Oric v2023.005

Ci-dessous la syntaxe pour assembler le fichier situé dans le répertoire example pour obtenir un fichier tap autoexec.  
~~~
    bin\frasm -o salut.hex salut.asm  
    bin\hex2oric salut.tap salut.hex -auto  
~~~
et sans lancement automatique :
~~~
    bin\frasm -o salut.hex salut.asm  
    bin\hex2oric salut.tap salut.hex  
~~~

## Notice Frankenstein Cross Assemblers Users Manual
[FRasm User Manual](https://github.com/club-europe-oric/DEVKIT_FRASM/blob/main/frasm/Frankenstein%20Cross%20Assemblers%20Users%20Manual.pdf)

## Instructions et Annexes pour FRASM
[FRasm instructions](https://github.com/club-europe-oric/DEVKIT_FRASM/blob/main/frasm/Appendix%20for%20as6502%20Frankenstein%20Assembler.pdf)