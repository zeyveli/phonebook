# phonebook
This repo contains a **phonebook.c** file for the phonebook and a **phonebook.dat** file that collects the phonebook data. 

The data for the phonebook is listed in lines and in each line contains the first names, last names and the phone numbers of people. When running the code, the 
**Main menu** appears on the console and asks the user to select the optioons: 

**(1)** Add new entry

**(2)** Find an entry by searching the name

**(3)** Print the phonebook

**(4)** Save the phonebook and quit

The **exit code** is **(-1)** and if the user picks any other character from the ones mentioned, nothing happens. 

The libraries **stdio.h**, **stdlib.h**, **string.h** are used making this code. 5 **void** functions are defined after the main function for reading the dat file **readfile()**, adding new entry **add()**, finding an entry **find()**, listing **list()** the phonebook and saving and quitting **save()**.
