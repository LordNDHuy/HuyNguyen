#include "searchbook.h"
#include "ui_searchbook.h"
#include "readfile.h"
#include <QHBoxLayout>
#include "logon.h"
#include "login.h"
#include <QMessageBox>
#include <sstream>
#include "book_edit.h"
#include "librarian.h"
searchbook::searchbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchbook)
{
    ui->setupUi(this);
    this->setWindowTitle("Search books");
    // initilzer something
    initialize();
}

void searchbook::initialize(){
    /// addd boook
    readfile file;
    file.get_book_database(&book,&author,&year);
    ui->bookname->addItems(book);
    ui->author->addItems(author);
    ui->year->addItems(year);
    ///addd combo box search by name or author
    ///
    // some feature for Qlist
    ui->bookname->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->author->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            //hover for lits, and color
    QPalette palette;
    palette.setColor(QPalette::Highlight,QColor(222,174,59));
    ui->bookname->setPalette(palette);
    ui->bookname->setMouseTracking(true);
    ui->author->setPalette(palette);
    ui->author->setMouseTracking(true);
    ui->year->setPalette(palette);
    ui->year->setMouseTracking(true);
    ui->bookname->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->author->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");
    ui->year->setStyleSheet("QListWidget::item:hover {background: #F0C674;}");


    /// scroll bar connect
    connect(ui->year->verticalScrollBar(),&QSlider::valueChanged,ui->author->verticalScrollBar(),&QSlider::setValue);
    connect(ui->year->verticalScrollBar(),&QSlider::valueChanged,ui->bookname->verticalScrollBar(),&QSlider::setValue);
    connect(ui->bookname->verticalScrollBar(),&QSlider::valueChanged,ui->author->verticalScrollBar(),&QSlider::setValue);
    connect(ui->bookname->verticalScrollBar(),&QSlider::valueChanged,ui->year->verticalScrollBar(),&QSlider::setValue);
    connect(ui->author->verticalScrollBar(),&QSlider::valueChanged,ui->bookname->verticalScrollBar(),&QSlider::setValue);
    connect(ui->author->verticalScrollBar(),&QSlider::valueChanged,ui->year->verticalScrollBar(),&QSlider::setValue);
    ui->bookname->verticalScrollBar()->hide();
    ui->author->verticalScrollBar()->hide();


    //add search method box
    QStringList search_method;
    search_method <<"Search By Name"<<"Search By Author"<<"Search By Year";
    ui->searchmethod->addItems(search_method);
    //separate into pages
    ui->spinBox->setValue(1);
}

void searchbook::show_window(std::string username){
    this->show();


    ///
    searchbook::username = username;
    if(username == "anno"){
        ui->Login->show();
        ui->user_page->hide();
        ui->loginstatus->hide();
        ui->edit->hide();
    }else if(username == "admin"){
        ui->borrow->hide();
        ui->edit->show();
        ui->Logon->hide();
        ui->Login->hide();
        QStringList user_page ;
        std::cout << searchbook::username<<std::endl;
        user_page<<"admin"<<("Own Page")<<("Log out");
        ui->user_page->addItems(user_page);
        ui->user_page->setItemData(0, QBrush(Qt::red), Qt::BackgroundColorRole);
        //ui->loginstatus->show();
        const QString quser= QString::fromStdString(username);
        //ui->loginstatus->setText(quser);
        std::cout << username<<std::endl;
    }else{
        ui->Login->hide();
        ui->user_page->show();
        ui->edit->hide();
        QStringList user_page ;
        std::cout << searchbook::username<<std::endl;
        user_page<<QString::fromStdString(searchbook::username)<< QString::fromStdString("Own Page")<<QString::fromStdString("Log out");
        ui->user_page->addItems(user_page);
        ui->user_page->setItemData(0, QBrush(Qt::red), Qt::BackgroundColorRole);
        //ui->loginstatus->show();
        const QString quser= QString::fromStdString(username);
        //ui->loginstatus->setText(quser);
        std::cout << username<<std::endl;
    }

}

searchbook::~searchbook()
{
    delete ui;
}

void searchbook::on_bookname_clicked(const QModelIndex &index)
{
    ui->author->setCurrentRow(index.row());
    ui->year->setCurrentRow(index.row());
}

void searchbook::on_author_clicked(const QModelIndex &index)
{
    ui->bookname->setCurrentRow(index.row());
    ui->year->setCurrentRow(index.row());
}

void searchbook::on_year_clicked(const QModelIndex &index)
{
    ui->bookname->setCurrentRow(index.row());
    ui->author->setCurrentRow(index.row());
}

void searchbook::on_searchbutton_clicked()
{
    ui->spinBox->setValue(1);
    unsigned int book_size = book.size();
    bool *check = new bool[book_size];
    memset(check,false,book_size);
    QRegExp Search_String(ui->searchbox->text(), Qt::CaseInsensitive,QRegExp::Wildcard);
    ui->bookname->clear();

    ui->author->clear();
    ui->year->clear();
    unsigned int pass;
    if((ui->searchmethod->currentIndex()==0)){
        pass = 0;
        QStringList filterbook = book.filter(Search_String);
        QStringList author_fil, year_fil;
        /*for(int i = 0; i <filterbook.size();i++){
            //std::cout << filterauthor.at(i).toUtf8().constData();
            for(int j=0;j <author.size();j++){
                if((filterbook.at(i) == book.at(j))&&(check[j]==false)){
                    //std::cout << filterauthor.at(i).toUtf8().constData()<<"   - "<<book.at(j).toUtf8().constData()<<std::endl;
                    author_fil.push_back(author.at(j));
                    year_fil.push_back(year.at(j));
                    check[j]= true;
                    break;
                }
            }
        }*/
        searchbook::filter_book(&filterbook,&author_fil,&year_fil,pass);

        ui->bookname->addItems(filterbook);
        ui->author->addItems(author_fil);
        ui->year->addItems(year_fil);
    }else if(ui->searchmethod->currentIndex()==1){
        pass = 1;
        QStringList filterauthor = author.filter(Search_String);
        QStringList book_fil, year_fil;
        searchbook::filter_book(&filterauthor,&book_fil,&year_fil,pass);
        /*for(int i = 0; i <filterauthor.size();i++){
            //std::cout << filterauthor.at(i).toUtf8().constData();
            for(int j=0;j <author.size();j++){
                if((filterauthor.at(i) == author.at(j))&&(check[j]==false)){
                    //std::cout << filterauthor.at(i).toUtf8().constData()<<"   - "<<book.at(j).toUtf8().constData()<<std::endl;
                    book_fil.push_back(book.at(j));
                    year_fil.push_back(year.at(j));
                    check[j]= true;
                    break;
                }
            }
        }*/
        ui->author->addItems(filterauthor);
        ui->bookname->addItems(book_fil);
        ui->year->addItems(year_fil);
    }else{
        pass = 2;
        QStringList filteryear = year.filter(Search_String);
        QStringList book_fil, author_fil;
        searchbook::filter_book(&filteryear,&book_fil,&author_fil,pass);
        /*for(int i = 0; i <filteryear.size();i++){
            //std::cout << filterauthor.at(i).toUtf8().constData();
            for(int j=0;j <author.size();j++){
                if((filteryear.at(i) == year.at(j))&&(check[j]==false)){
                    //std::cout << filterauthor.at(i).toUtf8().constData()<<"   - "<<book.at(j).toUtf8().constData()<<std::endl;
                    book_fil.push_back(book.at(j));
                    author_fil.push_back(author.at(j));
                    check[j]= true;
                    break;
                }
            }
        }*/
        ui->year->addItems(filteryear);
        ui->bookname->addItems(book_fil);
        ui->author->addItems(author_fil);
    }
}

void searchbook::on_searchbox_returnPressed()
{
    searchbook::on_searchbutton_clicked();
}



void searchbook::on_Login_clicked()
{
    login *login_window = new login;
    this->close();
    login_window->show();
    login_window->move(400,250);
}


void searchbook::on_Logon_clicked()
{
    logon *log_on = new logon;
    this->close();
    log_on->show();
    log_on->move(400,250);
}

void searchbook::on_borrow_clicked()

{
    if(searchbook::username == "anno"){
        QMessageBox message(QMessageBox::Information, "Login Request",
                                QObject::tr("Please Login to borrow books"),
                                QMessageBox::NoButton ,
                                this, Qt::FramelessWindowHint);
            message.show();
            message.move(400,350);

            message.exec();
    }
}

void searchbook::on_user_page_currentIndexChanged(int index)
{
    if(index != 0){
        if(index ==1){
            if(ui->user_page->itemText(0) == "admin"){
                librarian *libra = new librarian;
                libra->show();
                this->close();
            }else{
                userpage *userpage_window = new userpage;
                userpage_window->show();
                ui->user_page->setCurrentIndex(0);
            }
        }else{
            this->close();
            searchbook *search = new searchbook;
            search->move(200,100);

            search->show_window("anno");

        }
    }
}
/// filter book, author and yeaar. no clue why it works directly, but through function.

void searchbook::filter_book(QStringList *filtered, QStringList *list_1, QStringList *list_2, unsigned int pass){
    unsigned int book_size = book.size();
    bool *check = new bool[book_size];
    memset(check,false,book_size);
    if((ui->searchmethod->currentIndex()==0)){
        pass = 0;
        QStringList author_fil, year_fil;
        for(int i = 0; i <filtered->size();i++){
            //std::cout << filterauthor.at(i).toUtf8().constData();
            for(int j=0;j <author.size();j++){
                if((filtered->at(i) == book.at(j))&&(check[j]==false)){
                    //std::cout << filterauthor.at(i).toUtf8().constData()<<"   - "<<book.at(j).toUtf8().constData()<<std::endl;
                    list_1->push_back(author.at(j));
                    list_2->push_back(year.at(j));
                    check[j]= true;
                    break;
                }
            }
        }
    }else if(ui->searchmethod->currentIndex()==1){
        pass = 1;
        QStringList book_fil, year_fil;
        //searchbook::filter_book(&filterauthor,&book_fil,&year_fil,pass);
        for(int i = 0; i <filtered->size();i++){
            //std::cout << filterauthor.at(i).toUtf8().constData();
            for(int j=0;j <author.size();j++){
                if((filtered->at(i) == author.at(j))&&(check[j]==false)){
                    //std::cout << filterauthor.at(i).toUtf8().constData()<<"   - "<<book.at(j).toUtf8().constData()<<std::endl;
                    list_1->push_back(book.at(j));
                    list_2->push_back(year.at(j));
                    check[j]= true;
                    break;
                }
            }
        }
    }else{
        pass = 2;
        QStringList book_fil, author_fil;
        for(int i = 0; i <filtered->size();i++){
            //std::cout << filterauthor.at(i).toUtf8().constData();
            for(int j=0;j <author.size();j++){
                if((filtered->at(i) == year.at(j))&&(check[j]==false)){
                    //std::cout << filterauthor.at(i).toUtf8().constData()<<"   - "<<book.at(j).toUtf8().constData()<<std::endl;
                    list_1->push_back(book.at(j));
                    list_2->push_back(author.at(j));
                    check[j]= true;
                    break;
                }
            }
        }

    }
}

void searchbook::on_spinBox_valueChanged(int arg1)
{
    enum search_method {by_name=0,by_author, by_year};
    QStringList book_list,author_list,year_list;
    QString Search_String = ui->searchbox->text();
    switch(ui->searchmethod->currentIndex()){
        case by_name:{
            book_list= book.filter(Search_String);
            std::cout << book_list.count()<<std::endl;
            QStringList author_fil, year_fil;
            searchbook::filter_book(&book_list,&author_fil,&year_fil,by_name);
            author_list = author_fil;
            year_list   = year_fil;
            break;
        }
        case by_author:{
            author_list = author.filter(Search_String);
            QStringList book_fil, year_fil;
            searchbook::filter_book(&author_list,&book_fil,&year_fil,by_author);
            book_list = book_fil;
            year_list = year_fil;
            break;
        }
        case by_year:{
            year_list= year.filter(Search_String);
            QStringList book_fil, author_fil;
            searchbook::filter_book(&year_list,&book_fil,&author_fil,by_year);
            book_list = book_fil;
            author_list = author_fil;
            break;
        }
    }

    if(book_list.size() ==0){
        ui->spinBox->setValue(1);

    }else{
        int result_page  =20;
        if(arg1 ==0) {
            ui->spinBox->setValue(1);

        }else{
            unsigned  int max;
            if((book_list.size() % int(result_page) !=0) ){
                max = book_list.size()/result_page +1;
            }else max = book_list.size()/result_page ;

            if(arg1 > max){
                ui->spinBox->setValue(1);
                std::stringstream  a;
                a<<max;
                std::string caution = "The Maximum page is " + a.str();
                QString caut;
                caut = QString::fromStdString(caution);
                QMessageBox message(QMessageBox::Information, "Page Overloaded",
                                        caut,
                                        QMessageBox::NoButton ,
                                        this, Qt::FramelessWindowHint);
                    message.show();
                    message.move(400,350);

                    message.exec();
            }else{
                unsigned int init_index = (arg1-1)*result_page, term_index;
                if(arg1 == max) term_index = book_list.size();
                else term_index = (arg1)*result_page;
                ui->bookname->clear();
                ui->author->clear();
                ui->year->clear();
                for(int i= init_index;i<term_index;i++){
                    ui->bookname->addItem(book_list.at(i));
                    ui->author->addItem(author_list.at(i));
                    ui->year->addItem(year_list.at(i));
                }
            }
        }
    }
}


void searchbook::on_edit_clicked()
{
    book_edit *edit = new book_edit;
    edit->edit(&book,&author,&year);
    edit->move(200,150);
    this->close();
}
