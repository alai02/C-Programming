/* Name:  Alex Lai
 * Student number: 0920158
 * Class: CIS*2520 - A4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //use this for strcmp(x,y) for assingnment
typedef struct node { // An AVL tree node
    char* key;
    struct node *left;
    struct node *right;
    int height;
    int count;
} Node; //Struct defintion
void printOptions(); //function declarations
Node* init();
Node* find(Node* list, char* key);
Node* removeNode(Node* list, char* key);
int findAll(Node* n, int userCount);
int height( Node *N);
int max(int a, int b);
Node *newNode(char *key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node* balanceTree(Node* list);
Node* insert(Node* node, char* key);
void menu();

void printOptions(){
   printf("************* Menu ************\n");
   printf("1. Initialization \n");
   printf("2. Find \n");
   printf("3. Insert \n");
   printf("4. Remove \n");
   printf("5. Check height and size \n");
   printf("6. Find All(about a given frequency) \n");
   printf("7. Exit \n");
   printf("avl/> ");
}
Node* init(Node* tree){
    char filePath[30];
    scanf("%s",filePath);
    FILE * fp = fopen(filePath, "r");
    if(fp == NULL){
        printf("Failed to open the file\n");
    } else {
        char *value;
        char line[128];
        while(fgets(line, 128, fp)){
            value = strtok(line, " ");
            tree = insert(tree, value);
        }
        fclose(fp);
    }
    return tree;
}
Node* find(Node* list, char* key) {

    if(list == NULL){
        printf("LIST NULL: no_such_key\n");
        return list;
    }
    if(list->key == NULL){
        printf("KEY IS NULL: no_such_key\n");
        return list;
    } 
    if (strcmp(key, list->key) == 0){
        printf("key: %s, frequency: %d\n", key, list->count);
    } else if(strcmp(list->key,key) > 0){
        return find(list->left, key);
    } else if (strcmp(list->key,key) < 0){
        return find(list->right, key);
    } 
}
Node* removeNode(Node* list, char* key) {
    if (list == NULL) {
        printf("no_such_key\n");
        return NULL;
    } else if(list->key == NULL){
        printf("no_such_key\n");
        return NULL;
    }
    if (strcmp(list->key,key) == 0) {
       if(list->count > 1){
            list->count = list->count -1;
            printf("key: %s, frequency: %d\n", list->key, list->count);
       } else {
            Node* temp; //fix this shitty method 
            temp = newNode(list->key);
            temp->left = list->left;
            temp->right = list->right;
            free(list);
            return temp;
       }
    } else if (strcmp(list->key,key) > 0 ){
         list->left = removeNode(list->left, key);
    } else if(strcmp(list->key,key) < 0 ) {
        list->right = removeNode(list->right, key);
    } 
    list = balanceTree(list);
    return list;
}
int findAll(Node* n, int userCount){

    if(n == NULL){
        return 0;
    }
    if(userCount < 1){
        printf("Please enter a positive integer \n");
        printf("frequency: ");
        scanf("%d", &userCount);
    }
    if(userCount >= n->count){
        printf("key: %s, frequency: %d\n", n->key, n->count);
    }
    if(n->left != NULL){
        findAll(n->left, userCount);
    } else if(n->right != NULL){
        findAll(n->right, userCount);
    } else {
        return 0;
    }
}
int height(Node *N) { // A utility function to get height of the tree
    if (N == NULL){ //add to this function to get the size
        return 0;
    } else {
        return N->height; 
    }
}
int size(Node* list) {  
  if (list == NULL) { 
    return 0;
  } else {    
    return(size(list->left) + 1 + size(list->right));  
    }
}
int max(int a, int b) { // A utility function to get maximum of two integers
    return (a > b)? a : b;//returns whichever is higher
}
Node* newNode(char* key) {
    Node* node = ( Node*) malloc(sizeof( Node));
    node->key  = (char *)malloc((strlen(key)+1)*sizeof(char));
    strcpy(node->key,key);
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  
    node->count = 1;
    return node;
}
Node *rightRotate(Node *y) { // A utility function to right rotate subtree rooted with y
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y; // Perform rotation
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1; // Update heights
    x->height = max(height(x->left), height(x->right))+1;
    return x;// Return new root
}
Node *leftRotate(Node *x) {// A utility function to left rotate subtree rooted with x
    struct node *y = x->right;
    struct node *T2 = y->left; 
    y->left = x; // Perform rotation
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1; ////  Update heights
    y->height = max(height(y->left), height(y->right))+1;
    return y; // Return new root
}
int getBalance(Node *N) {  // Get Balance factor of node N
    if (N == NULL){
        return 0;
    } else {
    return height(N->left) - height(N->right);
    }
}
Node* insert(Node* list, char* key) { 
    Node* node;
    if (list == NULL){
        list = newNode(key);
        printf("key: %s, frequency: %d\n", key, list->count);
        return list;
    }
    node = newNode(key);
    printf("Key atempting to add: %s\n", node->key);
    if (strcmp(list->key,key) == 0) {
        list->count += 1;
        printf("key: %s, frequency: %d\n", list->key, list->count);
    } else if (strcmp(list->key,key) > 0){
        if(list->left != NULL){
            list->left = insert(list->left, key);
        } else {
            list->left = node;
            printf("key: %s, frequency: %d\n", node->key, node->count);
        }
    } else if (strcmp(list->key,key) < 0) {
        if(list->right != NULL){
            list->right = insert(list->right, key);
        } else {
            list->right = node;
            printf("key: %s, frequency: %d\n", node->key, node->count);
        }
    }
    list = balanceTree(list);
    return list; 
}
Node* balanceTree(Node* list){
    list->height = max(height(list->left), height(list->right)) + 1; // Update height of this parent node 
    int balance = 0;
    balance = getBalance(list); // Get the balance factor of this parent node to check whether this node became unbalanced 
    if (balance > 1 ) { // Left Left Case 
        return rightRotate(list);
    }
    if (balance < -1 ) {  // Right Right Case 
        return leftRotate(list);
    }
    if (balance > 1 ) {  // Left Right Case 
        list->left =  leftRotate(list->left);
        return rightRotate(list);
    }
    if (balance < -1 ) { // Right Left Case 
        list->right = rightRotate(list->right);
        return leftRotate(list);
    }
}
int main(int argc, char* argv[]){
    printf("Alex Lai - 0920158\n");
    printf("Welcome to my AVL tree program!\n");
    menu();  
    return 0;
}
void menu(){
    int userInput = 0;
    int userCount = 0;
    int heightOfList = 0;
    int sizeOfList = 0;
    int valForFindAll = 0;
    Node* tree = NULL;
    char* keyToFind = (char *)malloc((10)*sizeof(char));
    char* keyToRemove = (char *)malloc((10)*sizeof(char)); 
    char* keyToInsert = (char *)malloc((10)*sizeof(char));
    while (userInput != 7) {  
        printOptions();
        scanf("%d" , &userInput);
        if (userInput > 7 || userInput < 1) {
            printf("invalid command, please enter one of the 7 commands (1 to 7) : \n");
            printOptions();
            scanf("%d" , &userInput);
        } else {
            switch(userInput){
                case 1: 
                    printf("filename: ");
                    tree = init(tree);
                    break;
                case 2: 
                    printf("find key: ");
                    scanf("%s", keyToFind);
                    tree = find(tree, keyToFind);
                    break;
                case 3:
                    printf("insert key: ");
                    scanf("%s", keyToInsert);
                    tree = insert(tree, keyToInsert);
                    break;
                case 4: 
                    printf("remove key: ");
                    scanf("%s", keyToRemove);
                    tree = removeNode(tree, keyToRemove);
                    break;
                case 5: 
                    heightOfList = height(tree);
                    sizeOfList = size(tree);
                    printf("height: %d, size: %d\n", heightOfList, sizeOfList);
                    break;
                case 6:     
                    printf("frequency: ");
                    scanf("%d", &userCount);
                    valForFindAll = findAll(tree, userCount);
                    break;
                case 7:
                    printf("Exiting program\n");
                    break;
            }
        }
    }  
}