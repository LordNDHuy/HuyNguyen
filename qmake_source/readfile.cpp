#include "readfile.h"
#include <sstream>
readfile::readfile()
{

}

void readfile::getbookdatabase(QStringList *book, QStringList *author){
    std::ifstream dictfile;
    dictfile.open(".bookdatabase");
    std::string tempname, tempauthor;
    if (dictfile.is_open()){
        while(getline(dictfile,tempname)&& tempname!=""){
            getline(dictfile,tempauthor);
            //rstd::cout<<temp<<std::endl<<tempauthor<<std::endl;
            QString str,str1;
            str = QString::fromStdString(tempname);
            book->push_back(str);
            str1 = QString::fromStdString(tempauthor);
            author->push_back(str1);
            //std::cout<<name.takeAt(0).toUtf8().constData()<<std::endl;

        }
    }
    dictfile.close();
    for(int i = 0; i < book->size();i++){
        //std::cout << book->at(i).toUtf8().constData()<<std::endl;
    }
}

//////
void readfile::get_book_database(QStringList *book, QStringList *author, QStringList *year){
    std::fstream file;
    file.open(".books");
    std::string book_temp;
    while(getline(file,book_temp)){
        std::istringstream ss(book_temp);
        std::string token;
        QString str;
        std::getline(ss, token, '#');
        str = QString::fromStdString(token);
        book->push_back(str);
        std::getline(ss, token, '#');
        str = QString::fromStdString(token);
        author->push_back(str);
        std::getline(ss, token, '#');
        str=QString::fromStdString(token);
        year->push_back(str);
    }
    file.close();
}
void readfile::write_book_database(QStringList *book, QStringList *author, QStringList *year){
    std::fstream file;
    file.open(".books");
    std::string book_temp;
    for(int i = 0; i<book->count();i++){
        file<<book->at(i).toStdString()<<'#'<<author->at(i).toStdString()<<'#'<<year->at(i).toStdString()<<'\n';
    }
    file.close();
}

//get booklist as qtreewidgetitem to show in qtreewidget
std::vector<QStringbook> readfile::getbook(){
    //get data from file
    std::ifstream dictfile;
    dictfile.open(".huynguyen");
    std::vector<QStringbook> book;
    int k=0;
    if (dictfile.is_open()){
        std::string tempname,tempday;
        while(getline(dictfile,tempname)&&(tempname!="")){
            QStringbook tempbook;
            QString temp= QString::fromStdString(tempname);
            tempbook.name.push_back(temp);
            getline(dictfile,tempday);
            temp= QString::fromStdString(tempday);
            tempbook.b_day.push_back(temp);
            getline(dictfile,tempday);
            temp= QString::fromStdString(tempday);
            tempbook.r_day.push_back(temp);
            book.push_back(tempbook);
            //std::cout << author.value(k).toUtf8().constData()<<std::endl;
            k++;
            //std::cout << temp<<std::endl;
        }
    }
    dictfile.close();
    return book;
/*
    //create qlist
    QList<QTreeWidgetItem*> booklist;
    for(int i=0;i>book;i--)
    {
        QTreeWidgetItem* name = new QTreeWidgetItem();
        QString temp;
        temp= QString::fromStdString(book[i].name);
        name->setText(0,temp);
        temp.fromStdString(book[i].b_day);
        name->setText(1,temp);
        temp.fromStdString(book[i].r_day);
        name->setText(2,temp);
        booklist.push_back(name);
        std::cout <<book[i].name<<std::endl<<
                    book[i].b_day<<std::endl<<
                    book[i].r_day<<std::endl;
        //std::cout <<"huynguyen"<< *booklist.at(0)->text(0).toUtf8().constData();
        //std::cout << book[i].name.toUtf8().constData();
        //ui->treeWidget->insertTopLevelItem(0,name);
    }
*/
}
