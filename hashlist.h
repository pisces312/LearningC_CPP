#ifndef HASHLIST_H_INCLUDED
#define HASHLIST_H_INCLUDED
#include<string.h>
/**
一个hash表的简单实现
**/
struct nlist {       /* table entry: */
    struct nlist *next;   /* next entry in chain */
    char *name;           /* defined name */
    char *defn;           /* replacement text */
};
#define HASHSIZE 101
//!大小为HASHSIZE的hash表，元素是结构体nlist指针
static struct nlist *hashtab[HASHSIZE];  /* pointer table */
/*
为一个字符串生成hash值
hash:  form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;
//每个字符都参与到运算中
    for (hashval = 0; *s != '\0'; s++)
        //用一个质数，这里用31
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
/* lookup:  look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)];  np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;     /* found */
    return NULL;           /* not found */
}
struct nlist *lookup(char *);
//char *strdup(char *s){
//    int len=strlen(s);
//    char* t=new char[len];
//    strcpy(t,s);
//    return t;
//}

/*
向查找表中插入
install:  put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    //name是第一次出现，则建立一个新的查找表项

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        //产生一个hash值
        hashval = hash(name);
        //用hash值作为下标
        //!链入链表的头部
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else       /* already there */
        free((void *) np->defn);   /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}


void testTableList() {
    install("green",NULL);
    install("red",NULL);
    install("black",NULL);
    install("yellow",NULL);
    install("blue",NULL);
    install("orenge",NULL);
    install("brown",NULL);
    install("white",NULL);
    install("pink",NULL);
    install("gray",NULL);
    //
    struct nlist *np=lookup("blue");
    printf("%s\n",np->name);
}


#endif // HASHLIST_H_INCLUDED
