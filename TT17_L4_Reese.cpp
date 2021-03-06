
// Author: Lee Reese;  Course: COSC 1337 Spring 2018 TT17;  Instructor: Thayer
// Lab: 4  Purpose: Read speed of sounds in materials from a file and allow user to calculate the time for sound to travel a given distance in different materials

#include  <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
  //Read file into a vector file_contents
  string filename = "TT17_L4_Reese_In.txt";
  ifstream my_file{filename};
  vector<string> file_contents;
  if (my_file) {
    string item = "notAnInt";
    while (my_file >> item) {
      file_contents.push_back(item);
    }
  }
  my_file.close();
  
  //Menu to show user and map to process user input
  string menu = "Select a material: ";
  map<char, int> materials;

  //Populate menu and materials
  for (int i = 0; i < file_contents.size(); i += 2){
    //Skip table headings
    if (i > 1) {
      //Update map
      char key = tolower(file_contents[i][0]);
      int value = atoi(file_contents[i+1].c_str());
      materials[key] = value;
      
      //Update menu
      string tmp = file_contents[i];
      tmp[0] = tolower(tmp[0]);
      tmp.insert(1, ")");
      menu = menu + tmp + ", ";
    }
  }

  //Add the quit option to the menu
  menu += "or q)uit: ";

  bool done = false;
  while (!done) {
    //Prompt for material
    cout << menu;
    char option;
    cin >> option;
    option = tolower(option);

    //Material input validation
    while (materials[option] == 0 && option != 'q') {
      cout <<"Invalid material option.\n";
      cout << menu;
      cin >> option;
      option = tolower(option);
    }

    //Check for quit
    if (option == 'q') {
      cout << "Goodbye.";
      done = true;
    }
    
    else {
      //Get displacement
      cout << "How thick is the material (in feet): ";
      double displacement = 0;  
      cin >> displacement;
      
      //Displacement input validation
      while (displacement < 0) {
        cout <<"Thickness must not be negative.\n";
        cout << "How thick is the material (in feet): ";
        cin >> displacement;
      }

      //Output time for sound to pass through material
      double time_for = displacement / materials[option];
      cout << "The sound will travel " << displacement << " feet in ";
      printf("%0.4f seconds\n", time_for);
    }

    //Seperate loops
    cout << endl;
  }
  return 0;
}
/*
Program Output:
Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: a
How thick is the material (in feet): 1100
The sound will travel 1100 feet in 1.0000 seconds

Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: w
How thick is the material (in feet): 56
The sound will travel 56 feet in 0.0114 seconds

Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: s
How thick is the material (in feet): 560000     
The sound will travel 560000 feet in 34.1463 seconds

Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: a
How thick is the material (in feet): 560000
The sound will travel 560000 feet in 509.0909 seconds

Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: i
How thick is the material (in feet): -1
Thickness must not be negative.
How thick is the material (in feet): 1
The sound will travel 1 feet in 0.0001 seconds

Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: d
Invalid material option.
Select a material: a)ir, w)ater, s)teel, c)opper, n)ylon, i)ron, or q)uit: q
Goodbye. 
*/
