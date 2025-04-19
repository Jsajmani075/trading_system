// ETH-PERPETUAL
#include <cpr/cpr.h>

#include <iostream>

#include "login.h"
#include "order_managment.h"


int main()
{
    std::string client_id = "ooO0pphh";
    std::string client_secret = "Fcecl1lowD7buXLQaxPlbtue38QegnaVbrTcfA3nNEI";
    std::string grant_type = "client_credentials";
    std::string auth_response = get_access_token(client_id, client_secret, grant_type);
    std::cout << "Authentication Successful: " << auth_response<<std::endl;

    double price, amount;
    std::string order_id;
    std::string instrument;
    std::string type;

//place buy order start here
    std::cout << "enter instrument to place a order :";
    std::cin >> instrument;

    std::cout << "enter number of quantity to place a order :";
    std::cin >> amount;


    std::cout << "enter price to place a order :";
    std::cin >> price;


    std::cout << "enter a type place a order :";
    std::cin >> type;

    place_buy_order(auth_response, type, instrument, amount, price);

//place buy order finish here


//place sell order start here
    std::cout << "enter instrument to place a order :";
    std::cin >> instrument;

    std::cout << "enter number of quantity to place a order :";
    std::cin >> amount;


    std::cout << "enter price to place a order :";
    std::cin >> price;


    std::cout << "enter a type place a order :";
    std::cin >> type;

    place_sell_order(auth_response, type, instrument, amount, price);

//place sell order finish here

    // cancel order starts here

    std::cout << "enter a order id to cancel order:";
    std::cin >> order_id;
    cancel_order(auth_response, order_id);

    // cancel order finish here

    // modify order starts here

    std::cout << "enter a order id to modify order:";
    std::cin >> order_id;

    std::cout << "enter number of new quantity to modify  a order :";
    std::cin >> amount;

    std::cout << "enter new price to modify  a order :";
    std::cin >> price;

    modify_order(auth_response, order_id, price, amount);

    // modify order finish here

//get position or current position starts here

 getPositions(auth_response);


//get position or current position end here

//get order book start here

  std::cout << "enter instrument to get order book :";
    std::cin >> instrument;

getOrderBook(instrument);

//get order book end here

    return 0;
}