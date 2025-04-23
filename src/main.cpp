#include <Client.hpp>
#include <iostream>

int main() {

    const Client client = Client::find("A101");
    client.print_info();

    if (Client::is_exist("A101")) {
        std::cout << "Client A101 already exist\n";
    }

    if (!Client::is_exist("X250")) {
        std::cout << "Client X250 doesn't exist\n";
    }

    return 0;
}
