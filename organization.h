#include"Bank.H"
#include"conversation.h"
class goods
{
protected:
    string pro_name;
    int price;
    int quantity;
public:
    goods()
    {
        pro_name="";
        price=0;
        quantity=0;
    }
    goods(string n, int p, int q)
    {
        pro_name=n;
        price=p;
        quantity=q;
    }
    friend class organization;
};

class organization : public goods
{
protected:
    string org_name;

public:

    int check_org(string org)
    {

        bool flag=false;
        while(!flag)
        {
            // cout<<" hi"<<endl;
            flag=true;
            fstream fin;
            fin.open("organization.txt", ios::in);
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

                if(org==row[0])
                    flag=false;

            }
            fin.close();
            if(!flag)
            {
                return 0;
            }
        }
        return 1;
    }




    void add_good(string n)
    {
        vector<goods>g;
        this->org_name=n;

        cout<<"\tHow many goods you want to add?"<<endl;
        int t;
        cin>>t;
        while(t--)
        {
            string pro_n;
            int pri, qua;
            cout<<"Name of the product:"<<endl;
            cin>>pro_n;
            cout<<"Price of this product"<<endl;
            cin>>pri;
            cout<<"Quantity of this product"<<endl;
            cin>>qua;

            goods ne(pro_n, pri, qua);

            g.push_back(ne);
        }
        ofstream fout;
        fout.open("goods.txt", ios::out|ios::app);
        fout<<endl;
        fout<<"new ";
        fout<<this->org_name;
        for(int i=0; i<(int)g.size(); i++)
        {
            fout<<" "<<g[i].pro_name<<" "<<g[i].price<<" "<<g[i].quantity;
        }
        fout.close();

    }
    void show_goods(string org)
    {
        this->org_name=org;
        bool flag=false;
        while(!flag)
        {
            flag=true;
            fstream fin;
            fin.open("goods.txt", ios::in);
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

                if(this->org_name==row[0])
                {
                    int t=1;
                    for(int i=1; i<int(row.size()); i+=3)
                    {
                        cout<<"\tSerial: "<<t++<<"\tProduct name: "<<row[i]<<"\tPrice : "<<row[i+1]<<"\tQuantity Available: "<<row[i+2]<<endl;

                    }
                    cout<<endl;
                    flag=false;

                }

            }
            fin.close();
            if(!flag)
                break;
        }
    }

    int get_price(string org,int se, int *quan)
    {
        this->org_name=org;
        bool flag=false;
        while(!flag)
        {
            flag=true;
            fstream fin;
            fin.open("goods.txt", ios::in);
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

                if(this->org_name==row[0])
                {
                    int r=0;
                    for(int i=1; i<int(row.size()); i+=3)
                    {
                        stringstream now(row[i+1]);
                        int t;
                        now>>t;
                        if(r==se)
                        {
                            stringstream now(row[i+2]);
                            now>>(*quan);
                            return t;
                        }
                        r++;

                    }
                    //    cout<<endl;
                    flag=false;

                }

            }
            fin.close();
            if(!flag)
                break;
        }
        return -1;
    }

    void add_extra_goods(string org)
    {
H:
        string p_name,pri,q;
        cout<<"Name of the product:"<<endl;
        cin>>p_name;
        cout<<"Price of this product"<<endl;
        cin>>pri;
        cout<<"Quantity of this product"<<endl;
        cin>>q;

        map<string, vector<string> > mpp;
        vector<string>vp;

        fstream fin;
        fin.open("goods.txt", ios::in);
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

                mpp[s].push_back(p_name);
                mpp[s].push_back(pri);
                mpp[s].push_back(q);
            }
        }
        fin.close();

        ofstream fout;
        fout.open("goods.txt", ios::out);
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

        cout<<"\tDo you want to add more?"<<endl;
        cout<<"\t1.Yes\n\t2.No"<<endl;
        int cas;
        cin>>cas;
        if(cas==1)
            goto H;
        else
            return;
    }

    void edit_goods(string org)
    {
        show_goods(org);
        cout<<endl;
HH:
        string p_name,pri,q;
        cout<<"Name of the product:"<<endl;
        cin>>p_name;
        cout<<"Price of this product"<<endl;
        cin>>pri;
        cout<<"Quantity of this product"<<endl;
        cin>>q;

        map<string, vector<string> > mpp;
        vector<string>vp;

        fstream fin;
        fin.open("goods.txt", ios::in);
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

            int cnt=0;

            while(ss>>word)
            {
                mpp[s].push_back(word);
            }
            if(s==org)
            {
                for(int i=0;i<mpp[s].size();i+=3)
                {
                    if(mpp[s][i]==p_name)
                    {
                        mpp[s][i+1]=pri;
                        mpp[s][i+2]=q;
                    }
                }

            }
        }
        fin.close();

        ofstream fout;
        fout.open("goods.txt", ios::out);
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

        cout<<"\tDo you want to edit more?"<<endl;
        cout<<"\t1.Yes\n\t2.No"<<endl;
        int cas;
        cin>>cas;
        if(cas==1)
            goto HH;
        else
            return;
    }

    void delete_goods(string org)
    {
        show_goods(org);
        cout<<endl;
HHH:
        string p_name,pri,q;
        cout<<"Name of the product:"<<endl;
        cin>>p_name;

        map<string, vector<string> > mpp;
        vector<string>vp;

        fstream fin;
        fin.open("goods.txt", ios::in);
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

            int cnt=0;

            while(ss>>word)
            {
                mpp[s].push_back(word);
            }
            if(s==org)
            {
                for(int i=0;i<mpp[s].size();i+=3)
                {
                    if(mpp[s][i]==p_name)
                    {
                       mpp[s].erase(mpp[s].begin()+i);
                       mpp[s].erase(mpp[s].begin()+i);
                       mpp[s].erase(mpp[s].begin()+i);
                       break;
                    }
                }

            }
        }
        fin.close();

        ofstream fout;
        fout.open("goods.txt", ios::out);
        for(int i=0; i<(int)vp.size(); i++)
        {
         //    if(mpp[vp[i]][0]!="-1")
            fout<<endl;
            fout<<"new ";
            fout<<vp[i];
            for(int j=0; j<(int)mpp[vp[i]].size(); j++)
            {
               // if(mpp[vp[i]][j]!="-1")
                fout<<" "<<mpp[vp[i]][j];
            }
        }
        fout.close();

        cout<<"\tDo you want to delete more?"<<endl;
        cout<<"\t1.Yes\n\t2.No"<<endl;
        int cas;
        cin>>cas;
        if(cas==1)
            goto HHH;
        else
            return;
    }

    friend class owner;
    friend class worker;
    friend void goods_update(string org, int se, int qq);

};


void show_all_org()
{
    fstream fin;
    fin.open("organization.txt", ios::in);
    string line,tmp,word;
    map<string,vector<string> >row;


    while(fin>>tmp)
    {
        getline(fin, line);
        stringstream ss(line);
        while(ss>>word)
        {
            string w2;
            ss>>w2;
            cout<<"\tOrganization Name :"<<word<<"\t\tOwner name :"<<w2<<endl;
            //mpp[word].push_back(word);
        }

    }
    fin.close();
}


void goods_update(string org, int se, int qq)
{
    //cout<<" update good"<<endl;
    map<string, vector<string> > mpp;
    vector<string>vp;

    fstream fin;
    fin.open("goods.txt", ios::in);
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
            row.push_back(word);
        }
        if(org==s)
        {
            // cout<<" find org"<<endl;
            int r=0;
            for(int i=0; i<int(row.size()); i+=3)
            {
                stringstream now(row[i+1]);
                int t;
                now>>t;
                if(r==se)
                {
                    int n;
                    stringstream no(row[i+2]);
                    no>>(n);
                    n-=qq;

                    string s=to_string(n);
                    // cout<<s<<" quan "<<endl;
                    row[i+2]=s;
                    break;
                }
                r++;

            }
            //    cout<<endl

        }

        mpp[s]=row;

    }
    fin.close();

    ofstream fout;
    fout.open("goods.txt", ios::out);
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


void search_org(string user_n, int taka, string user_bank)
{
    show_all_org();
    cout<<endl;
    cout<<"\tEnter an Organization Name:"<<endl;
    string org;
    cin>>org;
    organization g;
    int r=g.check_org(org);
    if(r==0)
    {
        g.show_goods(org);
L:
        cout<<"\t\t\tEnter an option\n\t\t1.See Conversation\n\t\t2.Buy products\n\t\t3.Return"<<endl;
        int cha=0;
        cin>>cha;
        if(cha==2)
        {

            cout<<"\tTo buy a product  -   Enter the serial number of the product"<<endl;
            cout<<"\tNot To buy        -   Enter 0"<<endl;
            int n;
            cin>>n;
            if(n==0)
                return ;
            else
            {
                int quan=0;
                int f=g.get_price(org,n-1,&quan);
                if(f==-1)
                {
                    cout<<"\tWrong Option"<<endl;
                    goto L;
                }
                else
                {

                    cout<<"\tHow many do you want to buy?"<<endl;
                    int am;
                    cin>>am;

                    int total=am*f;
                    if(total>taka)
                    {
                        cout<<"\tYou don't have enough money\n"<<endl;
                        goto L;
                    }
                    else if(quan<am)
                    {
                        cout<<"\tThers has not so much\n"<<endl;
                        goto L;
                    }
                    else
                    {
                        taka-=total;
                        bank_update(user_bank,taka);
                        string bank_ac;
                        string g=get_owner_name(org);
                        bank b;
                        int tak=b.get_money(g,&bank_ac);
                        tak+=total;
                        bank_update(bank_ac,tak);

                        int t=am;
                        goods_update(org, n-1, t);

                        cout<<"\tDo you want to buy more?\n\t\t1.Yes\n\t\t2.No"<<endl;
                        int r;
                        cin>>r;
                        if(r==1)
                            goto L;
                        else
                            return;
                    }

                }


            }
        }
        else if(cha==1)
        {
            conversation con;
            con.view_msg(org,2);
            cout<<"\tIf you want to reply?\n\t\t1.Yes\n\t\t2.No"<<endl;
            int r;
            cin>>r;
            if(r==1)
                con.user_to_org_conversation(user_n,org);
            goto L;
        }
        else
            return;

    }
    else
    {
        cout<<"\tThis organization name doesn't exits\n"<<endl;
        return;
    }
}
