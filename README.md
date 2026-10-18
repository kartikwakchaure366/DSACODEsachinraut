#  Smart Agriculture Transport System

## 1. Introduction

The Smart Agriculture Transport System is a C++-based application designed to help farmers find suitable transport vehicles for carrying their agricultural products from pickup locations to their destinations. The system connects farmer requests with available transport vehicles based on location and carrying capacity.

The project uses singly linked lists to store farmer details and transport vehicle information dynamically. It provides a simple menu-driven interface through which users can add farmer requests, register transport vehicles, view stored records, and match farmers with suitable vehicles.

## 2. Objectives

- To simplify the process of arranging transportation for agricultural products.
- To maintain farmer requests and transport vehicle details efficiently.
- To match farmers with available vehicles based on pickup location and vehicle capacity.
- To reduce the manual effort involved in finding suitable transportation.
- To demonstrate the practical implementation of linked lists, pointers, structures, and functions in C++.

## 3. Main Features

1. Add Farmer Request: Records the farmer's ID, name, pickup location, crop name, and crop quantity in tons.
2. Add Transport Vehicle: Stores the vehicle ID, driver's name, vehicle location, and carrying capacity.
3. Display Farmer Requests: Displays all registered farmer requests.
4. Display Transport Vehicles: Shows all registered vehicles along with their availability status.
5. Match Transport: Matches a farmer with an available vehicle if both have the same location and the vehicle has sufficient capacity.
6. Vehicle Availability Management: Marks a vehicle as booked after a successful match to prevent it from being assigned again during the current session.
7. Memory Management: Uses dynamic memory allocation and a cleanup function to release linked-list nodes when the program exits.

## 4. Technologies Used

- Programming Language: C++
- Data Structures: Singly linked lists
- Concepts Used: Structures, pointers, dynamic memory allocation, functions, loops, conditional statements, and input/output operations.
- Interface: Console-based, menu-driven application.

## 5. Working of the System

Start the Application

Register Farmer

Enter crop, quantity and pickup location

Register Vehicle

Enter driver, location and capacity

Match Farmer with Vehicle

Check location, availability and capacity

Match Found

Display match and mark vehicle booked

No Match

Display a message for the farmer

## 6. Data Structures Used

The project uses two structures:

- Farmer: Stores the farmer's ID, name, pickup location, crop name, quantity, and a pointer to the next farmer node.
- Transport: Stores the vehicle ID, driver's name, location, capacity, availability status, and a pointer to the next vehicle node.

Both structures are organized as singly linked lists. This allows the program to add records dynamically without requiring a fixed-size array.

## 7. Advantages

- Simple and user-friendly interface.
- Dynamic storage of farmer and vehicle records.
- Efficient organization of records using linked lists.
- Automatic matching based on location and capacity.
- Prevents the same vehicle from being assigned to multiple farmers during the current session.
- Helps demonstrate real-world applications of fundamental C++ programming concepts.

## 8. Limitations and Future Scope

The current version stores information only while the program is running. It also requires an exact match between the farmer's pickup location and the vehicle's location.

Future improvements could include:

- Database integration for permanent data storage.
- A graphical user interface or web application.
- GPS-based location and distance calculations.
- Online booking and transport cost estimation.
- Support for partial loads or multiple vehicles for large crop quantities.
- Driver and farmer login systems with booking history.

## 9. Conclusion

The Smart Agriculture Transport System provides a basic solution for coordinating agricultural transportation by connecting farmer requests with suitable transport vehicles. It demonstrates how C++ and linked lists can be applied to a practical agricultural problem. By matching vehicles according to location, availability, and carrying capacity, the system helps organize transportation requests and provides a foundation for developing a more advanced smart agriculture logistics application.
