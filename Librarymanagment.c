/*
WACP to create a library Management System include menus like
1. Add
2. Display
3. Find
4. Delete
5. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 100

// Structure to represent a book
typedef struct{
		char title[100];
		char author[100];
		int year;
			
} Book;
// Function Prototype
void addBook(Book books[], int *numBooks);
void displayBooks(Book books[], int numBooks);
void deleteBook(Book bokks[], int *numBooks);
void findBook(Book books[], int *numBooks);

//void displayBook()
int main(){
	Book books[MAX_BOOKS];
	int numBooks = 0;
	int choice;
	
	printf("Welcome to the Library Managment System!\n");
	
	do {
		printf("\nMenu:\n");
		printf("1. Add a book\n");
		printf("2. Display all books\n");
		printf("3. Find a book\n");
		printf("4. Delete a book\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				addBook(books, &numBooks);
				break;
			case 2:
				displayBooks(books, numBooks);
				break;
			case 3:
				findBook(books, numBooks);
				break;
			case 4:
				deleteBook(books, &numBooks);
				break;
			case 5:
				printf("Exiting... Goodbye!\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}while (choice != 5);
return 0;	
} 
void addBook(Book books[], int *numBooks){
	if (*numBooks >= MAX_BOOKS){
		printf("Library is full. Can't add more books.\n");
		return;
	}
	printf("Enter the title of the book: ");
	scanf(" %[^\n]s", books[*numBooks].title);
	
	printf("Enter the author of the book: ");
	scanf(" %[^\n]s", books[*numBooks].author);
	
	printf("Enter the pblication year of the book: ");
	scanf("%d", &books[*numBooks].year);
	
	(*numBooks)++;
	printf("Book added sccessfully.\n");	
}

void displayBooks(Book books[], int numBooks){
	if (numBooks == 0){
		printf("No any books in the library.\n");
		return;
	}
	for(int i = 0; i<numBooks; i++){
		printf("Title: %s \nAuthor: %s \nYear of Publication: %d",books[i].title, books[i].author, books[i].year );
	}
}

void deleteBook(Book books[], int *numBooks){
	if (*numBooks == 0){
		printf("No any books in the library: \n");
		return;
	}
	
	char titleToDelete[100];
	printf("Enter the title of the book to delete: ");
	scanf(" %[^\n]s",titleToDelete);
	
	int foundIndex = -1;
	for (int i = 0; i < *numBooks; i++){
		if (strcmp(books[i].title,titleToDelete) == 0){
			foundIndex = 1;
			break;
		}
	}
	
	if (foundIndex == -1){
		printf("Book not found in the library.\n");
	}else {
	//Shift remaining elements to fill the gap
		for (int i = foundIndex; i < *numBooks - 1; i++){
			books[i] = books[i + 1];
			
		}
		(*numBooks)--;
		printf("Book delted successfully.\n");
	}
}

void findBook(Book books[], int *numBooks){
	if (numBooks == 0){
		printf("No books available in the library.\n");
		return;
 	}	
	char titleToFind[100];
	printf("Enter the title of the book to find: ");
	scanf(" %[^\n]s", titleToFind);
	
	int found = 0;
	for(int i = 0; i<numBooks; i++){
		if (strcmp(books[i].title, titleToFind) == 0){
			printf("Title: %s\nAuthor: %s\nYear: %d\n",books[i].title, books[i].author, books[i].year);
			found = 1;
			break;
		}
	}	
	if (!found){
		printf("Book not found in the library.\n");
	}
}

	
