#ifndef REQUEST_MODULE
#define REQUEST_MODULE

#include <vector>
#include <string>

enum ticket_respond{SUCCESSFUL, OUT_OF_BOOK};

const std::string REQFILE = "TicketSubmissions.txt";

struct Ticket{
    unsigned int id;
    unsigned int accountID;
    unsigned int bookID;
    bool pending;
    bool accepted;
};

class Request{
protected:
    static std::vector<Ticket> TicketsList;
public:
    void updateList();
    void saveList() const;
    void DenyTicket(unsigned int TicketID);
    int  RequestBook(unsigned int accountID, unsigned int bookID);
    void AcceptTicket(unsigned int TicketID);
    std::vector<Ticket> returnList() const;
    std::vector<std::string> fetchMessages(unsigned int accountID);
};

#endif