//
// Version 2023.005 de Hex2Oric revue par Didier / CEO
// Principales modifications : 
// 	- suppression de l'option -o inutile
//  - fichier tap par défaut en non auto
// 	- ajout d'une option -auto pour définir que le .tap est enregistré en auto
//

#include <stdio.h>

char buffer[65536];
char header[]={ 0x16,0x16,0x16,0x24, 0,0,0x80,0x00,0,0,0,0,0, 0 };
char ligne[80];

hex2dec(char x) 
{
	return x>'9' ? x-'a'+10 : x-'0';
}

int main(int argc, char *argv[]) 
{
	unsigned min=0xFFFF,max=0,adr,size;
	int ptr,val;
	int i;
	char *infile, *oricfile, *outfile, *option_auto;
	FILE *in, *fd, *out;

	printf("Version v2023.005 de Hex2Oric\n");
	
	if (argc<2)
	{ 
		printf("Syntaxe : hex2oric <file_sortie> <file_entree> \n \n");
		exit();
	}
	if (argc>2) 
	{
		infile=argv[2];
		outfile=argv[1];
	} 	else 	{
		infile=argv[1];
		outfile="ceo.tap";
	}
	if (argc==4)
	{
		option_auto=argv[3];
		if (strcmp(option_auto,"-auto")==0)
		{
			header[7]=0xc7;
			printf("option auto\n");
		}
	}

	printf("Conversion du fichier : %s \n",infile);
	in=fopen(infile,"rb");
	if (in==NULL) {
		printf("Can't open %s file\n",infile);
		exit(1);
	}
	fd=fopen(outfile,"wb");
	if (fd==NULL) {
		printf("Can't open %s file for writing\n",outfile);
		exit(1);
	}
	
	for(;;) {
		if (fscanf(in,"%s\n",ligne)==-1) break;
		if (ligne[0]!=':') continue;
		size=(hex2dec(ligne[1])<<4)+hex2dec(ligne[2]);
		adr=(hex2dec(ligne[5])<<4)+hex2dec(ligne[6]);
		adr+=(hex2dec(ligne[3])<<12)+(hex2dec(ligne[4])<<8);
		if (size==0) break;
		if (adr<min) min=adr;
		ptr=9;
		while(size--) {
			if (adr>max) max=adr;
			val=(hex2dec(ligne[ptr])<<4)+hex2dec(ligne[ptr+1]);
			buffer[adr++]=val;
			ptr+=2;
		}		
	}
	fclose(in);
	header[10]=min/256; header[11]=min%256;
	header[8]=max/256; header[9]=max%256;
	fwrite(header,14,1,fd);
	fwrite(buffer+min,max-min+1,1,fd);
	fclose(fd);
}
