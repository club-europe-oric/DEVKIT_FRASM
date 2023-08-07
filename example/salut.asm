; salut test
SERVICE equ $BB82	 ; ligne service
	 org $9801	 ; le programme sera implanté en $9801
	 ldy #$00	 ; mettre la valeur zéro dans le registre Y
BOUCLE lda MESSAGE,Y	; lire l’octet présent dans la mémoire d’adresse 980F+Y
	 beq FIN	 ; si la valeur lue est zéro, c’est fini on termine en 980E
	 sta SERVICE,Y	; sinon on copie l’octet en BB82+Y (dans ligne service)
	 iny	 ; Y=Y+1 pour indexer l’octet suivant
	 bne BOUCLE	 ; on reboucle en 9814 tant que Y ne repasse pas à zéro
FIN RTS ; fin du programme on retourne au point
MESSAGE string "Salut les gars"
	 db 0
; end
