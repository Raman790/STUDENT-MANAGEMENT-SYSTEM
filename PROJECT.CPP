#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student{
    string name1,name2,admin_num,class_standard,stream_sub,address,father,mother,phone,grade;
    int sub1_mark,sub2_mark,sub3_mark,sub4_mark,sub5_mark;
    double percentage;
    void calculate();
    public:
    void menu();
    void insert_stud();
    void display();
    void edit();
    void search_stud();
    void remove_student();
    void grade_list();
};

// void student::grade_list(){
//     cout<<"\t\n*************** GRADE TABLE ***************\n";
//     cout<<"\t\n ___________________________\n";
//     cout<<"\t\n|    GRADE | PERCENTAGE     |\n";
//     cout<<"\t\n|---------------------------|  \n";
//     cout<<"\t\n|     A+   |     % >=90     |\n";
//     cout<<"\t\n|     A    |   80 <= % < 90 |\n";
//     cout<<"\t\n|     B+   |   70 <= % < 80 |\n";
//     cout<<"\t\n|     B    |   60 <= % < 70 |\n";
//     cout<<"\t\n|     C+   |   50 <= % < 60 |\n";
//     cout<<"\t\n|     C    |   40 <= % < 50 |\n";
//     cout<<"\t\n|     D    |   33 <= % < 40 |\n";
//     cout<<"\t\n|___________________________|\n";
// }

void student::grade_list(){
    cout<<"\t\n*************** GRADE TABLE ***************\n";
    cout<<"\t\n _____________________________ \n";
    cout<<"\t\n|    Subject  |    Marks      |\n";
    cout<<"\t\n|-----------------------------|\n";
    cout<<"\t\n|     evs     |"<<"  "<<sub1_mark<<"           |\n";
    cout<<"\t\n|     maths   |"<<"  "<<sub2_mark<<"           |\n";
    cout<<"\t\n|     sst     |"<<"  "<<sub3_mark<<"           |\n";
    cout<<"\t\n|     english |"<<"  "<<sub4_mark<<"           |\n";
    cout<<"\t\n|     hindi   |"<<"  "<<sub5_mark<<"           |\n";
    cout<<"\t\n|_____________________________|\n";
}

void student::calculate(){
    percentage=(sub1_mark+sub2_mark+sub3_mark+sub4_mark+sub5_mark)/5;
    if(percentage>=90)
		grade="A+";
	else if(percentage>=80)
		grade="A";
	else if(percentage>=75)
		grade="A-";
	else if(percentage>=70)
		grade="B+";
	else if(percentage>=65)
		grade="B";
	else if(percentage>=60)
		grade="B-";
	else if(percentage>=55)
		grade="C+";
	else if(percentage>=50)
		grade="C";
    else if(percentage>=33){
        grade="D";
    }
	else{
		grade="F";
    }
}

void student::menu(){
    //menu
    menu:
    int choice;
    char x;
    //system("cls");

    cout<<"\n\t****************** WELCOME TO STUDENT MANAGEMENT SYSTEM ******************\n";
    cout<<"\n\t                                  CREATED BY - RAMAN AHLAWAT (2K20/SE/105)\n";
    cout<<"\n\t                                             - SHIV RAJ (2K20/SE/127)\n";
    cout<<"\n\n\t\t\t\t1.CREATE A NEW RECORD";
    cout<<"\n\n\t\t\t\t2.DISPLAY ALL STUDENT RECORD";
    cout<<"\n\n\t\t\t\t3.EDIT STUDENT ROCORD";
    cout<<"\n\n\t\t\t\t4.SEARCH STUDENT ROCORD";
    cout<<"\n\n\t\t\t\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t\t\t\t6.EXIT";
    cout<<"\n\n\t***************************** XYZ SCHOOL *****************************";
    cout<<"\n\n\tENTER YOUR CHOICE : ";
    cin>>choice;

    switch(choice){
        case 1:do{
            insert_stud();
            cout<<"\n\t\t\t Add another student (y/n)";
            cin>>x;       
        }while(x == 'y' || x == 'Y');
        break;
        case 2:display();
            break;
        case 3:edit();
        break;
        case 4:search_stud();
            break;
        case 5:remove_student();
        break;
        case 6:exit(0);
        default:
        cout<<"enter a valid choice !\n";
    }
    goto menu;
}

void student::insert_stud(){//insert student details
    system("cls");
    fstream file;
    cout<<"\n***************INSERT STUDENT DETAILS***************\n";
    cout<<"\t\t\tENTER STUDENT'S ADMISSION NUMBER : ";
    cin>>admin_num;
    cout<<"\t\t\tENTER STUDENT'S FIRST NAME : ";
    cin.ignore();
    getline(cin,name1);
    cout<<"\t\t\tENTER STUDENT'S LAST NAME : ";
    getline(cin,name2);
    cout<<"\t\t\tENTER STANDARD : ";
    cin>>class_standard;
    cout<<"\t\t\tENTER ADDRESS : ";
    cin.ignore();
    getline(cin,address); 
    cout<<"\t\t\tENTER FATHER'S NAME : ";
    getline(cin,father);
    cout<<"\t\t\tENTER MOTHER'S NAME : ";
    cin>>mother;
    cout<<"\t\t\tENTER CONTACT NUMBER : ";
    cin>>phone;
            cout<<"\nEnter the marks in evs(out of 100) : ";
            cin>>sub1_mark;
            cout<<"\nEnter the marks social science in (out of 100) : ";
            cin>>sub2_mark;
            cout<<"\nEnter the marks in maths(out of 100) : ";
            cin>>sub3_mark;
            cout<<"\nEnter the marks in english(out of 100) : ";
            cin>>sub4_mark;
            cout<<"\nEnter the marks in hindi(out of 100) : ";
            cin>>sub5_mark;
    calculate();
    file.open("student.txt",ios::app|ios::out);
    file<<admin_num<<" "<<name1<<" "<<name2<<" "<<class_standard<<" "<<address<<" "<<father<<" "<<mother<<" "<<phone<<" "<<sub1_mark<<" "<<sub2_mark<<" "<<sub3_mark<<" "<<sub4_mark<<" "<<sub5_mark<<" "<<percentage<<" "<<grade<<"\n";
    file.close();
}

void student::display(){
    system("cls");
    fstream file;
    int count=1;
    cout<<"\n         ******************** STUDENT DETAILS********************\n";
    file.open("student.txt",ios::in);
    if(!file){
        cout<<"no data created\n";
        file.close();
    }
    else{
        file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;
        while(!file.eof()){

            cout<<"\n\t\nSTUDENT NUMBER : "<<count++<<endl;
            cout<<"\t\t\tADMISSION NUMBER : "<<admin_num<<endl;
            cout<<"\t\t\tSTUDENT FIRST NAME : "<<name1<<endl;
            cout<<"\t\t\tSTUDENT LAST NAME : "<<name2<<endl;
            cout<<"\t\t\tSTANDARD : "<<class_standard<<endl;
            
            cout<<"\t\t\tADDRESS : "<<address<<endl;
            cout<<"\t\t\tFATHER'S NAME : "<<father<<endl;
            cout<<"\t\t\tMOTHER'S NAME : "<<mother<<endl;
            cout<<"\t\t\tCONTACT NUMBER : "<<phone<<endl;

            cout<<"\t\t\n                     MARKS OF "<<name1<<" "<<name2<<" IN EXAMS                   \n\n";
                cout<<"\t\t\tMARKS IN EVS : "<<sub1_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN SOCIAL STUDIES : "<<sub2_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN MATHEMATICS: "<<sub3_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN ENGLISH : "<<sub4_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN HINDI : "<<sub5_mark<<"/100\n";
                cout<<name1<<"'S PERCENTAGE IS : "<<percentage<<endl;
                cout<<name1<<" GRADE IS : "<<grade<<endl;
                cout<<"\n------------------------------------------\n";
                grade_list();
                cout<<"\t\n==================================================================================\n";
            file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;
            //>> operation is used for extracting output
            //<<is used for inserting formatted output
            //ios::in open a file for reading 
        }
        if(count==0){
            cout<<"\n\t\t NO DATA OR PROBLEM IN OPENING DATA\n";
        }
    }
    file.close();
}

//edit student details
void student::edit(){
    system("cls");
    fstream file,newfile;
    string adno;//admission number
    int count=0;
    cout<<"\n*************EDIT STUDENT DETAILS************\n";
    file.open("student.txt",ios::in);//for reading file
    if(!file){
        cout<<"no data present/entered\n";
    }
    else{
        cout<<"Enter the roll number of the student whose details you want to edit : ";
        cin>>adno;
        newfile.open("newstudent.txt",ios::app|ios::out);//creating a new txt file to save the new information
        file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;
        while(!file.eof()){
            if(adno!=admin_num){
                newfile<<admin_num<<" "<<name1<<" "<<name2<<" "<<class_standard<<" "<<address<<" "<<father<<" "<<mother<<" "<<phone<<" "<<sub1_mark<<" "<<sub2_mark<<" "<<sub3_mark<<" "<<sub4_mark<<" "<<sub5_mark<<" "<<percentage<<" "<<grade<<"\n";
            }
            else{
                cout<<"\t\t\tENTER STUDENT'S ADMISSION NUMBER : ";
                cin>>admin_num;
                cout<<"\t\t\tENTER STUDENT's FIRST NAME : ";
                cin>>name1;
                cout<<"\t\t\tENTER STUDENT's LAST NAME : ";
                cin>>name2;
                cout<<"\t\t\tENTER STANDARD : ";
                cin>>class_standard;
                cout<<"\t\t\tENTER ADDRESS : ";
                cin>>address;
                cout<<"\t\t\tENTER FATHER'S NAME : ";
                cin>>father;
                cout<<"\t\t\tENTER MOTHER'S NAME : ";
                cin>>mother;
                cout<<"\t\t\tENTER CONTACT NUMBER : ";
                cin>>phone;
                cout<<"\nEnter the marks in evs(out of 100) : ";
                cin>>sub1_mark;
                cout<<"\nEnter the marks social science in (out of 100) : ";
                cin>>sub2_mark;
                cout<<"\nEnter the marks in maths(out of 100) : ";
                cin>>sub3_mark;
                cout<<"\nEnter the marks in english(out of 100) : ";
                cin>>sub4_mark;
                cout<<"\nEnter the marks in hindi(out of 100) : ";
                cin>>sub5_mark;
                calculate();   
                newfile<<admin_num<<" "<<name1<<" "<<name2<<" "<<class_standard<<" "<<address<<" "<<father<<" "<<mother<<" "<<phone<<" "<<sub1_mark<<" "<<sub2_mark<<" "<<sub3_mark<<" "<<sub4_mark<<" "<<sub5_mark<<" "<<percentage<<" "<<grade<<"\n";
                count++;
            }
            file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;
            if(count==0){   
                cout<<"\n\n\tdetails not found \n";
            }
        }
        newfile.close();
        file.close();
        remove("student.txt");
        rename("newstudent.txt","student.txt");
    }
}

void student::search_stud(){
    system("cls");
    fstream file;
    int count=0;
    file.open("student.txt",ios::in);
    if(!file){
        cout<<"\t\nNO data is present\n";
    }
    else{
        string adno;
        cout<<"\n********** SEARCH STUDENT ***********\n";
        cout<<"ENTER THE ROLL NUMBER OF THE STUDENT TO BE SEARCHED : ";
        cin>>adno;
        file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;
        while(!file.eof()){
            if(adno==admin_num){
            cout<<"\t\t\tADMISSION NUMBER : "<<admin_num<<endl;
            cout<<"\t\t\tSTUDENT's FIRST NAME : "<<name1<<endl;
            cout<<"\t\t\tSTUDENT's LAST NAME : "<<name2<<endl;
            cout<<"\t\t\tSTANDARD : "<<class_standard<<endl;
            
            cout<<"\t\t\tADDRESS : "<<address<<endl;
            cout<<"\t\t\tFATHER'S NAME : "<<father<<endl;
            cout<<"\t\t\tMOTHER'S NAME : "<<mother<<endl;
            cout<<"\t\t\tCONTACT NUMBER : "<<phone<<endl;

            cout<<"\t\t\n                     MARKS OF "<<name1<<" "<<name2<<" IN EXAMS                   \n\n";
                cout<<"\t\t\tMARKS IN EVS : "<<sub1_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN SOCIAL STUDIES : "<<sub2_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN MATHEMATICS: "<<sub3_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN ENGLISH : "<<sub4_mark<<"/100\n";
                cout<<"\t\t\tMARKS IN HINDI : "<<sub5_mark<<"/100\n";
                cout<<name1<<"'S PERCENTAGE IS : "<<percentage<<endl;
                cout<<name1<<" GRADE IS : "<<grade<<endl;
                cout<<"\n------------------------------------------\n";
                grade_list();
                cout<<"\t\n==================================================================================\n"; 
                count++;
            }
            file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;   
        }
        if(count==0){
            cout<<"ROLL NUMBER NOT FOUND\n";
        }
        file.close();
    }
}

void student::remove_student(){
    system("cls");
    fstream file,newfile;
    int count=0;
    string adno;//roll number
    cout<<"\n****************DELETE STUDENT DETAIL******************\n";
    file.open("student.txt",ios::in);
    if(!file){
        cout<<"\n\tNO DATA PRESENT\n";
        file.close();
    }
    else{
        cout<<"\nENTER THE ROLL NUMBER OF THE STUDENT YOU WANT TO DELETE : ";
        cin>>adno;
        newfile.open("newstudent.txt",ios::app|ios::out);
        file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;   
        while(!file.eof()){
            if(adno!=admin_num){
                newfile<<admin_num<<" "<<name1<<" "<<name2<<" "<<class_standard<<" "<<address<<" "<<father<<" "<<mother<<" "<<phone<<" "<<sub1_mark<<" "<<sub2_mark<<" "<<sub3_mark<<" "<<sub4_mark<<" "<<sub5_mark<<" "<<percentage<<" "<<grade<<"\n";
            }
            else{
                count++;
                cout<<"STUDENT SUCESSFULLY DELETED\n";
            }
            file>>admin_num>>name1>>name2>>class_standard>>address>>father>>mother>>phone>>sub1_mark>>sub2_mark>>sub3_mark>>sub4_mark>>sub5_mark>>percentage>>grade;               
        }
        if(count==0){
            cout<<"\n\t\t\tSTUDENT ROLL NUMBER NOT FOUND\n";
        }
        newfile.close();
        file.close();
        remove("student.txt");
        rename("newstudent.txt","student.txt");
    }


}

int main()
{
    student s;
    s.menu();
    return 0;
}
