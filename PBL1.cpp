#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<string> 
using namespace std;

class ST{
private:
    string firstname,lastname;
    string hometown;
    string rate;
    
    int idst;
    int birthyear;
    float math,physic,english,gpa; 
    static int count;
public:
        ST(){}
        ST(int id,string ln, string fn, string ht,int by,float ma, float ps,float el,float ga){
          idst=id;
          lastname = ln;
          firstname =  fn;
          hometown = ht;
          birthyear = by;
          math = ma;
          physic = ps;
          english = el;
          gpa = ga;
    if (gpa >= 8 ) rate ="Excellent";
    if (gpa >= 6.5 and gpa<8 ) rate ="Good";
    if (gpa >= 5 and gpa <6.5 ) rate ="Average";
    if (gpa >= 3.5 and gpa <5  ) rate ="Fair";
    if (gpa <=3.5) rate="Poor";
        }
 
        void add_students(); 
        void print_list_students();
        void edit_student(int id);
        void del_students(int id);
        void layout();
        void search_students();
        void rank();
        void output();
        void statistic();
        void read_file(ifstream &, vector<ST> &);
        void write_file();
        void menu1();
        int menu2();
        void set_lastname(string ln){
             lastname =ln; 
        }
         void set_firstname(string fn){
             firstname =fn; 
        }
         void set_hometown(string ht){
             hometown=ht;
         }

        void set_by(int by){
            birthyear  =by ;
        }
        void set_scores_and_rate(float ma,float ps,float el){
            math = ma;
            physic =ps;
            english = el;
            gpa = (ma+ps+el)/3 ;
             if (gpa >= 8 ) rate ="Excellent";
    if (gpa >= 6.5 and gpa<8 ) rate ="Good";
    if (gpa >= 5 and gpa <6.5 ) rate ="Average";
    if (gpa >= 3.5 and gpa <5  ) rate ="Fair";
    if (gpa <=3.5) rate="Poor";

        }
};

int  ST::count=0;

vector<ST> listST; 

vector listST2=listST;


void ST::layout(){
      cout <<left  << setw(12) << "Student ID"             << "|" 
           << left << setw(20)  << "Last Name"               << "|" 
           << left << setw(10)   << "First Name"              << "|" 
           << left << setw(18)  << "Hometown"         << "|" 
           << left << setw(12)   << "Birth Year"        << "|" 
           << left << setw(10)   << "Math"        << "|" 
           << left << setw(10)   << "Physic"           << "|" 
           << left << setw(10)   << "English"        << "|" 
           << left << setw(10)  << "GPA"  << "|"
           <<left  << setw(10)  << "Rate"        << "|"<<endl;
}
void ST::output(){
            cout << left << setw(12)    << idst           << "|";
            cout << left << setw(20)    << lastname             << "|";
            cout << left << setw(10)     << firstname            << "|";
            cout << left << setw(18)    << hometown        << "|";
            cout << left << setw(12)     << birthyear        << "|";
            cout << left << setw(10)     << math              << "|";
            cout << left << setw(10)     << physic          << "|";
            cout << left << setw(10)     << english       << "|";
            cout << left << setw(10)    << setprecision(2) << fixed<<gpa            << "|";
            cout << left << setw(10)    << rate       << "|"<<endl;
}

void ST::add_students(){
    ++count;
    string lastname,firstname, hometown,rate;
    float  math, physic, english,gpa;
    int by,id ;
    id=count;  
    cin.ignore();  
    cout<<"Enter student 's last name"<<endl;        getline(cin,lastname);
    cout<<"Enter student 's first name "<<endl;           getline(cin,firstname);
    cout<<"Enter student 's hometown "<<endl;    getline(cin,hometown);
    do{
        cout<<"Enter student 's birth year "<<endl;
        cin>>by; 
  
    }while(by<1990 and by>2010);

    cout<<"Enter scores of 3 subjects of the student: Math, Physic and English "<<endl;
    cout<<"(eg:8 9 10)"<<endl;
    cin>>math>>physic>>english;
    gpa = (math+physic+english)/3; 
    if (gpa >= 8 ) rate ="Excellent";
    if (gpa >= 6.5 and gpa<8 ) rate ="Good";
    if (gpa >= 5 and gpa <6.5 ) rate ="Average";
    if (gpa >= 3.5 and gpa <5  ) rate ="Fair";
    if (gpa <=3.5) rate="Poor";


    listST.push_back(ST(id,lastname,firstname, hometown,by ,math,physic,english,gpa));
    
    
    }

void ST::print_list_students(){
    layout();
    for(int i=0; i<listST.size();i++) {
    listST[i].output();
    }
}
void ST::del_students(int id)
{    if(id > listST.size()) 
        cout<<"ID not found"<<endl;
       
    else {
    for (int i=0; i<listST.size(); i++)
    {
        if (listST[i].idst == id)
        {   
            
            listST.erase(listST.begin() + i);
            cout<<"Deleted"<<endl;
        }
    }
}}
void ST::edit_student(int id){
    if(id > listST.size()) 
        cout<<"ID not found"<<endl;
       
    else {
    for(int i=0; i<listST.size(); i++)
    {
         if (listST[i].idst == id)
         {  
            string ln,fn,ht;
            int by;
            float ma,ps,el;
            layout(); 
            listST[i].output();
            
            cout<<"EDIT"<<endl;
            cin.ignore();
            cout<<"Enter new last name"<<endl;  getline(cin,ln);   listST[i].set_lastname(ln);
                                                
            cout<<"Enter new first name"<<endl; getline(cin,fn);   listST[i].set_firstname(fn);
            
            cout<<"Enter new hometown "<<endl;   getline(cin,ht);  listST[i].set_hometown(ht);
           
            cout<<"Enter new birth year "<<endl; cin>>by;          listST[i].set_by(by);
            
            cout<<"Enter new scores "<<endl;   cin>>ma>>ps>>el;    listST[i].set_scores_and_rate(ma,ps,el);    

            cout<<"Student has been editted successfully!"<<endl;
            layout();
            listST[i].output();
        }}
         
}
} 

void ST::search_students(){
    int id;
    int tim1 =0;
    cout<<"Enter ID "<<endl;
    cout<<"Forget ID, Enter 0"<<endl;
    cin>>id;
    for(int i=0; i<listST.size(); i++){
        if(listST[i].idst == id) {
            tim1++;
            cout<<"Result"<<endl;
            layout();
            listST[i].output();
            system("pause");
        }
    }int tim2=0;
    if(tim1==0) {
        cin.ignore();
        cout<<"Enter first name"<<endl;
        string fn;
        
        getline(cin,fn);
        cout<<"Result"<<endl;
        layout();
        for(int i=0; i<listST.size(); i++) {
            if(listST[i].firstname == fn) {
                tim2++;
                
               
                listST[i].output();
            }
        }
        system("pause");
    
    }
    if(tim2 ==0 ){
        cout<<"Sorry, student not found"<<endl;
        system("pause");
    }
}
void ST::rank(){
    cout<<endl;
    listST2=listST;
    ST k;
    for(int i=0 ;i<listST2.size(); i++){
        for(int j=0; j<listST2.size(); j++){
            if(listST2[i].gpa > listST2[j].gpa){
                ST k;
                k=listST2[i];
                listST2[i]=listST2[j];
                listST2[j]=k;
            }
        }
    }
    layout();
    for(int i=0; i<listST2.size(); i++){
        listST2[i].output();
    }
}
void ST::statistic(){
    int ec,gc,ac,fc,pc;
    ec=gc=ac=fc=pc=0;
    for(int i=0;i<listST.size(); i++){
    if (listST[i].gpa >= 8 ) {ec++;}
    if (listST[i].gpa >= 6.5 and listST[i].gpa<8 ) {gc++;}
    if (listST[i].gpa >= 5 and listST[i].gpa <6.5 ) {ac++;}
    if (listST[i].gpa >= 3.5 and listST[i].gpa <5  ) {fc++;}
    if (listST[i].gpa <=3.5){pc++;}
    }
    double p1=double(ec)/double(count)*100.00;
    double p2=double(gc)/double(count)*100.00;
    double p3=double(ac)/double(count)*100.00;
    double p4=double(fc)/double(count)*100.00;
    double p5=double(pc)/double(count)*100.00;
    cout<<endl;
    cout<<"------------------Statistics-----------------"<<endl;
    cout<<left<<setw(12)<<"Rate"     <<"|"<<left<<setw(20)  <<"Number of students"<<"|"<<left<<setw(10)<<"Percentage"<<"|"<<endl;
    cout<<left<<setw(12)<<"Excellent"<<"|"<<left<<setw(20)  <<ec<<"|"<<left<<setw(10)<<setprecision(2)<<fixed<<p1<<"|"<<endl;
    cout<<left<<setw(12)<<"Good"     <<"|"<<left<<setw(20)  <<gc<<"|"<<left<<setw(10)<<setprecision(2)<<fixed<<p2<<"|"<<endl;
    cout<<left<<setw(12)<<"Average"<<"|"<<left<<setw(20)    <<ac<<"|"<<left<<setw(10)<<setprecision(2)<<fixed<<p3<<"|"<<endl;
    cout<<left<<setw(12)<<"Fair"<<"|"<<left<<setw(20)       <<fc<<"|"<<left<<setw(10)<<setprecision(2)<<fixed<<p4<<"|"<<endl;
    cout<<left<<setw(12)<<"Poor"<<"|"<<left<<setw(20)       <<pc<<"|"<<left<<setw(10)<<setprecision(2)<<fixed<<p5<<"|"<<endl;
    cout<<"---------------------------------------------"<<endl;
}
void ST::read_file(ifstream &filein, vector<ST> &listST){
    ifstream myfile("C:\\Users\\ninte\\.vscode\\SINHVIEN.txt");  
    while(!myfile.eof()){
        int id,by;
        string fullname,fn,ln,hometown;
        float ma,ps,el,ga;
        myfile>>id,' ';
        getline(myfile,fullname,',');
        getline(myfile,hometown,',');
        
        myfile>>by,' ';
        myfile>>ma,' ';
        myfile>>ps,' ';
        myfile>>el,' ';
        myfile>>ga,' ';

        for(int id=0; id<fullname.size(); id++){
            if(fullname[id]=='#') {
                for(int i=id; i<fullname.size();i++){
                    fn+=fullname[i];
                }
            }      
   }
   for(int id=0; id<fullname.size(); id++){
    if(fullname[id]=='#'){
       for(int i=0; i<id;i++){
        ln+=fullname[i];
       }
    }
   }
   fn.erase(0,1);
   ln.erase(0,1);
        listST.push_back(ST(id,ln,fn,hometown,by,ma,ps,el,ga));      
        count=id;       
    }
     listST.pop_back();
 }
void splitstring(string fullname, string &fn, string &ln){
   for(int id=0; id<fullname.size(); id++){
            if(fullname[id]=='#') {
                for(int i=id; i<fullname.size();i++){
                    fn+=fullname[i];
                }
            }
             
   }
   for(int id=0; id<fullname.size(); id++){
    if(fullname[id]=='#'){
       for(int i=0; i<id;i++){
        ln+=fullname[i];
       }
    }
   }
   fn.erase(0,1);
   ln.erase(0,1);
 }
void ST:: write_file(){
    ofstream output;
    output.open("C:\\Users\\ninte\\.vscode\\SINHVIEN.txt");    
    if(!output.is_open()){
        cout<<"Could not open this file"<<endl;
    }
    for(int i=0; i<listST.size(); i++) {
    output<<listST[i].idst<<" "<<listST[i].lastname<<"#"<<listST[i].firstname<<","<<listST[i].hometown<<","<<listST[i].birthyear
    <<" "<<listST[i].math<<" "<<listST[i].physic<<" "<<listST[i].english<<" "<<listST[i].gpa<<endl;
}
    cout<<"Data saved"<<endl;
    output.close();
    system("pause");
}
void ST::menu1(){
    ST st;
    while(true){
        system("cls");
        cout<<"STUDENTS MANAGEMENT PROGRAM \n";
        cout<<"Please select your role:\n";
        cout<<"1. Student\n";
        cout<<"2. Teacher\n";
        cout<<"0. Exit Program\n";
            int pick,id;
            string fn;
            cout<<endl;
            cout<<"Enter choice:\n";
            cin>>pick;
            if(pick==1){
                cout<<"Welcome student\n";
                cout<<endl;
                cout<<"Fill in your information to see your score\n";
                st.search_students();
            
            }
            else if(pick==2){
            int password;
            cout<<"Welcome teacher\n";
            cout<<"Enter password\n";
            cin>>password;
            if(password ==123) {
                cout<<"Welcome back, Teacher\n";
                system("cls");
                menu2();
            }
            else {
                cout<<"Wrong password\n";
                system("pause");
                menu1();
            } 
        }
            else if(pick ==0){
                break;
            }
         else {
            cout<<"Please enter choice\n";
            system("pause");
            menu1();    
         }   }

}
int ST::menu2(){
    cout<<"Welcome back, Teacher"<<endl;
    cout<<endl;
    ST st;
   st.print_list_students();
    int input;
    int id;
    while(true){
        cout <<endl;
        cout << "STUDENTS MANAGEMENT PROGRAM \n";
        cout << "FUNCTION : \n";
        cout << "1. Add New Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Search for student\n";
        cout << "5. Show List of Students\n";
        cout << "6. Rank (GPA)\n";
        cout << "7. Run Statistics\n";
        cout << "8. Save Data\n";
        cout << "0. Exit Program\n";
        cout << "YOUR CHOICE : " ; 
        cin >> input;

        switch (input)
        {
        case 1:
            system("cls");
            cout << "You choose 1.Add New Student\n";
            st.add_students();
            cout <<"Student has been added successfully!"<<endl;
            break;
        case 2:
            
            cout << "You choose 2.Edit Student\n";
            cout<<"Enter student id"<<endl;
            cin>>id;
            
            st.edit_student(id);
           
            break;
        case 3:
            
            cout << "You choose 3.Delete Student\n";
            cout << "Enter Student ID: "; cin >> id;
            st.del_students(id);
            
            break;
        case 4:
            system("cls");
            cout<< "You choose 4.Search for student\n ";
            st.search_students();
            break; 
        case 5:
            system("cls"); 
            cout << "You choose 5.Show List Of Students\n";
            st.print_list_students();
            break;
        case 6:
            system("cls");
            cout<<"You choose 6.Rank (GPA)\n ";
            st.rank();    
            break;
        case 7:
            system("cls");
            cout<<"You choose 7.Run Statistics\n";
            st.statistic();
            break;
        case 8:
            system("cls");
            cout<<"You choose 8.Save Data\n";
            st.write_file();
            break;    
        case 0:
            return 0;
    }
}

}
int main(){
ST st;
ifstream filein("C:\\Users\\ninte\\.vscode\\SINHVIEN.txt");
if(!filein.is_open()){
    cout<<"Could not open this file"<<endl;
    system("pause");
}

st.read_file(filein,listST);
filein.close();
st.menu1();
return 0;
}