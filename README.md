# Connect to a PostgreSQL Database in C++
*Tested on Debian 10.2.1 / Ubuntu 22.04.1*

<br>

Keep your Debian system **up-to-date** :

```shell
sudo apt update
```
```shell
sudo apt upgrade
```
<br>

## Install Oh My ZSH (*Optional*)

```shell
sudo apt install zsh git wget
```
```shell
sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"
```

**Open** .zshrc file with `nano .zshrc` and **change** :
```
ZSH_THEME="norm"
```
**Exit** nano and **refresh** with `source .zshrc`

<br>

## Install PostgreSQL

Install **packages** :
```shell
sudo apt install build-essential libpqxx-dev postgresql postgresql-contrib
```

Start the **service** :
```shell
sudo service postgresql start
```

Log in with the **postgres account** :
```shell
sudo -i -u postgres
```

Create the **database** :
```shell
createdb database_name
```

Open PostgreSQL **interactive terminal** for the database
```shell
psql -d database_name
```

Change **postgres password** :
```
\password postgres
```

You can **exit** the **interactive terminal** with `\q` and then the **postgres account** with `exit`

<br>

## Create a script to connect to the database

`main.cpp` :
```cpp
#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
    try {
        connection db(" \
        dbname = database_name \
        user = postgres \
        password = password \
        hostaddr = 127.0.0.1 \
        port = 5432 \
        ");
        if (db.is_open()) {
            cout << "Opened database successfully: " << db.dbname() << endl;
        } else {
            cout << "Can't open database" << endl;
            return 1;
        }

        /*
        Requests go here
        */

        db.disconnect ();
        return 0;

    } catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
}
```
You can find code examples [here](https://www.tutorialspoint.com/postgresql/postgresql_c_cpp.htm#)

<br>

**Compile** the c++ file :
```shell
g++ main.cpp -lpqxx -lpq -o output
```

You can now **execute** the compiled file with `./output`
