
#include "organization.h"


void add_org(string na,string name)
{
    ofstream fout;
    fout.open("organization.txt", ios::out|ios::app);

    fout<<endl;
    fout<<"new ";
    fout<<na<<" "<<name;

    fout.close();
}

class owner : public bank, public organization,public conversation
{
protected:

    string user_name;
    string organi;
    string password;
    string full_name;
    string phone;
public:
    owner()
    {
        organi="";
        user_name="";
        password="";
        full_name="";
        phone="";
    }
    owner (string org, string user, string pass, string full, string ph)
    {
        organi=org;
        user_name=user;
        password=pass;
        full_name=full;
        phone=ph;
    }

    int check_owner(string name, int rr)
    {
        this->user_name=name;
        bool flag=false;
        while(!flag)
        {
            //  cout<<" bye"<<endl;
            fstream fin;
            flag=true;
            fin.open("owner.txt", ios::in);
            string line,tmp,word;
            vector<string>row;
            while(fin>>tmp)
            {
                //  cout<<" hi"<<endl;
                row.clear();
                getline(fin, line);
                stringstream ss(line);
                while(ss>>word)
                {
                    row.push_back(word);
                }

                if(this->user_name==row[0])
                {
                    if(rr==2)
                    {
                        this->organi=row[1];
                        this->password=row[2];
                        this->full_name=row[3];
                        this->phone=row[4];
                    }
                    flag=0;
                }

            }
            fin.close();
            if(!flag)
            {
                return 0;
            }


        }
        return 1;


    }

    void add_owner ()
    {
        //  this->user_name=user;


        ofstream fout;
        fout.open("owner.txt", ios::out|ios::app);
        fout<<endl;
        fout<<"new ";
        fout<<this->user_name<<" "<<this->organi<<" "<<this->password<<" "<<this->full_name<<" "<<this->phone<<endl;
        fout.close();

    }
    int owner_log(string name)
    {
        this->user_name=name;
        int flag=0;
        vector<string>row;
        while(!flag)
        {
            flag=1;
            fstream fin;
            fin.open("owner.txt", ios::in);
            string line,tmp,word;
            while(fin>>tmp)
            {
                row.clear();
                getline(fin, line);
                stringstream ss(line);
                while(ss>>word)
                {
                    row.push_back(word);
                }


                if(this->user_name==row[0])
                {
                    this->organi=row[1];
                    this->password=row[2];
                    this->full_name=row[3];
                    this->phone=row[4];
                    flag=0;
                }

            }
            fin.close();
            if(!flag)
            {
                return 1;
            }
        }
        return 0;


    }



    friend owner_login(string *owner_name, string *owner_org);
    friend void show_owner_profile(string myname);

};

void org_to_worker_list(string n)
{
    ofstream fout;
    fout.open("organizations_worker.txt", ios::out|ios::app);

    fout<<endl;
    fout<<"new ";
    fout<<n;

    fout.close();
}

int owner_sign()
{
    string org, name, pass, full,ph;
A:
    cout<<"\tEnter Your Company Name:"<<endl;
    cin>>org;
    owner n;
    int r=n.check_org(org);
    if(r==0)
    {
        cout<<"\tThis organization name is already exits\n\tTry again."<<endl;
        goto A;
    }
    cout<<"\tEnter User Name:"<<endl;
    cin>>name;
    r=check_all_user(name);
    if(r==1)
    {
        cout<<"\tThis User Name is already exits\n\tTry again."<<endl;

        goto A;
    }
    cout<<"\tEnter Password:"<<endl;
    cin>>pass;
    cout<<"\tEnter Your Name (One word)"<<endl;
    cin>>full;
    cout<<"\tEnter Phone Number:"<<endl;
    cin>>ph;

    owner new_(org,name, pass, full, ph);
    new_.add_owner();
    add_to_all_user(name);

    conversation con;
    bank ne;
    org_to_worker_list(org);
    add_org(org,name);

    ne.open_bank_ac(name);

    cout<<"\tAdd Your Company's Product"<<endl;

    n.add_good(org);


     cout<<"\tYou are successfully signed up\n"<<endl;
    cout<<"\tYou want to go to..\n\t\t1.Main Menu\n\t\t2.Exit"<<endl;
    int c;
    cin>>c;
    if(c==1)
    {
        return 1;

    }
    else
    {


        return 0;
    }

}

int owner_login(string *owner_name, string *owner_org)
{
    string name,pass;
    owner p;

    cout<<"\tEnter User name:"<<endl;
    cin>>name;
    if(p.check_owner(name,1))
    {
        cout<<"\tThis User Name doesn't exist."<<endl;
        return 0;
        //goto A;
    }
    cout<<"\tEnter Password:"<<endl;
    cin>>pass;
    p.owner_log(name);
    if(p.password!=pass)
    {
        cout<<"\tYour Password is incorrect\n"<<endl;
        return 0;
            //goto A;
    }
    else
    {
        *owner_name=p.user_name;
        *owner_org=p.organi;
        return 1;
    }
}

void show_owner_profile(string myname)
{
    owner j;
    j.check_owner(myname,2);
    cout<<"\tOwner Name: "<<j.user_name;
    cout<<"\n\tOrgnization Name: "<<j.organi;
    cout<<"\n\tFull Name: "<<j.full_name;
    cout<<"\n\tPhone Number: "<<j.phone<<endl;
    bank r;
    r.show_bank(myname);
}
