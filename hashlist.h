#ifndef HASHLIST_H_INCLUDED
#define HASHLIST_H_INCLUDED
#include<string.h>
/**
һ��hash��ļ�ʵ��
**/
struct nlist {       /* table entry: */
    struct nlist *next;   /* next entry in chain */
    char *name;           /* defined name */
    char *defn;           /* replacement text */
};
#define HASHSIZE 101
//!��СΪHASHSIZE��hash��Ԫ���ǽṹ��nlistָ��
static struct nlist *hashtab[HASHSIZE];  /* pointer table */
/*
Ϊһ���ַ�������hashֵ
hash:  form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;
//ÿ���ַ������뵽������
    for (hashval = 0; *s != '\0'; s++)
        //��һ��������������31
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
����ұ��в���
install:  put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    //name�ǵ�һ�γ��֣�����һ���µĲ��ұ���

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        //����һ��hashֵ
        hashval = hash(name);
        //��hashֵ��Ϊ�±�
        //!���������ͷ��
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
