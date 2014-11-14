#ifndef __NODE_H
#define __NODE_H

typedef struct _Node
{
  char* name;
  char* url;
  int index;
} Node;

Node* createNode(char* name, char* url, int index);
void freeNode(Node*);
int getNodeIndex(Node*);
char* getNodeName(Node*);
char* getNodeURL(Node*);

//util
Node** readNodesFromFile(char*);
unsigned int getNodesLength(Node**);

#endif //__NODE_H
