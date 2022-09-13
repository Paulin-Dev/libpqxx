#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <fstream>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {

    try {
        connection db(R"""(
        dbname = database_name
        user = postgres
        password = password
        hostaddr = 127.0.0.1
        port = 5432
        )""");
        if (db.is_open()) {
            cout << "Opened Database successfully : " << db.dbname() << endl;
        } else {
            cout << "Can't open Database" << endl;
            return 1;
        }
        
        /*
        string sql;
        
        fsteam f("queries/base.sql", fsteam::in);
        getline(f, sql, '\0');
        work W(db);
        W.exec(sql)
        W.commit()      // 	W.abort()
        
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
