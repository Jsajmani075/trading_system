#include "login.h"

#include <cpr/cpr.h>

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
using json = nlohmann::json;
std::string get_access_token(const std::string& client_id, const std::string& client_secret,
                             const std::string& grant_type)
{
    std::string url = "https://test.deribit.com/api/v2/public/auth?client_id=" + client_id +
                      "&client_secret=" + client_secret + "&grant_type=" + grant_type;

    cpr::Response r = cpr::Get(cpr::Url{url}, cpr::Timeout{10000});

    std::cout << "Received Response: " << r.text << std::endl;

    if (r.status_code != 200)
    {
        std::cerr << "Error: Received non-200 status code " << r.status_code << std::endl;
        std::cerr << "Response Body: " << r.text << std::endl;
        return "";
    }

    try
    {
        auto res_json = json::parse(r.text);
        if (res_json.contains("result"))
        {
            std::string access_token = res_json["result"]["access_token"];
            std::cout << "Access Token: " << access_token << "\n";
            return access_token;
        }
        else
        {
            std::cerr << "Error response: " << r.text << "\n";
            return "";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "JSON Error: " << e.what() << "\n";
        return "";
    }
}
