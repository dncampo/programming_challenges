#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

int main () {
  unsigned n_cases;
  
  char* s1, *s2;

  unsigned m1['z' - 'a'], m2['z' - 'a'], i, ii;
  
  s1 = (char*)malloc(21*(sizeof(char)));
  s2 = (char*)malloc(21*(sizeof(char)));

  scanf ("%u", &n_cases);
  for (ii=0; ii<n_cases; ii++) {
    
    for (i =0; i<('z'-'a'); i++) {
      m1[i] = m2[i] = 0;
    }

    scanf ("%s %s", s1, s2);

    for (i=0; i < strlen(s1); i++) {
      m1[s1[i] - 'a']++;
    }

    for (i=0; i < strlen(s2); i++) {
      char tmp = s2[i];
      m2[(unsigned)(tmp - 'a')]++;
    }

    i=0;
    for (; i < ('z'-'a'); i++) {
      if (m1[i] != m2[i]) break;
    }
    if (i==('z'-'a')) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
