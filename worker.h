

void add_to_org(string name, string org)
{

    map<string, vector<string> > mpp;
    vector<string>vp;

    fstream fin;
    fin.open("organizations_worker.txt", ios::in);
    string line,tmp,word;
    vector<string>row;
    while(fin>>tmp)
    {
        row.clear();
        getline(fin, line);
        stringstream ss(line);
        ss>>word;
        string s=word;
        vp.push_back(word);
        while(ss>>word)
        {
            mpp[s].push_back(word);
        }
        if(s==org)
        {
            mpp[s].push_back(name);
        }
    }
    fin.close();

    ofstream fout;
    fout.open("organizations_worker.txt", ios::out);
    for(int i=0; i<(int)vp.size(); i++)
    {
        fout<<endl;
        fout<<"new ";
        fout<<vp[i];
        for(int j=0; j<(int)mpp[vp[i]].size(); j++)
        {
            fout<<" "<<mpp[vp[i]][j];
        }
    }
    fout.close();
}

class worker : public bank, public organization,public conversation
{
    string worker_user_name;
    string worker_pass;
    string worker_org;
    string worker_full_name;
    string worker_phone;
public:
    worker()
    {
        worker_user_name="";
        worker_pass="";
        worker_org="";
        worker_full_name="";
        worker_phone="";
    }
    // worker new_(org,name, pass, full, ph);
    worker(string o,string u, string p, string f, string ph)
    {
        worker_user_name=u;
        worker_pass=p;
        worker_org=o;
        worker_full_name=f;
        worker_phone=ph;
        add_to_org(f,o);
    }
    int check_worker(string name, string *pp, int rr)
    {
        this->worker_user_name=name;
        int flag=0;
        while(!flag)
        {
            flag=1;
            fstream fin;
            fin.open("worker.txt", ios::in);
            string line,tmp,word;
            vector<string>row;
            while(fin>>tmp)
            {
                row.clear();
                getline(fin, line);
                stringstream ss(line);
                while(ss>>word)
                {
                    row.push_back(word);
                }

                if(this->worker_user_name==row[0])
                {
                    if(rr==2)
                    {
                        this->worker_org=row[1];
                        this->worker_pass=row[2];
                        this->worker_full_name=row[3];
                        this->worker_phone=row[4];
                        *pp=row[2];
                    }
                    flag=0;
                }

            }
            fin.close();
            if(!flag)
            {
                return 0;
                ///find worker
            }
        }
        return 1;
    }
    void add_worker()
    {
        //  this->user_name=user;
        ofstream fout;
        fout.open("worker.txt", ios::out|ios::app);
        fout<<endl;
        fout<<"new ";
        fout<<this->worker_user_name<<" "<<this->worker_org<<" "<<this->worker_pass<<" "<<this->worker_full_name<<" "<<this->worker_phone<<endl;
        fout.close();
    }

    friend worker_login(string *worker_name, string *worker_org);
    friend void show_worker_profile(string myname);

};

int worker_sign()
{
    string org, name, pass, full,ph;
D:
    cout<<"\tEnter Your Company Name:"<<endl;
    cin>>org;
    worker n;
    int r=n.check_org(org);
    if(r==1)

    {
        cout<<"\tThis organization name doesn't exits\n\tTry again."<<endl;
        goto D;
    }
    cout<<"\tEnter User Name:"<<endl;
    cin>>name;
    r=check_all_user(name);
    if(r==1)
    {
        cout<<"\tThis user name is already exits\n\tTry again."<<endl;
        goto D;
    }
    cout<<"\tEnter Password:"<<endl;
    cin>>pass;
    cout<<"\tEnter Your Name (One word)"<<endl;
    cin>>full;
    cout<<"\tEnter Phone Number:"<<endl;
    cin>>ph;

    worker new_(org,name, pass, full, ph);
    new_.add_worker();
    add_to_all_user(name);

    new_.open_bank_ac(name);

    cout<<"\tYou are successfully signed up\n"<<endl;

    cout<<"\tYou want to go to..\n\t\t1.Main Menu\n\t\t2.Exit"<<endl;
    int c;
    cin>>c;
    if(c==1)
    {
        return 1;

    }
    else
        return 0;

}

int worker_login(string *worker_name, string *worker_org)
{
    string name,pass, user_pass;
    worker p;

    cout<<"\tEnter User name:"<<endl;
    cin>>name;
    if(p.check_worker(name, &user_pass,2))
    {
        cout<<"\tThis User Name doesn't exist."<<endl;
        return 0;
       // goto A;
    }
    cout<<"\tEnter Password:"<<endl;
    cin>>pass;
    //int r=p.worker_log();
    if(pass!=user_pass)
    {
        cout<<"\tYour Password is incorrect\n\t\n"<<endl;
        return 0;

           // goto A;

    }
    else
    {
        *worker_name=p.worker_user_name;
        *worker_org=p.worker_org;
        return 1;
    }
}

void show_worker_profile(string myname)
{
    worker j;
    string pr;
    int c=j.check_worker(myname,&pr,2);
    cout<<"\tWorker Name: "<<j.worker_user_name;
    cout<<"\n\tOrgnization Name: "<<j.worker_org;
    cout<<"\n\tFull Name: "<<j.worker_full_name;
    cout<<"\n\tPhone Number: "<<j.worker_phone<<endl;
    j.show_bank(myname);
}

void show_workers(string name)
{
    cout<<"\tOrganization Name : "<<name<<endl;
    cout<< "\t\tWorkers are.. :"<<endl;
    bool flag=0;
    while(!flag)
    {
        flag=1;
        fstream fin;
        fin.open("organizations_worker.txt", ios::in);
        string line,tmp,word;
        map<string,vector<string> >row;

        while(fin>>tmp)
        {
            getline(fin, line);
            stringstream ss(line);
            ss>>word;
            string s=word;
            int t=1;
            while(ss>>word)
            {
                row[s].push_back(word);
                //mpp[word].push_back(word);
            }
        }

        int t=1;

        for(int i=0; i<(int)row[name].size(); i++)
        {
            flag=0;
            cout<<"\t\t\t"<<t++<<". "<<row[name][i]<<endl;
        }

        fin.close();
        if(!flag)
        {
            break;
        }
    }
    cout<<endl;
}
