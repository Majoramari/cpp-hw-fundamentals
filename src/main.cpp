#include <Client.hpp>

int main() {

    const Client client = Client::find("A101");
    client.print_info();

    return 0;
}
