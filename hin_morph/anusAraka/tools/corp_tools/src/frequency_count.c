/* Header file inclusion */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

/* Define Constant parameters */
#define MAXWORD 100
#define BUFSIZE 100

/* Procedure Declaration */
int getword();
char *strdup();
struct tnode *talloc();
struct tnode *addtree();
void treeprint();
void ungetch();
int getch();

/* Global Variable Declaration */
char buf[BUFSIZE];
int bufp =0;

/* Main program */
main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while(getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) root = addtree(root, word);
		treeprint(root);
		return 0;
}

/* Procedure addtree */
struct tnode *addtree(p,w)
struct tnode *p ;
char *w;

{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} 
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

/* Procedure treeprint */
void treeprint(p)
struct tnode *p;
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* Procedure strdup */
char *strdup(s)
char *s;
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/* Procedure getword */
int getword(word, lim)
char *word;
int lim;
{
	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

/* Procedure talloc */
 struct tnode *talloc()
 {
 return (struct tnode *) malloc(sizeof(struct tnode));
 }

/* Procedure getch */
int getch()
{
	return(bufp > 0) ? buf[--bufp] : getchar();
}

/* Procedure ungetch */
void ungetch(c)
int c;
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
