# Car Repair Shop Management System

[![VIDEO: Car Repair Shop Management System](https://i9.ytimg.com/vi/C18D7aSCOE4/mqdefault.jpg?v=65031cbe&sqp=CJi7jKgG&rs=AOn4CLAsS2yjjETOD_4hz1chSyI9UscsNw)](https://youtu.be/C18D7aSCOE4)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Adding Customers](#adding-customers)
  - [Listing Customers](#listing-customers)
  - [Adding Services](#adding-services)
  - [Listing Services](#listing-services)
  - [Creating Repair Orders](#creating-repair-orders)
  - [Listing Repair Orders](#listing-repair-orders)
  - [Completing Repair Orders](#completing-repair-orders)
- [Data Persistence](#data-persistence)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

Welcome to the Car Repair Shop Management System, a C++ project that simulates a comprehensive management system for car repair shops. This project was developed during my internship experience as a software engineer, where I worked with a team at a car repair garage in London. Inspired by the real-world needs of such businesses, this system provides a platform for efficiently managing customers, services, and repair orders.

The project allows car repair shop owners and employees to streamline their operations, from adding and tracking customers to managing a list of available services, creating repair orders, and monitoring repair progress.

## Features

- **Customer Management:** Add and manage customer information, including names and contact details.

- **Service Management:** Maintain a list of available services, including service names, descriptions, and costs.

- **Repair Order Creation:** Create repair orders for customers, selecting from a list of available services.

- **Repair Order Tracking:** Track the status and cost of each repair order.

- **Invoice Generation:** Generate invoices for completed repair orders.

- **Data Persistence:** Store data persistently in text files (`customers.txt`, `services.txt`, `repair_orders.txt`) for future access and continuity.

## Project Structure

The project is structured as follows:

- `main.cpp`: The main program file containing the core logic and user interface.
- `customers.txt`: Text file to store customer data.
- `services.txt`: Text file to store service data.
- `repair_orders.txt`: Text file to store repair order data.

## Getting Started

### Prerequisites

To run this project, you need:

- A C++ compiler (e.g., g++) installed on your system.
- Access to a terminal or command prompt.

### Installation

1. Clone this repository to your local machine.

`git clone https://github.com/your-username/car-repair-shop-management.git
`
2. Navigate to the project directory.

`cd car-repair-shop-management`

3.  Compile the code.

`g++ main.cpp -o car_repair_shop`

4. Run the program.

`./car_repair_shop`

## Usage

### Adding Customers

To add a new customer, follow these steps:
1. Choose option 1 from the main menu.
2. Enter the customer's name.
3. Enter the customer's contact details.

### Listing Customers

To list all customers, choose option 2 from the main menu. The system will display a table with customer information.

### Adding Services

To add a new service, follow these steps:

1. Choose option 3 from the main menu.
2. Enter the service name.
3. Enter the service description.
4. Enter the service cost.

### Listing Services

To list all services, choose option 4 from the main menu. The system will display a table with service information.

### Creating Repair Orders

To create a repair order, follow these steps:

1. Ensure you have added customers and services.
2. Choose option 5 from the main menu.
3. Enter the customer's ID.
4. Enter the service IDs (separated by spaces) for the repair order. Enter `-1` to finish.

### Completing Repair Orders

To mark a repair order as completed, choose option 7 from the main menu. Enter the repair order ID when prompted.

## Data Persistence

Customer data, service data, and repair order data are stored in text files (`customers.txt`, `services.txt`, `repair_orders.txt`) for data persistence. This ensures that your data is retained between program sessions.

## Contributing

Contributions to this project are welcome! If you have ideas for improvements or new features, please open an issue or submit a pull request on the GitHub repository. Or email me privately and I'll respond to it.

## Licence

This project is open-source and available under the [MIT License](LICENSE). 

## Acknowledgments

I would like to express my gratitude to the team at the car repair garage in London, where I had the opportunity to work on a similar project. This experience inspired and informed the development of this Car Repair Shop Management System.

Thank you for using this software. Enjoy managing your car repair shop more efficiently with this tool!
