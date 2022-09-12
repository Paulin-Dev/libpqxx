#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {

    try {
        connection db("\
        dbname = database_name \
        user = postgres \
        password = password \
        hostaddr = 127.0.0.1 \
        port = 5432 \
        ");
        if (db.is_open()) {
            cout << "Opened Database successfully : " << db.dbname() << endl;
        } else {
            cout << "Can't open Database" << endl;
            return 1;
        }
        
        /*
        char * sql;
        
        sql = "";
        work W(db);
        W.exec(sql)
        
        or
        
        sql = "SELECT * FROM ";
        nontransaction N(db);
        result R(N.exec(sql));
        for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
            cout << "ID=" << c[0] << endl;
        }
        */

        db.disconnect();
        return 0;

    } catch (const std::exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

}
