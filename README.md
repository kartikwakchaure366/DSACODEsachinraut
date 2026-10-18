#  Smart Agriculture Transport System

## 1. Introduction

The Smart Agriculture Transport System is a console-based application developed using C++ to help farmers find suitable transport vehicles for carrying their agricultural produce. The system connects farmer requests with available transport vehicles based on pickup location and required transportation capacity.

The project uses singly linked lists and dynamic memory allocation to store and manage farmer requests and transport vehicle details. It aims to simplify the transportation process, reduce the difficulty of finding suitable vehicles, and improve coordination between farmers and transport providers.

## 2. Objectives

The main objectives of this project are:

- To maintain records of farmers and their crop transportation requests.
- To register transport vehicles along with driver details and vehicle capacity.
- To display farmer requests and registered transport vehicles.
- To match farmers with suitable vehicles based on location, crop quantity, and vehicle availability.
- To reduce the time and effort required to arrange agricultural transportation.
- To demonstrate the practical application of data structures in solving real-world problems.

## 3. Technologies Used

- Programming Language: C++
- Concepts Used: Structures, pointers, functions, loops, conditional statements, and dynamic memory allocation.
- Data Structure: Singly linked list
- Interface: Menu-driven console interface

## 4. Main Features and Modules

### 1. Add Farmer Request

Allows users to enter farmer details, including farmer ID, name, pickup location, crop name, and crop quantity in tons. The system validates that the crop quantity is greater than zero before storing the request.

### 2. Add Transport Vehicle

Allows users to register a transport vehicle by entering the vehicle ID, driver name, vehicle location, and carrying capacity. The vehicle is marked as available after successful registration.

### 3. Display Farmer Requests

Displays all registered farmer requests, including their personal details, pickup locations, crop types, and quantities.

### 4. Display Transport Vehicles

Displays all registered vehicles, their drivers, locations, capacities, and current status, which can be either Available or Booked.

### 5. Match Transport

The system searches for a suitable vehicle for each farmer request. A vehicle is selected when:

- The vehicle is available.
- The vehicle's location matches the farmer's pickup location.
- The vehicle's capacity is equal to or greater than the farmer's crop quantity.

When a suitable vehicle is found, its details are displayed and its status changes to Booked, preventing it from being assigned again during subsequent matching operations.

### 6. Exit and Memory Management

Allows users to exit the application. Before termination, the program releases the dynamically allocated memory used by the farmer and transport linked lists.

## 5. Data Structures Used

The project uses two singly linked lists:

- Farmer linked list: Stores farmer information and crop transportation requests.
- Transport linked list: Stores vehicle information, driver details, capacity, location, and availability status.

Each node contains the relevant data and a pointer to the next node. This structure allows records to be added dynamically without requiring a fixed-size array.

## 6. Working of the System

The system follows these steps:

1. The user starts the program and selects an option from the main menu.
2. Farmer requests and transport vehicle details are entered and stored in linked lists.
3. The user can view all registered farmer requests and vehicles.
4. When the matching option is selected, the system compares each farmer's pickup location and crop quantity with available vehicles.
5. If a suitable vehicle is found, the system displays the matching details and marks the vehicle as booked.
6. If no suitable vehicle is found, the system displays a message indicating that no appropriate vehicle is available.
7. When the user exits, all dynamically allocated memory is released.

## 7. Advantages

- Simple and user-friendly menu-driven interface.
- Efficient organization of farmer and transport records using linked lists.
- Automatic matching based on location and vehicle capacity.
- Prevents the same vehicle from being assigned to multiple requests during matching.
- Validates positive crop quantities and vehicle capacities.
- Demonstrates the practical use of C++ programming and data structures.

## 8. Limitations and Future Scope

The current version is a basic prototype. It stores data only while the program is running, and vehicle matching requires an exact location match. Future improvements could include:

- Database integration for permanent data storage.
- A graphical user interface or web-based application.
- Distance-based matching and route optimization.
- Support for splitting large crop loads across multiple vehicles.
- Farmer and driver login systems.
- Booking confirmation, delivery tracking, and notifications.
- Improved input validation and duplicate ID checking.

## 9. Conclusion

The Smart Agriculture Transport System provides a basic solution for coordinating agricultural transportation by connecting farmers with suitable available vehicles. It simplifies the management of farmer requests and transport records through a linked-list-based approach and automates vehicle selection according to location and capacity.

