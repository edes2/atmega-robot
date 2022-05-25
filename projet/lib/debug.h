/* Fichier qui permet de faire des debug prints lorsqu'on make debug */

void transmission(char* x); // "Hack"

#ifdef DEBUG
# define DEBUG_PRINT(x) transmission(x)                         
#else
# define DEBUG_PRINT(x) do{}while(0)
#endif