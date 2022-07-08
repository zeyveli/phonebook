#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct teldefter
{
  char Ad[20];
  char Soyad[20];
  char Numara[20];
};

struct teldefter phonebook[100];

int counter = 0;

void add();
void list();
void find();
void save();
void readfile();

int main()
{
  int selection = 0;

  // phonebook.dat file is read
  readfile();

  // while loop for menu, exits with -1
  while (selection != -1)
  {

    printf("Main menu:\n");
    printf("   (1) Add new entry\n");
    printf("   (2) Find an entry by name\n");
    printf("   (3) Print the phone book\n");
    printf("   (4) Save the phone book and quit\n");
    printf("Enter your selection: ");

    scanf("%d", &selection);
    switch(selection)
    {
      case 1:
        add();
        printf("New line added");
        break;
      case 2:
        find();
        break;
      case 3:
        list();
        break;
      case 4:
        save();
        printf("The phonebook has been saved.");
        selection = -1;
        break;
    }
  }
  return 0;
}

void add()
{
	system("clear");
  counter++;
  printf("Adding new entry:\n");
	printf("\nFirst Name: ");
  scanf("%s", phonebook[counter-1].Ad);
  printf("\nLast Name: ");
  scanf("%s", phonebook[counter-1].Soyad);
  printf("\nPhone Number: ");
  scanf("%s", phonebook[counter-1].Numara);
  getchar( );
  system("clear");
}

void find()
{
  system("clear");
  char aranan[3];
  int arananlen;
  int bulundu;
	system("clear");
  printf("Searching in the phonebook...\n");
	printf("\nEnter the first letters of the name (max. 3 characters): ");
  scanf("%s", aranan);
  arananlen = strlen(aranan);
  system("clear");
  printf("Searching in the phonebook...\n");
  printf("\nKeyword is: %s\t\n\n", aranan);

  printf("List No\t\tFirst Name\t\tLast Name\t\tPhone Number\n");
  printf("----------\t--------------\t\t--------------\t\t--------------\n");

  for (int i = 0; i < counter; i++)
  {
    bulundu = 1;
    for (int j = 0; j < arananlen; j++)
    {

      if (aranan[j]!=phonebook[i].Ad[j])
      {
        bulundu = 0;
      }
    }
    if (bulundu)
    {
      printf("%d\t\t", i+1);
      printf("%-10s\t\t%-10s\t\t", phonebook[i].Ad, phonebook[i].Soyad);
      printf("%-10s\n", phonebook[i].Numara);
    }
  }
  getchar( );
  getchar( );
  system("clear");
}

void list()
{
    
    // The phonebook is listed and alligned
  system("clear");
	int x;
  printf("Recorded entries:\n\n");
  printf("List No\t\tFirst Name\t\tLast Name\t\tPhone Number\n");
  printf("----------\t--------------\t\t--------------\t\t--------------\n");
	for( x = 0; x < counter; x++)
    {
      printf("%d\t\t", x+1);
      printf("%-10s\t\t%-10s\t\t", phonebook[x].Ad, phonebook[x].Soyad);
      printf("%s\n", phonebook[x].Numara);
    }

  printf("\nPress Enter to return main menu.");

  getchar( );
  getchar( );
  
  system("clear");

}

void readfile()
{

  // The file is opened to read
  FILE *fp1;
  fp1= fopen ("phonebook.dat", "r");

  if (fp1 == NULL) {
    printf("Cannot open file.\n");
  }

  // The number of lines defined counting (\n)
    char ch;
    do
      {
        ch = fgetc(fp1);
        if (ch == '\n') counter++;
      } 
    while (ch != EOF);
    counter++;

  // The file is read again 
    rewind(fp1);

    int i;
    for (i = 0; i < counter; i++) {
      fscanf(fp1, "%s %s %s\n", phonebook[i].Ad, phonebook[i].Soyad, phonebook[i].Numara);
    }

    fclose(fp1);

}

void save()
{
  FILE *fp1;
  fp1= fopen ("phonebook.dat", "w");

  for (int i = 0; i < counter-1; i++) 
  {
    fprintf(fp1, "%s %s %s\n", phonebook[i].Ad, phonebook[i].Soyad, phonebook[i].Numara);
  }
  
  // the last line is added to the file seperately
  fprintf(fp1, "%s %s %s", phonebook[counter-1].Ad, phonebook[counter-1].Soyad, phonebook[counter-1].Numara);

  fclose(fp1);

}