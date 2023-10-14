#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
    char name[20];
    struct user *friends;
    struct post *posts;
    struct user *next;

};

struct post{
    char post[100];
    struct post *next;
};

struct user *head = NULL;

//O(n)
void add_user(char name[20]){
    struct user *temp = (struct user*)malloc(sizeof(struct user));
    strcpy(temp->name, name);
    temp->next = NULL;
    temp->friends = NULL;
    temp->posts = NULL;
    if(head == NULL){
        head = temp;
    }   
    else{
        struct user *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

//O(n)
void add_friend(char name1[20], char name2[20]){
    struct user *ptr1 = head;
    struct user *ptr2 = head;
    while(strcmp(ptr1->name, name1) != 0){
        ptr1 = ptr1->next;
    }
    while(strcmp(ptr2->name, name2) != 0){
        ptr2 = ptr2->next;
    }
    struct user *temp1 = (struct user*)malloc(sizeof(struct user));
    struct user *temp2 = (struct user*)malloc(sizeof(struct user));
    strcpy(temp1->name, name1);
    strcpy(temp2->name, name2);
    temp1->next = NULL;
    temp2->next = NULL;
    temp1->friends = NULL;
    temp2->friends = NULL;
    temp1->posts = NULL;
    temp2->posts = NULL;
    if(ptr1->friends == NULL){
        ptr1->friends = temp2;
    }
    else{
        struct user *ptr = ptr1->friends;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp2;
    }
    if(ptr2->friends == NULL){
        ptr2->friends = temp1;
    }
    else{
        struct user *ptr = ptr2->friends;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp1;
    }
}

//O(n + m)
void add_post(char name[20], char post[100]){
    struct user *ptr = head;
    while(strcmp(ptr->name, name) != 0){
        ptr = ptr->next;
    }
    struct post *temp = (struct post*)malloc(sizeof(struct post));
    strcpy(temp->post, post);
    temp->next = NULL;
    if(ptr->posts == NULL){
        ptr->posts = temp;
    }
    else{
        struct post *ptr1 = ptr->posts;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
        }
        ptr1->next = temp;
    }
}

//O(n + m)
void show_posts(char name[20]){
    struct user *ptr = head;
    while(strcmp(ptr->name, name) != 0){
        ptr = ptr->next;
    }
    struct post *ptr1 = ptr->posts;
    while(ptr1 != NULL){
        printf("%s: %s\n", ptr->name, ptr1->post);
        ptr1 = ptr1->next;
    }
}

//O(n + k)
void show_friends(char name[20]){
    struct user *ptr = head;
    while(strcmp(ptr->name, name) != 0){
        ptr = ptr->next;
    }
    struct user *ptr1 = ptr->friends;
    while(ptr1 != NULL){
        printf("%s\n", ptr1->name);
        ptr1 = ptr1->next;
    }
}

//O(n + k + m)
void show_mutuals(char name1[20], char name2[20]){
    struct user *ptr1 = head;
    struct user *ptr2 = head;
    while(strcmp(ptr1->name, name1) != 0){
        ptr1 = ptr1->next;
    }
    while(strcmp(ptr2->name, name2) != 0){
        ptr2 = ptr2->next;
    }
    struct user *ptr = ptr1->friends;
    while(ptr != NULL){
        struct user *ptr3 = ptr2->friends;
        while(ptr3 != NULL){
            if(strcmp(ptr->name, ptr3->name) == 0){
                printf("%s\n", ptr->name);
            }
            ptr3 = ptr3->next;
        }
        ptr = ptr->next;
    }
}

//O(n)
    void remove_friend(char name1[20], char name2[20]){
        struct user *ptr1 = head;
        struct user *ptr2 = head;
        while(strcmp(ptr1->name, name1) != 0){
            ptr1 = ptr1->next;
        }
        while(strcmp(ptr2->name, name2) != 0){
            ptr2 = ptr2->next;
        }
        struct user *ptr = ptr1->friends;
        if(strcmp(ptr->name, name2) == 0){
            ptr1->friends = ptr->next;
            free(ptr);
        }
        else{
            while(strcmp(ptr->next->name, name2) != 0){
                ptr = ptr->next;
            }
            struct user *temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
        ptr = ptr2->friends;
        if(strcmp(ptr->name, name1) == 0){
            ptr2->friends = ptr->next;
            free(ptr);
        }
        else{
            while(strcmp(ptr->next->name, name1) != 0){
                ptr = ptr->next;
            }
            struct user *temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
    }

void main(){
    int choice;
    char name1[20], name2[20], post[100];
    while(1){
        printf("1. Add user\n2. Add friend\n3. Add post\n4. Show posts\n5. Show friends\n6. Show mutual\n7. Remove friend\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the name of the user: ");
                scanf("%s", name1);
                add_user(name1);
                break;
            case 2:
                printf("Enter the names of the user 1: ");
                scanf("%s", name1);
                printf("Enter the names of the user 2: ");
                scanf("%s", name2);
                add_friend(name1, name2);
                break;
            case 3:
                printf("Enter the name of the user: ");
                scanf("%s", name1);
                printf("Enter the post: ");
                scanf("%s", post);
                add_post(name1, post);
                break;
            case 4:
                printf("Enter the name of the user: ");
                scanf("%s", name1);
                show_posts(name1);
                break;
            case 5:
                printf("Enter the name of the user: ");
                scanf("%s", name1);
                show_friends(name1);
                break;
            case 6:
                printf("Enter the names of the user 1: ");
                scanf("%s", name1);
                printf("Enter the names of the user 2: ");
                scanf("%s", name2);
                show_mutuals(name1, name2);
                break;
            case 7:
                printf("Enter the names of the user 1: ");
                scanf("%s", name1);
                printf("Enter the names of the user 2: ");
                scanf("%s", name2);
                remove_friend(name1, name2);
                break;
            case 8:
                exit(0);
        }
    }
}





