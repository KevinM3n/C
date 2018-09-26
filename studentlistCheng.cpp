/*Saw KEVIN MEN'S CODE FOR HELP ON VECTORS


 */



#include<iostream>
#include<cstring>
#include<vector>
#include<string.h>
using namespace std;

struct student
{
  char name [99];
  int id;
  float gpa;
};

student add(vector<student*> studentlist); // when you want to add a student.
void deletestudent(); // when you want to delete a student
void print(student a); // when you want to print out the student list

  int main()
  {
    cout << "This program creates a student list and allows uesr to add/remove students into/from the student list." << endl;
    cout << "Type \"ADD\" if you want to add a student to the student list." << endl;
    cout << "Type \"DELETE\" if you want to delete one of the student in the student list."<< endl;
    cout << "Type \"PRINT\" if you want to see all of the students' information in the student list."<< endl;
    cout << "Type \"QUIT\" or simply alt+f4 to close the program."<< endl;
    cout << endl;

    vector<student*> studentlist;

    int numberofstudent = 0;
    bool program = true;
    while (program == true)
      {
	
	
	
	cout << "Now what would you like to do? my friend."<< endl;
	char answer [99];
  	cin.get (answer, 99);
	cin.get();
	int length = strlen(answer);
	answer[length] = '\0';// end the char array from reading in more.
	//Ex. answer = ADD, answer length = 3, answer[3] would be empty and just end right there.
	//cout << answer << length << endl; // just testing
	 // if the user's response starts with ADD, go add a student, same thing for deleteing and printing.
	if (answer[0] == 'A' &&
	    answer[1] == 'D' &&
	    answer[2] == 'D' )
	  {
	 
	    add(studentlist);
	    numberofstudent ++;
	    cout << "You currently have " <<numberofstudent << " students in your studentlist" << endl;

	  }
	else if (answer[0] == 'D' &&
	    answer[1] == 'E' &&
	    answer[2] == 'L' &&
	    answer[3] == 'E' &&
	    answer[4] == 'T' &&
	    answer[5] == 'E' )
	  {
	    deletestudent();
	  }
	 else if (answer[0] == 'P' &&
	    answer[1] == 'R' &&
	    answer[2] == 'I' &&
	    answer[3] == 'N' &&
	    answer[4] == 'T' )
	  {
	    
	    for (int i = 0; i < numberofstudent; i++)
	      {
		cout << *studentlist.at(i)->name << endl;
	   
	      }
	  }
	else if (answer[0] == 'Q' &&
	    answer[1] == 'U' &&
	    answer[2] == 'I' &&
	    answer[3] == 'T' )
	  {
	    cout << "Glad to help you, have a good day!" << endl;
	    return 0;
	  }
	else  // if it's none of them, tell user to retype.
	  {
	    cout << "I don't really understand, maybe try capitalize everything" << endl;

	  }
      
       }
  }
    
    void print(student a) // when you want to print out the student list
{
  cout << "Name: " ;
  for (int i=0; i<= strlen(a.name); i++)
    {
      cout << a.name[i];
    }
  cout << " ID: " << a.id;
  cout << " GPA: " << a.gpa << endl;
}
    void deletestudent() // when you want to delete a student
{
  cout << "Which student do you want to delete?" << endl;
  cout << "Either tell me the student's name or ID number." << endl;
}

student add(vector<student*> studentlist) // when you want to add a student.
{
  char name[99];
  int id;
  float gpa;

  student* a = new student;
  
    cout << "What's the name of the students that you want to add?" << endl;
 cin.get(name,99);

 int length = strlen(name);
 name[length] = '\0';

 student newstudent;
 
 for(int i=0; i<= length; i++)
   {
     a->name[i] = name[i];
   }
     


 cout << "ID?" << endl;
 cin >> id;
 cin.get();
   a->id = id;


 cout << "GPA?" << endl;
 cin >> gpa;
 cin.get();
   a->gpa =gpa;

   studentlist.push_back(a);

 
        }


       


