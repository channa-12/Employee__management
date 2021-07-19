#include<iostream>
#include<fstream>
using namespace std;

struct date{
    string day;
    string month;
    string year;
};

struct employee{
    string first_name;
    string last_name;
    string id;
    string sex;
    date yob;
    string phone;
    string email;
    date work_date;
    string position;
    string work_status;
};

struct employee_manage{
    employee_manage *next;
    employee_manage *prev;
    employee data;
};

struct List{
    employee_manage *head;
    employee_manage *tail;
    int n;
};

List *l;

void input(string fn, string ln, string id, string sex,string yd,string ym,string yy, string pn, string em, string day, string month, string year, string pos, string ws){
    employee_manage *e;
    e=new employee_manage;
    e->data.first_name=fn;
    e->data.last_name=ln;
    e->data.id=id;
    e->data.sex=sex;
    e->data.yob.day=yd;
    e->data.yob.month=ym;
    e->data.yob.year=yy;
    e->data.phone=pn;
    e->data.email=em;
    e->data.work_date.day=day;
    e->data.work_date.month=month;
    e->data.work_date.year=year;
    e->data.position=pos;
    e->data.work_status=ws;
    e->next=NULL;
    if(l->n==0){
        e->prev=NULL;
        l->head=e;
        l->tail=e;
        l->n=l->n+1;
    }
    else{
        e->prev=l->tail;
        l->tail->next=e;
        l->tail=e;
        l->n=l->n+1;
    }
}

bool isEmpty(){
    if(l->n==0){
        return true;
    }
    else {return false;}
}

bool have(string has){
employee_manage *ha;
ha=l->head;
int haint=0;
while(ha!=NULL){
    if(ha->data.id==has){
        haint++;
        break;
    }
    else{ha=ha->next;}
}
if(haint==0){
    return 0;
}
else{return 1;}
}
string a123="01";
string b123="31";
string q123="01";
string w123="12";
string z123="0001";
string x123="9999";
string p0="0";
string p9="9";
//1. Add an employee
void add1(){
    employee_manage *e1;

        while(true){
        int check=0;

        string f,l1,id,s,yd,ym,yy,p,e,wd,wm,wy,posc,pos,sta,con;
        cout<<"Enter his/her First_Name(0 to stop adding): ";cin>>f;
        if(f=="0")break;
        cout<<"Enter his/her Last_Name(0 to stop adding): ";cin>>l1;
        if(l1=="0")break;
        while(true){
        cout<<"Enter his/her ID(0 to stop adding): ";cin>>id;
        if(have(id)){
            cout<<"\tThis ID has been used!!!\nPlease enter another one:"<<endl;
        }else{break;
        }
        }
        if(id=="0")break;
        cout<<"Enter his/her Sex(0 to stop adding): ";cin>>s;if(s=="0")break;
                while(true){
        cout<<"Enter his/her Birth Day(Please enter with 2 digit numbers)(0 to stop adding): ";cin>>yd;
        if(yd=="0"){
        check++;
        break;}
        if(yd.length()==2){
            if(yd<a123 || yd>b123){cout<<"Please enter the number between 01 and 31"<<endl;}
            else{
            break;}
        }
        }
        if(check!=0){break;}
        while(true){
        cout<<"Enter his/her Birth MonthPlease enter with 2 digit numbers)(0 to stop adding): ";cin>>ym;
        if(ym=="0")check++;break;
        if(ym.length()==2){
            if(ym<q123 || ym>w123){cout<<"\tPlease enter number between 01 and 12"<<endl;}
            else{break;}
        }
        }
        if(check!=0){break;}
        while(true){
        cout<<"Enter his/her birth year(Please enter with 4 digit numbers)(0 to stop adding): ";cin>>yy;
        if(yy=="0"){check++;break;}
        if(yy.length()==4){
            if(yy<z123 || yy>x123){cout<<"\tPlease enter number between 0000 and 9999!!!"<<endl;}
            else{break;}
        }
        }
        if(check!=0){break;}
        while(true){
        cout<<"Enter his/her Phone_Number(0 to stop adding): ";cin>>p;if(p=="0"){check++;break;}
        int pnum=p.length();
        int numm=0;
        for(int counter=0;counter<pnum;counter++){

            string pa;
            pa=p[counter];
            if(pa<p0 || pa>p9){numm++;}
        }
        if(numm!=0){cout<<"\tPlease enter each digit with the number between 0 and 9!!!"<<endl;}
        else{break;}
        }
        if(check!=0){break;}
        cout<<"Enter his/her Email(0 to stop adding): ";cin>>e;if(e=="0")break;
        while(true){
        cout<<"Enter his/her Started_Working_Day(Please enter with 2 digit numbers)(0 to stop adding): ";cin>>wd;
        if(wd=="0"){
        check++;
        break;}
        if(wd.length()==2){
            if(wd<a123 || wd>b123){cout<<"Please enter the number between 01 and 31"<<endl;}
            else{
            break;}
        }
        }
        if(check!=0){break;}
        while(true){
        cout<<"Enter his/her Started_Working_Month(Please enter with 2 digit numbers)(0 to stop adding): ";cin>>wm;
        if(wm=="0")check++;break;
        if(wm.length()==2){
            if(wm<q123 || wm>w123){cout<<"\tPlease enter number between 01 and 12"<<endl;}
            else{break;}
        }
        }
        if(check!=0){break;}
        while(true){
        cout<<"Enter his/her Started_Working_Year(Please enter with 4 digit numbers)(0 to stop adding): ";cin>>wy;
        if(wy=="0"){check++;break;}
        if(wy.length()==4){
            if(wy<z123 || wy>x123){cout<<"\tPlease enter number between 0000 and 9999!!!"<<endl;}
            else{break;}
        }
        }
        if(check!=0){break;}
        cout<<"Enter his/her Position: "<<endl;
        while(true){
            cout<<"\t1. Director\n\t2. CEO\n\t3. Manager\n\t4. Accountant\n\t5. Driver\n\t0. To stop adding an employee"<<endl;
            cout<<"\t\tChoose his/her Position: ";cin>>posc;
            if(posc=="1"){cout<<"Are you sure?(0 to confirm,else to cancel): ";cin>>con;if(con=="0"){pos="Director";break;}}else if(posc=="2"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){pos="CEO";break;}}
            else if(posc=="3"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){pos="Manager";break;}}else if(posc=="4"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){pos="Accountant";break;}}
            else if(posc=="5"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){pos="Driver";break;}}
            else if(posc=="0"){break;}
            else{cout<<"\tInvalid input!!!\nPlease choose the number between 1 and 5!!!"<<endl;}
        }
        cout<<"Enter his/her Work_status: "<<endl;
        while(true){
            cout<<"\t1. Working\n\t2. Resigned\n\t3. Retired\n\t0. To stop adding an employee"<<endl;
            cout<<"\t\tChoose his/her Working_Status: ";cin>>posc;
            if(posc=="1"){cout<<"Are you sure?(0 to confirm,else to cancel): ";cin>>con;if(con=="0"){sta="Working";break;}}else if(posc=="2"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){sta="Resigned";break;}}
            else if(posc=="3"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){sta="Retired";break;}}
            else if(posc=="0")break;
            else{cout<<"\tInvalid input!!!\nPlease choose the number between 1 and 3!!!"<<endl;}
        }
     cout<<"These are what you have enter:"<<endl;
     cout<<"\tFirst Name: "<<f<<"\n\tLast Name: "<<l<<"\n\tID: "<<id<<"\n\tSex: "<<s<<"\n\tDate of Birth: "<<yd<<"-"<<ym<<"-"<<yy<<"\n\tPhone number: "<<p<<"\n\tEmail: "<<e<<"\n\tStarted_Working_Day: "<<wd<<"\n\tStarted_Working_Month: "<<wm<<"\n\tStarted_Working_Year: "<<wy<<"\n\tPosition: "<<pos<<"\n\tWorking_Status: "<<sta<<endl;
     cout<<"Are you sure?(enter 0 to confirm, else to cancel and add again): ";
     cin>>con;
     if(con=="0"){
        input(f,l1,id,s,yd,ym,yy,p,e,wd,wm,wy,pos,sta);
        break;
     }
    }
}
//2.Display All employee
void display(){
    employee_manage *h;
    h=l->head;
    cout<<"First_Name Last Name ID SEX Date of Birth Phone number Email Started_Working_Date Position Working_Status:"<<endl;
         while(h!=NULL){
    if(h->data.work_status!="resigned"){
        cout<<h->data.first_name<<" "<<h->data.last_name<<" "<<h->data.id<<" "<<h->data.sex<<" "<<h->data.yob.day<<"-"<<h->data.yob.month<<"-"<<h->data.yob.year<<" "<<h->data.phone<<" "<<h->data.email<<" "<<h->data.work_date.day<<"-"<<h->data.work_date.month<<"-"<<h->data.work_date.year<<" "<<h->data.position<<" "<<h->data.work_status<<endl;
    }
    h=h->next;
    }
    cout<<endl;
}
//3.Update the information by ID
void update(){
    if(isEmpty()){
        cout<<"Update failed!!!\nThere is no employee to update!!!"<<endl;
    }
    else{
    while(true){
    string id;
    cout<<"\tEnter his/her ID to update his/her information(0 to cancel): ";cin>>id;
    if(id=="0"){cout<<"Stop updating...."<<endl;break;}
    else{
        int b=0;
        employee_manage *up;
        up=l->head;
        while(up!=NULL){
            if(up->data.id==id){
                b++;
                break;
            }
            else{up=up->next;}
        }
        if(b==0){cout<<"The ID you have entered doesn't match with any of the employee ID!!!"<<endl;}
        else{
        while(true){
        string pick;
        cout<<"1. First name\n2. Last name\n3. employee id\n4. Sex\n5.Year of birth\n6. Phone Number\n7. Email\n8. Started working date\n9. Position\n10. Working status\n0. Stop updating"<<endl;
        cout<<"Please choose an information to update:";
        cin>>pick;
        if(pick=="1"){
            while(true){
            string f_name;
            string con;
            cout<<"Please enter the new First Name(0 to cancel): ";
            cin>>f_name;
            if(f_name=="0"){cout<<"Update cancel..."<<endl;break;}
            else{
            cout<<"Enter 0 to confirm or else to re-update: ";
            cin>>con;
            if(con=="0"){
                up->data.first_name=f_name;
                cout<<"Update success..."<<endl;
                break;
            }
            }}
        }
                else if(pick=="2"){
            while(true){
                string l_name;
                string con2;
                cout<<"Please enter the new Last Name(0 to cancel): ";
                cin>>l_name;
                if(l_name=="0"){cout<<"Update cancel..."<<endl;break;}
                else{
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con2;
                if(con2=="0"){
                    up->data.last_name=l_name;
                    cout<<"Update success..."<<endl;
                    break;
                }}
            }
        }
                else if(pick=="3"){
            while(true){
                string em_id;
                string con3;
                cout<<"Please enter the new Employee ID(0 to cancel): ";
                cin>>em_id;
                if(em_id=="0"){cout<<"Update cancel..."<<endl;break;}
                else{
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con3;
                if(con3=="0"){
                    up->data.id=em_id;
                    cout<<"Update success..."<<endl;
                    break;
                }
            }}
        }
                else if(pick=="4"){
            while(true){
                string sex;
                string con4;
                cout<<"Please enter the new sex(0 to cancel): ";
                cin>>sex;
                if(sex=="0"){cout<<"Update cancel..."<<endl;break;}
                else{
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con4;
                if(con4=="0"){
                    up->data.sex=sex;
                    cout<<"Update success..."<<endl;
                    break;
                }
            }}
        }
                else if(pick=="5"){
            while(true){
                string day;
                string month;
                string year;
                string con5;
                int check=0;
                cout<<"Please enter the new Date of birth: "<<endl;
                while(true){
                cout<<"Enter the Day of his/her Birth Day(2 digits number)(0 to cancel): ";
                cin>>day;
                        if(day=="0"){
                        check++;
                        break;}
                        if(day.length()==2){
                        if(day<a123 || day>b123){cout<<"Please enter the number between 01 and 31"<<endl;}
                        else{
                        break;}
                            }
                }
                if(check!=0){cout<<"Update cancel..."<<endl;break;}
                while(true){
                cout<<"Enter the Month of his/her Birth Month(2 digits number)(0 to cancel): ";
                cin>>month;
                        if(month=="0"){
                        check++;
                        break;}
                        if(month.length()==2){
                        if(month<q123 || month>w123){cout<<"Please enter the number between 00 and 12"<<endl;}
                        else{
                        break;}
                            }
                }
                if(check!=0){cout<<"Update cancel..."<<endl;break;}
                while(true){
                cout<<"Enter the Year of his/her Birth Year(4 digits number)(0 to cancel): ";
                cin>>year;
                        if(year=="0"){
                        check++;
                        break;}
                        if(year.length()==4){
                        if(year<z123 || year>x123){cout<<"Please enter the number between 0000 and 9999"<<endl;}
                        else{
                        break;}
                            }
                }
                if(check!=0){cout<<"Update cancel..."<<endl;break;}
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con5;
                if(con5=="0"){
                    up->data.yob.day=day;
                    up->data.yob.month=month;
                    up->data.yob.year=year;
                    cout<<"Update success..."<<endl;
                    break;
                }
            }
        }
                else if(pick=="6"){
            while(true){
                string pn;
                string con6;
                int check=0;

                while(true){
                    cout<<"Enter his/her new Phone_Number(0 to stop adding): ";cin>>pn;if(pn=="0"){check++;break;}
                    int pnum=pn.length();
                    int numm=0;
                    for(int counter=0;counter<pnum;counter++){

                        string pa;
                        pa=pn[counter];
                        if(pa<p0 || pa>p9){numm++;}
                    }
                    if(numm!=0){cout<<"\tPlease enter each digit with the number between 0 and 9!!!"<<endl;}
                    else{break;}
                    }
                    if(check!=0){cout<<"Update cancel...."<<endl;break;}
                else{
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con6;
                if(con6=="0"){
                    up->data.phone=pn;
                    cout<<"Update success..."<<endl;
                    break;
                }}
                }
            }

                else if(pick=="7"){
            while(true){
                string Email;
                string con7;
                cout<<"Please enter the new Email(0 to cancel): ";
                cin>>Email;
                if(Email=="0"){cout<<"Update cancel..."<<endl;break;}
                else{
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con7;
                if(con7=="0"){
                    up->data.email=Email;
                    cout<<"Update success..."<<endl;
                    break;
                }
            }}
        }
                else if(pick=="8"){
            while(true){
                string s_w_day;
                string s_w_month;
                string s_w_year;
                string con8;
                int check=0;
                cout<<"Please enter the new Started Working Date: "<<endl;
                while(true){
                cout<<"Enter the day(2 digits number)(0 to cancel): ";
                cin>>s_w_day;
                        if(s_w_day=="0"){
                        check++;
                        break;}
                        if(s_w_day.length()==2){
                        if(s_w_day<a123 || s_w_day>b123){cout<<"Please enter the number between 01 and 31"<<endl;}
                        else{
                        break;}
                            }
                }
                if(check!=0){cout<<"Update cancel..."<<endl;break;}
                while(true){
                cout<<"Enter the month(2 digits number)(0 to cancel): ";
                cin>>s_w_month;
                        if(s_w_month=="0"){
                        check++;
                        break;}
                        if(s_w_month.length()==2){
                        if(s_w_month<q123 || s_w_month>w123){cout<<"Please enter the number between 00 and 12"<<endl;}
                        else{
                        break;}
                            }
                }
                if(check!=0){cout<<"Update cancel..."<<endl;break;}
                while(true){
                cout<<"Enter the year(4 digits number)(0 to cancel): ";
                cin>>s_w_year;
                        if(s_w_year=="0"){
                        check++;
                        break;}
                        if(s_w_year.length()==4){
                        if(s_w_year<z123 || s_w_year>x123){cout<<"Please enter the number between 0000 and 9999"<<endl;}
                        else{
                        break;}
                            }
                }
                if(check!=0){cout<<"Update cancel..."<<endl;break;}
                cout<<"Enter 0 to confirm or else to re-update: ";
                cin>>con8;
                if(con8=="0"){
                    up->data.work_date.day=s_w_day;
                    up->data.work_date.month=s_w_month;
                    up->data.work_date.year=s_w_year;
                    cout<<"Update success..."<<endl;
                    break;
                }
            }
        }
                else if(pick=="9"){
            while(true){
                string posc,con;
                cout<<"Enter the new Position: "<<endl;
            cout<<"1. Director\n2. CEO\n3. Manager\n4. Accountant\n5. Driver\n0. To cancel"<<endl;
            cout<<"\tChoose his/her Position: ";cin>>posc;
            if(posc=="1"){cout<<"Are you sure?(0 to confirm,else to cancel): ";cin>>con;if(con=="0"){up->data.position="Director";cout<<"Update success..."<<endl;break;}}
            else if(posc=="2"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){up->data.position="CEO";cout<<"Update success..."<<endl;break;}}
            else if(posc=="3"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){up->data.position="Manager";cout<<"Update success..."<<endl;break;}}
            else if(posc=="4"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){up->data.position="Accountant";cout<<"Update success..."<<endl;break;}}
            else if(posc=="5"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){up->data.position="Driver";cout<<"Update success..."<<endl;break;}}
            else if(posc=="0"){cout<<"You did not up his/her position."<<endl;break;}
            else{cout<<"Invalid input!!!\nPlease choose the number between 1 and 5!!!"<<endl;}
        }
        }
                else if(pick=="10"){
            while(true){
            string posc,con;
            cout<<"Enter his/her Work_status: "<<endl;
            cout<<"1. Working\n2. Resigned\n3. Retired\n0. To cancel"<<endl;
            cout<<"\tChoose his/her Working_Status: ";cin>>posc;
            if(posc=="1"){cout<<"Are you sure?(0 to confirm,else to cancel): ";cin>>con;if(con=="0"){up->data.work_status="Working";cout<<"Update success..."<<endl; break;}}
            else if(posc=="2"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){up->data.work_status="Resigned";cout<<"Update success..."<<endl;break;}}
            else if(posc=="3"){cout<<"Are you sure?(0 to confirm, else to cancel): ";cin>>con;if(con=="0"){up->data.work_status="Retired";cout<<"Update success..."<<endl;break;}}
            else if(posc=="0"){cout<<"You did not up his/her position."<<endl;break;}
            else{cout<<"Invalid input!!!\nPlease choose the number between 1 and 3!!!"<<endl;}
        }
        }
                else if(pick=="0"){
                    cout<<"Update End....."<<endl;
                    break;
                }
                else{
                cout<<"Invalid input!!!\nPlease choose the number between 1 and 10!!!"<<endl;
        }
        }
    }
    }}}
}

//4.When someone want to Resign
void resign(){
    if(isEmpty()){
        cout<<"Resigned Failed!!!\nThere is no data to do so!!!"<<endl;
    }
    else{
    string id,con;
    while(true){
    employee_manage *re;
        re=l->head;
        int p=0;
    cout<<"Enter his/her id(Enter 0 if you want to cancel): ";
    cin>>id;
    if(id=="0"){cout<<"Cancel Resigning"<<endl;break;}
    else{
            while(re!=NULL){
            if(re->data.id==id){
                p++;
                break;
            }
            else{
                re=re->next;
            }
        }
        if(p==0){
            cout<<"The ID that you have enter, doesn't match with any employee!!!"<<endl;
        }
        else{
    cout<<"Are you sure ?(input 0 to confirm, else to cancel and input again): ";
    cin>>con;
    if(con=="0"){
            re->data.work_status="resigned";
            cout<<"Update Successful!!!"<<endl;
            break;
}
    }
    }
    }}}

//5.Display information by specific ID
void display_id(){
if(isEmpty()){
    cout<<"Display failed!!!\nNo employee!!!"<<endl;
}
else{
    while(true){
    string id;
    cout<<"Enter his/her ID to show his/her information: ";cin>>id;
    if(id=="0"){cout<<"Cancel Display...."<<endl;break;}
    else{
    employee_manage *dis_id;
    dis_id=l->head;
    int a=0;
    while(dis_id!=NULL){
        if(dis_id->data.id==id){
           a++;
           break;
        }
        else{
            dis_id=dis_id->next;
        }
    }
    if(a==0){cout<<"There is no Employee ID that matches the ID you have entered!!!"<<endl;}
    else{
    cout<<"All Information for the employee u have enter:"<<endl;
    cout<<"First Name\t\t: "<<dis_id->data.first_name<<endl;
    cout<<"Last Name\t\t: "<<dis_id->data.last_name<<endl;
    cout<<"Employee ID\t\t: "<<dis_id->data.id<<"\nSex\t\t\t: "<<dis_id->data.sex<<endl;
    cout<<"\nDate of Birth\t\t: "<<dis_id->data.yob.day<<"-"<<dis_id->data.yob.month<<"-";
    cout<<dis_id->data.yob.year<<"\nPhone number\t\t: "<<dis_id->data.phone<<endl;
    cout<<"Email\t\t\t: "<<dis_id->data.email<<"\nStarted Working Date\t: "<<dis_id->data.work_date.day<<"-"<<dis_id->data.work_date.month<<"-"<<dis_id->data.work_date.year<<"\nPosition\t\t: "<<dis_id->data.position<<"\nWorking status\t\t: "<<dis_id->data.work_status<<endl;
    }
}
}}}

//6.Show all employee sort by Started_Working date in descending order
void displayDesc(){
    if(isEmpty()){
        cout<<"Display failed!!!\nThere is no information to Display!!!"<<endl;
    }
    else{
    employee_manage *com, *temp;
    com=l->head;
    temp=new employee_manage;
    for(int j=0;j<l->n;j++){
        while(com->next){
            if(com->data.work_date.year > com->next->data.work_date.year){
            temp->data=com->data;
            com->data=com->next->data;
            com->next->data=temp->data;
            com=com->next;
            }
            else if(com->data.work_date.year==com->next->data.work_date.year && com->data.work_date.month > com->next->data.work_date.month){
            temp->data=com->data;
            com->data=com->next->data;
            com->next->data=temp->data;
            com=com->next;
            }
            else if(com->data.work_date.year==com->next->data.work_date.year && com->data.work_date.month==com->next->data.work_date.month && com->data.work_date.day > com->next->data.work_date.day){
            temp->data=com->data;
            com->data=com->next->data;
            com->next->data=temp->data;
            com=com->next;
            }
            else{
                com=com->next;
            }
        }
        com=l->head;
    }
        cout<<"First_Name Last Name ID SEX Date of Birth Phone number Email Started_Working_Date Position Working_Status:"<<endl;
        while(com!=NULL){
        if(com->data.work_status!="resigned"){
        cout<<com->data.first_name<<" "<<com->data.last_name<<" "<<com->data.id<<" "<<com->data.sex<<" "<<com->data.yob.day<<"-"<<com->data.yob.month<<"-"<<com->data.yob.year<<" "<<com->data.phone<<" "<<com->data.email<<" "<<com->data.work_date.day<<"-"<<com->data.work_date.month<<"-"<<com->data.work_date.year<<" "<<com->data.position<<" "<<com->data.work_status<<endl;
    }
        com=com->next;
    }
    }
  }


//7.Show all employee sorted by position in Ascending Order
enum arr {Director,CEO,Manager,Accountant,Driver};
void displayAsc(){
    if(isEmpty()){cout<<"Display failed!!!\nThere is no information to Display"<<endl;}
    else{
    employee_manage *pos, *tmp;
    pos=l->head;
    tmp=new employee_manage;
    for(int i=0;i<l->n;i++){
        while(pos->next!=NULL){
            arr pos1;
            arr pos2;
            if(pos->data.position=="Director"){pos1=Director;}
            else if(pos->data.position=="CEO"){pos1=CEO;}
            else if(pos->data.position=="Manager"){pos1=Manager;}
            else if(pos->data.position=="Accountant"){pos1=Accountant;}
            else if(pos->data.position=="Driver"){pos1=Driver;}
            if(pos->next->data.position=="Director"){pos2=Director;}
            else if(pos->next->data.position=="CEO"){pos2=CEO;}
            else if(pos->next->data.position=="Manager"){pos2=Manager;}
            else if(pos->next->data.position=="Accountant"){pos2=Accountant;}
            else if(pos->next->data.position=="Driver"){pos2=Driver;}
            if(pos1 < pos2){
                tmp->data=pos->data;
                pos->data=pos->next->data;
                pos->next->data=tmp->data;
                pos=pos->next;
            }

            else{
                pos=pos->next;
            }
        }
        pos=l->head;
    }
    cout<<"First_Name Last Name ID SEX Date of Birth Phone number Email Started_Working_Date Position Working_Status:"<<endl;
    while(pos!=NULL){
        if(pos->data.work_status!="resigned"){
        cout<<pos->data.first_name<<" "<<pos->data.last_name<<" "<<pos->data.id<<""<<pos->data.sex<<" "<<pos->data.yob.day<<"-"<<pos->data.yob.month<<"-"<<pos->data.yob.year<<" "<<pos->data.phone<<" "<<pos->data.email<<" "<<pos->data.work_date.day<<"-"<<pos->data.work_date.month<<"-"<<pos->data.work_date.year<<""<<pos->data.position<<""<<pos->data.work_status<<endl;
        }
        pos=pos->next;
   }

}
}

//8.Display all Retired Employees
void display_retired(){
    employee_manage *dre;
    dre=l->head;
    int p=0;
    cout<<"First_Name Last Name ID SEX Date of Birth Phone number Email Started_Working_Date Position Working_Status:"<<endl;
    while(dre!=NULL){
        if(dre->data.work_status=="Retired"){
            cout<<dre->data.first_name<<" "<<dre->data.last_name<<" "<<dre->data.id<<" "<<dre->data.sex<<" "<<dre->data.yob.day<<"-"<<dre->data.yob.month<<"-"<<dre->data.yob.year<<" "<<dre->data.phone<<" "<<dre->data.email<<" "<<dre->data.work_date.day<<"-"<<dre->data.work_date.month<<"-"<<dre->data.work_date.year<<" "<<dre->data.position<<" "<<dre->data.work_status<<endl;
            p++;
        }
    dre=dre->next;
    }
    if(p==0){
        cout<<"There is no retired employee!!!"<<endl;
    }
    cout<<endl;
}

//Read File
void read(){
fstream file;
string f,l,id,s,yd,ym,yy,p,e,wd,wm,wy,pos,sta;
file.open("employee1.txt",ios::in);
if(!file){
    cout<<"File Not Found"<<endl;
}
else{
    while(!file.eof()){
    file>>f>>l>>id>>s>>yd>>ym>>yy>>p>>e>>wd>>wm>>wy>>pos>>sta;
    input(f,l,id,s,yd,ym,yy,p,e,wd,wm,wy,pos,sta);
    }
}
file.close();
}

//Write File
void write(){
fstream file;
file.open("employee1.txt",ios::out);
employee_manage *w;
w=l->head;
while(w!=NULL){
    file<<w->data.first_name<<" "<<w->data.last_name<<" "<<w->data.id<<" "<<w->data.sex<<" "<<w->data.yob.day<<" "<<w->data.yob.month<<" "<<w->data.yob.year<<" "<<w->data.phone<<" "<<w->data.email<<" "<<w->data.work_date.day<<" "<<w->data.work_date.month<<" "<<w->data.work_date.year<<" "<<w->data.position<<" "<<w->data.work_status;
    if(w!=l->tail){
        file<<endl;
    }
        w=w->next;}
}


int main(){
    string choose;
    l=new List;
    employee *e1;
    read();
    while(true){
    cout<<"====================Welcome to Employee_Management program===================="<<endl;
    cout<<"1. Add a new employee\n2. Display information for all employee working in the company\n3. Update information of an employee\n4. Resigned an employee\n5. Display information for a specific employee\n6. Show all employees sorted by Started Working data in descending order\n7. Show all employees sorted by Position in ascending order\n8. Display all retired employees\n0. Exit"<<endl;
    cout<<"\tChoose an option: ";
    cin>>choose;
    if(choose=="1"){
            add1();
    }
    else if(choose=="2"){
        display();
    }
    else if(choose=="3"){
        update();
    }
    else if(choose=="4"){
        resign();
    }
    else if(choose=="5"){
        display_id();
    }
    else if(choose=="6"){
        displayDesc();
    }
    else if(choose=="7"){
        displayAsc();
    }
    else if(choose=="8"){
        display_retired();
    }
    else if(choose=="0"){
        write();
        cout<<"Thank you and Good Bye :)"<<endl;
        break;
    }
        else{
    cout<<"Invalid input!!!\nPlease enter the number between 0 and 8!!!"<<endl;
    }
    }
    return 0;
}
