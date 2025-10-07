#include <ctype.h>
char* replace_1(const char * str, const char * from, const char * to)
{
    if (str==NULL )
        return NULL;

    size_t len;
    char * p;
    if (from == NULL || to == NULL || 
        (len=strlen(str))==0 ||
        (p = strstr(str, from)) == NULL)
        return strdup(str);

    size_t len1 = strlen(from);
    size_t len2 = strlen(to);

    char * s = malloc(strlen(str) - len1 + len2 + 1);
    p = strstr(str, from);

    size_t  before = p-str;
    strncpy(s, str, before);
    s[before] = 0;
    // printf("s=_%s_\n", s);

    strcat(s, to);
    // printf("s=_%s_\n", s);
    strcat(s, p+len1);
    // printf("s=_%s_\n", s);

    return s;
}
