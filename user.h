
class user : public bank,public conversation
{
protected:

    string user_name;
    string password;
    string full_name;
    string phone;
public:
    user()
    {

        user_name="";
        password="";
        full_name="";
        phone="";
    }
    user ( string user, string pass, string full, string ph)
    {
        user_name=user;
        password=pass;
        full_name=full;
        phone=ph;
    }

    int check_user(string name, int rr)
    {
        this->user_name=name;
        bool flag=false;
        while(!flag)
        {
            //  cout<<" bye"<<endl;
            flag=1;
            fstream fin;
            fin.open("user.txt", ios::in);
            string line,tmp,word;
            vector<string>row;
            while(fin>>tmp)
            {
                //cout<<" hi"<<endl;
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
                        this->password=row[1];
                        this->full_name=row[2];
                        this->phone=row[3];
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

    void add_user()
    {
        //  this->user_name=user;


        ofstream fout;
        fout.open("user.txt", ios::out|ios::app);
        fout<<endl;
        fout<<"new ";
        fout<<this->user_name<<" "<<this->password<<" "<<this->full_name<<" "<<this->phone<<endl;
        fout.close();

    }
    int user_log(string name)
    {
        this->user_name=name;
        int flag=0;
        vector<string>row;
        while(!flag)
        {
            flag=1;
            fstream fin;
            fin.open("user.txt", ios::in);
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
                    this->password=row[1];
                    this->full_name=row[2];
                    this->phone=row[3];
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
    friend user_login(string *user_name);
    friend void show_user_profile(string myname);

};


int user_sign()
{
    string name, pass, full,ph;
A:

    user n;
    cout<<"\tEnter User Name:"<<endl;
    cin>>name;
    int r;
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

    user new_(name, pass, full, ph);
    bank *bn;
    bn = &new_;
    new_.add_user();
    add_to_all_user(name);

    bank ne;
    ne.open_bank_ac(name);

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

int user_login(string *user_name)
{
    string name,pass;
    user p;

    cout<<"\tEnter User name:"<<endl;
    cin>>name;
    if(p.check_user(name,1))
    {
        cout<<"\tThis User Name doesn't exist. "<<endl;
        return 0;
       // goto A;
    }
    cout<<"\tEnter Password:"<<endl;
    cin>>pass;
    int r=p.user_log(name);
    if(p.password!=pass)
    {
        cout<<"\tYour Password is incorrect\n\t\n"<<endl;

        return 0;
           // goto A;

    }
    else
    {
        *user_name=p.user_name;
        return 1;
    }
}

void show_user_profile(string myname)
{
    user j;
    int c=j.check_user(myname,2);
    cout<<"\tUser Name: "<<j.user_name;
    cout<<"\n\tFull Name: "<<j.full_name;
    cout<<"\n\tPhone Number: "<<j.phone<<endl;
    bank r;
    r.show_bank(myname);
    cout<<endl;
}
