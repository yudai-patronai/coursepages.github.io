#include <stdio.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
  FILE *in, *tt;
  int i,j,n,r;
  char s[200][200];
  int a[200],b[200];

  if (argc <= 2) {
    fprintf(stderr, "Too few arguments\n");
    return 6;
  }
  if (!(in = fopen(argv[1], "r"))) {
    fprintf(stderr, "Cannot open input file '%s'\n", argv[1]);
    return 6;
  }
  fscanf(in,"%d",&n);
  for(i=0;i<n;i++)fscanf(in, "%s", &s[i][0]);
  fclose(in);
  
  for(i=0;i<n;i++)for(j=0;j<i;j++)
  s[j][i] = (s[i][j]=='+') ? '-' : '+';
    
  if (!(tt = fopen(argv[2], "r"))) {
    fprintf(stderr, "Output file '%s' does not exist\n", argv[2]);
    return 4;
  }
  
  for(i=0;i<n;i++)a[i]=0;
  for(i=0;i<n;i++)
    if(fscanf(tt, "%d", &r) != 1){
    	fprintf(stderr, "Cannot read the answer\n");
    	fclose(tt);
    	return 4;
    } else if(r<1 || r>n) {
    	fprintf(stderr, "Wrong answer r<1 || r>n \n");
    	fclose(tt);
    	return 5;
    } else {a[r-1]=1;b[i]=r-1;}
  
  fscanf(tt, " ");
  if (getc(tt) != EOF) {
    fprintf(stderr, "Excess data\n");
    return 4;
  }
  
  fclose(tt);
  
  for(i=0;i<n;i++)if(a[i]==0){
  		fprintf(stderr, "Wrong answer a[i]=0 \n");
  		return 5;
  }
  for(i=0;i<n-1;i++)
  	if((b[i]<b[i+1] && s[b[i+1]][b[i]]=='+') || (b[i]>b[i+1] && s[b[i]][b[i+1]]=='-')){
  		fprintf(stderr, "Wrong answer + vs -. i=%d b[i]=%d b[i+1]=%d s[b[i][i+1]]=%c s[b[i+1][i]]=%c \n",i,b[i],b[i+1],s[b[i]][b[i+1]],s[b[i+1]][b[i]]);
  		return 5;
  	}
  
  fprintf(stderr, "OK\n");
  return 0;
}

/**
 * Local variables:
 *  compile-command: "gcc tbambig.c -o tbambig"
 * End:
 */
