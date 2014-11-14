#include "Node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_MAX 512

Node* createNode(char* name, char* url, int index)
{
  int length;
  Node* new = (Node*)malloc(sizeof(Node));
  if (new == NULL)
    {
      fprintf(stderr, "cannot allocate Node\n");
      return NULL;
    }
  
  length = strlen(name);
  new->name = (char*)malloc((length + 1) * sizeof(char));
  if (new->name == NULL)
    {
      fprintf(stderr, "cannot allocate Node::name\n");
      free(new);
      return NULL;
    }
  strcpy(new->name, name);

  length = strlen(url);
  new->url = (char*)malloc((length + 1) * sizeof(char));
  if (new->url == NULL)
    {
      fprintf(stderr, "cannot allocate Node::url\n");
      free(new->name);
      free(new);
      return NULL;
    }
  strcpy(new->url, url);
  
  new->index = index;
  
  return new;
}

void freeNode(Node* n)
{
  free(n->name);
  free(n);
}

int getNodeIndex(Node* n)
{
  return n->index;
}

char* getNodeName(Node* n)
{
  return n->name;
}

char* getNodeURL(Node* n)
{
  return n->url;
}

Node** readNodesFromFile(char* fname)
{
  FILE* fp;
  char line[LINE_MAX];
  char url[LINE_MAX];
  char name[LINE_MAX];
  int num;
  int index;
  int count;
  Node** nodes;

  count = 0;
  fp = fopen(fname, "r");

  if (fp == NULL)
    {
      fprintf(stderr, "cannot open %s\n", fname);
      return NULL;
    }

  //skip till number
  do
    {
      if (fgets(line, LINE_MAX, fp) == NULL)
	{
	  fprintf(stderr, "unexpected EOF\n");
	  return NULL;
	}
    }
  while(sscanf(line, "%d", &num) != 1);
  
  
  //一つ多めに取ることで後で長さを取得できるように
  nodes = (Node**)malloc((num + 1) * sizeof(Node*)); 
  if (nodes == NULL)
    {
      fprintf(stderr, "cannot allocate nodes\n");
      return NULL;
    }
  
  while(count < num)
    {
      if(fgets(line, LINE_MAX, fp) == NULL)
	{
	  fprintf(stderr, "unexpected EOF\n");
	  return NULL;
	}
      
      if(sscanf(line, "%d %s \"%[^\"]", &index, url, name) == 3)
	{
	  *(nodes + count) = createNode(name, url, index);
	  count++;
	}
    }
  
  return nodes;
  
}

unsigned int getNodesLength(Node** n)
{
  unsigned int count = 0;
  
  if (n == NULL)
    return 0;
  
  while(*(n++) != NULL)
    ++count;
  return count;
}

