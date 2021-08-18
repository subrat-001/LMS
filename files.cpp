#include "files.h"
using namespace std;
void files:: initmax(int code)
{
    if (code==1)
    {
        int i=0;
        while(i<sifi_size)
        {
            msifi_quantity[i]=sifi_quantity[i];
           // cout<<msifi_quantity[i]<<"	"<<sifi_quantity[i]<<endl;
            i++;
        }
    }
    else if (code==2)
    {
        int i=0;
        while(i<fan_size)
        {
            mfantasy_quantity[i]=fantasy_quantity[i];
          //  cout<<mfantasy_quantity[i]<<"	"<<fantasy_quantity[i]<<endl;
            i++;
        }
    }
    else if (code==3)
    {
        int i=0;
        while(i<sh_size)
        {
            msh_quantity[i]=sh_quantity[i];
           // cout<<msh_quantity[i]<<"	"<<sh_quantity[i]<<endl;
            i++;
        }
    }
    else if (code==4)
    {
        int i=0;
        while(i<philo_size)
        {
            mphilo_quantity[i]=philo_quantity[i];
           // cout<<mphilo_quantity[i]<<"	"<<philo_quantity[i]<<endl;
            i++;
        }
    }
    else if (code==5)
    {
        int i=0;
        while(i<bio_size)
        {
            mbio_quantity[i]=bio_quantity[i];
           // cout<<mbio_quantity[i]<<"	"<<bio_quantity[i]<<endl;
            i++;
        }
    }
}
void files::addsh(string bookname,int quantity)
{
    ofstream fout;
    fout.open("self help.txt",ios_base::app);
    fout<<endl<<bookname<<","<<quantity;
    fout.close();
    //msh_quantity[sh_size]=quantity;
    sh();
}

void files::addphilo(string bookname,int quantity)
{
    ofstream fout;
    fout.open("philo.txt",ios_base::app);
    fout<<endl<<bookname<<","<<quantity;
    fout.close();
    //mphilo_quantity[philo_size]=quantity;
    philo();
}

void files::addsifi(string bookname,int quantity)
{
	cout<<"begin adding";
    ofstream fout;
    fout.open("sifi.txt",ios_base::app);
    fout<<endl<<bookname<<","<<quantity;
    fout.close();
    cout<<"we are right here";
   // msifi_quantity[sifi_size]=quantity;
    cout<<"we are here";
    sifi();
    cout<<"added and reloaded";
}

void files::addbio(string bookname,int quantity)
{
    ofstream fout;
    fout.open("bio.txt",ios_base::app);
    fout<<endl<<bookname<<","<<quantity;
    fout.close();
    mbio_quantity[bio_size]=quantity;
    bio();
}

void files::addfan(string bookname,int quantity)
{
    ofstream fout;
    fout.open("fantasy.txt",ios_base::app);
    fout<<endl<<bookname<<","<<quantity;
    fout.close();
    //mfantasy_quantity[fan_size]=quantity;
    fantasy();
}

void files:: appendsh(int change,int bookno)
{
    ofstream fout;
    fout.open("self help.txt");
    int run=0;
    int y=bookno-1;
    while (run<sh_size)
    {
    	//cout<<msh_quantity[run];
        fout<<sh_books[run]<<",";
      //cout<<sh_books[run]<<",";
        if(run==sh_size-1)
        {
            if (y==run)
        {

	
            if (change==1)
            {fout<<(sh_quantity[run]+1);}
            else if(change==0 && sh_quantity[run]>0)
            {fout<<(sh_quantity[run]-1);}
			else
			{fout<<sh_quantity[run];}
        }
        else
            {fout<<sh_quantity[run];}
        break;

        }
        else{
        if (y==run)
        {


            if (change==1 )
            {fout<<(sh_quantity[run]+1)<<endl;}
           else if(change==0 && sh_quantity[run]>0)
            {fout<<(sh_quantity[run]-1)<<endl;}
            else
            {fout<<sh_quantity[run]<<endl;}

        }
        else
            {fout<<sh_quantity[run]<<endl;}
        }
        run++;
    }
    fout.close();
    sh();

}

void files:: appendfan(int change,int bookno)
{
    ofstream fout;
    fout.open("fantasy.txt");
    int run=0;
    int y=bookno-1;
    while (run<fan_size)
    {
        fout<<fantasy_books[run]<<",";
        if(run==fan_size-1)
        {
          if (y==run)
        {


            if (change==1 )
            {fout<<(fantasy_quantity[run]+1);}
            else if(change==0 && fantasy_quantity[run]>0)
            {fout<<(fantasy_quantity[run]-1);}
			else
			{fout<<fantasy_quantity[run];}

        }
        else
            {fout<<fantasy_quantity[run];}
        }
        else{
        if (y==run)
        {


            if (change==1)
            {fout<<(fantasy_quantity[run]+1)<<endl;}
           else if(change==0 && fantasy_quantity[run]>0)
            {fout<<(fantasy_quantity[run]-1)<<endl;}
            else
            {fout<<fantasy_quantity[run]<<endl;}
        }
        else
            {fout<<fantasy_quantity[run]<<endl;}
        }
        run++;
    }
    fout.close();
    fantasy();
}

void files:: appendbio(int change,int bookno)
{
	//cout<<"bio opened for appending";

    ofstream fout;
    fout.open("bio.txt");
    int run=0;
    int y=bookno-1;
    while (run<bio_size)
    {
        fout<<bio_books[run]<<",";
        if(run==bio_size-1)
        {
            if(y==run)
            {
			if (change==1)
            {fout<<(bio_quantity[run]+1);}
            else if(change==0 && bio_quantity[run]>0)
            {fout<<(bio_quantity[run]-1);}
			else
			{fout<<bio_quantity[run];}
        }
        else
            {fout<<bio_quantity[run];}
            break;

        }
        else
        {

        if (y==run)
        {

 if (change==1 )
            {fout<<(bio_quantity[run]+1)<<endl;}
           else if(change==0 && bio_quantity[run]>0)
            {fout<<(bio_quantity[run]-1)<<endl;}
            else
            {fout<<bio_quantity[run]<<endl;}
        }
        else
            {fout<<bio_quantity[run]<<endl;}
        }
        run++;
    }
    fout.close();
    bio();

}
void files:: appendphilo(int change,int bookno)
{
    ofstream fout;
    fout.open("philo.txt");
    int run=0;
    int y=bookno-1;
    while (run<philo_size)
    {
        fout<<philo_books[run]<<",";
        if (run==philo_size-1)
        {
            if (y==run)
        {
			if (change==1)
            {fout<<(philo_quantity[run]+1);}
            else if(change==0 && philo_quantity[run]>0)
            {fout<<(philo_quantity[run]-1);}
			else
			{fout<<philo_quantity[run];}

        }
        else
            {fout<<philo_quantity[run];}
        }
        else{
        if (y==run)
        {

 if (change==1)
            {fout<<(philo_quantity[run]+1)<<endl;}
           else if(change==0 && philo_quantity[run]>0)
            {fout<<(philo_quantity[run]-1)<<endl;}
            else
            {fout<<philo_quantity[run]<<endl;}
        }
        else
            {fout<<philo_quantity[run]<<endl;}
        }
        run++;
    }
    fout.close();
    philo();
}
void files:: appendsifi(int change,int bookno)
{
    ofstream fout;
    fout.open("sifi.txt");
    int run=0;
    int y=bookno-1;
    while (run<sifi_size)
    {
        fout<<sifi_books[run]<<",";
        if (run==sifi_size-1)
        {
            if (y==run)
        {
			if (change==1)
            {fout<<(sifi_quantity[run]+1);}
            else if(change==0 && sifi_quantity[run]>0)
            {fout<<(sifi_quantity[run]-1);}
			else
			{fout<<sifi_quantity[run];}

        }
        else
            {fout<<sifi_quantity[run];}
        }
        else{
        if (y==run)
        {

 if (change==1)
            {fout<<(sifi_quantity[run]+1)<<endl;}
           else if(change==0 && sifi_quantity[run]>0)
            {fout<<(sifi_quantity[run]-1)<<endl;}
            else
            {fout<<sifi_quantity[run]<<endl;}
        }
        else
            {fout<<sifi_quantity[run]<<endl;}
        }
        run++;
    }
    fout.close();
    sifi();
}

void files:: displayfan()
    {
            int k=0;
            while(k<fan_size){cout<<fantasy_books[k]<<"    "<<fantasy_quantity[k]<<endl;k++;}

    }
void files ::fantasy()
{
        ifstream fin;
    fin.open("fantasy.txt");
    int s=0;
    string blank;
    while(fin){s++;getline(fin,blank);if (!fin.good()){ break;}}//to count the number of books in this text file to initialize array with dynanmic memory
    fan_size=s;
    fin.close();
    fin.open("fantasy.txt");

    int i,mark=0;
    string word(""),q,line,check=",";
    int j=0;
    while (fin)//loops till end of the file
    {
        string apple;
        getline(fin,line);
        mark=0;
        word="";
        int quan(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else
            {
                if (mark==0)
                {
                    word+=q;
                }
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan=quan*10+u;


                }
            }

          a++;

        }
        fantasy_books[j]=word;
        fantasy_quantity[j]=quan;
        j++;
        if (!fin.good()){ break;}//when the last line from file is extracted,this line breaks out from the loop
    }
    fin.close();
    }

    void files:: displaysh()
    {
            int k=0;
            while(k<sh_size){cout<<sh_books[k]<<"    "<<sh_quantity[k]<<endl;k++;}

    }
void files ::sh()
{
        ifstream fin;
    fin.open("self help.txt");
    int s=0;
    string blank;
    while(fin){s++;getline(fin,blank);if (!fin.good()){ break;}}//to count the number of books in this text file to initialize array with dynanmic memory
    sh_size=s;
    fin.close();
    fin.open("self help.txt");

    int i,mark=0;
    string word(""),q,line,check=",";
    int j=0;
    while (fin)//loops till end of the file
    {
        string apple;
        getline(fin,line);
        mark=0;
        word="";
        int quan(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else
            {
                if (mark==0)
                {
                    word+=q;
                }
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan=quan*10+u;


                }
            }

          a++;

        }
        sh_books[j]=word;
        sh_quantity[j]=quan;
        j++;
        if (!fin.good()){ break;}//when the last line from file is extracted,this line breaks out from the loop
    }
    fin.close();
    }
void files:: displayphilo()
    {
            int k=0;
            while(k<philo_size){cout<<philo_books[k]<<"    "<<philo_quantity[k]<<endl;k++;}
            //cout<<fantasy_books[1]<<" "<<fantasy_quantity[1]<<" "<<fan_size;
    }
void files ::philo()
{
	//cout<<"show this shit";
        ifstream fin;
    fin.open("philo.txt");
    int s=0;
    string blank;
    while(fin){s++;getline(fin,blank);if (!fin.good()){ break;}}//to count the number of books in this text file to initialize array with dynanmic memory
    philo_size=s;
    fin.close();
    fin.open("philo.txt");

    int i,mark=0;
    //string fantasy_books[fan_size];
    string word(""),q,line,check=",";
    int j=0;
    //cout<<"we here";
    while (fin)//loops till end of the file
    {
    //	cout<<"		loop this shit";
        string apple;
        getline(fin,line);
        mark=0;
        word="";
        int quan(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else
            {
                if (mark==0)
                {
                    word+=q;
                }
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan=quan*10+u;


                }
            }

          a++;

        }
        philo_books[j]=word;
        philo_quantity[j]=quan;
        j++;
        if (!fin.good()){ break;}//when the last line from file is extracted,this line breaks out from the loop
    }
    fin.close();
    //cout<<"ending this shit";
    //int k=0;
    //while(k<s){cout<<fantasy_books[k]<<"    "<<fantasy_quantity[k]<<endl;k++;}
    }
void files:: displaysifi()
    {
            int k=0;
            while(k<sifi_size){cout<<sifi_books[k]<<"    "<<sifi_quantity[k]<<endl;k++;}
    }
void files ::sifi()
{
        ifstream fin;
    fin.open("sifi.txt");
    int s=0;
    string blank;
    while(fin){s++;getline(fin,blank);if (!fin.good()){ break;}}//to count the number of books in this text file to initialize array with dynanmic memory
    sifi_size=s;
    fin.close();
    fin.open("sifi.txt");

    int i,mark=0;
    string word(""),q,line,check=",";
    int j=0;
    while (fin)//loops till end of the file
    {
        string apple;
        getline(fin,line);
        mark=0;
        word="";
        int quan(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else
            {
                if (mark==0)
                {
                    word+=q;
                }
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan=quan*10+u;


                }
            }

          a++;

        }
        sifi_books[j]=word;
        sifi_quantity[j]=quan;
        j++;
        if (!fin.good()){ break;}//when the last line from file is extracted,this line breaks out from the loop
    }
    fin.close();
    }

void files:: displaybio()
    {
            int k=0;
            while(k<bio_size){cout<<bio_books[k]<<"    "<<bio_quantity[k]<<endl;k++;}
            //cout<<fantasy_books[1]<<" "<<fantasy_quantity[1]<<" "<<fan_size;
    }
void files ::bio()
{
        ifstream fin;
    fin.open("bio.txt");
    int s=0;
    string blank;
    while(fin){s++;getline(fin,blank);if (!fin.good()){ break;}}//to count the number of books in this text file to initialize array with dynanmic memory
    bio_size=s;
    fin.close();
    fin.open("bio.txt");

    int i,mark=0;
    //string fantasy_books[fan_size];
    string word(""),q,line,check=",";
    int j=0;
    while (fin)//loops till end of the file
    {
        string apple;
        getline(fin,line);
        mark=0;
        word="";
        int quan(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else
            {
                if (mark==0)
                {
                    word+=q;
                }
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan=quan*10+u;


                }
            }

          a++;

        }
        bio_books[j]=word;
        bio_quantity[j]=quan;
        j++;
        if (!fin.good()){ break;}//when the last line from file is extracted,this line breaks out from the loop
    }
    fin.close();
    //int k=0;
    //while(k<s){cout<<fantasy_books[k]<<"    "<<fantasy_quantity[k]<<endl;k++;}
}
void files ::lending()
{
        ifstream fin;
    fin.open("lent.txt");
    int s=0;
    string blank;
    while(fin){s++;getline(fin,blank);if (!fin.good()){ break;}}//to count the number of books in this text file to initialize array with dynanmic memory
    lending_size=s;
    fin.close();
    fin.open("lent.txt");

    int i,mark=0;
    //string fantasy_books[fan_size];
    string word(""),q,line,check=",",check1("|");
    int j=0;
    while (fin)//loops till end of the file
    {
        string apple,ball,cat;
        getline(fin,line);
        mark=0;
        string word="";
        int quan_indi(0),quan_code(0),a(0);
        i=line.length();
        while(a<i)
        {
            q=line[a];
            if (q==check)//quantity and book's name is seperated by comma
            {
                mark=1;
            }
            else if (q==check1)
            {
            	mark=2;
			}
            else
            {
                if (mark==0)
                {
                    ball=q;
                    stringstream a2(ball);//used to convert string to intiger
                    int v=0;
                    a2>>v;
                    quan_indi=quan_indi*10+v;
                    //cout<<endl<<quan_indi<<endl;
                }
                else if (mark==2)
                {
                	word+=q;
				}
                else
                {
                    apple=q;
                    stringstream a1(apple);//used to convert string to intiger
                    int u=0;
                    a1>>u;
                    quan_code=quan_code*10+u;


                }
            }

          a++;

        }
       
        lending_indicator[j]=quan_indi;
       
        lending_bookcode[j]=quan_code;
        lending_rollnumber[j]=word;
  
        j++;
        if (!fin.good()){ break;}//when the last line from file is extracted,this line breaks out from the loop
    }
    fin.close();

}
void files::addlending(int indi,int code,string rn)
{
    ofstream fout;
    fout.open("lent.txt",ios_base::app);
    if (lending_size==0)
    {
    	fout<<indi<<","<<code<<"|"<<rn;
	}
	else
    {
	fout<<endl<<indi<<","<<code<<"|"<<rn;
    fout.close();
	}
	//msh_quantity[sh_size]=quantity;
    lending();
}
void files:: appendlending(int indi,int code,string rn)
{
    ofstream fout;
    fout.open("lent.txt");
    int run=0;
    int mark=0;
    while (run<lending_size)
    {
    	
		if(mark==0)
		{
		
    	if(lending_indicator[run]==indi && lending_bookcode[run]==code &&lending_rollnumber[run]==rn)
    	{mark=1;goto skip;}
    	}
    	
        if(run==0)
        {
        

            fout<<lending_indicator[run]<<","<<lending_bookcode[run]<<"|"<<lending_rollnumber[run];
        }
        else{
       			
        	
               fout<<endl<<lending_indicator[run]<<","<<lending_bookcode[run]<<"|"<<lending_rollnumber[run];
        }
        skip:
        run++;
    }
    fout.close();
    lending();
}
void files::activity(string written)
{
    ofstream fout;
    fout.open("activity.txt",ios_base::app);
   
	
	fout<<endl<<written;
    fout.close();
	
}
void files::clearactivity()
{
    ofstream fout;
    fout.open("activity.txt");
    fout<<"Activity Log:";
    fout.close();
}
