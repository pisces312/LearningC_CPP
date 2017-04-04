#ifndef TESTRANDOM_H_INCLUDED
#define TESTRANDOM_H_INCLUDED
static unsigned long int nextInt=1;

/* rand:  return pseudo-random integer on 0..32767 */
int rand(void) {
    nextInt = nextInt * 1103515245 + 12345;
    return (unsigned int)(nextInt/65536) % 32768;
}

/* srand:  set seed for rand() */
void srand(unsigned int seed) {
    nextInt = seed;
}
void testRandom(){
    srand(234);
    printf("%d\n",rand());
//    printf("%d\n",srand(234));
}



#endif // TESTRANDOM_H_INCLUDED
