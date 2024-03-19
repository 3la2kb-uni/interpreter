#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxword 23
int peak=0;
int base=0;
typedef struct
{
    char data[maxword];
    float value;
    int size;
    struct Node* left;
    struct Node* right;
} Node;
Node* context;
Node** contextArray;
/*
*
*/
typedef struct
{
    char* parent;
    char* left;
    char* right;
    char* found;
} Res;
/*
*
*/
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    while (i < d)
        str[i++] = '0';
    reverse(str, i);
    str[i] = '\0';
    return i;
}
void ftoa(float n, char* res, int afterpoint)
{
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
/*
*
*/
Node* newNode(char *v,float val)
{
    Node* n=malloc(sizeof(Node));
    strcpy(n->data,v);
    n->value = val;
    char res[20];
    if(val<0){ftoa(abs(val),res,4);n->size=strlen(res);}
    else if(val>0){ftoa(val,res,4);n->size=strlen(res);}
    else{n->value=0;n->size=1;}
    n->left=NULL;
    n->right=NULL;
    return n;
}
/*
*
*/
Node* insertNode(Node *root,char* word,float val)
{
    if(root == NULL)
    {
        return newNode(word,val);
    }
    else if(strcmp(root->data,word)<0)
    {
        root->right = insertNode(root->right,word,val);
    }
    else
    {
        root->left = insertNode(root->left,word,val);
    }
    return root;
}
/*
*
*/
Node* findSuccessor(Node* root, char* data)
{
    Node* successor;
    while(root != NULL)
    {
        if(strcmp(root->data, data)<0)
        {
            root = root->right;
        }
        else if(strcmp(root->data, data)>0)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            if(root->right == NULL)
            {
                break;
            }
            else
            {
                successor = root->right;
                root = root->right;
            }
        }
    }
    return successor;
}
/*
*
*/
Node* findPredecessor(Node* root, char* data)
{
    Node* successor;
    while(root != NULL)
    {
        if(strcmp(root->data, data)<0)
        {
            successor = root;
            root = root->right;
        }
        else if(strcmp(root->data, data)>0)
        {
            root = root->left;
        }
        else
        {
            if(root->left == NULL)
            {
                break;
            }
            else
            {
                successor = root->left;
                root = root->left;
            }
        }
    }
    return successor;
}


Node* search(Node* root, char* word)
{
    while(root != NULL)
    {
	    if(strcmp(root->data,word) == 0)
	    {
	        return root;
	    }
	    else if(strcmp(root->data,word)<0)
	    {
	        root = root->right;
	    }
	    else if(strcmp(root->data,word)>0)
	    {
	        root = root->left;
	    }
    }
    return NULL;

}
/*
*
*/
int height(Node* root)
{
    if (root == NULL) {
        return -1;
    }

    int lefth = height(root->left);
    int righth = height(root->right);

    if (lefth > righth) {
        return lefth + 1;
    } else {
        return righth + 1;
    }
}
/*
*
*/
void put(char* var,float val){
    peak++;
    if(context==NULL){context = insertNode(context,var,val);}
    else if(search(context,var)){search(context,var)->value = val;}
    else{insertNode(context,var,val);}
}
/*void put(char* var,float val){
	peak++;
	if(context==NULL){context = insertNode(context,var,val);}
	else{insertNode(context,var,val);}
}/*
*
*/
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s = %f\n", root->data,root->value);
        inorder(root->right);
    }
}/*
*
*/
void BSTtoArray(Node* root){
    if(!base){
    	contextArray = (Node**)malloc(sizeof(Node*)*peak);
    }
    if (root != NULL)
    {
        BSTtoArray(root->left);
	contextArray[base++]=root;
        BSTtoArray(root->right);
    }

}
