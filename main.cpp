#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct node
{
    unsigned int key;
    struct node *left;
    struct node *right;
}node;

void addNode(node **tree, unsigned int key) // ajouter noeud
{
    node *tmpNode = nullptr;
    node *tmpTree = *tree;

    node *elem = new node; // contient la valeur a ajouter

    elem -> key = key;
    elem -> left = NULL;
    elem -> right = NULL;

    if(tmpTree) // si le pointeur ne pointe pas vers NULL
    {
        do
        {
            tmpNode = tmpTree;

            if(key > tmpTree -> key) // si la key est plus grande on va a droite
            {
                tmpTree = tmpTree -> right;
                if(!tmpTree) // quand on trouve plus rien on insère une nouvelle feuille
                {
                    tmpNode -> right = elem;
                }
            }
            else // sinon on va a gauche
            {
                tmpTree = tmpTree -> left;
                if(!tmpTree) // quand on trouve plus rien on insère une nouvelle feuille
                {
                    tmpNode -> left = elem;
                }
            }

        }while(tmpTree);
    }
    else
    {
        *tree = elem;
    }

    //delete elem;
    elem = nullptr;
}

int search_node(node *tree, unsigned int key)
{
    while(tree)
    {
        if(key == tree -> key) return 1;

        if(key > tree -> key)
        {
            tree = tree -> right;
        }
        else
        {
            tree = tree -> left;
        }

    }

    return 0;
}

int main()
{

    node *arbre = nullptr;

    addNode(&arbre, 30);
    addNode(&arbre, 10);
    addNode(&arbre, 20);
    addNode(&arbre, 40);
    addNode(&arbre, 50);

    if(search_node(arbre, 50))
    {
        std::cout<<"L'element rechercher se trouve dans l'arbre"<<std::endl;
    }
    else
    {
        std::cout<<"ya rien a sat"<<std::endl;
    }


    return 0;
}
