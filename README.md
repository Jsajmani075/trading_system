Trading System

#Overview
This project is a high-performance order execution and management system built using C++ for interacting with the Deribit Test API. The system supports placing, modifying, and canceling orders, as well as retrieving the order book and viewing current positions.

Core Features:
Place Order: Place  orders for market or limit type

Cancel Order: Cancel an existing order by its ID.

Modify Order: Modify an order's parameters (e.g., price or quantity).

Get Orderbook: Retrieve the current order book for selected instruments.

View Current Positions: View the current positions held by the user.

#System Architecture
This system integrates with the Deribit Test API to manage orders and market data. It uses the C++ programming language and external libraries for JSON parsing and HTTP requests.

The system is designed for low-latency performance and provides essential functionalities for placing, modifying, and canceling orders,Get orderbook ,View current positions 

#Prerequisites
C++ Compiler: clang++ (or GCC/Clang compatible compiler)

Dependencies:

nlohmann-json for JSON parsing.

CPR for making HTTP requests.

Make sure to install the dependencies via a package manager or manually from the following paths:

nlohmann-json: /opt/homebrew/Cellar/nlohmann-json/3.12.0/include

CPR: /opt/homebrew/Cellar/cpr/1.11.2/include and /opt/homebrew/Cellar/cpr/1.11.2/lib

#Installation & Setup

Steps to Build and Run
1)Clone the repository:
git clone https://github.com/Jsajmani075/trading_system.git
2)Navigate to the project directory:
cd trading-system

3)Compile the project using the following command:
clang++ -std=c++17 \
-I/opt/homebrew/Cellar/nlohmann-json/3.12.0/include \
-I/opt/homebrew/Cellar/cpr/1.11.2/include \
-L/opt/homebrew/Cellar/cpr/1.11.2/lib \
-lcpr \
main.cpp login.cpp order_management.cpp \
-o test_json && ./test_json


This will compile the source files and generate an executable named test_json.

Run the system with:
./test_json

Usage
Once the system is running, you will interact with it through a command-line interface where you can provide input to perform different actions. The system will prompt you for inputs, and based on your responses, it will execute the corresponding functionality.

Example Interaction:

Place Order

The system will ask for the type of order (market/limit), the amount,instrument and the price.

Please enter order type (market/limit):limit
Please enter amount: 1
Please enter price: 3000
please enter instrument:ETH-PERPETUAL

Cancel Order

The system will ask for the order_id of the order you wish to cancel.

Example:
Please enter order ID to cancel: <order_id>

Modify Order

The system will ask for the order_id, new price, and new amount to modify the order.

Example:
Please enter order ID to modify: <order_id>
Please enter new price: 3050
Please enter new amount: 1.5

Get Orderbook

The system will ask for the instrument(e.g., BTC-PERPETUAL) for which you want to get the order book.

Example:
Please enter instrumentfor order book: BTC-PERPETUAL

View Current Positions

The system will display the current positions held by the user without needing additional input.


#Code Structure
main.cpp: The entry point of the application. It sets up the system and runs the main loop.

login.cpp: Handles user authentication and API key management.

order_management.cpp: Contains functions for placing, modifying, and canceling orders,View current positions,Get orderbook 


