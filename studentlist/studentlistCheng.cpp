/*Saw KEVIN MEN'S CODE FOR HELP ON VECTORS


 */

#include<iostream>
#include<cstring>
#include<vector>
#include <iomanip>
#include <math.h>
#include<string.h>
using namespace std;

struct student
{
  char firstname [99];
  char lastname [99];
  int id;
  float gpa;
};

student* add(vector<student*>studentlist, int number); // when you want to add a student.
    
void print(vector<student*> studentlist); // when you want to print out the student list



  int main()
  {
    cout << "This program creates a student list and allows uesr to add/remove students into/from the student list." << endl;
    cout << "Type \"ADD\" if you want to add a student to the student list." << endl;
    cout << "Type \"DELETE\" if you want to delete one of the student in the student list."<< endl;
    cout << "Type \"PRINT\" if you want to see all of the students' information in the student list."<< endl;
    cout << "Type \"QUIT\" or simply alt+f4 to close the program."<< endl;
    cout << endl;

    vector<student*> studentlist;
    bool program = true;
    char answer[99];
    while (program == true)
      {
	
	
	int numberofstudent = 0;
		for (vector<student*>::iterator it = studentlist.begin(); it != studentlist.end(); ++it)
	      {
		numberofstudent ++;
	      }
	  
	      cout << "You currently have " <<numberofstudent << " students in your studentlist" << endl;

	cout << "Now what would you like to do? My friend."<< endl;
	
	
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
	 
	    studentlist.push_back(add(studentlist, numberofstudent)); // add
	    
	    
	  }
	else if (answer[0] == 'D' &&
	    answer[1] == 'E' &&
	    answer[2] == 'L' &&
	    answer[3] == 'E' &&
	    answer[4] == 'T' &&
	    answer[5] == 'E' )
	  {
	    if (numberofstudent != 0) // if there is a student in studentlist
	      {
	 	cout << "What is the ID of the student that you want to delete?" << endl;
		int id = 0;
		cin >>(id); // read in the id
		cin.get();
		int track = 0; // Keep track of which student it is
		for (vector<student*>::iterator it = studentlist.begin(); it != studentlist.end(); ++it)
	      {
	       
		if ((*it) -> id == id)
		  {
		    
		    studentlist.erase(studentlist.begin() + track); // start from 0 + the index
		    break; // so the code doesn't Kill it self and tell me core dumped
		    }
		else if (it == studentlist.end()-1)
		  {
		    cout << "Couldn't find the student that you want to delete, maybe try printing out the studentlist first!" << endl;
		  }
		track ++;
	      }
	   
		
	      }
	    else
	      {
		cout << "You don't have any student in your studnetlist! Please add some." << endl;
	      }
	  }
	 else if (answer[0] == 'P' &&
	    answer[1] == 'R' &&
	    answer[2] == 'I' &&
	    answer[3] == 'N' &&
	    answer[4] == 'T' )
	  {
	    /* Go through the studentlist (vector) from the beginning to the end
	       Print out their information.

	     */
	    if (numberofstudent != 0)
	      {
	    for (vector<student*>::iterator it = studentlist.begin(); it != studentlist.end(); ++it)
	      {
		cout <<"Name: "<< (*it)-> firstname <<" " <<(*it)-> lastname << "\tID: " <<(*it) -> id <<  "\tGPA: " << (*it)-> gpa <<endl;

	      }
	      }
	    else  // if has student print
	      {
		cout << "You don't have any student in your studentlist! Please add some!" << endl;
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
    

   
student* add(vector<student*> studentlist, int number) // when you want to add a student
{
  /*
    SAW KEVIN MEN'S GITHUB  EXAMPLES OF FOR LOOPS FOR VECTORS & USE OF ->, * & PUSHBACK 




   */
  /*
    when you add a student, first set the return type to student so back there you do 
    studentlist.push_back(add(studentlist)) add(studentlist) gives you a student
    
    I need to pass in the studetnlist so i can check if theres a student in studentlist
    with the same id number which is not allowed/


  */
  char firstname[99];
  char lastname[99];
  int id;
  float gpa;
  /*
    Variables of a student
   */
  student* a = new student;
  // create a new student
  
    cout << "What's the first name of the students that you want to add?" << endl;
 cin.get(firstname,99);
 cin.get();

 int flength = strlen(firstname);
firstname[flength] = '\0';

    cout << "What's the last name of the students that you want to add?" << endl;
 cin.get(lastname,99);
 cin.get();

 int llength = strlen(lastname);
 lastname[llength] = '\0';
 /*
   ask for information, and stop reading in more first name / last name after it's done('\0')
  */
 for(int i=0; i<= flength; i++)
   {
     a->firstname[i] = firstname[i];
   }
 for(int i=0; i<= llength; i++)
   {
     a->lastname[i] = lastname[i];
   }
 /*
   make the student's first name last name the same as what we just read in
  */
     


 cout << "ID?" << endl;

 
 bool rep = true;
 while (rep == true)
   {
     cin >> id;
     cin.get();

	 /*
	   keep doing it until the user types in something that's different than the id existed.
	 
	 */
     if (number == 0) // read in at the beginning so I know if theres any students in the studentlist
       // if there isn't any student there is no point checking for repeating id
	   {
	     
	     break;
	   }
    for (vector<student*>::iterator it = studentlist.begin(); it != studentlist.end(); ++it)
   {
       if  ((*it)-> id == id)
       {
	 // if we find one number that's the same as what user type in there is no point keep going
	 // just get out and tell him to retype
	 rep = true;
	 break;
       }
       else if (it == studentlist.end() -1  ) 
	 {
	   // if we can't find one and it's the end of the studentlist, he is clean, he can get out
	   rep =false;
	 }
    }
 /* read in the id, go through the studentlist, if the id already exists
	    tell the user to retype

	   
	  */
    if (rep == true) // if he needs to retype tell him this
	   {
	     cout << "Some one with the same ID number is already in the studentlist!" << endl;
	 cout << "Please type in another student ID" << endl;
	 
	   }

	 
   }
   a->id = id;

   /*
     if the id is unique, set the student's id to the id we read in
    */
	   
 
   // read in gpa 
 cout << "GPA?" << endl;
 cin >> gpa;
 cin.get();
   a->gpa =gpa;
	
  int digits = (log10(gpa)) + 3 ;
   
   
   std::cout << std::setprecision(digits) << gpa << '\n';
   std::cout << std::fixed;
 

  
   // return the student t
        }


       


