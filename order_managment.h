#pragma once
#include <string>

void place_buy_order(const std::string& auth_response, const std::string& type, const std::string& instrument,
                 double quantity, double price);


void place_sell_order(const std::string& auth_response, const std::string& type, const std::string& instrument,
                 double quantity, double price);
void cancel_order(const std::string& auth_response, const std::string& order_id);

void modify_order(const std::string& auth_response, const std::string& order_id, double new_price, double new_quantity);

void getPositions(const std::string& auth_response);


void getOrderBook(const std::string& instrument);