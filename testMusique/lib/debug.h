void transmission(char* x);

#ifdef DEBUG 
# define DEBUG_PRINT(x) transmission(x)                         
#else
# define DEBUG_PRINT(x) do{}while(0)
#endif