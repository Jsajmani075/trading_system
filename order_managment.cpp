#include "order_managment.h"

#include <cpr/cpr.h>

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

void place_buy_order(const std::string& auth_response, const std::string& type, const std::string& instrument,
                 double quantity, double price)
{
    std::string url = "https://test.deribit.com/api/v2/private/buy";
    std::string full_url = url + "?amount=" + std::to_string(quantity) +"&price="+ std::to_string(price)+ "&instrument_name=" + instrument +
                           "&type=" + type + "&label=market0000234";
    std::cout << "\nMaking request to: " << url << "\n";
    std::cout << "Authorization: Bearer " << auth_response << "\n";
    auto r = cpr::Get(cpr::Url{full_url}, cpr::Header{{"Authorization", "Bearer " + auth_response}});

    std::cout << "Received Response: " << r.text << std::endl;

    if (r.status_code != 200)
    {
        std::cerr << "Error in placing order: Received status " << r.status_code << "\n";
        return;
    }
    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result") && res_json["result"].contains("order"))
        {
            auto order_id = res_json["result"]["order"]["order_id"].get<std::string>();
            std::cout << "Order placed successfully: " << order_id << "\n";
        }
        else
        {
            std::cerr << "Unexpected response: " << r.text << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
    }
}


void place_sell_order(const std::string& auth_response, const std::string& type, const std::string& instrument,
                 double quantity, double price)
{
    std::string url = "https://test.deribit.com/api/v2/private/sell";
    std::string full_url = url + "?amount=" + std::to_string(quantity) +"&price="+ std::to_string(price)+ "&instrument_name=" + instrument +
                           "&type=" + type + "&label=market0000234";
    std::cout << "\nMaking request to: " << url << "\n";
    std::cout << "Authorization: Bearer " << auth_response << "\n";
    auto r = cpr::Get(cpr::Url{full_url}, cpr::Header{{"Authorization", "Bearer " + auth_response}});

    std::cout << "Received Response: " << r.text << std::endl;

    if (r.status_code != 200)
    {
        std::cerr << "Error in placing order: Received status " << r.status_code << "\n";
        return;
    }
    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result") && res_json["result"].contains("order"))
        {
            auto order_id = res_json["result"]["order"]["order_id"].get<std::string>();
            std::cout << "Order placed successfully: " << order_id << "\n";
        }
        else
        {
            std::cerr << "Unexpected response: " << r.text << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
    }
}


void cancel_order(const std::string& auth_response, const std::string& order_id)
{
  std::string url = "https://test.deribit.com/api/v2/private/cancel";
    std::string full_url = url + "?order_id=" + order_id;

    std::cout << "\nMaking request to: " << full_url << "\n";
    std::cout << "Authorization: Bearer " << auth_response << "\n";

    auto r = cpr::Get(
        cpr::Url{full_url},
        cpr::Header{
            {"Authorization", "Bearer " + auth_response}
        }
    );

 std::cout << "Received Response: " << r.text << std::endl;

    if (r.status_code != 200)
    {
        std::cerr << "Error in cancel of order: Received status " << r.status_code << "\n";
        return;
    }
    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result"))
        {
            std::cout << " your Order is  cancelled successfully for orderID:"<<order_id<< "\n";

        }
        else
        {
            std::cerr << "Unexpected response: " << r.text << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
    }
}

void modify_order(const std::string& auth_response, const std::string& order_id, double new_price, double new_quantity)
{
    std::string url = "https://test.deribit.com/api/v2/private/edit";
    std::string full_url = url + "?amount=" + std::to_string(new_quantity)+"&price="+ std::to_string(new_price)+"&order_id="+order_id;
    std::cout << "\nMaking request to: " << url << "\n";
    std::cout << "Authorization: Bearer " << auth_response << "\n";
    auto r = cpr::Get(cpr::Url{full_url}, cpr::Header{{"Authorization", "Bearer " + auth_response}});

    std::cout << "Received Response: " << r.text << std::endl;


    if (r.status_code != 200)
    {
        std::cerr << "Error in modifying order: Received status " << r.status_code << "\n";
        return;
    }
    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result") && res_json["result"].contains("order"))
        {
            std::cout << "Order modified successfully for orderId is: " << order_id<<"\n"<<"reponse is::"<<res_json["result"].dump(2) << "\n";
        }
        else
        {
            std::cerr << "Unexpected response: " << r.text << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
    }
}

void getPositions(const std::string& auth_response){
    
std::string url = "https://test.deribit.com/api/v2/private/get_positions";
    std::cout << "\nMaking request to: " << url << "\n";
    std::cout << "Authorization: Bearer " << auth_response << "\n";


    auto r = cpr::Get(
        cpr::Url{url},

        cpr::Header{
            {"Authorization", "Bearer " + auth_response}
        }
    );

 std::cout << "Received Response: " << r.text << std::endl;

    if (r.status_code != 200)
    {
        std::cerr << "Error in cancel of order: Received status " << r.status_code << "\n";
        return;
    }
    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result"))
        {
            std::cout <<res_json["result"].dump(2)<< "\n";

        }
        else
        {
            std::cerr << "Unexpected response: " << r.text << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
    }
}


void getOrderBook(const std::string& instrument){
    
std::string url = "https://test.deribit.com/api/v2/public/get_order_book";
std::string fullurl=url+"?instrument_name="+instrument;
    std::cout << "\nMaking request to: " << fullurl << "\n";



    auto r = cpr::Get(
        cpr::Url{fullurl}
    );

 std::cout << "Received Response: " << r.text << std::endl;

    if (r.status_code != 200)
    {
        std::cerr << "Error in cancel of order: Received status " << r.status_code << "\n";
        return;
    }
    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result"))
        {
            std::cout <<res_json["result"].dump(2)<< "\n";

        }
        else
        {
            std::cerr << "Unexpected response: " << r.text << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
    }
}