# DEVKIT_FRASM
Cross-Development Kit basé sur Frankenstein Assembleur

Historique : 
FRASM est crée par Mark Zenier, en domaine public et distribué sans garantie, aucune responsabilité ne saurait être liée à son utlisation
HEX2ORIC est crée par Fabrice F, modifié par Didier V. dans le fonctionnement des options.
Le source d'origine est disponible à l'adresse : xxx

Utilisation : 
La traduction de l'assembleur en objet au format tap se fait en 2 étapes.
1. la phase d'assemblage au format hex avec FRASM
2. la création du fichier hex en fichier TAP classique

bin\frasm -o salut.hex salut.asm
bin\hex2oric salut.tap salut.hex -auto

