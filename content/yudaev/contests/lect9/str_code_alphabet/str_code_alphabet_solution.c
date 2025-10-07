char * code (char * dst, char * src, char * alphabetA, char * alphabetB) {
	int i, j, n;
	char * p;
	n = strlen(src);
	for (i=0; i<n; i++) {
		p = strchr(alphabetA, src[i]);
		if (p==NULL)
			dst[i] = src[i];
		else {
			j = p - alphabetA;
			dst[i] = alphabetB[j];
		}
	}
	dst[i]='\0';
	return dst;
}
